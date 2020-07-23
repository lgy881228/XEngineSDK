//
//  XLinkHomeDeviceChangedNotify.h
//  XLinkSDK
//
//  Created by AllenKwok on 2018/8/28.
//  Copyright © 2018年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface XLinkHomeDeviceChangedNotify : NSObject

///家庭ID
@property (strong, nonatomic) NSNumber *homeId;

///家庭名称
@property (copy, nonatomic) NSString *homeName;

///设备ID
@property (strong, nonatomic) NSNumber *deviceId;

///操作类型，"add": 设备加入了家庭，"remove": 设备从家庭移除
@property (copy, nonatomic) NSString *type;

@end

NS_ASSUME_NONNULL_END
