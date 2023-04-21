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

@interface NSMutableDictionary (BRSSafe)

- (void)removeObjectForKeySafe:(id)aKey;
- (void)setObjectSafe:(id)anObject forKey:(id <NSCopying>)aKey;
- (void)setValueSafe:(id)value forKey:(NSString *)key;
- (void)removeAllObjectsSafe;
- (void)removeObjectsForKeysSafe:(NSArray<id> *)keyArray;
- (void)setDictionarySafe:(NSDictionary<id, id> *)otherDictionary;
- (id)objectForKeySafe:(id)aKey;
- (NSArray *)allValuesSafe;

- (dispatch_semaphore_t)semaphoreLock;

@end
