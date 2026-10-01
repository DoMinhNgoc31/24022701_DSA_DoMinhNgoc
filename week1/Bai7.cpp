#include <iostream>

using namespace std;

long long tinhTong(int arr[][100],int m,int n){
    long long sum=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            sum+=arr[i][j];
        }
    }
    return sum;
}

void xoaDong(int arr[][100],int &m,int n,int k) {
    if (k<0||k>= m) return;
    for(int i=k;i<m-1;i++){
        for(int j=0;j<n;j++){
            arr[i][j]=arr[i+1][j];
        }
    }
    m--;
}

int main()
{
    int m,n;
    cin>>m>>n;
    int arr[100][100];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    cout<<tinhTong(arr,m,n)<<'\n';

    int k=1;
    xoaDong(arr,m,n,k);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<' ';
        }
        cout<<'\n';
    }
}

//Memory: O(M*N)
//Time: hàm tính tổng O(M*N), hàm xóa dòng xấu nhất O(M*N), tốt nhất O(1)
