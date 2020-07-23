//
//  XLinkHomeDeviceAuthrizeChangedNotify.h
//  XLinkSDK
//
//  Created by AllenKwok on 2018/8/28.
//  Copyright © 2018年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface XLinkHomeDeviceAuthrizeChangedNotify : NSObject

///家庭ID
@property (strong, nonatomic) NSNumber *homeId;

///家庭名称
@property (copy, nonatomic) NSString *homeName;

///设备ID
@property (strong, nonatomic) NSNumber *deviceId;

///对设备的权限
@property (copy, nonatomic) NSString *authority;

///用户ID
@property (strong, nonatomic) NSNumber *userId;

@end

NS_ASSUME_NONNULL_END
