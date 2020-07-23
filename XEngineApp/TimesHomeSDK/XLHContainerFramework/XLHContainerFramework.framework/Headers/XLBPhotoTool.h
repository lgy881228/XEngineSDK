//
//  XLBPhotoTool.h
//  Park
//
//  Created by judy on 2019/1/2.
//  Copyright © 2019 judy. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface XLBPhotoTool : NSObject

/// 是否需要裁剪
@property (assign, nonatomic) BOOL needEditing;

+ (XLBPhotoTool *)share;

- (void)showWithViewController:(UIViewController *)vc
                       handler:(void(^)(id result, NSError *error))handler;

- (void)showWithViewController:(UIViewController *)vc
                         title:(NSString * _Nullable)title
          takePhotoButtonTitle:(NSString *)takePhotoButtonTitle
        selectPhotoButtonTitle:(NSString *)selectPhotoButtonTitle
             cancelButtonTitle:(NSString *)cancelBtnTitle
                       handler:(void(^)(id result, NSError *error))handler;

- (void)takePhotoWithViewController:(UIViewController *)vc
                            handler:(void(^)(id result, NSError *error))handler;

@end

NS_ASSUME_NONNULL_END
