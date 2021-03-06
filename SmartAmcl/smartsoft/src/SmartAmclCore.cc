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

#include "SmartAmclCore.hh"

// constructor
SmartAmclCore::SmartAmclCore()
{
	std::cout << "constructor SmartAmclCore\n";
}

pf_vector_t SmartAmclCore::uniformPoseGenerator(void* arg) {
	map_t* map = (map_t*) arg;
	double min_x, max_x, min_y, max_y;

	// CHANGED: added - to min_x and min_y
	min_x = -(map->size_x * map->scale) / 2.0 - map->origin_x;
	max_x = (map->size_x * map->scale) / 2.0 + map->origin_x;
	min_y = -(map->size_y * map->scale) / 2.0 - map->origin_y;
	max_y = (map->size_y * map->scale) / 2.0 + map->origin_y;

	pf_vector_t p;

	for (;;) {
		p.v[0] = min_x + drand48() * (max_x - min_x);
		p.v[1] = min_y + drand48() * (max_y - min_y);
		p.v[2] = drand48() * 2 * M_PI - M_PI;

		// Check that it's a free cell
		int i, j;
		i = MAP_GXWX(map, p.v[0]);
		j = MAP_GYWY(map, p.v[1]);
		if (MAP_VALID(map,i,j) && (map->cells[MAP_INDEX(map,i,j)].occ_state == -1)) {
			break;
		}
	}

	return p;
}
