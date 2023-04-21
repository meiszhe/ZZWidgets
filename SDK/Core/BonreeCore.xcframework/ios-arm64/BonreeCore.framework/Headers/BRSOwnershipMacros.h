//
//  BRSOwnershipMacros.h
//  BonreeCore
//
//  Created by shixj-iMac on 2023/3/8.
//  Copyright © 2023 bonree. All rights reserved.
//

#ifndef BRSOwnershipMacros_h
#define BRSOwnershipMacros_h

#define BRWeakSelf(type)  __weak typeof(type) weak##type = type;
#define BRStrongSelf(type)  __strong typeof(type) type = weak##type;

#endif /* BRSOwnershipMacros_h */
