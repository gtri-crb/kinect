// New Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
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

Skeleton bodyArray[1000];

void printSkeleton(Skeleton skel);
void printVector3D(Vector3D vec);

int main()
{   
	cout << "Hello world" << endl;
	NuiInitialize(NUI_INITIALIZE_FLAG_USES_SKELETON);
	NUI_SKELETON_FRAME ourframe;
	while (true) //For all of time
	{
		Skeleton*body = new Skeleton();
		
		NuiSkeletonGetNextFrame(0, &ourframe); //Get a frame and stuff it into ourframe
		for (int j = 0; j <= 2; j++)
		{
			NuiSkeletonGetNextFrame(0, &ourframe); //Get a frame and stuff it into ourframe
			for (int i = 0; i < 1; i++)
			{
		   
			if (ourframe.SkeletonData[i].eTrackingState == NUI_SKELETON_TRACKED) //See more on this line below
			{
			   body->hip.x += ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HIP_CENTER].x;	   		
			   body->hip.y += ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HIP_CENTER].y;
			   body->hip.z += ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HIP_CENTER].z;
			   body->head.x += ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HEAD].x;
			   body->head.y += ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HEAD].y;
			   body->head.z += ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HEAD].z;
			   body->spine.x += ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_SPINE].x;
			   body->spine.y += ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_SPINE].y;
			   body->spine.z += ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_SPINE].z;
			   body->leftfoot.x += ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_ANKLE_LEFT].x;
			   body->leftfoot.y += ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_ANKLE_LEFT].y;
			   body->leftfoot.z += ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_ANKLE_LEFT].z;
			   body->rightfoot.x += ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_ANKLE_RIGHT].x;
			   body->rightfoot.y += ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_ANKLE_RIGHT].y;
			   body->rightfoot.z += ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_ANKLE_RIGHT].z;
			   body->leftknee.x += ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_KNEE_LEFT].x;
			   body->leftknee.y += ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_KNEE_LEFT].y;
			   body->leftknee.z += ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_KNEE_LEFT].z;
			   body->rightknee.x += ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_KNEE_RIGHT].x;
			   body->rightknee.y += ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_KNEE_RIGHT].y;
			   body->rightknee.z += ourframe.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_KNEE_RIGHT].z;
			}
			else 
			{
				j -= 1;
			}
			std :: cout << "jvalue: ";
			std :: cout << j;
			std :: cout << "\n";


			}
			
			cout << body->hip.z << endl;
			if (j == 2){
				body->hip.x /= (j+1);
				body->hip.y /= (j+1);
				body->hip.z /= (j+1);
				body->head.x /= (j+1);
				body->head.y /= (j+1);
				body->head.z /= (j+1);
				body->spine.x /= (j+1);
				body->spine.y /= (j+1);
				body->spine.z /= (j+1);
				body->rightfoot.x /= (j+1);
				body->rightfoot.y /= (j+1);
				body->rightfoot.z /= (j+1);
				body->leftfoot.x /= (j+1);
				body->leftfoot.y /= (j+1);
				body->leftfoot.z /= (j+1);
				body->rightknee.x /= (j+1);
				body->rightknee.y /= (j+1);
				body->rightknee.z /= (j+1);
				body->leftknee.x /= (j+1);
				body->leftknee.y /= (j+1);
				body->leftknee.z /= (j+1);
			}
  		std :: cout << "\ncounter : ";
		std :: cout << counter << endl;



		//end counting when person is close enough to kinect
	    
	    system("cls");//Clear the screen
	}
	    

		bodyArray[counter] = *body;
		//Ends when you get too close
		if (body->hip.z <= 1.0  && counter >= 3) { 

		    std :: cout << "\n";
			//TEST CODES WILL GO HERE

			//main test loop
			double xtotalstr = 0;
			double proptester = 0;
			double scistester = 0;
			double spastesterleft = 0;
			double spastesterright = 0;
			double steptesterleft = 0;
			double steptesterright =0;
			
			for(int e = 0; e < counter; e++)
			{
				bodyArray[e].rightfoot.y = (bodyArray[e].rightfoot.y + bodyArray[e+1].rightfoot.y)/2;


			}

			for (int f = 0; f < counter; f ++) {
				//printSkeleton(bodyArray[f]);
				cout << "\n";
				xtotalstr += bodyArray[f].hip.x	;
				proptester += (bodyArray[f].head.z - bodyArray[f].hip.z);
				scistester += (bodyArray[f].rightknee.x - bodyArray[f].leftknee.x);
				spastesterleft += (bodyArray[f].hip.z - bodyArray[f].leftfoot.z);
				spastesterright += (bodyArray[f].hip.z - bodyArray[f].rightfoot.z);
				steptesterleft += bodyArray[f].leftknee.y;
				steptesterright += bodyArray[f].rightknee.y;
				
			}

			//average to value comparison loop
			double xtotaldev = 0;
			for (int f = 0; f < counter; f++) 
			{
				xtotaldev += abs(xtotalstr/counter - bodyArray[f].hip.x);
			}
			xtotaldev /= counter;
			proptester /= counter;
			scistester /= counter;
			spastesterleft /= counter;
			spastesterright /= counter;
			steptesterleft /= counter;
			steptesterright /= counter;

			cout << "Propulsive Gait Rating: " << proptester << endl;
			cout << "Scissors Gait Rating: " << scistester << endl;
			cout << "Spastic Gait Left Rating: " << spastesterleft << endl;
			cout << "Spastic Gait Right Rating: " << spastesterright << endl;
			cout << "Steppage Gait Left Rating: " << steptesterleft << endl;
			cout << "Steppage Gait Right Rating: " << steptesterright << endl;
			cout << "Dev: " << xtotaldev << endl;
			if (xtotaldev>.04)
			{
				cout << "Go home, you're drunk";
			}
			while (true) {}
	    }
		cout << endl;
				cout << endl;
						cout << endl;
								cout << endl;
		printSkeleton(*body);
		counter ++;

	}

	return 0;
}

void printSkeleton(Skeleton skel)
{
	ofstream myfile;
	myfile.open("shutupkevin.txt",ofstream::ate | ofstream::app);
	//for (int f = 0; f < counter; f++) {
//		getline (myfile,)
	//	myfile << 
//	myfile << "Right Foot: ";
	myfile << skel.rightfoot.y << endl;
//	myfile << "Left Foot: ";
//	myfile << " (" << skel.leftfoot.x << "," << skel.leftfoot.y << "," << skel.leftfoot.z << ")" << endl;
	myfile.close();
	//cout << "Hip: ";
	//printVector3D(skel.hip);
	//cout << "Head: ";
	//printVector3D(skel.head);
	//cout << "Spine: ";
	//printVector3D(skel.spine);
	cout << "Right Foot: ";
	printVector3D(skel.rightfoot);
	cout << "Left Foot: ";
	printVector3D(skel.leftfoot);
	//cout << "Right Knee: ";
	//printVector3D(skel.rightknee);
	//cout << "Left Knee: ";
	//printVector3D(skel.leftknee);

}

void printVector3D(Vector3D vec)
{
	cout << " (" << vec.x << "," << vec.y << "," << vec.z << ")" << endl;
}