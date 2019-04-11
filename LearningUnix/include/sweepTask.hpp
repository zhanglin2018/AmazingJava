#ifndef __SWEEP_TASK_H__
#define __SWEEP_TASK_H__

#include <vector>
#include <boost/shared_ptr.hpp>
#include "ptCommon.h"

using std::vector;
using std::string;

namespace parametricTest
{

    class SWEEP_TASK_IMPL;

    class SWEEP_TASK
    {
    private:
        boost::shared_ptr<SWEEP_TASK_IMPL> pimpl;

    public:
        SWEEP_TASK();

        SWEEP_TASK& pin(int pin);
        SWEEP_TASK& pin(const vector<int>& pin);
        SWEEP_TASK& pin(const string& pin);
        SWEEP_TASK& hw(ptHARDWARE type);
        SWEEP_TASK& mode(ptMODE mode);
        SWEEP_TASK& force(double voltage);
        SWEEP_TASK& force(double start, double stop, double step);
        SWEEP_TASK& min(double minRange);
        SWEEP_TASK& clamp(double dClamp);
        SWEEP_TASK& samples(int nSamples);
        SWEEP_TASK& samples(ptS_TIME speed);
        SWEEP_TASK& samples(double time);
        SWEEP_TASK& hold(double time);
        SWEEP_TASK& settling(double time);
        SWEEP_TASK& settling(ptS_TIME speed);
        SWEEP_TASK& fineVoltageForce(bool fine);
        SWEEP_TASK& remoteSense(int sensePinNr);
        SWEEP_TASK& remoteResolution(double remoteResolution);
        SWEEP_TASK& remoteMaxAdjust(double remoteMaxVoltAdjust);
        SWEEP_TASK& remoteMaxLoops(int maxLoops);
        SWEEP_TASK& stopOnClamp(bool stop);

        void execute();

        void getPinStatus(int pin, vector<ptPIN_STATUS>& status);
        void getResult(int pin, vector<double>& sensed, vector<double>& current);
        void getResult(int pin, vector<double>& sensed, vector<double>& force,
                       vector<double>& current);
        void getMeasRange(int pin, vector<double>& range);
        void getRemoteLoops(int pin, vector<int>& maxLoops);
        void getFSSReason(int pin, vector<char>& reason);

        void dmpPins();
        int DEBUG_LEVEL;
    };
}

#endif  // __SWEEP_TASK_H__

// Local Variables:
// c-basic-offset: 4
// End:
