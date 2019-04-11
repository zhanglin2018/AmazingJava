#!/opt/gss/python3/bin/python3 -B
'''
 @copyright: Advantest America Inc. 2016
 
 @file   APIFunctions.py
 
 @author STS R&D
 
 @date   Jan 2016
 
 @brief
         the APIFunctions class -- a singleton for xmlrpc access to the server
 
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
import xmlrpc.client

import pt_maint_activity as ptm


gInitialized = False
gXmlrpcClientProxy_MaintServer = None
gXmlrpcClientProxy_TestResultServer = None
gRegTaskNameSet = set()
gSystemActivitySet = set()

def initialize():
    #print("APIFunctions.initialize is called")
    
    global gXmlrpcClientProxy_MaintServer
    global gXmlrpcClientProxy_TestResultServer
    global gRegTaskNameSet
    global gSystemActivitySet
    global gInitialized
        
    ptMaintServerURL = "http://" + socket.gethostname() + ":25012/RPC2"        
    gXmlrpcClientProxy_MaintServer = xmlrpc.client.ServerProxy(ptMaintServerURL)
    
    gRegTaskNameSet = set(gXmlrpcClientProxy_MaintServer.GetAllRegisteredTasks())
    gSystemActivitySet = set(gXmlrpcClientProxy_MaintServer.GetSystemActivities())
    
    ptTestResultServerURL = "http://" + socket.gethostname() + ":25002/RPC2"
    gXmlrpcClientProxy_TestResultServer = xmlrpc.client.ServerProxy(ptTestResultServerURL)
    
    gInitialized = True
    
def isSystemActivity(activityName):
    global gInitialized
    global gSystemActivitySet
    
    if not gInitialized:
        initialize()     
    
    return (activityName in gSystemActivitySet)
                                  
def isValidTask(taskName):
    global gInitialized
    global gRegTaskNameSet
    
    if not gInitialized:
        initialize()     
        
        
    return (taskName in gRegTaskNameSet )
    
    
def addUserActivity(activity):
    global gInitialized
    global gXmlrpcClientProxy_MaintServer
    
    if not isinstance(activity, ptm.ptMaintActivity):
        raise TypeError("input parameter need to be ptMaintActivty instance") 
    
    if not gInitialized:
        initialize()     
    
    execStatus =  gXmlrpcClientProxy_MaintServer.AddUserActivity(activity.mActivityName, ','.join(activity.mTaskNameList))
    
    if execStatus != 0 :
        raise RuntimeError("can not add the user activity")
    
    pass

def executeActivity(activity): 
 
    global gInitialized
    global gXmlrpcClientProxy_MaintServer
    
    if not isinstance(activity, ptm.ptMaintActivity):
        raise TypeError("input parameter need to be ptMaintActivty instance") 
    
    if not gInitialized:
        initialize()     
    

    retValueMap =  gXmlrpcClientProxy_MaintServer.ExecuteActivity(activity.mActivityName, 1)
    
    if not isinstance(retValueMap, dict):
        raise ValueError("expect dictionary return value from ExecuteActivity xmlrpc call")
 
    activity.mResult = ptm.ptMaintActivityResult(retValueMap)
 
    pass
 
 
def executeHMCmd (cmd, smuChanNum, paramList):
 
    global gInitialized
    global gXmlrpcClientProxy_MaintServer
    
    if not isinstance(paramList, dict) :
        raise ValueError("the 3rd parameter must be a dictionary")
    
    if not gInitialized:
        initialize()     
    
    retValueMap =  gXmlrpcClientProxy_MaintServer.ExecuteSMUFW(cmd, smuChanNum, paramList)
     
    if not isinstance(retValueMap, dict):
        raise ValueError("expect dictionary return value from ExecuteSMUFW xmlrpc call")
    
    return retValueMap

def generateReport(dbFileName, outputFileSetting):
    global gInitialized
    global gXmlrpcClientProxy_TestResultServer
    
    if not gInitialized:
        initialize()     
    
    return gXmlrpcClientProxy_TestResultServer.GenerateReport(dbFileName, outputFileSetting)

