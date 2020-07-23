//
//  XLinkGatewayTriggerHandleTask.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/3/31.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "XLinkSendPolicyTask.h"
#import "XLinkTrigger.h"
#import "XDevice.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, XLinkHandleTriggerAction) {
    XLinkHandleTriggerActionTrigger,//触发某个触发器
    XLinkHandleTriggerActionAdd,//添加触发器
    XLinkHandleTriggerActionRemove,//删除触发器
    XLinkHandleTriggerActionUpdate,//修改触发器，要求triggerId相同
    XLinkHandleTriggerActionGet,//获取触发器列表
};

typedef void (^OnHandleTriggerCompleteBlock)(NSArray <XLinkTrigger *> *triggerArray, XLinkErrorCode code);

@interface XLinkGatewayTriggerHandleTask : XLinkSendPolicyTask

///触发器
@property(strong, nonatomic) XLinkTrigger *trigger;

///触发器管理动作
@property(assign, nonatomic) XLinkHandleTriggerAction action;

///传入网关设备
@property(strong, nonatomic) XDevice *gatewayDevice;

///完成后回调
@property(copy, nonatomic,nullable) OnHandleTriggerCompleteBlock handleTriggercompleteBlock;


/**
 触发器管理
 
 @param trigger 目标触发器
 @param action 触发器管理动作
 @param gatewayDevice 传入网关设备。
 @param timeout 超时时间,建议15秒
 @param completionHandler 完成后回调
 @return 触发器管理task
 */
+ (instancetype)triggerHandleTaskWithTrigger:(XLinkTrigger * _Nullable)trigger
                                      action:(XLinkHandleTriggerAction)action
                               gatewayDevice:(XDevice *)gatewayDevice
                                     timeout:(NSUInteger)timeout
                           completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;



/**
 触发器管理 并启动
 
 @param trigger 目标触发器
 @param action 触发器管理动作
 @param gatewayDevice 传入网关设备。
 @param timeout 超时时间,建议15秒
 @param completionHandler 完成后回调
 @return 触发器管理task
 */
+ (instancetype)scheduledTriggerHandleTaskWithTrigger:(XLinkTrigger * _Nullable)trigger
                                               action:(XLinkHandleTriggerAction)action
                                        gatewayDevice:(XDevice *)gatewayDevice
                                              timeout:(NSUInteger)timeout
                                    completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;


@end

//以下是废弃的方法，不建议使用，不久的将来会删除
@interface XLinkGatewayTriggerHandleTask (XLinkDeprecated)

/**
 触发器管理
 
 @param trigger 目标触发器
 @param action 触发器管理动作
 @param gatewayDevice 传入网关设备。
 @param timeout 超时时间,建议15秒
 @param completeBlock 完成后回调
 @return 触发器管理task
 */
+ (instancetype)handleTriggerTaskWithTrigger:(XLinkTrigger *)trigger
                                  withAction:(XLinkHandleTriggerAction)action
                           withGatewayDevice:(XDevice *)gatewayDevice
                                 withTimeOut:(NSUInteger)timeout
                           withCompleteBlock:(OnHandleTriggerCompleteBlock)completeBlock NS_DEPRECATED(2_0, 2_0, 2_0, 2_0, "已废弃方法，请使用+handleTriggerTaskWithTrigger:action: gatewayDevice:timeout:completeBlock:替换,以后的版本将可能会删除此方法");

@end

NS_ASSUME_NONNULL_END
