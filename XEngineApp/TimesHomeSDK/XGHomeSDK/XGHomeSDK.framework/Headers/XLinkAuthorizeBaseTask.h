//
//  XLinkAuthorizeBaseTask.h
//  XLinkSDK
//
//  Created by AllenKwok on 2018/9/11.
//  Copyright © 2018年 www.xlink.cn. All rights reserved.
//

#import "XLinkTask.h"

@interface XLinkAuthorizeBaseTask : XLinkTask

/**
 授权验证成功

 @param result 授权成功返回的数据
 @param err 授权失败的原因
 */
- (void)authorizeCompleteWithResult:(id)result
                              error:(NSError *)err;

@end
