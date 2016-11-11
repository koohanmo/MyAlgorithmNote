#include <cstdio>

void swap(int &a,int &b){
    int t= a;
    a=b;
    b=t;
}
int main(){
    int n; scanf("%d",&n);
    int A[50001];for(int i=0;i<=n;i++)A[i]=i;
    int R; scanf("%d",&R);
    for(int i=0;i<R;i++){
        int left,right; scanf("%d %d",&left,&right);
        while(left<=right){
            swap(A[left],A[right]);
            left++;
            right--;
        }
    }
    int Q; scanf("%d",&Q);
    while(Q--){
        int t,Ans=0; scanf("%d",&t);
        for(int i=1;i<=n;i++){
            if(A[i]==t){
                Ans=i;
                break;
            }
        }
        printf("%d\n",Ans);
    
    }
    return 0;
}
