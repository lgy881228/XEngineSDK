//
//  XLinkDelayRangeCondition.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/3/31.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "XLinkTriggerCondition.h"

NS_ASSUME_NONNULL_BEGIN

@interface XLinkDelayRangeCondition : XLinkTriggerCondition

///起始时间,单位是秒
@property(assign, nonatomic) NSTimeInterval from;

///结束时间,单位是秒
@property(assign, nonatomic) NSTimeInterval to;

/**
 构建一个延时区间条件

 @param from 起始时间
 @param to 结束时间
 @return 延时区间条件
 */
+ (instancetype)delayRangeConditionWithFromTime:(NSTimeInterval)from withToTime:(NSTimeInterval)to;

@end

NS_ASSUME_NONNULL_END
