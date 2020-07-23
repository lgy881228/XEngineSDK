//
//  XLinkGatewayEvent.h
//  XLinkSDK
//
//  Created by AllenKwok on 2018/1/9.
//  Copyright © 2018年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XLinkConst.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, XLinkGatewayEvenType) {
    XLinkGatewayEvenTypeAttributeChanged = 1,
    XLinkGatewayEvenTypeConnectionStateChanged = 2,
    XLinkGatewayEvenTypeSubDeviceHardwareStateChanged = 6,//子设备状态变化时,子设备当前的状态,入网/退网/在线/离线
    XLinkGatewayEvenTypeOperationResult = 7,//子设备操作结果事件返回
};

@interface XLinkGatewayEvent : NSObject

///通知类型
@property(assign, nonatomic) XLinkGatewayEvenType eventType;

///通知的内容
@property(copy, nonatomic) NSData *value;

@end

NS_ASSUME_NONNULL_END
