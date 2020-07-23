//
//  XLinkGatewayCategoryDeviceHandleTask.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/3/31.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "XLinkSendPolicyTask.h"
#import "XLinkCategory.h"
#import "XDevice.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^OnHandleDeviceCategoryCompleteBlock)(NSArray <XLinkCategory *> *categoryArray, XLinkErrorCode code);

//管理分组设备的操作
typedef NS_ENUM(NSUInteger, XLinkHandleDeviceCategoryAction) {
    XLinkHandleDeviceCategoryActionAdd,// 添加设备到分组
    XLinkHandleDeviceCategoryActionRemove,// 从分组中删除设备
    XLinkHandleDeviceCategoryActionSyncList,// 同步分组下的设备列表
};


@interface XLinkGatewayCategoryDeviceHandleTask : XLinkSendPolicyTask

///传入存储分组信息的网关设备
@property(strong, nonatomic) XDevice *gatewayDevice;

///目标分组
@property(strong, nonatomic) XLinkCategory *category;

///传入目标设备数组
@property(strong, nonatomic,nullable) NSArray <XDevice *> *targetDeviceArray;

///要进行的操作
@property(assign, nonatomic) XLinkHandleDeviceCategoryAction action;


/**
 构建分组设备管理任务
 
 @param gatewayDevice 传入存储分组信息的网关设备
 @param category 目标分组
 @param targetDeviceArray 传入目标设备数组
 @param action 要进行的操作
 @param timeout 超时时间,建议15秒
 @param completionHandler 完成后的回调 处理成功。返回目标分组。
 如果动作为XLinkHandleDeviceCategoryActionSyncList，则目标分组（category）的devices属性会被更新。
 @return 分组管理Task
 */
+ (instancetype)categoryDeviceHandleTaskWithGatewayDevice:(XDevice *)gatewayDevice
                                                 category:(XLinkCategory *)category
                                        targetDeviceArray:(NSArray <XDevice *> * _Nullable)targetDeviceArray
                                                   action:(XLinkHandleDeviceCategoryAction)action
                                                  timeout:(NSUInteger)timeout
                                        completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;



/**
 构建分组设备管理任务 并启动
 
 @param gatewayDevice 传入存储分组信息的网关设备
 @param category 目标分组
 @param targetDeviceArray 传入目标设备数组
 @param action 要进行的操作
 @param timeout 超时时间,建议15秒
 @param completionHandler 完成后的回调 处理成功。返回目标分组。
 如果动作为XLinkHandleDeviceCategoryActionSyncList，则目标分组（category）的devices属性会被更新。
 @return 分组管理Task
 */
+ (instancetype)scheduledCategoryDeviceHandleTaskWithGatewayDevice:(XDevice *)gatewayDevice
                                                          category:(XLinkCategory *)category
                                                 targetDeviceArray:(NSArray <XDevice *> * _Nullable)targetDeviceArray
                                                            action:(XLinkHandleDeviceCategoryAction)action
                                                           timeout:(NSUInteger)timeout
                                                 completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;

@end

//以下是废弃的方法，不建议使用，不久的将来会删除
@interface XLinkGatewayCategoryDeviceHandleTask (XLinkDeprecated)

/**
 构建分组设备管理任务
 
 @param gatewayDevice 传入存储分组信息的网关设备
 @param category 目标分组
 @param targetDeviceArray 传入目标设备数组
 @param action 要进行的操作
 @param timeout 超时时间,建议15秒
 @param completeBlock 完成后的回调
 @return 分组管理Task
 */
+ (instancetype)handleDeviceCategoryTaskWithGatewayDevice:(XDevice *)gatewayDevice
                                             withGategory:(XLinkCategory *)category
                                    withTargetDeviceArray:(NSArray <XDevice *> * _Nullable)targetDeviceArray
                                               withAction:(XLinkHandleDeviceCategoryAction)action
                                              withTimeOut:(NSUInteger)timeout
                                        withCompleteBlock:(OnHandleDeviceCategoryCompleteBlock)completeBlock NS_DEPRECATED(2_0, 2_0, 2_0, 2_0, "已废弃方法，请使用+ handleDeviceCategoryTaskWithGatewayDevice:category:targetDeviceArray:action:timeout:completeBlock:替换,以后的版本将可能会删除此方法");

@end
NS_ASSUME_NONNULL_END
