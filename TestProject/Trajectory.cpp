#include "stdafx.h"
#include "Trajectory.h"



struct Position
{
	int WN;
	int ToW;
	int ECEF_x, ECEF_y, ECEF_z;
	int LLH_lat, LLH_long, LLH_height;
};


Trajectory::Trajectory()
{
}


Trajectory::~Trajectory()
{
}

Trajectory::hasNext()
{
}

Trajectory::Next()
{
}

Trajectory::ECET2LLH()
{
}

Trajectory::LLH2ECET()
{
}
