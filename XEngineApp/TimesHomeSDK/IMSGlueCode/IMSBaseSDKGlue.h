//
//  IMSBaseSDKGlue.h
//  
//
//  Created by Aliyun on 2018/6/25.
//  Copyright © 2018年 Alibaba. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface IMSBaseSDKGlue : NSObject <UIApplicationDelegate>

+ (void)requestUnbindMobileChannelWithAccount;

@end
