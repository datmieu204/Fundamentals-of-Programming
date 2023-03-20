#include<bits/stdc++.h>

using namespace std;

//tim xau tien to chung dai nhat giua 2 xau
string LCP(string s1 , string s2){
    string s = "";
    for(int i = 0; i < (int)s1.length(); i++){
        if(s1[i]==s2[i]) s+=s1[i];
    }
    return s;
}

//de quy tim xau tien to chung dai nhat
string find(string s[] , int n){
    string tmp = s[0];
    for(int i = 1; i < n; i++) tmp = LCP(tmp, s[i]);
    return tmp;
}

int main(){
    int n ; cin >> n;
    cin.ignore();
    string s[100];

    //vd s[0] = dat mieu cute
    //vd s[1] = dat deptrai vcl

    for(int i = 0; i < n; i++) getline(cin, s[i]);
    
    string ans = find(s,n);
    cout << ans << endl;

    return 0;
}
