//
//  XLinkHandleShareDeviceTask.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/6/20.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "XLinkTask.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, XLinkHandleShareDeviceAction) {
    XLinkHandleShareDeviceActionAccept,//接受分享
    XLinkHandleShareDeviceActionDeny,//拒绝分享
    XLinkHandleShareDeviceActionCancel,//取消分享
    XLinkHandleShareDeviceActionDeleteRecord,//删除分享记录
    XLinkHandleShareDeviceActionAcceptQrCode,//接受二维码分享
};

@interface XLinkHandleShareDeviceTask : XLinkTask

///邀请码
@property(copy, nonatomic) NSString *inviteCode;

///处理的动作，接受或者取消
@property(assign, nonatomic) XLinkHandleShareDeviceAction action;

/**
 构建处理分享设备任务
 
 @param inviteCode 分享邀请码
 @param action 处理的动作，接受或者取消
 @param completionHandler 完成后的回调
 @return XLinkHandleShareDeviceTask
 */
+ (instancetype)handleShareDeviceTaskWithInviteCode:(NSString *)inviteCode
                                  handleShareAction:(XLinkHandleShareDeviceAction)action
                                            timeout:(NSUInteger)timeout
                                  completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;

/**
 构建处理分享设备任务 并启动
 
 @param inviteCode 分享邀请码
 @param action 处理的动作，接受或者取消
 @param completionHandler 完成后的回调
 @return XLinkHandleShareDeviceTask
 */
+ (instancetype)scheduledHandleShareDeviceTaskWithInviteCode:(NSString *)inviteCode
                                           handleShareAction:(XLinkHandleShareDeviceAction)action
                                                     timeout:(NSUInteger)timeout
                                           completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;

@end

//以下是废弃的方法，不建议使用，不久的将来会删除
@interface XLinkHandleShareDeviceTask (XLinkDeprecated)

/**
 构建处理分享设备任务
 
 @param inviteCode 分享邀请码
 @param action 处理的动作，接受或者取消
 @param completeBlock 完成后的回调
 @return XLinkHandleShareDeviceTask
 */
+ (instancetype)handleShareDeviceTaskWithInvitedCode:(NSString *)inviteCode
                               withHandleShareAction:(XLinkHandleShareDeviceAction)action
                                         withTimeOut:(NSUInteger)timeout
                               withTaskCompleteBlock:(OnTaskCompleteBlock)completeBlock NS_DEPRECATED(2_0, 2_0, 2_0, 2_0, "已废弃方法，使用+handleShareDeviceTaskWithInviteCode:handleShareAction:timeout:completeBlock:替换,以后的版本将可能会删除此方法");

@end

NS_ASSUME_NONNULL_END
