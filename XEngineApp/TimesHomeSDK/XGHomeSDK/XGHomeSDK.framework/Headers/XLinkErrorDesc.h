//
//  XLinkErrorDesc.h
//  XLinkSDK
//
//  Created by AllenKwok on 2018/3/22.
//  Copyright © 2018年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XLinkConst.h"

NS_ASSUME_NONNULL_BEGIN

@interface XLinkErrorDesc : NSObject

///错误名
@property (copy, nonatomic) NSString *errorName;

///错误描述
@property (copy, nonatomic) NSString *errorDescString;

+ (instancetype)errorDescWithErrorName:(NSString *)errorName
                       errorDescString:(NSString *)errorDescString;

@end
NS_ASSUME_NONNULL_END
