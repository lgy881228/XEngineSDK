//
//  XDeviceManager.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/2/14.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XDeviceStateObserver.h"
#import "XDevice.h"
#import "XLinkConnectDeviceTask.h"
#import "XLinkConst.h"

NS_ASSUME_NONNULL_BEGIN

@interface XDeviceManager : NSObject

/**
 单例对象
 */
+ (instancetype)shareManager;


/**
 连接设备
 
 @param device 设备
 */
- (void)connectDevice:(XDevice *)device;

/**
 连接设备

 @param device 设备
 @param connectionPolicy 连接策略
 */
- (void)connectDevice:(XDevice *)device
     withConnectionPolicy:(XDeviceConnectionPolicy)connectionPolicy;

/**
 断开连接设备
 
 @param device 设备
 */
- (void)disconnectDevice:(XDevice *)device;

/**
 断开连接设备本地连接
 
 @param device 设备
 */
- (void)disconnectLocalWithDevice:(XDevice *)device;

/**
 添加一个设备状态变化的更新监听
 
 @param observer 设备状态变化的更新监听
 */
- (void)addDeviceStateObserver:(XDeviceStateObserver *)observer;

/**
 删除一个设备状态变化的更新监听
 
 @param observer 设备状态变化的更新监听
 */
- (void)removeDeviceStateObserver:(XDeviceStateObserver *)observer;

/**
  删除某个设备的所有状态变化的监听

 @param device 设备实体
 */
- (void)removeAllDeviceStateObserverWithDevice:(XDevice *)device;

/**
 清除所有的设备状态监控
 */
- (void)clearDeviceStateObservers;

/**
 获取SDK管理的设备实体
 
 @param macData 设备实体的mac地址
 @return 设备实体
 */
- (XDevice *)getDeviceWithMacAddressData:(NSData *)macData
                               productId:(NSString *)productId;

/**
 获取SDK管理的设备实体
 
 @param macStr 设备实体的mac地址字符串
 @return 设备实体
 */
- (XDevice *)getDeviceWithMacAddressString:(NSString *)macStr
                                 productId:(NSString *)productId;

/**
 获取SDK管理的设备实体
 
 @param deviceId 设备id
 @return 设备实体
 */
- (XDevice *)getDeviceWithDeviceId:(NSUInteger)deviceId;

@end

//以下是废弃的方法，不建议使用，不久的将来会删除
@interface XDeviceManager (XLinkDeprecated)


/**
 获取SDK管理的设备实体
 
 @param macData 设备实体的mac地址
 @return 设备实体
 */
- (XDevice *)getDeviceWithMacAddressData:(NSData *)macData
                           withProductId:(NSString *)productId NS_DEPRECATED(2_0, 2_0, 2_0, 2_0, "已废弃方法，请使用-getDeviceWithMacAddressData:withProductId:替换,以后的版本将可能会删除此方法");

/**
 获取SDK管理的设备实体
 
 @param macStr 设备实体的mac地址字符串
 @return 设备实体
 */
- (XDevice *)getDeviceWithMacAddressString:(NSString *)macStr
                             withProductId:(NSString *)productId NS_DEPRECATED(2_0, 2_0, 2_0, 2_0, "已废弃方法，请使用-getDeviceWithMacAddressString:withProductId:替换,以后的版本将可能会删除此方法");

@end

NS_ASSUME_NONNULL_END
