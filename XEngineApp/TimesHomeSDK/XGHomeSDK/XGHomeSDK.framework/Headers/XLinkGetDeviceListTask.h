//
//  XLinkGetDeviceListTask.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/2/13.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "XLinkTask.h"
#import "XDevice.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^XLinkGetDeviceTaskCompletionHandler)(NSArray <XDevice *> *devices, XLinkErrorCode code);

@interface XLinkGetDeviceListTask : XLinkTask

/**
 构建获取设备列表任务
 
 @param version 版本号，默认值为0
 @param timeout 超时时间
 @param completionHandler 完成后回调
 @return XLinkGetDeviceListTask
 */
+ (instancetype)getDeviceListTaskWithVersion:(int)version
                                     timeout:(NSUInteger)timeout
                           completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;

/**
 构建获取设备列表任务 并启动
 
 @param version 版本号，默认值为0
 @param timeout 超时时间
 @param completionHandler 完成后回调
 @return XLinkGetDeviceListTask
 */
+ (instancetype)scheduledGetDeviceListTaskWithVersion:(int)version
                                              timeout:(NSUInteger)timeout
                                    completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;

@end


//以下是废弃的方法，不建议使用，不久的将来会删除
@interface XLinkGetDeviceListTask (XLinkDeprecated)

/**
 构建获取设备列表任务
 
 @param userId 用户id
 @param version 版本号，默认值为0
 @param timeout 超时时间
 @param completeBlock 完成后回调
 @return XLinkGetDeviceListTask
 */
+ (instancetype)getDeviceListTaskWithUserId:(NSNumber *)userId
                                withVersion:(int)version
                                withTimeOut:(NSUInteger)timeout
                          withCompleteBlock:(XLinkGetDeviceTaskCompletionHandler)completeBlock NS_DEPRECATED(2_0, 2_0, 2_0, 2_0, "已废弃方法，使用+getDeviceListTaskWithVersion:timeout:completeBlock:替换,以后的版本将可能会删除此方法");

@end
NS_ASSUME_NONNULL_END
