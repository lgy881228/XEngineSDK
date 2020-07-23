//
//  UIBarButtonItem+XLHExtension.h
//  CbyGE
//
//  Created by AllenKwok on 15/12/5.
//  Copyright © 2016年 Xlink.cn. All rights reserved.
//

@import UIKit;

typedef void (^TouchedBlock)(NSInteger tag);

@interface UIBarButtonItem (XLHExtension)

//单纯文字
+ (instancetype)xlh_createBarButtonItemWithText:(NSString *)text andAction:(TouchedBlock)action;

//文字
+ (instancetype)xlh_createBackBarButtonItemWithText:(NSString *)text icon:(NSString *)icon andAction:(TouchedBlock)action;

@end
