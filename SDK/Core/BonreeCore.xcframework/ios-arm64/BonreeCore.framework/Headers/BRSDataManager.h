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
#import <BonreeCore/BRSLOG.h>

typedef void(^BRSDataBreakHandle)(BRSLogFlag logFlag,  NSString * _Nullable breakMsg);

NS_ASSUME_NONNULL_BEGIN

@interface BRSFileInfo : NSObject

@property (nonatomic, copy) NSString *fileName;
@property (nonatomic, strong) NSData *fileData;
@property (nonatomic, strong) NSDate *createDate;

@end

@interface BRSDataManager : NSObject

+ (instancetype)sharedManager;

- (BOOL)removeFileOrDirectoryInDoucmentPath:(NSString *)path breakHandle:(BRSDataBreakHandle)breakHandle;

- (BOOL)writeData:(NSData *)object toDoucmentPath:(NSString *)path breakHandle:(BRSDataBreakHandle)breakHandle;
- (BOOL)writeData:(NSData *)object toDoucmentPath:(NSString *)path attributes:(nullable NSDictionary<NSFileAttributeKey, id> *)attributes breakHandle:(BRSDataBreakHandle)breakHandle;

- (nullable NSData *)readFileInDocumentPath:(NSString *)path;
- (nullable BRSFileInfo *)readFileInfoInDocumentPath:(NSString *)path breakHandle:(BRSDataBreakHandle)breakHandle;

- (nullable NSArray<NSData *> *)readFilesInDocumentDirectory:(NSString *)dir breakHandle:(BRSDataBreakHandle)breakHandle;
- (nullable NSArray<BRSFileInfo *> *)readFileInfosInDocumentDirectory:(NSString *)dir breakHandle:(BRSDataBreakHandle)breakHandle;


+ (NSString *)fullPathBasedOnDocumentByPath:(NSString *)path;
+ (NSString *)fullPathBasedOnLibraryByPath:(NSString *)path;
+ (NSString *)fullPathBasedOnTmpByPath:(NSString *)path;

@end

NS_ASSUME_NONNULL_END
