// Copyright 2018 Fangling Software Co., Ltd. All Rights Reserved.
// Author: zuo998@163.com (Dawei Zuo)

#ifndef OBASE_GCODE_ONAIVECAMFITTING_H__
#define OBASE_GCODE_ONAIVECAMFITTING_H__

#include <vector>

class OVector{
 public:
  OVector();
  OVector(double x, double y, double z);
  OVector operator +(const OVector &v);
  OVector operator -(const OVector &v);
  OVector operator *(double o);
  double Norm();
  double Dot(const OVector &v2);
  double x_;
  double y_;
  double z_;
};

#define ONAIVECAMFITTING_USE_ABCUVW_AXIS 0
class ONaiveCamFitting {
 public:
  enum GCodeCmd {
    G00,
    G01,
    GGG,
  };
  struct Point {
    Point();
    Point(double x
          , double y
          , double z
#if ONAIVECAMFITTING_USE_ABCUVW_AXIS
          , double a
          , double b
          , double c
          , double u
          , double v
          , double w
#endif
          );

    double x_;
    double y_;
    double z_;
#if ONAIVECAMFITTING_USE_ABCUVW_AXIS
    double a_;
    double b_;
    double c_;
    double u_;
    double v_;
    double w_;
#endif
  };

  ONaiveCamFitting();
  ~ONaiveCamFitting();
  void FittingOneInstruction(
      GCodeCmd cmd,
      const Point &cur_point,
      Point &segment,
      bool &add_small_segment,
      bool &cur_cmd_reserve);

  void SetTolerance(double tolerance);
  void Reset();

 private:
  inline bool Linkable(const Point &cur_point);
  inline bool SeeSegment(const Point &cur_point, Point &segment);
  inline bool FlushSegments(Point &segment);
  inline void UpdateEndPoint(const Point &cur_point);

  std::vector<Point> chained_points_;
  double tolerance_;
  Point end_point_;
  static const int LINKABLE_POINT_MAX_COUNT = 100;
};

#endif //OBASE_GCODE_ONAIVECAMFITTING_H__
