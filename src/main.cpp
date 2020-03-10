#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

const double EPS = 1e15;

class Point
{
public:
	Point();
	Point(double x0, double y0);
	double x;
	double y;
	bool operator==(const Point& p1) const {
		if ((this->x == p1.x) && (this->y == p1.y)) {
			return true;
		}
		else {
			return false;
		}
	}
};

Point::Point() {
	x = 0;
	y = 0;
}


Point::Point(double x0, double y0)
{
	x = x0;
	y = y0;
}


class Hash_point
{
public:
	size_t operator()(const Point& p) const
	{
		return std::hash<double>()(p.x+p.y);
	}
};

class Equal_point {
public:
	bool operator()(const Point& p1, const Point& p2) const
	{
		return ((p1.x == p2.x) && (p1.y == p2.y));
	}
};

class Line
{
public:
	Line(long long x1, long long y1, long long  x2, long long y2);
	long long A;
	long long B;
	long long C;

};

Line::Line(long long x1, long long y1, long long  x2, long long y2)
{
	A = y1 - y2;
	B = x2 - x1;
	C = x1 * y2 - x2 * y1;
}


Point cal_intersection(Line line1, Line line2) {
	double x, y, a1, b1, c1, a2, b2, c2;
	a1 = line1.A;
	b1 = line1.B;
	c1 = line1.C;
	a2 = line2.A;
	b2 = line2.B;
	c2 = line2.C;

	x = (c1 * b2 - c2 * b1) / (a2 * b1 - a1 * b2);
	y = (c1 * a2 - c2 * a1) / (a1 * b2 - a2 * b1);
	Point is = Point(x, y);
	return is;
}

int main(int argc, char* argv[])
{
	ifstream in;
	ofstream out;
	in.open(argv[2], ios::in);
	out.open(argv[4], ios::out);
	vector<Line> lines;
	unordered_set<Point,Hash_point, Equal_point> intersections;
	
	int total_count;
	in >> total_count;
	
	int i = 0;
	long long x1, x2, y1, y2;
	char type;
	for (i = 0; i < total_count; i++) {
		in >> type >> x1 >> y1 >> x2 >> y2;
		Line aline = Line(x1, y1, x2, y2);
		lines.push_back(aline);
	}
	
	
	for (i = 0; i < total_count; i++) {
		int j ;
		for (j = i + 1; j < total_count; j++) {
			if ((lines[i].A * lines[j].B - lines[j].A * lines[i].B) != 0) {
				Point is = cal_intersection(lines[i], lines[j]);
				intersections.insert(is);
			}
		}
	}

	int count = intersections.size();
	out << count;
	in.close();
	out.close();
	return 0;
}

