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
#ifndef _PLANNERTASK_CORE_HH
#define _PLANNERTASK_CORE_HH
	
#include "aceSmartSoft.hh"

// include upcall interface
#include "BaseStateClientUpcallInterface.hh"
#include "CurMapClientUpcallInterface.hh"

// include communication-objects for output ports
#include <CommNavigationObjects/CommPlannerEventParameter.hh>
#include <CommNavigationObjects/CommPlannerEventResult.hh>
#include <CommNavigationObjects/PlannerEventState.hh>
#include <CommNavigationObjects/CommPlannerGoal.hh>

	
class PlannerTaskCore
:	public SmartACE::ManagedTask
,	public BaseStateClientUpcallInterface
,	public CurMapClientUpcallInterface
{
private:
	bool useDefaultState; 
	bool useLogging;
	int taskLoggingId;
	unsigned int currentUpdateCount;
	
	
	Smart::StatusCode baseStateClientStatus;
	CommBasicObjects::CommBaseState baseStateClientObject;
	Smart::StatusCode curMapClientStatus;
	CommNavigationObjects::CommGridMap curMapClientObject;
	
protected:
	virtual int execute_protected_region();
	
	virtual void updateAllCommObjects();
	
	virtual int getPreviousCommObjId();
	
	void triggerLogEntry(const int& idOffset);
	
	
	// overload and implement this method in derived classes to immediately get all incoming updates from BaseStateClient (as soon as they arrive)
	virtual void on_BaseStateClient(const CommBasicObjects::CommBaseState &input) {
		// no-op
	}
	
	// this method can be safely used from the thread in derived classes
	inline Smart::StatusCode baseStateClientGetUpdate(CommBasicObjects::CommBaseState &baseStateClientObject) const
	{
		// copy local object buffer and return the last status code
		baseStateClientObject = this->baseStateClientObject;
		return baseStateClientStatus;
	}
	// overload and implement this method in derived classes to immediately get all incoming updates from CurMapClient (as soon as they arrive)
	virtual void on_CurMapClient(const CommNavigationObjects::CommGridMap &input) {
		// no-op
	}
	
	// this method can be safely used from the thread in derived classes
	inline Smart::StatusCode curMapClientGetUpdate(CommNavigationObjects::CommGridMap &curMapClientObject) const
	{
		// copy local object buffer and return the last status code
		curMapClientObject = this->curMapClientObject;
		return curMapClientStatus;
	}
	
	// this method is meant to be used in derived classes
	Smart::StatusCode plannerEventServerPut(CommNavigationObjects::PlannerEventState &eventState);
	// this method is meant to be used in derived classes
	Smart::StatusCode plannerGoalServerPut(CommNavigationObjects::CommPlannerGoal &plannerGoalServerDataObject);

public:
	PlannerTaskCore(Smart::IComponent *comp, const bool &useDefaultState=true)
	:	SmartACE::ManagedTask(comp)
	,	useDefaultState(useDefaultState)
	,	useLogging(false)
	,	taskLoggingId(0)
	,	currentUpdateCount(0)
	,	baseStateClientStatus(Smart::SMART_DISCONNECTED)
	,	baseStateClientObject()
	,	curMapClientStatus(Smart::SMART_DISCONNECTED)
	,	curMapClientObject()
	{  }
	virtual ~PlannerTaskCore()
	{  }
	
	inline void setUpLogging(const int &taskNbr, const bool &useLogging=true) {
		this->taskLoggingId = taskNbr;
		this->useLogging = useLogging;
	}
	
	inline bool isLoggingActive() const {
		return useLogging;
	}
	
	inline int getLoggingID() const {
		return taskLoggingId;
	}
	
	inline int getCurrentUpdateCount() const {
		return currentUpdateCount;
	}
};
#endif
