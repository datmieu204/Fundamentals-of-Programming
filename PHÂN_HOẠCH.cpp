//PHÂN HOẠCH 

#include<iostream>

using namespace std;

int n,a[100],ok,cnt;
//Biến cnt lưu số hạng trong tổng 

void ktao(){
    cnt = 1;
    a[1] = n; //Cấu hình đầu tiên = n 
}

void sinh(){
    int i = cnt; //Gán chỉ số cuối cùng của cấu hình , bắt đầu từ bit cuối cùng 
    
    //TH gặp bit 1 thì bỏ qua , xét từ phải sang trái 
    while(i >= 1 && a[i] == 1){
        --i;
    }
    
    if(i==0) ok = 0; //Cấu hình cuối cùng 
    else{            
        a[i]--; //Nếu bit đó khác 0 , giảm đi 1 đơn vị 
        int d = cnt - i + 1; //Phần bù còn thiếu số 1 
        cnt = i; //Reset số lượng số hạng 
        //Biểu diễn phần bù qua a[i]
        int q = d/a[i];
        int r = d%a[i];
        if(q){
            for(int j = 1; j <= q; j++){
                cnt++;
                a[cnt] = a[i];
            }
        } 
        if(r){
            ++cnt;
            a[cnt] = r;
        }
    }
}

int main(){
    cin >> n;
    ok = 1;
    ktao();
    while(ok){
        for(int i = 1; i <= cnt ; i++){
            cout << a[i] << " ";
        }
        cout << endl;
        sinh();
    }
    return 0;
}
