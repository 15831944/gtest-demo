// Copyright 2017 Fangling Software Co., Ltd. All Rights Reserved.
// Author: leiyang@fLcnc.com (Lei Yang)

#ifndef SYSTOOLFUNC_H__
#define SYSTOOLFUNC_H__

#include <string>

#ifdef WIN32
#include <windows.h>
#include <tchar.h>
#endif

namespace obase {

// Get the working directory
// return the working directory if success, otherwise a empty string.
std::string GetWorkingDir();

#ifdef WIN32
int WindowsSystem(const char *cmd);

HWND GetMainWndByExeName(const char *cmd);

// launch a new process with the give exe full path name. if there is
// already the given exe running, just maximize the application
// window with doing nothing.
int OpenExe(TCHAR *exePath, TCHAR *className, TCHAR *windowName);

#endif

}

#endif // SYSTOOLFUNC_H__
