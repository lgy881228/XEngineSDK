//
//  XLinkRequest.h
//  XLinkNetworking
//
//  Created by AllenKwok on 2018/5/7.
//  Copyright © 2018年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSUInteger, XLinkHTTPMethodType) {
    XLinkHTTPMethodTypeGet,
    XLinkHTTPMethodTypePost,
    XLinkHTTPMethodTypeHead,
    XLinkHTTPMethodTypeDelete,
    XLinkHTTPMethodTypePut,
    XLinkHTTPMethodTypePatch
};

typedef NS_ENUM(NSUInteger, XLinkHTTPBodyType) {
    XLinkHTTPBodyTypeJSON,
    XLinkHTTPBodyTypeData
};

typedef void (^XLinkSuccessBlock)(id _Nullable responseObject);
typedef void (^XLinkFailureBlock)(NSError * _Nullable error);
typedef void (^XLinkFinishedBlock)(id _Nullable responseObject, NSError * _Nullable error);

@interface XLinkRequest : NSObject

///请求的服务器地址，如果使用`useGeneralServer`的话，这个属性设置的值会被忽略
@property (nonatomic, copy, nullable) NSString *apiServer;

///请求的具体路径
@property (nonatomic, copy, nullable) NSString *api;

///请求的参数，如果使用`useGeneralParameters`的话，这个属性设置的值会被忽略
@property (nonatomic, strong, nullable) id parameters;

///请求的参数，如果使用`useGeneralHeaders`的话，这个属性设置的值会被忽略
@property (nonatomic, strong, nullable) NSDictionary<NSString *, NSString *> *headers;

///请求体类型
@property (assign, nonatomic) XLinkHTTPBodyType httpBodyType;

///请求方法
@property (nonatomic, assign) XLinkHTTPMethodType httpMethod;

///请求超时时间
@property (nonatomic, assign) NSTimeInterval timeoutInterval;

///请求的开始时间
@property (assign, nonatomic) NSTimeInterval startTime;

///失败后的重试次数
@property (nonatomic, assign) NSUInteger retryCount;

///请求的唯一标识码
@property (copy, nonatomic) NSString *identifier;

///使用全局的服务器地址
@property (nonatomic, assign) BOOL useGeneralServer;

///使用全局的请求头
@property (nonatomic, assign) BOOL useGeneralHeaders;

///使用全局的参数
@property (nonatomic, assign) BOOL useGeneralParameters;

///使用SDK内部的access-token
@property (assign, nonatomic) BOOL userGeneralAccessToken;

///请求成功的回调
@property (nonatomic, copy, readonly, nullable) XLinkSuccessBlock successBlock;

///请求失败的回调
@property (nonatomic, copy, readonly, nullable) XLinkFailureBlock failureBlock;

///请求完成的回调
@property (nonatomic, copy, readonly, nullable) XLinkFinishedBlock finishedBlock;

/**
 创建默认的request
 将会使用全局的服务器地址、全局的请求头、全局的参数
 */
+ (instancetype)defaultRequest;

/**
 创建默认的使用全局AccessTokenrequest
 将会使用全局的服务器地址、全局的请求头、全局的参数
 */
+ (instancetype)defaultAccessTokenRequest;

/**
 清除所有的回调
 */
- (void)cleanCallbackBlocks;

@end

NS_ASSUME_NONNULL_END
