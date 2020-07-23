//
//  XLBWebViewController.h
//  Park
//
//  Created by judy on 2019/2/22.
//  Copyright © 2019 judy. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface XLBWebViewController : UIViewController

@property (nonatomic, copy) NSString *loadUrl;

@property (nonatomic, copy) NSString *locationUrl;

/** 是否需要隐藏导航栏 */
@property (nonatomic, assign) BOOL isNeedToHideNav;


@end

NS_ASSUME_NONNULL_END
