#include<cstdio>
#include <algorithm>
int A[1001];
int main(){
    int T; scanf("%d",&T);
    for(int ca=1; ca<=T;ca++){
        int n, Ans=0; scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",A+i);
        for(int i=0;i<n;i++){
          for(int j=0;j<n-i-1;j++){
             if(A[j]>A[j+1]){
                 Ans++;
                 std::swap(A[j],A[j+1]);
             }
         }
     }
    printf("Scenario #%d:\n",ca);
     printf("%d\n\n",Ans);
    }
    return 0;
}

