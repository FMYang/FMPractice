//
//  main.m
//  runtime_test
//
//  Created by yfm on 2022/9/19.
//

#import <Foundation/Foundation.h>
#import <objc/runtime.h>
#import "Person.h"

/**
 Class object_getClass(id obj)
 {
     if (obj) return obj->getIsa();
     else return Nil;
 }
 
 typedef struct objc_object Person;
 
 struct objc_object {
     Class isa  OBJC_ISA_AVAILABILITY;
 };
  
 typedef struct objc_class *Class;

 struct objc_class {
     // 指向本类的指针
     Class isa  OBJC_ISA_AVAILABILITY;

 #if !__OBJC2__
     // 指向父类的指针
     Class super_class                                        OBJC2_UNAVAILABLE;
     // 类名
     const char *name                                         OBJC2_UNAVAILABLE;
     // 版本
     long version                                             OBJC2_UNAVAILABLE;
     long info                                                OBJC2_UNAVAILABLE;
     long instance_size                                       OBJC2_UNAVAILABLE;
     // 类实例列表
     struct objc_ivar_list *ivars                             OBJC2_UNAVAILABLE;
     // 类方法列表
     struct objc_method_list **methodLists                    OBJC2_UNAVAILABLE;
     // 类缓存
     struct objc_cache *cache                                 OBJC2_UNAVAILABLE;
     // 类协议列表
     struct objc_protocol_list *protocols                     OBJC2_UNAVAILABLE;
 #endif

 }
 */

struct objc_class {
    // 指向本类的指针
    Class isa  OBJC_ISA_AVAILABILITY;

//#if !__OBJC2__
    // 指向父类的指针
    Class super_class;
    // 类名
    const char *name;
    // 版本
    long version;
    long info;
    long instance_size;
    // 类实例列表
    struct objc_ivar_list *ivars;
    // 类方法列表
    struct objc_method_list **methodLists;
    // 类缓存
    struct objc_cache *cache;
    // 类协议列表
    struct objc_protocol_list *protocols;
//#endif

};

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
//        struct objc_object *p
        Person *p = [[Person alloc] init];
        struct objc_object *pp = (__bridge struct objc_object *)(p);
//        // pp->isa
        struct objc_class *cls = CFBridgingRetain(pp->isa);
        NSLog(@"name = %s", cls->name);
    }
    return 0;
}
