//
//  XLinkGatewayTriggerBatchHandleTask.h
//  XLinkGatewaySDK
//
//  Created by AllenKwok on 2018/5/30.
//  Copyright © 2018年 www.xlink.cn. All rights reserved.
//

#import "XLinkSendPolicyTask.h"
#import "XDevice.h"
#import "XLinkTrigger.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, XLinkTriggerBatchHandleAction) {
    XLinkTriggerBatchHandleActionAdd,//批量添加触发器
    XLinkTriggerBatchHandleActionRemove,//批量删除触发器
    XLinkTriggerBatchHandleActionUpdate,//批量修改触发器
};

typedef NS_ENUM(NSUInteger, XLinkTriggerBatchHandleLinkageFlag) {
    XLinkTriggerBatchHandleLinkageFlagNoLinkage,//触发器之间不关联
    XLinkTriggerBatchHandleLinkageFlagAutoLinkage,//触发器之间自动关联
};

@interface XLinkGatewayTriggerBatchHandleTask : XLinkSendPolicyTask

///传入网关设备
@property(strong, nonatomic) XDevice *gatewayDevice;

///触发器列表
@property(copy, nonatomic) NSArray <XLinkTrigger *>*triggerArray;

///触发器管理动作
@property(assign, nonatomic) XLinkTriggerBatchHandleAction action;

///触发器之间是否关联
@property (assign, nonatomic) XLinkTriggerBatchHandleLinkageFlag linkageFlag;

/**
 构建批量管理触发器的任务

 @param gatewayDevice 网关设备
 @param triggerArray 需要处理的触发器列表
 @param action 需要处理的动作
 @param flag 是否自动关联
 @param timeout 任务的超时时间
 @param completionHandler 完成后的回调
 @return 批量管理触发器的任务
 */
+ (instancetype)triggerBatchHandleTaskGatewayDevice:(XDevice *)gatewayDevice
                                       triggerArray:(NSArray *)triggerArray
                                       handleAction:(XLinkTriggerBatchHandleAction)action
                                        linkageFlag:(XLinkTriggerBatchHandleLinkageFlag)flag
                                            timeout:(NSUInteger)timeout
                                  completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;

/**
 构建批量管理触发器的任务 并启动
 
 @param gatewayDevice 网关设备
 @param triggerArray 需要处理的触发器列表
 @param action 需要处理的动作
 @param flag 是否自动关联
 @param timeout 任务的超时时间
 @param completionHandler 完成后的回调
 @return 批量管理触发器的任务
 */
+ (instancetype)scheduledTriggerBatchHandleTaskGatewayDevice:(XDevice *)gatewayDevice
                                                triggerArray:(NSArray *)triggerArray
                                                handleAction:(XLinkTriggerBatchHandleAction)action
                                                 linkageFlag:(XLinkTriggerBatchHandleLinkageFlag)flag
                                                     timeout:(NSUInteger)timeout
                                           completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;

@end
NS_ASSUME_NONNULL_END
