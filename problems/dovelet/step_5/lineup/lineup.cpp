#include <cstdio>
int C[10001];
int main(){
    int n,k,cur,Ans=1; scanf("%d %d",&n, &k);
    for(int i=0;i<n;i++) {
        scanf("%d",&cur);
        C[cur]++;
    
            bool isCom=true;
            for(int j=1;j<=k;j++){
                if(C[j]<1){
                    isCom=false;
                    break;
                }
            }
            if(isCom) {
                Ans++;
                for(int j=1;j<=k;j++) C[j]=0;
            }
        
    }
    printf("%d\n",Ans);


    return 0;
}
