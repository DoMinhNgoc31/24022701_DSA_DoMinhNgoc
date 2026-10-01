#include <iostream>

using namespace std;

void rutgon(int &a,int &b){
    int mini=min(a,b);
    int ucln=1;
    for(int i=2;i<=mini;i++){
        if(a%i==0&&b%i==0)
            ucln=i;
    }
    a/=ucln;
    b/=ucln;
}

int main()
{
    int a,b;
    cin>>a>>b;
    rutgon(a,b);
    cout<<a<<'/'<<b;
}

//Time: O(N) do vòng lặp for duyệt từ 2 đến min(a, b)
//Memory: O(1) do hàm chỉ sử dụng một vài biến cục bộ, không gian bộ nhớ phụ trợ này là cố định và không tăng lên theo độ lớn của a hay b
