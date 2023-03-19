
#include<iostream>

using namespace std;

int main(){
    int n ; 
    cout <<"Nhap kich thuoc ma tran la so le : ";
    
    do{
        cin >> n ;
        if(n%2==0) cout << "Nhap lai kich thuoc :" ;
    }while(n%2==0);

    int a[100][100];
    int i=0 , j = n/2;
    
    for(int num=1 ; num <= n*n ; num++){
        a[i][j] = num;
        if(num % n == 0) {
            i++;
        } 
        else {
            i=(i -1 +n) % n;
            j=(j +1) % n;
        } 
    }
    
    //in ra
    for(int r=0 ; r < n ; r++){
        for(int c=0 ; c < n ; c++){
            cout << a[r][c] << "\t" ;
        }
        cout << endl;
    }
    
    return 0;

}
