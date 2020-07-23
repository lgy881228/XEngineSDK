//
//  XLinkMaxRetryTask.h
//  XLinkSDKQueue
//
//  Created by AllenKwok on 2017/4/21.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "XLinkTask.h"

NS_ASSUME_NONNULL_BEGIN
@interface XLinkMaxRetryTask : XLinkTask

///最大重试次数
@property(assign, nonatomic) NSUInteger maxRetryCount;

@end
NS_ASSUME_NONNULL_END
