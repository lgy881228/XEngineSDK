//
//  XLinkUserAuthorizeTask.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/6/2.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "XLinkAuthorizeBaseTask.h"

NS_ASSUME_NONNULL_BEGIN


@interface XLinkUserAuthorizeTask : XLinkAuthorizeBaseTask

///企业ID，默认值为nil。
@property(copy, nonatomic) NSString *corpId;

///账号（email或者手机号码），默认值为nil。
@property(copy, nonatomic) NSString *account;

///密码，默认值为nil。
@property(copy, nonatomic) NSString *password;


/**
 构建用户使用账号密码登陆任务
 
 @param account 账号
 @param password 密码
 @param cropId 企业id
 @param timeout 设置超时时间，单位秒，建议15秒
 @param completionHandler 完成后的回调
 @return XLinkUserAuthorizeTask
 */
+ (instancetype)userAuthorizeTaskWithAccount:(NSString *)account
                                    password:(NSString *)password
                                      cropId:(NSString *)cropId
                                     timeout:(NSUInteger)timeout
                               completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;


/**
 构建使用手机号进行授权任务
 
 @param phone 手机
 @param phoneZone 手机区号
 @param password 密码
 @param cropId 企业ID
 @param timeout 超时时间
 @param completionHandler 完成后的回调
 */
+ (instancetype)userAuthorizeTaskWithPhone:(NSString *)phone
                                 phoneZone:(NSString *_Nullable)phoneZone
                                  password:(NSString *)password
                                    cropId:(NSString *)cropId
                                   timeout:(NSUInteger)timeout
                         completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;

/**
 构建用户使用账号密码登陆任务 并启动
 
 @param account 账号
 @param password 密码
 @param cropId 企业id
 @param timeout 设置超时时间，单位秒，建议15秒
 @param completionHandler 完成后的回调
 @return XLinkUserAuthorizeTask
 */
+ (instancetype)scheduledUserAuthorizeTaskWithAccount:(NSString *)account
                                             password:(NSString *)password
                                               cropId:(NSString *)cropId
                                              timeout:(NSUInteger)timeout
                                    completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;


/**
 构建使用手机号进行授权任务 并启动
 
 @param phone 手机
 @param phoneZone 手机区号
 @param password 密码
 @param cropId 企业ID
 @param timeout 超时时间
 @param completionHandler 完成后的回调
 */
+ (instancetype)scheduledUserAuthorizeTaskWithPhone:(NSString *)phone
                                          phoneZone:(NSString *_Nullable)phoneZone
                                           password:(NSString *)password
                                             cropId:(NSString *)cropId
                                            timeout:(NSUInteger)timeout
                                  completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;



@end

//以下是废弃的方法，不建议使用，不久的将来会删除
@interface XLinkUserAuthorizeTask (XLinkDeprecated)

/**
 构建用户使用账号密码登陆任务
 
 @param account 账号
 @param password 密码
 @param cropId 企业id
 @param timeout 设置超时时间，单位秒，建议15秒
 @param completeBlock 完成后的回调
 @return XLinkUserAuthorizeTask
 */
+ (instancetype)userAuthorizeTaskWithAccount:(NSString *)account
                                withPassword:(NSString *)password
                                  withCropId:(NSString *)cropId
                                 withTimeout:(NSUInteger)timeout
                           withCompleteBlock:(XLinkTaskDidCompletionHandler)completeBlock NS_DEPRECATED(2_0, 2_0, 2_0, 2_0, "已废弃方法，使用+userAuthorizeTaskWithAccount:password:cropId:timeout:completeBlock:替换,以后的版本将可能会删除此方法");

@end

NS_ASSUME_NONNULL_END
