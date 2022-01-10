//cubic root of a number
#include <iostream>

using namespace std;

int main()
{
    double u;
    scanf("%lf", &u);
    double l = - 100, r = 100;
    while (r - l > 1e-8)
    {
        double mid = (l + r) / 2;
        if(mid * mid * mid >= u) r = mid;
        else l = mid;
    }

    printf("%.6lf\n", l);
    return 0;
    
}