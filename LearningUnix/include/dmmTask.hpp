#ifndef __DMM_TASK_H__
#define __DMM_TASK_H__

#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>
#include "ptCommon.h"

using std::string;
using std::vector;

namespace parametricTest
{
    class DMM_TASK_IMPL;

    class DMM_TASK
    {
    private:
        boost::shared_ptr<DMM_TASK_IMPL> pimpl;

    public:
        DMM_TASK();
        DMM_TASK& pin(int hpin, int lpin);
        DMM_TASK& pin(int hpin);
        DMM_TASK& pin(const vector<int>& hpins, const vector<int>& lpins);
        DMM_TASK& pin(const vector<int>& hpins);
        DMM_TASK& pin(const string& hpins, const string& lpins);
        DMM_TASK& pin(const string& hpins);
        DMM_TASK& vrange(double range);
        DMM_TASK& autoRange(ptRANGE auto = ptAUTO);
        DMM_TASK& nplc(double nplc);
        DMM_TASK& settling(double wait);
        void execute();
        double getResult(int pin);
        double getResult(int hpin, int lpin);
        void dmpPins();

        int DEBUG_LEVEL;
    };
}
#endif  // __DMM_TASK_H__

// Local Variables:
// c-basic-offset: 4
// End:
