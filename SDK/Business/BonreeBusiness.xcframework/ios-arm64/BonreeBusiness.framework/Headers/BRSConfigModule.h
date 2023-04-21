/*
 *
 * Copyright (c) 2015-2020  Bonree Company
 * 北京博睿宏远科技发展有限公司  版权所有 2015-2020
 *
 * PROPRIETARY RIGHTS of Bonree Company are involved in the
 * subject matter of this material.  All manufacturing, reproduction, use,
 * and sales rights pertaining to this subject matter are governed by the
 * license agreement.  The recipient of this software implicitly accepts
 * the terms of the license.
 * 本软件文档资料是博睿公司的资产,任何人士阅读和使用本资料必须获得
 * 相应的书面授权,承担保密责任和接受相应的法律约束.
 *
 */

#import <Foundation/Foundation.h>
#import <BonreeBusiness/BRSConfigProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface BRSConfigModule : NSObject

/// 注册Config消息接收者
/// @param receiver 消息接收者
/// @param data 控制数据
+ (void)registerReceiver:(id<BRSConfigReceiverProtocol>)receiver data:(id<BRSConfigControlDataProtocol>)data;

/// 开始Config远端请求
/// @param moduleName 自身模块名称
+ (void)startRequestRemoteDataModule:(NSString *)moduleName;

/// 开始Config本地请求
/// @param moduleName 自身模块名称
+ (void)startLoadLocalDataModule:(NSString *)moduleName;

/// 停止Config
/// @param moduleName 自身模块名称
+ (void)stopConfig:(NSString *)moduleName;

/// 挂起Config
/// @param moduleName 自身模块名称
+ (void)suspendConfig:(NSString *)moduleName;

/// 恢复Config
/// @param moduleName 自身模块名称
+ (void)resumeConfig:(NSString *)moduleName;

/// 发送共享数据
/// @param crossData 共享数据
+ (void)postCrossData:(id<BRSConfigCrossData>)crossData;

@end

NS_ASSUME_NONNULL_END
