#include <iostream>
#include "struct.h"

using namespace std; 


int main()
{
	Monomial m;
	int t;
	while (1)
	{
		cout << "Enter 1: Multiply 2 monomials";
		cout << "Enter 2: Divide 2 monomials";
		cout << "Enter 3: First derivative";
		cout << "Enter 4: Input a point";
		cout << "Enter 5:Input and output a point";
		cout << "Enter 6: Distance between 2 points";
		cout << "Enter 7: Quadrant of the point";
		cout << "Enter 8: Input a triangle";
		cout << "Enter 9:Display a triangle";
		cout << "Enter 10:Perimeter of a triangle";
		cout << "Enter 11:Input array points";


		cin >> t;
		if (t == 1)
		{
			int k;
			Monomial m1, m2;
			Input_mono(m1, m2);
			k= Multi(m1, m2);
			cout << m1.a * m1.b << "(x^" << k << ")";
			cout << endl;
		}
		if (t == 2)
		{
			int k;
			Monomial m1, m2;
			Input_mono(m1, m2);
			k = Divi(m1, m2);
			cout << m1.a / m1.b << "(x^" << k << ")";
			cout << endl;
		}
		
		if (t == 3)
		{
			float a1, b1;
			cin >> m.a >> m.b;
			Deri(m, a1, b1);
			cout << a1 << "(x^" << b1 << ")";
			cout << endl;
		}
		if (t == 4)
		{
			Point pt;
			InputPoint(pt);
			cout << endl;
		}

		if (t == 5)
		{
			Point pt;
			InputPoint(pt);
			OutputPoint(pt);
			cout << endl;
		}
		if (t == 6)
		{
			Point pt1, pt2;
			InputPoint(pt1);
			InputPoint(pt2);
			double k=Distance2Point(pt1, pt2);
			cout << k;
		}
		if (t == 7)
		{
			Point pt;
			InputPoint(pt);
			int k = QuadrantofPoint(pt);
			cout << k;

		}
		if (t == 8)
		{
			Triangle triangle;
			InputTriangle(triangle);
		}

		if (t == 10)
		{
			Triangle triangle;
			InputTriangle(triangle);
			double k= TrianglePerimeter( triangle);
			cout << k;

		}
		if (t == 11)
		{
			Point pt[];
			int Size;
			InputArrPoint(pt[], Size);
		}

		if (t == 12)
		{
			Point pt[];
			int Size;
			InputArrPoint(pt[], Size);
			int k= CountPositiveCoordinatesPoint(pt[], Size);
			cout << k;

		}



		

		if (t == 0) break;
	}
	return 0;
}
