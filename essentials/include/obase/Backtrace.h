// Copyright 2017 Shanghai Fangling Software Co., Ltd. All Rights Reserved.
// Author: zuo998@163.com (Dawei Zuo)

// Based on http://stackoverflow.com/questions/4636456/stack-trace-for-c-using-gcc/4732119#4732119

#ifndef LOADER_BACKTRACE_H__
#define LOADER_BACKTRACE_H__

#ifndef WIN32

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

void BacktraceInit();

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // #ifdef WIN32

#endif // LOADER_BACKTRACE_H__
