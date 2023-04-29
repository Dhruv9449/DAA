// Dhruv Rajeshkumar Shah
// 21BCE0611

// Jarvis March algorithm for Convex Hull

// Import
#include <bits/stdc++.h>
using namespace std;

// Point class
struct Point
{
        int x;
        int y;
};
 
// To find orientation of ordered triplet (p, q, r).
int direction(Point p, Point q, Point r)
{
    int val =  (r.x - p.x)*(q.y - p.y)  - (q.x - p.x) * (r.y - p.y);
 
    if (val == 0)
        return 0; // collinear
    return (val > 0) ? 1 : 2; // clock or counterclock wise
}
 
// Prints convex hull of a set of n points.
void convexHull(Point points[], int n)
{
    if (n < 3)
        return;
    bool included[n];
    for (int i = 0; i < n; i++)
        included[i] = false;
    int left = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[left].x)
            left = i;
    int prev = left, curr;
    do
    {
        // Find the point 'curr' such that direction(prev, curr, i) is
        // anti-clockwise for all points 'i'
        curr = (prev + 1) % n;
        for (int i = 0; i < n; i++)
            if (direction(points[prev], points[curr], points[i]) == 2)
                curr = i;
 
        included[prev] = true; 
        prev = curr; 
         
    }
    while (prev != left);
 
    for (int i = 0; i < n; i++)
    {
        if (included[i] != false)
            cout << "(" << points[i].x << ", " << points[i].y << ")\n";
    }
}
 
int main()
{
    // Taking input from user
	int n;
	cout<<"Enter the number of points : ";
	cin>>n;
    Point points[n];
    cout<<"Enter the points : \n";
    for(int i=0;i<n;i++)
    {
    	cin>>points[i].x>>points[i].y;
    }
    
    // Print the result
    cout << "The points in the convex hull are: \n";
    convexHull(points, n);
    return 0;
}


// { { 0, 3 }, { 2, 2 }, { 1, 1 }, { 2, 1 }, { 3, 0 },
//             { 0, 0 }, { 3, 3 } };