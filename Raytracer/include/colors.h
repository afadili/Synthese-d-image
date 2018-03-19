#ifndef COLORS_H
#define COLORS_H
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Color3f
{
	float r,g,b;
}Color3f;

// fonction qui calcule la somme de deux couleurs 
Color3f addColors(Color3f c1, Color3f c2);
// fonction qui fait la multiplication et soustraction de deux couleurs
Color3f subColors(Color3f c1, Color3f c2);
Color3f multColors(Color3f c1, Color3f c2);
// fonction qui fait la multiplication et la division d'une couleur avec un scalaire 
Color3f multColor(Color3f c, float a);
Color3f divColor(Color3f c, float a);

#endif 