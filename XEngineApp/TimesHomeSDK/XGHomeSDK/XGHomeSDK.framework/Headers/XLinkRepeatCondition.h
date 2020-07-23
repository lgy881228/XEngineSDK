//
//  XLinkRepeatCondition.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/3/31.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "XLinkTriggerCondition.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, XLinkRepeatType) {
    XLinkRepeatTypePerHour, //每小时重复
    XLinkRepeatTypePerDay,//每天重复
    XLinkRepeatTypePerWeek,//每周重复
    XLinkRepeatTypePerMonth,//每月重复
    XLinkRepeatTypePerYear//每年重复
};

@interface XLinkRepeatCondition : XLinkTriggerCondition

///重复模式
@property(assign, nonatomic) XLinkRepeatType repeatType;

///重复模式值，不同模式下这个值有不同定义
@property(assign, nonatomic) uint32_t repeatValue;

/**
 构建一个重复条件

 @param repeatValue 重复值
 @param repeatType 重复模式
 @return 重复条件
 */
+ (instancetype)repeatConditionWithRepeatValue:(uint32_t)repeatValue
                                withRepeatType:(XLinkRepeatType)repeatType;

@end

NS_ASSUME_NONNULL_END

