#include <cstdio>
#define CLOSE 0
#define OPEN 1
int A[100001]={0};
int main(){
    int n,Ans=1; scanf("%d",&n);
    for(int i=1;i<=n;i++) A[i]=OPEN;
    for(int i=2;i<=n;i++){
        if(A[i]==CLOSE) continue;
        Ans++;
        for(int j=i+i;j<=n;j+=i){
            if(A[j]==CLOSE) A[j]=OPEN;
            else A[j]=CLOSE;
        }
    }
    printf("%d\n",Ans);
    return 0;
}
