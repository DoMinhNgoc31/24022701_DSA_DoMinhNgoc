#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int gt=1;
    for(int i=1;i<=n;i++){
        gt*=i;
    }
    cout<<gt;
}

//Time: O(N) vì for
//Memory: O(1) vì chỉ sử dụng một vài biến đơn không phụ thuộc vào kích thước đầu vào
