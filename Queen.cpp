#include<iostream>

using namespace std;

bool check(int a[][2] , int n);

int main(){
    int n  ; cin >> n ;
    int a[100000][2];
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < 2 ; j++){
        cin >> a[i][j];
    }
    }
    if(check(a,n)) cout <<"yes\n";
    else cout <<"no\n";
    return 0;
}

bool check(int a[][2] , int n){
    for(int i = 0; i < n-1; i++){
        for(int j=i+1 ; j < n ; j++){
            if((a[i][0]==a[j][0]) ||  //kiem tra hang 
               (a[i][1]==a[j][1]) ||  //kiem tra cot
               (a[i][0] - a[j][0]==a[j][1] - a[i][1]) ) //kiem tra duong cheo , hieu cac toa do la = nhau tren duong cheo
                return true;
        }
}
return false;
}
