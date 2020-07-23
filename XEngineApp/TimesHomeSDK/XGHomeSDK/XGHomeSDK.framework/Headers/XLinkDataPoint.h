//
//  XLinkDataPoint.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/2/14.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XLinkConst.h"

NS_ASSUME_NONNULL_BEGIN

/**
 数据端点值数据类型
 */
typedef NS_ENUM(uint8_t, XLinkDataType) {
    XLinkDataTypeBool = 1,//布尔类型
    XLinkDataTypeByte = 2,//单字节(无符号)
    XLinkDataTypeShort = 3,//16位短整型（有符号）
    XLinkDataTypeInt = 4,//32位整型（有符号）
    XLinkDataTypeFloat = 5,//浮点
    XLinkDataTypeString = 6,//字符串
    XLinkDataTypeByteArray = 7,//字节数组
    XLinkDataTypeUnsignedShort = 8,//16位短整型（无符号）
    XLinkDataTypeUnsignedInt = 9,//32位整型（无符号)
};

@interface XLinkDataPoint : NSObject

//数据端点id
@property (nonatomic, copy) NSString *dataPointId;

//是否系统数据端点
@property BOOL isSystem;

///数据端点值数据类型
@property(assign, nonatomic) XLinkDataType type;

///数据端点index
@property(assign, nonatomic) uint8_t index;

/**
 数据端点的值
 如果type是XLinkDataTypeBool、XLinkDataTypeByte、XLinkDataTypeShort、XLinkDataTypeInt、XLinkDataTypeFloat、XLinkDataTypeUnsignedShort、XLinkDataTypeUnsignedInt，那么value应该是NSNumber类型；
 如果type是XLinkDataTypeString，那么value应该是NSString类型；
 如果type是XLinkDataTypeByteArray，那么value应该是NSData类型；
 */
@property(strong, nonatomic) id value;

///数据端点的长度
@property(assign, nonatomic) uint16_t len;

///数据端点最大值
@property(assign, nonatomic) long long maxValue;

///数据端点最小值
@property(assign, nonatomic) long long minValue;

///数据端点名称
@property(copy, nonatomic) NSString *name;

///数据端点描述
@property (copy, nonatomic) NSString *dataPointDesc;

///符号
@property (copy, nonatomic) NSString *symbol;

///数据端点是否可读
@property (assign, nonatomic) BOOL isRead;

///数据端点是否可写
@property (assign, nonatomic) BOOL isWrite;

///是否收集端点数据
@property (assign, nonatomic) BOOL isCollect;

///默认值
@property (copy, nonatomic) NSString *defaultValue;

///动态计算数据端点表达式
@property (copy, nonatomic) NSString *expression;

/**
 数据端点来源类型.
 -1 | 未知
 1 | 设备上报
 2 | 动态计算
 3 | 应用设置
 */
@property (assign, nonatomic) uint16_t source;

//UI可见(远程控制可见"control": true,设备状态可见"state": true)
@property (nonatomic, copy) NSDictionary *uiVisible;

//字段名称
@property (nonatomic, copy) NSString *fieldName;

/**
 *  通过字典还原成数据端点实体
 *
 *  @param dic 数据端点字典
 *
 *  @return 数据端点实体
 */
- (instancetype)initWithDictionary:(NSDictionary *)dic;

/**
 *  将数据端点格式化成字典
 *
 *  @return 数据端点属性字典
 */
- (NSDictionary *)getDictionaryFormat;

/**
 比较两个数据端点是否为同一数据端点
 
 @param dataPoint 需要比较的数据端点
 @return 比较结果
 */
- (BOOL)isEqualToDataPoint:(XLinkDataPoint *)dataPoint;

@end

NS_ASSUME_NONNULL_END
