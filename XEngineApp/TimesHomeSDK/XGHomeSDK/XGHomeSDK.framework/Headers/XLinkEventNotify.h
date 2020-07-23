//
//  XLinkEventNotify.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/2/13.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XLinkConst.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, EventNotifyFromType) {
    EventNotifyFromSever = 1,//来自Server触发事件
    EventNotifyFromDevice,//来自Device触发事件
    EventNotifyFromAPP,//来自App触发事件
};

typedef NS_ENUM(NSUInteger, EventNotifyFlag) {
    EventNotifyFlagBinary = 0,//二进制数据
    EventNotifyFlagString = 1,//字符串
};

typedef NS_ENUM(NSUInteger, EventNotifyType) {
    EventNotifyTypeDataPointChanged = 1,//设备数据端点变化发送的通知
    EventNotifyTypeDataPointAlert = 2,//设备数据端点变换引起的报警
    EventNotifyTypeDeviceShare = 3,//设备管理员推送的分享消息
    EventNotifyTypeBoardcast = 4,//厂商推送的消息广播
    EventNotifyTypeDevicePropChanged = 5,//设备属性变化通知
    EventNotifyTypeSubscribeChanged = 6,//用户和设备订阅关系发生变化通知
    EventNotifyTypeDeviceOnlineStateChanged = 7,//设备在线状态变化引发的通知
    EventNotifyTypeDeviceOnlineStateAlert = 8,//设备在线状态变化引发的告警
    EventNotifyTypeHomeMessage = 9,//家庭消息通知
    EventNotifyTypeHomeInvite = 10,//家庭邀请通知
    EventNotifyTypeHomeDeviceAuthrizeChanged = 11,//家庭设备权限变化通知
    EventNotifyTypeHomeMemberChanged = 12,//家庭成员变化通知
    EventNotifyTypeHomeDeviceChanged = 13,//家庭设备变化通知
};

@interface XLinkEventNotify : NSObject

///通知事件触发来源类型
@property(nonatomic, assign) EventNotifyFromType fromType;

///notify来源
@property(nonatomic, assign) uint32_t fromID;

///消息类型
@property(nonatomic, assign) EventNotifyType messageType;

///通知事件标志
@property(assign, nonatomic) EventNotifyFlag notifyFlag;

///消息的原始数据
@property(nonatomic, copy) NSData *notifyData;

@end

NS_ASSUME_NONNULL_END
