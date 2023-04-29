// Dhruv Rajeshkumar Shah
// 21BCE0611

// Line segment intercept

// Import
#include<bits/stdc++.h>
using namespace std;

typedef struct point{
    int x, y;
} point;

bool onLine(point p, point q, point r) {
    // Check if the point q lies on the line segment pr
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) {
        return true;
    }
    return false;
}

int dir(point p, point q, point r) {
    // Check the direction of the point r with respect to the line segment pq
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) {
        return 0;
    }
    return (val > 0) ? 1 : 2;
}

bool intersect(point p1, point q1, point p2, point q2) {
    // Check if the line segment intersects with the line segment
    int d1 = dir(p1, q1, p2);
    int d2 = dir(p1, q1, q2);
    int d3 = dir(p2, q2, p1);
    int d4 = dir(p2, q2, q1);
    if (d1 != d2 && d3 != d4) {
        return true;
    }
    if (d1 == 0 && onLine(p1, p2, q1)) {
        return true;
    }
    if (d2 == 0 && onLine(p1, q2, q1)) {
        return true;
    }
    if (d3 == 0 && onLine(p2, p1, q2)) {
        return true;
    }
    if (d4 == 0 && onLine(p2, q1, q2)) {
        return true;
    }
    return false;
}


int main() {
    point p1, q1, p2, q2;
    cout << "Enter starting point of line 1: ";
    cin >> p1.x >> p1.y;
    cout << "Enter ending point of line 1: ";
    cin >> q1.x >> q1.y;    
    cout << "Enter starting point of line 2: ";
    cin >> p2.x >> p2.y;
    cout << "Enter ending point of line 2: ";
    cin >> q2.x >> q2.y;

    if (intersect(p1, q1, p2, q2)) {
        cout << "Lines intersect"<<endl;
    } else {
        cout << "Lines do not intersect"<<endl;
    }

    return 0;
}
