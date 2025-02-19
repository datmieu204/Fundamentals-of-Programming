/*Viết một chương trình nhận vào một số nguyên N
, trả về kết quả là một số nguyên lớn nhất thỏa mãn:

- Tổng các chữ số của chúng là N;

- Mỗi chữ số chỉ xuất hiện một lần.

Trường hợp không thể đáp ứng điều kiện trên (N>45 hoặc N<0), trả về "None" (không có dấu ngoặc).
VD N = 45 -> 9876543210
   N = 7  -> 4210
*/


#include<bits/stdc++.h>

using namespace std;

vector<long long> v;

//Hàm kiểm tra trong xâu có kí tự trùng lặp 
bool check(string s) {
    unordered_set<char> chars;
    for (char c : s) {
        if (chars.count(c) > 0) {
            return false;
        }
        chars.insert(c);
    }
    return true;
}

void solve(int n, int max_val, string s) {
    if (n == 0){
        if(check(s)){
            long long k = stoll(s);
            v.push_back(k);
        }
        return;
    }
    for (int i = min(max_val, n); i >= 1; i--) {
        solve(n - i, i, s + to_string(i));
    }
}

int main() {
    int n;
    cin >> n;
    if(n > 45 || n<0){
        cout << "None\n";
    }else{
        solve(n, n, "");
        sort(v.begin(), v.end());
        cout << v.back() << "0" ;
    }
    return 0;
}
