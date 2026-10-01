#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[10000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int tong=0;
    for(int i=0;i<n;i++){
        tong+=a[i];
    }
    cout<<tong;
}
//Time: O(N) vì cần duyệt qua N phần tử để nhập và tính tổng
//Memory: O(N) để lưu trữ mảng gồm N phần tử
