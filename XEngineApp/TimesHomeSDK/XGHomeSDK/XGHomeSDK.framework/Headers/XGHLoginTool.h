//
//  XGHLoginTool.h
//  XGHomeSDK
//
//  Created by Hoony on 2019/11/5.
//  Copyright © 2019 XLH. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface XGHLoginTool : NSObject

+ (void)loginWithOpenId:(NSString *)openid accessToken:(NSString *)accessToken nickName:(NSString *)nickName completion:(void (^) (id __nullable result, NSError *__nullable err))completion;

+ (void)loginWithPhone:(NSString *)phone pwd:(NSString *)pwd completion:(void (^) (id __nullable result, NSError *__nullable err))completion;

+ (void)logout;

@end

NS_ASSUME_NONNULL_END
