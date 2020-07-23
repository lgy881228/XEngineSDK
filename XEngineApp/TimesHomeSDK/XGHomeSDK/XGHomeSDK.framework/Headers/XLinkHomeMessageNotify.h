//
//  XLinkHomeMessageNotify.h
//  XLinkSDK
//
//  Created by AllenKwok on 2018/8/28.
//  Copyright © 2018年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface XLinkHomeMessageNotify : NSObject

///家庭ID
@property (strong, nonatomic) NSNumber *homeId;

///家庭名称
@property (copy, nonatomic) NSString *homeName;

///消息发送者ID
@property (strong, nonatomic) NSNumber *fromId;

///消息发送者名称
@property (copy, nonatomic) NSString *fromName;

///消息类型
@property (copy, nonatomic) NSString *type;

///消息标题
@property (copy, nonatomic) NSString *title;

///消息内容
@property (copy, nonatomic) NSString *content;

@end

NS_ASSUME_NONNULL_END
