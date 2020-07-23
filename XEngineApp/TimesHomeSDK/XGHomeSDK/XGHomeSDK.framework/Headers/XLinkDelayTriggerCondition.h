//
//  XLinkDelayTriggerCondition.h
//  XLinkGatewaySDK
//
//  Created by AllenKwok on 2018/6/11.
//  Copyright © 2018年 www.xlink.cn. All rights reserved.
//

#import "XLinkTriggerCondition.h"

@interface XLinkDelayTriggerCondition : XLinkTriggerCondition

///触发器延迟执行的时间,单位秒
@property (assign, nonatomic) uint32_t delay;

///表示最后一次触发的时间，APP新增加时此字段为0
@property (assign, nonatomic) uint32_t lastTriggerTime;

@end
