//
//  XLinkHomeInviteNotify.h
//  XLinkSDK
//
//  Created by AllenKwok on 2018/8/28.
//  Copyright © 2018年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@interface XLinkHomeInviteNotify : NSObject

///家庭ID
@property (strong, nonatomic) NSNumber *homeId;

///家庭名称
@property (copy, nonatomic) NSString *homeName;

///邀请者ID
@property (strong, nonatomic) NSNumber *fromId;

///邀请者名称
@property (copy, nonatomic) NSString *fromName;

///被邀者ID
@property (strong, nonatomic) NSNumber *toId;

///被邀者名称
@property (copy, nonatomic) NSString *toName;

///此次邀请请求的ID
@property (copy, nonatomic) NSString *invite_id;

///操作类型: invite/accept/deny
@property (copy, nonatomic) NSString *opt;

@end

NS_ASSUME_NONNULL_END
