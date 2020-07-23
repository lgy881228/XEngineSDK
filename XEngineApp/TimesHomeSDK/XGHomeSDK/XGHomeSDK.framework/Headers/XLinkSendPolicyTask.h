//
//  XLinkSendPolicyTask.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/8/22.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import "XLinkTask.h"
#import "XLinkConfig.h"

NS_ASSUME_NONNULL_BEGIN

#pragma mark - XLinkRetryUntilTimeoutTaskDataSource

@protocol XLinkSendPolicyTaskDataSource <NSObject>
/**
 通过本地发送数据，需子类重写
 */
- (void)sendDataByLocal;

/**
 通过云端发送数据，需子类重写
 */
- (void)sendDataByCloud;

/**
 本地发送数据失败
 */
- (void)sendDataByLocalDidFail;

/**
 云端发送数据失败
 */
- (void)sendDataByCloudDidFail;

@end

@interface XLinkSendPolicyTask : XLinkTask <XLinkSendPolicyTaskDataSource>

///这个任务的单独发送策略，只要设置了，就不会受全局的发送策略影响
@property (assign, nonatomic) XLinkSendDataPolicy sendDataPolicy;

@end

NS_ASSUME_NONNULL_END
