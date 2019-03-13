// Copyright 2016 Fangling Software Co., Ltd. All Rights Reserved.
// Author: miaochengyu@fLcnc.com (Miaocheng Yu)

#ifndef CORE_ECNC2MATH_H__
#define CORE_ECNC2MATH_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifndef PI
#define  PI   3.14159265358979323846264338327950288419716939937510
#endif

#ifndef MAX
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#endif

#ifndef MIN
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif

#ifndef MID
#define MID(a, b, c) (a < b ? (b < c ? b : a < c ? c : a) : (b > c ? b : a > c ? c : a))
#endif

/// @return 0: a != b
///         1: a = b
int IsEqual(double a, double b);

/// @return 0: a != 0
///         1: a == 0
int IsZero(double a);

/// @return 1: a > b
///         0: a <= b
int IsGreater(double a, double b);

/// @return 1: a >= b
///         0: a < b
int IsGreaterEqual(double a, double b);

/// @return 1: a < b
///         0: a >= b
int IsLesser(double a, double b);

/// @return 1: a <= b
///         0: a > b
int IsLesserEqual(double a, double b);

#ifdef __cplusplus
}
#endif

#endif // CORE_ECNC2MATH_H__
