#include <cstdio>

int A[100001];
int main(){
    int n,Ans=0,inc,dec; scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
        if(i==0){
            inc=1;
            dec=1;
        }else{
            if(A[i]==A[i-1]){
                inc++;
                dec++;
            }else if(A[i]>A[i-1]){
                inc++;
                dec=1;
            }else{
                inc=1;
                dec++;
            }
        }
        if(Ans<inc) Ans=inc;
        if(Ans<dec) Ans=dec;
    }
    printf("%d\n",Ans);

    return 0;
}
