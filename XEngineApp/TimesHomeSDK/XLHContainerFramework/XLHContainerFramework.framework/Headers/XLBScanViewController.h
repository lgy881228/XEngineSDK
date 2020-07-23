//
//  JSScanViewController
//
//
//  Created by judy on 2018/1/26.
//  Copyright © 2018年 XlinkH5API All rights reserved.
//

#import <UIKit/UIKit.h>

@interface XLBScanViewController : UIViewController

+ (BOOL)checkIsCanUseDevice;

- (void)showScanViewController:(UIViewController *)vc resultClosure:(void (^)(NSString *))result;

@end
