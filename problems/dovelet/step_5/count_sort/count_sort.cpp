#include <cstdio>

int A[10001];

int main(){
    int n; scanf("%d",&n);
    for(int i=0;i<n;i++){
        int temp; scanf("%d",&temp);
        A[temp]++;
    }
    for(int i=1;i<=10000;i++){
        for(int j=0;j<A[i];j++) printf("%d ",i);
    }
    return 0;
}
