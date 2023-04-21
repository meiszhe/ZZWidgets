//
//  BRLogAgent.h
//  BonreeLog
//
//  Created by 张喆 on 2023/4/3.
//

#import <Foundation/Foundation.h>
#import <BonreeLog/BRLogConfiguration.h>
#import <BonreeLog/BRLogger.h>

#define BRAGENT_LOG_OFF      0x0         /// 关闭日志输出
#define BRAGENT_LOG_PUBLIC   0x1         /// 输出主流程信息, default
#define BRAGENT_LOG_PBDATA   0x1 << 1    /// 输出上报数据、响应数据
#define BRAGENT_LOG_INFO     0x1 << 2    /// 输出提示信息
#define BRAGENT_LOG_WARN     0x1 << 3    /// 输出警告信息
#define BRAGENT_LOG_ERROR    0x1 << 4    /// 输出错误信息
#define BRAGENT_LOG_TO_FILE  0x1 << 31

NS_ASSUME_NONNULL_BEGIN

@interface BRLogAgent : NSObject

/// 启动LogAgent
+ (void)startWithConfiguration:(BRLogConfiguration *)configuration;

/// 数据是否上报
+ (BOOL)isTrackingData;

/// 生成自定义Logger
+ (BRLogger *)loggerWithBuilder:(BRLoggerBuilder *)builder;

/**
 打开Agent运行日志标志（此接口调试时调用，请勿在生产环境调用。）
 
 例:打开BRAGENT_LOG_PBDATA日志
 [BRSAgent setLogFlag:@(BRAGENT_LOG_PUBLIC|BRAGENT_LOG_PBDATA)];
 
 若需要通过iTunes导出log文件,应在程序的Info.plist文件中添加Application supports iTunes file sharing键，并将键值设置为YES.
 日志文件保存在沙盒目录 Documents/BRSDKLog/DebugLog 下.
 
 关闭日志开关:
 [BRSAgent setLogFlag:@(BRAGENT_LOG_OFF)];
*/
+ (void)setLogFlag:(NSNumber *)flag;

/// 设置Config地址（请在BonreeSDK启动之前设置） 默认为公有云地址，无需设置
/// @param configAddress 私有云Config地址
+ (void)setConfigAddress:(NSString *)configAddress;

@end

NS_ASSUME_NONNULL_END
