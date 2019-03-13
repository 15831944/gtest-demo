// Copyright 2017 Shanghai Fangling Software Co., Ltd. All Rights Reserved.
// Author: leiyang@flcnc.com (Lei Yang)

#ifndef GCODEPARSE_GCODEMATH_H__
#define GCODEPARSE_GCODEMATH_H__

#include <math.h>

namespace f2000 {

#define EP 1e-5
#define _1p4PI   0.78539816
#define _1p2PI   1.57079633
#define _3p4PI   2.35619449
#define _5p4PI   3.92699081
#define _3p2PI   4.71238898
#define _7p4PI   5.49778714
#define _2PI  6.28318531

#ifndef PI
#define  PI   3.14159265358979323846264338327950288419716939937510
#endif

typedef  struct {
  double x;
  double y;
  double r;
}circle_t;

typedef  struct {
  double x;
  double y;
}point_t;

typedef  struct {
  double x;
  double y;
  double z;
}point_d;

double fpmin(double x, double y); 

double fpmax(double x, double y); 

double dist (double x, double y, double x1, double y1);

double myatan2(double y,double x);

double sqr(double a);

double maxfabs (double a, double b);

double minfabs (double a, double b);

double ang_fabs(double ang);

double mysqrt(double x);

void RoundAngle(double *ptr_ang);

point_d VectorCrossProduct(const point_d &a, const point_d &b);

double RadiusAngle(const point_t &start, const point_t &end,
    const point_t &center, int ccw);

point_t RotatePoint(const point_t &p, double angle, int ccw);

point_t MidpointOfArc(const point_t &start, const point_t center,
    double angle, int ccw); 
 
point_t MidpointOfArc(const point_t &start, const point_t &end,
    const point_t &center, int ccw);

double VectorAngle(const point_t &vec_a, const point_t &vec_b);

double PartitionLineByPoint(const point_t &start, const point_t &end,
    const point_t &d); 

unsigned int  RToIJ(int Name, double R, point_t StartP, point_t EndP,
                    point_t *ResP);

double SpanCenterAngle(const point_t &start_pos, const point_t &end_pos,
                       const point_t &center, int cw_ccw);

double CenterAngle(const point_t &vec_oa);

}

#endif
