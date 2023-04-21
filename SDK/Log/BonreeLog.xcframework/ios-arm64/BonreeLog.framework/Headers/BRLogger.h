//
//  BRLogger.h
//  BonreeLog
//
//  Created by 张喆 on 2023/4/3.
//

#import <Foundation/Foundation.h>
#import <BonreeLog/BRLoggerBuilder.h>

NS_ASSUME_NONNULL_BEGIN

@interface BRLogger : NSObject

/// 生成自定义Logger
+ (BRLogger *)loggerWithBuilder:(BRLoggerBuilder *)builder;
- (BRLogger *)initWithBuilder:(BRLoggerBuilder *)builder;

/// 日志输出
/// @param message 日志内容
- (void)debug:(nullable NSString *)message;
- (void)info:(nullable NSString *)message;
- (void)warn:(nullable NSString *)message;
- (void)error:(nullable NSString *)message;
- (void)emergency:(nullable NSString *)message;

/// 日志输出[可选错误]
/// @param message 日志内容
/// @param error 错误信息
- (void)debug:(nullable NSString *)message error:(nullable NSError *)error;
- (void)info:(nullable NSString *)message error:(nullable NSError *)error;
- (void)warn:(nullable NSString *)message error:(nullable NSError *)error;
- (void)error:(nullable NSString *)message error:(nullable NSError *)error;
- (void)emergency:(nullable NSString *)message error:(nullable NSError *)error;

/// 添加属性信息
/// @param key 属性键
/// @param value 属性值[类型约束:字符串，数字，布尔]
- (void)addAttributeForKey:(NSString *)key value:(id)value;

/// 删除属性键
/// @param key 属性键
- (void)removeAttributeForKey:(NSString *)key;

/// 日志输出[多选项]
/// @param level 日志级别
/// @param error 错误信息
/// @param attributes 属性信息
- (void)logWithLevel:(BRLogLevel)level
             message:(nullable NSString *)message
               error:(nullable NSError *)error
          attributes:(nullable NSDictionary<NSString *, id> *)attributes;

@end

NS_ASSUME_NONNULL_END
