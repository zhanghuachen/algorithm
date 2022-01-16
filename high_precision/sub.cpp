//给定两个正整数（不含前导 0），计算它们的差，计算结果可能为负数。
#include <iostream>
#include <vector>

using namespace std;

bool cmp(vector<int> &A, vector<int> &B)
{
    if(A.size() != B.size()) return A.size() > B.size();
    for(int i = A.size() - 1; i >= 0 ; i --)
        if(A[i] != B[i]) return A[i] > B[i];
    return true;
}

vector<int> sub(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    
    //t进位
    for(int i = 0, t = 0; i < A.size(); i ++ )
    {
        t = A[i] - t;//A减去进位
        if(i < B.size()) t -= B[i]; //如果B[i]这位存在则再减去B[i]
        //即t = A[i] - B[i] - t;
        
        //t >= 0 即还是t, t < 0 时，t = t + 10 ==> (t+10)%10
        C.push_back((t + 10) % 10);
        if(t < 0) t = 1; //t<0有借位
        else t = 0;
    }
    
    //去除前导0，C逆序
    //C.back()访问C中最后一个元素，C.pop_back()将C中元素弹出
    while(C.size() > 1 && C.back() == 0) C.pop_back(); 
    
    return C;
}

int main()
{
    string a, b;
    vector<int> A, B;
    
    cin >> a >> b; //a="123456"
    for(int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');//A=[6,5,4,3,2,1]
    for(int i = b.size() - 1; i >= 0; i -- ) B.push_back(b[i] - '0');
    
    if(cmp(A ,B))
    {
        auto C = sub(A ,B);
        for(int i = C.size() - 1; i >= 0; i --) printf("%d", C[i]);
    }
    else
    {
        printf("-");
        auto C = sub(B ,A);
        for(int i = C.size() - 1; i >= 0; i --) printf("%d", C[i]);
    }
    
    return 0;
}