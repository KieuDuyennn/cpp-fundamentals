#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>

struct Point {
    float x;
    float y;
};

struct Tree {
    Point location;
    int type;
};

struct Plantation {
    Tree trees[100];
    int count;
};
int countTrees(const Plantation& p, int type) ;
int countCoffeeTrees(const Plantation& p);
int countTeaTrees(const Plantation& p);
Point findUpperLeft(const Plantation& p);
Point findLowerRight(const Plantation& p) ;
float calcFenceLength(const Plantation& p);
float distance(const Point& p, const Point& q);
float calculateTotalLength(const Plantation& p);
Point findPump(const Plantation& p);
void readData (Plantation &p, const std::string &filename);
 void writeData (const Plantation &p,const std::string &filename);

#endif
