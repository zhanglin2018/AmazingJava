#ifndef _DATALOGGER_H_
#define _DATALOGGER_H_

#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>

#include "Poco/Mutex.h"
#include "Poco/ThreadLocal.h"

namespace parametricTest {

typedef void(*datalogStrFunc)(std::ostringstream& str, const std::string& key, const std::string& val);
typedef void(*datalogIntFunc)(std::ostringstream& str, const std::string& key, int val);
typedef void(*datalogDblFunc)(std::ostringstream& str, const std::string& key, double val);
typedef void(*datalogVectorStrFunc)(std::ostringstream& str, const std::string& key, const std::vector<std::string>& val);
typedef void(*datalogVectorIntFunc)(std::ostringstream& str, const std::string& key, const std::vector<int>& val);
typedef void(*datalogVectorDblFunc)(std::ostringstream& str, const std::string& key, const std::vector<double>& val);
typedef void(*datalogDisplayMsgFunc)(const std::string& threadid, const std::string msg, std::ofstream* fileStream);

class ptDatalog
{
public:
    // Get a reference to the datalogger
    static ptDatalog& datalogger();

    // Open the log file.
    // The log file name is <fileBaseName>_<timestamp>[.<suffix>]
    void open(const std::string& fileBaseName, const std::string& suffix="");
    // Close the log file
    void close();

    // Output the key/value pair to the log file.
    void logData(const std::string& key, const std::string& val);
    void logData(const std::string& key, int val);
    void logData(const std::string& key, double val);
    void logData(const std::string& key, const std::vector<std::string>& val);
    void logData(const std::string& key, const std::vector<int>& val);
    void logData(const std::string& key, const std::vector<double>& val);

    // Specify a customizable output function for outputting string
    // integer and double values.
    void setDatalogFunc(datalogStrFunc func);
    void setDatalogFunc(datalogIntFunc func);
    void setDatalogFunc(datalogDblFunc func);
    void setDatalogFunc(datalogVectorStrFunc func);
    void setDatalogFunc(datalogVectorIntFunc func);
    void setDatalogFunc(datalogVectorDblFunc func);
    // Specify a customizable display function.
    void setDatalogFunc(datalogDisplayMsgFunc func);

    // Output the specified message to the display. 
    // "optionalKey" is an optional string that forms part of the message identifier.
    void displayMsg(const std::string& msg, const std::string& optionalKey="");
    // Output the display messages to both the display and the log file when
    // set to TRUE.
    void logDisplayMsg(bool logToFile);
    // Output the log data to both the display and the log file when set to TRUE.
    void dispLogData(bool outputToDisp);

    // Return the full pathname of the log file currently opened.
    void logfileName(std::string& filename);

    // Set the run information for message output.
    // This information comes from the Test Sequencer.
    void setRunInfo(int threadId, const std::string& seqName, const std::string& subdieName, 
    				const std::string& algName, const std::string& subfuncName, 
				const std::string& subfuncAlg, const std::string& algLoc,
				const std::string& subfuncAlgLoc);

    // Format the test algorithm location for logging or display.
    static void formatTestAlgLocation(const std::string& part1Loc, const std::string& part2Loc,
    									std::string& finalLoc);

private:
    ptDatalog();
    ~ptDatalog();

    std::string logFileName;
    std::ofstream fileStream;

    datalogStrFunc strOutputFunc;
    datalogIntFunc intOutputFunc;
    datalogDblFunc dblOutputFunc;
    datalogVectorStrFunc vecStrOutputFunc;
    datalogVectorIntFunc vecIntOutputFunc;
    datalogVectorDblFunc vecDblOutputFunc;
    datalogDisplayMsgFunc displayMsgOutputFunc;

    std::string getTimeStamp();
    void formatID(const std::string& optionalKey, std::stringstream& id);

    Poco::Mutex mMutex;
    bool mLogDspMsg;
    bool mDspLogData;

    // The following run information comes from the Test Sequencer.
    // It indicates which algorithm is currently being run in the thread.
    // Since the Test Sequencer runs the test algorithms in multiple threads,
    // each thread has its own set of run information.
    Poco::ThreadLocal<int> threadID;
    Poco::ThreadLocal<std::string> subDieName;
    Poco::ThreadLocal<std::string> subDieAlgName;
    Poco::ThreadLocal<std::string> subFuncName;
    Poco::ThreadLocal<std::string> subFuncAlgName;
    Poco::ThreadLocal<std::string> sequenceName;
    Poco::ThreadLocal<std::string> algLocation;
    Poco::ThreadLocal<std::string> subfuncAlgLocation;
};

};

#endif

