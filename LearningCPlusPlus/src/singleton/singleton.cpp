/*
 * datalogToEDL.cpp
 *
 * Created on: Jan 29, 2019
 * Author: linzhang
 */

#include "ptEventDataLog.h"
#include "tpi_c.h"
#include "libcicpi.h"
#include "TMLimits.h"
#include "dcl.h"
#include <iostream>
#include <stdexcept>

using namespace std;
using namespace parametricTest;
using V93kLimits::tmLimits;

ptEventDataLog* ptEventDataLog::singleton = NULL;
pthread_mutex_t ptEventDataLog::mutex;

ptEventDataLog & ptEventDataLog::datalogger()
{
  if (singleton == NULL) {
    pthread_mutex_lock(&mutex);
    if (singleton == NULL) {
      singleton = new ptEventDataLog();
    }
    pthread_mutex_unlock(&mutex);
  }

  return *singleton;
}

ptEventDataLog::ptEventDataLog()
{
  dataLogFileName = "/tmp/example.out";
  resultName = "";
  testId = 0;
  testDescriptor = "";
  testSuiteName = "";
  siteId = 0;
  dieXY = "";
  subdieTagName = "";
}

void ptEventDataLog::initParameters()
{
  //init testsuiteName
  char suiteName[CI_CPI_MAX_TESTSUITE_LEN];

  if (GetTestsuiteName(suiteName) == 1) {
    throw runtime_error("Error: can not get the correct test suite name. ");
  }
  testSuiteName = string(suiteName);

  //init test ID or test number
  testId = GetTestNumber();
}

void ptEventDataLog::logResultData(const std::string &resultName,
    const std::vector<double>& resultValue)
{
  this->resultName = resultName;
  resultValues.clear();
  resultValues.assign(resultValue.begin(), resultValue.end());
  initParameters();

  doTestEvent();
}

void ptEventDataLog::logResultData(const std::string &resultName,
    double resultValue)
{
  this->resultName = resultName;
  resultValues.clear();
  resultValues.push_back(resultValue);
  initParameters();

  doTestEvent();
}

void ptEventDataLog::logVariableData(const std::string &variableName,
    const std::string &variableValue)
{

}

void ptEventDataLog::doTestEvent()
{
  DCLStart(NULL);

  cout << "testName: " << resultName.c_str() << endl;
  cout << "testSuiteName: " << testSuiteName.c_str() << endl;
  cout << "testDescriptor: " << testDescriptor.c_str() << endl;
  cout << "testId: " << testId << endl;
  cout << "siteId: " << siteId << endl;

  DCLEvent event;
  DCLAttribute attribute = DCLMakeTestNameAttr(resultName.c_str());
  event = DCLMakeEvent(TestEventType, 1, &attribute);

  attribute = DCLMakeAttribute(TestSuiteNameAttrType, testSuiteName.size() + 1,
      testSuiteName.c_str());
  event = DCLAddAttributes(1, &attribute, event);

  attribute = DCLMakeSiteIdAttr(siteId);
  event = DCLAddAttributes(1, &attribute, event);

  attribute = DCLMakeParaOrFuncTestAttr(TEST_TYPE_PARAMETRIC);
  event = DCLAddAttributes(1, &attribute, event);

  attribute = DCLMakeAttribute(TestDescriptionAttrType,
      testDescriptor.size() + 1, testDescriptor.c_str());
  event = DCLAddAttributes(1, &attribute, event);

  attribute = DCLMakeTestIdAttr(testId);
  event = DCLAddAttributes(1, &attribute, event);

  LIMIT limit;
  double min, max;
  char min_rel, max_rel;
  std::string unit = limit.unit();
  limit.getLow(&min);
  limit.getHigh(&max);

  attribute = DCLMakePassRangeAttr(min, min_rel, max_rel, max, unit.c_str());
  event = DCLAddAttributes(1, &attribute, event);

  std::string unit1;
  std::vector<double>::iterator iter;
  for (iter = resultValues.begin(); iter != resultValues.end(); iter++) {
    attribute = DCLMakeValueResultAttr(*iter, unit1.c_str(),
        testDescriptor.c_str());
    event = DCLAddAttributes(1, &attribute, event);
  }

  DCLLogEvent(event);
  DCLFreeEvent(event);

  DCLStop();
}

void ptEventDataLog::doAssignmentEvent()
{

}

void ptEventDataLog::doActionEvent()
{

}

