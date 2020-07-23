//
//  XLHMessageHomeViewController.h
//  Zensun
//
//  Created by judy on 2018/12/24.
//  Copyright © 2018 www.xlink.cn. All rights reserved.
//

#import <UIKit/UIKit.h>
@class XLHMessageViewModel;

NS_ASSUME_NONNULL_BEGIN

@interface XLHMessageHomeViewController : UIViewController

@property (nonatomic, strong) XLHMessageViewModel *viewModel;

@property (nonatomic, copy) void (^BlockOnRefreshMessage)(void);

@end

NS_ASSUME_NONNULL_END
