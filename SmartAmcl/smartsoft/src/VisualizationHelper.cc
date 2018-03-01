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

#include "VisualizationHelper.hh"

#include <sstream>

VisualizationHelper::VisualizationHelper() {
}

void VisualizationHelper::initializeVisualization(){
	grid3D = new CDisplayWindow3D();
	grid3D->setWindowTitle("SmartAMCL");
	grid3D->resize(800, 600);
}

void VisualizationHelper::initObjects() {

	opengl::COpenGLScenePtr &ptrScene = grid3D->get3DSceneAndLock();
	{
		opengl::CAxisPtr axis = opengl::CAxis::Create(-10, -10, 0, 10, 10, 1,
				1, 1, true);
		axis->setName("axis");
		axis->setColor(0, 0, 0);
		ptrScene->insert(axis);

		opengl::CCylinderPtr cylinder = opengl::CCylinder::Create(0.2, 0.2, 0.4, 10, 10);
		cylinder->setName("robot");
		cylinder->setColor(0, 0, 1);
		ptrScene->insert(cylinder);

		//		opengl::CArrowPtr robotArrow = opengl::CArrow::Create(0, 0, 0, 0.2, 0, 0);
		//		robotArrow->setColor(0, 0, 1);
		//		robotArrow->setName("robotOrientation");
		//		ptrScene->insert(robotArrow);

		opengl::CPlanarLaserScanPtr scan = opengl::CPlanarLaserScan::Create();
		scan->setName("scan");
		ptrScene->insert(scan);

		opengl::CPointCloudColouredPtr particles =
				opengl::CPointCloudColoured::Create();
		particles->setName("particles");
		particles->setPointSize(3);
		ptrScene->insert(particles);

		opengl::CSetOfLinesPtr particleLines = opengl::CSetOfLines::Create();
		particleLines->setName("particleLines");
		ptrScene->insert(particleLines);

		opengl::CPointCloudColouredPtr hypotheses =
				opengl::CPointCloudColoured::Create();
		hypotheses->setName("hypotheses");
		hypotheses->setPointSize(10);
		ptrScene->insert(hypotheses);

		opengl::CTextPtr robotText = opengl::CText::Create();
		robotText->setName("robotLabel");
		robotText->setColor(0, 0, 0);
		ptrScene->insert(robotText);

	}
	grid3D->unlockAccess3DScene();
	grid3D->forceRepaint();
}

VisualizationHelper::~VisualizationHelper() {
	std::cout<<"Destructor VisualizationHelper..."<<std::endl;
	try{
		if(grid3D != NULL){
			std::cout<<"delete grid3D"<<std::endl;
			delete grid3D;
		}
	}
	catch (std::exception &e)
	{
			std::cerr << e.what() << std::endl << "Program finished for an exception!!" << std::endl;
	}
	catch (...)
	{
			std::cerr << "Untyped exception!!" << std::endl;
	}
	std::cout<<"Destructor VisualizationHelper.DONE"<<std::endl;
}

void VisualizationHelper::clear() {
	opengl::COpenGLScenePtr &ptrScene = grid3D->get3DSceneAndLock();
	{
		ptrScene->clear();
	}
	grid3D->unlockAccess3DScene();
	grid3D->forceRepaint();
}

void VisualizationHelper::displayMap(map_t* map) {

	int width = map->size_x;
	int height = map->size_y;
	double scale = map->scale;

//	int x = width / 2;
//	int y = height / 2;

	int x = width/2.0 - map->origin_x/map->scale;
	int y = height/2.0 - map->origin_y/map->scale;

	std::cout<<"x: "<<x<<" y:"<<y<<std::endl;

	std::cout<<"Height : "<<height<<" Width: "<<width<<std::endl;

	Eigen::MatrixXf m(height, width);
	for (int j = 0; j < width; j++) {
		for (int i = 0; i < height; i++) {
			if (map->cells[MAP_IDX(width, j, height - i - 1)].occ_state == 1) {
				m(i, j) = 0;
			} else if (map->cells[MAP_IDX(width, j, height - i - 1)].occ_state
					== -1) {
				m(i, j) = 1;
			} else {
				m(i, j) = 0.5;
			}
		}
	}

        //WORKAROUND: do not use construtor from matix, since mrpt bug:
        //https://github.com/MRPT/mrpt/commit/d4e5adf3eccbb655a9340254b88985bb808c1bda
        utils::CImage image;
        image.setFromMatrix(m, true);
	//image.flipVertical();
	gridMap.loadFromBitmap(image, scale, x, y);

	opengl::COpenGLScenePtr &ptrScene = grid3D->get3DSceneAndLock();
	{
		opengl::CSetOfObjectsPtr ptrObjs = opengl::CSetOfObjects::Create();
		gridMap.getAs3DObject(ptrObjs);

		ptrScene->insert(ptrObjs);
	}
	grid3D->unlockAccess3DScene();
	grid3D->forceRepaint();
}

void VisualizationHelper::displayLaserScan(
		const CommBasicObjects::CommMobileLaserScan& scan) {
	if(scan.get_scan_size()<2){
		std::cout<<"WARNING: [VisualizationHelper] scan size <2 skip scan..."<<std::endl;
		return;

	}

#ifdef WITH_OLD_MRPT_VERSION
	CObservation2DRangeScan s;
#else
	obs::CObservation2DRangeScan s;
#endif

	CommBasicObjects::CommPose3d bp =
			scan.get_base_state().get_base_position().get_base_pose3d();
	CommBasicObjects::CommPose3d sp = scan.get_sensor_pose();

	poses::CPose3D pBase(bp.get_x(1), bp.get_y(1), bp.get_z(1), bp.get_azimuth(),
			bp.get_elevation(), bp.get_roll());
	poses::CPose3D pSensor(sp.get_x(1), sp.get_y(1), sp.get_z(1), sp.get_azimuth(),
			sp.get_elevation(), sp.get_roll());

	size_t numScans = scan.get_scan_size();
	double resolution = scan.get_scan_resolution();
	double startAngle = pi_to_pi(scan.get_scan_start_angle());
	double endAngle =  pi_to_pi(scan.get_scan_angle(numScans - 1));
	int scanSize = fabs(endAngle - startAngle) / resolution;

	s.scan.resize(scanSize);
	s.validRange.resize(scanSize, 0);
	s.aperture = scanSize * resolution;
	s.maxRange = scan.get_max_distance(1.0);
	s.sensorPose = pBase + pSensor;

	for (size_t i = 0; i < numScans; ++i) {
		int index = fabs(pi_to_pi(scan.get_scan_angle(i)) - startAngle) / resolution;

		if (index < scanSize) {
			s.scan[index] = scan.get_scan_distance(i, 1);
			s.validRange[index] = 1;
		}
	}

	opengl::COpenGLScenePtr &ptrScene = grid3D->get3DSceneAndLock();
	{
		opengl::CPlanarLaserScanPtr sPtr =
				(opengl::CPlanarLaserScanPtr) ptrScene->getByName("scan");
		sPtr->setScan(s);
	}
	grid3D->unlockAccess3DScene();
	grid3D->forceRepaint();
}



void VisualizationHelper::displayCoordinateSystem( poses::CPose3D& pose, double size){

		opengl::COpenGLScenePtr &theScene = grid3D->get3DSceneAndLock();


		opengl::CSetOfObjectsPtr corner = opengl::stock_objects::CornerXYZSimple(size,2.0);
		{
		corner->setPose(pose);
		theScene->insert(corner);
		}
		grid3D->unlockAccess3DScene();
		grid3D->forceRepaint();

}

void VisualizationHelper::displayBase(const CommBasicObjects::CommBasePose& pos) {
	CommBasicObjects::CommPose3d p = pos.get_base_pose3d();
	poses::CPose3D pose(p.get_x(1.0), p.get_y(1.0), p.get_z(1.0), p.get_azimuth(),
			p.get_elevation(), p.get_roll());
	poses::CPose3D poseLabel(p.get_x(1.0) - 0.3, p.get_y(1.0) + 1, p.get_z(1.0),
			p.get_azimuth(), p.get_elevation(), p.get_roll());

	std::stringstream labelString;
	labelString << "Pose: x=" << p.get_x(1.0) << ", y=" << p.get_y(1.0)
			<< ", a=" << p.get_azimuth();

	opengl::COpenGLScenePtr &ptrScene = grid3D->get3DSceneAndLock();
	{
		opengl::CRenderizablePtr obj1 = ptrScene->getByName("robot");
		obj1->setPose(pose);

		opengl::CTextPtr label = (opengl::CTextPtr) ptrScene->getByName(
				"robotLabel");
		label->setPose(poseLabel);
		label->setString(labelString.str());

		//		opengl::CRenderizablePtr obj2 = ptrScene->getByName("robotOrientation");
		//		obj2->setPose(pose);
	}
	grid3D->unlockAccess3DScene();
	grid3D->forceRepaint();
}

void VisualizationHelper::displayParticles(const pf_sample_set_t* set) {

	std::cout << "Num samples: " << set->sample_count << "\n";

	opengl::COpenGLScenePtr &ptrScene = grid3D->get3DSceneAndLock();
	{
		opengl::CPointCloudColouredPtr obj =
				(opengl::CPointCloudColouredPtr) ptrScene->getByName("particles");
		obj->clear();

		opengl::CSetOfLinesPtr particleLines =
				(opengl::CSetOfLinesPtr) ptrScene->getByName("particleLines");
		particleLines->clear();
		particleLines->setColor(0, 1, 0);

		for (int i = 0; i < set->sample_count; i++) {

			obj->push_back(set->samples[i].pose.v[0],
					set->samples[i].pose.v[1], 0, 0, 1, 0);

			particleLines->appendLine(set->samples[i].pose.v[0],
					set->samples[i].pose.v[1], 0, set->samples[i].pose.v[0]
							+ cos(set->samples[i].pose.v[2]) * 0.2,
					set->samples[i].pose.v[1] + sin(set->samples[i].pose.v[2])
							* 0.2, 0);

		}

	}
	grid3D->unlockAccess3DScene();
	grid3D->forceRepaint();
}

void VisualizationHelper::displayHypotheses(const std::vector<amcl_hyp_t>& hyps) {

	std::cout << "num hypotheses: " << hyps.size() << "\n";

	opengl::COpenGLScenePtr &ptrScene = grid3D->get3DSceneAndLock();
	{
		opengl::CPointCloudColouredPtr obj =
				(opengl::CPointCloudColouredPtr) ptrScene->getByName("hypotheses");
		obj->clear();

		for (size_t i = 0; i < hyps.size(); i++) {
			obj->push_back(hyps[i].pf_pose_mean.v[0],
					hyps[i].pf_pose_mean.v[1], 0, 1, 0, 0);
		}
	}
	grid3D->unlockAccess3DScene();
	grid3D->forceRepaint();
}
