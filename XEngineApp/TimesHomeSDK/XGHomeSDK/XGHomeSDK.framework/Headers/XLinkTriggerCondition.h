//
//  XLinkTriggerCondition.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/3/31.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XLinkConst.h"

NS_ASSUME_NONNULL_BEGIN

@interface XLinkTriggerCondition : NSObject

/**
 * 缓存信息生成触发器条件实体
 */

+ (XLinkTriggerCondition *)conditionWithCacheKeyValues:(nullable NSDictionary *)cacheKeyValues;

- (instancetype)initWithCacheKeyValues:(NSDictionary *)cacheKeyValues;

// 用来缓存的信息
- (NSDictionary *)cacheKeyValues;

- (NSString *)conditionDescription;

/**
 比较两个触发器条件是否为相同
 
 @param condition 需要比较的触发器条件
 @return 比较结果
 */
- (BOOL)isEqualToCondition:(XLinkTriggerCondition *)condition;

@end
NS_ASSUME_NONNULL_END
