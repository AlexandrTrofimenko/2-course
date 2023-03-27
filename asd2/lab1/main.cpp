#include <iostream>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point
{
	int x, y;
};

Point p0;

int orient(Point& p1, Point& p2, Point& p3) {
	int t = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);
	if (t == 0)
		return 0;
	return (t > 0) ? 1 : 2;
}

int distance(Point& p1, Point& p2) {
	return (p2.x - p1.x) * (p2.y - p1.y);
}

bool cmp(Point& p1, Point& p2) {
	if (orient(p0, p1, p2) == 0) {
		return distance(p0, p1) < distance(p0, p2);
	}
	return (orient(p0, p1, p2) == 2);
}

void convexHull(Point* points,int n) {
	
	int min  = 0;
	int ymin = points[0].y;
	for (int i = 1; i < n; i++) {
		if ((points[i].y < points[0].y) || (points[0].y == points[i].y && points[i].x < points[min].x)) {
			min = i; ymin = points[i].y;
		}
	}
	swap(points[0], points[min]);
	p0 = points[0];
	sort(points + 1, points + n, cmp);
	
	int m = 1;
	for (int i = 1; i < n; i++) {
		while (i < n - 1 && orient(p0, points[i], points[i + 1]) == 0) {
			i++;
		}
		points[m] = points[i];
		m++;
	}
	if (m < 3)
		return;
	stack<Point> S;
	S.push(points[0]);
	S.push(points[1]);
	S.push(points[2]);
	for (int i = 3; i < n; i++) {
		while (orient(S.top(), points[1], points[2]) != 2) {
			S.pop();
		}
		S.push(points[i]);
	}
	cout << "Result of algorithm Graham:" << endl;
	while (!S.empty()) {
		Point p = S.top();
		cout << "(" << p.x << "," << p.y << ")" << endl;
		S.pop();
	}
}

int main()
{
	Point points[] = { 
	{ 0, 3 }, { 1, 1 }, { 2, 2 }, { 4, 4 },
	{ 0, 0 }, { 1, 2 }, { 3, 1 }, { 3, 3 } 
	};
	int n = sizeof(points) / sizeof(points[0]);
	convexHull(points, n);
	return 0;
}