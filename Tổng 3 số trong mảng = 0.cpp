//Lưu ý : các bộ số là khác nhau

#include<iostream>
#include<algorithm>
#include<set>
#include<vector>

using namespace std;

int main(){
    int n ; 
    cin >> n;
    int a[10000];
    for(int i = 0; i < n; i++) cin >> a[i];

    set<vector<int>> ans;

    for(int i = 0 ; i < n-2 ; i++){
        for(int j = i+1; j < n-1 ; j++){
            for(int k =j+1 ; k < n ; k++){
                if(a[i] + a[j] + a[k] == 0){
                    vector<int> x = { a[i], a[j], a[k] };
                    ans.insert(x);
                }
            }
        }
    }

    for(auto x : ans){
        cout << x[0] << " " << x[1] << " " << x[2] << endl;
    }

    return 0;
}
