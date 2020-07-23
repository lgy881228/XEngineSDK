//
//  XLinkGatewaySyncSubDeviceListTask.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/12/6.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "XLinkTask.h"
@class XDevice;

NS_ASSUME_NONNULL_BEGIN

typedef void (^OnSyncSubDeviceListCompleteBlock)(NSArray <XDevice *> *devices, XLinkErrorCode code);

@interface XLinkGatewaySyncSubDeviceListTask : XLinkTask

///设备列表版本号，默认为0
@property(assign, nonatomic) int version;

///同步列表完成后是否连接本地
@property(assign, nonatomic) BOOL connectLocal;

///需要同步子设备的网关
@property(strong, nonatomic) XDevice *gatewayDevice;


/**
 同步网关设备下子设备列表
 
 @param device 网关设备
 @param timeout 超时时间
 @param connectLocal 是否自动进行本地连接，默认 true
 @param completionHandler 完成后的回调
 @return task
 */
+ (instancetype)syncSubDeviceListTaskWithDevice:(XDevice *)device
                                        timeout:(NSUInteger)timeout
                                   connectLocal:(BOOL)connectLocal
                              completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;


/**
 同步网关设备下子设备列表 并启动
 
 @param device 网关设备
 @param timeout 超时时间
 @param connectLocal 是否自动进行本地连接，默认 true
 @param completionHandler 完成后的回调
 @return task
 */
+ (instancetype)scheduledSyncSubDeviceListTaskWithDevice:(XDevice *)device
                                                 timeout:(NSUInteger)timeout
                                            connectLocal:(BOOL)connectLocal
                                       completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;


@end

//以下是废弃的方法，不建议使用，不久的将来会删除
@interface XLinkGatewaySyncSubDeviceListTask (XLinkDeprecated)

/**
 同步网关设备下子设备列表
 
 @param version 版本号
 @param device 网关设备
 @param timeout 超时时间
 @param connectLocal 是否自动进行本地连接，默认 true
 @param syncCompleteBlock 完成后的回调
 @return task
 */
+ (instancetype)syncDeviceListTaskWithVersion:(int)version
                                   withDevice:(XDevice *)device
                                  withTimeout:(NSUInteger)timeout
                             withConnectLocal:(BOOL)connectLocal
                            withCompleteBlock:(OnSyncSubDeviceListCompleteBlock)syncCompleteBlock NS_DEPRECATED(2_0, 2_0, 2_0, 2_0, "已废弃方法，请使用+ syncSubDeviceListTaskWithDevice:timeout: connectLocal:completeBlock:替换,以后的版本将可能会删除此方法");

@end
NS_ASSUME_NONNULL_END
