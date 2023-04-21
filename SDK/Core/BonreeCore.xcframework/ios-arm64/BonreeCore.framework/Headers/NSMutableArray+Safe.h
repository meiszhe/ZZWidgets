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

@interface NSMutableArray (BRSSafe)

- (void)addObjectSafe:(id)anObject;
- (void)insertObjectSafe:(id)anObject atIndex:(NSUInteger)index;
- (void)removeLastObjectSafe;
- (void)removeObjectAtIndexSafe:(NSUInteger)index;
- (void)replaceObjectAtIndexSafe:(NSUInteger)index withObject:(id)anObject;
- (void)addObjectsFromArraySafe:(NSArray<id>*)otherArray;
- (void)exchangeObjectAtIndexSafe:(NSUInteger)idx1 withObjectAtIndex:(NSUInteger)idx2;
- (void)removeAllObjectsSafe;
- (void)removeObjectSafe:(id)anObject inRange:(NSRange)range;
- (void)removeObjectSafe:(id)anObject;
- (void)removeObjectIdenticalToSafe:(id)anObject inRange:(NSRange)range;
- (void)removeObjectIdenticalToSafe:(id)anObject;
- (void)removeObjectsFromIndicesSafe:(NSUInteger*)indices numIndices:(NSUInteger)cnt API_DEPRECATED("Not supported", macos(10.0,10.6), ios(2.0,4.0), watchos(2.0,2.0), tvos(9.0,9.0));
- (void)removeObjectsInArraySafe:(NSArray<id>*)otherArray;
- (void)removeObjectsInRangeSafe:(NSRange)range;
- (void)replaceObjectsInRangeSafe:(NSRange)range withObjectsFromArray:(NSArray<id>*)otherArray range:(NSRange)otherRange;
- (void)replaceObjectsInRangeSafe:(NSRange)range withObjectsFromArray:(NSArray<id>*)otherArray;
- (void)setArraySafe:(NSArray<id>*)otherArray;
- (void)insertObjectsSafe:(NSArray<id>*)objects atIndexes:(NSIndexSet*)indexes;
- (void)removeObjectsAtIndexesSafe:(NSIndexSet*)indexes;
- (void)replaceObjectsAtIndexesSafe:(NSIndexSet*)indexes withObjects:(NSArray<id>*)objects;
- (void)setObjectSafe:(id)obj atIndexedSubscript:(NSUInteger)idx;
- (void)sortWithOptionsSafe:(NSSortOptions)opts usingComparator:(NSComparator NS_NOESCAPE)cmptr;
- (BOOL)containsObjectSafe:(id)anObject;

- (dispatch_semaphore_t)semaphoreLock;

@property (nonatomic,copy)NSString *brs_contentClass;

@end
