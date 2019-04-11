#!/opt/gss/python3/bin/python3 -B
'''
 @copyright: Advantest America Inc. 2017
 
 @file   pt_maint_report.py
 
 @author STS R&D
 
 @date   Feb 2017
 
 @brief
         the classes in ptMaintReport module: generate various report file:
         *QIS file for PT-DIAG (XML-based)
         *Sunday format file for PT-PV or PT-NIST
         *CSV format file for all activites
 
 @history
        initial version, Feb 2017

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
class ptMaintQISReport

Responsible for the QIS file report generation
based on the DB file
  
'''
class ptMaintQISReport:
    def __init__(self, dbFileName, outputFileName):
                    
        self.mDBFileName = dbFileName
        self.mOutputFileName = os.path.abspath(outputFileName)
                
    def generate(self):
                
        if not (os.path.exists(self.mDBFileName) and os.path.isfile(self.mDBFileName) ) :            
            return -1    
                
        jsonSetting = '{"files" : ["xml,%s"]}' % ( self.mOutputFileName )         
        
        return APIFunctions.generateReport(self.mDBFileName, jsonSetting)
    
        
        
'''
class ptMaintSundayReport

Responsible for the Sunday format file report generation
based on the DB file
  
'''
class ptMaintSundayReport:
    def __init__(self, dbFileName, outputFileName):
                    
        self.mDBFileName = dbFileName
        self.mOutputFileName = os.path.abspath(outputFileName)
                
    def generate(self):
                
        if not (os.path.exists(self.mDBFileName) and os.path.isfile(self.mDBFileName) ) :            
            return -1    
                
        jsonSetting = '{"files" : ["sunday,%s"]}' % ( self.mOutputFileName )         
        
        return APIFunctions.generateReport(self.mDBFileName, jsonSetting)


'''
class ptMaintCSVReport

Responsible for the Sunday format file report generation
based on the DB file
  
'''
class ptMaintCSVReport:
    def __init__(self, dbFileName, outputFileName):
                    
        self.mDBFileName = dbFileName
        self.mOutputFileName = os.path.abspath(outputFileName)
                
    def generate(self):
                
        if not (os.path.exists(self.mDBFileName) and os.path.isfile(self.mDBFileName) ) :            
            return -1    
                
        jsonSetting = '{"files" : ["csv,%s"]}' % ( self.mOutputFileName )         
        
        return APIFunctions.generateReport(self.mDBFileName, jsonSetting)
    
pt_report_dir = "/var/opt/parametricTest/maintenance.report/"
