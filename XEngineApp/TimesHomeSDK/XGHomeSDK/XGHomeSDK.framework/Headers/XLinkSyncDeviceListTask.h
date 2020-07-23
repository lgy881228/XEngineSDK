//
//  XLinkSyncDeviceListTask.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/4/28.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

//将当前用户的设备从云端同步到本地。要求设备和当前用户之间有订阅关系。任务完成后默认自动发起本地连接和云端连接。

#import "XLinkTask.h"
#import "XDevice.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^XLinkSyncDeviceListCompletionHandler)(NSArray <XDevice *> *devices, XLinkErrorCode code);

@interface XLinkSyncDeviceListTask : XLinkTask

///设备列表版本号，默认为0
@property(assign, nonatomic) int version;

///同步列表完成后是否连接本地
@property(assign, nonatomic) BOOL connectLocal;


/**
 同步设备列表
 
 @param version 版本号(第一次获取需要传入0，才会返回所有的设备。)
 @param timeout 超时时间
 @param connectLocal 是否自动进行本地连接，默认 true
 @param completionHandler 完成后的回调
 @return XLinkSyncDeviceListTask
 */
+ (instancetype)syncDeviceListTaskWithVersion:(int)version
                                      timeout:(NSUInteger)timeout
                                 connectLocal:(BOOL)connectLocal
                                completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;

/**
 同步设备列表 并启动
 
 @param version 版本号(第一次获取需要传入0，才会返回所有的设备。)
 @param timeout 超时时间
 @param connectLocal 是否自动进行本地连接，默认 true
 @param completionHandler 完成后的回调
 @return XLinkSyncDeviceListTask
 */
+ (instancetype)scheduledSyncDeviceListTaskWithVersion:(int)version
                                               timeout:(NSUInteger)timeout
                                          connectLocal:(BOOL)connectLocal
                                     completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;

@end


//以下是废弃的方法，不建议使用，不久的将来会删除
@interface XLinkSyncDeviceListTask (XLinkDeprecated)

/**
 同步设备列表
 
 @param version 版本号(第一次获取需要传入0，才会返回所有的设备。)
 @param timeout 超时时间
 @param connectLocal 是否自动进行本地连接，默认 true
 @param syncCompleteBlock 完成后的回调
 @return XLinkSyncDeviceListTask
 */
+ (instancetype)syncDeviceListTaskWithVersion:(int)version
                                  withTimeout:(NSUInteger)timeout
                             withConnectLocal:(BOOL)connectLocal
                            withCompleteBlock:(XLinkSyncDeviceListCompletionHandler)syncCompleteBlock NS_DEPRECATED(2_0, 2_0, 2_0, 2_0, "已废弃方法，请使用+syncDeviceListTaskWithVersion:timeout:connectLocal:completeBlock:替换,以后的版本将可能会删除此方法");

@end
NS_ASSUME_NONNULL_END
