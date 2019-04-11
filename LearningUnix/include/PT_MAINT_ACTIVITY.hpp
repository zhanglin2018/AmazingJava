#ifndef _PT_MAINT_ACTIVITY_HPP_
#define _PT_MAINT_ACTIVITY_HPP_

/**
 *
 * Copyright by Advantest America Inc. 2015
 *
 * @file PT_MAINT_ACTIVITY.hpp
 *
 * @author STS R&D
 *
 * @date   Oct. 2015
 *
 * @brief  the header file for the PT_MAINT_ACTIVITY class
 *
 *
 * @history
 *      initial version, Oct. 2015
 *
 *
 *
 */
#include <string>
#include <vector>
#include <map>

namespace parametricTest {

class APIFunctionsMgr;
class PT_MAINT_ACTIVITY;

class PT_MAINT_ACTIVITY_RESULT {
  friend class PT_MAINT_ACTIVITY;
  friend class APIFunctionsMgr;

public:
  PT_MAINT_ACTIVITY_RESULT & operator=(const PT_MAINT_ACTIVITY_RESULT&src);

  std::string passFail();
  std::string taskPassFail(const std::string &taskName);
  std::string startTime();
  std::string stopTime();
  std::string testResultDB();
  void generateCSVOutputFile(const std::string &fileName);

  ~PT_MAINT_ACTIVITY_RESULT();

private:
  PT_MAINT_ACTIVITY_RESULT();
  PT_MAINT_ACTIVITY_RESULT(std::map<std::string, std::string> & result);
  PT_MAINT_ACTIVITY_RESULT(const PT_MAINT_ACTIVITY_RESULT & src);


private:
  std::map<std::string, std::string> mActivityRunResultCol;
};

class PT_MAINT_ACTIVITY {
  friend class APIFunctionsMgr;
public:
  PT_MAINT_ACTIVITY(const std::string &actName);
  ~PT_MAINT_ACTIVITY();

  PT_MAINT_ACTIVITY & add(const std::string &taskName);
  PT_MAINT_ACTIVITY & execute();
  PT_MAINT_ACTIVITY_RESULT &getResult();

  void clear();

private:
  std::string mActivityName;
  std::vector<std::string> mTaskNameList;
  PT_MAINT_ACTIVITY_RESULT mResult;
};



};

#endif  // end _PT_MAINT_ACTIVITY_HPP_
