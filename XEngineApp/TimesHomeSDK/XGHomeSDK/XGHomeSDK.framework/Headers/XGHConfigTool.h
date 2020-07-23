//
//  XGHConfigTool.h
//  XGHomeSDK
//
//  Created by Hoony on 2019/11/1.
//  Copyright © 2019 XLH. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <UserNotifications/UserNotifications.h>

#import "XLinkSDK.h"

@class XLinkConfig;

FOUNDATION_EXTERN NSString * _Nonnull const kXGHConfigToolNewWarningMessageNotificationName;
FOUNDATION_EXTERN NSString * _Nonnull const kXGHUserDeviceChangeNotificationName;
FOUNDATION_EXTERN NSString * _Nonnull const kXGHUserSceneChangeNotificationName;

FOUNDATION_EXTERN NSString * _Nonnull const kXGHUserAccountErrorNotificationName;
FOUNDATION_EXTERN NSString * _Nonnull const kXGHUserAccountErrorNotificationReasonKey;

NS_ASSUME_NONNULL_BEGIN

@interface XGHAliConfigModel : NSObject

@property (nonatomic , copy)NSString            *appKey;

@property (nonatomic , copy)NSString            *EMASAppKey;
@property (nonatomic , copy)NSString            *EMASAppSecret;
@property (nonatomic , copy)NSString            *APNAppId;

@end

//@interface XGHXlinkTempleteModel : NSObject
//
//@end

@interface XGHConfigModel : NSObject

@property (nonatomic , strong)XLinkConfig           *xlinkConfig;

@property (nonatomic , strong)XGHAliConfigModel     *aliConfig;

@end



@interface XGHConfigTool : NSObject <UNUserNotificationCenterDelegate>

+ (instancetype)shareTool;

// 资源的Bundle
+ (NSBundle *)sourceBundle;


@property (nonatomic , strong , readonly)XLinkConfig *xlinkConfig;
@property (nonatomic , strong , readonly)XGHAliConfigModel     *aliConfig;
- (void)startWithConfig:(XGHConfigModel *)xlinkConfig;

#pragma mark - appdelegate Handler

- (void)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;

@end

NS_ASSUME_NONNULL_END
