//
//  JSOCTool.h
//  XlinkH5API
//
//  Created by judy on 2018/9/29.
//  Copyright © 2018 judy. All rights reserved.
//

#import <Foundation/Foundation.h>
@class XLBConfigModel;

@interface XLBConfigTool : NSObject

@property (nonatomic, strong, readonly) XLBConfigModel *infoModel;

+ (XLBConfigTool *)share;

/**
 配置信息

 @param model 模型
 */
//- (void)configWithModel:(XLBConfigModel *)model;

/**
 配置用户信息

 @param dict 用户信息字典
 */
//- (void)configUserInfoWithDict:(NSDictionary *)dict;

@end
