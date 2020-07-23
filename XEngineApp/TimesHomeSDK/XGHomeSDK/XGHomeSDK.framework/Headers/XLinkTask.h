//
//  Task.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/2/9.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XLinkErrorCode.h"
#import "XLinkConst.h"
@class XLinkTask;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - XLinkTaskDataSource

@protocol XLinkTaskDataSource <NSObject>
/** XLinkTaskDataSource 执行函数*/
/**
 执行所需操作的函数入口
 */
- (void)execute;

/**
 总的运行函数
 */
- (void)main;

/**
 是否重试
 */
- (BOOL)taskShouldRetry;

/** XLinkTaskDataSource 回调函数*/

/**
 任务开始
 */
- (void)taskDidStart;

/**
 任务完成
 */
- (void)taskDidComplete;

/**
 任务超时
 */
- (void)taskDidTimeout;

/**
 任务出现错误
 
 @param error 错误
 */
- (void)taskDidError:(NSError *)error;

@end

typedef NS_ENUM(NSUInteger, TaskState) {
    TaskStateStart = 1,//任务启动
    TaskStateExecute,//任务执行
    TaskStateStop,//任务结束
};

#pragma mark - 以下是废弃属性，之后不定期会删除。
typedef void (^OnTaskStartBlock)(void);
typedef void (^OnTaskCompleteBlock)(XLinkErrorCode code);
typedef void (^TimeoutBlock)(void);
#pragma mark - 以上是废弃属性


typedef void (^XLinkTaskDidStartHandler)(void);
typedef void (^XLinkTaskDidCompletionHandler)( id _Nullable result, NSError *_Nullable error);
typedef void (^XLinkTaskDidTimeoutHandler)(void);

@interface XLinkTask : NSObject <XLinkTaskDataSource>
///是否已启动
@property(assign, nonatomic) BOOL isStarted;

///是否已经超时
@property(assign, nonatomic) BOOL isTimeout;

///是否已经完成
@property(assign, nonatomic) BOOL isComplete;

///默认0s
@property(assign, nonatomic) NSUInteger timeout;

///当前的重试次数
@property(assign, nonatomic) NSUInteger currentRetryCount;

///任务返回的结果
@property(strong, nonatomic ,nullable) id result;

///任务返回的错误
@property(strong, nonatomic ,nullable) NSError *error;


#pragma mark - callback
///task开始的回调
@property (copy, nonatomic ,nullable) XLinkTaskDidStartHandler taskDidStartHandler;

///task完成的回调
@property (copy, nonatomic ,nullable) XLinkTaskDidCompletionHandler taskDidCompletionHandler;

///task超时的回调
@property (copy, nonatomic ,nullable) XLinkTaskDidTimeoutHandler taskDidTimeoutHandler;

#pragma mark - 外部函数

/**
 开始
 */
- (void)start;

/**
 取消
 */
- (void)cancel;

#pragma mark - 以下是废弃属性
///task开始的回调
@property(copy, nonatomic,nullable) OnTaskStartBlock taskStartBlock NS_DEPRECATED(2_0, 2_0, 2_0, 2_0, "已过期, 用taskDidStartHandler替换");
///task完成的回调
@property(copy, nonatomic,nullable) OnTaskCompleteBlock taskCompleteBlock NS_DEPRECATED(2_0, 2_0, 2_0, 2_0, "已过期, 用taskDidCompletionHandler替换");
///任务超时之后的回调
@property(copy, nonatomic,nullable) TimeoutBlock timeoutBlock
NS_DEPRECATED(2_0, 2_0, 2_0, 2_0, "已过期, 用taskDidTimeoutHandler替换");
#pragma mark - 以上是废弃属性

@end

NS_ASSUME_NONNULL_END
