//
//  BRSClassInfo.h
//  YYModel <https://github.com/ibireme/YYModel>
//
//  Created by ibireme on 15/5/9.
//  Copyright (c) 2015 ibireme.
//
//  This source code is licensed under the MIT-style license found in the
//  LICENSE file in the root directory of this source tree.
//

#import <Foundation/Foundation.h>
#import <objc/runtime.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Type encoding's type.
 */
typedef NS_OPTIONS(NSUInteger, BRSEncodingType) {
    BRSEncodingTypeMask       = 0xFF, ///< mask of type value
    BRSEncodingTypeUnknown    = 0, ///< unknown
    BRSEncodingTypeVoid       = 1, ///< void
    BRSEncodingTypeBool       = 2, ///< bool
    BRSEncodingTypeInt8       = 3, ///< char / BOOL
    BRSEncodingTypeUInt8      = 4, ///< unsigned char
    BRSEncodingTypeInt16      = 5, ///< short
    BRSEncodingTypeUInt16     = 6, ///< unsigned short
    BRSEncodingTypeInt32      = 7, ///< int
    BRSEncodingTypeUInt32     = 8, ///< unsigned int
    BRSEncodingTypeInt64      = 9, ///< long long
    BRSEncodingTypeUInt64     = 10, ///< unsigned long long
    BRSEncodingTypeFloat      = 11, ///< float
    BRSEncodingTypeDouble     = 12, ///< double
    BRSEncodingTypeLongDouble = 13, ///< long double
    BRSEncodingTypeObject     = 14, ///< id
    BRSEncodingTypeClass      = 15, ///< Class
    BRSEncodingTypeSEL        = 16, ///< SEL
    BRSEncodingTypeBlock      = 17, ///< block
    BRSEncodingTypePointer    = 18, ///< void*
    BRSEncodingTypeStruct     = 19, ///< struct
    BRSEncodingTypeUnion      = 20, ///< union
    BRSEncodingTypeCString    = 21, ///< char*
    BRSEncodingTypeCArray     = 22, ///< char[10] (for example)
    
    BRSEncodingTypeQualifierMask   = 0xFF00,   ///< mask of qualifier
    BRSEncodingTypeQualifierConst  = 1 << 8,  ///< const
    BRSEncodingTypeQualifierIn     = 1 << 9,  ///< in
    BRSEncodingTypeQualifierInout  = 1 << 10, ///< inout
    BRSEncodingTypeQualifierOut    = 1 << 11, ///< out
    BRSEncodingTypeQualifierBycopy = 1 << 12, ///< bycopy
    BRSEncodingTypeQualifierByref  = 1 << 13, ///< byref
    BRSEncodingTypeQualifierOneway = 1 << 14, ///< oneway
    
    BRSEncodingTypePropertyMask         = 0xFF0000, ///< mask of property
    BRSEncodingTypePropertyReadonly     = 1 << 16, ///< readonly
    BRSEncodingTypePropertyCopy         = 1 << 17, ///< copy
    BRSEncodingTypePropertyRetain       = 1 << 18, ///< retain
    BRSEncodingTypePropertyNonatomic    = 1 << 19, ///< nonatomic
    BRSEncodingTypePropertyWeak         = 1 << 20, ///< weak
    BRSEncodingTypePropertyCustomGetter = 1 << 21, ///< getter=
    BRSEncodingTypePropertyCustomSetter = 1 << 22, ///< setter=
    BRSEncodingTypePropertyDynamic      = 1 << 23, ///< @dynamic
};

/**
 Get the type from a Type-Encoding string.
 
 @discussion See also:
 https://developer.apple.com/library/mac/documentation/Cocoa/Conceptual/ObjCRuntimeGuide/Articles/ocrtTypeEncodings.html
 https://developer.apple.com/library/mac/documentation/Cocoa/Conceptual/ObjCRuntimeGuide/Articles/ocrtPropertyIntrospection.html
 
 @param typeEncoding  A Type-Encoding string.
 @return The encoding type.
 */
BRSEncodingType BRSEncodingGetType(const char *typeEncoding);


/**
 Instance variable information.
 */
@interface BRSClassIvarInfo : NSObject
@property (nonatomic, assign, readonly) Ivar ivar;              ///< ivar opaque struct
@property (nonatomic, strong, readonly) NSString *name;         ///< Ivar's name
@property (nonatomic, assign, readonly) ptrdiff_t offset;       ///< Ivar's offset
@property (nonatomic, strong, readonly) NSString *typeEncoding; ///< Ivar's type encoding
@property (nonatomic, assign, readonly) BRSEncodingType type;    ///< Ivar's type

/**
 Creates and returns an ivar info object.
 
 @param ivar ivar opaque struct
 @return A new object, or nil if an error occurs.
 */
- (instancetype)initWithIvar:(Ivar)ivar;
@end


/**
 Method information.
 */
@interface BRSClassMethodInfo : NSObject
@property (nonatomic, assign, readonly) Method method;                  ///< method opaque struct
@property (nonatomic, strong, readonly) NSString *name;                 ///< method name
@property (nonatomic, assign, readonly) SEL sel;                        ///< method's selector
@property (nonatomic, assign, readonly) IMP imp;                        ///< method's implementation
@property (nonatomic, strong, readonly) NSString *typeEncoding;         ///< method's parameter and return types
@property (nonatomic, strong, readonly) NSString *returnTypeEncoding;   ///< return value's type
@property (nullable, nonatomic, strong, readonly) NSArray<NSString *> *argumentTypeEncodings; ///< array of arguments' type

/**
 Creates and returns a method info object.
 
 @param method method opaque struct
 @return A new object, or nil if an error occurs.
 */
- (instancetype)initWithMethod:(Method)method;
@end


/**
 Property information.
 */
@interface BRSClassPropertyInfo : NSObject
@property (nonatomic, assign, readonly) objc_property_t property; ///< property's opaque struct
@property (nonatomic, strong, readonly) NSString *name;           ///< property's name
@property (nonatomic, assign, readonly) BRSEncodingType type;      ///< property's type
@property (nonatomic, strong, readonly) NSString *typeEncoding;   ///< property's encoding value
@property (nonatomic, strong, readonly) NSString *ivarName;       ///< property's ivar name
@property (nullable, nonatomic, assign, readonly) Class cls;      ///< may be nil
@property (nullable, nonatomic, strong, readonly) NSArray<NSString *> *protocols; ///< may nil
@property (nonatomic, assign, readonly) SEL getter;               ///< getter (nonnull)
@property (nonatomic, assign, readonly) SEL setter;               ///< setter (nonnull)

/**
 Creates and returns a property info object.
 
 @param property property opaque struct
 @return A new object, or nil if an error occurs.
 */
- (instancetype)initWithProperty:(objc_property_t)property;
@end


/**
 Class information for a class.
 */
@interface BRSClassInfo : NSObject
@property (nonatomic, assign, readonly) Class cls; ///< class object
@property (nullable, nonatomic, assign, readonly) Class superCls; ///< super class object
@property (nullable, nonatomic, assign, readonly) Class metaCls;  ///< class's meta class object
@property (nonatomic, readonly) BOOL isMeta; ///< whether this class is meta class
@property (nonatomic, strong, readonly) NSString *name; ///< class name
@property (nullable, nonatomic, strong, readonly) BRSClassInfo *superClassInfo; ///< super class's class info
@property (nullable, nonatomic, strong, readonly) NSDictionary<NSString *, BRSClassIvarInfo *> *ivarInfos; ///< ivars
@property (nullable, nonatomic, strong, readonly) NSDictionary<NSString *, BRSClassMethodInfo *> *methodInfos; ///< methods
@property (nullable, nonatomic, strong, readonly) NSDictionary<NSString *, BRSClassPropertyInfo *> *propertyInfos; ///< properties

/**
 If the class is changed (for example: you add a method to this class with
 'class_addMethod()'), you should call this method to refresh the class info cache.
 
 After called this method, `needUpdate` will returns `YES`, and you should call 
 'classInfoWithClass' or 'classInfoWithClassName' to get the updated class info.
 */
- (void)setNeedUpdate;

/**
 If this method returns `YES`, you should stop using this instance and call
 `classInfoWithClass` or `classInfoWithClassName` to get the updated class info.
 
 @return Whether this class info need update.
 */
- (BOOL)needUpdate;

/**
 Get the class info of a specified Class.
 
 @discussion This method will cache the class info and super-class info
 at the first access to the Class. This method is thread-safe.
 
 @param cls A class.
 @return A class info, or nil if an error occurs.
 */
+ (nullable instancetype)classInfoWithClass:(Class)cls;

/**
 Get the class info of a specified Class.
 
 @discussion This method will cache the class info and super-class info
 at the first access to the Class. This method is thread-safe.
 
 @param className A class name.
 @return A class info, or nil if an error occurs.
 */
+ (nullable instancetype)classInfoWithClassName:(NSString *)className;

@end

NS_ASSUME_NONNULL_END
