#include <cstdio>
#define ll long long

int main(){
    int T;scanf("%d",&T);
    while(T--){
        ll A[100];
        int n; scanf("%lld %lld %d",A+1,A+2,&n);
        for(int i=3;i<=n;i++) A[i]=A[i-1]+A[i-2];
        printf("%lld\n",A[n]);
    
    }
    return 0;
}
