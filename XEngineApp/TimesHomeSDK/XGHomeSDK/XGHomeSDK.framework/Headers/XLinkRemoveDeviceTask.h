//
//  XLinkRemoveDeviceTask.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/2/13.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "XLinkRetryUntilTimeoutTask.h"
#import "XDevice.h"

NS_ASSUME_NONNULL_BEGIN

@interface XLinkRemoveDeviceTask : XLinkRetryUntilTimeoutTask

///要删除的设备
@property(strong, nonatomic) XDevice *device;

/**
 构建删除设备任务
 
 @param device 要删除的设备
 @param timeout 设置超时，单位秒，默认90秒
 @param completionHandler 任务完成后回调
 @return XLinkRemoveDeviceTask
 */
+ (instancetype)removeDeviceTaskWithDevice:(XDevice *)device
                                   timeout:(NSUInteger)timeout
                             completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;

/**
 构建删除设备任务 并启动
 
 @param device 要删除的设备
 @param timeout 设置超时，单位秒，默认90秒
 @param completionHandler 任务完成后回调
 @return XLinkRemoveDeviceTask
 */
+ (instancetype)scheduledRemoveDeviceTaskWithDevice:(XDevice *)device
                                            timeout:(NSUInteger)timeout
                                  completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;


@end


//以下是废弃的方法，不建议使用，不久的将来会删除
@interface XLinkRemoveDeviceTask (XLinkDeprecated)
/**
 构建删除设备任务
 
 @param device 要删除的设备
 @param timeout 设置超时，单位秒，默认90秒
 @param completeBlock 任务完成后回调
 @return XLinkRemoveDeviceTask
 */
+ (instancetype)removeDeviceTaskWithDevice:(XDevice *)device
                               withTimeOut:(NSUInteger)timeout
                         withCompleteBlock:(OnTaskCompleteBlock)completeBlock NS_DEPRECATED(2_0, 2_0, 2_0, 2_0, "已废弃方法，请使用+removeDeviceTaskWithDevice:timeout:completeBlock:替换,以后的版本将可能会删除此方法");
@end
NS_ASSUME_NONNULL_END
