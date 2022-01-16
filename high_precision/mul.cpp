//给定两个非负整数（不含前导 0） A 和 B，请你计算 A×B 的值。
#include <iostream>
#include <vector>

using namespace std;

vector<int> mul(vector<int> &A, int b)
{
    vector<int> C;
    
    int t = 0;
    for (int i = 0; i < A.size() || t; i ++ )
    {
        if(i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    
    return C;
}


int main()
{
    string a;
    int b;
    cin >> a >> b;
   
    vector<int> A;
    for (int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');
    
    auto C = mul(A, b);
    
    for(int i = C.size() - 1; i >= 0; i --) printf("%d",C[i]);
    
    return 0;
}