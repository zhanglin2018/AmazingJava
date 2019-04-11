/*
 * ptEventDataLog.h
 *
 *  Created on: Feb 12, 2019
 *  Author: linzhang
 */

#ifndef PT_EVENT_DATA_LOG_H_
#define PT_EVENT_DATA_LOG_H_
#define HP83000_ROOT

#include <string>
#include <vector>

namespace parametricTest {



class ptEventDataLog{
public:
        static ptEventDataLog & datalogger();

        void logResultData(const std::string &resultName, const std::vector<double>& resultValue);

        void logResultData(const std::string &resultName, double resultValue);

        void logVariableData(const std::string &variableName, const std::string &variableValue);


private:
        ptEventDataLog();

        ptEventDataLog(const ptEventDataLog & rhs);

        ptEventDataLog& operator=(const ptEventDataLog & rhs);


        void initParameters();

        void doAssignmentEvent();

        void doTestEvent();

        void doActionEvent();

private:
        std::string                      dataLogFileName;
        std::string                      resultName;
        int                              testId;
        std::string                      testDescriptor;
        std::string                      testSuiteName;
        int                              siteId;
        std::vector<double>              resultValues;
        std::string                      dieXY;
        std::string                      subdieTagName;

        static ptEventDataLog*           singleton;
        static pthread_mutex_t           mutex;
};

}


#endif /* PT_EVENT_DATA_LOG_H_ */
