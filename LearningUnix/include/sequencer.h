#ifndef _SEQUENCER_H_
#define _SEQUENCER_H_

#include <string>
#include <map>
#include <vector>
#include "ptCommon.h"

///////////////////////////////////////////////////////////////////////////////////////////////
// Type declaration for Test Sequencer objects
///////////////////////////////////////////////////////////////////////////////////////////////
class testAlgorithm;
typedef testAlgorithm EXEC_PARAM_MAP;

typedef int(*engine_pt)(const EXEC_PARAM_MAP &exec_param_map);
typedef std::map<std::string,engine_pt> ENGINE_MAP;

///////////////////////////////////////////////////////////////////////////////////////////////
// Global flags
///////////////////////////////////////////////////////////////////////////////////////////////
// When set to TRUE, ptSequencer will invoke safeReset() at the end of a subdie when the
// _END_SUBDIE Test Algorithm is not specified.
// The default value is TRUE. I.e. safeReset() is invoked.
extern bool ptSequencerExecSafeReset;
extern bool& pAsequencer_execSafeReset;


///////////////////////////////////////////////////////////////////////////////////////////////
// Invoke the Test Sequencer to run the Test Algorithms for the subdie identified by "tag_name".
// The Test Sequence File names are specified in 'csv_table_name'. The file name specified must
// be relative to the device directory.
// The Test Algorithm name to Test Algorithm Function mapping is specified in 'engine_lookup_map'.
// This API also accepts 
// 1. A list of Algorithm Description Files. If supplied, the information in the ADF's is used 
//    to check the test algorithm parameters for correctness when the parameters are accessed.
// 2. An algorithm selection specification. When specified, only Test Algorithms that match the
//    specification will be executed. An empty string means all Test Algorithms.
///////////////////////////////////////////////////////////////////////////////////////////////
extern void ptSequencer(const std::vector<std::string> &csv_table_name, const std::vector<std::string> &sequences,
			const std::string &tag_name, ENGINE_MAP &engine_lookup_map, 
			const std::vector<std::string> &adf, const std::string& selection);

//-------------------------------------------------------------------------
// The following APIs are older implementations of ptSequencer(). 
// This API will be removed in the next release.
//extern void pAsequencer(const std::string &csv_table_name, const std::string &tag_name, ENGINE_MAP &engine_lookup_map);

// NOTE: An error code is returned in 'errCode' when an error is encountered.
// 	 Error code: 0 if successful
//	       	     1 if warning
//	      	     2 if error
// 	 An error message will be returned if 'errMsg' points to a string object.
extern void pAsequencer(const std::string &csv_table_name, const std::string &tag_name, ENGINE_MAP &engine_lookup_map, int& errCode, std::string* errMsg=NULL);


///////////////////////////////////////////////////////////////////////////////////////////////
// Invoke the Test Sequencer to run the sub-function identified by "funcName" within a Test
// Algorithm.
///////////////////////////////////////////////////////////////////////////////////////////////
extern void ptSequencerExecuteSubfunc(const std::string& funcName);

//-------------------------------------------------------------------------
// The following API is an older implementation of ptSequencerExecuteSubfunc().
// This API will be removed in the next release.
// NOTE: An error code is returned in 'errCode' when an error is encountered.
// 	 Error code: 0 if successful
//	       	     1 if warning
//	      	     2 if error
// 	 An error message will be returned if 'errMsg' points to a string object.
extern void pAsequencer_execute_subfunc(const std::string& funcName, int& errCode, std::string* errMsg=NULL);


///////////////////////////////////////////////////////////////////////////////////////////////
// Disable asynchronous parallel execution of test algorithms when the parameter is TRUE.
///////////////////////////////////////////////////////////////////////////////////////////////
extern void ptDisableParallelExec(bool disable);


///////////////////////////////////////////////////////////////////////////////////////////////
// Return the sequencer and algorithm run information.
///////////////////////////////////////////////////////////////////////////////////////////////
extern void ptSequencerGetRunInfo(int& threadId, std::string& subdieName, std::string& algName,
						std::string& subfuncName, std::string& subfuncAlg,
						std::string& seqName, std::string& algLoc);


///////////////////////////////////////////////////////////////////////////////////////////////
// Set the sequencer debug level.
// Debug level:
//  0  :  Only report the start and end of test algorithm execution.
//  1  :  Reserve for later use.
//  2  :  Reserve for later use.
//  3  :  Output the test algorithm parameters without resolving the variable database variables.
//  4  :  Output the test algorithm parameters with the variable database variables resolved.
///////////////////////////////////////////////////////////////////////////////////////////////
extern void ptSequencerSetDebugLevel(int level);


///////////////////////////////////////////////////////////////////////////////////////////////
// Re-read all Test Sequence files the next time when the Test Sequencer is invoked.
///////////////////////////////////////////////////////////////////////////////////////////////
extern void ptSequencerRereadSeqFile();


//////////////////////////////////////////////////////////////////////////////////////////////
// Overloaded functions for saving varaible values in the variable database.
///////////////////////////////////////////////////////////////////////////////////////////////
// NOTE: The following SaveVariableValue() API will throw exception when an error is encountered
//       instead of returning an error code and an error message.
// NOTE: This is the API to use going forward.
extern void SaveVariableValue(const std::string& var_name, const std::string& var_value);
extern void SaveVariableValue(const std::string& var_name, int var_value);
extern void SaveVariableValue(const std::string& var_name, double var_value);
extern void SaveVariableValue(const std::string& var_name, const std::vector<std::string>& var_value);
extern void SaveVariableValue(const std::string& var_name, const std::vector<int>& var_value);
extern void SaveVariableValue(const std::string& var_name, const std::vector<double>& var_value);

//-------------------------------------------------------------------------
// NOTE: An error code is returned in 'errCode' when an error is encountered.
//       Error code: 0 if successful
//                   1 if failed
//       An error message will be returned if 'errMsg' points to a string object.
extern void SaveVariableValue(const std::string& var_name, const std::string& var_value, int& errCode, std::string* errMsg=NULL);
extern void SaveVariableValue(const std::string& var_name, int var_value, int& errCode, std::string* errMsg=NULL);
extern void SaveVariableValue(const std::string& var_name, double var_value, int& errCode, std::string* errMsg=NULL);
extern void SaveVariableValue(const std::string& var_name, const std::vector<std::string>& var_value, int& errCode, std::string* errMsg=NULL);
extern void SaveVariableValue(const std::string& var_name, const std::vector<int>& var_value, int& errCode, std::string* errMsg=NULL);
extern void SaveVariableValue(const std::string& var_name, const std::vector<double>& var_value, int& errCode, std::string* errMsg=NULL);


///////////////////////////////////////////////////////////////////////////////////////////////
// Overloaded functions for retrieving varaible values from the variable database.
///////////////////////////////////////////////////////////////////////////////////////////////
// NOTE: The following GetVariableValue() API will throw exception when an error is encountered
//       instead of returning an error code and an error message.
// NOTE: This is the API to use going forward.
extern void GetVariableValue(const std::string& var_name, std::string& var_value);
extern void GetVariableValue(const std::string& var_name, int& var_value);
extern void GetVariableValue(const std::string& var_name, double& var_value);
extern void GetVariableValue(const std::string& var_name, std::vector<std::string>& var_value);
extern void GetVariableValue(const std::string& var_name, std::vector<int>& var_value);
extern void GetVariableValue(const std::string& var_name, std::vector<double>& var_value);

//-------------------------------------------------------------------------
// NOTE: An error code is returned in 'errCode' when an error is encountered.
//       Error code: 0 if successful
//                   1 if failed
//       An error message will be returned if 'errMsg' points to a string object.
extern void GetVariableValue(const std::string& var_name, std::string& var_value, int& errCode, std::string* errMsg=NULL);
extern void GetVariableValue(const std::string& var_name, int& var_value, int& errCode, std::string* errMsg=NULL);
extern void GetVariableValue(const std::string& var_name, double& var_value, int& errCode, std::string* errMsg=NULL);
extern void GetVariableValue(const std::string& var_name, std::vector<std::string>& var_value, int& errCode, std::string* errMsg=NULL);
extern void GetVariableValue(const std::string& var_name, std::vector<int>& var_value, int& errCode, std::string* errMsg=NULL);
extern void GetVariableValue(const std::string& var_name, std::vector<double>& var_value, int& errCode, std::string* errMsg=NULL);


///////////////////////////////////////////////////////////////////////////////////////////////
// Function for removing the specified variable from variable database.
///////////////////////////////////////////////////////////////////////////////////////////////
// NOTE: The following ClearVariableValue() API will throw exception when an error is encountered
//       instead of returning an error code and an error message.
// NOTE: This is the API to use going forward.
extern void ClearVariableValue(const std::string& var_name);

//-------------------------------------------------------------------------
// NOTE: An error code is returned in 'errCode' when an error is encountered.
//       Error code: 0 if successful
//                   1 if failed
//       An error message will be returned if 'errMsg' points to a string object.
extern void ClearVariableValue(const std::string& var_name, int& errCode, std::string* errMsg=NULL);


///////////////////////////////////////////////////////////////////////////////////////////////
// Function for clearing the variable database.
///////////////////////////////////////////////////////////////////////////////////////////////
extern void ClearVariableDatabase();


///////////////////////////////////////////////////////////////////////////////////////////////
// Function for dumping name and value of specified variable to stdout.
///////////////////////////////////////////////////////////////////////////////////////////////
extern void DumpVariableValue(const std::string& var_name);


///////////////////////////////////////////////////////////////////////////////////////////////
// Function for dumping the contents of the database to the specified file.
// The output will be dumped to stdout if no file name is specified.
// Return 1 if failed to open the specified file. Otherwise return 0.
///////////////////////////////////////////////////////////////////////////////////////////////
extern int DumpVariableDatabase(const std::string& file_name="");


///////////////////////////////////////////////////////////////////////////////////////////////
// Overloaded functions for retrieving values for a Test Sequence parameter.
//
// There are 6 versions:
// 1. Return a vector of strings
// 2. Return a vector of doubles
// 3. Return a vector of integers
// 4. Return a string
// 5. Return a double
// 6. Return a integer
// The first 3 versions should be used whenever possible since they are the most
// flexible. When using the first 3 versions, a Test Algorithm does not need to 
// care if the parameter is a single value or a list of values. The function 
// automatically breaks the parameter into separate components.
///////////////////////////////////////////////////////////////////////////////////////////////
// NOTE: The following GetptSequenceValue() API will throw exception when an error is encountered.
extern void GetptSequenceValue( const EXEC_PARAM_MAP& params, const std::string& key, std::vector<std::string>& value );
extern void GetptSequenceValue( const EXEC_PARAM_MAP& params, const std::string& key, std::vector<int>& value );
extern void GetptSequenceValue( const EXEC_PARAM_MAP& params, const std::string& key, std::vector<double>& value );
extern void GetptSequenceValue( const EXEC_PARAM_MAP& params, const std::string& key, std::string& value );
extern void GetptSequenceValue( const EXEC_PARAM_MAP& params, const std::string& key, int& value );
extern void GetptSequenceValue( const EXEC_PARAM_MAP& params, const std::string& key, double& value );

//-------------------------------------------------------------------------
// The following APIs are older implementations of GetptSequenceValue().
// These APIs will be removed in the next release.
//extern void GetpASequenceValue( const EXEC_PARAM_MAP& params, const std::string& key, std::vector<std::string>& value );
//extern void GetpASequenceValue( const EXEC_PARAM_MAP& params, const std::string& key, std::vector<int>& value );
//extern void GetpASequenceValue( const EXEC_PARAM_MAP& params, const std::string& key, std::vector<double>& value );
//extern void GetpASequenceValue( const EXEC_PARAM_MAP& params, const std::string& key, std::string& value );
//extern void GetpASequenceValue( const EXEC_PARAM_MAP& params, const std::string& key, int& value );
//extern void GetpASequenceValue( const EXEC_PARAM_MAP& params, const std::string& key, double& value );

// NOTE: An error code is returned in 'errCode' when an error is encountered.
//       Error code: 0 if successful
//                   1 if failed
// NOTE: An error message will be returned if 'errMsg' points to a string object.
extern void GetpASequenceValue( const EXEC_PARAM_MAP& params, const std::string& key, std::vector<std::string>& value , int& errCode, std::string* errMsg=NULL );
extern void GetpASequenceValue( const EXEC_PARAM_MAP& params, const std::string& key, std::vector<int>& value, int& errCode, std::string* errMsg=NULL );
extern void GetpASequenceValue( const EXEC_PARAM_MAP& params, const std::string& key, std::vector<double>& value, int& errCode, std::string* errMsg=NULL );
extern void GetpASequenceValue( const EXEC_PARAM_MAP& params, const std::string& key, std::string& value, int& errCode, std::string* errMsg=NULL );
extern void GetpASequenceValue( const EXEC_PARAM_MAP& params, const std::string& key, int& value, int& errCode, std::string* errMsg=NULL );
extern void GetpASequenceValue( const EXEC_PARAM_MAP& params, const std::string& key, double& value, int& errCode, std::string* errMsg=NULL );


///////////////////////////////////////////////////////////////////////////////////////////////
// Check if a Test Sequence parameter exists.
// Returns TRUE if the parameter exists. Otherwise returns FALSE.
///////////////////////////////////////////////////////////////////////////////////////////////
extern bool CheckptSequenceValueExist( const EXEC_PARAM_MAP& params, const std::string& key );





///////////////////////////////////////////////////////////////////////////////////////////////
namespace parametricTest
{
  ///////////////////////////////////////////////////////////////////////////////////////////////
  // Resource locking object.
  // Locks the pins/sites and external instruments for parallel execution of Test Algorithms.
  ///////////////////////////////////////////////////////////////////////////////////////////////
  class ptResourceLockImpl;

  class ptResourceLock
  {
  public:
    ptResourceLock();
    ~ptResourceLock();

    ptResourceLock& pin(int pin);
    ptResourceLock& pin(const std::vector<int>& pin);

    ptResourceLock& reserve(ptHARDWARE inst);
    ptResourceLock& reserve(const std::vector<ptHARDWARE>& inst);

    ptResourceLock& share(int pin);
    ptResourceLock& share(const std::vector<int>& pin);

    void lock();

    // Debug level. Copy the value of ptEnvironment::DEBUG_LEVEL on creation.
    int DEBUG_LEVEL;

  private:
    ptResourceLockImpl* m_ptr;
  };


  ///////////////////////////////////////////////////////////////////////////////////////////////
  // Timer object.
  ///////////////////////////////////////////////////////////////////////////////////////////////
  class ptDeltaTimer
  {
  public:
     ptDeltaTimer();
    ~ptDeltaTimer();

    // Record the start time and clear the stop time.
    void start();
    // Record the stop time.
    void stop();
    // Return time between start and stop in seconds.
    double getTime();

  private:
    double startTime;
    double stopTime;
  };

}; // parametricTest namespace


#endif

