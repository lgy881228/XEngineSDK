//
//  XLinkSmsAuthorizeTask.h
//  XLinkSDK
//
//  Created by AllenKwok on 2018/9/17.
//  Copyright © 2018年 www.xlink.cn. All rights reserved.
//

#import "XLinkAuthorizeBaseTask.h"
NS_ASSUME_NONNULL_BEGIN
@interface XLinkSmsAuthorizeTask : XLinkAuthorizeBaseTask

///企业ID，默认值为nil。
@property(copy, nonatomic) NSString *corpId;
///手机号
@property (copy, nonatomic) NSString *phone;
///手机区号
@property (copy, nonatomic, nullable) NSString *phoneZone;
///短信验证码
@property (copy, nonatomic) NSString *verifyCode;

/**
 构建使用短信验证码进行授权任务
 
 @param phone 手机
 @param phoneZone 手机区号
 @param verifyCode 短信验证码
 @param cropId 企业ID
 @param timeout 超时时间
 @param completionHandler 完成后的回调
 */
+ (instancetype)smsAuthorizeTaskWithPhone:(NSString *)phone
                                phoneZone:(NSString *_Nullable)phoneZone
                               verifyCode:(NSString *)verifyCode
                                   cropId:(NSString *)cropId
                                  timeout:(NSUInteger)timeout
                        completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;

/**
 构建使用短信验证码进行授权任务
 
 @param phone 手机
 @param phoneZone 手机区号
 @param verifyCode 短信验证码
 @param cropId 企业ID
 @param timeout 超时时间
 @param completionHandler 完成后的回调
 */
+ (instancetype)scheduledSmsAuthorizeTaskWithPhone:(NSString *)phone
                                         phoneZone:(NSString *_Nullable)phoneZone
                                        verifyCode:(NSString *)verifyCode
                                            cropId:(NSString *)cropId
                                           timeout:(NSUInteger)timeout
                                 completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;

@end
NS_ASSUME_NONNULL_END
