//
//  XLHMessageViewModel.h
//  Zensun
//
//  Created by judy on 2019/4/8.
//  Copyright © 2019 www.xlink.cn. All rights reserved.
//

#import <Foundation/Foundation.h>

@class XLHMessageHomeModel, XLHMessageModel, XLHNotificationModel, XLHWarningMessageModel, RACCommand, RACSubject;

NS_ASSUME_NONNULL_BEGIN

@interface XLHMessageViewModel : NSObject

//@property (nonatomic, strong) RACCommand *communityCommand;
//@property (nonatomic, strong) RACCommand *comUnreadCommand;
//@property (nonatomic, strong) NSArray <XLHMessageModel *>*communityArray;

@property (nonatomic, strong) RACCommand *notiCommand;
@property (nonatomic, strong) RACCommand *notiUnreadCmmand;

@property (nonatomic, strong) NSArray <XLHNotificationModel *>*notiArray;

@property (nonatomic, strong) RACCommand *alarmCommand;
@property (nonatomic, strong) RACCommand *alarmUnreadCommand;
@property (nonatomic, strong) NSArray <XLHWarningMessageModel *>*alarmArray;

//@property (nonatomic, strong) XLHMessageHomeModel *communityModel;
//@property (nonatomic, assign) int communityUnreadCount;

@property (nonatomic, strong) XLHMessageHomeModel *notiModel;
@property (nonatomic, assign) int notiUnreadCount;

@property (nonatomic, strong) XLHMessageHomeModel *alarmModel;
@property (nonatomic, assign) int alarmUnreadCount;

//@property (nonatomic, assign) int comPage;
//@property (nonatomic, assign) int comLimit;

@property (nonatomic, assign) int notiPage;
@property (nonatomic, assign) int notiLimit;

@property (nonatomic, assign) int alarmPage;
@property (nonatomic, assign) int alarmLimit;

- (void)xlh_refreshMessage;

- (void)xlh_configUnreadMessage;

/**
 社区通知已读，messages为空时，设置全部已读

 @param messages 消息数组
 */
//- (void)xlh_communityMessageUploadRead:(NSArray <XLHMessageModel *>*)messages;

/**
 通知已读，messages为空时，设置全部已读

 @param messages 消息数组
 */
- (void)xlh_notificationMessageUploadRead:(NSArray <XLHNotificationModel *>*)messages;

/**
 告警消息已读，messages为空时，设置全部已读

 @param messages 消息数组
 */
- (void)xlh_alarmMessageUploadRead:(NSArray <XLHWarningMessageModel *>*)messages;

@end

NS_ASSUME_NONNULL_END
