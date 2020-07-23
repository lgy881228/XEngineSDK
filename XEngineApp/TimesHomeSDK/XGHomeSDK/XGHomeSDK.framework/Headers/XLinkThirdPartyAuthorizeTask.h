//
//  XLinkThirdPartyAuthorizeTask.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/6/5.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "XLinkAuthorizeBaseTask.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, XLinkUserSourceType) {
    XLinkUserSourceTypeWeb = 1, //web
    XLinkUserSourceTypeAndroid = 2, //Android客户端
    XLinkUserSourceTypeIOS = 3, //IOS客户端
    XLinkUserSourceTypeWechat = 4, //微信用户
    XLinkUserSourceTypeQQ = 5, //QQ用户
    XLinkUserSourceTypeWeibo = 6, //微博用户
    XLinkUserSourceTypeFacebook = 7, //facebook用户
    XLinkUserSourceTypeTwitter = 8, //twitter用户
    XLinkUserSourceTypeOthers = 10,//其它遵循xlink统一身份认证规范的用户来源
};

@interface XLinkThirdPartyAuthorizeTask : XLinkAuthorizeBaseTask

///企业ID，默认值为nil。
@property(copy, nonatomic) NSString *corpId;

///用户来源，默认值为0。如果使用第三方账号登陆，参照XLinkUserSourceType填入对应的类型。
@property(assign, nonatomic) XLinkUserSourceType sourceType;

///第三方账号openid。
@property(copy, nonatomic) NSString *openId;

///第三方账号授权凭证。
@property(copy, nonatomic) NSString *accessToken;

///第三方账号昵称。
@property(copy, nonatomic) NSString *nickNmae;

///国外的第三方账号的登录内容
@property(strong, nonatomic) NSDictionary *content;


/**
 构建第三方用户登陆任务
 
 @param userSourceType 用户来源
 @param openid 第三方账号openid
 @param accessToken 第三方账号授权凭证
 @param nickName 第三方账号昵称
 @param cropId 企业ID
 @param completionHandler 完成回调
 @return XLinkThirdPartyAuthorizeTask
 */
+ (instancetype)thirdPartyUserAuthorizeTaskWithSource:(XLinkUserSourceType)userSourceType
                                               openId:(NSString *)openid
                                          accessToken:(NSString *)accessToken
                                             nickName:(NSString *)nickName
                                               cropId:(NSString *)cropId
                                              timeout:(NSUInteger)timeout
                                    completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;

/**
 构建外国的第三方用户（如Twitter，Facebook）登陆任务
 
 @param content 第三方账号信息
 @param cropId 企业ID
 @param completionHandler 完成回调
 @return XLinkThirdPartyAuthorizeTask
 */
+ (instancetype)thirdForeignUserAuthorizeTaskWithContent:(NSDictionary *)content
                                                  cropId:(NSString *)cropId
                                                 timeout:(NSUInteger)timeout
                                       completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;

/**
 构建第三方用户登陆任务 并启动
 
 @param userSourceType 用户来源
 @param openid 第三方账号openid
 @param accessToken 第三方账号授权凭证
 @param nickName 第三方账号昵称
 @param cropId 企业ID
 @param completionHandler 完成回调
 @return XLinkThirdPartyAuthorizeTask
 */
+ (instancetype)scheduledThirdPartyUserAuthorizeTaskWithSource:(XLinkUserSourceType)userSourceType
                                                        openId:(NSString *)openid
                                                   accessToken:(NSString *)accessToken
                                                      nickName:(NSString *)nickName
                                                        cropId:(NSString *)cropId
                                                       timeout:(NSUInteger)timeout
                                             completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;

/**
 构建外国的第三方用户（如Twitter，Facebook）登陆任务 并启动
 
 @param content 第三方账号信息
 @param cropId 企业ID
 @param completionHandler 完成回调
 @return XLinkThirdPartyAuthorizeTask
 */
+ (instancetype)scheduledThirdForeignUserAuthorizeTaskWithContent:(NSDictionary *)content
                                                           cropId:(NSString *)cropId
                                                          timeout:(NSUInteger)timeout
                                                completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;

@end

//以下是废弃的方法，不建议使用，不久的将来会删除
@interface XLinkThirdPartyAuthorizeTask (XLinkDeprecated)

/**
 构建第三方用户登陆任务
 
 @param userSourceType 用户来源
 @param openid 第三方账号openid
 @param accessToken 第三方账号授权凭证
 @param nickName 第三方账号昵称
 @param cropId 企业ID
 @param completeBlock 完成回调
 @return XLinkThirdPartyAuthorizeTask
 */
+ (instancetype)thirdPartyUserAuthorizeTaskWithSource:(XLinkUserSourceType)userSourceType
                                           withOpenId:(NSString *)openid
                                      withAccessToken:(NSString *)accessToken
                                         withNickName:(NSString *)nickName
                                           withCropId:(NSString *)cropId
                                          withTimeout:(NSUInteger)timeout
                                    withCompleteBlock:(XLinkTaskDidCompletionHandler)completeBlock NS_DEPRECATED(2_0, 2_0, 2_0, 2_0, "已废弃方法，请使用+thirdPartyUserAuthorizeTaskWithSource:(XLinkUserSourceType)userSourceType openId:accessToken:nickName:cropId:imeout:completeBlock:替换,以后的版本将可能会删除此方法");

/**
 构建外国的第三方用户（如Twitter，Facebook）登陆任务
 
 @param content 第三方账号信息
 @param cropId 企业ID
 @param completeBlock 完成回调
 @return XLinkThirdPartyAuthorizeTask
 */
+ (instancetype)thirdForeignUserAuthorizeTaskWithContent:(NSDictionary *)content
                                              withCropId:(NSString *)cropId
                                             withTimeout:(NSUInteger)timeout
                                       withCompleteBlock:(XLinkTaskDidCompletionHandler)completeBlock NS_DEPRECATED(2_0, 2_0, 2_0, 2_0, "已废弃方法，请使用+thirdForeignUserAuthorizeTaskWithContent:cropId:timeout:completeBlock:替换,以后的版本将可能会删除此方法");

@end
NS_ASSUME_NONNULL_END
