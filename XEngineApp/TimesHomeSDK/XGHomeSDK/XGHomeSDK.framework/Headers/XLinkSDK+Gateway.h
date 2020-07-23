//
//  XLinkSDK+Gateway.h
//  XLinkSDK
//
//  Created by AllenKwok on 2018/1/9.
//  Copyright © 2018年 www.xlink.cn. All rights reserved.
//

#import "XLinkSDK.h"
#import "XLinkGatewayEvent.h"
#import "XLinkConst.h"
#import "XLinkGatewayPassthroughTask.h"

NS_ASSUME_NONNULL_BEGIN

//接收到信息的来源
typedef NS_ENUM(NSUInteger, XLinkDataSource) {
    XLinkDataSourceFromLocal,//来自设备从本地发送
    XLinkDataSourceFromCloud,//来自设备从云端发送
};

#pragma mark - 网关回调

@protocol XLinkGatewayDelegate <NSObject>

@optional
/**
 *  当SDK接收到网关的推送消息时，会回调这个方法。
 *
 *  @param gwDevice 收到推送消息的网关
 */
- (void)onReceiveGatewayEventNotifyWithDevice:(XDevice *)gwDevice
                                withEventList:(NSArray <XLinkGatewayEvent *> *)eventList
                                   withSource:(XLinkDataSource)source;

/**
 当SDK收到设备上报的透传数据，会回调这个方法。
 
 @param xDevice 接收到数据的设备
 @param payloadType 1-普通文字 2-json字符串 3-二进制数据的base64编码字符串
 @param payload 接收到的数据
 @param source 接收到的消息通道
 */
- (void)onReceivePassthroughDataWithDevice:(XDevice *)xDevice
                               payloadType:(XLinkPassthroughPayloadType)payloadType
                                   payload:(NSString *)payload
                                    source:(XLinkDataSource)source;

@end

@interface XLinkSDK (Gateway)

///网关事件回调delegate
@property(weak, nonatomic,nullable) id <XLinkGatewayDelegate> gatewayDelegate;

/**
 获取SDK版本号
 
 @return SDK版本号
 */
+ (NSString *)getXLinkGatewaySDKVersion;

@end

NS_ASSUME_NONNULL_END
