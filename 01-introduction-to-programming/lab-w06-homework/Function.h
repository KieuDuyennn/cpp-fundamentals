// Lê Phạm Kiều Duyên - 23CLC04
#ifndef FUNCTION_H
#define FUNCTION_H

// Sum of digits. 12345 -> 15, 23 -> 5, 123 -> 6
int tongcs(int n);

// Product of odd digits. 12345 -> 15, 23 -> 3, 34567 -> 105
int tich(int n);

// Smallest digit. 12345 -> 1, 230147 -> 0, 4598621 -> 1
int mi(int n);

// 1 if every digit is odd, otherwise 0
int checkchan(int n);

// Greatest common divisor
int ucln(int a, int b);

// a raised to the power b (b >= 0)
double Pow(double a, int b);

// k!
long long gt(int k);

// 1 if n is a power of 3, otherwise 0
int k3(int n);

// Moves the date forward by n days
void addDay(int& day, int& month, int& year, int n);

// 1 if n is prime, otherwise 0
int checknt(int n);

// Solves ax^2 + bx + c = 0 (a != 0). Returns the number of real roots.
int giaiPT(float a, float b, float c, float& x1, float& x2);

#endif
