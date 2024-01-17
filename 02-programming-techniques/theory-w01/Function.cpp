#include <iostream>
#include <fstream>
#include <cmath>

// Declare struct

// Count trees of a specific type.
int countTrees(const Plantation& p, int type) {
    int count = 0;
    for(int i = 0; i < p.count; i++) {
        if(p.trees[i].type == type) {
            count++;
        }
    }
    return count;
}

// Count coffee trees.
int countCoffeeTrees(const Plantation& p) {
    return countTrees(p, 0);
}

// Count tea trees.
int countTeaTrees(const Plantation& p) {
    return countTrees(p, 1);
}

// Find upper left point.
Point findUpperLeft(const Plantation& p) {
    Point upperLeft = p.trees[0].location;
    for(int i = 1; i < p.count; i++) {
        if(p.trees[i].location.x < upperLeft.x || p.trees[i].location.y > upperLeft.y) {
            upperLeft = p.trees[i].location;
        }
    }
    return upperLeft;
}

// Find lower right point.
Point findLowerRight(const Plantation& p) {
    Point lowerRight = p.trees[0].location;
    for(int i = 1; i < p.count; i++) {
        if(p.trees[i].location.x > lowerRight.x || p.trees[i].location.y < lowerRight.y) {
            lowerRight = p.trees[i].location;
        }
    }
    return lowerRight;
}

// Calculate perimeter of rectangular fence.
float calcFenceLength(const Plantation& p) {
    Point upperLeft = findUpperLeft(p);
    Point lowerRight = findLowerRight(p);
    return 2 * (fabs(upperLeft.x - lowerRight.x) + fabs(upperLeft.y - lowerRight.y));
}

// Calculate distance between two points.
float distance(const Point& p, const Point& q) {
    return sqrt(pow(p.x - q.x, 2) + pow(p.y - q.y, 2));
}

// Calculate total length of tubes.
float calculateTotalLength(const Plantation& p) {
    Point pump = findPump(p);
    float totalLength = 0;
    for(int i = 0; i < p.count; i++) {
        totalLength += distance(pump, p.trees[i].location);
    }
    return totalLength;
}

// Find position of the pump.
Point findPump(const Plantation& p) {
    float x = 0;
    float y = 0;
    for(int i = 0; i < p.count; i++) {
        x += p.trees[i].location.x;
        y += p.trees[i].location.y;
    }
    Point pump = {x / p.count, y / p.count};
    return pump;
}


void readData (Plantation &p, const string &filename)
{
	ifstream ifs (filename);
	ifs.open();
	for (int i=0;i<p.N;++i)
	{
		ifs>>p.trees[i].location.x>>p.trees[i].location.y >> p.trees[i].type;
	}
	ifs.close();
 } 
 void writeData (const Plantation &p,const string &filename)
 {
 	ofstream ofs;
 	ofs.open();
 	int s0 = countCoffeeTrees(p);
 	int s1 = countTeaTrees(p);
 	ofs << s0 << " "<< s1<<endl;
 	float Cmin= calcFenceLength (p);
 	ofs<<Cmin<<endl;
 	float Dmin = calculateTotalLength (o);
 	ofs<<Dmin<<endl;
 	ofs.close ();
 }
