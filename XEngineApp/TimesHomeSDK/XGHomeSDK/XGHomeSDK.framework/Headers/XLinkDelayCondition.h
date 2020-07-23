//
//  XLinkDelayCondition.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/3/31.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "XLinkTriggerCondition.h"

NS_ASSUME_NONNULL_BEGIN

@interface XLinkDelayCondition : XLinkTriggerCondition

///延时的单位时间数量,单位是秒
@property(assign, nonatomic) NSTimeInterval delay;

/**
 构建一个延时执行条件

 @param delayTime 延迟时间
 @return 延时执行条件
 */
+ (instancetype)delayConditionWithDelayTime:(NSTimeInterval)delayTime;

@end

NS_ASSUME_NONNULL_END
