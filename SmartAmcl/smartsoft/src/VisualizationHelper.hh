//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain Version 0.10.3
// The SmartSoft Toolchain has been developed by:
//
// ZAFH Servicerobotic Ulm
// Christian Schlegel (schlegel@hs-ulm.de)
// University of Applied Sciences
// Prittwitzstr. 10
// 89075 Ulm (Germany)
//
// Information about the SmartSoft MDSD Toolchain is available at:
// smart-robotics.sourceforge.net
//
// This file is generated once. Modify this file to your needs.
// If you want the toolchain to re-generate this file, please
// delete it before running the code generator.
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
//
//  Copyright (C) 2010 Manuel Wopfner, Matthias Lutz
//
//        schlegel@hs-ulm.de
//        lutz@hs-ulm.de
//
//        ZAFH Servicerobotic Ulm
//        University of Applied Sciences
//        Prittwitzstr. 10
//        89075 Ulm
//        Germany
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2.1
//  of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU General Public License along
//  with this library; if not, write to the Free Software Foundation, Inc.,
//  59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
//
//  This work is based on previous work by the folks from PlayerStage.
//
//--------------------------------------------------------------------------

//----------------------------------------------------------------------------
//
// CREDITS:
//
// The code for the amcl algorithm was taken from the
// Playerstage Project, which is distributed under GPL, and you can find at
// http://playerstage.sourceforge.net/
//
// Player - One Hell of a Robot Server
// Copyright (C) 2000
//    Brian Gerkey, Kasper Stoy, Richard Vaughan, & Andrew Howard
//
//----------------------------------------------------------------------------

#ifndef VISUALIZATIONHELPER_H_
#define VISUALIZATIONHELPER_H_

#include <mrpt/gui.h>
#include <mrpt/opengl.h>
#include <mrpt/utils.h>
#include <mrpt/maps.h>

using namespace mrpt;
using namespace mrpt::math;
#ifdef WITH_OLD_MRPT_VERSION
using namespace mrpt::slam;
#endif
using namespace mrpt::gui;

#include "AmclTypes.hh"
#include "CommBasicObjects/CommBasePose.hh"
#include "CommBasicObjects/CommMobileLaserScan.hh"

#include <vector>

class VisualizationHelper {

private:
#ifdef WITH_OLD_MRPT_VERSION
	COccupancyGridMap2D gridMap;
#else
	maps::COccupancyGridMap2D gridMap;
#endif

	CDisplayWindow3D *grid3D;

public:
	VisualizationHelper();
	virtual ~VisualizationHelper();

	void initializeVisualization();

	void initObjects();

	void clear();

	void displayMap(map_t* map);

	void displayLaserScan(const CommBasicObjects::CommMobileLaserScan& scan);

	void displayBase(const CommBasicObjects::CommBasePose& pos);

	void displayParticles(const pf_sample_set_t* set);

	void displayHypotheses(const std::vector<amcl_hyp_t>& hyps);

	void displayCoordinateSystem(poses::CPose3D& pose, double size = 0.1);

private:
	static double pi_to_pi(double angle) {
		angle += M_PI;
		double ret_angle = fmod(angle, 2* M_PI );

		if (angle < 0)
			ret_angle += 2* M_PI ;

		ret_angle -= M_PI;

		return ret_angle;
	}
};

#endif /* VISUALIZATIONHELPER_H_ */
