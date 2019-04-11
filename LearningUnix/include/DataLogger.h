/**
 * Copyright by Advantest, 2019
 *
 * @author  linzhang
 * @date    Jan 24, 2019
 */
#ifndef DATA_LOGGER_H_
#define DATA_LOGGER_H_

typedef void(*datalogStrFunc)(std::ostringstream& str, const std::string& key, const std::string& val);
typedef void(*datalogIntFunc)(std::ostringstream& str, const std::string& key, int val);
typedef void(*datalogDoubleFunc)(std::ostringstream& str, const std::string& key, double val);
typedef void(*datalogVectorStrFunc)(std::ostringstream& str, const std::string& key, const std::vector<std::string>& val);
typedef void(*datalogVectorIntFunc)(std::ostringstream& str, const std::string& key, const std::vector<int>& val);
typedef void(*datalogVectorDoubleFunc)(std::ostringstream& str, const std::string& key, const std::vector<double>& val);
typedef void(*datalogDisplayMsgFunc)(const std::string& threadid, const std::string msg, std::ofstream* fileStream);

class DataLogger
{
public:
  static DataLogger& getDataLogger();


private:
  DataLogger();
  ~DataLogger();
  DataLogger(const DataLogger& rhs);
  DataLogger& operator = (const DataLogger& rhs);

  std::string logFileName;
  std::ofstream fileStream;

  datalogStrFunc strOutputFunc;
  datalogIntFunc intOutputFunc;
  datalogDoubleFunc dblOutputFunc;
  datalogVectorStrFunc vecStrOutputFunc;
  datalogVectorIntFunc vecIntOutputFunc;
  datalogVectorDoubleFunc vecDblOutputFunc;
  datalogDisplayMsgFunc displayMsgOutputFunc;

  Poco::Mutex mutex;
  Poco::ThreadLocal<int> threadId;
  Poco::ThreadLocal<std::string> subDieName;
  Poco::ThreadLocal<std::string> subDieAlgName;
  Poco::ThreadLocal<std::string> subFuncName;
  Poco::ThreadLocal<std::string> subFuncAlgName;
  Poco::ThreadLocal<std::string> sequenceName;
  Poco::ThreadLocal<std::string> algLocation;
  Poco::ThreadLocal<std::string> subfuncAlgLocation;

};


#endif /* HA3D7C639_74E1_4269_A557_76FFAC6F8ACE */
