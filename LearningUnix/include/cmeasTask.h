//*************************************************************************************************
// This is a header file for sawtooth CMEAS_TASK class
//*************************************************************************************************
#ifndef __CMEAS_TASK_H__
#define __CMEAS_TASK_H__

#include <string>
#include <vector>
#include "ptCommon.h"
namespace parametricTestInternal
{
   class CMEAS_TASK_IMPL;
}

namespace parametricTest
{
class CMEAS_TASK
{
public:
   CMEAS_TASK();
   ~CMEAS_TASK();

   /***********************************************************************************************
    * Defines pin-pairs to measure with LCR meters.
    * This function must be called once and can be called multiple times to add pins to the list
    **********************************************************************************************/
   CMEAS_TASK& pin(const int                       highPin,  const int                       lowPin);
   CMEAS_TASK& pin(const std::vector<int>&         highPins, const std::vector<int>&         lowPins);
   CMEAS_TASK& pin(const std::string&              highPin,  const std::string&              lowPin);
   CMEAS_TASK& pin(const std::vector<std::string>& highPins, const std::vector<std::string>& lowPins);

   /***********************************************************************************************
    * Defines the frequencey to use with the last defined pin-pairs. Default is 10KHz.
    **********************************************************************************************/
   CMEAS_TASK& frequency(const double frequency);

   /***********************************************************************************************
    * Sets the LCR AC level. Default is 100mV if not called
    **********************************************************************************************/
   CMEAS_TASK& vrms(const double vrms);

   /***********************************************************************************************
    * Sets DC bias voltage which the LCR meter will have on its terminal. Default is 0
    **********************************************************************************************/
   CMEAS_TASK& bias(const double bias);

   /***********************************************************************************************
    * Sets the LCR meter aperture(SHORT,MEDIUM,LONG), default is MEDIUM
    **********************************************************************************************/
   CMEAS_TASK& aperture(ptS_TIME aperture);

   /***********************************************************************************************
    * Sets the LCR meter average rate(1~256), default is 4
    **********************************************************************************************/
   CMEAS_TASK& average(const int average);

   /***********************************************************************************************
    * Sets the LCR meter settling time, default is 1ms
    **********************************************************************************************/
   CMEAS_TASK& settling(const double wait);

   /***********************************************************************************************
    * Sets unique id for this measurement to lookup calibration offset
    **********************************************************************************************/
   void uid(const std::string& uid);

   /***********************************************************************************************
    * Activates the LCR meters and relay connections
    * to make capacitance and conductance measurements
    **********************************************************************************************/
   void execute();

   /***********************************************************************************************
    * Returns the compensated capacitance value of the pin-pair from execute() function
    **********************************************************************************************/
   double getCval(const int highPin, const int lowPin);
   double getCval(const std::string& gangedHighPin, const std::string& gangedLowPin);

   /***********************************************************************************************
    * Returns the compensated conductance value of the pin-pair from the execute() function
    **********************************************************************************************/
   double getGval(const int highPin, const int lowPin);
   double getGval(const std::string& gangedHighPin, const std::string& gangedLowPin);

   /***********************************************************************************************
    * Returns the LCR meter status value of the pin-pair from the execute() function
    **********************************************************************************************/
   ptPIN_STATUS getPinStatus(const int highPin, const int lowPin);
   ptPIN_STATUS getPinStatus(const std::string& gangedHighPin, const std::string& gangedLowPin);

   /***********************************************************************************************
    * Generates open-compensation factors using the LCR meters
    **********************************************************************************************/
   void runOpenCal(double lowLimit = 50e-15, double highLimit = 50e-12);

   /***********************************************************************************************
    * Checks whether the open-calibration factor
    * for a given pin-pair exists in the Open-Calibration table
    **********************************************************************************************/
   static bool isOpenCalInCalTable(
         const int hiPin,
         const int loPin,
         double f = 10e3,
         std::string uid = "");
   static bool isOpenCalInCalTable(
         const std::string& hiPin,
         const std::string& loPin,
         double f = 10e3,
         std::string uid = "");

   /***********************************************************************************************
    * clear object
    **********************************************************************************************/
   void clear();

   /***********************************************************************************************
    * Serial mode on/off 
    **********************************************************************************************/
   void serial(bool = true);

   /***********************************************************************************************
    *  For debug
    **********************************************************************************************/
   int DEBUG_LEVEL;

   /***********************************************************************************************
    * Dump PinPairSetups
    **********************************************************************************************/
   void dmpPins();

   friend parametricTestInternal::CMEAS_TASK_IMPL* dbgCmeasTaskGetImpl( CMEAS_TASK& sInst );

private:
   parametricTestInternal::CMEAS_TASK_IMPL *m_ptr;
   CMEAS_TASK(const CMEAS_TASK&); // Disallowed
   CMEAS_TASK& operator=(const CMEAS_TASK&);  // Disallowed
};
}
#endif  // __CMEAS_TASK_H__
