//
//  IMSThingCapabilityLaunch.m
//  
//
//  Created by Aliyun on 2018/6/12.
//  Copyright © 2018年 Alibaba. All rights reserved.
//

#import "IMSThingCapabilityLaunch.h"

#import <IMSLaunchKit/IMSLaunchKit.h>
#import <IMSThingCapability/IMSThingCapability.h>

@interface IMSThingCapabilityLaunch ()

@end

@implementation IMSThingCapabilityLaunch

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    [kIMSThingManager startLocalAcceleration];
    
    return TRUE;
}

@end
