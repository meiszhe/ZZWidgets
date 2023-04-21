//
//  BRSLockMacros.h
//  BonreeCore
//
//  Created by shixj-iMac on 2023/3/8.
//  Copyright © 2023 bonree. All rights reserved.
//

#ifndef BRSLockMacros_h
#define BRSLockMacros_h

#define Lock(semaphore_lock)\
if (semaphore_lock) dispatch_semaphore_wait(semaphore_lock,DISPATCH_TIME_FOREVER);

#define UnLock(semaphore_lock)\
if (semaphore_lock) dispatch_semaphore_signal(semaphore_lock);

#endif /* BRSLockMacros_h */
