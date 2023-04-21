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

NS_ASSUME_NONNULL_BEGIN

@interface BRSSafeMutableArray<ObjectType> : NSObject

- (void)execute:(void(^)(NSMutableArray *arr))handler;

// MARK: - NSMutableArray

- (void)addObject:(ObjectType)anObject;
- (void)insertObject:(ObjectType)anObject atIndex:(NSUInteger)index;
- (void)removeLastObject;
- (void)removeObjectAtIndex:(NSUInteger)index;
- (void)replaceObjectAtIndex:(NSUInteger)index withObject:(ObjectType)anObject;

// MARK: - NSExtendedMutableArray

- (void)addObjectsFromArray:(NSArray<ObjectType> *)otherArray;
- (void)exchangeObjectAtIndex:(NSUInteger)idx1 withObjectAtIndex:(NSUInteger)idx2;
- (void)removeAllObjects;
- (void)removeObject:(ObjectType)anObject inRange:(NSRange)range;
- (void)removeObject:(ObjectType)anObject;
- (void)removeObjectIdenticalTo:(ObjectType)anObject inRange:(NSRange)range;
- (void)removeObjectIdenticalTo:(ObjectType)anObject;
- (void)removeObjectsInArray:(NSArray<ObjectType> *)otherArray;
- (void)removeObjectsInRange:(NSRange)range;
- (void)replaceObjectsInRange:(NSRange)range withObjectsFromArray:(NSArray<ObjectType> *)otherArray range:(NSRange)otherRange;
- (void)replaceObjectsInRange:(NSRange)range withObjectsFromArray:(NSArray<ObjectType> *)otherArray;
- (void)setArray:(NSArray<ObjectType> *)otherArray;
- (void)sortUsingFunction:(NSInteger (NS_NOESCAPE *)(ObjectType,  ObjectType, void * _Nullable))compare context:(nullable void *)context;
- (void)sortUsingSelector:(SEL)comparator;

- (void)insertObjects:(NSArray<ObjectType> *)objects atIndexes:(NSIndexSet *)indexes;
- (void)removeObjectsAtIndexes:(NSIndexSet *)indexes;
- (void)replaceObjectsAtIndexes:(NSIndexSet *)indexes withObjects:(NSArray<ObjectType> *)objects;

- (void)setObject:(ObjectType)obj atIndexedSubscript:(NSUInteger)idx API_AVAILABLE(macos(10.8), ios(6.0), watchos(2.0), tvos(9.0));

- (void)sortUsingComparator:(NSComparator NS_NOESCAPE)cmptr API_AVAILABLE(macos(10.6), ios(4.0), watchos(2.0), tvos(9.0));
- (void)sortWithOptions:(NSSortOptions)opts usingComparator:(NSComparator NS_NOESCAPE)cmptr API_AVAILABLE(macos(10.6), ios(4.0), watchos(2.0), tvos(9.0));

// MARK: - NSArray

@property (readonly) NSUInteger count;
- (ObjectType)objectAtIndex:(NSUInteger)index;

// MARK: - NSExtendedArray

- (BOOL)containsObject:(ObjectType)anObject;

@property (nullable, nonatomic, readonly) ObjectType firstObject API_AVAILABLE(macos(10.6), ios(4.0), watchos(2.0), tvos(9.0));
@property (nullable, nonatomic, readonly) ObjectType lastObject;

@end

NS_ASSUME_NONNULL_END
