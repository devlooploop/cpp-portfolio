
// #7 Rectangle area Through Diagonal and side Area

#include <iostream>
#include <cmath>

using namespace std;

float RectAreaDiagonal(float a, float d) {

	float Area = a * sqrt(pow(d, 2) - pow(a, 2));

	return Area;
}

int main() {
	float x, y;

	cout << "Enter the sides of Rectangle a and b: \n";
	cin >> x;
	cin >> y;

	cout <<"\nThe Area of Rectangle is: " << RectAreaDiagonal(x, y);
}