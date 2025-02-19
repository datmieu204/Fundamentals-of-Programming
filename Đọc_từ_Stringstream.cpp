/*
Viết hàm double evaluateFractionString(string fraction) để tính giá trị của phân số lưu trong 1 xâu ký tự kiểu string. Xâu này có định dạng a/b
 hoặc −a/b
 với a
 và b
 là các số nguyên dương. Nếu xâu không tuân thủ định dạng này thì hàm cần ném ngoại lệ với thông điệp "Bad fraction string."
Trong bài này bạn chỉ cần viết hàm evaluateFractionString. Chương trình test sẽ đọc dữ liệu từ stdin: dòng đầu là số n
 chỉ định số lượng xâu phân số cần tính giá trị, n
 dòng tiếp theo mỗi dòng chứa 1 xâu phân số. Chương trình test sẽ in kết quả ra stdout tương ứng trên n
 dòng.
 ========================================================================================================================================================================
                                               Input                             	Result
                                               2
                                               1/(2                               Caught Bad fraction string.
                                               2/3                                0.67
 =====================================================================================================================================================================*/

#include<bits/stdc++.h>

using namespace std;

double evaluateFractionString(string fraction){
    //Tạo một đối tượng stringstream từ xâu đầu vào để trích xuất a và b
    stringstream ss(fraction);
    //Các thành phần đc yêu cầu 
    int a, b;
    char c;

    // Đọc a, /, b từ stringstream
    if (!(ss >> a >> c >> b) || c != '/')   throw "Bad fraction string.";
    
    double result = (double)a*1.0 / b;
    
    return result;
}

int main(){
 int n;
 cin >> n;
 cin.ignore();
 for (int i = 0; i < n; i++) {
    string line;
    getline(cin, line);
    // fflush(stdin);
    try {
        double val = evaluateFractionString(line);
        cout << fixed << setprecision(2) << val << endl;
    } catch (const char* str){
        cout << "Caught " << str << endl;
    }
  }
}

