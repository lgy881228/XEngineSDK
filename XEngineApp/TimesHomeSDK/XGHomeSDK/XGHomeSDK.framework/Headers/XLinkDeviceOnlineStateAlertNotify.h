//
//  XLinkDeviceOnlineStateAlertNotify.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/3/16.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XLinkConst.h"

NS_ASSUME_NONNULL_BEGIN
/**
 设备在线状态变化引发的告警
 */
typedef NS_ENUM(NSUInteger, DeviceOnlineState) {
    DeviceOnlineStateOffline = 0,//离线
    DeviceOnlineStateOnline = 1,//在线
};


@interface XLinkDeviceOnlineStateAlertNotify : NSObject

///设备id
@property(copy, nonatomic) NSNumber *deviceId;

///设备在线状态
@property(assign, nonatomic) DeviceOnlineState state;

@end
NS_ASSUME_NONNULL_END
