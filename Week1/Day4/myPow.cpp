// You are using GCC
#include<bits/stdc++.h>
using namespace std;

double myPow(double x, long long n){
    if(n == 0) return 1.0;
    
    if(n < 0){
        x = 1.0 / x;
        n = -n;
    }
    
    double result = 1.0;
    while(n > 0){
        if(n % 2 == 1){        // odd power
            result *= x;
        }
        x *= x;                // square the base
        n /= 2;                // halve the power
    }
    return result;
}

int main(){
    double x;
    long long n;
    cin >> x >> n;
    
    double ans = myPow(x, n);
    cout << fixed << setprecision(5) << ans;
    return 0;
}