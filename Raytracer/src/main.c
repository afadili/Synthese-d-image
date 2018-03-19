#include <stdlib.h>
#include <stdio.h>
#include "../include/geometry.h"
#include "../include/colors.h"

int main (int argc, char ** argv)
{
	Point3D test;
	test = pointXYZ(0,0,0);
	printPoint3D(test);
	Vector3D testv;
	testv = vectorXYZ(1,2,0);
	printVector3D(testv);
	Point3D result;

	result = pointPlusVector(test, testv);
	printf("test de pointPlusVector :\n");
	printPoint3D(result);
	printf("test de addVectors :\n");
	result = addVectors(vectorXYZ(0.5,1.0,-2.0),vectorXYZ(0.2,-1.0,0));
	printVector3D(result);
	printf("test de subVectors :\n");
	result = subVectors(vectorXYZ(0.5,1.0,-2.0),vectorXYZ(0.2,-1.0,0));
	printVector3D(result);
	printf("test de multVector :\n");
	result = multVector(vectorXYZ(0.5,1.0,-2.0),2.0);
	printVector3D(result);
	printf("test de multVector:\n");
	result = multVector(vectorXYZ(0.5,1.0,-2.0),0.0);
	printVector3D(result);
	printf("test de divVector :\n");
	result = divVector(vectorXYZ(0.5,1.0,-2.0),2.0);
	printVector3D(result);
	printf("test de divVector :\n");
	result = divVector(vectorXYZ(0.5,1.0,-2.0),0.0);
	printVector3D(result);
	printf("test de dot : %.1f \n",dot(vectorXYZ(1.0,0.0,0.0),vectorXYZ(2.0,0.0,0.0)));
	printf("test de dot2 : %.1f \n",dot(vectorXYZ(1.0,0.0,0.0),vectorXYZ(0.0,1.0,0.0)));
	printf("test de norm : %.1f \n",norm(vectorXYZ(2.0,0.0,0.0)));
	printf("test de norm2 :%.1f \n",norm(vectorXYZ(1.0,1.0,1.0)));
	printf("test de norm3 :%.1f \n",norm(vectorXYZ(0.0,0.0,0.0)));
	printf("test de normalize :\n");
	testv = normalize(vectorXYZ(1.0,1.0,1.0));
	printVector3D(testv);
	printf("test de normalize2 :\n");
	testv = normalize(vectorXYZ(0.0,0.0,0.0));
	printVector3D(testv);
	return 0;
}