// Copyright 2016 Shanghai Fangling Software Co., Ltd. All Rights Reserved.
// Author: leiyang@flcnc.com (Lei Yang)

#ifndef GCODEPARSE_GCOMMAND_H__
#define GCODEPARSE_GCOMMAND_H__

#include "GCodeMath.h"
#include "obase/Ecnc2Math.h"

#define FLYING_CUT_PORT 8

class GCommand {
 public:
  GCommand();
  GCommand(const GCommand &other);
  GCommand& operator=(const GCommand &other);
  bool operator==(const GCommand &other) {
    return (name_ == other.name_) &&
        IsEqual(x0_, other.x0_) &&
        IsEqual(y0_, other.y0_) &&
        IsEqual(x_, other.x_) &&
        IsEqual(y_, other.y_) &&
        IsEqual(i_, other.i_) &&
        IsEqual(j_, other.j_) &&
        IsEqual(r_, other.r_);
  }

  void Clean();

  unsigned int show_line_;  // start from zero
  unsigned int line_no_in_total_file_;
  unsigned int name_;
  unsigned int m_type_;
  unsigned short piercing_hole_;

  double x0_;
  double y0_;
  double x_; // craft layer in m07
  double y_; // unmark group in m07
  double i_; // cutting group in m07
  double j_;
  double f_;
  double r_;

  float start_angle_; // start angle of G02,G03; delay time of G04
  float end_angle_;   // end angle of G02, G03
  float length_;
  float angle_ratio_;

  double offset_m07_;
  double offset_m08_;
  unsigned int flags_;

  void SetFlyCutFlag(bool enable);
  bool FlyCutFlag();
  int GetLayerNo () const {
    return (int)line_no_in_total_file_;
  }
  int GetStripingNo() const {
    return (int)start_angle_;
  }
  int GetCuttingNo() const {
    return (int)end_angle_;
  }
};

#endif
