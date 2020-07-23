//
//  XLinkGatewayScanSubDeviceTask.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/8/23.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "XLinkSendPolicyTask.h"
#import "XLinkScanDeviceTask.h"

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSUInteger, XLinkSearchFlag) {
    XLinkSearchFlagReturnDeviceListAndSendSearch = 0,//网关返回子设备的同时向PTP发送一个Search
    XLinkSearchFlagReturnDeviceList = 1, //网关只需要返回子设备
    XLinkSearchFlagSendSearch = 2, //网关只需要向PTP发送一个Search
    XLinkSearchFlagSendCancelSearch = 3,//网关只需要向PTP发送一个Cancel Search
    XLinkSearchFlagReturnDeviceListAndSendCancelSearch = 5//网关返回子设备的同时向PTP发送一个Cancel Search
};

@interface XLinkGatewayScanSubDeviceTask : XLinkSendPolicyTask

///要搜索子设备的网关设备
@property(strong, nonatomic) XDevice *device;

///要扫描子设备的productID数组
@property(copy, nonatomic) NSArray *productIdArray;

///扫描标志
@property (assign, nonatomic) XLinkSearchFlag searchFlag;

///扫描到设备后回调
@property(copy, nonatomic) XLinkDidDiscoveredDeviceHandler discoveredDeviceHandler;

/**
 构建扫描网关设备下面的子设备任务
 
 @param pidArray productID数组,传入空数组或者nil的时候，返回所有扫描到的子设备
 @param timeout 设置超时时间，单位秒，建议90秒
 @param discoveredDeviceHandler 搜索到设备的回调
 @param completionHandler 搜索完成的回调
 @return 设备任务
 */
+ (instancetype)scanSubDeviceTaskWithGatewayDevice:(XDevice *)device
                                    productIdArray:(NSArray * _Nullable)pidArray
                                           timeout:(NSUInteger)timeout
                        didDiscoveredDeviceHandler:(XLinkDidDiscoveredDeviceHandler)discoveredDeviceHandler
                                 completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;



/**
 构建扫描网关设备下面的子设备任务 并启动
 
 @param pidArray productID数组
 @param timeout 设置超时时间，单位秒，建议90秒
 @param discoveredDeviceHandler 搜索到设备的回调
 @param completionHandler 搜索完成的回调
 @return 设备任务
 */
+ (instancetype)scheduledScanSubDeviceTaskWithGatewayDevice:(XDevice *)device
                                             productIdArray:(NSArray *)pidArray
                                                    timeout:(NSUInteger)timeout
                                 didDiscoveredDeviceHandler:(XLinkDidDiscoveredDeviceHandler)discoveredDeviceHandler
                                          completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;


@end

//以下是废弃的方法，不建议使用，不久的将来会删除
@interface XLinkGatewayScanSubDeviceTask (XLinkDeprecated)

/**
 构建扫描网关设备下面的子设备任务
 
 @param pidArray productID数组,传入空数组或者nil的时候，返回所有扫描到的子设备
 @param timeout 设置超时时间，单位秒，建议90秒
 @param discoveredDeviceHandler 搜索到设备的回调
 @param completeBlock 搜索完成的回调
 @return 设备任务
 */
+ (instancetype)scanDeviceTaskWithProductIds:(NSArray *)pidArray
                                  withDevice:(XDevice * _Nullable)device
                                 withTimeOut:(NSUInteger)timeout
                          withGotDeviceBlock:(XLinkDidDiscoveredDeviceHandler)discoveredDeviceHandler
                           withCompleteBlock:(OnTaskCompleteBlock)completeBlock NS_DEPRECATED(2_0, 2_0, 2_0, 2_0, "已废弃方法，请使用+ scanSubDeviceTaskWithGatewayDevice:productIdArray:                                       timeout:gotDeviceHandler:completeBlock:替换,以后的版本将可能会删除此方法");

@end
NS_ASSUME_NONNULL_END
