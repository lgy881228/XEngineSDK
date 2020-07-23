//
//  XLinkGatewayPassthroughTask.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/10/12.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "XLinkSendPolicyTask.h"
#import "XDevice.h"

NS_ASSUME_NONNULL_BEGIN

/**
 数据类型 1-普通文字 2-json 3-二进制数据的base64编码字符串
 */
typedef NS_ENUM(NSUInteger, XLinkPassthroughPayloadType) {
    XLinkPassthroughPayloadTypeText = 1,//普通文字
    XLinkPassthroughPayloadTypeJson = 2,//json
    XLinkPassthroughPayloadTypeBase64 = 3,//二进制数据的base64编码字符串
};

@interface XLinkGatewayPassthroughTask : XLinkSendPolicyTask

///要发送的设备
@property (strong, nonatomic) XDevice *device;

///数据类型 1-普通文字 2-json 3-二进制数据的base64编码字符串
@property (assign, nonatomic) XLinkPassthroughPayloadType payloadType;

///要发送的数据
@property (copy, nonatomic) NSString *payload;

/**
 构建发送透传数据任务
 
 @param device 发送透传数据的设备
 @param payloadType 发送透传数据的类型 1-普通文字 2-json字符串 3-二进制数据的base64编码字符串
 @param payload 发送透传的数据
 @param timeout 设置超时时间，单位秒，建议10秒
 @param completionHandler 任务完成后回调
 @return XLinkAddDeviceTask
 */
+ (instancetype)passthroughTaskWithDevice:(XDevice *)device
                              payloadType:(XLinkPassthroughPayloadType)payloadType
                                  payload:(NSString *)payload
                                  timeout:(NSUInteger)timeout
                        completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;

/**
 构建发送透传数据任务 并启动
 
 @param device 发送透传数据的设备
 @param payloadType 发送透传数据的类型 1-普通文字 2-json字符串 3-二进制数据的base64编码字符串
 @param payload 发送透传的数据
 @param timeout 设置超时时间，单位秒，建议10秒
 @param completionHandler 任务完成后回调
 @return XLinkAddDeviceTask
 */
+ (instancetype)scheduledPassthroughTaskWithDevice:(XDevice *)device
                                       payloadType:(XLinkPassthroughPayloadType)payloadType
                                           payload:(NSString *)payload
                                           timeout:(NSUInteger)timeout
                                 completionHandler:(XLinkTaskDidCompletionHandler)completionHandler;

@end

//以下是废弃的方法，不建议使用，不久的将来会删除
@interface XLinkGatewayPassthroughTask (XLinkDeprecated)

/**
 构建发送透传数据任务
 
 @param device 发送透传数据的设备
 @param payloadType 发送透传数据的类型 1-普通文字 2-json字符串 3-二进制数据的base64编码字符串
 @param payload 发送透传的数据
 @param timeout 设置超时时间，单位秒，建议10秒
 @param completeBlock 任务完成后回调
 @return XLinkAddDeviceTask
 */
+ (instancetype)sendPassthroughWithDevice:(XDevice *)device
                          withPayloadType:(XLinkPassthroughPayloadType)payloadType
                              withPayload:(NSString *)payload
                              withTimeout:(NSUInteger)timeout
                        withCompleteBlock:(OnTaskCompleteBlock)completeBlock NS_DEPRECATED(2_0, 2_0, 2_0, 2_0, "已废弃方法，请使用+passthroughTaskWithDevice:payloadType:payload:timeout:                                     completionHandler:替换,以后的版本将可能会删除此方法");

@end
NS_ASSUME_NONNULL_END
