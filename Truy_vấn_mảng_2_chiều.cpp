/*Một mảng A gồm N phần tử. Trong mảng A phần tử tại vị trí thứ i trỏ đến một mảng gồm ki phần tử.
Mỗi truy vấn trên mảng A có định dạng i j, trong đó i là chỉ mục tới vị trí trong mảng A và j là chỉ mục tới vị trí trong mảng A[i].
Viết chương trình in ra giá trị tương ứng với mỗi truy vấn được nhập từ bàn phím. Biết rằng các truy vấn này luôn hợp lệ.

Đầu vào
Dòng đầu tiên gồm 2 số nguyên N và Q là số lượng phần tử của mảng A và Q là số lượng truy vấn. (1≤N,Q)
N dòng tiếp theo, mỗi dòng đại diện cho một mảng con được trỏ đến bởi các phần tử của mảng A. Mỗi dòng gồm phần tử đầu tiên là độ dài mảng, các phần tử tiếp theo là các phần tử của mảng
Q dòng tiếp theo, mỗi dòng gồm hai giá trị i j tương ứng với các truy vấn trên mảng A
Đầu ra
Q dòng, mỗi dòng là giá trị tại vị trí tương ứng với mỗi truy vấn trên mảng A

input            output
2 2              5
3 1 5 4          9
5 1 2 8 9 3
0 1
1 3
*/


#include<iostream>

using namespace std;

int main(){
    int N,Q;
    cin >> N >> Q;

    //truy  vấn mảng 2 chiều 
    int **A = new int*[N];
    for(int i = 0 ; i < N ; i++){
        int k;
        cin >> k;
        A[i] = new int[k];
        for(int j = 0 ; j < k ; j++){
            cin >> A[i][j];
        }
    }

    while(Q--){
        int i,j;
        cin >> i >> j;
        cout << A[i][j] << endl;
    }
    
    //giải phóng bộ nhớ 
    for(int i = 0 ; i < N ; i++){
        delete[] A[i];
    }
    delete[] A;

    return 0;
}
