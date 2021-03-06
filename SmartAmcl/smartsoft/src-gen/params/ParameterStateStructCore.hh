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
		 * Definition of Parameter Filter
		 */
		class FilterType 
		{
			friend class ParamUpdateHandler;
		protected:
			/**
			 * here are the member definitions
			 */
			double kld_err;
			double kld_z;
			int max_particles;
			int min_particles;
			double recovery_alpha_fast;
			double recovery_alpha_slow;
			double resample_interval;
			double update_min_alpha;
			double update_min_d;
		
		public:
			// default constructor
			FilterType() {
				kld_err = 0.05;
				kld_z = 0.99;
				max_particles = 5000;
				min_particles = 500;
				recovery_alpha_fast = 0.1;
				recovery_alpha_slow = 0.001;
				resample_interval = 1.0;
				update_min_alpha = 0.5236;
				update_min_d = 0.2;
			}
		
			/**
			 * here are the public getters
			 */
			inline double getKld_err() const { return kld_err; }
			inline double getKld_z() const { return kld_z; }
			inline int getMax_particles() const { return max_particles; }
			inline int getMin_particles() const { return min_particles; }
			inline double getRecovery_alpha_fast() const { return recovery_alpha_fast; }
			inline double getRecovery_alpha_slow() const { return recovery_alpha_slow; }
			inline double getResample_interval() const { return resample_interval; }
			inline double getUpdate_min_alpha() const { return update_min_alpha; }
			inline double getUpdate_min_d() const { return update_min_d; }
			
			void to_ostream(std::ostream &os = std::cout) const
			{
				os << "Filter(";
				os << "kld_err = " << kld_err << ", ";
				os << "kld_z = " << kld_z << ", ";
				os << "max_particles = " << max_particles << ", ";
				os << "min_particles = " << min_particles << ", ";
				os << "recovery_alpha_fast = " << recovery_alpha_fast << ", ";
				os << "recovery_alpha_slow = " << recovery_alpha_slow << ", ";
				os << "resample_interval = " << resample_interval << ", ";
				os << "update_min_alpha = " << update_min_alpha << ", ";
				os << "update_min_d = " << update_min_d << ", ";
				os << ")\n";
			}
			
		}; // end class FilterType
		
		/**
		 * Definition of Parameter Laser
		 */
		class LaserType 
		{
			friend class ParamUpdateHandler;
		protected:
			/**
			 * here are the member definitions
			 */
			double lambda_short;
			double laser_likelihood_max_dist;
			std::string laser_model_type;
			unsigned int max_beams;
			double sigma_hit;
			double z_hit;
			double z_max;
			double z_rand;
			double z_short;
		
		public:
			// default constructor
			LaserType() {
				lambda_short = 0.1;
				laser_likelihood_max_dist = 2.0;
				laser_model_type = "likelihood_field";
				max_beams = 30;
				sigma_hit = 0.2;
				z_hit = 0.95;
				z_max = 0.05;
				z_rand = 0.05;
				z_short = 0.1;
			}
		
			/**
			 * here are the public getters
			 */
			inline double getLambda_short() const { return lambda_short; }
			inline double getLaser_likelihood_max_dist() const { return laser_likelihood_max_dist; }
			inline std::string getLaser_model_type() const { return laser_model_type; }
			inline unsigned int getMax_beams() const { return max_beams; }
			inline double getSigma_hit() const { return sigma_hit; }
			inline double getZ_hit() const { return z_hit; }
			inline double getZ_max() const { return z_max; }
			inline double getZ_rand() const { return z_rand; }
			inline double getZ_short() const { return z_short; }
			
			void to_ostream(std::ostream &os = std::cout) const
			{
				os << "Laser(";
				os << "lambda_short = " << lambda_short << ", ";
				os << "laser_likelihood_max_dist = " << laser_likelihood_max_dist << ", ";
				os << "laser_model_type = " << laser_model_type << ", ";
				os << "max_beams = " << max_beams << ", ";
				os << "sigma_hit = " << sigma_hit << ", ";
				os << "z_hit = " << z_hit << ", ";
				os << "z_max = " << z_max << ", ";
				os << "z_rand = " << z_rand << ", ";
				os << "z_short = " << z_short << ", ";
				os << ")\n";
			}
			
		}; // end class LaserType
		
		/**
		 * Definition of Parameter Odometry
		 */
		class OdometryType 
		{
			friend class ParamUpdateHandler;
		protected:
			/**
			 * here are the member definitions
			 */
			double alpha1;
			double alpha2;
			double alpha3;
			double alpha4;
			double alpha5;
			std::string odom_model_type;
		
		public:
			// default constructor
			OdometryType() {
				alpha1 = 0.2;
				alpha2 = 0.2;
				alpha3 = 0.8;
				alpha4 = 0.2;
				alpha5 = 0.2;
				odom_model_type = "diff";
			}
		
			/**
			 * here are the public getters
			 */
			inline double getAlpha1() const { return alpha1; }
			inline double getAlpha2() const { return alpha2; }
			inline double getAlpha3() const { return alpha3; }
			inline double getAlpha4() const { return alpha4; }
			inline double getAlpha5() const { return alpha5; }
			inline std::string getOdom_model_type() const { return odom_model_type; }
			
			void to_ostream(std::ostream &os = std::cout) const
			{
				os << "Odometry(";
				os << "alpha1 = " << alpha1 << ", ";
				os << "alpha2 = " << alpha2 << ", ";
				os << "alpha3 = " << alpha3 << ", ";
				os << "alpha4 = " << alpha4 << ", ";
				os << "alpha5 = " << alpha5 << ", ";
				os << "odom_model_type = " << odom_model_type << ", ";
				os << ")\n";
			}
			
		}; // end class OdometryType
		
		/**
		 * Definition of Parameter General
		 */
		class GeneralType 
		{
			friend class ParamUpdateHandler;
			public:
			/**
			 * Wrapper class for Enum initalizationType
			 */
			class initalizationTypeType {
			public:
				enum ENUM_initalizationType {
					ENUM_VALUE_UNDEFINED = 0,
					INI_POSE = 1,
					FILE_POSE = 2,
					GLOBAL = 3
				};
				
				// default constructor
				initalizationTypeType() { 
					value = ENUM_VALUE_UNDEFINED;
				}
				
				// copy constructor for enum type
				initalizationTypeType(ENUM_initalizationType e) {
					value = e;
				}
				
				// copy constructor for String type
				initalizationTypeType(const std::string &literal) {
					from_string(literal);
				}
				
				// from_string assignment operator
				initalizationTypeType& operator = (const std::string &literal) {
					from_string(literal);
					return *this;
				}
				
				// ENUM operator
				operator ENUM_initalizationType() const {
					return value;
				}
				
				// String operator
				operator std::string() const {
					return to_string();
				}
				
				// compare operator
				bool operator == (const ENUM_initalizationType t) const {
					return this->value == t;
				}
				
				std::string to_string() const {
					std::string result = "";
					switch (value) {
						case FILE_POSE:
							result = "FILE_POSE";
							break;
						case GLOBAL:
							result = "GLOBAL";
							break;
						case INI_POSE:
							result = "INI_POSE";
							break;
						default:
							result = "ENUM_VALUE_UNDEFINED";
							break;
					};
					return result;
				}
				
				void from_string(const std::string &literal) {
					if(literal == "INI_POSE") {
						value = INI_POSE;
					} else if(literal == "FILE_POSE") {
						value = FILE_POSE;
					} else if(literal == "GLOBAL") {
						value = GLOBAL;
					} else {
						value = ENUM_VALUE_UNDEFINED;
					}
				}
				
				// helper method to easily implement output stream
				void to_ostream(std::ostream &os = std::cout) const {
					os << to_string();
				}
			private:
				ENUM_initalizationType value;
			};
			
		protected:
			/**
			 * here are the member definitions
			 */
			bool connect_services;
			bool enable_visualization;
			std::string initPoseFileName;
			GeneralType::initalizationTypeType initalizationType;
			double initial_a;
			double initial_cov_aa;
			double initial_cov_xx;
			double initial_cov_yy;
			double initial_x;
			double initial_y;
			double lostEventMaxEigValueSum;
			unsigned int lostEventMaxHypothese;
			bool verbose;
			std::string yaml_file;
		
		public:
			// default constructor
			GeneralType() {
				connect_services = true;
				enable_visualization = false;
				initPoseFileName = "/tmp/lastRobotPose.txt";
				initalizationType = GeneralType::initalizationTypeType::INI_POSE;
				initial_a = 0.0;
				initial_cov_aa = 0.068539;
				initial_cov_xx = 0.03;
				initial_cov_yy = 0.03;
				initial_x = 0.0;
				initial_y = 0.0;
				lostEventMaxEigValueSum = 0.2;
				lostEventMaxHypothese = 3;
				verbose = false;
				yaml_file = "data/maps/amcl-c26.yaml";
			}
		
			/**
			 * here are the public getters
			 */
			inline bool getConnect_services() const { return connect_services; }
			inline bool getEnable_visualization() const { return enable_visualization; }
			inline std::string getInitPoseFileName() const { return initPoseFileName; }
			inline GeneralType::initalizationTypeType getInitalizationType() const { return initalizationType; }
			inline double getInitial_a() const { return initial_a; }
			inline double getInitial_cov_aa() const { return initial_cov_aa; }
			inline double getInitial_cov_xx() const { return initial_cov_xx; }
			inline double getInitial_cov_yy() const { return initial_cov_yy; }
			inline double getInitial_x() const { return initial_x; }
			inline double getInitial_y() const { return initial_y; }
			inline double getLostEventMaxEigValueSum() const { return lostEventMaxEigValueSum; }
			inline unsigned int getLostEventMaxHypothese() const { return lostEventMaxHypothese; }
			inline bool getVerbose() const { return verbose; }
			inline std::string getYaml_file() const { return yaml_file; }
			
			void to_ostream(std::ostream &os = std::cout) const
			{
				os << "General(";
				os << "connect_services = " << connect_services << ", ";
				os << "enable_visualization = " << enable_visualization << ", ";
				os << "initPoseFileName = " << initPoseFileName << ", ";
				os << "initalizationType = " << initalizationType << ", ";
				os << "initial_a = " << initial_a << ", ";
				os << "initial_cov_aa = " << initial_cov_aa << ", ";
				os << "initial_cov_xx = " << initial_cov_xx << ", ";
				os << "initial_cov_yy = " << initial_cov_yy << ", ";
				os << "initial_x = " << initial_x << ", ";
				os << "initial_y = " << initial_y << ", ";
				os << "lostEventMaxEigValueSum = " << lostEventMaxEigValueSum << ", ";
				os << "lostEventMaxHypothese = " << lostEventMaxHypothese << ", ";
				os << "verbose = " << verbose << ", ";
				os << "yaml_file = " << yaml_file << ", ";
				os << ")\n";
			}
			
		}; // end class GeneralType
		
	
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
			 * Definition of instantiated ParameterSet AmclParameter
			 */
			class AmclParameterType {
				friend class ParamUpdateHandler;
				public:
				protected:
					/**
					 * internal members
					 */
					
				public:
					/**
					 * public getter methods
					 */
					
					void to_ostream(std::ostream &os = std::cout) const
					{
						os << "AmclParameter(\n";
						os << ")";
					}
			}; // end of parameter-set class AmclParameterType
			
			protected:
				/**
				 * internal members
				 */
				AmclParameterType AmclParameter;
			
			public:
				/**
				 * public getter methods
				 */
				inline AmclParameterType getAmclParameter() const { return AmclParameter; }
				
				void to_ostream(std::ostream &os = std::cout) const
				{
					os << "CommNavigationObjects(\n";
					AmclParameter.to_ostream(os);
					os << ")";
				}
		}; // end of parameter-repository wrapper class CommNavigationObjectsType
	
protected:

	// Internal params
	FilterType Filter;
	GeneralType General;
	LaserType Laser;
	OdometryType Odometry;
	
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
	FilterType getFilter() const {
		return Filter;
	}
	GeneralType getGeneral() const {
		return General;
	}
	LaserType getLaser() const {
		return Laser;
	}
	OdometryType getOdometry() const {
		return Odometry;
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
		Filter.to_ostream(os);
		General.to_ostream(os);
		Laser.to_ostream(os);
		Odometry.to_ostream(os);
		
		// External params
		
		// Instance params (encapsulated in a wrapper class for each instantiated parameter repository)
		CommNavigationObjects.to_ostream(os);
	}
};

#endif
