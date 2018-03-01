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
#ifndef _TRIGGERHANDLER_HH
#define _TRIGGERHANDLER_HH

#include "TriggerHandlerCore.hh"

class TriggerHandler: public TriggerHandlerCore 
{
public:
	TriggerHandler() {  }
	virtual ~TriggerHandler() {  }
	
	// trigger user methods
	virtual void handleCommNavigationObjects_AmclParameter_INITIALPOSE(const int &x, const int &y, const double &a);
	virtual void handleCommNavigationObjects_AmclParameter_GLOBALLOCALIZATION();
	virtual void handleCommNavigationObjects_AmclParameter_LOADMAP(const std::string &filename);
};

#endif // _TRIGGERHANDLER_HH
