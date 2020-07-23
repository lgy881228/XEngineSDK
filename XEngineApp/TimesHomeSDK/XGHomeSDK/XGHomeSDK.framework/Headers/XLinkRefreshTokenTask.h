//
//  XLinkRefreshTokenTask.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/10/9.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "XLinkAuthorizeBaseTask.h"

NS_ASSUME_NONNULL_BEGIN

@interface XLinkRefreshTokenTask : XLinkAuthorizeBaseTask

///上次登录成功返回的授权信息
@property(copy, nonatomic) NSDictionary *authorizeDic;

/**
 构建根据授权信息登录任务
 
 @param authorizeDic 授权信息
 @param timeout 超时时间
 @param completionHandler 完成后的回调
 @return XLinkRefreshTokenAuthorizeTask
 */
+ (instancetype)refreshTokenTaskWithUserAuthorizeDictionary:(NSDictionary *)authorizeDic
                                                    timeout:(NSUInteger)timeout
                                          completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;

/**
 构建根据授权信息登录任务 并启动
 
 @param authorizeDic 授权信息
 @param timeout 超时时间
 @param completionHandler 完成后的回调
 @return XLinkRefreshTokenAuthorizeTask
 */
+ (instancetype)scheduledRefreshTokenTaskWithUserAuthorizeDictionary:(NSDictionary *)authorizeDic
                                                             timeout:(NSUInteger)timeout
                                                   completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;

@end

NS_ASSUME_NONNULL_END
