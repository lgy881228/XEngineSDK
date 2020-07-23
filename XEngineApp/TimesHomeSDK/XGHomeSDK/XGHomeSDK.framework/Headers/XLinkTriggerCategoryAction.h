//
//  XLinkTriggerCategoryAction.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/3/31.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//
// 触发分组下的设备执行

#import "XLinkTriggerAction.h"
#import "XLinkCategory.h"
#import "XLinkDataPoint.h"

NS_ASSUME_NONNULL_BEGIN
@interface XLinkTriggerCategoryAction : XLinkTriggerAction

///目标分组id
@property(assign, nonatomic) uint32_t categoryId;

///"pid-dataPoints"对应表
@property(strong, nonatomic) NSMutableDictionary <NSString *, NSArray <XLinkDataPoint *> *> *targetDataPointDict;

/**
 初始化一个分组触发器动作，添加一个产品及对应的动作
 
 @param categoryId 分组ID
 @param pid 产品ID
 @param dataPointArray 该产品下的需要进行操作数据端点列表
 @return 分组触发器动作
 */
+ (instancetype)triggerCategoryActionWithCategoryId:(uint32_t)categoryId
                                          productId:(NSString *)pid
                                     dataPointArray:(NSArray *)dataPointArray;

/**
 添加一个产品及对应的动作
 
 @param pid 产品ID
 @param dataPointArray 该产品下的需要进行操作数据端点列表
 */
- (void)addCategoryWithProductId:(NSString *)pid
                  dataPointArray:(NSArray *)dataPointArray;

@end

NS_ASSUME_NONNULL_END
