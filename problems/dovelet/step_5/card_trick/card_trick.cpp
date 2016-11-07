#include <cstdio>

int main(){
    int n; scanf("%d",&n);
    int V[14]={0},start=0;
    for(int i=1;i<=n;i++){
        for(int j =0;j<i;){
            if(V[start] == 0) j++;
            start = ( start+1 ) % n;
        }
        while(V[start]!=0) start=(start+1)%n;
        V[start]=i;
    }
    for(int i=0;i<n;i++) printf("%d ",V[i]);
    return 0;
}
