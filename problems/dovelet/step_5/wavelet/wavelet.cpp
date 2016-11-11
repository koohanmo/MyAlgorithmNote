#include <cstdio>

int main(){
    int n; scanf("%d",&n);
    int A[257]; for(int i=0;i<n;i++)scanf("%d",A+i);
    for(int i=2;i<=n;i*=2){  
        int AT[257];
        for(int pos=0; pos<i/2;pos++){
            AT[pos*2]=(A[pos]+A[pos+i/2])/2;
            AT[pos*2+1]=(A[pos]-A[pos+i/2])/2;
        }
        for(int z=0; z<i;z++)A[z]=AT[z];
    }
    for(int i=0;i<n;i++)printf("%d ",A[i]);
    return 0;
}
