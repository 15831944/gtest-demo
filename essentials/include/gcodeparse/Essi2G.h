// Copyright 2016 Shanghai Fangling Software Co., Ltd. All Rights Reserved.
// Author: leiyang@flcnc.com (Lei Yang)

#ifndef GCODEPARSE_ESSI2G_H__
#define GCODEPARSE_ESSI2G_H__

enum ESSI_CODE
{
  ESSI_Start, //0 %
  ESSI_G,     // G00, G01, G02,G03
  ESSI_0,
  ESSI_3,
  ESSI_4,
  ESSI_5,   //5
  ESSI_6,
  ESSI_7,
  ESSI_8,
  ESSI_9,
  ESSI_10,  // 10
  ESSI_11, 
  ESSI_12,
  ESSI_11_1,
  ESSI_12_1,
  ESSI_11_2,  //15
  ESSI_12_2,
  ESSI_11_3,
  ESSI_12_3,
  ESSI_11_4,
  ESSI_12_4,  // 20
  ESSI_11_5,
  ESSI_12_5,
  ESSI_11_6,
  ESSI_12_6,
  ESSI_11_7, // 25
  ESSI_12_7,
  ESSI_11_8,
  ESSI_12_8,
  ESSI_13,
  ESSI_14,  // 30
  ESSI_15,
  ESSI_16,
  ESSI_21,
  ESSI_22,
  ESSI_23, // 35
  ESSI_24,
  ESSI_25,
  ESSI_26,
  ESSI_27,
  ESSI_28, //40 
  ESSI_29, 
  ESSI_30,
  ESSI_38,
  ESSI_39,
  ESSI_40,
  ESSI_41,  //45
  ESSI_45,
  ESSI_46,
  ESSI_47,
  ESSI_48,
  ESSI_51, // 50
  ESSI_52,
  ESSI_53,
  ESSI_54,
  ESSI_63,
  ESSI_64, // 55
  ESSI_65,
  ESSI_67,
  ESSI_68,
  ESSI_70,
  ESSI_71,
  ESSI_79_1,  //60
  ESSI_79_2,
  ESSI_79_3,
  ESSI_79_4,
  ESSI_81,
  ESSI_82,  //65
  ESSI_83,
  ESSI_90,
  ESSI_97,
  ESSI_98,
  ESSI_99,  //70
  ESSI_245,
  ESSI_246,
  ESSI_247,
  ESSI_248,
  ESSI_249,  //75
  ESSI_250, 
  ESSI_251,
  ESSI_252,
  ESSI_253,
  ESSI_254,
  ESSI_255,  // 80
  ESSI_256,
  ESSI_257,
  ESSI_258,
  ESSI_259,
  ESSI_260,  //85
  ESSI_282,
  ESSI_283,
  ESSI_284,
  ESSI_285,
  ESSI_286,  //90
  ESSI_287,
  ESSI_288,
  ESSI_289,
  ESSI_290,
  ESSI_291,  //95
  ESSI_292,
  ESSI_293,
  //unsupported essi codes
  ESSI_UNSUPPORT,

};

enum ESSIORG{
GCODETYPE,
ESSICODETYPE
};

int ESSI2G(const char *SourceFile, const char *TargetFile);
int JudgeESSIOrG(const char *fn); 

#endif
