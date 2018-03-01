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
#ifndef _PLANNERCLIENT_UPCALL_MANAGER_HH
#define _PLANNERCLIENT_UPCALL_MANAGER_HH

#include <list>
#include "aceSmartSoft.hh"
#include "PlannerClientUpcallInterface.hh"

/** PlannerClientUpcallManager connects input-handling with Upcall propagation
 *
 * This class implements an InputHandler for the InputPort PlannerClient and propagates the handling 
 * of incoming data to all associated (i.e. attached) Upcalls.
 */
class PlannerClientUpcallManager
:	public Smart::IInputHandler<CommNavigationObjects::CommPlannerGoal>
{
private:
	// list of associated updalls
	std::list<PlannerClientUpcallInterface*> upcalls;

	// call the on_PlannerClient of all the attached PlannerClientUpcallInterfaces
	void notify_upcalls(const CommNavigationObjects::CommPlannerGoal &input);
	
protected:
	virtual void handle_input(const CommNavigationObjects::CommPlannerGoal &input) {
		// relay input-handling to all attached PlannerClientUpcallInterfaces
		this->notify_upcalls(input);
	}
public:
	PlannerClientUpcallManager(
		Smart::InputSubject<CommNavigationObjects::CommPlannerGoal> *subject,
		const int &prescaleFactor=1
	);
	virtual ~PlannerClientUpcallManager();
	
	void attach(PlannerClientUpcallInterface *upcall);
	void detach(PlannerClientUpcallInterface *upcall);
};

#endif
