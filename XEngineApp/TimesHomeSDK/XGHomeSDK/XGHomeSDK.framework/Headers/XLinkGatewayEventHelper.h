//
//  XLinkGatewayEventHelper.h
//  XLinkSDK
//
//  Created by AllenKwok on 2018/1/19.
//  Copyright © 2018年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XLinkSubDeviceOptResultEvent.h"
#import "XLinkSubDeviceStateChangedEvent.h"
#import "XLinkConst.h"

NS_ASSUME_NONNULL_BEGIN

@interface XLinkGatewayEventHelper : NSObject

/**
 子设备状态变化事件
 
 @param data 原始的XLinkGatewayEvent数据
 @return 子设备状态变化事件model
 */
+ (XLinkSubDeviceStateChangedEvent *)parseSubDeviceStateChangedEventWithData:(NSData *)data;

/**
 子设备操作异步应答结果事件
 
 @param data 原始的XLinkGatewayEvent数据
 @return 子设备操作异步应答结果model
 */
+ (XLinkSubDeviceOptResultEvent *)parseSubDeviceOptResultEventWithData:(NSData *)data;

@end

NS_ASSUME_NONNULL_END
