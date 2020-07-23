//
//  XGHDeviceTool.h
//  XGHomeSDK
//
//  Created by Hoony on 2019/12/11.
//  Copyright © 2019 XLH. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface XGHDeviceTool : NSObject

+ (instancetype)shareTool;


/// 对阿里设备进行重置
/// 重置要求先登录
/// @param iotId IOTID
/// @param callBack 回调
- (void)resetDeviceWithIotId:(NSString *)iotId handler:(void(^)(NSError * error))callBack;

- (void)resetDeviceWithProductKey:(NSString *)pk deviceName:(NSString *)dn handler:(void (^)(NSError * _Nonnull))callBack;

/// 对阿里设备进行解绑
/// 重置要求先登录
/// @param iotId IOTID
/// @param callBack 回调
//- (void)unbindDeviceWithIotId:(NSString *)iotId handler:(void(^)(NSError * error))callBack;

@end

NS_ASSUME_NONNULL_END
