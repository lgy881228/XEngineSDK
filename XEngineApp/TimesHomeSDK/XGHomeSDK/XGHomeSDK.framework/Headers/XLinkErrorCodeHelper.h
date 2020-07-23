//
//  XLinkErrorCodeHelper.h
//  XLinkSDK
//
//  Created by AllenKwok on 2018/3/22.
//  Copyright © 2018年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XLinkErrorDesc.h"
#import "XLinkConst.h"

NS_ASSUME_NONNULL_BEGIN

@interface XLinkErrorCodeHelper : NSObject

/**
 获取当前错误码的描述信息

 @param errorCode 错误码
 @return 描述信息
 */
+ (XLinkErrorDesc *)getErrorCodeDescWithErrorCode:(NSInteger)errorCode;

/**
 获取当前错误码的名称(英文)

 @param errorCode 错误码
 @return 描述信息
 */
+ (NSString *)getErrorCodeNameWithErrorCode:(NSInteger)errorCode;

/**
 获取当前错误码的名称(中文)
 
 @param errorCode 错误码
 @return 描述信息
 */
+ (NSString *)getErrorCodeDescStr:(NSInteger)errorCode;

@end

NS_ASSUME_NONNULL_END
