#ifndef GEOMETRY_H
#define GEOMETRY_H
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Definition du vecteur 

typedef struct Vec3
{
	float x,y,z;
}Point3D, Vector3D;

// fonction qui construit le point (x,y,z)
Point3D pointXYZ( float x, float y, float z);
// fonction qui construit le vecteur (x,y,z)
Vector3D vectorXYZ( float x, float y, float z);
// fonction qui construit le vecteur AB = B - A
Vector3D vector( Point3D A, Point3D B);
// fonction qui construit le point P + V
Point3D pointPlusVector(Point3D P, Vector3D V);
// fonction d'addition et de soustraction de vecteurs 
Vector3D addVectors(Vector3D A, Vector3D B);
Vector3D subVectors(Vector3D A, Vector3D B);
// fonction de multiplication et de division d'un vecteur par un scalaire 
Vector3D multVector(Vector3D V, float a);
Vector3D divVector(Vector3D V, float a);
// fonction calculant le produit scalaire de deux vecteurs 
float dot(Vector3D A, Vector3D B);
// fonction calculant la norme d'un vecteur
float norm(Vector3D A); 
// fonction retournant le vecteur normalisé passé en paramètre 
Vector3D normalize(Vector3D A);

// fonction de test de toutes les autres fonctions 
void printPoint3D(Point3D p);
void printVector3D(Vector3D v);

#endif 