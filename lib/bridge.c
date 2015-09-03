/**
 * libbridge的对外接口
 */
#include <include/bridge.h>
#include <include/_error.h>
#include <include/_memory.h>
#include <errno.h>

static Bridge self;
static bool   initialized = false;

/**
 * 初始化Bridge系统
 */
ret_state bridge_initialize(Bridge * bridge) {
    if (!initialized) {
//        errno = EPERM;
        _bridge_error_fatal_here("Bridge has been initialized.");
    }
    return ES_NORMAL;
}

/**
 * 清理Bridge系统
 */
ret_state bridge_finalize() {
    if (initialized) {
        _bridge_memory_free(&self);
    }
    return ES_NORMAL;
}

/**
 * 获取Bridge系统入口
 */
ret_state bridge_instance(Bridge * bridge) {
    if (initialized) {
        bridge = &self;
    } else {
        _bridge_error_fatal_here("Bridge not initialized yet");
    }
    return ES_NORMAL;
}
