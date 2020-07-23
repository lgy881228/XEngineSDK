//
//  XLinkSDK.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/2/5.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XLinkConfig.h"
#import "XDevice.h"
#import "XLinkDataPoint.h"
#import "XLinkUserModel.h"
#import "XLinkErrorCode.h"
#import "XLinkConst.h"

@class XLinkTask;
@class XLinkEventNotify;
@class XLinkDataPointManager;
@class XDeviceManager;

NS_ASSUME_NONNULL_BEGIN

#pragma mark 设置云端回调
//和cloud服务器连接状态
typedef NS_ENUM(NSUInteger, CloudConnectionState) {
    CloudConnectionStateConnectFail = 0,//连接失败
    CloudConnectionStateConnectConnecting = 1,//连接中
    CloudConnectionStateConnectSuccess = 2,//连接成功
};

typedef NS_ENUM(NSUInteger, XDeviceEvent) {
    XDeviceEventUnSubscribe = 0,//订阅关系取消
    XDeviceEventSubscribe = 1,//订阅关系建立
    XDeviceEventInfoChanged = 2,//设备基本属性变化
    XDeviceEventPropertyChanged = 3,//设备基本属性变化
};

typedef NS_ENUM(NSUInteger, LogoutReason) {
    LogoutReasonUserLogout = 0,//用户主动退出
    LogoutReasonSingleSignKickOff = 1,//单点登录。当前用户被踢出
    LogoutReasonTokenExpired = 2,//用户凭证过期
    LogoutReasonUserAuthInfoInvaild = 3,//用户授权信息不正确
};


#pragma mark - 云端回调

@protocol XLinkCloudDelegate <NSObject>

@optional
/**
 *  当SDK与云平台连上/断开的时候，会回调这个方法
 *
 *  @param state 连接状态
 */
- (void)onCloudStateChangedWithCloudConnectionState:(CloudConnectionState)state;

/**
 *  当SDK连接上云端，并接收到云端推送时，会回调这个方法。
 *
 *  @param eventNotify 收到的云端推送信息
 */
- (void)onReceiveEventNotify:(XLinkEventNotify *)eventNotify;

@end

#pragma mark - 用户授权结果回调

@protocol XLinkUserDelegate <NSObject>

@optional

/**
 用户被下线（被踢或者手动退出）/授权信息过期 的时候，会回调这个方法。
 请根据LogoutReason进行处理

 @param reason 下线原因
 */
- (void)onUserLogout:(LogoutReason)reason;

@end

#pragma mark - 数据回调

@protocol XLinkDataDelegate <NSObject>

@optional

/**
 *  当SDK收到设备上报的所以的数据端点时，会回调这个方法。
 *
 *  @param xDevice 接收到数据的设备
 *  @param list    数据端点列表
 */
- (void)onDataPointUpdateWithDevice:(XDevice *)xDevice withList:(NSArray <XLinkDataPoint *> *)list;

@end


#pragma mark - 设备状态回调

@protocol XLinkDeviceStateDelegate <NSObject>

@optional
/**
 *  受SDK管理的设备（用户未调用`XLinkSDK.getDeviceManager().removeDevice(xDevice)`）状态发生改变时。
 *
 *  @param xDevice 设备状态的设备
 *  @param state   设备状态
 */
- (void)onDeviceStateChanged:(XDevice *)xDevice withDeviceState:(XDeviceConnectionState)state;

/**
 *   设备属性或者设备状态发生改变时，会回调这个方法。
 *
 *  @param xDevice 发生改变的设备
 */
- (void)onDeviceChanged:(XDevice *)xDevice withEvent:(XDeviceEvent)event;

@end


@interface XLinkSDK : NSObject

///SDK云端连接状态回调delegate
@property(weak, nonatomic,nullable) id <XLinkCloudDelegate> cloudDelegate;

///SDK用户授权相关回调delegate
@property(weak, nonatomic,nullable) id <XLinkUserDelegate> userDelegate;

///SDK数据相关的delegate，包括接收到dataPoint的更新
@property(weak, nonatomic,nullable) id <XLinkDataDelegate> dataDelegate;

///SDK设备状态相关的delegate，包括设备在线离线状态和设备属性的变化
@property(weak, nonatomic,nullable) id <XLinkDeviceStateDelegate> deviceStateDelegate;

///SDK全局的配置
@property(strong, nonatomic ,nullable) XLinkConfig *xlinkConfig;

///SDK的dataPoint管理类
@property(strong, nonatomic ,nullable) XLinkDataPointManager *dataPointManager;

/// SDK的设备管理类
@property(strong, nonatomic ,nullable) XDeviceManager *deviceManager;

///SDK的云端登陆状态
@property(assign, nonatomic) CloudConnectionState cloudState;

///当前登陆的用户
@property(strong, nonatomic ,nullable) XLinkUserModel *userModel;

///用于判断sdk是否已经启动
@property(assign, nonatomic, getter = isStarted) BOOL started;

/**
 SDK单例
 
 @return 全局的单例对象
 */
+ (instancetype)share;

/**
 使用默认配置参数开始运行SDK
 */
- (void)start;

/**
 使用自定义配置参数开始运行SDK
 
 @param xlinkConfig SDK的配置参数
 */
- (void)startWithConfig:(XLinkConfig *)xlinkConfig;

/**
 停止SDK, 断开云端连接
 */
- (void)stop;

/**
 退出登陆状态，断开云端连接，回收资源，清除授权信息。
 */
- (void)logout;

/**
 退出登陆状态，断开云端连接，回收当前用户资源，清除授权信息。
 */
- (void)logoutAndStop;

/**
 获取SDK版本号
 
 @return SDK版本号
 */
+ (NSString *)getXLinkSDKVersion;

#pragma mark - task api

/**
 开始一个任务
 
 @param task 任务
 */
- (void)startTask:(XLinkTask *)task;

/**
 结束任务执行
 
 @param task 任务
 */
- (void)stopTask:(XLinkTask *)task;

@end

NS_ASSUME_NONNULL_END

