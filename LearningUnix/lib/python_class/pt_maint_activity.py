#!/opt/gss/python3/bin/python3 -B
'''
 @copyright: Advantest America Inc. 2016
 
 @file   ptMaintActivity.py
 
 @author STS R&D
 
 @date   Jan 2016
 
 @brief
         the ptMaintActivity class
 
 @history
        initial version, Jan 2016

'''

import socket
import re
from pprint import pprint
import cProfile
import logging
import os
import time
import datetime


import APIFunctions 



'''
class ptMaintActivity

used to define and run the maintenance Activity (system, user-defined)
  
'''
class ptMaintActivity:
    def __init__(self, activityName):
                    
        self.mActivityName = activityName
        self.mTaskNameList = []
        self.mResult = ptMaintActivityResult({})
        
        
    def add(self, taskName):
                
        if  APIFunctions.isSystemActivity(self.mActivityName):
            raise ValueError("can not add task to system-provided activity: " + self.mActivityName)
  
        if not APIFunctions.isValidTask(taskName):
            raise ValueError("task name: " + taskName + " is not supported")
        
        taskNameSet = set(self.mTaskNameList)
        
        if taskName in taskNameSet :
            raise ValueError("task name: " + taskName + " already exist; can not be added again")

        self.mTaskNameList.append(taskName)
        
        return self
    
    
    def execute(self):
        
        if not APIFunctions.isSystemActivity(self.mActivityName) :            
            if len(self.mTaskNameList) == 0 :             
                raise ValueError("no Task added to user Activity: " + self.mActivityName)
        
            APIFunctions.addUserActivity(self)
            
        
        #now will execute the activity
        APIFunctions.executeActivity(self)
    
        pass
    
    
    def clear(self):        
        self.mTaskNameList = []
        self.mResult = ptMaintActivityResult({})
        
    def getResult(self):
        
        return self.mResult
    
        
class ptMaintActivityResult:
    
    def __init__(self, value):
        
        if not isinstance(value, dict):
            raise ValueError("input parameter must be a dict instance")
        
        
        self.mActivityRunResultCol = value

    def passFail(self):
        
        if "ACTIVITY" in self.mActivityRunResultCol:
            return self.mActivityRunResultCol["ACTIVITY"]

        return ""
    
    
    def taskPassFail(self, taskName):
        
        if taskName in self.mActivityRunResultCol:
            return self.mActivityRunResultCol[taskName]
        
        return ""


    def startTime(self):
        
        if "START_TIME" in self.mActivityRunResultCol:
            return self.mActivityRunResultCol["START_TIME"]
        
        return ""

    def stopTime(self):
        
        if "STOP_TIME" in self.mActivityRunResultCol:
            return self.mActivityRunResultCol["STOP_TIME"]
        
        return ""

    def testResultDB(self):
        
        if "TESTRESULT_DB" in self.mActivityRunResultCol:
            return self.mActivityRunResultCol["TESTRESULT_DB"]
        
        return ""


    #todo
    def generateCSVOutputFile(self, filename):

        pass

'''
function ptExecHMCmd

  execute the SMU FW command used by Hardware Monitor Tool 
'''
def ptExecHMCmd(cmd, smuChanNum, paramList):
    
    return APIFunctions.executeHMCmd(cmd, smuChanNum, paramList)


    
