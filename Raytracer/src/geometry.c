#include "../include/geometry.h"

// fonction qui construit le point (x,y,z)

Point3D pointXYZ( float x, float y, float z)
{
	Point3D point;
	point.x = x;
	point.y = y;
	point.z = z;
	return point;
}

// fonction qui construit le vecteur (x,y,z)

Vector3D vectorXYZ( float x, float y, float z)
{
	Vector3D vecteur;
	vecteur.x = x;
	vecteur.y = y;
	vecteur.z = z;
	return vecteur;
}

// fonction qui construit le vecteur AB = B - A

Vector3D vector( Point3D A, Point3D B)
{
	Vector3D vecteur;
	vecteur.x = B.x - A.x;
	vecteur.y = B.y - A.y;
	vecteur.z = B.z - A.z;
	return vecteur;
}

// fonction qui construit le point P + V

Point3D pointPlusVector(Point3D P, Vector3D V)
{
	Point3D point;
	point.x = P.x + V.x;
	point.y = P.y + V.y;
	point.z = P.z + V.z;
	return point;
}

// fonction d'addition et de soustraction de vecteurs 

Vector3D addVectors(Vector3D A, Vector3D B)
{
	Vector3D vecteur;
	vecteur.x = A.x + B.x;
	vecteur.y = A.y + B.y;
	vecteur.z = A.z + B.z;
	return vecteur;
}

Vector3D subVectors(Vector3D A, Vector3D B)
{
	Vector3D vecteur;
	vecteur.x = A.x - B.x;
	vecteur.y = A.y - B.y;
	vecteur.z = A.z - B.z;
	return vecteur;
}

// fonction de multiplication et de division d'un vecteur par un scalaire

Vector3D multVector(Vector3D V, float a)
{
	Vector3D vecteur;
	vecteur.x = a * V.x;
	vecteur.y = a * V.y;
	vecteur.z = a * V.z;
	return vecteur;
}

Vector3D divVector(Vector3D V, float a)
{
	if (a != 0)
	{
		Vector3D vecteur;
		vecteur.x = V.x / a;
		vecteur.y = V.y / a;
		vecteur.z = V.z / a;
		return vecteur;
	}
	return vectorXYZ(0,0,0);
}

// fonction calculant le produit scalaire de deux vecteurs 

float dot(Vector3D A, Vector3D B)
{
	return ((A.x)*(B.x)+(A.y)*(B.y)+(A.z)*(B.z));
}

// fonction calculant la norme d'un vecteur

float norm(Vector3D A)
{
	return sqrtf(((A.x)*(A.x))+((A.y)*(A.y))+((A.z)*(A.z)));
}

// fonction retournant le vecteur normalisé passé en paramètre 

Vector3D normalize(Vector3D A)
{
	Vector3D vecteur;
	float normeA = norm(A);
	vecteur.x = A.x / normeA;
	vecteur.y = A.y / normeA;
	vecteur.z = A.z / normeA;
	return vecteur;
}

// le produit scalaire c'est la norme de la projection d'un vecteur sur un autre

// fonction de test de toutes les autres fonctions 
void printPoint3D(Point3D p)
{
	printf("(%.1f,%.1f,%.1f) \n", p.x,p.y,p.z);
}

void printVector3D(Vector3D v)
{
	printf("(%.1f,%.1f,%.1f) \n", v.x,v.y,v.z);
}