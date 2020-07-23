//
//  XGHRouter.h
//  XGHomeSDK
//
//  Created by Hoony on 2019/11/1.
//  Copyright © 2019 XLH. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface XGHRouter : NSObject

+ (instancetype)shareRouter;

- (UIViewController *(^)(void))xhomeFurnishingVC;
- (UIViewController *(^)(void))testVC;

@end

NS_ASSUME_NONNULL_END
