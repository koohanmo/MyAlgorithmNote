#include <cstdio>
bool isP[10001];
void is(){
    for(int i=0;i<=100;i++) isP[i*i]=true;
}

int main(){
    is();
    int sum=0,m=1<<30;    
    int M,N; scanf("%d %d",&M,&N);
    for(int i=M;i<=N;i++){
        if(isP[i]==true) {
            sum+=i;
            m= m>i? i:m;
        }
    }
    if(sum==0)  printf("-1\n");
    else printf("%d\n%d\n",sum,m);
    return 0;
}
