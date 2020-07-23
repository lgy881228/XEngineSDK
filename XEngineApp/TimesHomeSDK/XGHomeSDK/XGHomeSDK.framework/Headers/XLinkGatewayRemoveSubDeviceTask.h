//
//  XLinkGatewayRemoveSubDeviceTask.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/7/29.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "XLinkRetryUntilTimeoutTask.h"
#import "XDevice.h"

NS_ASSUME_NONNULL_BEGIN

@interface XLinkGatewayRemoveSubDeviceTask : XLinkRetryUntilTimeoutTask
///要删除的设备
@property(strong, nonatomic) XDevice *subDevice;

///假如要删除的是子设备，则填入子设备的网关设备
@property(strong, nonatomic) XDevice *gatewayDevice;

/**
 构建删除子设备任务
 
 @param subDevice 要删除的子设备
 @param gatewayDevice 子设备所在的网关设备
 @param timeout 设置超时时间，单位秒，建议15秒
 @param completionHandler 任务完成后回调
 @return XLinkAddDeviceTask
 */
+ (instancetype)removeSubDeviceTaskWithSubDevice:(XDevice *)subDevice
                               fromGatewayDevice:(XDevice *)gatewayDevice
                                         timeout:(NSUInteger)timeout
                               completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;

/**
 构建删除子设备任务 并启动
 
 @param subDevice 要删除的子设备
 @param gatewayDevice 子设备所在的网关设备
 @param timeout 设置超时时间，单位秒，建议15秒
 @param completionHandler 任务完成后回调
 @return XLinkAddDeviceTask
 */
+ (instancetype)scheduledRemoveSubDeviceTaskWithSubDevice:(XDevice *)subDevice
                                        fromGatewayDevice:(XDevice *)gatewayDevice
                                                  timeout:(NSUInteger)timeout
                                        completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;

@end

//以下是废弃的方法，不建议使用，不久的将来会删除
@interface XLinkGatewayRemoveSubDeviceTask (XLinkDeprecated)

/**
 构建删除设备任务
 
 @param device 要添加的设备
 @param gatewayDevice 假如是子设备，则填入子设备的网关设备
 @param timeout 设置超时时间，单位秒，建议15秒
 @param completeBlock 任务完成后回调
 @return XLinkAddDeviceTask
 */
+ (instancetype)removeDeviceTaskWithDevice:(XDevice *)device
                         withGatewayDevice:(XDevice *)gatewayDevice
                               withTimeOut:(NSUInteger)timeout
                         withCompleteBlock:(OnTaskCompleteBlock)completeBlock NS_DEPRECATED(2_0, 2_0, 2_0, 2_0, "已废弃方法，请使用+ rmoveSubDeviceTaskWithSubDevice:fromGatewayDevice:timeout:completionHandler:替换,以后的版本将可能会删除此方法");

@end

NS_ASSUME_NONNULL_END
