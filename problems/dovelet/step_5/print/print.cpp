#include <cstdio>
using namespace std;

int main(){
    int n,target,pos=0; scanf("%d %d",&n,&target);
    int A[101],Ans=0;
    for(int i=0;i<n;i++)scanf("%d",&A[i]);
    for(int i=0;i<n;i++){
        int curMax=-1000;
        for(int j=0;j<n;j++) curMax = curMax < A[j] ? A[j] : curMax;        
        for(int j=0;j<=n;j++){
            if(A[pos]==curMax){
                Ans++;
                A[pos]=-100;
                break;
            }
            pos=(pos+1)%n;
        }
        if(pos==target) break;
        pos=(pos+1)%n;
    }
    printf("%d",Ans);
    return 0;
}
