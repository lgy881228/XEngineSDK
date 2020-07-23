//
//  XLinkAddSubDeviceTask.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/7/29.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "XLinkTask.h"
@class XDevice;

NS_ASSUME_NONNULL_BEGIN

@interface XLinkGatewayAddSubDeviceTask : XLinkTask

///要添加的设备
@property(strong, nonatomic) XDevice *device;

///要添加的子设备
@property(strong, nonatomic) XDevice *subDevice;

/**
 构建添加将子设备添加到设备（网关）任务
 
 @param device 要加入的设备（网关）
 @param subDevice 被添加的子设备
 @param pinCode 安全码，一般为设备会显示出来，需要设备支持。没有的时候传nil即可
 @param timeout 设置超时，单位秒，默认90秒
 @param completionHandler 任务完成后回调
 @return XLinkAddDeviceTask
 */
+ (instancetype)addSubDeviceTaskWithDevice:(XDevice *)device
                                 subDevice:(XDevice *)subDevice
                                   pinCode:(NSData * _Nullable)pinCode
                                   timeout:(NSUInteger)timeout
                             completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;

/**
 构建添加将子设备添加到设备（网关）任务 并启动
 
 @param device 要加入的设备（网关）
 @param subDevice 被添加的子设备
 @param pinCode 安全码，一般为设备会显示出来，需要设备支持。没有的时候传nil即可
 @param timeout 设置超时，单位秒，默认90秒
 @param completionHandler 任务完成后回调
 @return XLinkAddDeviceTask
 */
+ (instancetype)scheduledAddSubDeviceTaskWithDevice:(XDevice *)device
                                          subDevice:(XDevice *)subDevice
                                            pinCode:(NSData * _Nullable)pinCode
                                            timeout:(NSUInteger)timeout
                                  completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;

@end

//以下是废弃的方法，不建议使用，不久的将来会删除
@interface XLinkGatewayAddSubDeviceTask (XLinkDeprecated)

/**
 构建添加将子设备添加到设备（网关）任务
 
 @param device 要加入的设备（网关）
 @param subDevice 被添加的子设备
 @param pinCode 安全码，一般为设备会显示出来，需要设备支持。没有的时候传nil即可
 @param timeout 设置超时，单位秒，默认90秒
 @param completeBlock 任务完成后回调
 @return XLinkAddDeviceTask
 */
+ (instancetype)addSubDeviceTaskWithDevice:(XDevice *)device
                             withSubDevice:(XDevice *)subDevice
                               withPinCode:(NSData * _Nullable)pinCode
                               withTimeOut:(NSUInteger)timeout
                         withCompleteBlock:(OnTaskCompleteBlock)completeBlock NS_DEPRECATED(2_0, 2_0, 2_0, 2_0, "已废弃方法，请使用+addSubDeviceTaskWithDevice:subDevice:pinCode:timeout:completeBlock:替换,以后的版本将可能会删除此方法");

@end
NS_ASSUME_NONNULL_END
