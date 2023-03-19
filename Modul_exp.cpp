#include <iostream>
using namespace std;

// Hàm tính a^b mod m
int power(int a, int b, int m) {
    int res = 1;
    a = a % m;  // Giảm thiểu số lần tính toán mod m
    
    while (b > 0) {
        // Nếu b lẻ, nhân res với a mod m
        if (b & 1) {
            res = (res * a) % m;
        }
        // Chia b cho 2
        b /= 2;
        // Nhân a với chính nó mod m
        a = (a * a) % m;
    }
    return res;
}

int main() {
    int a, b, m;
    cin >> a >> b >> m;
    cout  << power(a, b, m) << endl;
    return 0;
}
