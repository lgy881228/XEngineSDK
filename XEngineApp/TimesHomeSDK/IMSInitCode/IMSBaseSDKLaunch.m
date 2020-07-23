//
//  IMSBaseSDKLaunch.m
//  
//
//  Created by Aliyun on 2018/6/11.
//  Copyright © 2018年 Alibaba. All rights reserved.
//

#import "IMSBaseSDKLaunch.h"

#import <IMSLaunchKit/IMSLaunchKit.h>
#import <IMSApiClient/IMSConfiguration.h>
#import <IMSBoneKit/IMSBoneConfiguration.h>

#import <IMSLog/IMSLog.h>

#import <AlinkAppExpress/AlinkAppExpress.h>
#import <IMSAccount/IMSAccount.h>
#import <ALBBOpenAccountCloud/ALBBOpenAccountSDK.h>
#import <IMSApiClient/IMSApiClient.h>

#import <IMSAuthentication/IMSAuthentication.h>
#import <IMSAccount/IMSAccount.h>
#import <IMSInitCode/IMSOpenAccount.h>

static NSString *const kIMSMobileChannelLaunchLogTag = @"MobileChannelDemo";
static NSString *const kIMSApiClientLaunchAutoSelectChannelHost = @"autoSelectChannelHost";

static NSString *const kIMSApiClientLaunchHosts = @"hosts";
static NSString *const kIMSApiClientLaunchLanguage = @"language";


@interface IMSBaseSDKLaunch () <LKAppExpConnectListener>

@property (nonatomic, strong) NSDictionary *serverEnvDict;
@property (nonatomic, strong) NSDictionary *lanMapper;

@end


@implementation IMSBaseSDKLaunch

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    NSDictionary *envConfig = [launchOptions valueForKey:kLauncherEnvConfigKey];
    NSString *gRegion = [envConfig valueForKey:kLauncherEnvRegion] ? : LauncherEnvRegionDefaultValue;
    NSString *gEnviroment = [envConfig valueForKey:kLauncherEnvServer] ? : LauncherEnvEnviromentDefaultValue;
    NSString *gLanguage = [envConfig valueForKey:kLauncherEnvLanguage];
    
    NSString *host = launchOptions[gRegion][kIMSApiClientLaunchHosts][gEnviroment];
    IMSServerEnviroment serverEnv = [self.serverEnvDict[gEnviroment] integerValue];
    NSString *language = gLanguage ? : launchOptions[gRegion][kIMSApiClientLaunchLanguage];
    NSString *autoCode = [envConfig valueForKey:kLauncherEnvAuthCode] ? : @"07e8";
    
    // IMSApiClient初始化
    [IMSConfiguration initWithHost:(host ? : @"api.link.aliyun.com") serverEnv:serverEnv];
    [IMSConfiguration sharedInstance].authCode = autoCode;
    [IMSConfiguration sharedInstance].language = language;
    
    // IMSAuthentication初始化
#if DEBUG
    [[ALBBOpenAccountSDK sharedInstance] setDebugLogOpen:YES];
#endif
    
    if (language.length > 0) {
        [[ALBBOpenAccountSDK sharedInstance] setI18N:[self.lanMapper valueForKey:language]];
    }
    
    IMSAccountService *accountService = [IMSAccountService sharedService];
    IMSOpenAccount *openAccount = [IMSOpenAccount sharedInstance];
    accountService.sessionProvider = openAccount;
    accountService.accountProvider = openAccount;
    
    [IMSCredentialManager initWithAccountProtocol:accountService.sessionProvider];
    IMSIoTAuthentication *iotAuthDelegate = [[IMSIoTAuthentication alloc] initWithCredentialManager:IMSCredentialManager.sharedManager];
    [IMSRequestClient registerDelegate:iotAuthDelegate forAuthenticationType:IMSAuthenticationTypeIoT];

    // IMSBoneKit初始化
    NSString *boneEnv = [envConfig valueForKey:kLauncherEnvBoneKit];
    IMSBonePluginEnvironment pluginEnv = IMSBonePluginEnvironmentRelease;
    if ([boneEnv isEqualToString:@"test"]) {
        pluginEnv = IMSBonePluginEnvironmentDaily;
    }
    
    [IMSBoneConfiguration sharedInstance].pluginEnvironment = pluginEnv;
    
    // 长连接初始化
    [IMSLog registerTag:kIMSMobileChannelLaunchLogTag];
    NSNumber *autoSelectChannelHost = launchOptions[gRegion][kIMSApiClientLaunchAutoSelectChannelHost];
    
    LKAppExpressEnv expressEnv = (LKAppExpressEnv)([IMSConfiguration sharedInstance].serverEnv + 1);
    LKAEConnectConfig *channelConfig = [LKAEConnectConfig new];
    channelConfig.appKey = [IMSConfiguration sharedInstance].appKey;
    channelConfig.authCode = [IMSConfiguration sharedInstance].authCode;
    if (expressEnv == LKAppExpressEnvDaily) {
        channelConfig.server = @"10.125.3.189";
        channelConfig.port = 1883;
    }
    
    if ([autoSelectChannelHost isKindOfClass:[NSNumber class]] && [autoSelectChannelHost boolValue]) {
        channelConfig.autoSelectChannelHost = YES;
    }
    [LKAppExpressEnvSet setRunEnv:expressEnv];
    
    if ([[IMSAccountService sharedService] isLogin]) {
        [[LKAppExpress sharedInstance] startConnect:channelConfig connectListener:self];
    }
    
    [[NSNotificationCenter defaultCenter] addObserverForName:ALBBOpenAccountNotificationUserLoggedIn
                                                      object:nil
                                                       queue:[NSOperationQueue mainQueue]
                                                  usingBlock:^(NSNotification * _Nonnull note)
     {
         [[LKAppExpress sharedInstance] startConnect:channelConfig connectListener:self];
     }];
    
    return TRUE;
}

#pragma mark - LKAppExpConnectListener

- (void)onConnectState:(LKAppExpConnectState)state {
    switch (state) {
        case LKAppExpConnectStateConnected: {
            IMSLogDebug(kIMSMobileChannelLaunchLogTag, @"已连接");
            dispatch_async(dispatch_get_main_queue(), ^{
                [[NSNotificationCenter defaultCenter] postNotificationName:@"IMSMobileChannelConnectedSussess" object:nil userInfo:nil];
            });
            break;
        }
        case LKAppExpConnectStateDisconnected: {
            IMSLogDebug(kIMSMobileChannelLaunchLogTag, @"已断连");
            break;
        }
        case LKAppExpConnectStateConnecting: {
            IMSLogDebug(kIMSMobileChannelLaunchLogTag, @"开始建联");
            break;
        }
        default:
            break;
    }
}

#pragma mark - Property

- (NSDictionary *)serverEnvDict {
    if (!_serverEnvDict) {
        _serverEnvDict = @{
                           @"test": @(IMSServerDaily),
                           @"pre": @(IMSServerPreRelease),
                           @"release": @(IMSServerRelease),
                           };
    }
    return _serverEnvDict;
}

- (NSDictionary *)lanMapper {
    if (!_lanMapper) {
        _lanMapper = @{
                       @"zh-CN": @"zh-Hans",
                       @"en-US": @"en",
                       };
    }
    return _lanMapper;
}

@end
