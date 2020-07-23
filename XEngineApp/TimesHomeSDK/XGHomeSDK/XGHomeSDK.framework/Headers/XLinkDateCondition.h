//
//  XLinkDateCondition.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/4/2.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "XLinkTriggerCondition.h"

NS_ASSUME_NONNULL_BEGIN

@interface XLinkDateCondition : XLinkTriggerCondition

///指定时间的时间戳,单位是秒
@property(assign, nonatomic) NSTimeInterval when;


/**
 构建一个时间条件

 @param when 指定的时间戳
 @return 指定的时间条件
 */
+ (instancetype)dateConditionWithWhen:(NSTimeInterval)when;

@end
NS_ASSUME_NONNULL_END
