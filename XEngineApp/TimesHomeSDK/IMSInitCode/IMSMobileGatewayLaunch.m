//
//  IMSMobileGatewayLaunch.m
//  IMSInitCode
//
//  Created by 冯君骅 on 2019/8/9.
//

#import "IMSMobileGatewayLaunch.h"

#import <AlinkAppExpress/AlinkAppExpress.h>
#import <AlinkMobileGateway/AlinkMobileGateway.h>

@interface IMSMobileGatewayLaunch ()<LKMgwConnectListener>

@end

@implementation IMSMobileGatewayLaunch

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
	[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(receviceSuccessNotification:) name:@"IMSMobileChannelConnectedSussess" object:nil];
	return YES;
}

- (void)receviceSuccessNotification:(NSNotification *)notification {
	
	NSString *clientId = [[LKAppExpress sharedInstance] getClientId];
	if (clientId.length > 0) {
		[[LKIoTMobileGateway sharedGateway] startConnectWithId:clientId connectListener:self];
	}
}

-(void)onConnectState:(LKMgwConnectState) state {
	
	switch (state) {
		case LKMgwConnectStateConnected: {
			NSLog(@"移动端设备网关SDK 已连接");
			break;
		}
		case LKMgwConnectStateDisConnected: {
			NSLog(@"移动端设备网关SDK 已断连");
			break;
		}
		case LKMgwConnectStateConnecting: {
			NSLog(@"移动端设备网关SDK 连接中");
			break;
		}
	}
	
}


@end
