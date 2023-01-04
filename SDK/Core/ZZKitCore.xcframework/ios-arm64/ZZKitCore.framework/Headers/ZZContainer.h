//
//  ZZContainer.h
//  ZZKit
//
//  Created by 张喆 on 2023/1/4.
//

#import <Foundation/Foundation.h>

@interface ZZContainer : NSObject

+ (BOOL)registerLibrary:(Class)library;

+ (void)startLibraries;

@end
