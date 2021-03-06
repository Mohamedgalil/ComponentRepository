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
// This file is generated once. Modify this file to your needs. 
// If you want the toolchain to re-generate this file, please 
// delete it before running the code generator.
//--------------------------------------------------------------------------
#ifndef _PLANNERTASK_HH
#define _PLANNERTASK_HH

#include "PlannerTaskCore.hh"

#include "smartPlannerMap.hh"
	
class PlannerTask  : public PlannerTaskCore
{
private:
	GoalFifoStructPtr goalFifoPtr;
	CommBasicObjects::CommBaseState base_state;
	CommNavigationObjects::CommGridMap currentGridMap;
	CommNavigationObjects::CommPlannerGoal plannerGoal;
	CommNavigationObjects::PlannerEventType    generalstatus;
	Smart::PlannerMapClass *plannerMap;

	// not used upcall methods (instead the methods get...(input) are used)
//	virtual void on_CurMapClient(const CommNavigationObjects::CommGridMap &input);
//	virtual void on_BaseStateClient(const CommBasicObjects::CommBaseState &input);
public:
	PlannerTask(SmartACE::SmartComponent *comp);
	virtual ~PlannerTask();
	
	virtual int on_entry();
	virtual int on_execute();
	virtual int on_exit();
};

#endif
