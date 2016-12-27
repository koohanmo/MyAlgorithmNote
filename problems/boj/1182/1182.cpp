#include <cstdio>


int N,T;
int A[21];
int Ans=0;

void search(int n,int tot){
    if(n==N) return;
    if(tot==T) Ans++;
    for(int i=n+1;i<N;i++) search(i,tot+A[i]);
}
int main(){
    scanf("%d %d",&N,&T);
    for(int i=0;i<N;i++)scanf("%d",A+i);
    for(int i=0;i<N;i++)search(i,A[i]);
    printf("%d\n",Ans);
    return 0;
}
