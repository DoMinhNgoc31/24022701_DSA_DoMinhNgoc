#include <iostream>

using namespace std;

void sapxeptangdan(int a[], int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                int tmp=a[i];
                a[i]=a[j];
                a[j]=tmp;
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int a[1000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sapxeptangdan(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
    }
}

//Time: O(N^2) do 2 vong lặp lồng nhau
//Memory: O(1) cho bộ nhớ phụ trợ, O(N) để lưu mảng ban đầu
