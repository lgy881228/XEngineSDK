//
//  XLinkGatewayUnPairSubDeviceTask.h
//  XLinkSDK
//
//  Created by AllenKwok on 2018/1/19.
//  Copyright © 2018年 www.xlink.cn. All rights reserved.
//

#import "XLinkSendPolicyTask.h"
#import "XDevice.h"

@interface XLinkGatewayUnPairSubDeviceTask : XLinkSendPolicyTask

/**
 子设备
 */
@property (strong, nonatomic) XDevice *subDevice;

/**
 子设备所在的网关设备
 */
@property (strong, nonatomic) XDevice *gatewayDevice;

/**
 新建取消配对子设备任务
 
 @param subDevice 要取消配对的设备
 @param gatewayDevice 假如是子设备，则填入子设备的网关设备
 @param timeOut 设置超时时间，单位秒，建议15秒
 @param completionHandler 任务完成后回调
 @return XLinkUnPairSubDeviceTask
 */
+ (instancetype)unpairDeviceTaskWithDevice:(XDevice *)subDevice
                         gatewayDevice:(XDevice *)gatewayDevice
                               timeOut:(NSUInteger)timeOut
                         completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;

/**
 新建取消配对子设备任务 并启动
 
 @param subDevice 要取消配对的设备
 @param gatewayDevice 假如是子设备，则填入子设备的网关设备
 @param timeOut 设置超时时间，单位秒，建议15秒
 @param completionHandler 任务完成后回调
 @return XLinkUnPairSubDeviceTask
 */
+ (instancetype)scheduledUnpairDeviceTaskWithDevice:(XDevice *)subDevice
                                      gatewayDevice:(XDevice *)gatewayDevice
                                            timeOut:(NSUInteger)timeOut
                                  completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;



@end

//以下是废弃的方法，不建议使用，不久的将来会删除
@interface XLinkGatewayUnPairSubDeviceTask (XLinkDeprecated)

/**
 新建取消配对子设备任务
 
 @param subDevice 要取消配对的设备
 @param gatewayDevice 假如是子设备，则填入子设备的网关设备
 @param timeOut 设置超时时间，单位秒，建议15秒
 @param completeBlock 任务完成后回调
 @return XLinkUnPairSubDeviceTask
 */
+ (instancetype)unpairDeviceTaskWithDevice:(XDevice *)subDevice
                         withGatewayDevice:(XDevice *)gatewayDevice
                               withTimeOut:(NSUInteger)timeOut
                         withCompleteBlock:(OnTaskCompleteBlock)completeBlock NS_DEPRECATED(2_0, 2_0, 2_0, 2_0, "已废弃方法，请使用+ unpairDeviceTaskWithDevice:gatewayDevice:timeout:completionHandler:替换,以后的版本将可能会删除此方法");

@end
