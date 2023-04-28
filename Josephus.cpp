/*
Bài toán Josephus có N sinh viên đứng thành vòng tròn ( đánh số thứ tự liên tiếp từ 1 tới N) và được trao thưởng là người thứ M quanh vòng tròn, sau đó người đó bước ra khỏi vòng tròn và vòng tròn được thu hẹp lại. Yêu cầu tìm ra thứ tự từng người được trao thưởng. Hãy viết chương trình giải quyết bài toán Josephus. 

Input: Dòng đầu tiên ghi giá trị N Dòng thứ hai ghi giá trị M 

Output: Dòng đầu tiên ghi danh sách thứ tự lĩnh thưởng cách nhau bởi dấu cách.

*/

#include<iostream>
#include<vector>

using namespace std;

void josephus(int n, int m) {
    vector<int> circle(n);
    for (int i = 0; i < n; i++) {
        circle[i] = i + 1;
    }
    int index = 0;
    
    while (n > 1) {
        index = (index + m - 1) % n;
        cout << circle[index] << " ";
        circle.erase(circle.begin() + index);
        n--;
    }
    cout << circle[0] << endl;
}

int main(){
    int n,m;
    cin >> n >> m;
    josephus(n,m);
}
