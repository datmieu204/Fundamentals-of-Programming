/*Không dùng thư viện string hay cstring, cài đặt các hàm thành viên cho lớp MyString như sau:

class MyString {
    char *str;
    int len;
public:
    // Hàm khởi tạo xâu rỗng
    MyString();

    // Hàm khởi tạo từ một xâu kiểu c-string
    MyString(const char* );

    // Hàm khởi tạo sao chép từ một thực thể (instance) MyString khác
    MyString(const MyString& );

    // Hàm huỷ
    ~MyString();

    // Toán tử gán
    MyString operator=(const MyString& );
    MyString operator=(const char* );

    // Toán tử nối xâu rồi gán
    MyString operator+=(const MyString& );

    // Toán tử truy cập đến từng kí tự
    char& operator[] (unsigned int index);
    const char& operator[] (unsigned int index) const;

    // Hàm trả về độ dài của xâu
    int size();

    // Hàm trả về 1 thực thể MyString có các kí tự giống thực thể đang xét nhưng các chữ cái viết hoa
    MyString upper() const;

    // Hàm trả về 1 thực thể MyString có các kí tự giống thực thể đang xét nhưng các chữ cái viết thường
    MyString lower() const;

    // Toán tử để in ra màn hình
    friend ostream& operator<< (ostream& , const MyString& );

    // Toán tử nối xâu
    friend MyString operator+ (const MyString& , const MyString& );

    // Các toán tử so sánh
    friend bool operator< (const MyString& , const MyString& );
    friend bool operator> (const MyString& , const MyString& );
    friend bool operator<=(const MyString& , const MyString& );
    friend bool operator>=(const MyString& , const MyString& );
    friend bool operator==(const MyString& , const MyString& );
    friend bool operator!=(const MyString& , const MyString& );
};                                                                                                                                  */

int strlen(const char *str){
    int len = 0;
    while(str[len] != '\0') len++;
    return len;
}

//So sánh 2 xâu theo thứ tự từ điển 
int strcmp(const char* s1 , const char* s2){
    int i = 0;
    while(s1[i] == s2[i]){
        if(s1[i] == '\0') return 0;
        i++;
    }
    return s1[i]-s2[i];
}

//Hàm copy xâu s2 sang s1 
char* strcpy( char* s1 , const char* s2){
    int i = 0;
    while(s2[i] != '\0'){
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return s1;
}


//Hàm nối 2 xâu s2 vào s1 
char* strcat(char* s1, const char* s2){
    int i = 0;
    while(s1[i] != '\0') i++;
    int j = 0;
    while(s2[j] != '\0'){
        s1[i] = s2[j];
        i++;
        j++;
    }
    s1[i] = '\0';
    return s1;
}

//Hàm khởi tạo 
MyString::MyString(){
    len = 0;
    str = new char[len + 1];
    str[0] = '\0';
}

// Hàm khởi tạo từ một xâu kiểu c-string
MyString::MyString(const char* s){
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
}

// Hàm khởi tạo sao chép từ một thực thể (instance) MyString khác
MyString::MyString(const MyString& other){
    len = other.len;
    str = new char[len+1];
    strcpy(str, other.str);
}

// Hàm huỷ
MyString::~MyString(){
    delete[] str;
}

// Toán tử gán
MyString MyString::operator=(const MyString& other){
    if(this != &other){
        delete[] str;
        len = other.len;
        str = new char[len+1];
        strcpy(str, other.str);
    }
    return *this;
}

MyString MyString::operator=(const char* s){
    delete[] str;
    len = strlen(s);
    str = new char[len+1];
    strcpy(str, s);
    return *this;
}

// Toán tử nối xâu rồi gán
MyString MyString::operator+=(const MyString& other){
    len += other.len;
    char *tmp = new char[len+1];
    strcpy(tmp, str);
    strcat(tmp, other.str);
    str = tmp;
    return *this;
}

// Toán tử truy cập đến từng kí tự
char& MyString::operator[] (unsigned int index){
    return str[index];
}
const char& MyString::operator[] (unsigned int index) const{
    return str[index];
}

// Hàm trả về độ dài của xâu
int MyString::size(){
    return len;
}

// Hàm trả về 1 thực thể MyString có các kí tự giống thực thể đang xét nhưng các chữ cái viết hoa
MyString MyString::upper() const{
    MyString tmp(*this); //Tạo 1 thực thể có các kí tự giống với thực thể đang xét 
    for(int i=0; i < len ; i++) 
        if(tmp[i] >= 'a' && tmp[i] <= 'z') tmp[i] -= 32;
    return tmp;
}

// Hàm trả về 1 thực thể MyString có các kí tự giống thực thể đang xét nhưng các chữ cái viết thường
MyString MyString::lower() const{
    MyString tmp(*this);
    for(int i=0; i < len ; i++) 
        if(tmp[i] >= 'A' && tmp[i] <= 'Z') tmp[i] += 32;
    return tmp;
}

// Toán tử để in ra màn hình
ostream& operator<< (ostream& os, const MyString& s){
    os << s.str;
    return os;
}

// Toán tử nối xâu
MyString operator+ (const MyString& s1, const MyString& s2){
    MyString res;
    res.len = s1.len + s2.len;
    res.str = new char[res.len + 1];
    strcpy(res.str, s1.str);
    strcat(res.str, s2.str);
    return res;
}

// Các toán tử so sánh
bool operator< (const MyString& s1, const MyString& s2){
    return strcmp(s1.str, s2.str) < 0;
}

bool operator> (const MyString& s1, const MyString& s2){
    return strcmp(s1.str, s2.str) > 0;
}

bool operator<=(const MyString& s1, const MyString& s2){
    return strcmp(s1.str, s2.str) <= 0;
}

bool operator>=(const MyString& s1, const MyString& s2){
    return strcmp(s1.str, s2.str) >= 0;
}

bool operator==(const MyString& s1, const MyString& s2){
    return strcmp(s1.str, s2.str) == 0;
}

bool operator!=(const MyString& s1, const MyString& s2){
    return strcmp(s1.str, s2.str) != 0;
}














