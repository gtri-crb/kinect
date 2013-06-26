// New Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <NuiApi.h>
using namespace std;


double xtotal;
double ytotal;
double ztotal;
int counter = 0;
Vector3D vectorArray[100];

struct Vector3D 
{
	int x;
	int y;
	int z;
} vector;

int main()
{   
	cout << "Hello world" << endl;
	NuiInitialize(NUI_INITIALIZE_FLAG_USES_SKELETON);
	NUI_SKELETON_FRAME ourframe;
	while (1) //For all of time
	{
		xtotal = 0;
		ytotal = 0;
		ztotal = 0;

		NuiSkeletonGetNextFrame(0, &ourframe); //Get a frame and stuff it into ourframe
		for (int j = 0; j <= 19; j++)
		{
			NuiSkeletonGetNextFrame(0, &ourframe); //Get a frame and stuff it into ourframe
			for (int i = 0; i < 1; i++)
			{
		   
			if (ourframe.SkeletonData[i].eTrackingState == NUI_SKELETON_TRACKED) //See more on this line below
			{
			   xtotal += ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HIP_CENTER].x;
			   ytotal += ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HIP_CENTER].y;
			   ztotal += ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HIP_CENTER].z;
			}
			else 
			{
				j -= 1;
			}
			std :: cout << "jvalue: ";
			std :: cout << j;
			std :: cout << "\n";
			std :: cout << "xAverage: ";
			std :: cout << xtotal/j << endl;
			std :: cout << "yAverage: ";
			std :: cout << ytotal/j << endl;
			std :: cout << "zAverage: ";
			std :: cout << ztotal/j << endl;

			}

	    vector.x = xtotal/j;
		vector.y = ytotal/j;
		vector.z = ztotal/j;
	    vectorArray[counter] = vector;
 	    counter = counter + 1;

  		std :: cout << "\ncounter : ";
		std :: cout << counter;

		//end counting when person is close enough to kinect
	    if (vector.z <= 1.2) { 
		    std :: cout << "\n";
			for (int f = 0; f < counter; f ++) {
				cout << vectorArray[f];
				std :: cout << "\n";
				cout << "ok";
				while (true) {}
			}
	    }
	    system("cls");//Clear the screen
	}
	counter ++;
	}

	return 0;
}