//
//  XLinkSubDeviceStateChangedEvent.h
//  XLinkSDK
//
//  Created by AllenKwok on 2018/1/24.
//  Copyright © 2018年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XDevice.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, XLinkSubDeviceState) {
    XLinkSubDeviceStateOnline = 1,//设备在线
    XLinkSubDeviceStateUnknow,//未知状态
    XLinkSubDeviceStateNoResponse,//设备没有响应
    XLinkSubDeviceStateLeft,//设备离开(即未入网或已退网)
};

@interface XLinkSubDeviceStateChangedEvent : NSObject

///上报数据的子设备
@property(strong, nonatomic) XDevice *device;

///操作类型
@property(assign, nonatomic) XLinkSubDeviceState deviceState;

@end

NS_ASSUME_NONNULL_END
