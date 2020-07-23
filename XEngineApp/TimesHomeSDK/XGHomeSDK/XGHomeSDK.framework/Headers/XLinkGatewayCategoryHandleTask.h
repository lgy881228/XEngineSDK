//
//  XLinkGatewayCategoryHandleTask.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/3/31.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "XLinkSendPolicyTask.h"
#import "XLinkCategory.h"
#import "XDevice.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^OnHandleCategoryCompleteBlock)(NSArray <XLinkCategory *> *categoryArray, XLinkErrorCode code);

//处理分组的操作
typedef NS_ENUM(NSUInteger, XLinkHandleCategoryAction) {
    XLinkHandleCategoryActionAdd,// 新增分组信息
    XLinkHandleCategoryActionRemove,// 删除分组信息
    XLinkHandleCategoryActionGet,// 获取分组信息。当category传入不为nil时，获取指定分组的信息。否则获取当前网关下的所有分组信息。
    XLinkHandleCategoryActionUpdate,// 更新分组信息
};

@interface XLinkGatewayCategoryHandleTask : XLinkSendPolicyTask

///传入存储分组信息的网关设备
@property(strong, nonatomic) XDevice *gatewayDevice;

///目标分组
@property(strong, nonatomic) XLinkCategory *category;

///要进行的操作
@property(assign, nonatomic) XLinkHandleCategoryAction action;


/**
 分组管理

 @param gatewayDevice 传入存储分组信息的网关设备
 @param category 目标分组
 @param action 要进行的操作
 @param timeout 超时时间,建议15秒
 @param completionHandler 完成后的回调
 @return 分组管理Task
 */
+ (instancetype)categoryHandleTaskWithGatewayDevice:(XDevice *)gatewayDevice
                                           category:(XLinkCategory * _Nullable)category
                                             action:(XLinkHandleCategoryAction)action
                                            timeout:(NSUInteger)timeout
                                  completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;

/**
 分组管理 并启动
 
 @param gatewayDevice 传入存储分组信息的网关设备
 @param category 目标分组
 @param action 要进行的操作
 @param timeout 超时时间,建议15秒
 @param completionHandler 完成后的回调
 @return 分组管理Task
 */
+ (instancetype)scheduledCategoryHandleTaskWithGatewayDevice:(XDevice *)gatewayDevice
                                                    category:(XLinkCategory * _Nullable)category
                                                      action:(XLinkHandleCategoryAction)action
                                                     timeout:(NSUInteger)timeout
                                           completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;


@end

//以下是废弃的方法，不建议使用，不久的将来会删除
@interface XLinkGatewayCategoryHandleTask (XLinkDeprecated)

/**
 分组管理
 
 @param gatewayDevice 传入存储分组信息的网关设备
 @param category 目标分组
 @param action 要进行的操作
 @param timeout 超时时间,建议15秒
 @param completeBlock 完成后的回调
 @return 分组管理Task
 */
+ (instancetype)handleCategoryTaskWithGatewayDevice:(XDevice *)gatewayDevice
                                       withGategory:(XLinkCategory *)category
                                         withAction:(XLinkHandleCategoryAction)action
                                        withTimeOut:(NSUInteger)timeout
                                  withCompleteBlock:(OnHandleCategoryCompleteBlock)completeBlock NS_DEPRECATED(2_0, 2_0, 2_0, 2_0, "已废弃方法，请使用+handleCategoryTaskWithGatewayDevice:category:action:timeout:completeBlock:替换,以后的版本将可能会删除此方法");

@end

NS_ASSUME_NONNULL_END
