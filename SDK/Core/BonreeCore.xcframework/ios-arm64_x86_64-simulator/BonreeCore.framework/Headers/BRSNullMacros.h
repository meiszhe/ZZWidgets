//
//  BRSNullMacros.h
//  BonreeCore
//
//  Created by 张喆 on 2023/3/27.
//

#ifndef BRSNullMacros_h
#define BRSNullMacros_h

//字符串是否为空
#define StringIsEmpty(str) ( [str isKindOfClass:[NSNull class]] || str == nil || ([str length] < 1 ? YES : NO) )
#define StringNoNull(str) StringIsEmpty(str) ? @"" : str
#define ArrayNoNull(arr) (arr != nil && arr.count) ? arr : @[]

#endif /* BRSNullMacros_h */
