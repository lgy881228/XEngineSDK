//
//  HCLoginTool.h
//  H5ContainerDemo
//
//  Created by 覃凤姣 on 2020/4/9.
//  Copyright © 2020 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^HCLoginRequestCompletion) (id __nullable result, NSError *__nullable err);

@interface HCLoginTool : NSObject

+ (void)loginWithAccount:(NSString *)account password:(NSString *)password completion:(HCLoginRequestCompletion)completion;

+ (void)refreshToken:(void(^)(NSString *token,NSError *error))callback;

@end

NS_ASSUME_NONNULL_END
