//
//  BRLogConfiguration.h
//  BonreeLog
//
//  Created by 张喆 on 2023/4/3.
//

#import <Foundation/Foundation.h>
#import <BonreeLog/BRLogAgentType.h>

NS_ASSUME_NONNULL_BEGIN

@interface BRLogConfiguration : NSObject

/// Log Token
@property (nonatomic, copy) NSString *token;

/// 数据收集模式[仅启动时设置生效]
/// YES：数据发送远端并本地存储
/// NO：数据不发送远端，不存储本地
@property (nonatomic, assign) BOOL isTrackingData;

/// 应用版本
@property (nonatomic, copy, nullable) NSString *applicationVersion;

@end

NS_ASSUME_NONNULL_END
