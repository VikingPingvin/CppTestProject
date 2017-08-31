#pragma once
class Trajectory
{
public:
	Trajectory();
	~Trajectory();

	hasNext();
	Next();

private:
	ECET2LLH();
	LLH2ECET();
};

