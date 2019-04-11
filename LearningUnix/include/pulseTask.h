/*
 * pulseTask.h
 *
 *  Created on: Dec 3, 2015
 *      Author: R&D
 */

#ifndef PULSE_TASK_H_
#define PULSE_TASK_H_

#include <string>
#include <vector>

#include "ptCommon.h"


namespace parametricTest
{
#define  V_per_uSec   *1.000000e+06

class PULSE_TASK_IMP;

/*
 * @brief PULSE_TASK is user interface for PULSE algorithm
 */

class PULSE_TASK
{
public:
   PULSE_TASK();
   virtual ~PULSE_TASK();

   PULSE_TASK& pin(int pinNr);
   PULSE_TASK& pin(const std::vector<int>& vPinNrs);
   PULSE_TASK& pin(const std::string& sPins);
   PULSE_TASK& hw( ptHARDWARE type = ptAVI64);
   PULSE_TASK& mode(ptMODE mode = ptPMU);
   PULSE_TASK& period(int periodIndex, double time);
   PULSE_TASK& delay(int periodIndex, double time);
   PULSE_TASK& width(int periodIndex, double time);
   PULSE_TASK& amplitude(int periodIndex, double volts);
   PULSE_TASK& edgeRate(double allEdgeRates);
   PULSE_TASK& clamp(double currentValue);
   PULSE_TASK& vbase(double voltage = 0.0);
   PULSE_TASK& execute(int cycles = 1, bool freeRunning = false);

   //Debug level, copy this value from ptEnvironment::DEBUG_LEVEL
   int DEBUG_LEVEL;
   void clear();
   void dmpPins();

private:
   PULSE_TASK_IMP* mpPulseTaskImp;
   PULSE_TASK(const PULSE_TASK&);  // Disallowed
   PULSE_TASK& operator=(const PULSE_TASK&);  // Disallowed
};

}

#endif /* PULSE_TASK_H_ */
