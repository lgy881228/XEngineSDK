//
//  Header.h
//  Park
//
//  Created by judy on 2018/12/10.
//  Copyright © 2018 judy. All rights reserved.
//

#ifndef Header_h
#define Header_h

static inline BOOL IsIphone5() {
    return [UIScreen mainScreen].bounds.size.width == 320 && [UIScreen mainScreen].bounds.size.height == 568;
}

static inline BOOL IsIphone6() {
    return [UIScreen mainScreen].bounds.size.width == 375 && [UIScreen mainScreen].bounds.size.height == 667;
}

static inline BOOL IsIphone6Plus() {
    return [UIScreen mainScreen].bounds.size.width == 414 && [UIScreen mainScreen].bounds.size.height == 736;
}

static inline BOOL IsIphoneX() {
    return [UIScreen mainScreen].bounds.size.width == 375 && [UIScreen mainScreen].bounds.size.height == 812;
}

static inline BOOL IsIphoneXMax() {
    return [UIScreen mainScreen].bounds.size.width == 414 && [UIScreen mainScreen].bounds.size.height == 896;
}

#endif /* Header_h */
