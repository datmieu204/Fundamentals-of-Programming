/*
Viết hàm lọc ký tự phía bên phải xâu dùng con trỏ void rFilter(char *s).

Yêu cầu:
 Hàm nhận vào một con trỏ đến một xâu ký tự (không chứa dấu cách) có độ dài không quá 5050 ký tự.
 Lọc các ký tự không nằm trong bảng chữ cái tiếng Anh (a-zA-Z) nằm ngoài cùng bên phải xâu, chuyển thành '_'.
 Sinh viên KHÔNG được truy cập xâu ký tự bằng cách truy cập mảng thông thường (phải dùng toán tử * và & với con trỏ).
 Sinh viên KHÔNG được phép dùng biến đếm (Ví dụ: i, j,...), thay vào đó dùng con trỏ để duyệt xâu.
 Sinh viên KHÔNG dùng thêm bất kỳ thư viện nào. Các thư viện có sẵn gồm: <iostream> và <cstring>.
 */

#include<iostream>
#include<cstring>

//cách1 :
void rFilter(char *s) {
    // Tìm đến vị trí ký tự cuối cùng trong bảng chữ cái tiếng Anh
    char *lastChar = s;
    while (*lastChar) {
        lastChar++;
    }
    lastChar--;//trừ đi vị trí cuối là NULL 
    
    //lastChar là con trỏ trỏ tới xâu s 
    while (lastChar >= s) {
        if ((*lastChar >= 'a' && *lastChar <= 'z') ||
            (*lastChar >= 'A' && *lastChar <= 'Z')) {
            break;
        } else {
            *lastChar = '_';
            lastChar--;
        }
    }
}


/*cách 2:
  void rFilter(char *s){ 
      for(char *p = &s[strlen(s)-1] ; p >= &s[0]; p--){    //Duyệt từ phải qua trái 
          if(('a' <= *p && *p <= 'z') || (*p <= 'Z' && *p >= 'A')) break;
          *p = '-';
       }    
  }
*/

int main(){
    char *s;
    s = new char[50];
    cin >> s;
    rFilter(s);
    cout << s;
}
