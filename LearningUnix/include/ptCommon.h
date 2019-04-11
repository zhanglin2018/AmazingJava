#ifndef _PTCOMMON_H_
#define _PTCOMMON_H_

/////////////////////////////////////////////////////////
// Common enumerated types used in PAMU_TASK, SEARCH_IV_TASK, SWEEP_TASK, PULSE_TASK, etc.
/////////////////////////////////////////////////////////

namespace parametricTest
{

  enum ptHARDWARE
  {
    ptSMU,
    ptAVI64,
    ptAVI64_LC,
    ptLCR,
    ptDMM,
    ptAUX,
    ptILLEGAL_HW
  };
      
  enum ptMODE
  {
    ptVFIM,
    ptIFVM,
    ptVFVM,
    ptIFIM,
    ptVF,
    ptVM,
    ptIF,
    ptDISCONNECTED, // Used for tracking internal state.
    ptILLEGAL_MODE, // Used for uninitialized values.
    ptPMU,
    ptDIGITAL
  };

  enum ptS_TIME
  {
    ptSHORT,
    ptMEDIUM,
    ptLONG
  };

  enum ptPIN_STATUS
  {
    ptVALID = 0,
    ptOUTOFRANGE = 1,
    ptOUTOFRANGELOW = 2,
    ptCLAMP = 3,
    ptPINNOTEXIST = 4,
    ptHWERROR = 5,
    ptNOTVALID = 6,
    ptTARGETNOTFOUND = 7,
    ptTEMPALARM = 8,
    ptNOOPENCOMP = 9
  };

  enum ptRANGE
  {
    ptRUP,
    ptRDWN,
    ptAUTO,
    ptJDWN,
    ptFIXED
  };

  enum ptSEARCH_MODE
  {
    ptLINEAR_ABOVE,
    ptLINEAR_BELOW,
    ptBINARY
  };

  enum ptTERM_MODE
  {
     pt50OHM,
     ptHIZ
  };

  enum ptPortMux
  {
    LCR1L, LCR2L, LCR3L, LCR4L,
    DMM1L, DMM2L, DMM3L, DMM4L,
    LCR1H, LCR2H, LCR3H, LCR4H,
    DMM1H, DMM2H, DMM3H, DMM4H,
    AVI_64, AVI_64_SENSE, AUX
  };

  #define PT_INVALID_SITE_CHANNEL 0

  // Values returned by Test Sequencer APIs for a parameter or variable 
  // when an error is encountered.
  #define ptSequence_ERROR_INT -9999
  #define ptSequence_ERROR_DBL -9999.00
  #define ptSequence_ERROR_STR ""

}

#endif
