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

typedef void(^BRSConfigResponseHandle)(BOOL isSuccess, NSData *data);

/// 模块共享数据
@protocol BRSConfigCrossData <NSObject, NSCopying>

/// 消息来源
@property (nonatomic, copy) NSString *fromModule;

/// 会话标识
@property (nonatomic, copy) NSString *session;

/// 额外信息
@property (nonatomic, copy) NSDictionary *extraInfo;

@end

/// Config模块控制数据
@protocol BRSConfigControlDataProtocol <NSObject>

/// 自身模块名称
@property (nonatomic, copy) NSString *moduleName;
/// 重试次数，默认5次，设置为0则不重试
@property (nonatomic, assign) NSInteger retryCount;
/// Config本地版本号[不传不缓存到本地]
@property (nonatomic, copy) NSString *localVersion;
/// Config本地版本KEY，UserDefault使用[不传不缓存到本地]
@property (nonatomic, copy) NSString *localVersionKey;
/// Config本地路径[不传不缓存到本地]
@property (nonatomic, copy) NSString *localPath;
/// Config本地文件名称[不传不缓存到本地]
@property (nonatomic, copy) NSString *localFileName;

@end

/// Config模块消息接收者
@protocol BRSConfigReceiverProtocol <NSObject>

/// 获取Config请求对象
- (NSURLRequest *)getConfigRequest;

/// Config收到响应
/// @param response 响应原数据
/// @param error 错误信息
/// @param handle 回调给Config的消息
- (void)configDidReceiveResponse:(NSData *)response
                           error:(NSError *)error
                          handle:(BRSConfigResponseHandle)handle;

/// Config已加载本地数据
- (void)configDidLoadLocalResponse:(NSData *)response;

@optional
/// 接收共享数据
- (void)didReceiverCrossData:(id<BRSConfigCrossData>)crossData;

@end
