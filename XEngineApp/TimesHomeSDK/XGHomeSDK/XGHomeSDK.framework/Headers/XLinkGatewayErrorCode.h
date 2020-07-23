//
//  XLinkGatewayErrorCode.h
//  XLinkGatewaySDK
//
//  Created by AllenKwok on 2018/4/10.
//  Copyright © 2018年 www.xlink.cn. All rights reserved.
//

#pragma once

/***************************
 * 网关协议错误码
 *****************************/

typedef NS_ENUM(NSInteger, XLinkGatewayErrorCode) {

    // 网关搜索网关/子设备成功
    XLinkGatewayErrorCodeSearchSubDeviceSuccess = 601900,
    // 发起网关配对网关/子设备成功
    XLinkGatewayErrorCodePairingSubDeviceSuccess = 602100,
    // 发起网关配对网关/子设备失败，配对数已达上限
    XLinkGatewayErrorCodePairingSubDeviceFailReachPairingLimit = 602101,
    // 发起网关配对网关/子设备失败，设备不存在
    XLinkGatewayErrorCodePairingSubDeviceFailDeviceNotExist = 602102,
    // 发起网关配对网关/子设备失败，设备不在线
    XLinkGatewayErrorCodePairingSubDeviceFailDeviceOffline = 602103,
    // App通过网关与子设备开启会话成功
    XLinkGatewayErrorCodeSessionHandshakeSubDeviceSuccess = 602300,
    // App通过网关与子设备开启会话，Mac不合法
    XLinkGatewayErrorCodeSessionHandshakeSubDeviceFailMacInvalid = 602301,
    // App通过网关与子设备开启会话失败，设备不在线
    XLinkGatewayErrorCodeSessionHandshakeSubDeviceFailDeviceOffline = 602302,
    // 取消配对网关/子设备成功
    XLinkGatewayErrorCodeUnpairingSubDeviceSuccess = 602500,
    // 取消配对网关/子设备失败，设备不存在
    XLinkGatewayErrorCodeUnpairingSubDeviceFailDeviceNotExist = 602502,
    // 取消配对网关/子设备失败，设备不在线
    XLinkGatewayErrorCodeUnpairingSubDeviceFailDeviceOffline = 602503,
    // 获取网关/子设备属性成功
    XLinkGatewayErrorCodeGetDeviceAttributeSuccess = 602700,
    // 设置网关/子设备属性成功
    XLinkGatewayErrorCodeSetDeviceAttributeSuccess = 602900,
    // 获取网关/子设备状态成功
    XLinkGatewayErrorCodeGetDeviceStatusSuccess = 603100,
    // 获取网关下已配对的子设备列表成功
    XLinkGatewayErrorCodeGetSubDeviceListSuccess = 603400,
    // 通过网关获取子设备Ticket成功
    XLinkGatewayErrorCodeGetSubDeviceTicketSuccess = 603600,
    // 通过网关获取子设备Ticket失败，未知Ticket Type
    XLinkGatewayErrorCodeGetSubDeviceTicketFailUnknownTicketType = 603601,
    // 通过网关获取子设备Ticket失败，未知设备
    XLinkGatewayErrorCodeGetSubDeviceTicketFailUnknownDevice = 603602,
    // 添加分组数据成功
    XLinkGatewayErrorCodeCategoryAddSuccess = 605400,
    // 添加分组数据失败，Parent Id不存在
    XLinkGatewayErrorCodeCategoryAddFailParentIdNotExist = 605401,
    // 添加分组数据失败，分组已满
    XLinkGatewayErrorCodeCategoryAddFailReachCategoryLimit = 605402,
    // 添加分组数据失败，数据不合法
    XLinkGatewayErrorCodeCategoryAddFailDataInvalid = 605403,
    // 添加分组数据失败,父分组Id无效
    XLinkGatewayErrorCodeCategoryAddFailParentIdInvalid = 605404,
    // 添加分组数据失败,分组名称为空或者无效
    XLinkGatewayErrorCodeCategoryAddFailNameNotExistOrInvalid = 605405,
    // 删除分组数据成功
    XLinkGatewayErrorCodeCategoryRemoveSuccess = 605600,
    // 删除分组数据失败， Id不存在
    XLinkGatewayErrorCodeCategoryRemoveFailCategoryIdNotExist = 605601,
    // 删除分组数据失败， 数据不合法或分组ID错误
    XLinkGatewayErrorCodeCategoryRemoveFailCategoryDataInvaild = 605603,
    // 删除分组数据失败， 父分组ID无效
    XLinkGatewayErrorCodeCategoryRemoveFailParentIdInvalid = 605604,
    // 删除分组数据失败， 未知错误
    XLinkGatewayErrorCodeCategoryRemoveFailUnknowError = 605699,
    // 获取分组数据成功
    XLinkGatewayErrorCodeCategoryGetListSuccess = 605800,
    // 获取分组数据失败，参数错误
    XLinkGatewayErrorCodeCategoryGetListFailParamInvalid = 605801,
    // 更新分组数据成功
    XLinkGatewayErrorCodeCategoryUpdateSuccess = 606000,
    // 更新分组数据失败，分组不存在
    XLinkGatewayErrorCodeCategoryUpdateFailCategoryNotExist = 606001,
    // 更新分组数据失败，分组名称错误或名称长度为0
    XLinkGatewayErrorCodeCategoryUpdateFailCategoryNameInvaild = 606005,
    // 添加设备到分组成功
    XLinkGatewayErrorCodeCategoryAddDeviceSuccess = 606400,
    // 添加设备到分组失败
    XLinkGatewayErrorCodeCategoryAddDeviceFail = 606401,
    // 从分组中删除设备成功
    XLinkGatewayErrorCodeCategoryRemoveDeviceSuccess = 606600,
    // 从分组中删除设备失败
    XLinkGatewayErrorCodeCategoryRemoveDeviceFail = 606601,
    // 获取分组的设备列表成功
    XLinkGatewayErrorCodeCategoryGetDeviceListSuccess = 606800,
    // 获取分组的设备列表失败
    XLinkGatewayErrorCodeCategoryGetDeviceListFail = 606801,
    // 设置某分组下某类型设备的数据端点成功
    XLinkGatewayErrorCodeCategorySetDatapointSuccess = 607000,
    // 设置某分组下某类型设备的数据端点失败
    XLinkGatewayErrorCodeCategorySetDatapointFail = 607001,
    // 添加触发器成功
    XLinkGatewayErrorCodeTriggerAddSuccess = 608400,
    // 添加触发器失败
    XLinkGatewayErrorCodeTriggerAddFail = 608401,
    // 删除触发器成功
    XLinkGatewayErrorCodeTriggerRemoveSuccess = 608600,
    // 删除触发器失败,Id无效
    XLinkGatewayErrorCodeTriggerRemoveFailIdInvalid = 608601,
    // 删除触发器失败,未知错误
    XLinkGatewayErrorCodeTriggerRemoveFailUnknowError = 608699,
    // 修改触发器成功
    XLinkGatewayErrorCodeTriggerUpdateSuccess = 608800,
    // 修改触发器失败,Id无效
    XLinkGatewayErrorCodeTriggerUpateFailIdInvalid = 608801,
    // 获取触发器成功
    XLinkGatewayErrorCodeTriggerGetListSuccess = 609000,
    // 获取触发器失败
    XLinkGatewayErrorCodeTriggerGetListFail = 609001,
    // 执行触发器成功
    XLinkGatewayErrorCodeTriggerExcuteSuccess = 609200,
    // 执行触发器失败,Id无效
    XLinkGatewayErrorCodeTriggerExcuteFailIdInvalid = 609201,
    // 添加触发器并自动关联成功
    XLinkGatewayErrorCodeTriggerBatchAddSuccess = 609400,
    // 添加触发器并自动关联失败
    XLinkGatewayErrorCodeTriggerBatchAddFail = 609401,
    // 批量删除触发器成功
    XLinkGatewayErrorCodeTriggerBatchRemoveSuccess = 609600,
    // 批量删除触发器失败
    XLinkGatewayErrorCodeTriggerBatchRemoveFail = 609601,
    // 批量修改触发器成功
    XLinkGatewayErrorCodeTriggerBatchUpdateSuccess = 609800,
    // 批量修改触发器失败
    XLinkGatewayErrorCodeTriggerBatchUpdateFail = 609801,
    // App发送透传数据到网关成功
    XLinkGatewayErrorCodeSendPassthroughSuccess = 610500,
    // App请求网关计算时间误差成功
    XLinkGatewayErrorCodeRequestGatewayTimeSuccess = 610700,
    // App请求网关计算时间误差失败，Flag无效
    XLinkGatewayErrorCodeRequestGatewayTimeFailFlagInvalid = 610701,
    // App请求网关计算时间误差失败，不提供时间同步功能
    XLinkGatewayErrorCodeRequestGatewayTimeFailNotSupport = 610702,
    // App同步时间到网关网关成功
    XLinkGatewayErrorCodeSyncGatewayTimeSuccess = 610900,
    // App同步时间到网关失败，Flag无效
    XLinkGatewayErrorCodeSyncGatewayTimeFailFlagInvalid = 610901,
};
