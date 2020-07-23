//
//  XLinkDataPointObserver.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/2/14.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XLinkConst.h"
@class XDevice;
@class XLinkDataPoint;

NS_ASSUME_NONNULL_BEGIN

typedef void (^DataPointUpdateBlock)(XDevice *device, NSArray <XLinkDataPoint *> *dataPoints);

@interface XLinkDataPointObserver : NSObject

///要监听数据端点变化的设备
@property(strong, nonatomic, readonly) XDevice *device;

///要监听的dataPoint的index数组，不传或者传空数组默认监听所有的dataPoint
@property(copy, nonatomic, readonly,nullable) NSArray *indexArray;

///监听到dataPoint变化的回调
@property(copy, nonatomic, readonly) DataPointUpdateBlock block;


/**
 构建一个设备dataPoint变化的监听
 
 @param device 要监听的设备
 @param indexArray 要监听的dataPoint的index数组，不传或者传空数组默认监听所有的dataPoint
 @param block 监听到dataPoint变化的回调
 @return 该监听的对象
 */
+ (instancetype)dataPointObserverWithDevice:(XDevice *)device
                                 IndexArray:(NSArray *_Nullable)indexArray
                   withDataPointUpdateBlock:(DataPointUpdateBlock)block;

@end

NS_ASSUME_NONNULL_END
