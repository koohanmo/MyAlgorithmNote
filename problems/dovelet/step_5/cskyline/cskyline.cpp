#include <cstdio>

int A[1000001];
int N[50002][2];
int main(){
    
    int n,k;scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++) scanf("%d %d",&N[i][0],&N[i][1]);
    N[n][0]=k+1;
    N[n][1]=0;
    for(int i=0;i<n;i++){
        int pos = N[i][0];
        int val = N[i][1];
        int npos = N[i+1][0];
        for(;pos<npos;pos++) A[pos]=val;
    }
    
    int Ans=0;
    for(int i=1;i<=k;i++){
        int curVal = A[i];
        if(curVal==0) continue;
        else Ans++;
        int curpos=i;
        A[curpos++]=0;
        while(curpos <=k && A[curpos]>=curVal){
            if(A[curpos]==curVal) A[curpos]=0;
            curpos++;
        }
    }
    printf("%d\n",Ans);
    return 0;
}
