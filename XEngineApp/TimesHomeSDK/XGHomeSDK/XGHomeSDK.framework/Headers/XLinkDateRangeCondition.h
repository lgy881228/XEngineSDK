//
//  XLinkDateRangeCondition.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/8/17.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "XLinkTriggerCondition.h"

NS_ASSUME_NONNULL_BEGIN

@interface XLinkDateRangeCondition : XLinkTriggerCondition

///起始时间,单位是秒
@property(assign, nonatomic) NSTimeInterval from;

///结束时间,单位是秒
@property(assign, nonatomic) NSTimeInterval to;

/**
 构建一个日期区间条件

 @param from 起始时间
 @param to 结束时间
 @return 日期区间条件
 */
+ (instancetype)dateRangeConditionWithFromTime:(NSTimeInterval)from
                                    withToTime:(NSTimeInterval)to;

@end

NS_ASSUME_NONNULL_END
