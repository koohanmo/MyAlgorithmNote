#include <cstdio>

int main(){
    int n,Ans=0,AnsVal=0; scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int A[5],curResult=0;
        for(int z=0;z<5;z++) scanf("%d",&A[z]);
        for(int a=0;a<5;a++)for(int b=a+1;b<5;b++)for(int c=b+1;c<5;c++){
            curResult = curResult < (A[a]+A[b]+A[c])%10 ? (A[a]+A[b]+A[c])%10 : curResult;
        }
        if(AnsVal<=curResult){
            AnsVal = curResult;
            Ans=i;
        }
    }
    printf("%d\n",Ans);
    return 0;
}
