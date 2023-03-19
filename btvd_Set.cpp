#include<iostream>
#include<set>

using namespace std;

int main(){
    int t ; cin >> t ;
    set<int> s;

    while(t--){
        int x , y;
        cin >> x >> y ;

        if(x == 1) s.insert(y); //them y vao tep

        else if(x == 2) s.erase(y);//xoa y khoi tep

        else if(x == 3) {
            if(s.find(y) != s.end()) //tim y co trong tep ko
                cout << "yes\n";
            else cout << "no\n";
        }
    }
    return 0;
}
