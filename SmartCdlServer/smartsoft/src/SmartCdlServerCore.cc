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

// --------------------------------------------------------------------------
//
//  Copyright (C) 2008 Christian Schlegel, Andreas Steck, Matthias Lutz
//
//        schlegel@hs-ulm.de
//        steck@hs-ulm.de
//
//        ZAFH Servicerobotik Ulm
//        University of Applied Sciences
//        Prittwitzstr. 10
//        D-89075 Ulm
//        Germany
//
//  This file is part of the "SmartSoft CDL component".
//  It provides navigation services based on the CDL
//  Curvature Distance Lookup approach.
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
// --------------------------------------------------------------------------

#include "SmartCdlServerCore.hh"

#include "SmartCdlServer.hh"

// constructor
SmartCdlServerCore::SmartCdlServerCore()
: mutex()
, saveFlag(false)
, counter(0)
, goalId(0)
, strategy()
, strategyChanged(false)
, cdlLookupDefault()
, cdlLookupSecond()
, cdlLookup(&cdlLookupDefault)
, desV(0)
, desW(0.0)
//, CDLglobalState()
//, CDLlocalState()
//, CdlGlobalLock()
{
	std::cout << "constructor SmartCdlServerCore\n";
}

TriggerHandler::SETSTRATEGYType::stratType SmartCdlServerCore::getStrategy() const
{
	SmartACE::SmartGuard g(mutex);
	return strategy;
}
void SmartCdlServerCore::triggerStrategy(const TriggerHandler::SETSTRATEGYType::stratType &strat)
{
	SmartACE::SmartGuard g(mutex);
	this->strategy = strat;

	if(strat != TriggerHandler::SETSTRATEGYType::stratType::PATH_NAV){
		cdlLookup->setUsePathNav(false);
	}
	if(strat == TriggerHandler::SETSTRATEGYType::stratType::PATH_NAV){
		COMP->cdlTask->initPathNav();
	}
	if(strat == TriggerHandler::SETSTRATEGYType::stratType::APPROACH_FLAT_SURF) {
		// reset counter
		counter = 0;
	}
	strategyChanged = true;
}
bool SmartCdlServerCore::isStrategyTriggered()
{
	SmartACE::SmartGuard g(mutex);
	if(strategyChanged) {
		strategyChanged = false;
		return true;
	}
	return false;
}

void SmartCdlServerCore::setGoalId(const long &goalId)
{
	SmartACE::SmartGuard g(mutex);
	this->goalId = goalId;
}
long SmartCdlServerCore::getGoalId() const
{
	SmartACE::SmartGuard g(mutex);
	return this->goalId;
}
void SmartCdlServerCore::triggerSavePos(const long &goalId)
{
	SmartACE::SmartGuard g(mutex);
	this->goalId = goalId;
	saveFlag = true;
}

bool SmartCdlServerCore::isSavePosTriggered()
{
	SmartACE::SmartGuard g(mutex);
	if(saveFlag == true) {
		saveFlag = false;
		return true;
	}
	return false;
}

void SmartCdlServerCore::resetCounter()
{
	SmartACE::SmartGuard g(mutex);
	counter = 0;
}
int SmartCdlServerCore::getCounter() const
{
	SmartACE::SmartGuard g(mutex);
	return counter;
}
void SmartCdlServerCore::incrementCounter()
{
	SmartACE::SmartGuard g(mutex);
	this->counter++;
}

void SmartCdlServerCore::getDesiredVelocities(int& v,double& w) const{
	SmartACE::SmartGuard g(mutex);
	v = this->desV;
	w = this->desW;
}

void SmartCdlServerCore::setDesiredVelocities(int v,double w){
	SmartACE::SmartGuard g(mutex);
	this->desV = v;
	this->desW = w;
}
