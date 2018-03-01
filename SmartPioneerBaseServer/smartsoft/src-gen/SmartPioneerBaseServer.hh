//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain
// The SmartSoft Toolchain has been developed by:
//  
// Service Robotics Research Center
// University of Applied Sciences Ulm
// Prittwitzstr. 10
// 89075 Ulm (Germany)
//
// Information about the SmartSoft MDSD Toolchain is available at:
// www.servicerobotik-ulm.de
//
// Please do not modify this file. It will be re-generated
// running the code generator.
//--------------------------------------------------------------------------
#ifndef _SMARTPIONEERBASESERVER_HH
#define _SMARTPIONEERBASESERVER_HH
	
#include <iostream>
#include "aceSmartSoft.hh"
#include "smartQueryServerTaskTrigger_T.h"
#include "SmartPioneerBaseServerCore.hh"
#include "SmartPioneerBaseServerImpl.hh"

// include communication objects
#include <CommBasicObjects/CommBasePositionUpdate.hh>
#include <CommBasicObjects/CommBasePositionUpdateACE.hh>
#include <CommBasicObjects/CommBaseState.hh>
#include <CommBasicObjects/CommBaseStateACE.hh>
#include <CommBasicObjects/CommBatteryEvent.hh>
#include <CommBasicObjects/CommBatteryEventACE.hh>
#include <CommBasicObjects/CommBatteryParameter.hh>
#include <CommBasicObjects/CommBatteryParameterACE.hh>
#include <CommBasicObjects/CommBatteryState.hh>
#include <CommBasicObjects/CommBatteryStateACE.hh>
#include <CommBasicObjects/CommNavigationVelocity.hh>
#include <CommBasicObjects/CommNavigationVelocityACE.hh>
#include <CommBasicObjects/CommVoid.hh>
#include <CommBasicObjects/CommVoidACE.hh>

// include tasks
#include "PoseUpdateTask.hh"
#include "RobotTask.hh"
// include UpcallManagers
#include "LocalizationUpdateUpcallManager.hh"
#include "NavVelInUpcallManager.hh"

// include input-handler
// include input-handler
#include "BaseStateQueryHandler.hh"

// include handler
#include "CompHandler.hh"

#include "ParameterStateStruct.hh"
#include "ParameterUpdateHandler.hh"

#include "SmartStateChangeHandler.hh"

#define COMP SmartPioneerBaseServer::instance()

class SmartPioneerBaseServer : public SmartPioneerBaseServerCore {
private:
	static SmartPioneerBaseServer _smartPioneerBaseServer;
	
	// constructor
	SmartPioneerBaseServer();
	
	// copy-constructor
	SmartPioneerBaseServer(const SmartPioneerBaseServer& cc);
	
	// destructor
	~SmartPioneerBaseServer() { };
	
	// load parameter from ini file
	void loadParameter(int argc, char* argv[]);
	
	// instantiate comp-handler
	CompHandler compHandler;
	
	Smart::TaskTriggerSubject* getInputTaskTriggerFromString(const std::string &client);
	
public:
	// component
	SmartPioneerBaseServerImpl *component;
	
	ParameterStateStruct getGlobalState() const
	{
		return paramHandler.getGlobalState();
	}
	
	// define tasks
	Smart::TaskTriggerSubject* poseUpdateTaskTrigger;
	PoseUpdateTask *poseUpdateTask;
	Smart::TaskTriggerSubject* robotTaskTrigger;
	RobotTask *robotTask;
	
	// define input-ports
	// InputPort LocalizationUpdate
	Smart::ISendServerPattern<CommBasicObjects::CommBasePositionUpdate> *localizationUpdate;
	Smart::InputTaskTrigger<CommBasicObjects::CommBasePositionUpdate> *localizationUpdateInputTaskTrigger;
	LocalizationUpdateUpcallManager *localizationUpdateUpcallManager;
	// InputPort NavVelIn
	Smart::ISendServerPattern<CommBasicObjects::CommNavigationVelocity> *navVelIn;
	Smart::InputTaskTrigger<CommBasicObjects::CommNavigationVelocity> *navVelInInputTaskTrigger;
	NavVelInUpcallManager *navVelInUpcallManager;
	
	// define request-ports
	
	// define input-handler
	
	// define output-ports
	Smart::IPushServerPattern<CommBasicObjects::CommBaseState> *basePositionOut;
	Smart::IEventServerPattern<CommBasicObjects::CommBatteryParameter, CommBasicObjects::CommBatteryEvent, CommBasicObjects::CommBatteryState,SmartACE::EventId> *batteryEventServer;
	Smart::IEventTestHandler<CommBasicObjects::CommBatteryParameter, CommBasicObjects::CommBatteryEvent, CommBasicObjects::CommBatteryState> *batteryEventServerEventTestHandler; 
	
	// define answer-ports
	Smart::IQueryServerPattern<CommBasicObjects::CommVoid, CommBasicObjects::CommBaseState,SmartACE::QueryId> *baseStateQueryServer;
	Smart::QueryServerTaskTrigger<CommBasicObjects::CommVoid, CommBasicObjects::CommBaseState,SmartACE::QueryId> *baseStateQueryServerInputTaskTrigger;
	
	// define request-handlers
	BaseStateQueryHandler *baseStateQueryHandler;
	
	// define default slave ports
	SmartACE::StateSlave *stateSlave;
	SmartStateChangeHandler *stateChangeHandler;
	SmartACE::WiringSlave *wiringSlave;
	ParamUpdateHandler paramHandler;
	SmartACE::ParameterSlave *param;
	
	
	void init(int argc, char *argv[]);
	void run();
	
	void setStartupFinished();
	Smart::StatusCode connectAndStartAllServices();
	void startAllTasks();
	void startAllTimers();
	

	// return singleton instance
	static SmartPioneerBaseServer* instance()
	{
		return (SmartPioneerBaseServer*)&_smartPioneerBaseServer;
	}
	
	// connections parameter
	struct connections_struct
	{
		// component struct
		struct component_struct
		{
			// the name of the component
			std::string name;
			std::string initialMainState;
			std::string defaultScheduler;
			bool useLogger;
		} component;
		
		//--- task parameter ---
		struct PoseUpdateTask_struct {
			double minActFreq;
			double maxActFreq;
			std::string trigger;
			// only one of the following two params is 
			// actually used at run-time according 
			// to the system config model
			double periodicActFreq;
			// or
			std::string inPortRef;
			int prescale;
			// scheduling parameters
			std::string scheduler;
			int priority;
			int cpuAffinity;
		} poseUpdateTask;
		struct RobotTask_struct {
			// scheduling parameters
			std::string scheduler;
			int priority;
			int cpuAffinity;
		} robotTask;
		
		//--- upcall parameter ---
		
		//--- server port parameter ---
		struct BasePositionOut_struct {
				std::string serviceName;
		} basePositionOut;
		struct BaseStateQueryServer_struct {
				std::string serviceName;
		} baseStateQueryServer;
		struct BatteryEventServer_struct {
				std::string serviceName;
		} batteryEventServer;
		struct LocalizationUpdate_struct {
				std::string serviceName;
		} localizationUpdate;
		struct NavVelIn_struct {
				std::string serviceName;
		} navVelIn;
	
		//--- client port parameter ---
	} connections;
};
#endif
