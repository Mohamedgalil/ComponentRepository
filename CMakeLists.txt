CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

FIND_FILE(SMART_MACROS SmartMacros2.cmake PATHS $ENV{SMART_ROOT_ACE}/CMakeMacros /opt/smartSoftAce/CMakeMacros)
INCLUDE(${SMART_MACROS})

#SMART_ADD_PACKAGE(SmartAmcl)
SMART_ADD_PACKAGE(SmartCdlServer)
#SMART_ADD_PACKAGE(SmartGazeboBaseServer)
#SMART_ADD_PACKAGE(SmartGMapping)
#SMART_ADD_PACKAGE(SmartHighLevelInterface)
#SMART_ADD_PACKAGE(SmartJobDispatcher)
#SMART_ADD_PACKAGE(SmartJoystickNavigation)
#SMART_ADD_PACKAGE(SmartJoystickServer)
#SMART_ADD_PACKAGE(SmartLaserLMS1xxServer)
SMART_ADD_PACKAGE(SmartLaserLMS200Server)
#SMART_ADD_PACKAGE(SmartLaserS300Server)
#SMART_ADD_PACKAGE(SmartLispServer)
SMART_ADD_PACKAGE(SmartMapperGridMap)
#SMART_ADD_PACKAGE(SmartPioneerBaseServer)
SMART_ADD_PACKAGE(SmartPlannerBreadthFirstSearch)
#SMART_ADD_PACKAGE(SmartPlayerStageSimulator)
#SMART_ADD_PACKAGE(SmartRMPBaseServer)
SMART_ADD_PACKAGE(SmartRobotConsole)
#SMART_ADD_PACKAGE(SmartSimpleKB)
#SMART_ADD_PACKAGE(SmartSymbolicPlanner)
#SMART_ADD_PACKAGE(SmartVisualization)
IF(${ROBOTINO_COMPONENTS})
  #SMART_ADD_PACKAGE(SmartRobotinoBaseServer)
  #SMART_ADD_PACKAGE(SmartRobotinoLaserServer)
  #SMART_ADD_PACKAGE(SmartRobotinoRPCBridge)
ENDIF(${ROBOTINO_COMPONENTS})
