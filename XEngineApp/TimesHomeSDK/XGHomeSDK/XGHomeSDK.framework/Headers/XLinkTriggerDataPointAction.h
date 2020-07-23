//
//  XLinkTriggerDataPointAction.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/3/31.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//
//  改变某个设备的某些数据端点的值

#import "XLinkTriggerAction.h"
#import "XLinkDataPoint.h"

NS_ASSUME_NONNULL_BEGIN

@interface XLinkTriggerDataPointAction : XLinkTriggerAction

///目标设备的mac地址
@property(copy, nonatomic) NSData *deviceMacAddres;

///目标设备的product_id
@property(copy, nonatomic) NSString *productId;

///目标数据端点列表
@property(copy, nonatomic) NSArray <XLinkDataPoint *> *datapoints;

@end

NS_ASSUME_NONNULL_END
