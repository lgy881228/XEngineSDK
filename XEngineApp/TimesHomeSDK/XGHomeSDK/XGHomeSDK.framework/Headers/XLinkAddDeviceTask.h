//
//  XLinkAddDeviceTask.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/2/13.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "XLinkTask.h"
@class XDevice;

NS_ASSUME_NONNULL_BEGIN

@interface XLinkAddDeviceTask : XLinkTask

///要添加的设备
@property(strong, nonatomic) XDevice *device;

///是否需要订阅设备,默认情况下为YES
@property (assign, nonatomic) BOOL needSubscription;

/**
 构建添加设备任务
 
 @param device 要添加的设备
 @param pinCode 安全码，一般为设备会显示出来，需要设备支持。没有的时候传nil即可
 @param timeout 设置超时，单位秒，默认90秒
 @param completionHandler 任务完成后回调
 @return XLinkAddDeviceTask
 */
+ (instancetype)addDeviceTaskWithDevice:(XDevice *)device
                                pinCode:(NSData * _Nullable)pinCode
                                timeout:(NSUInteger)timeout
                      completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;


/**
 构建二维码添加设备任务
 
 @param qrcodeString 扫描的二维码
 @param timeout 设置超时，单位秒，默认90秒
 @param completionHandler 任务完成后回调
 @return XLinkAddDeviceTask
 */
+ (instancetype)addDeviceTaskWithQrcodeString:(NSString *)qrcodeString
                                      timeout:(NSUInteger)timeout
                            completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;

/**
 构建添加设备任务 并启动
 
 @param device 要添加的设备
 @param pinCode 安全码，一般为设备会显示出来，需要设备支持。没有的时候传nil即可
 @param timeout 设置超时，单位秒，默认90秒
 @param completionHandler 任务完成后回调
 @return XLinkAddDeviceTask
 */
+ (instancetype)scheduledAddDeviceTaskWithDevice:(XDevice *)device
                                pinCode:(NSData * _Nullable)pinCode
                                timeout:(NSUInteger)timeout
                      completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;


/**
 构建二维码添加设备任务 并启动
 
 @param qrcodeString 扫描的二维码
 @param timeout 设置超时，单位秒，默认90秒
 @param completionHandler 任务完成后回调
 @return XLinkAddDeviceTask
 */
+ (instancetype)scheduledAddDeviceTaskWithQrcodeString:(NSString *)qrcodeString
                                      timeout:(NSUInteger)timeout
                            completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;

@end

//以下是废弃的方法，不建议使用，不久的将来会删除
@interface XLinkAddDeviceTask (XLinkDeprecated)

/**
 构建添加设备任务
 
 @param device 要添加的设备
 @param pinCode 安全码，一般为设备会显示出来，需要设备支持。没有的时候传nil即可
 @param timeout 设置超时，单位秒，默认90秒
 @param completeBlock 任务完成后回调
 @return XLinkAddDeviceTask
 */
+ (instancetype)addDeviceTaskWithDevice:(XDevice *)device
                            withPinCode:(NSData * _Nullable)pinCode
                            withTimeOut:(NSUInteger)timeout
                      withCompleteBlock:(OnTaskCompleteBlock)completeBlock NS_DEPRECATED(2_0, 2_0, 2_0, 2_0, "已废弃方法，请使用+addDeviceTaskWithDevice:pinCode:timeout:completeBlock:替换,以后的版本将可能会删除此方法");


/**
 构建二维码添加设备任务
 
 @param qrcodeString 扫描的二维码
 @param timeout 设置超时，单位秒，默认90秒
 @param completeBlock 任务完成后回调
 @return XLinkAddDeviceTask
 */
+ (instancetype)addDeviceTaskWithQrcodeString:(NSString *)qrcodeString
                                  withTimeOut:(NSUInteger)timeout
                            withCompleteBlock:(OnTaskCompleteBlock)completeBlock NS_DEPRECATED(2_0, 2_0, 2_0, 2_0, "已废弃方法，请使用+addDeviceTaskWithQrcodeString:timeout:completeBlock:替换,以后的版本将可能会删除此方法");

@end
NS_ASSUME_NONNULL_END
