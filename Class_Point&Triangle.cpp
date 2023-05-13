/*Cài đặt các hàm thành viên cho cấu trúc Point và lớp Triangle sau:

struct Point {
    double x, y;  // Toạ độ x, y
    Point(); // Hàm khởi tạo điểm (0, 0)
    Point(double, double); // Hàm khởi tạo từ toạ độ x, y
    Point(const Point&); // Hàm khởi tạo sao chép từ một thực thể (instance) Point khác
};

class Triangle {
    Point p1, p2, p3;
public:
    Triangle(Point, Point, Point); // Hàm khởi tạo tam giác từ 3 điểm
    double getPerimeter() const;  // Hàm trả về chu vi tam giác
    double getArea() const;  // Hàm trả về diện tích tam giác
};                                                                                            */


Point::Point(){
    	x = 0;
    	y = 0;
    }
    
Point::Point(double x_, double y_){
    	x = x_;
    	y = y_;
    }
    
Point::Point(const Point& other){
    	x = other.x;
    	y = other.y;
    }
    
Triangle::Triangle(Point a, Point b, Point c){
    	p1 = a;
    	p2 = b;
    	p3 = c;
    }
    
double Triangle:: getPerimeter() const{
		double u = sqrt((p2.x-p1.x)*(p2.x-p1.x) + (p2.y-p1.y)*(p2.y-p1.y));
		double i = sqrt((p3.x-p1.x)*(p3.x-p1.x) + (p3.y-p1.y)*(p3.y-p1.y));
		double o = sqrt((p3.x-p2.x)*(p3.x-p2.x) + (p3.y-p2.y)*(p3.y-p2.y));
		
		return u + i + o;
	}
	
double Triangle::getArea() const{
		double p = 0;
		double s = 1;
		
		double u = sqrt((p2.x-p1.x)*(p2.x-p1.x) + (p2.y-p1.y)*(p2.y-p1.y));
		double i = sqrt((p3.x-p1.x)*(p3.x-p1.x) + (p3.y-p1.y)*(p3.y-p1.y));
		double o = sqrt((p3.x-p2.x)*(p3.x-p2.x) + (p3.y-p2.y)*(p3.y-p2.y));
		
		p = (u + i + o)/2;
		s = sqrt(p*(p-u)*(p-i)*(p-o));
		return s;
	}
  
  
 /*==============================================================================================================================
#include<bits/stdc++.h>

using namespace std;

struct Point {
    double x, y;  // To? d? x, y
    Point(){
    	x = 0;
    	y = 0;
    }
    Point(double x_, double y_){
    	x = x_;
    	y = y_;
    }
    Point(const Point& other){
    	x = other.x;
    	y = other.y;
    }
};

class Triangle {
    Point p1, p2, p3;
public:
    Triangle(Point a, Point b, Point c){
    	p1 = a;
    	p2 = b;
    	p3 = c;
    }
    
    double getPerimeter() const{
		double ans = 0;
		double x = sqrt((p2.x-p1.x)*(p2.x-p1.x) + (p2.y-p1.y)*(p2.y-p1.y));
		double y = sqrt((p3.x-p1.x)*(p3.x-p1.x) + (p3.y-p1.y)*(p3.y-p1.y));
		double z = sqrt((p3.x-p2.x)*(p3.x-p2.x) + (p3.y-p2.y)*(p3.y-p2.y));
		ans = x + y + z;
		return ans;
	}
	
	double getArea() const{
		double p = 0;
		double s = 1;
		
		double x = sqrt((p2.x-p1.x)*(p2.x-p1.x) + (p2.y-p1.y)*(p2.y-p1.y));
		double y = sqrt((p3.x-p1.x)*(p3.x-p1.x) + (p3.y-p1.y)*(p3.y-p1.y));
		double z = sqrt((p3.x-p2.x)*(p3.x-p2.x) + (p3.y-p2.y)*(p3.y-p2.y));
		
		p = (x+y+z)/2;
		s = sqrt(p*(p-x)*(p-y)*(p-z));
		return s;
		
	}
};

int main(){
	Point A(-1,0), B(1, 0), C(0, 1);
	Triangle tri(A, B, C);
	cout << tri.getPerimeter() << endl;
	cout << tri.getArea() << endl; 
	return 0;
}*/
