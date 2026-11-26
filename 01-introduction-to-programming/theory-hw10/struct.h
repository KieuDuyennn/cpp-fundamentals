#pragma once
#include <iostream>
#include <cmath>
struct Monomial
{
	float a;
	float b;
};
void Input_mono(Monomial& m1, Monomial& m2);
float Multi(Monomial& m1, Monomial& m2);
float Divi(Monomial& m1, Monomial& m2);
void Deri(Monomial& m, float &a1, float& b1);

struct Point {
	double x, y;
};

void InputPoint(Point& pt);
void OutputPoint(Point pt);
double Distance2Point(Point ptA, Point ptB);
int QuadrantofPoint(Point pt);
struct Triangle {
	Point pt[3];
};

void InputTriangle(Triangle& triangle);
double TrianglePerimeter(Triangle triangle);
const int MAX_POINTS = 100;

void InputArrPoint(Point pt[], int& Size);
int CountPositiveCoordinatesPoint(Point pt[], int Size);
Point FindLargestx_componentValuePoint(Point pt[], int Size);
Point FindSmallestx_componentValuePoint(Point pt[], int Size);
