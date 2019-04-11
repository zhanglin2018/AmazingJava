#ifndef __AUX_TASK_H__
#define __AUX_TASK_H__

#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>
#include "ptCommon.h"

using std::string;
using std::vector;

namespace parametricTest
{
    class AUX_TASK_IMPL;

    class AUX_TASK
    {
    private:
        boost::shared_ptr<AUX_TASK_IMPL> pimpl;

    public:
        AUX_TASK();
        AUX_TASK& pin(int pin);
        AUX_TASK& pin(const vector<int>& pins);
        AUX_TASK& pin(const string& pins);
        AUX_TASK& port(ptPortMux port);
        void execute();

        int DEBUG_LEVEL;
    };
}
#endif  // __AUX_TASK_H__

// Local Variables:
// c-basic-offset: 4
// End:
