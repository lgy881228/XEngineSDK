//
//  XLinkErrorCode.h
//  XLinkSDK
//
//  Created by AllenKwok on 2017/4/6.
//  Copyright © 2017年 www.xlink.cn. All rights reserved.
//

#pragma once

typedef NS_ENUM(NSInteger, XLinkErrorCode) {
    //没有错误
    XLinkErrorCodeNoError = 0,
    //本地配对握手成功
    XLinkErrorCodePairingHandshakeLocalSuccess = 100400,
    //本地配对握手Dh参数不合法
    XLinkErrorCodePairingHandshakeLocalFailDhParamsInvalid = 100401,
    //本地Ticket验证失败(为空、不匹配)
    XLinkErrorCodePairingHandshakeLocalFailTicketVerify = 100402,
    //本地配对握手Public Key不合法
    XLinkErrorCodePairingHandshakeLocalFailPublicKeyInvalid = 100403,
    //本地Pincode验证失败(为空、不匹配)
    XLinkErrorCodePairingHandshakeLocalFailPinVerify = 100404,
    //设备不在配对状态
    XLinkErrorCodePairingHandshakeLocalFailDeviceNotReady = 100405,
    //本地配对成功
    XLinkErrorCodePairingLocalSuccess = 100600,
    //本地配对达到上限
    XLinkErrorCodePairingLocalFailReachPairingLimit = 100601,
    //本地会话握手成功
    XLinkErrorCodeSessionHandshakeLocalSuccess = 100900,
    //本地会话未知Pairing Id
    XLinkErrorCodeSessionHandshakeLocalFailUnknownPairingId = 100901,
    //本地会话验证失败
    XLinkErrorCodeSessionHandshakeLocalFailVerify = 100902,
    //本地会话Dh参数不合法
    XLinkErrorCodeSessionHandshakeLocalFailDhParamsInvalid = 100903,
    //本地Public Key不合法
    XLinkErrorCodeSessionHandshakeLocalFailPublicKeyInvalid = 100904,
    //本地设置数据端点成功
    XLinkErrorCodeSetDataPointLocalSuccess = 101300,
    //本地设置数据端点失败
    XLinkErrorCodeSetDataPointLocalFail = 101301,
    //未授予本地设置端点权限
    XLinkErrorCodeSetDataPointLocalFailUnauthorised = 101302,
    //设备问题
    XLinkErrorCodeSetDataPointLocalFailDeviceFault = 101303,
    //数据端点类型错误
    XLinkErrorCodeSetDataPointLocalFailTypeError = 101304,
    //获取数据端点成功
    XLinkErrorCodeGetDataPointLocalSuccess = 101500,
    //Flag参数不支持
    XLinkErrorCodeGetDataPointLocalFailFlagNotSupported = 101501,
    //未授予获取权限
    XLinkErrorCodeGetDataPointLocalFailUnauthorised = 101502,
    //获取Ticket成功
    XLinkErrorCodeGetTicketLocalSuccess = 101700,
    //未知Ticket Type
    XLinkErrorCodeGetTicketLocalFailUnknownType = 101701,
    //获取Probe成功
    XLinkErrorCodeProbeLocalSuccess = 110300,
    //Flag参数不支持
    XLinkErrorCodeProbeLocalFailFlagNotSupported = 110301,
    //未授予获取权限
    XLinkErrorCodeProbeLocalFailUnauthorised = 110302,
    //云端设置数据端点成功
    XLinkErrorCodeSetDataPointCloudSuccess = 200800,
    //云端设置数据端点失败
    XLinkErrorCodeSetDataPointCloudFail = 200801,
    //未授予设置权限
    XLinkErrorCodeSetDataPointCloudFailUnauthorised = 200802,
    //云端获取数据端点成功
    XLinkErrorCodeGetDataPointCloudSuccess = 201000,
    //云端获取数据端点失败,服务不可用
    XLinkErrorCodeGetDataPointCloudFail = 201001,
    //云端订阅设备成功
    XLinkErrorCodeSubscribeDeviceSuccess = 201601,
    //云端订阅设备失败，设备信息有误
    XLinkErrorCodeSubscribeDeviceFailDeviceInfoInvaild = 201602,
    //云端订阅设备失败，Ticket校验失败
    XLinkErrorCodeSubscribeDeviceFailTicketInvaild = 201603,
    //云端订阅设备失败, 服务器出错
    XLinkErrorCodeSubscribeDeviceFail = 201604,
    //云端订阅设备失败，设备订阅模式限制订阅失败
    XLinkErrorCodeSubscribeDeviceFailDeviceModeLimited = 201605,
    //云端获取Ticket成功
    XLinkErrorCodeGetTicketCloudSuccess = 202200,
    //云端请求订阅码成功
    XLinkErrorCodeRequestSubCodeCloudSuccess = 203901,
    //云端请求订阅码失败，提供的Mac、ProductId设备信息不存在
    XLinkErrorCodeRequestSubCodeCloudFailDeviceInfoInvaild = 203902,
    //云端订阅码订阅成功
    XLinkErrorCodeSubscribeWithSubCodeCloudSuccess = 204101,
    //云端订阅码订阅失败，云端执行订阅时发生错误
    XLinkErrorCodeSubscribeWithSubCodeCloudFailSeverSubscribeFail = 204151,
    //云端订阅码订阅失败，因产品配置限制导致订阅失败
    XLinkErrorCodeSubscribeWithSubCodeCloudFailDeviceModeLimited = 204152,
    //任务超时
    XLinkErrorCodeTaskTimeout = 300101,
    //任务取消
    XLinkErrorCodeTaskCanceled = 300102,
    //任务依赖等待超时(如云端任务需要云端连接成功才能操作,等待期间云端未能连接成功导致超时)
    XLinkErrorCodeTaskDependenceTimeout = 300103,
    //未知错误
    XLinkErrorCodeUnknown = 400101,
    //未知的Api错误,或者解析Api错误码时出错
    XLinkErrorCodeApiUnknown = 400102,
    //Socket 连接超时
    XLinkErrorCodeSocketTimeout = 400103,
    //SDK还没启动
    XLinkErrorCodeSDKNotStarted = 400104,
    //Client操作时参数不合法,比如无法获取到Clientid拼接Topic进行通讯
    XLinkErrorCodeMqttFailClientParamsNotExist = 400201,
    //Client不存在,无法进行相关通讯操作
    XLinkErrorCodeMqttFailClientNotExist = 400202,
    //Mqtt Client未连接成功
    XLinkErrorCodeMqttFailClientDisconnected = 400203,
    //Client内部出错,属于Client的未知错误
    XLinkErrorCodeMqttFailClientInnerError = 400204,
    //初始化本地Client失败
    XLinkErrorCodeMqttFailLocalClientInit = 400205,
    //初始化云端Client失败
    XLinkErrorCodeMqttFailCloudClientInit = 400206,
    //本地发布Topic失败
    XLinkErrorCodeMqttFailLocalPublish = 400207,
    //云端发布Topic失败
    XLinkErrorCodeMqttFailCloudPublish = 400208,
    //协议版本不支持
    XLinkErrorCodeProtocolVersionNotSupported = 400301,
    //会话解密失败
    XLinkErrorCodeProtocolFailEncryptSession = 400302,
    //会话加密失败
    XLinkErrorCodeProtocolFailDecryptSession = 400303,
    //配对解密失败
    XLinkErrorCodeProtocolFailEncryptPairing = 400304,
    //配对加密失败
    XLinkErrorCodeProtocolFailDecryptPairing = 400305,
    //配对握手加密失败
    XLinkErrorCodeProtocolFailDecryptPairingHandshake = 400306,
    //配对握手解密失败
    XLinkErrorCodeProtocolFailEncryptPairingHandshake = 400307,
    //Pincode加密失败
    XLinkErrorCodeProtocolFailEncryptPinCode = 400308,
    //Pincode解密失败
    XLinkErrorCodeProtocolFailDecryptPinCode = 400309,
    //配对握手会话信息不存在
    XLinkErrorCodeProtocolFailPairingHandshakeNotExit = 400310,
    //配对信息不存在
    XLinkErrorCodeProtocolFailPairingNotExist = 400311,
    //本地会话信息不存在
    XLinkErrorCodeProtocolFailSessionNotExist = 400312,
    //云端连接失败
    XLinkErrorCodeProtocolFailCloudCmConnected = 400313,
    //断开云端连接失败
    XLinkErrorCodeProtocolFailCloudCmDisconnected = 400314,
    //打包数据包出错
    XLinkErrorCodeProtocolFailPacketData = 400315,
    //解析数据包出错
    XLinkErrorCodeProtocolFailParseData = 400316,
    //设备本地未连接
    XLinkErrorCodeDeviceFailLocalNotConnected = 400401,
    //设备云端未连接
    XLinkErrorCodeDeviceFailCloudNotConnected = 400402,
    //设备本地关闭Session失败
    XLinkErrorCodeDeviceFailLocalCloseSession = 400403,
    //设备云端关闭Session失败
    XLinkErrorCodeDeviceFailCloudCloseSession = 400404,
    //维护的设备不存在
    XLinkErrorCodeDeviceFailDeviceNotExist = 400405,
    //设备ID不能为0
    XLinkErrorCodeDeviceIdIsZero = 400406,
    //用户断开云端连接
    XLinkErrorCodeUserCloudCmDisconnected = 400501,
    //用户断开本地Client连接
    XLinkErrorCodeUserLocalDisconnected = 400502,
    
    //参数不正确的
    //参数不合法(参数存在但是未获取需要的信息,如设备对象对象存在但获取不到Mac)
    XLinkErrorCodeParamsInvalid = 400601,
    //需要的参数不存在(参数不存在,Null或者Nil)
    XLinkErrorCodeParamsNotExist = 400602,
    //InviteCode不存在
    XLinkErrorCodeParamsInviteCodeNotExist = 400603,
    //配置项不正确的
    //没有配置企业id
    XLinkErrorCodeConfigWithoutCropId = 400701,
    
    //进入产测成功
    XLinkErrorCodeFactoryStartLocalSuccess = 500100,
    //进入产测失败,设备不在线
    XLinkErrorCodeFactoryStartLocalFailDeviceOffline = 500201,
    //进入产测失败,未使能产测
    XLinkErrorCodeFactoryStartLocalFailDeviceDisabled = 500202,
    //结束产测成功
    XLinkErrorCodeFacotryFinishLocalSuccess = 500400,
    //结束产测失败
    XLinkErrorCodeFacotryFinishLocalFail = 500401,
    //获取Rssi成功
    XLinkErrorCodeFactoryRssiLocalSuccess = 500600,
    //获取Rssi失败
    XLinkErrorCodeFactoryRssiLocalFail = 500601,
    //自定义产测成功
    XLinkErrorCodeFactoryCustomLocalSuccess = 500800,
    
    
    ////////////////////////////  Api 接口 //////////////////////////////////
    
    //网络Io错误
    XLinkErrorCodeApiParamNetioError = 1001001,
    //请求数据字段验证不通过
    XLinkErrorCodeApiParamValidError = 4001001,
    //请求数据必须字段不可为空
    XLinkErrorCodeApiParamMustNotNull = 4001002,
    //手机验证码不存在
    XLinkErrorCodeApiPhoneVerifycodeNotExists = 4001003,
    //手机验证码错误
    XLinkErrorCodeApiPhoneVerifycodeError = 4001004,
    //注册的手机号已存在
    XLinkErrorCodeApiRegisterPhoneExists = 4001005,
    //第三方要绑定手机号已存在
    XLinkErrorCodeApiRegisterThirdpartyPhoneExists = 4001094,
    //第三方要绑定邮箱已存在
    XLinkErrorCodeApiRegisterThirdpartyEmailExists = 4001096,
    //注册的邮箱已存在
    XLinkErrorCodeApiRegisterEmailExists = 4001006,
    //密码错误
    XLinkErrorCodeApiAccountPasswordError = 4001007,
    //密码重试次数过多
    XLinkErrorCodeApiAccountPasswordRetryLimit = 4001061,
    //帐号不合法
    XLinkErrorCodeApiAccountVaildError = 4001008,
    //企业成员状态不合法
    XLinkErrorCodeApiMemberStatusError = 4001009,
    //刷新Token不合法
    XLinkErrorCodeApiRefreshTokenError = 4001010,
    //未知成员角色类型
    XLinkErrorCodeApiMemberRoleTypeUnkown = 4001011,
    //只有管理员才能邀请
    XLinkErrorCodeApiMemberInviteNotAdmin = 4001012,
    //不可修改其他成员信息
    XLinkErrorCodeApiCanNotModifyOtherMemberInfo = 4001013,
    //不能删除本人
    XLinkErrorCodeApiCanNotDeleteYourself = 4001014,
    //未知的产品连接类型
    XLinkErrorCodeApiProductLinkTypeUnkown = 4001015,
    //已发布的产品不可删除
    XLinkErrorCodeApiCanNotDeleteReleaseProduct = 4001016,
    //固件版本已存在
    XLinkErrorCodeApiFirmwareVersionExists = 4001017,
    //数据端点未知数据类型
    XLinkErrorCodeApiDataPointTypeUnkown = 4001018,
    //数据端点索引已存在
    XLinkErrorCodeApiDataPointIndexExists = 4001019,
    //已发布的数据端点不可删除
    XLinkErrorCodeApiCantNotDeleteReleasedDataPoint = 4001020,
    //该产品下设备Mac地址已存在
    XLinkErrorCodeApiDeviceMacAddressExists = 4001021,
    //不能删除已激活的设备
    XLinkErrorCodeApiCanNotDeleteActivatedDevice = 4001022,
    //扩展属性Key为预留字段
    XLinkErrorCodeApiPropertyKeyProtect = 4001023,
    //设备扩展属性超过上限
    XLinkErrorCodeApiPropertyLimit = 4001024,
    //新增已存在的扩展属性
    XLinkErrorCodeApiPropertyAddExists = 4001025,
    //更新不存在的扩展属性
    XLinkErrorCodeApiPropertyUpdateNotExists = 4001026,
    //属性字段名不合法
    XLinkErrorCodeApiPropertyKeyError = 4001027,
    //邮件验证码不存在
    XLinkErrorCodeApiEmailVerifycodeNotExists = 4001028,
    //邮件验证码错误
    XLinkErrorCodeApiEmailVerifycodeError = 4001029,
    //用户状态不合法
    XLinkErrorCodeApiUserStatusError = 4001030,
    //用户手机尚未认证
    XLinkErrorCodeApiUserPhoneNotVaild = 4001031,
    //用户邮箱尚未认证
    XLinkErrorCodeApiUserEmailNotVaild = 4001032,
    //用户已经订阅设备
    XLinkErrorCodeApiUserHasSubscribeDevice = 4001033,
    //用户没有订阅该设备
    XLinkErrorCodeApiUserHaveNoSubscribeDevice = 4001034,
    //自动升级任务名称已存在
    XLinkErrorCodeApiUpgradeTaskNameExists = 4001035,
    //升级任务状态未知
    XLinkErrorCodeApiUpgradeTaskStatusUnkown = 4001036,
    //已有相同的起始版本升级任务
    XLinkErrorCodeApiUpgradeTaskHaveStartingVersion = 4001037,
    //设备激活失败
    XLinkErrorCodeApiDeviceActiveFail = 4001038,
    //设备认证失败
    XLinkErrorCodeApiDeviceAuthFail = 4001039,
    //订阅设备认证码错误
    XLinkErrorCodeApiSubscribeAuthorizeCodeError = 4001041,
    //授权名称已存在
    XLinkErrorCodeApiEmpowerNameExists = 4001042,
    //该告警规则名称已存在
    XLinkErrorCodeApiAlarmRuleNameExists = 4001043,
    //数据变名称已存在
    XLinkErrorCodeApiDataTableNameExists = 4001045,
    //产品固件文件超过大小限制
    XLinkErrorCodeApiProductFirmwareFileSizeLimit = 4001046,
    //Apn密钥文件超过大小限制
    XLinkErrorCodeApiAppApnLicenseFileSizeLimit = 4001047,
    //App的Apn功能未启用
    XLinkErrorCodeApiAppApnIsNotEnable = 4001048,
    //产品未允许用户注册设备
    XLinkErrorCodeApiProductCanNotRegisterDevice = 4001049,
    //不是设备的管理员
    XLinkErrorCodeApiNotDeviceAdmin = 4001076,
    //禁止访问
    XLinkErrorCodeApiInvalidAccess = 4031001,
    //禁止访问，需要Access-Token
    XLinkErrorCodeApiNeedAccessToken = 4031002,
    //无效的Access-Token
    XLinkErrorCodeApiAccessTokenInvalid = 4031003,
    //Access-Token过期
    XLinkErrorCodeApiAccessTokenExpired = 4031021,
    //Access-Token需要重新刷新
    XLinkErrorCodeApiAccessTokenRefresh = 4031022,
    //需要企业的调用权限
    XLinkErrorCodeApiNeedCorpApi = 4031004,
    //需要企业管理员权限
    XLinkErrorCodeApiNeedCorpAdminMember = 4031005,
    //需要数据操作权限
    XLinkErrorCodeApiNeedDataPermission = 4031006,
    //禁止访问私有数据
    XLinkErrorCodeApiInvalidAccessPrivateData = 4031007,
    //分享已经被取消
    XLinkErrorCodeApiShareCanceled = 4031008,
    //分享已经接受
    XLinkErrorCodeApiShareAccepted = 4031009,
    //分享无效
    XLinkErrorCodeApiShareInvalid = 4031012,
    //Url找不到
    XLinkErrorCodeApiUrlNotFound = 4041001,
    //Share找不到
    XLinkErrorCodeApiShareNotPending = 4001216,
    //Share找不到2
    XLinkErrorCodeApiShareNotPending2 = 4001218,
    //企业成员帐号不存在
    XLinkErrorCodeApiMemberAccountNoExists = 4041002,
    //企业成员不存在
    XLinkErrorCodeApiMemberNotExists = 4041003,
    //激活的成员邮箱不存在
    XLinkErrorCodeApiMemberInviteEmailNotExists = 4041004,
    //产品信息不存在
    XLinkErrorCodeApiProductNotExists = 4041005,
    //产品固件不存在
    XLinkErrorCodeApiFirmwareNotExists = 4041006,
    //数据端点不存在
    XLinkErrorCodeApiDataPointNotExists = 4041007,
    //设备不存在
    XLinkErrorCodeApiDeviceNotExists = 4041008,
    //设备扩展属性不存在
    XLinkErrorCodeApiDevicePropertyNotExists = 4041009,
    //企业不存在
    XLinkErrorCodeApiCorpNotExists = 4041010,
    //用户不存在
    XLinkErrorCodeApiUserNotExists = 4041011,
    //用户扩展属性不存在
    XLinkErrorCodeApiUserPropertyNotExists = 4041012,
    //升级任务不存在
    XLinkErrorCodeApiUpgradeTaskNotExists = 4041013,
    //第三方身份授权不存在
    XLinkErrorCodeApiEmpowerNotExists = 4041014,
    //告警规则不存在
    XLinkErrorCodeApiAlarmRuleNotExists = 4041015,
    //数据表不存在
    XLinkErrorCodeApiDataTableNotExists = 4041016,
    //数据不存在
    XLinkErrorCodeApiDataNotExists = 4041017,
    //分享资源不存在
    XLinkErrorCodeApiShareNotExists = 4041018,
    //企业邮箱不存在
    XLinkErrorCodeApiCorpEmailNotExists = 4041019,
    //App不存在
    XLinkErrorCodeApiAppNotExists = 4041020,
    //第三方授权错误=其它途径)
    XLinkErrorCodeApiThirdPartyOpenIdExistOther = 4001125,
    //Qq授权错误
    XLinkErrorCodeApiThirdPartyOpenIdExistQq = 4001126,
    //微信授权错误
    XLinkErrorCodeApiThirdPartyOpenIdExistWx = 4001127,
    //微博授权错误
    XLinkErrorCodeApiThirdPartyOpenIdExistWb = 4001128,
    //服务端发生异常
    XLinkErrorCodeApiServiceException = 5031001,
    
    //发送订阅码成功
    XLinkErrorCodeSendSubcodeLocalSuccess = 600601,
    //设备拒绝被订阅
    XLinkErrorCodeSendSubkeyLocalFailRefuse = 600602,
    //设备解密出错，数据校验失败
    XLinkErrorCodeSendSubkeyLocalFailDecrypt = 600603,
    //设备配对次数达到上限
    XLinkErrorCodeSendSubcodeFailReachPairingLimit = 600604,
    //设备上报订阅码成功
    XLinkErrorCodeSubcodeStateLocalSuccess = 600700,
    //设备上报订阅码云端无法识别
    XLinkErrorCodeSubcodeStateLocalSubcodeInvaild = 600701,
    //设备上报订阅码已过期，过期仅在一定时间内有效，逾期无法识别
    XLinkErrorCodeSubcodeStateLocalSubcodeExpired = 600702,
    //设备上报订阅码中的APP ID与提交的APP ID无法匹配
    XLinkErrorCodeSubcodeStateLocalAppidNotMatch = 600703,
};

/* XLinkErrorCode_h */

