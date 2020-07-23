//
//  XLinkProbeDataPointTask.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/12/27.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "XLinkSendPolicyTask.h"
#import "XDevice.h"

NS_ASSUME_NONNULL_BEGIN

@class XLinkDataPoint;
@class XLinkGetDataPointTask;

typedef void (^XLinkProbeDataPointTaskCompletionHandler)(NSArray <XLinkDataPoint *> *result, XLinkErrorCode errCode);

@interface XLinkProbeDataPointTask : XLinkSendPolicyTask

///要获取数据端点的设备
@property(strong, nonatomic) XDevice *device;

///要获取数据端点的index列表
@property(copy, nonatomic) NSArray <NSNumber *> *indexArray;

/**
 构建获取数据端点的任务
 
 @param device 设备
 @param indexArray 要获取的数据端点索引列表，传空的话将不返回数据端点
 @param timeout 设置超时时间，单位秒，建议10秒
 @param completionHandler 完成后的回调
 @return XLinkProbeDataPointTask
 */
+ (instancetype)probeDataPointTaskWithDevice:(XDevice *)device
                                  indexArray:(NSArray <NSNumber *> * _Nullable)indexArray
                                     timeout:(NSUInteger)timeout
                           completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;

/**
 构建获取数据端点的任务 并启动
 
 @param device 设备
 @param indexArray 要获取的数据端点索引列表，传空的话将不返回数据端点
 @param timeout 设置超时时间，单位秒，建议10秒
 @param completionHandler 完成后的回调
 @return XLinkProbeDataPointTask
 */
+ (instancetype)scheduledProbeDataPointTaskWithDevice:(XDevice *)device
                                           indexArray:(NSArray <NSNumber *> * _Nullable)indexArray
                                              timeout:(NSUInteger)timeout
                                    completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;

@end

//以下是废弃的方法，不建议使用，不久的将来会删除
@interface XLinkProbeDataPointTask (XLinkDeprecated)

/**
 构建获取数据端点的任务
 
 @param device 设备
 @param indexArray 要获取的数据端点索引列表，传空的话将不返回数据端点
 @param timeout 设置超时时间，单位秒，建议10秒
 @param completeBlock 完成后的回调
 @return XLinkProbeDataPointTask
 */
+ (instancetype)probeDataPointTaskWithDevice:(XDevice *)device
                                  indexArray:(NSArray <NSNumber *> *_Nullable)indexArray
                                     timeOut:(NSUInteger)timeout
                 probeDataPointCompleteBlock:(XLinkProbeDataPointTaskCompletionHandler)completeBlock NS_DEPRECATED(2_0, 2_0, 2_0, 2_0, "已废弃方法，请使用+probeDataPointTaskWithDevice:indexArray:timeout:completeBlock:替换,以后的版本将可能会删除此方法");

@end
NS_ASSUME_NONNULL_END
