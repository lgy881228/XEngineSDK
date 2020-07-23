//
//  XLinkCategorySetDatapointTask.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/3/31.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "XLinkSendPolicyTask.h"
#import "XLinkDataPoint.h"
#import "XLinkCategory.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^OnCategorySetDatapointCompleteBlock)(XLinkErrorCode code);

@interface XLinkGatewayCategorySetDataPointTask : XLinkSendPolicyTask

///传入网关设备
@property(strong, nonatomic) XDevice *gatewayDevice;

///传入网关分组
@property(strong, nonatomic) XLinkCategory *category;

///key是productId，value是XLinkDataPoint数组的字典
@property(strong, nonatomic) NSDictionary <NSString *, NSArray <XLinkDataPoint *> *> *productIdDataPointDict;

/**
 触发器管理
 
 @param gatewayDevice 传入网关设备。
 @param category 传入网关分组
 @param productIdDataPointDict 目标设备的pid:dataPoint 的字典
 @param timeout 超时时间,建议15秒
 @param completionHandler 完成后回调
 @return 触发器管理task
 */
+ (instancetype)categorySetDatapointTaskWithGatewayDevice:(XDevice *)gatewayDevice
                                                 category:(XLinkCategory *)category
                                     productDatapointDict:(NSDictionary <NSString *, NSArray <XLinkDataPoint *> *> *)productIdDataPointDict timeout:(NSUInteger)timeout
                                        completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;

/**
 触发器管理 并启动
 
 @param gatewayDevice 传入网关设备。
 @param category 传入网关分组
 @param productIdDataPointDict 目标设备的pid:dataPoint 的字典
 @param timeout 超时时间,建议15秒
 @param completionHandler 完成后回调
 @return 触发器管理task
 */
+ (instancetype)scheduledCategorySetDatapointTaskWithGatewayDevice:(XDevice *)gatewayDevice
                                                          category:(XLinkCategory *)category
                                              productDatapointDict:(NSDictionary <NSString *, NSArray <XLinkDataPoint *> *> *)productIdDataPointDict
                                                           timeout:(NSUInteger)timeout
                                                 completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;

@end

//以下是废弃的方法，不建议使用，不久的将来会删除
@interface XLinkGatewayCategorySetDataPointTask (XLinkDeprecated)

/**
 触发器管理
 
 @param gatewayDevice 传入网关设备。
 @param category 传入网关分组
 @param productIdDataPointDict 目标设备的pid:dataPoint 的字典
 @param timeout 超时时间,建议15秒
 @param completeBlock 完成后回调
 @return 触发器管理task
 */
+ (instancetype)categorySetDatapointTaskWithGatewayDevice:(XDevice *)gatewayDevice
                                             withCategory:(XLinkCategory *)category
                                 withProductDatapointDict:(NSDictionary <NSString *, NSArray <XLinkDataPoint *> *> *)productIdDataPointDict
                                              withTimeOut:(NSUInteger)timeout
                                        withCompleteBlock:(OnCategorySetDatapointCompleteBlock)completeBlock NS_DEPRECATED(2_0, 2_0, 2_0, 2_0, "已废弃方法，请使用+ categorySetDatapointTaskWithGatewayDevice:category:productDatapointDict:timeout:completeBlock:替换,以后的版本将可能会删除此方法");

@end
NS_ASSUME_NONNULL_END
