//
// This is a header file for sawtooth SEARCH_IV_TASK class
//
#ifndef __SEARCH_IV_TASK_H__
#define __SEARCH_IV_TASK_H__

#include <math.h>
#include <vector>
#include "ptCommon.h"

namespace parametricTest
{

  class SEARCH_IV_TASK_IMPL;

  class SEARCH_IV_TASK
  {
  public:
    SEARCH_IV_TASK();
    ~SEARCH_IV_TASK();

    // Set a pin that other methods can modify.
    SEARCH_IV_TASK& pin(int pin);
    // Set a list of pins that other methods can modify. All pins in 
    // the list are modified at the same time.
    SEARCH_IV_TASK& pin(const std::vector<int>& pin);
    SEARCH_IV_TASK& pin(const std::string& pin);

    // Supported hardware types.
    // Specify the hardware to use when forcing a voltage or measuring 
    // a current.
    SEARCH_IV_TASK& hw(ptHARDWARE type);

    // Specify the mode.
    // Supported modes:
    // VFIM  --  Force a voltage and measure current on the same pin.
    // VF    --  Only force a voltage, no current measurement is done.
    SEARCH_IV_TASK& mode(ptMODE mode);

    // Specify a fixed force voltage.
    SEARCH_IV_TASK& force(double voltage);
    // Specify the search voltage range. Only one range is allowed per 
    // SEARCH_IV_TASK object.
    // In linear search mode, 'step' is the voltage change per measurement.
    // In binary search mode, 'step' is the smallest voltage change before
    // the search terminates.
    // NOTE: Only one search range is available per SEARCH_IV_TASK instance.
    SEARCH_IV_TASK& force(double start, double stop, double step);

    // Specify the minimum current measurement range to use for pins other than
    // the search pin. This is optional.
    // If not specified min will default to the lowest range.
    // The measurement ranges are from clamp to min. For fixed range measurement,
    // assign the same range to both clamp and min.
    SEARCH_IV_TASK& min(double minRange);

    // Specify a current clamp.
    SEARCH_IV_TASK& clamp(double dClamp);

    // Specify the number of samples for averaging.
    SEARCH_IV_TASK& samples(int nSamples);
    // Specify the speed aperture in SEARCH_IV_TASK::S_TIME.
    SEARCH_IV_TASK& samples(ptS_TIME speed);
    // Specify the integration time.
    SEARCH_IV_TASK& samples(double integrationTime);

    // Specify the hold time for the first measurement in the search.
    SEARCH_IV_TASK& hold(double time);

    // Specify the settling time period.
    SEARCH_IV_TASK& settling(double time);
    // Specify the speed aperture in SEARCH_IV_TASK::S_TIME.
    SEARCH_IV_TASK& settling(ptS_TIME speed);

    // Specify the search target.
    SEARCH_IV_TASK& searchTarget(ptSEARCH_MODE mode, double target, 
    				int maxIterations=19, double targetResolution=0, double iRange=NAN);

    // When parameter is TRUE, stop search when the search pin measurement is clamped. 
    SEARCH_IV_TASK& stopOnClamp(bool stop);
    
    // Force-sense split setup APIs
    SEARCH_IV_TASK& remoteSense(int sensePin);
    SEARCH_IV_TASK& remoteResolution(double remoteResolution);
    SEARCH_IV_TASK& remoteMaxAdjust(double remoteMaxVoltAdjust);
    SEARCH_IV_TASK& remoteMaxLoops(int maxLoops);

    // Voltage force resolution control
    SEARCH_IV_TASK& fineVoltageForce(bool fine);

    // Execute the search algorithm.
    void execute();

    // Get the final pin status.
    ptPIN_STATUS getPinStatus(int pin);
    // Get the pin status at each search iteration.
    void getPinStatus(int pin, std::vector<ptPIN_STATUS>& status);
    
    // Return the final sensed voltage and measured current.
    // One version also returns the force voltage that produces the sensed voltage
    // In force-sense split mode, sensed voltage is the measurement of the sense pin.
    // If not in force-sense split mode, sensed voltage is the same as force voltage.
    // For pins in VF mode, NaN is returned for current.
    void getResult(int pin, double& sensed, double& current);
    void getResult(int pin, double& sensed, double& force, double& current);
    // Return the sensed voltage and measured current at each iteration.
    // One version also returns the force voltage that produces the sensed voltage
    // In force-sense split mode, sensed voltage is the measurement of the sense pin.
    // If not in force-sense split mode, sensed voltage is the same as force voltage.
    // For pins in VF mode, NaN is returned for current.
    void getResult(int pin, std::vector<double>& sensed, std::vector<double>& current);
    void getResult(int pin, std::vector<double>& sensed, std::vector<double>& force,
							std::vector<double>& current);

    // Return the current range in which the final measurement was taken.
    double getMeasRange(int pin);
    // Return the current range used at each search iteration.
    void getMeasRange(int pin, std::vector<double>& range);

    // Return the number of FSS loops required to converge during the final measurement.
    int getRemoteLoops(int pin);
    // Return the number of FSS loops required to converge at each search iteration.
    void getRemoteLoops(int pin, std::vector<int>& maxLloops); 
    
    // Output the current pin settings.
    void dmpPins();

    // Debug level. Copy the value of ptEnvironment::DEBUG_LEVEL on creation.
    int DEBUG_LEVEL; 
    friend SEARCH_IV_TASK_IMPL* dbgSearchIVTaskGetImpl( SEARCH_IV_TASK& sInst );
    
    private:
    SEARCH_IV_TASK_IMPL* m_ptr;
  };
}

#endif  // __SEARCH_IV_TASK_H__
