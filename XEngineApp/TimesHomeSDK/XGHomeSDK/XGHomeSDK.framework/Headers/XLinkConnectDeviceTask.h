//
//  XLinkConnectDeviceTask.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/2/13.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "XLinkTask.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, XDeviceConnectionPolicy) {
    XDeviceConnectionPolicyAuto = 0,//自动连接策略
    XDeviceConnectionPolicyLocalOnly = 1,//只进行本地连接
    XDeviceConnectionPolicyLocalFirst = 2,//优先本地连接
    XDeviceConnectionPolicyCloudOnly = 3,//只进行云端连接
    XDeviceConnectionPolicyCloudFirst = 4,//优先云端连接
};

@class XDevice;


@interface XLinkConnectDeviceTask : XLinkTask
///要连接的设备
@property(strong, nonatomic) XDevice *device;

///连接的策略
@property(assign, nonatomic) XDeviceConnectionPolicy connectionPolicy;

/**
 构建连接设备任务
 
 @param device 要连接的设备
 @param timeout 设置超时，单位毫秒，默认10秒
 @param completionHandler 任务完成后回调
 @return XLinkConnectDeviceTask
 */
+ (instancetype)connectDeviceTaskWithDevice:(XDevice *)device
                           connectionPolicy:(XDeviceConnectionPolicy)connectionPolicy
                                    timeout:(NSUInteger)timeout
                              completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;

/**
 构建连接设备任务 并启动
 
 @param device 要连接的设备
 @param timeout 设置超时，单位毫秒，默认10秒
 @param completionHandler 任务完成后回调
 @return XLinkConnectDeviceTask
 */
+ (instancetype)scheduledConnectDeviceTaskWithDevice:(XDevice *)device
                           connectionPolicy:(XDeviceConnectionPolicy)connectionPolicy
                                    timeout:(NSUInteger)timeout
                          completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;


@end

//以下是废弃的方法，不建议使用，不久的将来会删除
@interface XLinkConnectDeviceTask (XLinkDeprecated)

/**
 构建连接设备任务
 
 @param device 要连接的设备
 @param timeout 设置超时，单位毫秒，默认10秒
 @param completeBlock 任务完成后回调
 @return XLinkConnectDeviceTask
 */
+ (instancetype)connectDeviceTaskWithDevice:(XDevice *)device
                                withTimeOut:(NSUInteger)timeout
                          withCompleteBlock:(OnTaskCompleteBlock)completeBlock NS_DEPRECATED(2_0, 2_0, 2_0, 2_0, "已废弃方法，使用+connectDeviceTaskWithDevice:connectionPolicy:timeout:completeBlock:替换,以后的版本将可能会删除此方法");

@end
NS_ASSUME_NONNULL_END
