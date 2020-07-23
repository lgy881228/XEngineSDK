//
//  DataPointAlertNotify.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/3/16.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XLinkConst.h"


NS_ASSUME_NONNULL_BEGIN
/**
 设备数据端点变换引起的报警
 */
@interface XLinkDataPointAlertNotify : NSObject

///变化数据端点的index
@property(assign, nonatomic) NSUInteger index;

///变化数据端点的数据
@property(copy, nonatomic) NSNumber *value;

///管理台设置的报警内容
@property(copy, nonatomic) NSString *alarmMessage;

@end
NS_ASSUME_NONNULL_END
