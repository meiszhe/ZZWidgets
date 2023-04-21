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

#define BRSRetryWaitingTime 1

NS_ASSUME_NONNULL_BEGIN

extern NSString *const BRSCompressHeaderKey;
extern NSString *const BRSQueryMonitorTimeKey;
extern NSString *const BRSQueryConfigMonitorTimeKey;
extern NSString *const BRSQuerySessionKey;

@interface BRSNetworkTool : NSObject

/// 重连次数限制1-10，超过进行过滤 超时时间默认30s
+ (void)sendRequest:(NSURLRequest *)request
         retryCount:(NSUInteger)retryCount
            success:(nullable void (^)(NSData * _Nullable data, NSHTTPURLResponse * _Nullable response))success
            failure:(nullable void (^)(NSError * _Nullable error))failure;

/// 重连次数默认为1，只执行一次，不进行重连 超时时间默认30s
+ (void)sendRequest:(NSURLRequest *)request
            success:(nullable void (^)(NSData * _Nullable data, NSHTTPURLResponse * _Nullable response))success
            failure:(nullable void (^)(NSError * _Nullable error))failure;

/// 上传文件
/// @note waitsForConnectivity
+ (void)uploadRequest:(NSURLRequest *)request
             filePath:(NSString *)filePath
              success:(nullable void (^)(NSData * _Nullable data, NSHTTPURLResponse * _Nullable response))success
              failure:(nullable void (^)(NSError * _Nullable error))failure;

/// 检测是否有网
+ (BOOL)isNetworkReachable;
/// 检测是否连接wifi
+ (BOOL)isNetworkReachableViaWiFi;

+ (NSURLRequest *)defaultRequestWithUrl:(NSURL *)url
                                 querys:(nullable NSDictionary<NSString *,NSString *> *)querys
                                   body:(NSData *)body
                                headers:(nullable NSDictionary<NSString *, NSString *> *)headers
                               needGzip:(BOOL)isNeedZip
                                  brKey:(nullable NSString *)brKey
                        timeoutInterval:(NSTimeInterval)timeoutInterval
                             failHandle:(void(^)(NSString *errorMsg))failHandle;

@end

NS_ASSUME_NONNULL_END


