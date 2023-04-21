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
#import <BonreeBusiness/BRSBusinessTypeDefine.h>

@class BRSFileInfo;

/// Upload控制数据
@protocol BRSUploadControlDataProtocol <NSObject>

/// 自身模块名称
@property (nonatomic, copy) NSString *moduleName;
/// Upload地址
@property (nonatomic, copy) NSString *address;
/// 会话标识
@property (nonatomic, copy) NSString *session;
/// Config下发的monitorTime时间戳
@property (nonatomic, assign) uint64_t configMonitorTime;
/// Upload回传周期 recoveryCycle
@property (nonatomic, assign) NSInteger intervalTime;
/// Upload场景
@property (nonatomic, assign) BRSUploadScenario uploadScenario;
/// 数据存储时间 [单位小时] unsigned int
@property (nonatomic, assign) NSUInteger saveTime;
///Config本地版本号[不传不缓存到本地]
@property (nonatomic, copy) NSString *localVersion;
///Config本地版本KEY，UserDefault使用[不传不缓存到本地]
@property (nonatomic, copy) NSString *localVersionKey;
///Upload本地路径[不传不缓存到本地]
@property (nonatomic, copy) NSString *localPath;

@end

/// Upload请求数据[内存/本地]
@protocol BRSUploadRequestDataProtocol <NSObject>

/// 请求对象
@property (nonatomic, strong) NSURLRequest *request;
/// Upload Key
@property (nonatomic, copy) NSString *key;
/// 本地数据
@property (nonatomic, strong) NSData *localData;
/// 本地数据文件名
@property (nonatomic, copy) NSString *dataFileName;
/// Query数据
@property (nonatomic, strong) NSData *localQueryData;
/// Query数据文件名
@property (nonatomic, copy) NSString *queryFileName;
/// 数据创建时间
@property (nonatomic, strong) NSDate *date;

@end

/// Upload消息接收者
@protocol BRSUploadReceiverProtocol <NSObject>

/// 获取Upload请求数据
/// @param option 获取选项
/// @param data 控制数据
- (id<BRSUploadRequestDataProtocol>)getUploadRequestOption:(BRSUploadOption)option data:(id<BRSUploadControlDataProtocol>)data;

/// 获取要保存本地的数据
- (id<BRSUploadRequestDataProtocol>)getNeedLocalSaveData;

/// 本地读取数据转换为可发送数据
/// @param files 文件数据
/// @param data 控制数据
- (NSArray<id<BRSUploadRequestDataProtocol>> *)transformLocalFiles:(NSArray<BRSFileInfo *> *)files data:(id<BRSUploadControlDataProtocol>)data;

/// 异步上传时获取要额外附加的请求数据
/// @param isStart 是否是启动时
/// @param data 控制数据
- (NSArray<id<BRSUploadRequestDataProtocol>> *)asyncLocalExtraDatasIsStart:(BOOL)isStart data:(id<BRSUploadControlDataProtocol>)data;

/// Upload收到响应
/// @param response 响应数据
/// @param requestData 请求数据
/// @param error 错误信息
/// @return 解析响应是否成功
- (BOOL)uploadDidReceiveResponse:(NSData *)response requestData:(id<BRSUploadRequestDataProtocol>)requestData error:(NSError *)error;

/// Upload已停止
- (void)uploadDidStop;

@optional

/// Upload请求成功是否删除本地文件
/// @param requestData 请求数据
/// @param controlData 模块数据
/// @param option 上报类型
/// @return 是否删除
- (BOOL)uploadSuccessIsDeleteFileWithRequest:(id<BRSUploadRequestDataProtocol>)requestData controlData:(id<BRSUploadControlDataProtocol>)controlData option:(BRSUploadOption)option;

@end

