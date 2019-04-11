// This is a header file for sawtooth FREQ_TASK class
#ifndef __FREQ_TASK_H__
#define __FREQ_TASK_H__

#include <string>
#include <sstream>
#include <vector>
#include "ptCommon.h"

namespace parametricTestInternal
{
class FREQ_TASK_IMPL;
}

namespace parametricTest
{

class FREQ_TASK
{
public:
   FREQ_TASK();
   ~FREQ_TASK();

   FREQ_TASK& pin(const int iPin);
   FREQ_TASK& pin(const std::vector<int>& vPins);
   FREQ_TASK& pin(const std::string& sPins);

   FREQ_TASK& hw(const ptHARDWARE inst);
   FREQ_TASK& maxFreq(const double mFreq);
   FREQ_TASK& termMode(ptTERM_MODE tMode);
   FREQ_TASK& vth(const double thresholdVtg);
   FREQ_TASK& settling(double dSettling);
   void execute();
   void clear();
   ptPIN_STATUS getPinStatus(const int pinNr);
   double getResult(const int pinNr);
   int DEBUG_LEVEL;
   void dmpPins();

private:
   parametricTestInternal::FREQ_TASK_IMPL *m_ptr;
   FREQ_TASK(const FREQ_TASK&);  // Disallowed
   FREQ_TASK& operator=(const FREQ_TASK&);  // Disallowed
};

}
#endif  // __FREQ_TASK_H__
