//
//  BRSModel.h
//  YYModel <https://github.com/ibireme/YYModel>
//
//  Created by ibireme on 15/5/10.
//  Copyright (c) 2015 ibireme.
//
//  This source code is licensed under the MIT-style license found in the
//  LICENSE file in the root directory of this source tree.
//

#import <Foundation/Foundation.h>

#if __has_include(<BonreeCore/BRSModel.h>)
FOUNDATION_EXPORT double BRSModelVersionNumber;
FOUNDATION_EXPORT const unsigned char BRSModelVersionString[];
#import <BonreeCore/NSObject+BRSModel.h>
#import <BonreeCore/BRSClassInfo.h>
#else
#import "NSObject+BRSModel.h"
#import "BRSClassInfo.h"
#endif
