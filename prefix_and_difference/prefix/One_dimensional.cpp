/*输入一个长度为 n 的整数序列。

接下来再输入 m 个询问，每个询问输入一对 l,r。

对于每个询问，输出原序列中从第 l 个数到第 r 个数的和。
*/
//注意前缀和从a[1]开始，默认a[0]=0,即s[0]=0 i<=n
#include <iostream>

using namespace std;

const int N = 100010;

int n,m;
int a[N],s[N];

int main()
{
    ios::sync_with_stdio(false);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n ; i ++ ) scanf("%d", &a[i]);
    
    for(int i = 1; i <= n; i ++ ) s[i]= s[i - 1] + a[i];
    
    while (m -- )
    {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", s[r] - s[l - 1]);
    }
    return 0;
}
