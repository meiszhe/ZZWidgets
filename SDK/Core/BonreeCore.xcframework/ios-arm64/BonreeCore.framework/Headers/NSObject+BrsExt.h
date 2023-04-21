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

@interface NSObject (BrsExt)

/**oc对象转换为整型(长整型)*/
- (int64_t)objectToInt;

/**oc对象转换为无符号整型(长整型)*/
- (uint64_t)objectToUInt;
/// 调用者仅限字典或者数组  @{@"aaa": [NSNull null]}的结果{"aaa" : null}
- (id)brs_jsonString;

@property (nonatomic, strong, nullable) NSUUID *brsUUID;

@end