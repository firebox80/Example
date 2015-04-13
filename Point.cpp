#include <iostream>
#include <cmath>

using namespace std;
	
class Point {
	private:
		double x, y;
				
	public:
		Point() : x(0), y(0) {}
		Point(double i, double j) : x(i), y(j) {}
		~Point() {} 
		 
		bool operator==(const Point& other) const {
		    return x == other.x && y == other.y;
		}

		bool operator!=(const Point& other) const {
		    return !(*this == other);
		}		

		double getDistance(const Point& other) const {
		    return hypot(x-other.x, y-other.y);
		}

		void getX( double t ) { x = t; }
		void getY( double t ) { y = t; }
	
		double showX() const { return x; }
		double showY() const { return y; }
};

	istream& operator>>(istream& in, Point& point){
		double x , y;
	    in >> x >> y;
		point.getX(x); 
		point.getY(y);
                 	
	return in;
}
	ostream& operator<<(ostream& out, const Point& point){
		out << '(' << point.showX() << ", " << point.showY() << ')';
	
	return out;
	}

int main() {
	Point a;
	Point b;

	cin >> a;
	cin >> b;
	
	cout << a << endl;
	cout << b << endl;
	
	if ( a != b ) {
		cout << a << "different from" << b << endl;
	} else {
		cout << a << "equals" << b << endl;
	}

	cout << "Distance is " << a.getDistance(b) << endl;

	return 0;
}
/*
Условие задачи
С помощью известных вам инструментов реализовать тип Point (точка на координатной плоскости)
координатами x, y типа double.
Также реализовать следующие функции:

void pointPrint(Point a) - печать точки в виде (x, y). Воспользоваться шаблоном %g.
int pointEqual(Point a, Point b) - сравнение двух точек по координатам (равны или не равны).
double pointDistance(Point a, Point b) - нахождение расстояния между двумя точками.
Воспользоваться функцией hypot() из библиотеки math.h
*/