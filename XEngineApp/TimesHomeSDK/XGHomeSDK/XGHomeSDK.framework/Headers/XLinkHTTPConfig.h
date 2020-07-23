//
//  XLinkHTTPConfig.h
//  XLinkSDK
//
//  Created by AllenKwok on 2018/6/11.
//  Copyright © 2018年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface XLinkHTTPConfig : NSObject

///全局服务器地址
@property (nonatomic, copy, nullable) NSString *apiServer;

///全局参数
@property (nonatomic, strong, nullable) NSDictionary<NSString *, id> *parameters;

///全局请求头
@property (nonatomic, strong, nullable) NSDictionary<NSString *, NSString *> *headers;

///全局请求头
@property (nonatomic, copy, nonnull) NSString *corpId;

///全局请求头
@property (nonatomic, assign) NSTimeInterval defaultTimeout;

///回调线程，默认为主线程
@property (nonatomic, strong, nullable) dispatch_queue_t callbackQueue;

@end

NS_ASSUME_NONNULL_END
