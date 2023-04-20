//Nhập vào n xâu kí tự , đếm xem mỗi kí tưj có bao nhiêu từ chứa nó 
#include<iostream>
#include<map>
#include<set>

using namespace std;

int main(){
  int n ; cin >> n;
  map<char,int> cnt;

  while(n--){
    string s;
    cin >> s;
    set<char> b;
    for(char c : s) b.insert(c);

    for(char c : b) cnt[c]++; 
  }
  //Duyệt map 
  for(auto it : cnt) 
    cout << it.first << ": " << it.second << endl;
  return 0;
}

//Nhập vào n xâu kí tự đếm xem mỗi kí tự xuất hiện bao nhiêu lần
#include<iostream>
#include<map>

using namespace std;

int main(){
  int n ; cin >> n;
  map<char,int> cnt;

  while(n--){
    string s;
    cin >> s;
    for(char c :s) cnt[c]++; 
  }
  //Duyệt map 
  for(auto it : cnt) 
    cout << it.first << ": " << it.second << endl;
  return 0;
}
