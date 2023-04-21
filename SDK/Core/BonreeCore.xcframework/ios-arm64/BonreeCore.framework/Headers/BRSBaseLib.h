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

#ifndef BRSBASELIB_H
#define BRSBASELIB_H

#import <UIKit/UIKit.h>

typedef struct {
    double usage;
    long long user_time;
    long long system_time;
} BRSCpuUsageInfo;

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus
    
#import <netdb.h>
#import <BonreeCore/BRSThreadTypes.h>

/// 成功时返回当前线程消耗的cpu时间（微秒）；失败时返回0
uint64_t brs_getThreadClockTime() API_AVAILABLE(ios(10.0));
/// 成功时返回进程消耗的cpu时间（微秒）；失败时返回0
int64_t brs_getProcessClockTime() API_AVAILABLE(ios(10.0));

NSTimeInterval brs_processStartTime();

/// 当前设备时间戳
uint64_t brs_timestamp_in_us();

/**cpu启动到现在的微秒数*/
uint64_t brs_cpu_time_us(void);

/**cpu启动到现在的毫秒数*/
uint64_t brs_cpu_time_ms(void);

uint64_t brs_absolute_time(void);

/**判断某类（cls）是否为指定类（acls）的子类*/
BOOL brs_isSubclassOfClass(Class _Nullable cls, Class _Nullable acls);

/**判断某类（cls）是否为指定类（acls）或其子类*/
BOOL brs_isKindOfClass(Class _Nullable cls, Class _Nullable acls);

/**动态添加方法*/
void brs_addInstanceMethod(Class _Nullable cls, SEL _Nonnull sel, IMP _Nonnull imp);

Class _Nullable brs_getOriginalClassOfFirebaseClass(Class _Nullable cls);

NSString * _Nonnull brs_frameToString(CGRect frame);

NSString * _Nullable brs_getClsName(NSObject * _Nullable target);

void brs_dispatch_sync_on_main(DISPATCH_NOESCAPE dispatch_block_t _Nonnull block);

/// 获取当前线程
BRSThreadType brs_thread_self();

/// 获取主线程
BOOL brs_get_main_thread(BRSThreadType * _Nonnull thread);

NSString * _Nonnull brs_thread_stringThreadId(BRSThreadType threadId);

/// 应用消耗的CPU时长 (user+system)
int64_t brs_appCpuTimeInUs();

BOOL brs_appCpuUsageInfo(BRSCpuUsageInfo * _Nonnull usageInfo);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //BRSBASELIB_H
