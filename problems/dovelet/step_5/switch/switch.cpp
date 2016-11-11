#include <cstdio>

int main(){

    int n; scanf("%d",&n);
    int A[101]; for(int i=1;i<=n;i++) scanf("%d",A+i);
    int T; scanf("%d",&T);
    while(T--){
        int sex,num; scanf("%d %d",&sex,&num);
        if(sex==1){
            int cur=num;
            while(cur<=n){
                if(A[cur]==1) A[cur]=0;
                else A[cur]=1;
                cur+=num;
            }
        }else{
            int left=num,right=num;
            while(left>=1 && right<=n){
                if(A[left]!=A[right]) {
                    left++;
                    right--;
                    break;
                }
                if(left==1 || right==n) break;
                left--;
                right++;
            }
            for(int l =left;l<=right;l++){
                 if(A[l]==1) A[l]=0;
                else A[l]=1;
            }
        }
    }
    for(int i=1;i<=n;i++) {
        printf("%d ",A[i]);
        if(i%20==0)printf("\n");
    }

    return 0;
}
