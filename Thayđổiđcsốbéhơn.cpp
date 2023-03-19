#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    string s;
    cin >> s;
    long long n = stoll(s);

    for(int i = 0; i < (int)s.size(); i++){
        for(int j = i+1 ; j < (int)s.size() ; j++){
            string tmp = s;
            swap(tmp[i],tmp[j]);
            if(tmp[0] != '0') n = min(n,stoll(tmp));
        }
    }
    cout << n << endl;
    return 0;
}
