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
#include "SmartPioneerBaseServer.hh"
#include "smartTimedTaskTrigger.h"
//FIXME: implement logging
//#include "smartGlobalLogger.hh"

#include "BatteryEventServerEventTestHandler.hh"

// constructor
SmartPioneerBaseServer::SmartPioneerBaseServer()
{
	std::cout << "constructor of SmartPioneerBaseServer\n";
	
	component = NULL;
	
	// set all pointer members to NULL
	basePositionOut = NULL;
	baseStateQueryHandler = NULL;
	baseStateQueryServer = NULL;
	baseStateQueryServerInputTaskTrigger = NULL;
	batteryEventServer = NULL;
	batteryEventServerEventTestHandler = NULL; 
	localizationUpdate = NULL;
	localizationUpdateInputTaskTrigger = NULL;
	localizationUpdateUpcallManager = NULL;
	navVelIn = NULL;
	navVelInInputTaskTrigger = NULL;
	navVelInUpcallManager = NULL;
	poseUpdateTask = NULL;
	poseUpdateTaskTrigger = NULL;
	robotTask = NULL;
	robotTaskTrigger = NULL;
	stateChangeHandler = NULL;
	stateSlave = NULL;
	wiringSlave = NULL;
	param = NULL;
	
	// set default ini parameter values
	connections.component.name = "SmartPioneerBaseServer";
	connections.component.initialMainState = "Active";
	connections.component.defaultScheduler = "DEFAULT";
	connections.component.useLogger = false;
	
	connections.basePositionOut.serviceName = "BasePositionOut";
	connections.baseStateQueryServer.serviceName = "BaseStateQueryServer";
	connections.batteryEventServer.serviceName = "BatteryEventServer";
	connections.localizationUpdate.serviceName = "LocalizationUpdate";
	connections.navVelIn.serviceName = "NavVelIn";
	connections.poseUpdateTask.minActFreq = 10.0;
	connections.poseUpdateTask.maxActFreq = 40.0;
	connections.poseUpdateTask.prescale = 1;
	connections.poseUpdateTask.trigger = "PeriodicTimer";
	connections.poseUpdateTask.periodicActFreq = 10.0;
	// scheduling default parameters
	connections.poseUpdateTask.scheduler = "DEFAULT";
	connections.poseUpdateTask.priority = -1;
	connections.poseUpdateTask.cpuAffinity = -1;
	// scheduling default parameters
	connections.robotTask.scheduler = "DEFAULT";
	connections.robotTask.priority = -1;
	connections.robotTask.cpuAffinity = -1;
}



/**
 * Notify the component that setup/initialization is finished.
 * You may call this function from anywhere in the component.
 *
 * Set component's internal lifecycle state automaton (if any) into 
 * Alive mode (from here on the component is ready to provide its services)
 */
void SmartPioneerBaseServer::setStartupFinished() {
	stateSlave->setWaitState("Alive");
	std::cout << "ComponentDefinition initialization/startup finished." << std::endl;
}




/**
 * First connect ALL client ports contained in this component, then start all services:
 * activate state, push, etc...
 */
Smart::StatusCode SmartPioneerBaseServer::connectAndStartAllServices() {
	Smart::StatusCode status = Smart::SMART_OK;
	
	
	return status;
}

/**
 * Start all tasks contained in this component.
 */
void SmartPioneerBaseServer::startAllTasks() {
	// start task PoseUpdateTask
	if(connections.poseUpdateTask.scheduler != "DEFAULT") {
		ACE_Sched_Params poseUpdateTask_SchedParams(ACE_SCHED_OTHER, ACE_THR_PRI_OTHER_DEF);
		if(connections.poseUpdateTask.scheduler == "FIFO") {
			poseUpdateTask_SchedParams.policy(ACE_SCHED_FIFO);
			poseUpdateTask_SchedParams.priority(ACE_THR_PRI_FIFO_MIN);
		} else if(connections.poseUpdateTask.scheduler == "RR") {
			poseUpdateTask_SchedParams.policy(ACE_SCHED_RR);
			poseUpdateTask_SchedParams.priority(ACE_THR_PRI_RR_MIN);
		}
		poseUpdateTask->start(poseUpdateTask_SchedParams, connections.poseUpdateTask.cpuAffinity);
	} else {
		poseUpdateTask->start();
	}
	// start task RobotTask
	if(connections.robotTask.scheduler != "DEFAULT") {
		ACE_Sched_Params robotTask_SchedParams(ACE_SCHED_OTHER, ACE_THR_PRI_OTHER_DEF);
		if(connections.robotTask.scheduler == "FIFO") {
			robotTask_SchedParams.policy(ACE_SCHED_FIFO);
			robotTask_SchedParams.priority(ACE_THR_PRI_FIFO_MIN);
		} else if(connections.robotTask.scheduler == "RR") {
			robotTask_SchedParams.policy(ACE_SCHED_RR);
			robotTask_SchedParams.priority(ACE_THR_PRI_RR_MIN);
		}
		robotTask->start(robotTask_SchedParams, connections.robotTask.cpuAffinity);
	} else {
		robotTask->start();
	}
}

/**
 * Start all timers contained in this component
 */
void SmartPioneerBaseServer::startAllTimers() {
}


Smart::TaskTriggerSubject* SmartPioneerBaseServer::getInputTaskTriggerFromString(const std::string &client)
{
	if(client == "LocalizationUpdate") return localizationUpdateInputTaskTrigger;
	if(client == "NavVelIn") return navVelInInputTaskTrigger;
	
	return NULL;
}


void SmartPioneerBaseServer::init(int argc, char *argv[])
{
	try {
		Smart::StatusCode status;
		
		// load initial parameters from ini-file (if found)
		loadParameter(argc, argv);
		
		// print out the actual parameters which are used to initialize the component
		std::cout << " \nComponentDefinition Initial-Parameters:\n" << COMP->getGlobalState() << std::endl;
		if(connections.component.defaultScheduler != "DEFAULT") {
			ACE_Sched_Params sched_params(ACE_SCHED_OTHER, ACE_THR_PRI_OTHER_DEF);
			if(connections.component.defaultScheduler == "FIFO") {
				sched_params.policy(ACE_SCHED_FIFO);
				sched_params.priority(ACE_THR_PRI_FIFO_MIN);
			} else if(connections.component.defaultScheduler == "RR") {
				sched_params.policy(ACE_SCHED_RR);
				sched_params.priority(ACE_THR_PRI_RR_MIN);
			}
			// create new instance of the SmartSoft component with customized scheuling parameters 
			component = new SmartPioneerBaseServerImpl(connections.component.name, argc, argv, sched_params);
		} else {
			// create new instance of the SmartSoft component
			component = new SmartPioneerBaseServerImpl(connections.component.name, argc, argv);
		}
		
		
		std::cout << "ComponentDefinition SmartPioneerBaseServer is named " << connections.component.name << std::endl;
		
		if(connections.component.useLogger == true) {
			//FIXME: use logging
			//Smart::LOGGER->openLogFileInFolder("data/"+connections.component.name);
			//Smart::LOGGER->startLogging();
		}

		// create event-test handlers (if needed)
		batteryEventServerEventTestHandler = new BatteryEventServerEventTestHandler();
		
		// create server ports
		// TODO: set minCycleTime from Ini-file
		basePositionOut = new SmartACE::PushServer<CommBasicObjects::CommBaseState>(component, connections.basePositionOut.serviceName);
		baseStateQueryServer = new SmartACE::QueryServer<CommBasicObjects::CommVoid, CommBasicObjects::CommBaseState>(component, connections.baseStateQueryServer.serviceName);
		baseStateQueryServerInputTaskTrigger = new Smart::QueryServerTaskTrigger<CommBasicObjects::CommVoid, CommBasicObjects::CommBaseState,SmartACE::QueryId>(baseStateQueryServer);
		batteryEventServer = new SmartACE::EventServer<CommBasicObjects::CommBatteryParameter, CommBasicObjects::CommBatteryEvent, CommBasicObjects::CommBatteryState>(component, connections.batteryEventServer.serviceName, batteryEventServerEventTestHandler);
		localizationUpdate = new SmartACE::SendServer<CommBasicObjects::CommBasePositionUpdate>(component, connections.localizationUpdate.serviceName);
		navVelIn = new SmartACE::SendServer<CommBasicObjects::CommNavigationVelocity>(component, connections.navVelIn.serviceName);
		
		// create client ports
		
		// create InputTaskTriggers and UpcallManagers
		localizationUpdateInputTaskTrigger = new Smart::InputTaskTrigger<CommBasicObjects::CommBasePositionUpdate>(localizationUpdate);
		localizationUpdateUpcallManager = new LocalizationUpdateUpcallManager(localizationUpdate);
		navVelInInputTaskTrigger = new Smart::InputTaskTrigger<CommBasicObjects::CommNavigationVelocity>(navVelIn);
		navVelInUpcallManager = new NavVelInUpcallManager(navVelIn);
		
		// create input-handler
		
		// create request-handlers
		baseStateQueryHandler = new BaseStateQueryHandler(baseStateQueryServer);
		
		// create state pattern
		stateChangeHandler = new SmartStateChangeHandler();
		stateSlave = new SmartACE::StateSlave(component, stateChangeHandler);
		// create one default main state called Active which should be entered by default
		if (stateSlave->defineStates("Active" ,"active") != Smart::SMART_OK) std::cerr << "ERROR: define state" << std::endl;
		if (stateSlave->setUpInitialState(connections.component.initialMainState) != Smart::SMART_OK) std::cerr << "ERROR: setUpInitialState" << std::endl;
		// activate state slave
		status = stateSlave->activate();
		if(status != Smart::SMART_OK) std::cerr << "ERROR: activate state" << std::endl;
		
		wiringSlave = new SmartACE::WiringSlave(component);
		// add client port to wiring slave
		
		// create parameter slave
		param = new SmartACE::ParameterSlave(component, &paramHandler);
		
		
		// create Task PoseUpdateTask
		poseUpdateTask = new PoseUpdateTask(component);
		// configure input-links
		// configure task-trigger (if task is configurable)
		if(connections.poseUpdateTask.trigger == "PeriodicTimer") {
			// create PeriodicTimerTrigger
			int microseconds = 1000*1000 / connections.poseUpdateTask.periodicActFreq;
			if(microseconds > 0) {
				Smart::TimedTaskTrigger *triggerPtr = new Smart::TimedTaskTrigger();
				triggerPtr->attach(poseUpdateTask);
				component->getTimerManager()->scheduleTimer(triggerPtr, std::chrono::microseconds(microseconds), std::chrono::microseconds(microseconds));
				// store trigger in class member
				poseUpdateTaskTrigger = triggerPtr;
			} else {
				std::cerr << "ERROR: could not set-up Timer with cycle-time " << microseconds << " as activation source for Task PoseUpdateTask" << std::endl;
			}
		} else if(connections.poseUpdateTask.trigger == "DataTriggered") {
			poseUpdateTaskTrigger = getInputTaskTriggerFromString(connections.poseUpdateTask.inPortRef);
			if(poseUpdateTaskTrigger != NULL) {
				poseUpdateTaskTrigger->attach(poseUpdateTask, connections.poseUpdateTask.prescale);
			} else {
				std::cerr << "ERROR: could not set-up InPort " << connections.poseUpdateTask.inPortRef << " as activation source for Task PoseUpdateTask" << std::endl;
			}
		} else
		{
			// setup default task-trigger as PeriodicTimer
			Smart::TimedTaskTrigger *triggerPtr = new Smart::TimedTaskTrigger();
			int microseconds = 1000*1000 / 10.0;
			if(microseconds > 0) {
				component->getTimerManager()->scheduleTimer(triggerPtr, std::chrono::microseconds(microseconds), std::chrono::microseconds(microseconds));
				triggerPtr->attach(poseUpdateTask);
				// store trigger in class member
				poseUpdateTaskTrigger = triggerPtr;
			} else {
				std::cerr << "ERROR: could not set-up Timer with cycle-time " << microseconds << " as activation source for Task PoseUpdateTask" << std::endl;
			}
		}
		
		// create Task RobotTask
		robotTask = new RobotTask(component);
		// configure input-links
		localizationUpdateUpcallManager->attach(robotTask);
		navVelInUpcallManager->attach(robotTask);
		// configure task-trigger (if task is configurable)
		
		
		// link observers with subjects
		robotTask->attach(poseUpdateTask);
		robotTask->attach(baseStateQueryHandler);
	} catch (const std::exception &ex) {
		std::cerr << "Uncaught std exception" << ex.what() << std::endl;
	} catch (...) {
		std::cerr << "Uncaught exception" << std::endl;
	}
}

// run the component
void SmartPioneerBaseServer::run()
{
	compHandler.onStartup();
	
	// coponent will now start running and will continue (block in the run method) until it is commanded to shutdown (i.e. by a SIGINT signal)
	component->run();
	// component was signalled to shutdown
	// 1) signall all tasks to shutdown as well (and give them 2 seconds time to cooperate)
	// if time exceeds, component is killed without further clean-up
	component->closeAllAssociatedTasks(2);
	
	if(connections.component.useLogger == true) {
		//FIXME: use logging
		//Smart::LOGGER->stopLogging();
	}
	
	compHandler.onShutdown();
	
	// unlink all observers
	robotTask->detach(poseUpdateTask);
	
	// destroy all task instances
	// unlink all UpcallManagers
	// unlink the TaskTrigger
	poseUpdateTaskTrigger->detach(poseUpdateTask);
	delete poseUpdateTask;
	// unlink all UpcallManagers
	localizationUpdateUpcallManager->detach(robotTask);
	navVelInUpcallManager->detach(robotTask);
	// unlink the TaskTrigger
	robotTaskTrigger->detach(robotTask);
	delete robotTask;

	// destroy all input-handler

	// destroy InputTaskTriggers and UpcallManagers
	delete localizationUpdateInputTaskTrigger;
	delete localizationUpdateUpcallManager;
	delete navVelInInputTaskTrigger;
	delete navVelInUpcallManager;

	// destroy client ports

	// destroy server ports
	delete basePositionOut;
	delete baseStateQueryServer;
	delete baseStateQueryServerInputTaskTrigger;
	delete batteryEventServer;
	delete localizationUpdate;
	delete navVelIn;
	// destroy event-test handlers (if needed)
	delete batteryEventServerEventTestHandler;
	
	// create request-handlers
	delete baseStateQueryHandler;

	delete stateSlave;
	// delete state-change-handler
	delete stateChangeHandler;
	
	// delete all master/slave ports
	delete wiringSlave;
	delete param;
	

	// clean-up component's internally used resources (internally used communication middleware) 
	component->cleanUpComponentResources();
	
	// finally delete the component itself
	delete component;
}

void SmartPioneerBaseServer::loadParameter(int argc, char *argv[])
{
	/*
	 Parameters can be specified via command line --filename=<filename> or -f <filename>

	 With this parameter present:
	   - The component will look for the file in the current working directory,
	     a path relative to the current directory or any absolute path
	   - The component will use the default values if the file cannot be found

	 With this parameter absent:
	   - <Name of Component>.ini will be read from current working directory, if found there
	   - $SMART_ROOT/etc/<Name of Component>.ini will be read otherwise
	   - Default values will be used if neither found in working directory or /etc
	 */
	SmartACE::SmartIniParameter parameter;
	std::ifstream parameterfile;
	bool parameterFileFound = false;

	// load parameters
	try
	{
		// if paramfile is given as argument
		if(parameter.tryAddFileFromArgs(argc,argv,"filename", 'f'))
		{
			parameterFileFound = true;
			std::cout << "parameter file is loaded from an argv argument \n";
		} else if(parameter.searchFile("SmartPioneerBaseServer.ini", parameterfile)) {
			parameterFileFound = true;
			std::cout << "load SmartPioneerBaseServer.ini parameter file\n";
			parameter.addFile(parameterfile);
		} else {
			std::cout << "WARNING: SmartPioneerBaseServer.ini parameter file not found! (using default values or command line arguments)\n";
		}
		
		// add command line arguments to allow overwriting of parameters
		// from file
		parameter.addCommandLineArgs(argc,argv,"component");
		
		// initialize the naming service using the command line parameters parsed in the
		// SmartIniParameter class. The naming service parameters are expected to be in
		// the "component" parameter group.
		SmartACE::NAMING::instance()->checkForHelpArg(argc,argv);
		if(parameterFileFound) 
		{
			if(SmartACE::NAMING::instance()->init(parameter.getAllParametersFromGroup("component")) != 0) {
				// initialization of naming service failed
				throw std::logic_error( "<NamingService> Service initialization failed!\nPossible causes could be:\n-> Erroneous configuration.\n-> Naming service not reachable.\n" );
			}
		} else {
			if(SmartACE::NAMING::instance()->init(argc, argv) != 0) {
				// initialization of naming service failed
				throw std::logic_error( "<NamingService> Service initialization failed!\nPossible causes could be:\n-> Erroneous configuration.\n-> Naming service not reachable.\n" );
			}
		}
			
		// print all known parameters
		// parameter.print();
		
		//--- server port // client port // other parameter ---
		// load parameter
		parameter.getString("component", "name", connections.component.name);
		parameter.getString("component", "initialMainState", connections.component.initialMainState);
		if(parameter.checkIfParameterExists("component", "defaultScheduler")) {
			parameter.getString("component", "defaultScheduler", connections.component.defaultScheduler);
		}
		if(parameter.checkIfParameterExists("component", "useLogger")) {
			parameter.getBoolean("component", "useLogger", connections.component.useLogger);
		}
		
		
		// load parameters for server BasePositionOut
		parameter.getString("basePositionOut", "serviceName", connections.basePositionOut.serviceName);
		// load parameters for server BaseStateQueryServer
		parameter.getString("baseStateQueryServer", "serviceName", connections.baseStateQueryServer.serviceName);
		// load parameters for server BatteryEventServer
		parameter.getString("batteryEventServer", "serviceName", connections.batteryEventServer.serviceName);
		// load parameters for server LocalizationUpdate
		parameter.getString("localizationUpdate", "serviceName", connections.localizationUpdate.serviceName);
		// load parameters for server NavVelIn
		parameter.getString("navVelIn", "serviceName", connections.navVelIn.serviceName);
		
		// load parameters for task PoseUpdateTask
		parameter.getDouble("PoseUpdateTask", "minActFreqHz", connections.poseUpdateTask.minActFreq);
		parameter.getDouble("PoseUpdateTask", "maxActFreqHz", connections.poseUpdateTask.maxActFreq);
		parameter.getString("PoseUpdateTask", "triggerType", connections.poseUpdateTask.trigger);
		if(connections.poseUpdateTask.trigger == "PeriodicTimer") {
			parameter.getDouble("PoseUpdateTask", "periodicActFreqHz", connections.poseUpdateTask.periodicActFreq);
		} else if(connections.poseUpdateTask.trigger == "DataTriggered") {
			parameter.getString("PoseUpdateTask", "inPortRef", connections.poseUpdateTask.inPortRef);
			parameter.getInteger("PoseUpdateTask", "prescale", connections.poseUpdateTask.prescale);
		}
		if(parameter.checkIfParameterExists("PoseUpdateTask", "scheduler")) {
			parameter.getString("PoseUpdateTask", "scheduler", connections.poseUpdateTask.scheduler);
		}
		if(parameter.checkIfParameterExists("PoseUpdateTask", "priority")) {
			parameter.getInteger("PoseUpdateTask", "priority", connections.poseUpdateTask.priority);
		}
		if(parameter.checkIfParameterExists("PoseUpdateTask", "cpuAffinity")) {
			parameter.getInteger("PoseUpdateTask", "cpuAffinity", connections.poseUpdateTask.cpuAffinity);
		}
		// load parameters for task RobotTask
		if(parameter.checkIfParameterExists("RobotTask", "scheduler")) {
			parameter.getString("RobotTask", "scheduler", connections.robotTask.scheduler);
		}
		if(parameter.checkIfParameterExists("RobotTask", "priority")) {
			parameter.getInteger("RobotTask", "priority", connections.robotTask.priority);
		}
		if(parameter.checkIfParameterExists("RobotTask", "cpuAffinity")) {
			parameter.getInteger("RobotTask", "cpuAffinity", connections.robotTask.cpuAffinity);
		}
		
		paramHandler.loadParameter(parameter);
	
	} catch (const SmartACE::IniParameterError & e) {
		std::cerr << e.what() << std::endl;
	} catch (const std::exception &ex) {
		std::cerr << "Uncaught std::exception: " << ex.what() << std::endl;
	} catch (...) {
		std::cerr << "Uncaught exception" << std::endl;
	}
}
