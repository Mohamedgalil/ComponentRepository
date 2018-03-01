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
#ifndef _PARAMETERSTATESTRUCTCORE_HH
#define _PARAMETERSTATESTRUCTCORE_HH

#include "aceSmartSoft.hh"

#include <iostream>

// forward declaration (in order to define validateCOMMIT(ParameterStateStruct) which is implemented in derived class)
class ParameterStateStruct;

class ParameterStateStructCore
{
	friend class ParamUpdateHandler;
public:
	
		///////////////////////////////////////////
		// Internal params
		///////////////////////////////////////////
		
		/**
		 * Definition of Parameter Settings
		 */
		class SettingsType 
		{
			friend class ParamUpdateHandler;
		protected:
			/**
			 * here are the member definitions
			 */
			double no_path_event_timeout;
		
		public:
			// default constructor
			SettingsType() {
				no_path_event_timeout = 5.0;
			}
		
			/**
			 * here are the public getters
			 */
			inline double getNo_path_event_timeout() const { return no_path_event_timeout; }
			
			void to_ostream(std::ostream &os = std::cout) const
			{
				os << "Settings(";
				os << "no_path_event_timeout = " << no_path_event_timeout << ", ";
				os << ")\n";
			}
			
		}; // end class SettingsType
		
	
		///////////////////////////////////////////
		// External params
		///////////////////////////////////////////
		
	
		///////////////////////////////////////////
		// Instance params
		///////////////////////////////////////////
		
		/**
		 * Definition of instantiated ParameterRepository CommNavigationObjects
		 */
		class CommNavigationObjectsType {
			friend class ParamUpdateHandler;
			public:
			/**
			 * Definition of instantiated ParameterSet PlannerParams
			 */
			class PlannerParamsType {
				friend class ParamUpdateHandler;
				public:
				/**
				 * Definition of Parameter ID
				 */
				class IDType {
					friend class ParamUpdateHandler;
				
				protected:
					/**
					 * here are the member definitions
					 */
					unsigned int id;
					
				public:
					// default constructor
					IDType() {
						id = 0;
					}
					
					/**
					 * here are the getter methods
					 */
					inline unsigned int getId() const { return id; }
					
					void to_ostream(std::ostream &os = std::cout) const
					{
						os << "\tID(";
						os << "id = " << id << ", ";
						os << ")\n";
					}
					
				}; // end of parameter class IDType
				
				protected:
					/**
					 * internal members
					 */
					IDType ID;
					
				public:
					/**
					 * public getter methods
					 */
					inline IDType getID() const { return ID; }
					
					void to_ostream(std::ostream &os = std::cout) const
					{
						os << "PlannerParams(\n";
						ID.to_ostream(os);
						os << ")";
					}
			}; // end of parameter-set class PlannerParamsType
			
			protected:
				/**
				 * internal members
				 */
				PlannerParamsType PlannerParams;
			
			public:
				/**
				 * public getter methods
				 */
				inline PlannerParamsType getPlannerParams() const { return PlannerParams; }
				
				void to_ostream(std::ostream &os = std::cout) const
				{
					os << "CommNavigationObjects(\n";
					PlannerParams.to_ostream(os);
					os << ")";
				}
		}; // end of parameter-repository wrapper class CommNavigationObjectsType
	
protected:

	// Internal params
	SettingsType Settings;
	
	// External params
	
	// Instance params (encapsulated in a wrapper class for each instantiated parameter repository)
	CommNavigationObjectsType CommNavigationObjects;
	

	void setContent(const ParameterStateStructCore &commit) {
		// External params
	
		this->CommNavigationObjects = commit.getCommNavigationObjects();
	}

	// special trigger method (user upcall) called before updating parameter global state
	virtual SmartACE::ParamResponseType handleCOMMIT(const ParameterStateStruct &commitState) = 0;
public:
	ParameterStateStructCore() {  }
	virtual ~ParameterStateStructCore() {  }
	
	// internal param getters
	SettingsType getSettings() const {
		return Settings;
	}
	
	// external param getters
	
	// repo wrapper class getter(s)
	CommNavigationObjectsType getCommNavigationObjects() const {
		return CommNavigationObjects;
	}
	
	// helper method to easily implement output stream in derived classes
	void to_ostream(std::ostream &os = std::cout) const
	{
		// Internal params
		Settings.to_ostream(os);
		
		// External params
		
		// Instance params (encapsulated in a wrapper class for each instantiated parameter repository)
		CommNavigationObjects.to_ostream(os);
	}
};

#endif
