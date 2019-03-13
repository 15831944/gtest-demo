// Copyright 2014 Fangling Software Co., Ltd. All Rights Reserved.
// Author: miaochengyu@fLcnc.com (Miaocheng Yu)

#ifdef _REVISION
#undef _REVISION
#endif
#ifdef _XSTR
#undef _XSTR
#endif
#ifdef XSTR
#undef XSTR
#endif
#ifdef CURRENT_MODULE_REVISION
#undef CURRENT_MODULE_REVISION
#endif

#define _REVISION 2c0e5869
#define _XSTR(str) #str
#define XSTR(str) _XSTR(str)
#define CURRENT_MODULE_REVISION XSTR(_REVISION)
