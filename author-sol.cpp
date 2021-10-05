#include <bits/stdc++.h>

using namespace std;

double TriangleArea(double x1, double y1, double x2, double y2, double x3, double y3) {
	return (0.5 * abs(x1 * y2 - x2 * y1 + x2 * y3 - x3 * y2 + x3 * y1 - x1 * y3));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	double max_area = -DBL_MIN;
	double min_area = DBL_MAX;
	int max_index = 0;
	int min_index = 0;
	// use the formula for finding the area of a triangle from its vertices
	// find the index (1-based) of the smallest and largest area (update the index if there are same areas)
	for (int i = 0; i < n; i++) {
		double x1, y1, x2, y2, x3, y3;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		double triangle_area = TriangleArea(x1, y1, x2, y2, x3, y3);
		if (triangle_area >= max_area) {
			max_area = triangle_area;
			max_index = i + 1;
		}
		if (triangle_area <= min_area) {
			min_area = triangle_area;
			min_index = i + 1;
		}
	}
	cout << min_index << " " << max_index << '\n';
	return 0;
}
