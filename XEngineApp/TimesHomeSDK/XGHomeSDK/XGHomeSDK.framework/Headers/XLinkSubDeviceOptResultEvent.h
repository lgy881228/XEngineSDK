//
//  XLinkSubDeviceOptResultEvent.h
//  XLinkSDK
//
//  Created by AllenKwok on 2018/1/24.
//  Copyright © 2018年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XDevice.h"

NS_ASSUME_NONNULL_BEGIN

@interface XLinkSubDeviceOptResultEvent : NSObject

///上报数据的子设备
@property(strong, nonatomic) XDevice *device;

///操作类型
@property(assign, nonatomic) uint8_t opttype;

///返回结果
@property(assign, nonatomic) uint8_t code;

///描述数据
@property(strong, nonatomic) NSData *descData;


@end

NS_ASSUME_NONNULL_END
