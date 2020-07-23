//
//  UIColor+XHTheme.h
//  Zensun
//
//  Created by Chris on 2019/8/6.
//  Copyright © 2019 www.xlink.cn. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "UIImage+XGHAccess.h"

NS_ASSUME_NONNULL_BEGIN

@interface UIColor (XHTheme)

+ (UIColor *)xh_colorWithHexString:(NSString *)hexString;

/// 主题色 222222
+ (UIColor *)xh_themeColor;

/// 背景色 FFFFFF
+ (UIColor *)xh_backgroundColor;

///列表背景颜色 F8F9FA
+ (UIColor *)xh_listBackgroundColor;

///边框颜色 D9D9D9
+ (UIColor *)xh_borderColor;

#pragma mark - 按钮

/// 正常背景色(按钮) 222222
+ (UIColor *)xh_buttonNormalBackgroundColor;

/// 高亮背景色(按钮)
+ (UIColor *)xh_buttonHighlightedBackgroundColor;

/// 不可点击背景色(按钮) 333333
+ (UIColor *)xh_buttonDisabledBackgroundColor;

/// 点击状态背景色(按钮)
+ (UIColor *)xh_buttonSelectedBackgroundColor;

#pragma mark - 文本

/// 一级文本色值 222222
+ (UIColor *)xh_textLevel1;

/// 二级文本色值 333333
+ (UIColor *)xh_textLevel2;

/// 三级文本色值 404040
+ (UIColor *)xh_textLevel3;

/// 四级文本色值 5A5A5A
+ (UIColor *)xh_textLevel4;

/// 五级文本色值 666666
+ (UIColor *)xh_textLevel5;

/// 六级文本色值 919191
+ (UIColor *)xh_textLevel6;

/// 七级文本色值 999999
+ (UIColor *)xh_textLevel7;

/// 八级文本色值 BFBFBF
+ (UIColor *)xh_textLevel8;

/// 九级文本色值 FFFFFF
+ (UIColor *)xh_textLevel9;
    
#pragma mark - 摧毁色
/// 摧毁色 E9264B
+ (UIColor *)xh_destroyColor;

#pragma mark - 分割色

/// 分割色 E0E0E0
+ (UIColor *)xh_separatorColor;

//+ (UIColor *)xh_textMainColor;


/**
 主题颜色
 
 @return color
 */
+ (UIColor *)xlh_themeColor;

/**
 输入框颜色
 
 @return color
 */
+ (UIColor *)xlh_textFieldBoardColor;

/**
 按钮正常状态颜色
 
 @return color
 */
+ (UIColor *)xlh_buttonNormalColor;


/**
 按钮正常状态title颜色
 */
+ (UIColor *)xlh_buttonNormalTitleColor;

/**
 按钮正常状态阴影颜色
 
 @return color
 */
+ (UIColor *)xlh_buttonNormalShadowColor;

/**
 按钮不可点击状态颜色
 
 @return color
 */
+ (UIColor *)xlh_buttonDisableColor;

/** 按钮不可点击title颜色 */
+ (UIColor *)xlh_buttonDisableTitleColor;

/**
 按钮不可点击状态阴影颜色
 */
+ (UIColor *)xlh_buttonDisableShadowColor;

/**
 viewController背景颜色
 
 @return color
 */
+ (UIColor *)xlh_viewBackgroundColor;

@end

NS_ASSUME_NONNULL_END
