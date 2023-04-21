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

/*
 1.用来写日志到沙盒中
 2.用开关标志 来 针对性的打印某类需要打印的log日志
 */

#import <Foundation/Foundation.h>

#ifndef BRSLOG_H
#define BRSLOG_H

/// 模块划分
typedef NS_OPTIONS(NSInteger, BRSAgentLogModule)
{
    BRSAgentLogModuleNone               = 0x0,           /// 未知模块
    BRSAgentLogModuleRUM                = 0x1,           /// RUM模块
    BRSAgentLogModuleLogRecord          = 0x1 << 1       /// 日志分析模块
};

/// 日志级别
typedef NS_OPTIONS(NSInteger, BRSLogFlag)
{
    
    BRSLogFlagNone          = 0x0,         /// 关闭日志输出
    BRSLogFlagPublic        =  0x1,        /// 显示主流程的相关信息，对sdk启动或使用有重大影响的配置或者参数使用, default
    
    BRSLogFlagData          =  0x1 << 1,   /// 展示上报数据、响应数据
    
    BRSLogFlagInfo          =  0x1 << 2,   /// 提示信息
    BRSLogFlagWarn          =  0x1 << 3,   /// 警告信息
    BRSLogFlagError         =  0x1 << 4,   /// 错误信息
    
    BRSLogFlagWeb           =  0x1 << 5,
    BRSLogFlagNet           =  0x1 << 6,
    BRSLogFlagLag           =  0x1 << 7,
    BRSLogFlagCrash         =  0x1 << 8,
    BRSLogFlagView          =  0x1 << 9,
    BRSLogFlagCustom        =  0x1 << 10,
    BRSLogFlagUpload        =  0x1 << 12,
    BRSLogFlagConfig        =  0x1 << 13,
    BRSLogFlagAction        =  0x1 << 14,
    BRSLogFlagLaunch        =  0x1 << 15,
    BRSLogStateChange       =  0x1 << 16,
    BRSLogDevice            =  0x1 << 17,
    BRSLogFlagLogback       =  0x1 << 18,
    BRSLogFlagSpeedTest     =  0x1 << 19,
    BRSLogFlagReactNative   =  0x1 << 20,
    BRSLogFlagRouteChange   =  0x1 << 21,
    BRSLogFlagWatchdog      =  0x1 << 22,
    BRSLogOnlineTracking    =  0x1 << 23,
    BRSLogFlagTrace         =  0x1 << 24,
    BRSLogFlagBattery       =  0x1 << 25,
    BRSLogFlagLogRecord     =  0x1 << 26,

    BRSLogFlagAll           =  0x7FFFFFF,
    
    BRSLogFlagWriteFile     =  0x1 << 31,
};

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus
    
    /**
     位运算
     
     左移运算符 <<
     
     公式 x << 3 就是把x的各二进位左移3位
     1<<1  实际就是  0001 << 1  = 0010   转成十进制后就是  2
     1<<4  实际就是  0001 << 4  = 10000  转成十进制后就是  16
     与&运算
     0&0=0,0&1=0,1&0=0,1&1=1
     
     非~运算即取反运算，
     在二进制中1变0,0变1
     110101进行非运算后为
     001010即1010
     
     或|运算
     A（或）|B任意开则开
     0&0=0,0&1=1,1&0=1,1&1=1
     
     异或^运算
     同为真，异为假
     0&0=1,0&1=0,1&0=0,1&1=1
     */
    
    //日志开关标志
    
extern BRSLogFlag brsLogFlag;
extern BRSLogFlag brsLogModuleFlag;

//NSString *brs_currentTime();
//NSString *brs_emoji(NSInteger flag);
void brs_outputLog(BRSAgentLogModule moduleType, BRSLogFlag options,NSString *fmt);
BOOL brs_shouldLog(BRSAgentLogModule moduleType, BRSLogFlag options);

//回调SDK错误信息
void brs_errorMessegeLog(const char *file, const char *method, int line, NSString *fmtStr);

/// Common
#define BRSLOG(module, flag, fmt, ...) \
    do { \
        if (brs_shouldLog(module, flag)) { \
            brs_outputLog(module, flag, [NSString stringWithFormat:fmt, ##__VA_ARGS__]);\
        } \
    } while (0)

#define BRSLOGERROR(module, flag, fmt, ...) BRSLOG(module, flag | BRSLogFlagError, fmt, ##__VA_ARGS__)
#define BRSLOGWARN(module, flag, fmt, ...) BRSLOG(module, flag | BRSLogFlagWarn, fmt, ##__VA_ARGS__)
#define BRSLOGINFO(module, flag, fmt, ...) BRSLOG(module, flag | BRSLogFlagInfo, fmt, ##__VA_ARGS__)

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //BRSLOG_H

