#ifndef _PTINIT_H_
#define _PTINIT_H_

#include <string>
#include <vector>
#include <map>
#include <set>
#include "ptCommon.h"
#include "SpmuTask.h"
#include "Poco/RWLock.h"


namespace parametricTestInternal
{
  class ptClient;
  int stFWTask(const std::string& cmd, std::string& result);
}

namespace parametricTest
{

class ptExternalInst;

// Singleton class containing the Parameter Test environment information
// and the APIs for querying and updating the information.
// NOTE: This singleton is used with the user application. All APIs are thread safe.
class ptEnvironment
{
public:
  // Get a reference to the Parametric Test environment singleton object.
  static ptEnvironment& getPtEnvironment();

  // Global debug level.
  // The default value is 0.
  static int DEBUG_LEVEL;

  // Initialize the parametric test environment, both hardware and software.
  // The sites will be in the initial operating state when the function completes.
  // NOTE: initialize() runs only when the initialization flag is set to true.
  void initialize();
  // Set initialization flag to trigger an intialization the next time initialize()
  // is invoked.
  void setInitializeFlag();
  // Query whether the environment is initialized. 
  bool isInitialized();

  // Dump the channel mapping information currently in use to the specified file.
  void dumpChannelMap( const std::string& file );

  // Reset the specified sites and their associated relays to power-on state.
  // Both AVI64 and SMU are reset.
  // The API with no parameter is for resetting all sites.
  // The API with an integer vector parameter is for resetting a list of sites.
  void reset();
  void reset(const std::vector<int>& siteList);

  // Returns bool on base of site is activated or not.
  bool siteActive(size_t site);

  // Find out AVI64 channel mode(ptPMU/ptDIGITAL)
  ptMODE getAVI64ChannelMode(int siteNum);

  // Determine online/offline state of the environment.
  // Return TRUE if both SmarTest and Parametric Test are online.
  // Return FALSE if both are offline or SmarTest is offline and Parametric Test is online.
  // SmarTest online/Parametric Test offline is illegal.
  bool online();

  // Load calibration factors of specified instrument (SMU, AVI64, external
  // instruments, etc.)
  enum CAL_FACTOR_TYPE {SMU_CAL, AVI64_CAL};
  void loadCalFactors(CAL_FACTOR_TYPE type);

  // Return the full path of the current device.
  std::string devicePath();

  // Return the SMU channel number for the specified site.
  // NOTE: If the site specified has no associated SMU channel, PT_INVALID_SITE_CHANNEL
  //       will be returned.
  int smuChannel(int site);

  // Return the site number for the specified SMU channel.
  // NOTE: If the SMU channel specified is not associated with a site, PT_INVALID_SITE_CHANNEL
  // will be returned.
  int siteNumber(int smuChannel);

  // Return the hardware type associated with the site
  // NOTE: Only AVI64 is supported currently.
  ptHARDWARE hardwareType(int site);

  // Return the pin name of the SmarTest hardware for the site
  // NOTE: If the site is not configured, an empty string is returned.
  std::string pinName(int site);

  // Return the digital pogo number for the site
  std::string digitalPogo(int site);

  // Return the SMU pogo number for the site
  std::string smuPogo(int site);

  // Return the low-leak pogo number for the site
  std::string lowLeakPogo(int site);

  // Return the portmux pogo block number for the site
  std::string portmuxPogo(int site);

  // Return the SMU board location for the site
  void location(int site, std::string& cardCage, std::string& slot);

  // Return the serial numbers of the SMU channel for the site
  void serialNumber(int site, std::string& mb, std::string& dc);

  // Return the external instrument name for specified port
  // The name returned can be used to map to an external instrument object to
  // interface to the instrument.
  std::string extInstName(const std::string& port);

  // Return a pointer to the external instrument object for the
  // specified port.
  // Return NULL if the instrument is not connected.
  ptExternalInst* ptExtInstPtr(const std::string& port);

  // Return TRUE if the environment is configured SMU only.
  bool isSMUOnly();

  ////////////////////////////////////////////
  // Functions for accessing software test board information.
  // (For internal use)
  void _getTestBoardTerminal(const std::string& compName, const std::string& termName, int& site, double& value);

private:
  // Initialize the internal data object.
  void environmentInit();

  // Map SMU channel to a site based on the SmarTest pin configuration.
  void mapSiteToSMUChannel();

  int getSMUChannel(int site);

  // Perform power-on exercises. E.g. toggle relays, check leakage, etc.
  void powerOnExercise();

  // High-level functionality check 
  void highLevelFuncCheck();

  // Extract the pin name from result of "dfpn?" and "pals?"
  bool extractPinInfo(const std::string& info, std::string& pinName, int& pinInfoIndex);

  void doResetAllSites();
  // Reset the AVI64.
  // NOTE: Must enable and activate the sites requiring reset before calling the function.
  void resetAVI64(const std::vector<int>& siteList);

  // Create pseudo-site mapping when there is no SmarTest hardware.
  void createPseudoSiteMapping();

  // Unlock resources in ptServer.
  void unlockAllResources ();

  ptEnvironment();
  ~ptEnvironment();

  //////////////////////////////////
  // Data Members
  //////////////////////////////////
  // Invoke the initialization sequence when FALSE and when the initialize()
  // member function is invoked.
  bool initialized;

  // Path of the current device.
  std::string devPath;

  // Site to SMU channel number mapping.
  // This information is based on the Parameter Test model file and the 
  // SmarTest pin configuration file.
  std::vector<int> siteToSMUChannel;

  // Read/Write lock for data in the class.
  Poco::RWLock rwLock;
  // SmarTest SiteData lock
  Poco::RWLock rwLockSite;

  ///////////////////////////////////
  // Software test board information
  class ptTestBoardInfo
  {
    public:
    std::string compName;
    std::string termName;
    int smuChannel;
    std::string compType;
    double compValue;
    
    ptTestBoardInfo()
    {
      smuChannel = -1;
      compValue = -1;
    }
  };

  // Vector of component information.
  std::vector<ptTestBoardInfo> testBoardCompInfo;
  // Map of component/terminal names to component information
  std::map< std::string, int > compTermByName;

  void readTestBoardInfo();
};

// Miscellaneous utility functions
class ptUtilFunc
{
public:
  static std::string ConvertPinStatusToString(ptPIN_STATUS status);  
};

} // end namespace parametricTest

#endif
