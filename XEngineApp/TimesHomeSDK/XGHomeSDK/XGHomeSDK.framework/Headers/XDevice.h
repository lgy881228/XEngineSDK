//
//  XDevice.h
//  XLinkSdkLib
//
//  Created by AllenKwok on 2017/2/5.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XLinkConst.h"

NS_ASSUME_NONNULL_BEGIN

//设备类型
typedef NS_ENUM(NSUInteger, XDeviceType) {
    XDeviceTypeSingleDevice = 0,//单品设备
    XDeviceTypeMasterGateway,//主网关
    XDeviceTypeSubDevice,//子设备
};

//设备连接状态
typedef NS_ENUM(uint8_t, XDeviceConnectionState) {
    XDeviceConnectionStateDetached = 0,//XDevice的状态未知
    XDeviceConnectionStateOffline = 1,//SDK设备与设备失去连接
    XDeviceConnectionStateConnecting = 2,//SDK正在连接设备
    XDeviceConnectionStateOnline = 3,//SDK设备保持连接
};


@interface XDevice : NSObject

/** 产品ID*/
@property (copy, nonatomic) NSString *productID;

/** MAC地址*/
@property (copy, nonatomic) NSData *macAddress;

/**
 获得Mac地址的字符串形式，格式：00:00:11:aa:bb:cc
 */
@property (copy, nonatomic,getter = getMacAddressString) NSString *macAddressString;

/**
 获得Mac地址的字符串形式,格式：000011AABBCC
 */
@property (copy, nonatomic,getter = getMacAddressSimple) NSString *macAddressSimple;

/** 设备名称*/
@property (copy, nonatomic) NSString *deviceName;

/** 权限*/
@property (strong, nonatomic) NSNumber *role;

/** 来源*/
@property (strong, nonatomic) NSNumber *source;

/** 设备ID*/
@property (assign, nonatomic) uint32_t deviceID;

/** 内网配对id*/
@property (assign, nonatomic) uint16_t pairingID;

/** 内网配对秘钥*/
@property (copy, nonatomic) NSData *pairingSignature;

/** 内网配对凭证*/
@property (copy, nonatomic,nullable) NSData *ticket;

/** IP地址*/
@property (copy, nonatomic) NSData *address;

/** 协议版本*/
@property (assign, nonatomic) uint16_t protocolVersion;

/** 固件型号*/
@property (copy, nonatomic) NSString *firmwareMod;

/** 固件版本号*/
@property (copy, nonatomic) NSString *firmwareVersion;

/** MCU型号*/
@property (copy, nonatomic) NSString *mcuMod;

/** mcu软件版本号*/
@property (copy, nonatomic) NSString *mcuVersion;

/** 上次登录的时间，格式2017-10-17T17:43:35.881Z*/
@property (copy, nonatomic) NSString *lastLoginDate;

/** 订阅设备的时间*/
@property (copy, nonatomic) NSString *subscribeDate;

/** 设备序列号*/
@property (copy, nonatomic) NSString *sn;

/** 对设备的控制权限，**R可读，W可写，RW可读可写；默认为null相当于RW**；*/
@property (copy, nonatomic) NSString *authority;

/** 是否激活*/
@property (assign, nonatomic) BOOL isActive;

/** 设备的激活时间*/
@property (copy, nonatomic) NSString *activeDate;

/** 激活码*/
@property (copy, nonatomic) NSString *activeCode;

/** 认证码*/
@property (copy, nonatomic) NSString *authorizeCode;

/** 设备销售时间*/
@property (copy, nonatomic) NSString *salesDate;

/** 设备类型*/
@property (assign, nonatomic) XDeviceType deviceType;

/** 设备是否被绑定过*/
@property (assign, nonatomic) uint8_t isBinded;

/** 云端是否在线,只代表云端记录的设备是否在线，不代表APP和设备建立了连接，建议设备的连接状态使用connectionState或者cloudConnectionState两个字段来表示*/
@property (assign, nonatomic) BOOL isCloudOnline;

/** 是否支持订阅码订阅*/
@property (assign, nonatomic,getter=isSupportSubByCode) BOOL supportSubByCode;

/**
 返回DETACHED时，表示SDK尚未尝试过内网或者外网连接。
 返回OFFLINE时，表示SDK与设备无内外网连接
 返回ONLINE时，表示SDK与设备内外网连接或者内网连接。
 返回CONNECTING时，表示SDK与设备无内外网连接，但正在尝试进行内网或者外网连接。
 */
@property (assign, nonatomic) XDeviceConnectionState connectionState;

/**
 内网连接状态
 返回DETACHED时，表示SDK尚未尝试过内网连接。
 返回OFFLINE时，表示SDK与设备无内网连接
 返回ONLINE时，表示SDK与设备内网连接。
 返回CONNECTING时，正在尝试进行内网连接。
 */
@property (assign, nonatomic) XDeviceConnectionState localConnectionState;

/**
 外网连接状态
 返回DETACHED时，表示SDK尚未尝试过外网连接。
 返回OFFLINE时，表示SDK与设备无外网连接
 返回ONLINE时，表示SDK与设备外网连接。
 返回CONNECTING时，正在尝试进行外网连接。
 */
@property (assign, nonatomic) XDeviceConnectionState cloudConnectionState;

/**
 网关设备id
 */
@property (assign, nonatomic) uint32_t gatewayId;

/**
 是否是网关设备
 */
@property (assign, nonatomic) BOOL isGatewayDevice;

/** 父设备*/
@property (weak, nonatomic,nullable) XDevice *parentDevice;

/**
 *  通过字典还原成设备实体
 *
 *  @param dic 设备字典
 *
 *  @return 设备实体
 */
- (instancetype)initWithDictionary:(NSDictionary *)dic;

/**
 *  将设备属性格式化成字典
 *
 *  @return 设备属性字典
 */
- (NSDictionary *)getDictionaryFormat;

/**
 比较两个设备是否是同一个设备
 
 @param otherDevice 另一个要比较的设备
 @return 比较结果
 */
- (BOOL)isEqualToDevice:(XDevice *)otherDevice;

@end
NS_ASSUME_NONNULL_END
