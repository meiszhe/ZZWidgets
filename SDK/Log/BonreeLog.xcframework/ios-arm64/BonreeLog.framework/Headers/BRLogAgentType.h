//
//  BRLogAgentType.h
//  BonreeLog
//
//  Created by 张喆 on 2023/4/3.
//

#ifndef BRLogAgentType_h
#define BRLogAgentType_h

/// 日志等级
/// 严重级别由上至下递增，例：Error严重级别大于Info
typedef NS_ENUM(NSInteger, BRLogLevel) {
    BRLogLevelDebug       = 1,
    BRLogLevelInfo,
    BRLogLevelNotice,
    BRLogLevelWarn,
    BRLogLevelError,
    BRLogLevelEmergency
};

#endif /* BRLogAgentType_h */
