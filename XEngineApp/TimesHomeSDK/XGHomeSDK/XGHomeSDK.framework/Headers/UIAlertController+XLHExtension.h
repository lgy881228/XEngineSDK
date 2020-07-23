//
//  UIAlertController+showAlertOnMainThread.h
//  Socket Protocol
//
//  Created by 黄 庆超 on 2016/10/31.
//  Copyright © 2016年 com.hqc. All rights reserved.
//

@import UIKit;

typedef void(^AlertBlock)(UIAlertController * _Nonnull alertController);

@interface UIAlertController (XLHExtension)

+(UIAlertController * _Nonnull)xlh_showHintAlertOnMainThreadWithMsg:(NSString *_Nullable)msg;

+(UIAlertController * _Nonnull)xlh_showHintAlertOnMainThreadWithTitle:(NSString *_Nullable)title withMsg:(NSString *_Nullable)msg completion:(AlertBlock _Nullable )block;

+ (UIAlertController * _Nonnull)xlh_showHintAlertOnMainThreadWithTitle:(NSString *_Nullable)title withMsg:(NSString *_Nullable)msg withConfirmBtnTitle:(NSString *_Nullable)confirmBtnTitle withConfirmBtnAction:(AlertBlock _Nullable )confirmBtnAction;

+ (UIAlertController * _Nonnull)xlh_showHintAlertOnMainThreadWithTitle:(NSString *_Nullable)title withMsg:(NSString *_Nullable)msg withConfirmBtnTitle:(NSString *_Nullable)confirmBtnTitle withConfirmBtnAction:(AlertBlock _Nullable )confirmBtnAction withOtherBtnTitle:(NSString *_Nullable)otherBtnTitle withOtherBtnAction:(AlertBlock _Nullable )otherBtnAction;

+ (UIAlertController * _Nonnull)xlh_showHintAlertOnMainThreadWithTitle:(NSString *_Nullable)title withMsg:(NSString *_Nullable)msg withTextFieldNum:(NSUInteger)textFieldNum withConfirmBtnTitle:(NSString *_Nullable)confirmBtnTitle withConfirmBtnAction:(AlertBlock _Nullable )confirmBtnAction withCancelBtnTitle:(NSString *_Nullable)cancelBtnTitle withCancelBtnAction:(AlertBlock _Nullable )cancelBtnAction;

@end
