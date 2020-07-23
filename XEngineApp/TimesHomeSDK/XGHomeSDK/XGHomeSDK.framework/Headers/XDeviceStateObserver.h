//
//   XDeviceStateObserver.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/2/14.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XDevice.h"
#import "XLinkConst.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^DeviceStateChangedBlock)(XDevice *device, XDeviceConnectionState state);

@interface XDeviceStateObserver : NSObject

///要监听状态变化的设备
@property(strong, nonatomic) XDevice *device;

///监听到设备状态变化的回调
@property(copy, nonatomic) DeviceStateChangedBlock block;

/**
 构建设备状态变化的监听类
 
 @param device 要监听状态变化的设备
 @param block 监听到设备状态变化的回调
 @return 设备状态变化的监听类
 */
+ (instancetype)deviceStateChangedObserverWithDevice:(XDevice *)device
                             deviceStateChangedBlock:(DeviceStateChangedBlock)block;

@end

//以下是废弃的方法，不建议使用，不久的将来会删除
@interface XDeviceStateObserver (XLinkDeprecated)

/**
 构建设备状态变化的监听类
 
 @param device 要监听状态变化的设备
 @param block 监听到设备状态变化的回调
 @return 设备状态变化的监听类
 */
+ (instancetype)deviceStateChangedObserverWithDevice:(XDevice *)device
                            withDataPointUpdateBlock:(DeviceStateChangedBlock)block NS_DEPRECATED(2_0, 2_0, 2_0, 2_0, "已废弃方法，请使用+deviceStateChangedObserverWithDevice:deviceStateChangedBlock:替换,以后的版本将可能会删除此方法");

@end

NS_ASSUME_NONNULL_END
