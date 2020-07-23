//
//  XLinkCategory.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/7/28.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XDevice.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, XLinkCategoryType) {
    XLinkCategoryTypeUnknow = 0,//未知类型
    XLinkCategoryTypeHome,//家庭
    XLinkCategoryTypeRoom,//房间
    XLinkCategoryTypeZone,//区域
};

@interface XLinkCategory : NSObject

///分组id
@property(assign, nonatomic) uint32_t categoryId;

///分组类型
@property(assign, nonatomic) XLinkCategoryType categoryType;

///父分组id
@property(assign, nonatomic) uint32_t parrentCategoryId;

///分组名称
@property(copy, nonatomic, nullable) NSString *categoryName;

///扩展数据
@property(copy, nonatomic, nullable) NSData *extendData;

///子分组id数组
@property(copy, nonatomic, nullable) NSArray <NSNumber *> *childCategoryIdArray;

///分组下面的设备
@property(copy, nonatomic, nullable) NSArray <XDevice *> *devices;

///分组下面的子分组
@property(copy, nonatomic, nullable) NSArray <XLinkCategory *> *childCategoryArray;

- (instancetype)initWithCacheKeyValues:(NSDictionary *)cacheKeyValues;

// 缓存数据
- (NSDictionary *)cacheKeyValues;

/**
 比较两个分组是否为相同
 
 @param category 需要比较的触发器
 @return 比较结果
 */
- (BOOL)isEqualToCategory:(XLinkCategory *)category;

@end

NS_ASSUME_NONNULL_END
