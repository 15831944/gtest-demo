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
  float       g_f_XMaxLimit;  //+X�����ֵ
  float       g_f_XMinLimit;  //-X����Сֵ
  float       g_f_YMaxLimit; //+Y�����ֵ
  float       g_f_YMinLimit;//-Y����Сֵ
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
  M90, //ͼ�㿪ʼ 
  M91, //ͼ�����
  M92, //ѭ����ʼ
  M93, //ѭ������
  M94, //�ļ���ʼ
  M95, //�ļ�����
  M200 //�û��Զ���M���� enum LASER_USER_M_CMD

} GMID;

typedef enum _GCodeErr {
  NoErr,
  InvalidFile,
  G02G03Err,
  SyntaxErr,
  FileTooLarge,

} GCodeErr;

enum M10_M21{
M42 = 110, //ȼ������Ԥ�ȣ���
M43,       //ȼ��(��Ԥ��)��
M44,       //�и����� (��ѹ�и���)
M45,       //�и�����(��ѹ�и���)
M14,       //��ǹ����
M15,       //��ǹ����
M16,       //��ǹ����
M17,       //��ǹ����
M18,       //���        
M19,       //����
M20,       //��Ԥ�ȿ�
M21,       //��Ԥ�ȹ�
M22,       //һ�����׿�����ѹ�и�����
M23,       //һ�����׹أ���ѹ�и�����
M24,       //�������׿�����ѹ�и�����
M25,       //�������׹أ���ѹ�и�����
M26,       //���ߺп�
M27,       //���ߺй�
M28,       //�𻡿�
M29,       //�𻡹�
M46,       //�رյ��߿�
M47,       //�رյ��߹�
M32,       //��ۿ�
M33,       //��۹�
M34,       //��ۿ�
M35,       //��۹�
M36,       //���Ԥ�ȿ�
M37,       //���Ԥ�ȹ�
M38,       //�����ڿ�
M39,       //�����ڹ�
M40,       //�����Ӷ�λ��
M41,        //�����Ӷ�λ��
M48,
M60,
M62,
M63,
M64,
M65,
M81,        //��ף����� ���
M82,        //̧�����������
I28,        //�ȴ��������λ
I29,        //�ȴ��������λ

};

typedef struct {
  U32 ShowLine; //32bit
  U32 LineNoInTotalFile;
  U16 Name;
  U16 PierceHoleNum;
  double X0;  //G�������ʼ����
  double Y0;
  double X;             // U of G00 G01 G02 G03 G92
  double Y;             // V of G00 G01 G02 G03 G92

  double I;             // I of G02 G03,
  double J;             // J of G02 G03
  double F;             // Target Speed
  double R;             // Radius of G02 G03
  double StartAngle;    // Start angle of G02 G03,G04 ����delay time, G41��G42��ָ������С 
  double EndAngle;      // End angle of G02 G03
  double  Length;          /* ��ǰ�����еĳ���                  */
  double  AngleRatio;      /* ĩ����������һ�����ߵ�����ļнǵı仯��
                          >=90��ʱ    = 1��
                          С��90��ʱ��= (_1p2PI-�н�)/_1p2PI*/
}GCodeARRAY_STRUCT;

typedef struct 
{
	float RowPulse;             //����������
	float ColPulse;             //����������
	float MaxCutSpeed;          //����и��ٶ�
	float MaxG00Speed;          //�ճ�����ٶ�
	float MaxManualSpeed;
	float ArcLimitSpeed;        //СԲ������
	float AdjustTime;           //����ʱ��
	float PlasmaAdjustTime;     //�����ӵ���ʱ��
	float EmergencyStopTime;    //��ͣʱ��
	float StartSpeed;           //�����ٶȡ�
	float MaxX;                 //������λ+X
	float MaxY;                 //������λ+Y
	float MinX;                 //����λ-X
	float MinY;                 //����λ-Y
}SYSTEM_PARA;

typedef struct 
{
    float CutSpeed;                 //�и��ٶ�
    float ManualSpeed;              //�ֶ��Ƴ��ٶ�
    float G00Speed;                 //�ճ��Ƴ��ٶ�
    float NullSpeed;                //��ǰ�����ٶ�
    float SprayPowderSpeed;         //����ٶ�
    float KerfValue;                //��첹��ֵ
    float SteelPlateThickness;      //�ְ���  
    float CurrentCutType;           //��ǰ�и����ͣ������ӣ���ȼ���л�
    float EdgeCutEn;                //��Ե����ʹ�ܣ�1ʹ�ܣ�����M07ʱ��ʾ����Ե���ף���ǰ�㴩�ף������ס�
    float HoldPreHeatInCutting;     //�и���Ԥ��������
}GENERAL_PARA;

#endif
