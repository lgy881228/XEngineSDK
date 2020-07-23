//
//  XLinkShareDeviceTask.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/6/19.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "XLinkTask.h"
#import "XLinkThirdPartyAuthorizeTask.h"
#import "XDevice.h"

NS_ASSUME_NONNULL_BEGIN

//分享的方式
typedef NS_ENUM(NSUInteger, XLinkShareDeviceMode) {
    XLinkShareDeviceModeApp,//通过账号分享
    XLinkShareDeviceModeQrcode,//通过二维码分享
    XLinkShareDeviceModeEmail,//通过发送邮件分享
};

//分享完成后的回调
typedef void (^XLinkShareDeviceTaskCompletionHandler)(NSDictionary *result, XLinkErrorCode code);

@interface XLinkShareDeviceTask : XLinkTask

///设备
@property(strong, nonatomic) XDevice *device;

///对方账号（邮箱或者手机号）
@property(copy, nonatomic) NSString *account;

///用户来源，第三方来源用户需要填
@property(assign, nonatomic) XLinkUserSourceType sourceType;

///分享的方式
@property(assign, nonatomic) XLinkShareDeviceMode shareDeviceMode;

///过期时间（单位秒）
@property(copy, nonatomic) NSString *expired;

///对设备的控制权限，R可读，W可写，RW可读可写；默认为null相当于RW；
@property(copy, nonatomic) NSString *authority;


/**
 构建通过账号分享设备任务
 
 @param device 设备
 @param account 对方账号（邮箱或者手机号）
 @param expired 分享有效期时间（单位秒）
 @param shareDeviceMode 分享的方式
 @param authority 对设备的控制权限，R可读，W可写，RW可读可写；默认为null相当于RW；
 @param timeout task超时时间
 @param completionHandler 完成后的回调
 @return XLinkShareDeviceTask
 */
+ (instancetype)shareDeviceTaskWithDevice:(XDevice *)device
                                  account:(NSString *)account
                                  expired:(NSString *)expired
                                shareMode:(XLinkShareDeviceMode)shareDeviceMode
                                authority:(NSString *)authority
                                  timeout:(NSUInteger)timeout
                        completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;

/**
 构建通过openId分享设备任务
 
 @param device 设备
 @param openId 对方openId
 @param sourceType 账号来源
 @param expired 分享有效期时间（单位秒）
 @param shareDeviceMode 分享的方式
 @param authority 对设备的控制权限，R可读，W可写，RW可读可写；默认为null相当于RW；
 @param timeout task超时时间
 @param completionHandler 完成后的回调
 @return XLinkShareDeviceTask
 */
+ (instancetype)shareDeviceTaskWithDevice:(XDevice *)device
                                   openId:(NSString *)openId
                               sourceType:(XLinkUserSourceType)sourceType
                                  expired:(NSString *)expired
                                shareMode:(XLinkShareDeviceMode)shareDeviceMode
                                authority:(NSString *)authority
                                  timeout:(NSUInteger)timeout
                        completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;

/**
 构建通过账号分享设备任务 并启动
 
 @param device 设备
 @param account 对方账号（邮箱或者手机号）
 @param expired 分享有效期时间（单位秒）
 @param shareDeviceMode 分享的方式
 @param authority 对设备的控制权限，R可读，W可写，RW可读可写；默认为null相当于RW；
 @param timeout task超时时间
 @param completionHandler 完成后的回调
 @return XLinkShareDeviceTask
 */
+ (instancetype)scheduledShareDeviceTaskWithDevice:(XDevice *)device
                                           account:(NSString *)account
                                           expired:(NSString *)expired
                                         shareMode:(XLinkShareDeviceMode)shareDeviceMode
                                         authority:(NSString *)authority
                                           timeout:(NSUInteger)timeout
                                 completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;

/**
 构建通过openId分享设备任务 并启动
 
 @param device 设备
 @param openId 对方openId
 @param sourceType 账号来源
 @param expired 分享有效期时间（单位秒）
 @param shareDeviceMode 分享的方式
 @param authority 对设备的控制权限，R可读，W可写，RW可读可写；默认为null相当于RW；
 @param timeout task超时时间
 @param completionHandler 完成后的回调
 @return XLinkShareDeviceTask
 */
+ (instancetype)scheduledShareDeviceTaskWithDevice:(XDevice *)device
                                            openId:(NSString *)openId
                                        sourceType:(XLinkUserSourceType)sourceType
                                           expired:(NSString *)expired
                                         shareMode:(XLinkShareDeviceMode)shareDeviceMode
                                         authority:(NSString *)authority
                                           timeout:(NSUInteger)timeout
                                 completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;

@end

//以下是废弃的方法，不建议使用，不久的将来会删除
@interface XLinkShareDeviceTask (XLinkDeprecated)

/**
 构建通过账号分享设备任务
 
 @param device 设备
 @param account 对方账号（邮箱或者手机号）
 @param expired 分享有效期时间（单位秒）
 @param shareDeviceMode 分享的方式
 @param authority 对设备的控制权限，R可读，W可写，RW可读可写；默认为null相当于RW；
 @param timeout task超时时间
 @param shareCompleteBlock 完成后的回调
 @return XLinkShareDeviceTask
 */
+ (instancetype)shareDeviceTaskWithDevice:(XDevice *)device
                              withAccount:(NSString *)account
                              withExpired:(NSString *)expired
                            withShareMode:(XLinkShareDeviceMode)shareDeviceMode
                            withAuthority:(NSString *)authority
                              withTimeOut:(NSUInteger)timeout
         withShareDeviceTaskCompleteBlock:(XLinkShareDeviceTaskCompletionHandler)shareCompleteBlock NS_DEPRECATED(2_0, 2_0, 2_0, 2_0, "已废弃方法，使用+shareDeviceTaskWithDevice:account:expired:shareMode:authority:timeout:completeBlock:替换,以后的版本将可能会删除此方法");

/**
 构建通过openId分享设备任务
 
 @param device 设备
 @param openId 对方openId
 @param sourceType 账号来源
 @param expired 分享有效期时间（单位秒）
 @param shareDeviceMode 分享的方式
 @param authority 对设备的控制权限，R可读，W可写，RW可读可写；默认为null相当于RW；
 @param timeout task超时时间
 @param shareCompleteBlock 完成后的回调
 @return XLinkShareDeviceTask
 */
+ (instancetype)shareDeviceTaskWithDevice:(XDevice *)device
                               withOpenId:(NSString *)openId
                           withSourceType:(XLinkUserSourceType)sourceType
                              withExpired:(NSString *)expired
                            withShareMode:(XLinkShareDeviceMode)shareDeviceMode
                            withAuthority:(NSString *)authority
                              withTimeOut:(NSUInteger)timeout
         withShareDeviceTaskCompleteBlock:(XLinkShareDeviceTaskCompletionHandler)shareCompleteBlock NS_DEPRECATED(2_0, 2_0, 2_0, 2_0, "已废弃方法，使用+shareDeviceTaskWithDevice:openId:sourceType:expired:shareMode:authority:timeout:completeBlock:替换,以后的版本将可能会删除此方法");

@end
NS_ASSUME_NONNULL_END
