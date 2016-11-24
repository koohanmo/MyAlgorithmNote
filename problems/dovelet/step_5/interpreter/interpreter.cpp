#include <cstdio>
#define MOD 1000
int V[1100];
int P[1100];
int I[1001];

int ans=0;
int main(){
    int cnt=0;
    while(true){
        if(-1==scanf("%d",&I[cnt++])) break;
        if(I[cnt-1]==100) break;
    }

    for(int i=0;;i++){
 //       printf("%d\n",I[i]);
   //     for(int j=1;j<=10;j++)printf("%d ",V[j]);
     //   printf("ans : %d\n",ans);
        
        int ins=I[i];
        ans++;
        if(ins==100) break;
        if(ins ==0) continue;
        int op = ins/100;
        int d = (ins/10)%10;
        int n = ins%10;
    
        switch(op){
            case 2 : V[d]=n;  break;
            case 3:  V[d]+=n; V[d]%=MOD; break;
            case 4:  V[d]*=n; V[d]%=MOD; break;
            case 5:  V[d]=V[n]; break;
            case 6:  V[d]+=V[n]; V[d]%=MOD; break;
            case 7:  V[d]*=V[n]; V[d]%=MOD; break;
            case 8:  V[d]= I[V[n]]; break;
            case 9:  I[V[n]]=V[d]; break;
            case 0 : if(V[n]) {
                        i=V[d]-1;
                        } break;
        }
    
    }
    printf("%d\n",ans);
    return 0;
}
