//
//  XLinkDevicePropChangedNotify.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/3/16.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XLinkConst.h"
/**
 设备属性变化通知 
 */

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, DevicePropChangedType) {
    DevicePropChangedTypeInfo = 0,//设备基本属性变化
    DevicePropChangedTypeProp = 1,//设备扩展属性变化
    DevicePropChangedTypeOnline = 2, //设备上线
    DevicePropChangedTypeOffline = 3,//设备下线
};


@interface XLinkDevicePropChangedNotify : NSObject

///设备id
@property(copy, nonatomic) NSNumber *deviceId;

///设备属性变化类型
@property(assign, nonatomic) DevicePropChangedType type;

@end
NS_ASSUME_NONNULL_END
