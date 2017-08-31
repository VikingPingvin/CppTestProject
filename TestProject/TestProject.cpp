// TestProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <Windows.h>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string outputString;
void buildString();
void readTrajectoryFile();
void writeDebugOutput(string out);

struct Position
{
	int WN;
	int ToW;
	int ECEF_x, ECEF_y, ECEF_z;
	int LLH_lat, LLH_long, LLH_height;
};

int main()
{
	ofstream file;

	AllocConsole();
	writeDebugOutput("Debug console Initialized!");

	buildString();
	file.open("Trajectory_LLH.txt");
	file << outputString << endl;
	file.close();
	readTrajectoryFile();
	getchar();
	return 0;
}

void buildString() {
	ostringstream oss;
	int weekNumber = 19444;
	int ttow = 100000;
	int tlat = 45;
	int tlong = 55;
	int theight = 101;

	oss << "WN" << ' ' << "ToW" << ' ' << "LLH/ECEF" << endl;
	for (int i = 1; i < 300; i++) {
		oss << to_string(weekNumber) << ' ' << to_string(ttow++) << ' ' << to_string(tlat++) << ' ' << to_string(tlong++) << ' ' << to_string(theight) << endl;
	}
	outputString = oss.str();
	writeDebugOutput("LLH file generated.");
}

void readTrajectoryFile() {
	ifstream file;
	string input;
	Position currPos = { 0,0,0,0,0 };

	file.open("Trajectory_LLH.txt");
	while (getline(file,input)) {
		//writeDebugOutput(input);		
		sscanf_s(input.c_str(), "%i %i %i %i %i", &currPos.WN, &currPos.ToW, &currPos.LLH_lat, &currPos.LLH_long, &currPos.LLH_height);
		cout << "WN: " << currPos.WN << " TOW: " << currPos.ToW << " LAT: " << currPos.LLH_lat << " LONG: " << currPos.LLH_long << endl;
	}
	file.close();

}

void LLH2ECEF() {

}

void writeDebugOutput(string out) {
	cout << out << endl;
}

