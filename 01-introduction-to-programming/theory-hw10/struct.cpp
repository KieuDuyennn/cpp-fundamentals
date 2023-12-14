#include <iostream>
#include "struct.h"

using namespace std;


// monomials
void Input_mono(Monomial& m1, Monomial& m2)
{
	cin >> m1.a >> m1.b;
	cin >> m2.a >> m2.b;
}

float Multi(Monomial& m1, Monomial& m2)
{
	float k = m1.b + m2.b;
	return k;

}

float Divi(Monomial& m1, Monomial& m2)
{
	float k = m1.b - m2.b;
	return k;
}

void Deri(Monomial& m, float &a1, float &b1)
{
	a1 = m.a * m.b;
	b1 = m.b - 1;
}

// points


void InputPoint(Point& pt)
{
	cout << "Nhap hoanh do x cua diem: ";
	cin >> pt.x;
	cout << "Nhap tung do y cua diem: ";
	cin >> pt.y;
}

void OutputPoint(Point pt)
{
	cout << "Toa do cua diem la: [" << pt.x << "," << pt.y << "]";
}

double Distance2Point(Point ptA, Point ptB)
{
	return sqrt((ptA.x - ptB.x) * (ptA.x - ptB.x) + (ptA.y - ptB.y) * (ptA.y - ptB.y));
}

int QuadrantofPoint(Point pt)
{
	if (pt.x > 0 && pt.y > 0) return 1; // I
	if (pt.x < 0 && pt.y > 0) return 2; // II
	if (pt.x < 0 && pt.y < 0) return 3; // III
	if (pt.x > 0 && pt.y < 0) return 4; // IV
	return 0;	// diem tren truc toa do
}



void InputTriangle(Triangle& triangle)
{
	cout << "Nhap toa do 3 diem cua tam giac: ";
	for (int i = 0; i < 3; i++)
	{
		cout << "Nhap toa do diem thu" << i << ": ";
		InputPoint(triangle.pt[i]);
	}
}

double TrianglePerimeter(Triangle triangle)
{
	double Perimeter = 0;
	for (int i = 0; i < 3; i++)
		Perimeter += Distance2Point(triangle.pt[i % 3], triangle.pt[(i + 1) % 3]);
	return Perimeter;
}


void InputArrPoint(Point pt[], int Size)
{
	for (int i = 0; i < Size; i++) InputPoint(Point pt[i]);
}

int CountPositiveCoordinatesPoint(Point pt[], int Size)
{
	int Count = 0;
	for (int i = 0; i < Size; i++)
		if (pt[i].x > 0 && pt[i].y > 0) count++;
	return Count;
}

Point FindLargestx_componentValuePoint(Point pt[], int Size)
{
	Point Res = pt[0];
	for (int i = 1; i < Size; i++)
		if (pt[i].x > Res.x) Res = pt[i];
	return Res;
}

Point FindSmallestx_componentValuePoint(Point pt[], int Size)
{
	Point Res = pt[0];
	for (int i = 1; i < Size; i++)
		if (pt[i].x < Res.x) Res = pt[i];
	return Res;
}


