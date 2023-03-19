#include<iostream>

using namespace std;

int main(){
    int n ; cin >> n ;
    int a[1000];

    for(int i = 0; i < n ; i++) cin >> a[i];

    // Tổng tích lũy trái 
    int b[1000];
    b[0] = 0;
    for(int i = 1 ; i < n ; i++) b[i] = b[i-1] + a[i-1];

    // Tổng tích lũy phải 
    int c[1000];
    c[n-1] = 0;
    for(int i = n - 2; i >= 0 ; i--) c[i] = c[i+1] + a[i+1];

    bool check = false;
    for(int i = 0; i < n ; i++) if(b[i] == c[i]) check = true;
    if(check) cout <<"yes\n";
    else cout <<"no\n";
    
    return 0;

}
