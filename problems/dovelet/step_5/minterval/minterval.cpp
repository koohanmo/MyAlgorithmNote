#include <cstdio>

int A[2001];
int D[2001];

int main(){
    int ans,cur=0;
    while(true){
        scanf("%d",&A[cur]);
        if(A[cur]==0) break;
        if(cur==0) {
            D[cur]=A[cur];
            ans=D[cur];
        }else{
            D[cur] = D[cur-1]+A[cur] > A[cur] ? D[cur-1]+A[cur] : A[cur];
        }
        if(D[cur]>ans) ans=D[cur];
        cur++;
    }
    printf("%d",ans);


    return 0;
}
