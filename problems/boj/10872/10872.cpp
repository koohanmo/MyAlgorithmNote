#include <cstdio>
#define ll long long
int main(){
    ll n,Ans; scanf("%lld",&n);
    for(Ans=1;n>=1;n--)Ans*=n;
    printf("%lld\n",Ans);
    return 0;
}
