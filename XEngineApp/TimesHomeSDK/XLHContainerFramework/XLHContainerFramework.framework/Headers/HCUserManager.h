//
//  HCUserManager.h
//  H5ContainerDemo
//
//  Created by 覃凤姣 on 2020/4/9.
//  Copyright © 2020 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>

@class HCUserModel;

NS_ASSUME_NONNULL_BEGIN

@interface HCUserManager : NSObject

+(instancetype)sharedManager;
 
- (void)saveUser:(HCUserModel *)user;

- (HCUserModel *)getCacheUserInfo;

- (void)logout;

- (BOOL)isLogin;

- (void)getToken:(void(^)(HCUserModel *user,NSError *error))callback;

@end

NS_ASSUME_NONNULL_END
