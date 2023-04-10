//Dùng lớp Vector thực hiện vector 2 chiều viết các hàm tính toán trên vector như sau

//class Vector {
//    double x_, y_;
//public:
//    Vector(double x = 0, double y = 0);  
//    void print(int precision = 2, bool newLine = true); 
//    Vector& operator=(const Vector& v);    
//    Vector operator+(const Vector& v) const;
//    Vector operator-(const Vector& v) const;
//    Vector& operator+=(const Vector& v);
//    Vector& operator-=(const Vector& v);
//};

//Trong đó:

//    Hàm Vector& operator=(const Vector& v) thay đổi giá trị vector hiện tại cho giống với vector v và trả lại tham chiếu đến vector hiện tại. 
//    Hàm Vector operator+(const Vector& v) const trả lại kết quả là vector tổng của vector hiện tại với vector v. Hàm này không thay đổi giá trị vector hiện tại.
//    Hàm Vector operator-(const Vector& v) const trả lại kết quả là vector hiệu của vector hiện tại với vector v. Hàm này không thay đổi giá trị vector hiện tại.
//    Hàm Vector& operator+=(const Vector& v) cộng thêm vector v vào vector hiện tại (thay đổi nó) và trả lại tham chiếu đến vector hiện tại.
//    Hàm Vector& operator-=(const Vector& v) trừ vector hiện tại (thay đổi nó) đi một lựong là vector v và trả lại tham chiếu đến vector hiện tại.

//    Lưu ý: Bạn chỉ cần viết nội dung của lớp Vector là đ?, các ph?n đ? làm ? bài trư?c có th? sao chép sang bài này.


//For example:
//Test 	Result

//Vector x(1,2), y(3, 3), z;
//z = x + y;
//z.print()

//(4.00, 5.00)



class Vector {
    double x_, y_;
public:
    Vector(double x = 0, double y = 0) {
        x_ = x; y_ = y;
    }
    void print(int precision = 2, bool newLine = true) {
        cout << fixed<<setprecision(precision)<< "(" << x_ << ", " << y_ << ")";
        if (newLine) {
            cout << endl;
        }
    }
    Vector& operator=(const Vector& v) {
        x_ = v.x_;
        y_ = v.y_;
        return *this;
    }    
    Vector operator+(const Vector& v) const {
        return Vector(x_ + v.x_, y_ + v.y_);
    }
    Vector operator-(const Vector& v) const {
        return Vector(x_ - v.x_, y_ - v.y_);
    }
    Vector& operator+=(const Vector& v){
        x_ += v.x_;
        y_ += v.y_;
        return *this;
    }
    Vector& operator-=(const Vector& v) {
         x_ -= v.x_;
        y_ -= v.y_;
        return *this;
    }
};
