#include <cstdio>

int A[10001];
int main(){
    int n,Ans=0; scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",A+i);
    for(int i=0;i<n;i++){
        int curP=i,curV=A[i];
        for(int j=i+1;j<n;j++){
            if(curV>A[j]){
                curP=j;
                curV=A[j];
            }
        }
        if(curP!=i) Ans++;
        int temp = curV;
        A[curP] = A[i];
        A[i] = temp;
    }
    printf("%d",Ans);

    return 0;
}
