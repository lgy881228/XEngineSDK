//
//  XLBShareViewController.h
//  Park
//
//  Created by judy on 2018/12/19.
//  Copyright © 2018 judy. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, XLBShareType) {
    XLBShareTypeWechat = 0,
    XLBShareTypePyq,
    XLBShareTypeQQ,
    XLBShareTypeSMS,
};

NS_ASSUME_NONNULL_BEGIN

@interface XLBShareViewController : UIViewController

- (void)showShareViewControllerWithTypes:(NSArray *)types selectViewController:(UIViewController *)vc resultClosure:(void (^)(NSInteger))result;

@end

NS_ASSUME_NONNULL_END
