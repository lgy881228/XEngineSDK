//
//  XLinkBroadcastNotify.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/3/16.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XLinkConst.h"

NS_ASSUME_NONNULL_BEGIN

///厂商推送的消息广播
@interface XLinkBroadcastNotify : NSObject

///消息类型，暂时只有txt
@property(copy, nonatomic) NSString *messageType;

///url/command
@property(copy, nonatomic) NSString *actionType;

///如果action_type是url时的参数
@property(copy, nonatomic) NSString *url;

///用户自定义动作,如果action_type是command时的参数；
@property(copy, nonatomic) NSString *command;

///消息标题，UTF-8
@property(copy, nonatomic) NSString *title;

///消息内容，UTF-8
@property(copy, nonatomic) NSString *content;

@end

NS_ASSUME_NONNULL_END
