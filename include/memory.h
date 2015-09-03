/**
 * Bridge.Memory模块的默认实现的定义
 */
#ifndef BRIDGE_MEMORY_H
#define BRIDGE_MEMORY_H

#include <include/bridge.h>

typedef struct {
    DERIVING_NAMED;
    ret_state (*alloc)(size_t, void **);
    ret_state (*free)(void *);
} ModMemory;

#endif //BRIDGE_MEMORY_H