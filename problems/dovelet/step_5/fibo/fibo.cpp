#include <cstdio>
long long A[50];

int main(){
    A[0]=1;A[1]=2;A[2]=3;
    for(int i=3;i<50;i++){
        A[i]=A[i-1]+A[i-2];
    }
    int n; scanf("%d",&n);
    printf("%lld\n",A[n]);
    return 0;
}
