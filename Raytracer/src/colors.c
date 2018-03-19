#include <../include/colors.h>

// fonction qui calcule la somme de deur couleurs 

Color3f addColors(Color3f c1, Color3f c2)
{
	Color3f color;
	color.r = c1.r + c2.r;
	color.g = c1.g + c2.g;
	color.b = c1.b + c2.b;
	return color;
}

// fonction qui fait la multiplication et soustraction de deux couleurs

Color3f subColors(Color3f c1, Color3f c2)
{
	Color3f color;
	color.r = c1.r - c2.r;
	color.g = c1.g - c2.g;
	color.b = c1.b - c2.b;
	return color;
}

Color3f multColors(Color3f c1, Color3f c2)
{
	Color3f color;
	color.r = c1.r * c2.r;
	color.g = c1.g * c2.g;
	color.b = c1.b * c2.b;
	return color;
}

// fonction qui fait la multiplication et la division d'une couleur avec un scalaire 

Color3f multColor(Color3f c, float a)
{
	Color3f color;
	color.r = a * c.r;
	color.g = a * c.g;
	color.b = a * c.b;
	return color;
}

Color3f divColor(Color3f c, float a)
{
	Color3f color;
	if (a != 0)
	{
		color.r = c.r / a;
		color.g = c.g / a;
		color.b = c.b / a;
	}
	else 
	{
		color.r = 0;
		color.g = 0;
		color.b = 0;
	}
	return color;
}