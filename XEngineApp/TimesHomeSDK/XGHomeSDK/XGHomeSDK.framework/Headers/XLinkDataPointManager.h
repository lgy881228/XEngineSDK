//
//  XLinkDataPointManager.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/2/14.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XLinkDataPointObserver.h"
#import "XDevice.h"
#import "XLinkConst.h"

NS_ASSUME_NONNULL_BEGIN

@interface XLinkDataPointManager : NSObject

///所有的监听类对象
@property(strong, nonatomic, readonly) NSMutableArray <XLinkDataPointObserver *> *observerArray;

/**
 单例对象
 
 @return 单例对象
 */
+ (instancetype)shareManager;

/**
 停止数据端点上报监听管理，清除所有缓存
 */
- (void)stopManage;

/**
 添加一个数据端点上报监听
 
 @param dataPointObserver 数据端点上报监听
 */
- (void)addDataPointObserver:(XLinkDataPointObserver *)dataPointObserver;

/**
 移除一个数据端点上报监听
 
 @param dataPointObserver 数据端点上报监听
 */
- (void)removeDataPointObserver:(XLinkDataPointObserver *)dataPointObserver;


/**
 移除某个设备所有数据端点上报监听
 
 @param device 设备实体
 */
- (void)removeAllDataPointObserverWithDevice:(XDevice *)device;

/**
 获取设备的dataPoint的模板
 
 @param device 设备
 @param block 完成后的回调
 */
- (void)getDataPointSourceWithDevice:(XDevice *)device
                     withFinishBlock:(void (^)(NSArray <XLinkDataPoint *> *))block;

@end

NS_ASSUME_NONNULL_END
