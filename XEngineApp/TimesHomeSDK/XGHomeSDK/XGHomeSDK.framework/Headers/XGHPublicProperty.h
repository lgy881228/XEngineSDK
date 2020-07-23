//
//  XGHPublicProperty.h
//  XGHomeSDK
//
//  Created by Hoony on 2019/11/4.
//  Copyright © 2019 XLH. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "XLHMessageHomeViewController.h"
#import "XLHSceneRecordViewController.h"

NS_ASSUME_NONNULL_BEGIN

@interface XLHMessageHomeViewController (XGHPublicProperty)

@property (nonatomic, strong, readonly)UITableView    *tableView;

@end

@interface XLHSceneRecordViewController (XGHPublicProperty)

@property (nonatomic, strong, readonly)UITableView    *tableView;

@property(nonatomic, strong)NSArray                   *dataArray;

// 清除数据的方法
- (void)deleteSceneLogsRecord;

@end



NS_ASSUME_NONNULL_END
