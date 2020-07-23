//
//  XLinkHomeMemberChangedNotify.h
//  XLinkSDK
//
//  Created by AllenKwok on 2018/8/28.
//  Copyright © 2018年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface XLinkHomeMemberChangedNotify : NSObject

///家庭ID
@property (strong, nonatomic) NSNumber *homeId;

///家庭名称
@property (copy, nonatomic) NSString *homeName;

///用户ID
@property (strong, nonatomic) NSNumber *userId;

///用户名称
@property (copy, nonatomic) NSString *name;

///家庭成员角色
@property (copy, nonatomic) NSNumber *role;

///操作类型: add/remove
@property (copy, nonatomic) NSString *type;

@end

NS_ASSUME_NONNULL_END
