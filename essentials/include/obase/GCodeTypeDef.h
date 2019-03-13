// Copyright 2017 Shanghai Fangling Software Co., Ltd. All Rights Reserved.
// Author: leiyang@flcnc.com (Lei Yang)

#ifndef UTILITY_GCODETYPEDEF_H__
#define UTILITY_GCODETYPEDEF_H__

#ifndef U32
#define U32 unsigned long
#endif

#ifndef U16
#define U16 unsigned short
#endif

#define GFILETOTALROWS 200000

typedef struct
{
  float       g_f_XMaxLimit;  //+X轴最大值
  float       g_f_XMinLimit;  //-X轴最小值
  float       g_f_YMaxLimit; //+Y轴最大值
  float       g_f_YMinLimit;//-Y轴最小值
  float       ScaleXY;
  float       g_GraphicX_start;
  float       g_GraphicY_start;
  float       MaxRadius;
  float       MinRadius;
}GraphyLimit;

typedef enum _GMID {
  M02, G00, G01, G02, G03, G04, G92, G40, G41, G42,
  G20, G21, G90, G91, G99, G26, G27, G28, G22, G80,
  M00, M30, M07, M08, M09, M10, M11, M12, M50, M52,
  M80, G62, G63, G64, GGG,
  M90, //图层开始 
  M91, //图层结束
  M92, //循环开始
  M93, //循环结束
  M94, //文件开始
  M95, //文件结束
  M200 //用户自定义M命令 enum LASER_USER_M_CMD

} GMID;

typedef enum _GCodeErr {
  NoErr,
  InvalidFile,
  G02G03Err,
  SyntaxErr,
  FileTooLarge,

} GCodeErr;

enum M10_M21{
M42 = 110, //燃气（低预热）开
M43,       //燃气(低预热)关
M44,       //切割氧开 (高压切割氧)
M45,       //切割氧关(高压切割氧)
M14,       //割枪升开
M15,       //割枪升关
M16,       //割枪降开
M17,       //割枪降关
M18,       //点火开        
M19,       //点火关
M20,       //高预热开
M21,       //高预热关
M22,       //一级穿孔开（低压切割氧）
M23,       //一级穿孔关（低压切割氧）
M24,       //二级穿孔开（中压切割氧）
M25,       //二级穿孔关（中压切割氧）
M26,       //调高盒开
M27,       //调高盒关
M28,       //起弧开
M29,       //起弧关
M46,       //关闭调高开
M47,       //关闭调高关
M32,       //喷粉开
M33,       //喷粉关
M34,       //扬粉开
M35,       //扬粉关
M36,       //喷粉预热开
M37,       //喷粉预热关
M38,       //排气口开
M39,       //排气口关
M40,       //等离子定位开
M41,        //等离子定位关
M48,
M60,
M62,
M63,
M64,
M65,
M81,        //冲孔，钻轴 快进
M82,        //抬抢，钻轴快退
I28,        //等待冲孔下限位
I29,        //等待冲孔上限位

};

typedef struct {
  U32 ShowLine; //32bit
  U32 LineNoInTotalFile;
  U16 Name;
  U16 PierceHoleNum;
  double X0;  //G代码的起始坐标
  double Y0;
  double X;             // U of G00 G01 G02 G03 G92
  double Y;             // V of G00 G01 G02 G03 G92

  double I;             // I of G02 G03,
  double J;             // J of G02 G03
  double F;             // Target Speed
  double R;             // Radius of G02 G03
  double StartAngle;    // Start angle of G02 G03,G04 中是delay time, G41或G42中指定割缝大小 
  double EndAngle;      // End angle of G02 G03
  double  Length;          /* 当前代码行的长度                  */
  double  AngleRatio;      /* 末点的切向和下一句曲线的切向的夹角的变化率
                          >=90度时    = 1，
                          小于90度时　= (_1p2PI-夹角)/_1p2PI*/
}GCodeARRAY_STRUCT;

typedef struct 
{
	float RowPulse;             //横向脉冲数
	float ColPulse;             //纵向脉冲数
	float MaxCutSpeed;          //最大切割速度
	float MaxG00Speed;          //空程最大速度
	float MaxManualSpeed;
	float ArcLimitSpeed;        //小圆弧限速
	float AdjustTime;           //调整时间
	float PlasmaAdjustTime;     //等离子调整时间
	float EmergencyStopTime;    //急停时间
	float StartSpeed;           //起跳速度　
	float MaxX;                 //软正限位+X
	float MaxY;                 //软正限位+Y
	float MinX;                 //软负限位-X
	float MinY;                 //软负限位-Y
}SYSTEM_PARA;

typedef struct 
{
    float CutSpeed;                 //切割速度
    float ManualSpeed;              //手动移车速度
    float G00Speed;                 //空程移车速度
    float NullSpeed;                //单前单后速度
    float SprayPowderSpeed;         //喷粉速度
    float KerfValue;                //割缝补偿值
    float SteelPlateThickness;      //钢板厚度  
    float CurrentCutType;           //当前切割类型，等离子，氧燃气切换
    float EdgeCutEn;                //边缘穿孔使能，1使能，遇到M07时提示：边缘穿孔，当前点穿孔，不穿孔。
    float HoldPreHeatInCutting;     //切割中预热氧保持
}GENERAL_PARA;

#endif
