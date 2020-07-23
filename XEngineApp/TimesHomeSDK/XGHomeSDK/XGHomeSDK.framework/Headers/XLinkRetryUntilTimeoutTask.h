//
//  XLinkRetryUntilTimeoutTask.h
//  XLinkSDKQueue
//
//  Created by AllenKwok on 2017/4/28.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "XLinkBackoffTask.h"

NS_ASSUME_NONNULL_BEGIN

#pragma mark - XLinkRetryUntilTimeoutTaskDataSource

@protocol XLinkRetryUntilTimeoutTaskDataSource <NSObject>
/**
 任务超时
 */
- (void)taskDidTotalTimeout;

@end

@interface XLinkRetryUntilTimeoutTask : XLinkBackoffTask <XLinkRetryUntilTimeoutTaskDataSource,XLinkTaskDataSource>

/// task总的超时时间
@property(assign, nonatomic) NSUInteger totalTimeout;

@end
NS_ASSUME_NONNULL_END
