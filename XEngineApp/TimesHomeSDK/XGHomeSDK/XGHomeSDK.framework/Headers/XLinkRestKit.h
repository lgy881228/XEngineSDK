//
//  XLinkRestKit.h
//  XLinkNetworking
//
//  Created by AllenKwok on 2018/6/7.
//  Copyright © 2018年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XLinkHTTPConfig.h"
#import "XLinkRequest.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^XLinkRestCompletionHandler)(id _Nullable result, NSError * _Nullable err);

//XLink用户来源
typedef NS_ENUM(NSUInteger, XLinkUserSource) {
    XLinkUserSourceWeb = 1,//web
    XLinkUserSourceAndroid = 2,//Android客户端
    XLinkUserSourceIOS = 3,//IOS客户端
    XLinkUserSourceWechat = 4,//微信用户
    XLinkUserSourceQQ = 5,//QQ用户
    XLinkUserSourceWeibo = 6,//微博用户
    XLinkUserSourceFacebook = 7,//facebook用户
    XLinkUserSourceTwitter = 8,//twitter用户
    XLinkUserSourceOther = 10,//其它遵循xlink统一身份认证规范的用户来源
};


@interface XLinkRestKit : NSObject

/**
 初始化全局参数
 
 @param block 在回调中进行参数设备
 */
+ (void)setupConfig:(void(^)(XLinkHTTPConfig *config))block;

/**
 发送请求
 
 @param request 具体的请求
 @param finishedBlock 请求完成的回调
 @return 请求任务的标识
 */
+ (NSString *)sendRequest:(XLinkRequest *)request
               onFinished:(nullable XLinkRestCompletionHandler)finishedBlock;

/**
 保存获取到的授权信息
 
 @param authInfo 授权信息
 */
+ (void)onResponseAccessTokenWithAuthInfoDict:(NSDictionary *)authInfo;

#pragma mark - 用户身份接口

/**
 1.使用邮箱注册新账号
 
 @param email 邮箱地址
 @param pwd 认证密码，长度6-16个字符
 @param name 用户昵称，长度2-32个字符
 @param lang 本地语言代码，默认：zh-cn
 @param handler 完成后的回调
 */
+ (void)registerWithEmail:(NSString *)email
                 password:(NSString *)pwd
                 nickName:(NSString * _Nullable)name
                localLang:(NSString * _Nullable)lang
        completionHandler:(XLinkRestCompletionHandler)handler;


/**
 3.发送注册手机验证码（手机验证码有效期是120秒）
 
 @param phone 手机号
 @param phoneZone 手机区号，不填则默认中国:+86
 @param captcha 图片验证码，当调用本接口到了一定次数以后需要该字段。
 */
+ (void)sendVerifyCodeForRegisterWithPhone:(NSString *)phone
                                 phoneZone:(NSString * _Nullable)phoneZone
                                   captcha:(NSString * _Nullable)captcha
                         completionHandler:(XLinkRestCompletionHandler)handler;


/**
 4.请求或刷新发送注册短信的图片验证码（当请求发送注册手机验证码达到一定的次数后，需要进行图片验证码进行验证）
 
 @param phone 手机号
 @param phoneZone 手机区号，不填则默认中国:+86
 */
+ (void)getCaptchaForRegisterWithPhone:(NSString *)phone
                             phoneZone:(NSString * _Nullable)phoneZone
                     completionHandler:(XLinkRestCompletionHandler)handler;


/**
 5.通过手机验证码注册新账号
 
 @param phone 手机号
 @param phoneZone 手机区号，不填则默认中国:+86
 @param pwd 认证密码，长度6-16个字符
 @param name 用户昵称，长度2-32个字符
 @param verifyCode 手机短信验证码
 @param lang 本地语言代码，默认：zh-cn
 @param handler 完成后的回调
 */
+ (void)registerWithPhone:(NSString *)phone
                phoneZone:(NSString * _Nullable)phoneZone
                 password:(NSString *)pwd
                 nickName:(NSString * _Nullable)name
               verifyCode:(NSString *)verifyCode
                localLang:(NSString * _Nullable)lang
        completionHandler:(XLinkRestCompletionHandler)handler;

/**
 6.1 登录与认证
 
 @param email 邮箱
 @param pwd 密码
 @param resource 登录源，用户可以在登录时指定登录源，不同登录源可同时登录，长度在0~16个字符之间。
 @param handler 完成后的回调
 */
+ (void)authWithEmail:(NSString *)email
             password:(NSString *)pwd
             resource:(NSString * _Nullable)resource
    completionHandler:(XLinkRestCompletionHandler)handler;

/**
 6.2 登录与认证
 
 @param phone 手机
 @param phoneZone 手机区号
 @param pwd 密码
 @param resource 登录源，用户可以在登录时指定登录源，不同登录源可同时登录，长度在0~16个字符之间。
 @param handler 完成后的回调
 */
+ (void)authWithPhone:(NSString *)phone
            phoneZone:(NSString * _Nullable)phoneZone
             password:(NSString *)pwd
             resource:(NSString * _Nullable)resource
    completionHandler:(XLinkRestCompletionHandler)handler;

/**
 6.3 登录与认证
 
 @param account 账号，手机号或邮箱
 @param pwd 密码
 @param resource 登录源，用户可以在登录时指定登录源，不同登录源可同时登录，长度在0~16个字符之间。
 @param handler 完成后的回调
 */
+ (void)authWithAccount:(NSString *)account
               password:(NSString *)pwd
               resource:(NSString * _Nullable)resource
      completionHandler:(XLinkRestCompletionHandler)handler;

/**
 7. 刷新凭证 通过本接口刷新一个新的调用凭证和一个新的刷新凭证，若在调用凭证已经
 过期，则无法刷新凭证，只能重新认证
 
 @param refreshToken  认证成功后返回的refreshToken
 @param handler 完成后的回调
 */
+ (void)refreshTokenWithRefreshToken:(NSString *)refreshToken
                   completionHandler:(XLinkRestCompletionHandler)handler;

/**
 8.获取用户详细信息
 
 @param userId 用户ID
 @param handler 完成后的回调
 */
+ (void)queryUserDetialInfoWithUserId:(NSNumber *)userId
                    completionHandler:(XLinkRestCompletionHandler)handler;

/**
 10. 修改用户的密码
 
 @param oldPwd 旧密码
 @param newPwd 新密码
 @param handler 完成后的回调
 */
+ (void)modifyPasswordWithOld:(NSString *)oldPwd
                          new:(NSString *)newPwd
            completionHandler:(XLinkRestCompletionHandler)handler;

/**
 11.1. 请求密码找回(发送一则带有6位数字的验证码的短信到用户手机，用户通过验证码进行密码重置)
 
 @param phone 手机号
 @param phoneZone 手机区号，不填则默认中国:+86
 @param captcha 图片验证码，当调用本接口到了一定次数以后需要该字段。
 @param handler 完成后的回调
 */
+ (void)sendVerifyCodeForResetPasswordWithPhone:(NSString *)phone
                                      phoneZone:(NSString * _Nullable)phoneZone
                                        captcha:(NSString * _Nullable)captcha
                              completionHandler:(XLinkRestCompletionHandler)handler;

/**
 11.2 请求找回密码需要的图片验证码（当请求手机验证码达到一定的次数后，需要进行图片验证码进行验证）
 
 @param phone 手机号
 @param phoneZone 手机区号，不填则默认中国:+86
 @param handler 完成后的回调
 */
+ (void)getCaptchaForResetPasswordWithPhone:(NSString *)phone
                                  phoneZone:(NSString * _Nullable)phoneZone
                          completionHandler:(XLinkRestCompletionHandler)handler;

/**
 11.3 通过验证码重置密码
 
 @param phone 手机号
 @param phoneZone 手机区号，不填则默认中国:+86
 @param verifyCode 验证码
 @param newPwd 新的密码
 @param handler 完成后的回调
 */
+ (void)resetPasswordWithPhone:(NSString *)phone
                     phoneZone:(NSString * _Nullable)phoneZone
                    verifyCode:(NSString *)verifyCode
                   newPassword:(NSString *)newPwd
             completionHandler:(XLinkRestCompletionHandler)handler;

/**
 11.4 请求密码找回
 
 @param email 用户邮箱地址
 @param handler 完成后的回调
 */
+ (void)sendVerifyCodeForResetPasswordWithEmail:(NSString *)email
                              completionHandler:(XLinkRestCompletionHandler)handler;

/**
 11.5 通过验证码重置密码
 
 @param email 用户邮箱地址
 @param verifyCode 验证码
 @param newPwd 新的密码
 @param handler 完成后的回调
 */
+ (void)resetPasswordWithEmail:(NSString *)email
                    verifyCode:(NSString *)verifyCode
                   newPassword:(NSString *)newPwd
             completionHandler:(XLinkRestCompletionHandler)handler;

/**
 13.1 请求发送验证码修改手机号
 
 @param userId 用户id
 @param oldPhone 手机号
 @param phoneZone 手机区号，不填则默认中国:+86
 @param handler 完成后的回调
 */
+ (void)sendVerifyCodeForModifyPhoneWithUserId:(NSNumber *)userId
                                      oldPhone:(NSString *)oldPhone
                                     phoneZone:(NSString * _Nullable)phoneZone
                             completionHandler:(XLinkRestCompletionHandler)handler;

/**
 13.2 请求更换手机号码需要的图片验证码（当请求手机验证码达到一定的次数后，需要进行图片验证码进行验证）
 
 @param userId 用户id
 @param phone 手机号
 @param phoneZone 手机区号，不填则默认中国:+86
 @param handler 完成后的回调
 */
+ (void)getCaptchaForModifyPhoneWithUserId:(NSNumber *)userId
                                     phone:(NSString *)phone
                                 phoneZone:(NSString * _Nullable)phoneZone
                         completionHandler:(XLinkRestCompletionHandler)handler;

/**
 13.3 通过验证码完成手机号修改
 
 @param newPhone 修改后的手机号
 @param phoneZone 手机区号，不填则默认中国:+86
 @param verifyCode 验证码
 @param pwd 用户登录密码
 @param handler 完成后的回调
 */
+ (void)modifyPhoneWithUserId:(NSNumber *)userId
                     newPhone:(NSString *)newPhone
                    phoneZone:(NSString * _Nullable)phoneZone
                   verifyCode:(NSString *)verifyCode
                     password:(NSString *)pwd
            completionHandler:(XLinkRestCompletionHandler)handler;


#pragma mark - 第三方用户身份接口

/**
 第三方用户登录
 
 @param openId APP在第三方平台登录成功返回的用户标识
 @param accessToken APP在第三方平台登录成功返回的用户凭证
 @param source 用户来源，根据第三方选择不同的来源
 @param nickName 第三方用户昵称
 @param resource 登录源，用户可以在登录时指定登录源，不同登录源可同时登录,长度在0~16个字符之间
 @param handler 完成后的回调
 */
+ (void)authFromThirdPartyWithOpenId:(NSString *)openId
                         accessToken:(NSString *)accessToken
                              source:(XLinkUserSource)source
                            nickName:(NSString * _Nullable)nickName
                            resource:(NSString * _Nullable)resource
                   completionHandler:(XLinkRestCompletionHandler)handler;


/**
 第三方用户初始化登录密码
 
 @param userId 用户id
 @param pwd 登陆密码
 @param handler 完成后的回调
 */
+ (void)thirdPartyUserInitPasswordWithUserId:(NSNumber *)userId
                                    password:(NSString *)pwd
                           completionHandler:(XLinkRestCompletionHandler)handler;


/**
 第三方用户初始化登录邮箱
 
 @param userId 用户id
 @param email 邮箱号
 @param verfifyCode 验证码
 @param pwd 登陆密码
 @param nickName 用户昵称
 @param handler 完成后的回调
 */
+ (void)thirdPartyUserInitEmailWithUserId:(NSNumber *)userId
                                    email:(NSString *)email
                              verfifyCode:(NSString *)verfifyCode
                                 password:(NSString *)pwd
                                 nickName:(NSString * _Nullable)nickName
                        completionHandler:(XLinkRestCompletionHandler)handler;


/**
 第三方用户初始化登录手机号
 
 @param userId 用户id
 @param phone 手机号
 @param phoneZone 手机号区域，默认为中国:+86
 @param verfifyCode 验证码
 @param pwd 登陆密码
 @param nickName 用户昵称
 @param handler 完成后的回调
 */
+ (void)thirdPartyUserInitPhoneWithUserId:(NSNumber *)userId
                                    phone:(NSString *)phone
                                phoneZone:(NSString * _Nullable)phoneZone
                              verfifyCode:(NSString *)verfifyCode
                                 password:(NSString *)pwd
                                 nickName:(NSString * _Nullable)nickName
                        completionHandler:(XLinkRestCompletionHandler)handler;

/**
 绑定第三方帐号
 
 @param userId 用户id
 @param openId APP在第三方平台登录成功返回的用户标识
 @param accessToken APP在第三方平台登录成功返回的用户凭证
 @param source 用户来源，根据第三方选择不同的来源
 @param handler 完成后的回调
 */
+ (void)bindThirdPartyAccountWithWithUserId:(NSNumber *)userId
                                     openId:(NSString *)openId
                                accessToken:(NSString *)accessToken
                                     source:(XLinkUserSource)source
                          completionHandler:(XLinkRestCompletionHandler)handler;

/**
 解绑第三方帐号
 
 @param userId 用户id
 @param source 用户来源，根据第三方选择不同的来源
 @param handler 完成后的回调
 */
+ (void)unbindThirdPartyAccountWithWithUserId:(NSNumber *)userId
                                       source:(XLinkUserSource)source
                            completionHandler:(XLinkRestCompletionHandler)handler;

/**
 国外的第三方用户登录
 
 @param openId APP在第三方平台登录成功返回的用户标识
 @param accessToken APP在第三方平台登录成功返回的用户凭证
 @param source 用户来源，根据第三方选择不同的来源
 @param nickName 第三方用户昵称
 @param resource 登录源，用户可以在登录时指定登录源，不同登录源可同时登录,长度在0~16个字符之间
 @param oauth_version oauth版本.值为1.0或者2.0
 @param oauth_consumer_key 注册应用后由应用服务商提供（如果oauth_version为1.0，必须提供）
 @param oauth_signature_method 随机字符串，须保证每次都不同（如果oauth_version为1.0，必须提供）
 @param oauth_timestamp 时间戳（如果oauth_version为1.0，必须提供）
 @param oauth_nonce 签名base string 的方法，目前支持 HMAC-SHA1（如果oauth_version为1.0，必须提供）
 @param oauth_signature 签名值（如果oauth_version为1.0，必须提供）
 @param handler 完成后的回调
 */
+ (void)authFromThirdForeignPartyWithOpenId:(NSString *)openId
                                accessToken:(NSString *)accessToken
                                     source:(XLinkUserSource)source
                                   nickName:(NSString * _Nullable)nickName
                                   resource:(NSString * _Nullable)resource
                               oauthVersion:(NSString * _Nullable)oauth_version
                           oauthConsumerCey:(NSString * _Nullable)oauth_consumer_key
                       oauthSignatureMethod:(NSString * _Nullable)oauth_signature_method
                             oauthTimestamp:(NSString * _Nullable)oauth_timestamp
                                 oauthNonce:(NSString * _Nullable)oauth_nonce
                             oauthSignature:(NSString * _Nullable)oauth_signature
                          completionHandler:(XLinkRestCompletionHandler)handler;


/**
 国外的第三方用户登录
 
 @param content 请求的内容
 @param handler 完成后的回调
 */
+ (void)authFromThirdForeignPartyWithContent:(NSDictionary *)content
                           completionHandler:(XLinkRestCompletionHandler)handler;

/**
 绑定国外的第三方帐号
 
 @param userId 用户id
 @param openId APP在第三方平台登录成功返回的用户标识
 @param accessToken APP在第三方平台登录成功返回的用户凭证
 @param source 用户来源，根据第三方选择不同的来源
 @param oauth_version oauth版本.值为1.0或者2.0
 @param oauth_consumer_key 注册应用后由应用服务商提供（如果oauth_version为1.0，必须提供）
 @param oauth_signature_method 随机字符串，须保证每次都不同（如果oauth_version为1.0，必须提供）
 @param oauth_timestamp 时间戳（如果oauth_version为1.0，必须提供）
 @param oauth_nonce 签名base string 的方法，目前支持 HMAC-SHA1（如果oauth_version为1.0，必须提供）
 @param oauth_signature 签名值（如果oauth_version为1.0，必须提供）
 @param handler 完成后的回调
 */
+ (void)bindThirdForeignPartyAccountWithWithUserId:(NSNumber *)userId
                                            openId:(NSString *)openId
                                       accessToken:(NSString *)accessToken
                                            source:(XLinkUserSource)source
                                      oauthVersion:(NSString * _Nullable)oauth_version
                                  oauthConsumerCey:(NSString * _Nullable)oauth_consumer_key
                              oauthSignatureMethod:(NSString * _Nullable)oauth_signature_method
                                    oauthTimestamp:(NSString * _Nullable)oauth_timestamp
                                        oauthNonce:(NSString * _Nullable)oauth_nonce
                                    oauthSignature:(NSString * _Nullable)oauth_signature
                                 completionHandler:(XLinkRestCompletionHandler)handler;


/**
 18 短信验证登录--发送手机验证码
 
 @param phone 手机号
 @param phoneZone 手机区号，不填则默认中国:+86
 @param captcha 图片验证码
 @param handler 完成后的回调
 */
+ (void)sendVerifyCodeForUserAuthWithPhone:(NSString *)phone
                                 phoneZone:(NSString * _Nullable)phoneZone
                                   captcha:(NSString * _Nullable)captcha
                         completionHandler:(XLinkRestCompletionHandler)handler;

/**
 19 短信验证登录--请求或刷新发送短信的图片验证码
 
 @param phone 手机号
 @param phoneZone 手机区号，不填则默认中国:+86
 @param handler 完成后的回调
 */
+ (void)getCaptchaForUserAuthWithPhone:(NSString *)phone
                             phoneZone:(NSString * _Nullable)phoneZone
                     completionHandler:(XLinkRestCompletionHandler)handler;

/**
 20 短信验证登录，可以是已注册的帐号或未注册的帐号的账号(如果未注册，则注册该账户)
 
 @param verifyCode 短信验证码
 @param phone 手机号
 @param phoneZone 手机区号，不填则默认中国:+86
 @param resource 登陆源
 @param handler 完成后的回调
 */
+ (void)authWithSmsVerifyCode:(NSString *)verifyCode
                        phone:(NSString *)phone
                    phoneZone:(NSString *)phoneZone
                     resource:(NSString * _Nullable)resource
            completionHandler:(XLinkRestCompletionHandler)handler;

#pragma mark - 设备功能接口

/**
 用户获取设备列表
 
 @param userId 用户id
 @param version 设备列表的版本号，起始版本默认为0
 @param filterArray 需要额外返回的字段数组 例：soft_init_date,name
 @param handler 完成后的回调
 */
+ (void)getDeviceListWithUserId:(NSNumber *)userId
                        version:(NSNumber * _Nullable)version
                    filterArray:(NSArray * _Nullable)filterArray
              completionHandler:(XLinkRestCompletionHandler)handler;

/**
 取消订阅设备
 
 @param userId 用户id
 @param deviceId 设备id
 @param handler 完成后的回调
 */
+ (void)unsubscribeDeviceWithUserId:(NSNumber *)userId
                           deviceId:(NSNumber *)deviceId
                  completionHandler:(XLinkRestCompletionHandler)handler;


/**
 通过账号进行设备分享
 
 @param account 对方账户
 @param deviceId 所要分享的设备ID
 @param expire 分享请求有效时间，单位秒
 @param mode 分享方式，枚举值,string类型【"app"-通过用户ID分享,"qrcode"-,"二维码方式分享","email"-邮件方式分享】
 @param authority 对设备的控制权限，R可读，W可写，RW可读可写；默认为null相当于RW；
 @param extend 扩展信息，250字符以内
 @param handler 完成后的回调
 */
+ (void)shareDeviceToAccount:(NSString * _Nullable)account
                withDeviceId:(NSNumber *)deviceId
                      expire:(NSNumber *)expire
                        mode:(NSString *)mode
                   authority:(NSString * _Nullable)authority
                      extend:(NSString * _Nullable)extend
           completionHandler:(XLinkRestCompletionHandler)handler;

/**
 通过对方的用户id进行设备分享
 
 @param userId 对方账户userId
 @param deviceId 所要分享的设备ID
 @param expire 分享请求有效时间，单位秒
 @param authority 对设备的控制权限，R可读，W可写，RW可读可写；默认为null相当于RW；
 @param extend 扩展信息，250字符以内
 @param handler 完成后的回调
 */
+ (void)shareDeviceToUserId:(NSNumber * _Nullable)userId
               withDeviceId:(NSNumber *)deviceId
                     expire:(NSNumber *)expire
                  authority:(NSString * _Nullable)authority
                     extend:(NSString * _Nullable)extend
          completionHandler:(XLinkRestCompletionHandler)handler;

/**
 通过二维码进行设备分享，这个接口用于获取分享码，以生成二维码数据。
 
 @param deviceId 所要分享的设备ID
 @param expire 分享请求有效时间，单位秒
 @param authority 对设备的控制权限，R可读，W可写，RW可读可写；默认为null相当于RW；
 @param extend 扩展信息，250字符以内
 @param handler 完成后的回调
 */
+ (void)shareDeviceByQrCodeWithDeviceId:(NSNumber *)deviceId
                                 expire:(NSNumber *)expire
                              authority:(NSString * _Nullable)authority
                                 extend:(NSString * _Nullable)extend
                      completionHandler:(XLinkRestCompletionHandler)handler;

+ (void)shareDeviceToAccount:(NSString * _Nullable)account
                    toUserId:(NSNumber * _Nullable)userId
                withDeviceId:(NSNumber *)deviceId
                      expire:(NSNumber *)expire
                        mode:(NSString *)mode
                   authority:(NSString * _Nullable)authority
                      extend:(NSString * _Nullable)extend
           completionHandler:(XLinkRestCompletionHandler)handler;

/**
 取消分享
 
 @param inviteCode 分享ID
 @param handler 完成后的回调
 */
+ (void)cancelShareDeviceWithInviteCode:(NSString *)inviteCode
                      completionHandler:(XLinkRestCompletionHandler)handler;

/**
 接受分享
 
 @param inviteCode 分享ID
 @param handler 完成后的回调
 */
+ (void)acceptShareDeviceWithInviteCode:(NSString *)inviteCode
                      completionHandler:(XLinkRestCompletionHandler)handler;

/**
 拒绝分享
 
 @param inviteCode 分享ID
 @param reason 用户拒绝分享的原因
 @param handler 完成后的回调
 */
+ (void)denyShareDeviceWithInviteCode:(NSString *)inviteCode
                               reason:(NSString * _Nullable)reason
                    completionHandler:(XLinkRestCompletionHandler)handler;

/**
 获取设备分享列表
 
 @param handler 完成后的回调
 */
+ (void)getShareDeviceListWithCompletionHandler:(XLinkRestCompletionHandler)handler;

/**
 删除设备分享记录
 
 @param inviteCode 分享ID
 @param handler 完成后的回调
 */
+ (void)deleteShareRecordWithInviteCode:(NSString *)inviteCode
                      completionHandler:(XLinkRestCompletionHandler)handler;


/**
 通过二维码订阅设备
 
 @param userId 用户ID
 @param qrcode 二维码数据
 @param handler 完成后的回调
 */
+ (void)subscribeDeviceByQrCodeWithUserId:(NSNumber *)userId
                                   qrcode:(NSString *)qrcode
                        completionHandler:(XLinkRestCompletionHandler)handler;


/**
 修改设备名称
 
 @param pid 产品id
 @param deviceId 设备id
 @param name 设备名称
 @param handler 完成后的回调
 */
+ (void)modifyDeviceNameWithProductId:(NSString *)pid
                             deviceId:(NSNumber *)deviceId
                           deviceName:(NSString *)name
                    completionHandler:(XLinkRestCompletionHandler)handler;

/**
 修改设备的sn
 
 @param pid 产品id
 @param deviceId 设备id
 @param sn      设备序列号
 @param handler 完成后的回调
 */
+ (void)modifyDeviceSnWithProductId:(NSString *)pid
                           deviceId:(NSNumber *)deviceId
                           deviceSn:(NSString *)sn
                  completionHandler:(XLinkRestCompletionHandler)handler;

/**
 获取设备详细信息
 
 @param pid 产品id
 @param deviceId 设备id
 @param handler 完成后的回调
 */
+ (void)getDeviceDetailInfoWithProductId:(NSString *)pid
                                deviceId:(NSNumber *)deviceId
                       completionHandler:(XLinkRestCompletionHandler)handler;

/**
 设置设备的扩展属性
 
 @param pid 产品id
 @param deviceId 设备id
 @param propertyDict 扩展属性以Key-Value方式设置储存，扩展属性限制为10个
 @param handler 完成后的回调
 */
+ (void)setDeviceExtendPropertyWithProductId:(NSString *)pid
                                    deviceId:(NSNumber *)deviceId
                          propertyDictionary:(NSDictionary *)propertyDict
                           completionHandler:(XLinkRestCompletionHandler)handler;

/**
 获取设备的扩展属性列表
 
 @param pid 产品id
 @param deviceId 设备id
 @param handler 完成后的回调
 */
+ (void)getDeviceExtendPropertyWithProductId:(NSString *)pid
                                    deviceId:(NSNumber *)deviceId
                           completionHandler:(XLinkRestCompletionHandler)handler;

/**
 修改设备的扩展属性
 
 @param pid 产品id
 @param deviceId 设备id
 @param propertyDict 扩展属性以Key-Value方式设置储存，扩展属性限制为10个
 @param handler 完成后的回调
 */
+ (void)modifyDeviceExtendPropertyWithProductId:(NSString *)pid
                                       deviceId:(NSNumber *)deviceId
                             propertyDictionary:(NSDictionary *)propertyDict
                              completionHandler:(XLinkRestCompletionHandler)handler;

/**
 获取数据端点列表元数据
 
 @param pid 产品id
 @param handler 完成后的回调
 */
+ (void)getDataPointMetaDataWithProductId:(NSString *)pid
                        completionHandler:(XLinkRestCompletionHandler)handler;


/**
 查询设备的在线状态
 
 @param uid 用户id
 @param didArray 设备id数组
 @param handler 完成后的回调
 */
+ (void)queryDeviceCloudStateWithUserId:(NSNumber *)uid
                          deviceIdArray:(NSArray <NSNumber *>*)didArray
                      completionHandler:(XLinkRestCompletionHandler)handler;

#pragma mark - 设备的配对信息

/**
 添加配对信息
 
 @param userId 用户id
 @param deviceId 设备id
 @param pairingId pairingid
 @param pairingKey pairing key
 @param handler 完成后的回调
 */
+ (void)addSubscribeInfoWithUserId:(NSNumber *)userId
                          deviceId:(NSNumber *)deviceId
                         pairingId:(NSNumber *)pairingId
                        pairingKey:(NSString *)pairingKey
                 completionHandler:(XLinkRestCompletionHandler)handler ;

/**
 查询设备的配对信息
 
 @param userId 用户ID
 @param deviceIdArray 设备id列表
 @param handler 完成后的回调
 */
+ (void)querySubscribeInfoWithUserId:(NSNumber *)userId
                       deviceIdArray:(NSArray <NSNumber *>*)deviceIdArray
                   completionHandler:(XLinkRestCompletionHandler)handler ;

/**
 删除设备的配对信息
 
 @param userId 用户ID
 @param deviceId 设备ID
 @param handler 完成后的回调
 */
+ (void)deleteSubscribeInfoWithUserId:(NSNumber *)userId
                             deviceId:(NSNumber *)deviceId
                    completionHandler:(XLinkRestCompletionHandler)handler;

#pragma mark - 用户扩展属性
/**
 设置用户的扩展属性
 
 @param userId 用户id
 @param propertyDict 扩展属性以Key-Value方式设置储存，扩展属性限制为10个
 @param handler 完成后的回调
 */
+ (void)setUserExtendPropertyWithUserId:(NSNumber *)userId
                     propertyDictionary:(NSDictionary *)propertyDict
                      completionHandler:(XLinkRestCompletionHandler)handler;

/**
 获取用户全部扩展属性
 
 @param userId 用户id
 @param handler 完成后的回调
 */
+ (void)getUserAllExtendPropertyWithUserId:(NSNumber *)userId
                         completionHandler:(XLinkRestCompletionHandler)handler;

/**
 修改用户的扩展属性
 
 @param userId 用户id
 @param propertyDict 扩展属性以Key-Value方式设置储存，扩展属性限制为10个
 @param handler 完成后的回调
 */
+ (void)modifyUserExtendPropertyWithUserId:(NSNumber *)userId
                        propertyDictionary:(NSDictionary *)propertyDict
                         completionHandler:(XLinkRestCompletionHandler)handler;

/**
 获取用户单个扩展属性
 
 @param userId 用户id
 @param key 用户id
 @param handler 完成后的回调
 */
+ (void)getUserSingleExtendPropertyWithUserId:(NSNumber *)userId
                                  propertyKey:(NSString *)key
                            completionHandler:(XLinkRestCompletionHandler)handler;

/**
 删除用户扩展属性
 
 @param userId 用户id
 @param key 用户id
 @param handler 完成后的回调
 */
+ (void)deleteUserExtendPropertyWithUserId:(NSNumber *)userId
                               propertyKey:(NSString *)key
                         completionHandler:(XLinkRestCompletionHandler)handler;

/**
 注册阿里推送
 
 @param userId 用户id
 @param appId 推送应用id，需要在云智易管理台创建
 @param aliDeviceId 阿里推送返回的设备标签-[CloudPushSDK getDeviceId]
 @param isNoticed 阿里推送设置--是否为通知
 @param isDev iOS通知环境，YES表示在调试环境，NO表示在发布环境
 @param handler 完成后的回调
 */
+ (void)alipushRegisterWithUserId:(NSNumber *)userId
                            appId:(NSString *)appId
                      aliDeviceId:(NSString *)aliDeviceId
                        isNoticed:(BOOL)isNoticed
                 isDevEnvironment:(BOOL)isDev
                completionHandler:(XLinkRestCompletionHandler)handler;

/**
 注销阿里推送
 
 @param userId 用户id
 @param appId 推送应用id，需要在云智易管理台创建
 @param handler 完成后的回调
 */
+ (void)alipushUnRegisterWithUserId:(NSNumber *)userId
                              appId:(NSString *)appId
                  completionHandler:(XLinkRestCompletionHandler)handler;

@end

NS_ASSUME_NONNULL_END
