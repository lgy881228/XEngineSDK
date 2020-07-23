//
//  XLinkLinkageCondition.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/3/31.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "XLinkTriggerCondition.h"
#import "XLinkDataPoint.h"
#import "XDevice.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, XLinkLinkageConditionType) {
    XLinkLinkageConditionTypeGreaterThan,// 大于
    XLinkLinkageConditionTypeGreaterEqual,// 大于等于
    XLinkLinkageConditionTypeLessThan,//小于
    XLinkLinkageConditionTypeLessEqual,//小于等于
    XLinkLinkageConditionTypeEqual,//等于
    XLinkLinkageConditionTypeNotEqual,//不等于
    XLinkLinkageConditionTypeInRange// 在范围内（闭区间）
};

@interface XLinkLinkageCondition : XLinkTriggerCondition

///来源设备的mac地址
@property(copy, nonatomic) NSData *deviceMacAddres;

///来源设备的productId
@property(copy, nonatomic) NSString *productId;

///判断条件
@property(assign, nonatomic) XLinkLinkageConditionType linkageConditionType;

///参数1的值。一般表示比较的标准值。在在linkageConditionType == XLinkLinkageConditionTypeInRange（闭区间）的时候表示左区间的值。
@property(strong, nonatomic) XLinkDataPoint *dataPoint1;

///参数2的值，只在linkageConditionType == XLinkLinkageConditionTypeInRange（闭区间）的时候用到。dataPoint1表示左区间的值，dataPoint2表示右区间的值
@property(strong, nonatomic,nullable) XLinkDataPoint *dataPoint2;

@end

NS_ASSUME_NONNULL_END
