// Copyright 2017 Shanghai Fangling Software Co., Ltd. All Rights Reserved.
// Author: zuo998@163.com (Dawei Zuo)

#ifndef UTILITY_BASE_CPPMATH_H__
#define UTILITY_BASE_CPPMATH_H__

#include "obase/Ecnc2Math.h"

class Compare {
public:
  static inline bool Equal(double a, double b) {
    return IsEqual(a, b) ? true : false;
  }

  static inline bool Equal(bool a, bool b) {
    return a == b;
  }

  static inline bool Equal(int a, int b) {
    return a == b;
  }

  static inline bool Equal(char a, char b) {
    return a == b;
  }
};

#endif // UTILITY_BASE_CPPMATH_H__
