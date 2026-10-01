#include <iostream>

using namespace std;

void xoaPhanTu(int arr[],int &n,int k){
    if(k<0||k>=n) return;
    for(int i=k;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    n--;
}

void chenPhanTu(int arr[],int&n,int m,int y){
    if(m<0||m>n) return;
    for(int i=n;i>m;i--){
        arr[i]=arr[i-1];
    }
    arr[m]=y;
    n++;
}

int main()
{
    int n;
    cin>>n;
    int a[1000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k=2;
    xoaPhanTu(a,n,k);
    int m=1,y=99;
    chenPhanTu(a,n,m,y);
}

// Time: O(N) trường hợp xấu nhất(đầu mảng), O(1) trường hợp tốt nhất(cuối mảng)
// Memory: O(N)
