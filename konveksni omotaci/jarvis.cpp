#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;



/*
    if result > 0  =>  C is on the left side of vector ab
    if result = 0  =>  A,B,C collinear
    if result < 0  => C is on the right side of vector ab
*/
double orientationOfPoints(pair<int,int> A, pair<int,int> B, pair<int,int> C) {
    double a1 = B.first - A.first;
    double a2 = B.second - A.second;
    double b1 = C.first - A.first;
    double b2 = C.second - A.second;

    return a1*b2 - a2*b1;

}



/*
    function return -1 if 'B' is closer to 'A' compared to 'C'
    function return 0 if if 'B' and 'C' are on the same distance from 'A'
    function return 1 if 'C' is closer to 'A' compared to 'B'
*/
int distance(pair<int,int> A, pair<int,int> B, pair<int,int> C) {
    double ABx = B.first - A.first;
    double ABy = B.second - A.second;
    double ACx = C.first - A.first;
    double ACy = C.second - A.second;

    double distanceAB = sqrt(ABx*ABx + ABy*ABy);
    double distanceAC = sqrt(ACx*ACx + ACy*ACy);
    if(distanceAB < distanceAC) {
        return -1;
    }else if(distanceAB == distanceAC) {
        return 0;
    }else {
        return 1;
    }
}


set<pair<int,int> > Jarvis(vector<pair<int,int> > &points) {

    pair<int,int> start = points[0];
    for(int i = 1; i < points.size(); i++) {
        if(points[i].first < start.first) {
            start = points[i];
        }
    }


    pair<int,int> current = start;
    set<pair<int,int> > result;
    result.insert(start);
    vector<pair<int,int> > collinearPoints;

    while(true) {

        pair<int,int> nextTarget = points[0];
        for(int i = 1; i < points.size(); i++) {
            if(points[i] == current) {
                continue;
            }

            double value = orientationOfPoints(current,nextTarget,points[i]);
            if(value > 0) {
                nextTarget = points[i];
                collinearPoints.clear();
            }else if(value == 0) {
                if(distance(current,nextTarget,points[i]) == -1) {
                    collinearPoints.push_back(nextTarget);
                    nextTarget = points[i];
                }else if(distance(current,nextTarget,points[i]) == 1){
                    collinearPoints.push_back(points[i]);
                }

            }

        }

        for(int i = 0; i < collinearPoints.size(); i++) {
            result.insert(collinearPoints[i]);
        }

        if(nextTarget == start) {
            break;
        }

        result.insert(nextTarget);
        current = nextTarget;

    }

    return result;

}



int main() {

    vector<pair<int,int> > points = { {2,3}, {0,0}, {4,-2},{1,-5}, {1,5}, {2,1}, {4,1}, {4,3}, {-4,1} };

    set<pair<int,int> > result = Jarvis(points);

    for(auto it = result.begin(); it != result.end(); it++) {
        cout << (*it).first << " " << (*it).second << endl;
    }





    return 0;
}
