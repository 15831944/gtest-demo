// Copyright 2016 Shanghai Fangling Software Co., Ltd. All Rights Reserved.
// Author: leiyang@flcnc.com (Lei Yang)

#ifndef GCODEPARSE_GCODEPARSE_H__
#define GCODEPARSE_GCODEPARSE_H__

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <locale>

#include "GCommand.h"
#include "obase/GCodeTypeDef.h"

/***
 * GCodeParse is used to parse the G code file, and form the the G code
 * commands stored in the memory.
 *
 */

typedef enum _FootMetricSystem {
  FootSystem,
  MetricSystem,

} FootMetricSystem;

typedef enum _RelOrAbsAxix {
  RelativeAxis,
  AbsAxis,

} RelOrAbsAxis;

namespace gcode {

class GCodeParse {
 public:
  GCodeParse();
  GCodeParse(const GCodeParse &other);
  GCodeParse& operator=(const GCodeParse &other);

  /**
   * Function Name: SetParseEnv
   * The function is used to set the external environment before the parsing.
   * @param [in]: system_rel_abs, true: relative axis; false: absolute axis.
   * @param [in]: system_IJ_abs, set the center coordinates system, true: absolute;
   * false: relative.
   * @param [in]: system_foot_metric, true: foot; false: metric.
   * @param [in]: system_F_forbidden, whether the F argument is forbidden.
   *
   */
  void SetParseEnv(bool system_rel_abs, bool system_IJ_abs,
      bool system_foot_metric, bool system_F_forbidden);

  /// whether delete the M(M07,M08) from the original file.
  void SetGCodeCheckEnable(bool enable) {
    check_M_ = enable;
  }

  void SetG99Option(double scale, double rotate_ang,
      double x_mirror, double y_mirror, bool combine = false);

  void GetG99Option(double &scale, double &rotate_ang, int &x_mirr, int &y_mirr);
  void DeleteHeadTailG00();
  void AddHeadTailG00(double tail_offset_x, double tail_offset_y);
  void GetTailG00Dis(double &offset_x, double &offest_y);

  /// Parse the G code file to the G commands that to be stored in memory.
  int ToStdGCode(std::string filename);
  int ToStdGCodeFromMem(const std::string &g_code_buff);

  /// Judget whether is Essi code, 0: G code; 1: Essi cdoe; -1: file error
  int IsEssiCode(std::string filename);

  /// Get the last parse error in parsing the G code.
  int GetErr();
  std::string &GetErrMsg() {
    return err_msg_;
  }

  /// Set the G commands with kerf
  void SetCommandKerfVec(const std::vector<GCommand> &cmd_vec);
  void SetCommandVec(const std::vector<GCommand> &cmd_vec);

  /// Get the parsed result G commands with kerf default.
  /// with_kerf: 1 return the reference to the kerf g code
  ///            0 return the reference to the g code without kerf
  const std::vector<GCommand>& GetCommandVec(int with_kerf = 1) const;

  /// Set the G code file path name.
  void SetGCodeFilePath(std::string file_path);
  std::string GetGCodeFilePath() const {
    return path_;
  }

  /// Scale the G code.
  void ScaleGCode(double scale);

  /// Rotate the G code.
  void RotateGCode(double angle);
  void RotateGCommandVec(double angle);
  void RotateGCommandKerfVec(double angle);

  /// Mirror the G code at X direction.
  void GCodeXMirror(int x_mirr);

  /// Mirror the G code at y direction.
  void GCodeYMirror(int y_mirr);

  /// Translate G code. 
  void TranslateGCode(double offset_x, double offset_y);

  /// Change the origin(start point) of the g code.
  void ChangeOrigin(double origin_x, double origin_y);
  void G99Process(GCommand &g_cmd);
  void PreArrangeProcess();
  void PostArrangeProcess();

  /// Write the g commands to a file.
  void WriteToStdFile(const std::string filename);

  /// Translate a g command to a line of string. 
  /// The passed GCommand must be with kerf, used to generate command to machinekit.
  std::string GenerateStdGCommand(GCommand g_cmd);
  std::string GenerateStdGCommand(int index);
  /// The passed GCommand should be with no kerf, used to generate command for editing.
  std::string GenerateGCmdString(const GCommand &g_cmd);
  /// Used to generate the absolute GCommand class data.
  std::string GenerateGCmdData(const GCommand &g_cmd);

  /// Reverse a g command.
  std::string ReverseGCommand(int line_no, std::vector<double> *breakpoint = NULL);
  std::string ReverseGCommand(int line_no,
      std::vector<double> &breakpoint, double velocity = 0);


  int ReverseGCommand(GCommand &cmd);
  GCommand ReverseGCommandCmd(int line_no, std::vector<double> *breakpoint = NULL);
  GCommand ReverseGCommandCmd(int line_no,
      std::vector<double> &breakpoint, double velocity = 0);

  /// velocity > 0, forward; otherwise backward
  std::string GenerateCmdByLineNo(int line_no,
      std::vector<double> &breakpoint, double velocity, int direct = 1);

  /// Get the end point of the entire g code
  void GetGCodeEndPoint(std::vector<double> &end_point);
  void GetGCodeStartPoint(std::vector<double> &start_point) const;

  void AppendGCommand(const GCodeParse &appended);

  int GetCurveLines() const;
  int GetPierceHoles() const;
  void SetPierceHoles(int holes);
  /// Get show line by curve num or hole num.
  /// 0:by line num, 1:by hole num
  int GetLinesByHoleOrLine(int line_hole_no, int mode);
  int GetHoleByLine(int line_no);

  /// This method must be called after calling the methods in ComputeTask module.
  int Calcu2M07M08Dis();

  double GetMaxRadius() const {
    return max_radius_;
  }
  
  void SetMaxRadius(double max_r) {
    max_radius_ = max_r;
  }

  double GetMinRadius() const {
    return IsZero(min_radius_) ? 5 : min_radius_;
  }

  void SetMinRadius(double min_r) {
    min_radius_ = min_r; 
  }

  std::string &GetGCodeText() {
    UpdateGCodeContent();
    return gcode_content_;
  }

  bool GetKerfFlag() const {
    return kerf_flag_;
  }

  bool IsCuttingCurve(int line_no);

  void SetKerfFlag(bool kerf) {
    kerf_flag_ = kerf;
  }

  void SetG99Flag(bool g99) {
    g99_flag_ = g99;
    if (!g99) {
      SetG99Option(1, 0, 0, 0);
    }
  }
  
  void SetRectifyAngle(double angle) {
    rectify_angle = angle;
  }

  void SetG90G91Opt(RelOrAbsAxis rel_abs) {
    rel_abs_ = rel_abs;
  }

  RelOrAbsAxis GetRelOrAbsAxis() const {
    return rel_abs_;
  }

  void AddRectifyAngle(GCommand &g_cmd);
  void RemoveRectifyAngle(GCommand &g_cmd);
  void CalcuCmdLengths();
  void RawCmd2ExecCmd();
  double PartitionCmdByPoint(int line, double x, double y);
  static void CalcuCmdLength(GCommand &gcmd);
  static double PartitionCmdByPoint(const GCommand &gcmd, double x, double y);
  static bool system_axis_type; // false: countclockwise; true: clockwise
  static bool sys_rel_abs;      // false: absolute  true: relative
  static bool g02g03IJ_abs;     // false: relative  true: relative
  static bool arg_F_forbidden;  // false: not forbidden true: forbidden
  static bool sys_foot_metric;  // false: metric    true: foot
  static bool check_M_;         // false: let it go; true: delete the M07 and M08 

  static double ref_x;
  static double ref_y;
  static double rectify_angle;    // the steel rectify angle
  static unsigned short no_hole;  // the num of the pierce holes
  static short err;
  static bool zero_segment_del;

 private:
  enum CmdType { Cutting, Moving };
  enum TorchType { Flame, Powder };
  FootMetricSystem foot_metric_;
  RelOrAbsAxis rel_abs_;
  double g99_scale_;
  double rotate_ang_;
  int x_mirror_;
  int y_mirror_;
  double max_radius_;
  double min_radius_;

  std::vector<GCommand> cmd_vec_;
  std::vector<GCommand> cmd_kerf_vec_;
  std::vector<std::string> cmd_buffer_;
  GCommand g_cmd_;
  std::string path_;
  std::string line_;
  std::string err_msg_;
  std::string gcode_content_;
  bool parse_over_;
  bool run_into_m9_;
  bool del_g00_flag_;
  int parse_line_no_;

  unsigned int cmd_head_;
  bool kerf_flag_;
  bool g99_flag_;
  CmdType cmd_type_;
  TorchType torch_type_;
  unsigned int last_curve_;
  int current_layer_;
  unsigned int last_m08_index_;
  /// Change all the alphabets to upper case.
  static void ToUppercase(std::string &line);
  unsigned int SkipSpace(std::string &line, unsigned int start_pos = 0);
  double GetArgValue(unsigned int start_pos);
  int ParseGCmd();
  int DeleteLinePrefix();
  int ParseGOrder();
  int ParseMOrder();

  int PreprocessCmd();
  void PushBackCmd();
  void PostprocessCmd();
  void G99ScaleRotateMirror();
  void Clean();

  int Index2CmdName(int code_type, int code_index);
  int AnotherOrder();

  int ArgXProcess();
  int ArgUProcess();
  int ArgYProcess();
  int ArgVProcess();
  int ArgIProcess();
  int ArgJProcess();
  int ArgRProcess();
  int ArgFProcess();
  int ArgLProcess();
  int ArgPProcess();
  void InsertM07M08();
  void InsertLayerCmd();
  void InsertLayerEndCmd();
  void InsertMCmd(GMID m_id);
  int CheckG02G03();
  bool CheckZeroSegment();
  int CheckGCodeError();
  void GenerateErrMsg();
  int CalcuCenter(GCommand &g_cmd);
  void UpdateGCodeContent();
  void UpdateG99Option();
  void SetStartPoint(double x, double y, std::vector<GCommand> &cmd_vec);


  static void CalcuG02G03(GCommand &gcmd);

};

} // end of gcode namespace

#endif
