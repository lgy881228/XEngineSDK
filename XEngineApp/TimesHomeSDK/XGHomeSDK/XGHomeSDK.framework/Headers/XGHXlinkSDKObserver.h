//
//  XGHXlinkSDKObserver.h
//  XGHomeSDK
//
//  Created by Hoony on 2019/11/1.
//  Copyright © 2019 XLH. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "XLinkSDK.h"

NS_ASSUME_NONNULL_BEGIN

@interface XGHXlinkSDKObserver : NSObject

+ (instancetype)shareObserver;

///SDK云端连接状态回调delegate
@property(weak, nonatomic,nullable) id <XLinkCloudDelegate> cloudDelegate;

///SDK用户授权相关回调delegate
@property(weak, nonatomic,nullable) id <XLinkUserDelegate> userDelegate;

@end

@interface XGHDeviceManager : NSObject

+ (instancetype)shareManager;

///SDK数据相关的delegate，包括接收到dataPoint的更新
@property(weak, nonatomic,nullable) id <XLinkDataDelegate> dataDelegate;

///SDK设备状态相关的delegate，包括设备在线离线状态和设备属性的变化
@property(weak, nonatomic,nullable) id <XLinkDeviceStateDelegate> deviceStateDelegate;

@end

NS_ASSUME_NONNULL_END
