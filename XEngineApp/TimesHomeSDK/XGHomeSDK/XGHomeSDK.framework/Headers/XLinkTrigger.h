//
//  XLinkTrigger.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/3/31.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XLinkTriggerCondition.h"
#import "XLinkTriggerAction.h"
#import "XLinkConst.h"

NS_ASSUME_NONNULL_BEGIN

@interface XLinkTrigger : NSObject

///触发器id。当触发器提交到网关后，由网关返回触发器id。
@property(assign, nonatomic) uint32_t triggerId;

///触发器名称,默认为nil。
@property(copy, nonatomic) NSString *name;

///扩展数据
@property(copy, nonatomic) NSData *extendData;

///是否启用该触发器
@property(assign, nonatomic) BOOL enable;

///触发条件列表
@property(strong, nonatomic) NSMutableArray <XLinkTriggerCondition *> *conditions;

///触发动作列表
@property(strong, nonatomic) NSMutableArray <XLinkTriggerAction *> *actions;

/**
 * 缓存信息生成触发器实体
 */
- (instancetype)initWithCacheKeyValues:(nullable NSDictionary *)cacheKeyValues;

// 用来缓存的信息
- (NSDictionary *)cacheKeyValues;

/**
 添加一个触发条件

 @param condition 触发条件
 */
- (void)addCondition:(XLinkTriggerCondition *)condition;


/**
 删除一个触发条件
 
 @param condition 触发条件
 */
- (void)removeCondition:(XLinkTriggerCondition *)condition;


/**
 添加一个触发动作

 @param action 触发动作
 */
- (void)addAction:(XLinkTriggerAction *)action;

/**
 删除一个触发动作
 
 @param action 触发动作
 */
- (void)removeAction:(XLinkTriggerAction *)action;

/**
 比较两个触发器是否为同一触发器

 @param trigger 需要比较的触发器
 @return 比较结果
 */
- (BOOL)isEqualToTrigger:(XLinkTrigger *)trigger;

@end

NS_ASSUME_NONNULL_END
