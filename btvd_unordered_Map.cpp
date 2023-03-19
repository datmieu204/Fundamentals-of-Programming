#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
    int t ; cin >> t ;
    unordered_map<string,int> map; //ko sap xep thu tu cac key , ko luu dc nhieu key giong nhau
    //string la key , int la value 
    while(t--){
        int x ; cin >> x ;
        string s ; cin >> s ;
        int a;

        if(x==1){
            cin >> a ;
            map[s]+=a;
        }
        else if(x==2) map.erase(s);
        else if(x==3) cout << map[s] << endl;
    }
    return 0;
}
