//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain
// The SmartSoft Toolchain has been developed by:
//  
// Christian Schlegel (schlegel@hs-ulm.de)
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
#ifndef _CURMAPTASK_HH
#define _CURMAPTASK_HH

#include "CurMapTaskCore.hh"
#include "ParameterStateStruct.hh"
#include "smartCurrentGridMap.hh"
	
class CurMapTask  : public CurMapTaskCore
{
private:
	CommBasicObjects::CommMobileLaserScan laserscan;
	ParameterStateStruct localState;
	int updateCounter;

public:
	CurMapTask(Smart::IComponent *comp);
	virtual ~CurMapTask();
	
	virtual int on_entry();
	virtual int on_execute();
	virtual int on_exit();

};

#endif
