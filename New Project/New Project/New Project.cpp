// New Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <NuiApi.h>
using namespace std;



int counter = 0;

struct Vector3D 
{
	double x;
	double y;
	double z;
	Vector3D()
	{
		x = 0;
		y = 0;
		z = 0;
	}
};

struct Skeleton
{
	Vector3D hip;
	Vector3D head;
	Vector3D spine;
	Vector3D leftfoot;
	Vector3D rightfoot;
	Vector3D leftknee;
	Vector3D rightknee;
	Skeleton()
	{
		hip = Vector3D();
		head = Vector3D();
		spine = Vector3D();
		leftfoot = Vector3D();
		rightfoot = Vector3D();
		leftknee = Vector3D();
		rightknee = Vector3D();
	} 
} body;

Skeleton bodyArray[100];


int main()
{   
	cout << "Hello world" << endl;
	NuiInitialize(NUI_INITIALIZE_FLAG_USES_SKELETON);
	NUI_SKELETON_FRAME ourframe;
	while (1) //For all of time
	{
		body = Skeleton();

		NuiSkeletonGetNextFrame(0, &ourframe); //Get a frame and stuff it into ourframe
		for (int j = 0; j <= 9; j++)
		{
			NuiSkeletonGetNextFrame(0, &ourframe); //Get a frame and stuff it into ourframe
			for (int i = 0; i < 1; i++)
			{
		   
			if (ourframe.SkeletonData[i].eTrackingState == NUI_SKELETON_TRACKED) //See more on this line below
			{
			   body.hip.x += ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HIP_CENTER].x;
			   body.hip.y += ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HIP_CENTER].y;
			   body.hip.z += ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HIP_CENTER].z;
			   body.head.x += ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HEAD].x;
			   body.head.y += ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HEAD].y;
			   body.head.z += ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HEAD].z;
			   body.spine.x += ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_SPINE].x;
			   body.spine.y += ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_SPINE].y;
			   body.spine.z += ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_SPINE].z;
			   body.leftfoot.x += ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_FOOT_LEFT].x;
			   body.leftfoot.y += ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_FOOT_LEFT].y;
			   body.leftfoot.z += ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_FOOT_LEFT].z;
			   body.rightfoot.x += ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_FOOT_RIGHT].x;
			   body.rightfoot.y += ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_FOOT_RIGHT].y;
			   body.rightfoot.z += ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_FOOT_RIGHT].z;
			   body.leftknee.x += ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_KNEE_LEFT].x;
			   body.leftknee.y += ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_KNEE_LEFT].y;
			   body.leftknee.z += ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_KNEE_LEFT].z;
			   body.rightknee.x += ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_KNEE_RIGHT].x;
			   body.rightknee.y += ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_KNEE_RIGHT].y;
			   body.rightknee.z += ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_KNEE_RIGHT].z;
			}
			else 
			{
				j -= 1;
			}
			std :: cout << "jvalue: ";
			std :: cout << j;
			std :: cout << "\n";


			}

	    body.hip.x /= j;
		body.hip.y /= j;
		body.hip.z /= j;
		body.head.x /= j;
		body.head.y /= j;
		body.head.z /= j;
		body.spine.x /= j;
		body.spine.y /= j;
		body.spine.z /= j;
		body.rightfoot.x /= j;
		body.rightfoot.y /= j;
		body.rightfoot.z /= j;
		body.leftfoot.x /= j;
		body.leftfoot.y /= j;
		body.leftfoot.z /= j;
		body.rightknee.x /= j;
		body.rightknee.y /= j;
		body.rightknee.z /= j;
		body.leftknee.x /= j;
		body.leftknee.y /= j;
		body.leftknee.z /= j;


  		std :: cout << "\ncounter : ";
		std :: cout << counter;


		//end counting when person is close enough to kinect
	    
	    system("cls");//Clear the screen
	}
	    
		
		bodyArray[counter] = body;
		if (body.hip.z <= 1.1  && counter >= 3) { 
		    std :: cout << "\n";
			//TEST CODES WILL GO HERE


			double xtotalstr = 0;
			for (int f = 0; f < counter; f ++) {
				printSkeleton(bodyArray[f]);
				cout << "\n";
				xtotalstr += bodyArray[f].hip.x;	
			}
			double xtotaldev = 0;
			for (int f = 0; f < counter; f++) 
			{
				xtotaldev += abs(xtotalstr/counter - bodyArray[f].hip.x);
			}
			xtotaldev /= counter;
			cout << "Dev: " << xtotaldev << endl;
			if (xtotaldev>.04)
			{
				cout << "Go home, you're drunk";
			}
			while (true) {}
	    }
		counter ++;

	}

	return 0;
}

void printSkeleton(Skeleton skel)
{
	cout << "Hip: ";
	printVector3D(body.hip);
	cout << "Head: ";
	printVector3D(body.head);
	cout << "Spine: ";
	printVector3D(body.spine);
	cout << "Right Foot: ";
	printVector3D(body.rightfoot);
	cout << "Left Foot: ";
	printVector3D(body.leftfoot);
	cout << "Right Knee: ";
	printVector3D(body.rightknee);
	cout << "Left Knee: ";
	printVector3D(body.leftknee);

}

void printVector3D(Vector3D vec)
{
	cout << " (" << vec.x << "," << vec.y << "," << vec.z << ")" << endl;
}