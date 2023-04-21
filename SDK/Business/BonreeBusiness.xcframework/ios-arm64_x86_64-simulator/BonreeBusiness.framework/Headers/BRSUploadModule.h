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
#import "BRSUploadProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface BRSUploadModule : NSObject

/// 开启Upload
/// @param data 控制Upload的数据
/// @param receiver 消息接收者
+ (void)startUploadWithData:(id<BRSUploadControlDataProtocol>)data receiver:(id<BRSUploadReceiverProtocol>)receiver;

/// 立即触发Upload
/// @param moduleName 模块名称
/// @param inUploadThread 是否切换到Upload线程
/// @param option 生成请求选项
+ (void)uploadImmediatelyModule:(NSString *)moduleName inUploadThread:(BOOL)inUploadThread option:(BRSUploadOption)option;

/// 修改Upload间隔
/// @param moduleName 模块名称
/// @param interval 间隔
/// @param isRecover 恢复默认间隔
+ (void)modifyUploadModule:(NSString *)moduleName interval:(NSInteger)interval recover:(BOOL)isRecover;

/// 停止Upload
/// @param moduleName 模块名称
+ (void)stopUpload:(NSString *)moduleName;

/// 挂起Upload
/// @param moduleName 模块名称
+ (void)suspend:(NSString *)moduleName;

/// 恢复Upload
/// @param moduleName 模块名称
+ (void)resume:(NSString *)moduleName;

@end

NS_ASSUME_NONNULL_END
