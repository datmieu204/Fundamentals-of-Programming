#include<iostream>

using namespace std;

bool binarySearch( int a[] , int n , int x);

int main(){
    int n,x;
    int a[100000];
    cin >> n >> x ;
    for(int i = 0; i < n ; i++){
        cin >> a[i];
    }
    if(binarySearch(a,n,x)) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}

bool binarySearch( int a[] , int n , int x){
    int l=0 , r=n-1;
    while(l<=r) {
        int mid=(l+r)/2;
        if(a[mid]==x) {
            return true;
        }else if(a[mid]<x){
            l=mid+1;
        }else {
            r=mid-1;
        }
    }
    return false;
}
