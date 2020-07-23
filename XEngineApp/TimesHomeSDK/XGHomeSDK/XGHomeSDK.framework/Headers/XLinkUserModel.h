//
//  XLinkUserModel.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/3/15.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XLinkConst.h"

NS_ASSUME_NONNULL_BEGIN

@interface XLinkUserModel : NSObject

#pragma mark - 用户基础信息
///用户ID
@property(copy, nonatomic) NSNumber *user_id;

///调用凭证
@property(copy, nonatomic) NSString *access_token;

///刷新凭证
@property(copy, nonatomic) NSString *refresh_token;

///有效期（秒）
@property(copy, nonatomic) NSNumber *expire_in;

///用户认证码
@property(copy, nonatomic) NSString *authorize;


/**
 根据服务器返回用户数据初始化一个用户对象
 
 @param dict 用户数据
 @return 用户对象
 */
- (instancetype)initWithDict:(NSDictionary *)dict;


/**
 根据服务器返回用户数据赋值到用户对于的属性
 
 @param dict 用户数据
 */
- (void)setInfoWithDict:(NSDictionary *)dict;

/**
 返回用户授权信息的字典
 
 @return 用户授权信息的字典
 */
- (NSDictionary *)getAuthorizeDict;

@end

NS_ASSUME_NONNULL_END
