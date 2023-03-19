#include<bits/stdc++.h>

using namespace std;

    bool check(string s){
        string target = "congnghe";
        int cnt = 0;
        for(int i=0; i<(int)s.size(); i++){   //Duyet tung ki tu trong chuoi s
            if(cnt<(int)target.size() && s[i] == target[cnt]) cnt++;
        }
        //Duyet tung ki tu trong chuoi s xem co trung voi ki tu trong chuoi "congnghe" hay khong 
        return cnt == (int)target.size();
    }

    int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        if(check(s)) cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;
}
