#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

pair<int,int> p0;

pair<int,int> beforeTop(stack<pair<int,int> > &s) {
    pair<int,int> top = s.top();
    s.pop();
    pair<int,int> result = s.top();
    s.push(top);
    return result;
}

/*
    if result > 0  =>  C is on the left side of vector ab
    if result = 0  =>  A,B,C collinear
    if result < 0  => C is on the right side of vector ab
*/
int orientationOfPoints(pair<int,int> A, pair<int,int> B, pair<int,int> C) {
    double a1 = B.first - A.first;
    double a2 = B.second - A.second;
    double b1 = C.first - A.first;
    double b2 = C.second - A.second;

    double result = a1*b2 - a2*b1;
    if(result > 0) {
        return 1;
    }else if(result == 0) {
        return 0;
    }else if(result < 0) {
        return -1;
    }

}


double distance(pair<int,int> A, pair<int,int> B) {
    double ABx = B.first - A.first;
    double ABy = B.second - A.second;

    return ABx*ABx + ABy*ABy;
}



bool compare(pair<int,int> A, pair<int,int> B) {

    int orientation = orientationOfPoints(p0,A,B);
    if(orientation == 0) {
        return distance(p0,B) >= distance(p0,A);
    }

    return orientationOfPoints(p0,A,B) == 1;
}

int main() {


    vector<pair<int,int> > points = {{3,3},{5,5},{5,2},{7,0},{1,4},{3,1},{9,6},{0,0}};


    pair<int,int> minY = points[0];
    int indeks = 0;

    for(int i = 1; i < points.size(); i++) {
        if(points[i].second < minY.second) {
            minY = points[i];
            indeks = i;
        }else if(points[i].second == minY.second) {
            if(points[i].first < minY.first) {
               minY = points[i];
               indeks = i;
            }
        }
    }

    pair<int,int> temp = points[0];
    points[0] = minY;
    points[indeks] = temp;

    p0 = minY;

    sort(points.begin()+1,points.end(),compare);


    vector<pair<int,int> > noneCollinearPoints;
    noneCollinearPoints.push_back(p0);
    int i;
    for(i = 1; i < points.size(); i++) {
        while(i < points.size()-1 && orientationOfPoints(p0,points[i],points[i+1]) == 0) {
            i++;
        }
        noneCollinearPoints.push_back(points[i]);

    }

    stack<pair<int,int> > S;
    S.push(noneCollinearPoints[0]);
    S.push(noneCollinearPoints[1]);
    S.push(noneCollinearPoints[2]);

    for(int i = 3; i < noneCollinearPoints.size(); i++) {

        while(orientationOfPoints(beforeTop(S),S.top(),noneCollinearPoints[i]) != 1) {
            S.pop();
        }
        S.push(noneCollinearPoints[i]);
    }

    while(!S.empty()) {
        cout << S.top().first << " " << S.top().second << endl;
        S.pop();
    }


    return 0;
}
