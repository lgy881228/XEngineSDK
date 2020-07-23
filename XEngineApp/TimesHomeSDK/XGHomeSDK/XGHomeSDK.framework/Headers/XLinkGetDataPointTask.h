//
//  XLinkGetDataPointTask.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/2/14.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "XLinkSendPolicyTask.h"
#import "XDevice.h"

NS_ASSUME_NONNULL_BEGIN

@class XLinkDataPoint;
@class XLinkGetDataPointTask;

typedef void (^XLinkGetDataPointTaskCompletionHandler)(NSArray <XLinkDataPoint *> *result, XLinkErrorCode errCode);

@interface XLinkGetDataPointTask : XLinkSendPolicyTask

///要获取数据端点的设备
@property(strong, nonatomic) XDevice *device;

/**
 构建获取数据端点的任务
 
 @param device 设备
 @param timeout 设置超时时间，单位秒，建议10秒
 @param completionHandler 完成后的回调
 @return XLinkGetDataPointTask
 */
+ (instancetype)getDataPointTaskWithDevice:(XDevice *)device
                                   timeout:(NSUInteger)timeout
                         completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;

/**
 构建获取数据端点的任务 并启动
 
 @param device 设备
 @param timeout 设置超时时间，单位秒，建议10秒
 @param completionHandler 完成后的回调
 @return XLinkGetDataPointTask
 */
+ (instancetype)scheduledGetDataPointTaskWithDevice:(XDevice *)device
                                            timeout:(NSUInteger)timeout
                                  completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;

@end

//以下是废弃的方法，不建议使用，不久的将来会删除
@interface XLinkGetDataPointTask (XLinkDeprecated)

/**
 构建获取数据端点的任务
 
 @param device 设备
 @param timeout 设置超时时间，单位秒，建议10秒
 @param completeBlock 完成后的回调
 @return XLinkGetDataPointTask
 */
+ (instancetype)getDataPointTaskWithDevice:(XDevice *)device
                               withTimeOut:(NSUInteger)timeout
         withGetDataPointTaskCompleteBlock:(XLinkGetDataPointTaskCompletionHandler)completeBlock NS_DEPRECATED(2_0, 2_0, 2_0, 2_0, "已废弃方法，使用+getDataPointTaskWithDevice:timeout:completeBlock:替换,以后的版本将可能会删除此方法");

@end

NS_ASSUME_NONNULL_END
