// This is a header file for sawtooth PAMU_TASK class
#ifndef __PAMU_TASK_H__
#define __PAMU_TASK_H__

#include <string>
#include <sstream>
#include <vector>
#include "ptCommon.h"

namespace parametricTestInternal
{
class PAMU_TASK_IMPL;
}

namespace parametricTest
{

class PAMU_TASK
{
public:
   PAMU_TASK();
   ~PAMU_TASK();

   /**
    * @brief  Specify single pin on which DC actions are to be performed
    * @param  pinNr pin number. e.g. pin(1)
    * @return reference to current object
    */
   PAMU_TASK& pin(const int pinNr);
   /**
    * @brief Specify pin or pin list name on which DC actions are to be performed
    * @param pinNr pin number or pin numbers separated by comma. e.g. pin("1,2,3")
    * @return reference to current object
    */
   PAMU_TASK& pin(const std::string& pinNr);
   /**
    * @brief Specify pin or pin list name on which DC actions are to be performed
    * @param pinNr Vector type object name which contains pin number or numbers.
    *             vector<int> drain_pin
    *             drain_pin.push_back(1)
    *             pin(drain_pin)
    * @return reference to current object
    */
   PAMU_TASK& pin(const std::vector<int>& pinNr);

   /**
    * @brief Assign/Designate the instrument to pin or pin list.
    * @param Instrument HW in string or enum. Options are:
    * Options are:
    *  - ptSMU   or "SMU"
    *  - ptAVI64 or "AVI64"
    * @return reference to current object
    */
   PAMU_TASK& hw(const ptHARDWARE inst);
   PAMU_TASK& hw(const std::string& inst);

   /**
    * @brief DC action to be performed on the pin
    * @param mode Mode in string or enum.
    * Options are:
    *  - ptVFIM or "VFIM"
    *  - ptIFVM or "IFVM"
    *  - ptVFVM or "VFVM"
    *  - ptIFIM or "IFIM"
    *  - ptVF   or "VF"
    *  - ptIF   or "IF"
    *  - ptVM   or "VM"
    *  @return reference to current object
    */
   PAMU_TASK& mode(const ptMODE mode);
   PAMU_TASK& mode(const std::string& mode);

   /**
    * @brief Specify force value on the pin
    * @param dForce value to be forced.
    *  - In VFIM mode Force Voltage (V)
    *  - In IFVM mode Force Current (A)
    * @return reference to current object
    */
   PAMU_TASK& force(const double dForce);

   /**
    * @brief User defined clamp value
    * @param dClamp clamp value,
    *  - In VFIM clamp is current value(A)
    *  - In IFVM clamp is voltage value(V)
    * @return reference to current object
    */
   PAMU_TASK& clamp(const double dClamp);

   /**
    * @brief User selected range for fixed V range.
    * @return reference to current object
    */
   PAMU_TASK& vrange(const double dVRange);

   /**
    * @brief User selected range for fixed I range.
    * @return reference to current object
    */
   PAMU_TASK& irange(const double dIRange);

   /**
    * @brief Specify autoRange mode for ptVFIM mode. Not effective in all other modes
    * Options are:
    * - ptAUTO  or "AUTO"
    * - ptFIXED or "FIXED"
    * @return reference to current object
    */
   PAMU_TASK& autoRange(const ptRANGE ar);
   PAMU_TASK& autoRange(const std::string& ar);

   /**
    * @brief Min determines minumum measurement range in mode(ptVFIM).autoRange(ptAUTO) mode.
    *        Not effective in all other modes.
    * @param dMin Min value:
    *  - In VFIM min current range
    * @return reference to current object
    */
   PAMU_TASK& min(const double dMin);

   /**
    * @brief  Kept for compatibility.No effect.
    * @return reference to current object
    */
   PAMU_TASK& max(const double dMax);

   /**
    * @brief  Kept for compatibility.No effect.
    * @return reference to current object
    */
   PAMU_TASK& startMR(const double dMR);

   /**
    * @brief Specify the number of samples for averaging.
    * @param iSamples Sample numbers for averaging
    * @return reference to current object
    */
   PAMU_TASK& samples(const int iSamples);

   /**
    * @brief Specify the averaging time.
    * @param averaging time
    * @return reference to current object
    */
   PAMU_TASK& samples(const double averagingTime);

   /**
    * @brief Overloaded function to specify the number of samples for averaging.
    * Options are:
    * - ptSHORT  or "SHORT"
    * - ptMEDIUM or "MEDIUM"
    * - ptLONG   or "LONG"
    * @return reference to current object
    */
   PAMU_TASK& samples(const ptS_TIME speed_option);
   PAMU_TASK& samples(const std::string& speed_option);

   /**
    * @brief Specify hold time after force
    * @param dTime hold time.
    * @return reference to current object
    */
   PAMU_TASK& hold(const double dTime);

   /**
    * @brief Specify settling time
    * @param dSettling Settling time in second
    * @return reference to current object
    */
   PAMU_TASK& settling(double dSettling);

   /**
    * @brief Overloaded function to specify the settling time.
    * Options are:
    * - ptSHORT  or "SHORT"
    * - ptMEDIUM or "MEDIUM"
    * - ptLONG   or "LONG"
    * @return reference to current object
    */
   PAMU_TASK& settling(const ptS_TIME speed_option);
   PAMU_TASK& settling(const std::string& speedOption);

   /**
    * @brief Specify fine voltage force setting
    *  - true  : turn on  fine voltage force mode
    *  - false : turn off fine voltage force mode
    *  - default is false
    * @return reference to current object
    */
   PAMU_TASK& fineVoltageForce(const bool bFine);

   /**
    * @brief Specify sense pin number on which FSS(Force Sense Split) mode will be performed
    * @return reference to current object
    */
   PAMU_TASK& remoteSense(const int sensePinNr);

   /**
    * @brief Specify sense pin voltage resolution of FSS mode
    * @return reference to current object
    */
   PAMU_TASK& remoteResolution(const double dRemoteResolution);

   /**
    * @brief Specify adjustable maximum voltage of FSS mode
    * @return reference to current object
    */
   PAMU_TASK& remoteMaxAdjust(const double dRemoteMaxVoltAdjust);

   /**
    * @brief Specify maximum number of FSS loops before giving up
    * @return reference to current object
    */
   PAMU_TASK& remoteMaxLoops(const int maxLoops);

   /**
    * @brief Specify the number of measurements for ptSMU to make at data capturing.
    * @param numMeasurements indicates the collected data elements.
    * @return reference to current object
    */
   PAMU_TASK& digitizer(const int numMeasurements);

   /**
    * @brief Executes PAMU_TASK
    */
   void execute();

   /**
    * @brief Clear PAMU_TASK object
    */
   void clear();

   /**
    * @brief Get Status flag for pin
    * @param pinNr Pin number on which status is be retrieved
    * @return status value
    * - ptVALID          = 0
    * - ptOUTOFRANGE     = 1
    * - ptOUTOFRANGELOW  = 2
    * - ptCLAMP          = 3
    * - ptPINNOTEXIST    = 4
    * - ptHWERROR        = 5
    * - ptNOTVALID       = 6
    * - ptTARGETNOTFOUND = 7
    * - ptTEMPALARM      = 8
    * - ptNOOPENCOMP     = 9
    */
   ptPIN_STATUS getPinStatus(const int pinNr);
   ptPIN_STATUS getPinStatus(const std::string& pinNr);

   /**
    * @brief Get measurement result from pin
    * @param pinNr Pin number on which result is be retrieved
    * @return result value
    *  - Current in VFIM/IFIM mode
    *  - Voltage in IFVM/VFVM/VM mode
    */
   double getResult(const int pinNr);
   double getResult(const std::string& pinNr);

   /**
    * @brief Retrieve measurement result as well as FSS mode sensed voltage and true force voltage from pin
    * @param pinNr Pin number on which values will be retrieved
    * @param senseVoltage will have the sensed voltage from pin
    * @param trueForceVoltage will have the true force voltage from pin
    * @param measVI will have the measured voltage or current value
    */
   void getResult(const int pinNr, double& senseVoltage, double& measVI);
   void getResult(const int pinNr, double& senseVoltage, double& trueForceVoltage, double& measVI);

   /**
    * @brief Retrieve the collected measurements which are setup by digitizer(const int) member function.
    */
   void getResult(const int pinNr, std::vector<double>& measVI);
   void getResult(const int pinNr, std::vector<double>& senseVoltage, std::vector<double>& measVI);
   void getResult(const int pinNr, std::vector<double>& senseVoltage, std::vector<double>& trueForceVoltage, std::vector<double>& measVI);

   /**
    * @brief Get the measurement range in which the measurement returned by getResult() was taken for pin
    * @param pinNr Pin number on which measurement range is be retrieved
    * @return status value
    * - Current range in VFIM/IFIM mode
    * - Voltage range in IFVM/VFVM/VM mode
    */
   double getMeasRange(const int pinNr);
   double getMeasRange(const std::string& pinNr);

   /**
    * @brief Specify FSS mode pinNr 
    * @return the number of FSS loops that were required to converge
    */
   int getRemoteLoops(const int pinNr);

   /**
    * For debug
    */
   int DEBUG_LEVEL;

   /**
    *@param
    *  - 1 : print CurrTargetPins
    *  - 2 : print AllTargetPins
    */
   void dmpPins();
   char getFSSReason(const int pinNr);
   double getDigiTime(const int pinNr);

private:
   parametricTestInternal::PAMU_TASK_IMPL *m_ptr;
   PAMU_TASK(const PAMU_TASK&);  // Disallowed
   PAMU_TASK& operator=(const PAMU_TASK&);  // Disallowed
};

}
#endif  // __PAMU_TASK_H__
