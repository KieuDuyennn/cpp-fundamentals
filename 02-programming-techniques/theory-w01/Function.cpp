#include "Function.h"
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


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

// Find the upper-left corner of the bounding box (smallest x, largest y).
Point findUpperLeft(const Plantation& p) {
    Point upperLeft = p.trees[0].location;
    for(int i = 1; i < p.count; i++) {
        if(p.trees[i].location.x < upperLeft.x) upperLeft.x = p.trees[i].location.x;
        if(p.trees[i].location.y > upperLeft.y) upperLeft.y = p.trees[i].location.y;
    }
    return upperLeft;
}

// Find the lower-right corner of the bounding box (largest x, smallest y).
Point findLowerRight(const Plantation& p) {
    Point lowerRight = p.trees[0].location;
    for(int i = 1; i < p.count; i++) {
        if(p.trees[i].location.x > lowerRight.x) lowerRight.x = p.trees[i].location.x;
        if(p.trees[i].location.y < lowerRight.y) lowerRight.y = p.trees[i].location.y;
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


// File format: the number of trees, then one "x y type" line per tree.
void readData(Plantation &p, const string &filename)
{
    p.count = 0;
    ifstream ifs(filename);
    int n = 0;
    if (!(ifs >> n)) return;
    if (n > 100) n = 100;
    for (int i = 0; i < n && ifs >> p.trees[i].location.x >> p.trees[i].location.y >> p.trees[i].type; ++i)
        p.count++;
}

void writeData(const Plantation &p, const string &filename)
{
    ofstream ofs(filename);
    if (p.count == 0) {
        ofs << "0 0" << endl;
        return;
    }
    ofs << countCoffeeTrees(p) << " " << countTeaTrees(p) << endl;
    ofs << calcFenceLength(p) << endl;
    ofs << calculateTotalLength(p) << endl;
}
