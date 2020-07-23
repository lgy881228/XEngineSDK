//
//  HCHttpManager.h
//  H5ContainerDemo
//
//  Created by 覃凤姣 on 2020/4/9.
//  Copyright © 2020 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^HCRequestCompletion) (id __nullable result, NSError *__nullable err);


@interface HCHttpManager : NSObject

+(void)postRequstWithUrl:(NSString *)url params:(NSDictionary *)params token:(nullable NSString *)token completion:(HCRequestCompletion)completion;

@end

NS_ASSUME_NONNULL_END
