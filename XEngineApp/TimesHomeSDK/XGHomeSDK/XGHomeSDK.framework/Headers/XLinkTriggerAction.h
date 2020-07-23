//
//  XLinkTriggerAction.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/3/31.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XLinkConst.h"

NS_ASSUME_NONNULL_BEGIN

@interface XLinkTriggerAction : NSObject

/**
 * 缓存信息生成触发器动作实体
 */
+ (XLinkTriggerAction *)actionWithCacheKeyValues:(nullable NSDictionary *)cacheKeyValues;

- (instancetype)initWithCacheKeyValues:(nullable NSDictionary *)cacheKeyValues;

// 用来缓存的信息
- (NSDictionary *)cacheKeyValues;

- (NSString *)actionDescription;

/**
 比较两个触发器动作是否为同一触发器动作
 
 @param action 需要比较的触发器动作
 @return 比较结果
 */
- (BOOL)isEqualToAction:(XLinkTriggerAction *)action;

@end
NS_ASSUME_NONNULL_END
