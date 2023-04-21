//
//  BRLoggerBuilder.h
//  BonreeLog
//
//  Created by 张喆 on 2023/4/3.
//

#import <Foundation/Foundation.h>
#import <BonreeLog/BRLogAgentType.h>

NS_ASSUME_NONNULL_BEGIN

@interface BRLoggerBuilder : NSObject

/// 日志阈值
/// 等于或严重于levelThreshold级别的日志会进行上报和存储
@property (nonatomic, assign) BRLogLevel levelThreshold;

/// Logger名称
@property (nonatomic, copy, nullable) NSString *loggerName;

/// 是否开启控制台输出
@property (nonatomic, assign) BOOL printConsole;

/// 日志前缀，该Logger生成的日志前缀统一
@property (nonatomic, copy, nullable) NSString *prefix;

@end

NS_ASSUME_NONNULL_END
