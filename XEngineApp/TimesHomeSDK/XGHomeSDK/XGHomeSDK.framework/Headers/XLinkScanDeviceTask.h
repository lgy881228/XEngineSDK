//
//  XLinkScanDeviceTask.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/2/13.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "XLinkRetryUntilTimeoutTask.h"
#import "XDevice.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^XLinkDidDiscoveredDeviceHandler)(XDevice *device);

@interface XLinkScanDeviceTask : XLinkRetryUntilTimeoutTask

///要扫描设备的productID数组
@property(copy, nonatomic) NSArray *productIdArray;

///扫描到设备后回调
@property(copy, nonatomic,nullable) XLinkDidDiscoveredDeviceHandler discoveredDeviceHandler;

/**
 构建扫描设备任务
 
 @param pidArray productID数组
 @param timeout 设置超时，单位毫秒，默认90秒
 @param discoveredDeviceHandler 搜索到设备的回调
 @param completionHandler 搜索完成的回调
 @return XLinkScanDeviceTask
 */
+ (instancetype)scanDeviceTaskWithProductIdArray:(NSArray *)pidArray
                                         timeout:(NSUInteger)timeout
                      didDiscoveredDeviceHandler:(XLinkDidDiscoveredDeviceHandler)discoveredDeviceHandler
                               completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;

/**
 构建扫描设备任务 并启动
 
 @param pidArray productID数组
 @param timeout 设置超时，单位毫秒，默认90秒
 @param discoveredDeviceHandler 搜索到设备的回调
 @param completionHandler 搜索完成的回调
 @return XLinkScanDeviceTask
 */
+ (instancetype)scheduledScanDeviceTaskWithProductIdArray:(NSArray *)pidArray
                                                  timeout:(NSUInteger)timeout
                               didDiscoveredDeviceHandler:(XLinkDidDiscoveredDeviceHandler)discoveredDeviceHandler
                                        completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;


@end

//以下是废弃的方法，不建议使用，不久的将来会删除
@interface XLinkScanDeviceTask (XLinkDeprecated)

/**
 构建扫描设备任务
 
 @param pidArray productID数组
 @param timeout 设置超时，单位毫秒，默认90秒
 @param gotDeviceBlock 搜索到设备的回调
 @param completeBlock 搜索完成的回调
 @return XLinkScanDeviceTask
 */
+ (instancetype)scanDeviceTaskWithProductIds:(NSArray *)pidArray
                                 withTimeOut:(NSUInteger)timeout
                          withGotDeviceBlock:(XLinkDidDiscoveredDeviceHandler)gotDeviceBlock
                           withCompleteBlock:(OnTaskCompleteBlock)completeBlock NS_DEPRECATED(2_0, 2_0, 2_0, 2_0, "已废弃方法，请使用+scanDeviceTaskWithProductIdArray:timeout:didDiscoveredDeviceHandler:completionHandler:替换,以后的版本将可能会删除此方法");

@end
NS_ASSUME_NONNULL_END
