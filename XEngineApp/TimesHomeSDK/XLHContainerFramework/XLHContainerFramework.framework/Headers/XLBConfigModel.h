//
//  XLBConfigModel.h
//  XLHContainerFramework
//
//  Created by judy on 2019/8/29.
//  Copyright © 2019 judy. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface XLBConfigModel : NSObject

@property (nonatomic, copy) NSDictionary *userInfo;

@property (nonatomic, copy) NSString *umengAppkey;

@property (nonatomic, copy) NSString *wechatAppkey;

@property (nonatomic, copy) NSString *wechatAppSecret;

@property (nonatomic, copy) NSString *qqAppkey;

@property (nonatomic, copy) NSString *qqAppSecret;

@end

NS_ASSUME_NONNULL_END
