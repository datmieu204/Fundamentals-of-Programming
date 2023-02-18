#include <iostream>
using namespace std;

int modul_exp(int a, int n, int m);

int main() {
    int a, n, m;
    cin >> a >> n >> m;
    cout  << modul_exp(a, n, m) << endl;
    return 0;
}

int modul_exp(int a, int n, int m) {
    int res = 1;
    a = a % m;  // Giảm thiểu số lần tính toán mod m
    
    while (n > 0) {
        // Nếu n lẻ, nhân res với a mod m
        if (n % 2 == 1) res = (res * a) % m;
        
        n /= 2;
        
        // Nhân a với chính nó mod m
        a = (a * a) % m;
    }
    return res;
}
