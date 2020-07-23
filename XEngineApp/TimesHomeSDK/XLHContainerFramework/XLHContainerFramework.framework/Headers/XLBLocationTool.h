//
//  XLBLocation.h
//  Park
//
//  Created by judy on 2018/11/20.
//  Copyright © 2018 judy. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^ResultClosure)(NSDictionary *);

@interface XLBLocationTool : NSObject

+ (XLBLocationTool *)share;

/**
 开始定位

 @param always 是否一直定位
 @param complete <#complete description#>
 */
- (void)startLocationIsAlwaysLocation:(BOOL)always result:(ResultClosure)complete ;

/**
 停止定位
 */
- (void)stopLcation;

/**
 获取当前城市

 @param completion 回调
 */
- (void)requestCurrentCity:(ResultClosure)completion;

@end

NS_ASSUME_NONNULL_END
