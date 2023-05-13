#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int compareAbs(string a, string b){
    if (a.length() > b.length())
        return 1;
    if (a.length() < b.length())
        return -1;
    return a.compare(b);
}

string add(string a, string b){
    string c ;
    long long n1 = a.length(), n2 = b.length() , nho = 0 , Tong;

    if(n1 > n2) b.insert(0,n1-n2,'0');
    if(n1 < n2) a.insert(0,n2-n1,'0');
    c=a;
     
    for(int i = a.length()-1; i>= 0; i--){
        Tong = (a[i] - 48) + (b[i] - 48) + nho;
        nho = Tong/10;
        Tong = Tong%10;
        c[i] = char(Tong+48);
    }

    if(nho > 0) c = char(nho + 48) + c;
    return c;
}


// alwways a-b . Xet a luon luon > b
string subtract(string a, string b){
    string c = "";
    if (compareAbs(a, b) < 0)  swap(a, b);
    
    long long n1 = a.length(), n2 = b.length(), Muon = 0 ,Hieu;
    if(n1 > n2) b.insert(0,n1-n2,'0');
    
    for(int i = a.length()-1 ; i>= 0 ; i--){
        Hieu = (a[i] - 48) -(b[i] - 48) - Muon;
        if(Hieu < 0){
            Hieu += 10;
            Muon = 1;
        }else{
            Muon = 0;
        }
        c = char(Hieu +48) + c;
    }
    while(c.length() > 1 && c[0] == '0') c.erase(0,1);
    return c;
}

class BigInt{
    string value;
    int sign;

public:
    // Hàm khởi tạo số nguyên lớn
    BigInt();
    BigInt(const char *);
    BigInt(int);
    BigInt(const BigInt &);

    // Toán tử in ra màn hình
    friend ostream &operator<<(ostream &, const BigInt &);

    // Toán tử gán
    BigInt &operator=(int);
    BigInt &operator=(const char *);
    BigInt &operator=(const BigInt &);

    // Toán tử cộng
    friend BigInt operator+(const BigInt &, const BigInt &);
    friend BigInt operator+(const BigInt &, int);
    friend BigInt operator+(int, const BigInt &);

    // Toán tử trừ
    friend BigInt operator-(const BigInt &, const BigInt &);
    friend BigInt operator-(const BigInt &, int);
    friend BigInt operator-(int, const BigInt &);

    // Toán tử cộng rồi gán
    BigInt &operator+=(int);
    BigInt &operator+=(const BigInt &);

    // Toán tử trừ rồi gán
    BigInt &operator-=(int);
    BigInt &operator-=(const BigInt &);
};

BigInt::BigInt(){
    value = "0";
    sign = 1;
}

BigInt::BigInt(const char *x){
    int index = 1;
    if (x[0] == '-'){
        index = 1;
        sign = -1;
    }else{
        index = 0;
        sign = 1;
    }

    while (*(x + index) != '\0'){
        value += *(x + index);
        index++;
    }
}

BigInt::BigInt(int x){
    if (x >= 0)  sign = 1;
    else   sign = -1;
    value = to_string(abs(x));
}

BigInt::BigInt(const BigInt &other){
    value = other.value;
    sign = other.sign;
}

ostream &operator<<(ostream &os, const BigInt &other){
    if (other.sign == -1) os << '-';
    os << other.value;
    return os;
}

BigInt &BigInt ::operator=(int x){
    if (x >= 0)    sign = 1;
    else    sign = -1;
    value = to_string(abs(x));
    return *this;
}

BigInt &BigInt ::operator=(const char *x){
    value.clear();
    int index = 1;
    if (x[0] == '-'){
        index = 1;
        sign = -1;
    }else{
        index = 0;
        sign = 1;
    }

    while (*(x + index) != '\0'){
        value += *(x + index);
        index++;
    }
    return *this;
}

BigInt &BigInt ::operator=(const BigInt &other){
    value = other.value;
    sign = other.sign;
    return *this;
}

BigInt operator+(const BigInt &a, const BigInt &b){
    BigInt ans;
    if (a.sign == b.sign){
        ans.sign = a.sign;
        ans.value = add(a.value, b.value);
    }else{
        if (compareAbs(a.value, b.value) >= 0){
            ans.value = subtract(a.value, b.value);
            ans.sign = a.sign;
        }else{
            ans.value = subtract(b.value, a.value);
            ans.sign = b.sign;
        }
    }
    return ans;
}

BigInt operator+(const BigInt &other, int num){
    return other + BigInt(num);
}

BigInt operator+(int num, const BigInt &other){
    return other + BigInt(num);
}

BigInt operator-(const BigInt &a, const BigInt &b){
    BigInt res;
    if (a.sign == b.sign){
        if (compareAbs(a.value, b.value) >= 0){
            if (a.sign == -1)    res.sign = -1;
            else    res.sign = 1;
            res.value = subtract(a.value, b.value);
        }else{
            if (a.sign == 1)    res.sign = -1;
            else    res.sign = -1;
            res.value = subtract(a.value, b.value);
        }
    }else{
        res.sign = a.sign;
        res.value = add(a.value, b.value);
    }
    return res;
}

BigInt operator-(const BigInt &other, int b){
    return other - BigInt(b);
}

BigInt operator-(int a, const BigInt &other){
    return BigInt(a) - other;
}

BigInt &BigInt::operator+=(int num){
    *this = *this + num;
    return *this;
}

BigInt &BigInt::operator+=(const BigInt &other){
    *this = *this + other;
    return *this;
}

BigInt &BigInt::operator-=(int num){
    *this = *this - num;
    return *this;
}

BigInt &BigInt::operator-=(const BigInt &other){
    *this = *this - other;
    return *this;
}

int main(){
   BigInt a = BigInt("7412391231723192399991239");
   BigInt b = BigInt(21348123);
   cout << a - b << endl;
   cout << 43 - a << endl;
   cout << b - 71 << endl;
   return 0;
}
