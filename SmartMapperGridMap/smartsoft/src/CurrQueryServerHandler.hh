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
#ifndef _CURRQUERYSERVERHANDLER_USER_HH
#define _CURRQUERYSERVERHANDLER_USER_HH
		
#include "CurrQueryServerHandlerCore.hh"

class CurrQueryServerHandler : public CurrQueryServerHandlerCore
{
protected:
	virtual void on_update_from(const CurMapTask* curMapTask);
public:
	CurrQueryServerHandler(Smart::IQueryServerPattern<CommNavigationObjects::CommGridMapRequest, CommNavigationObjects::CommGridMap, SmartACE::QueryId>* server);
	virtual ~CurrQueryServerHandler();
	virtual void handleQuery(const SmartACE::QueryId &id, const CommNavigationObjects::CommGridMapRequest& request);
};
#endif
