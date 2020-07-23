//
//  XLinkTriggerLinkageAction.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/3/31.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//
//  触发另外一些触发器的执行

#import "XLinkTriggerAction.h"
#import "XLinkTrigger.h"

NS_ASSUME_NONNULL_BEGIN

@interface XLinkTriggerLinkageAction : XLinkTriggerAction

///触发器id数组
@property(strong, nonatomic) NSMutableArray <NSNumber *> *triggerIdArray;


/**
 初始化对象，并添加一个triggerId

 @param triggerId triggerId
 @return XLinkTriggerLinkageAction
 */
+ (instancetype)triggerLinkageActionWithTriggerId:(uint32_t)triggerId;


/**
 添加一个trigger

 @param triggerId triggerId
 */
- (void)addTriggerId:(uint32_t)triggerId;

@end
NS_ASSUME_NONNULL_END
