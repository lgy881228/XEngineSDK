//
//  HCUserModel.h
//  H5ContainerDemo
//
//  Created by 覃凤姣 on 2020/4/9.
//  Copyright © 2020 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HCUserModel : NSObject

@property (nonatomic, strong)NSString *accessToken;
@property (nonatomic, strong)NSString *refreshToken;
@property (nonatomic, strong)NSString *corpId;
@property (nonatomic, strong)NSString *memberId;
@property (nonatomic, assign)NSInteger roleType;
@property (nonatomic, assign)NSInteger expireIn;
@property (nonatomic, strong)NSString *user_id;


@end

NS_ASSUME_NONNULL_END
