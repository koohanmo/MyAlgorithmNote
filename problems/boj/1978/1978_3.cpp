#include <cstdio>

int main(){
    int n,Ans=0,temp;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&temp);
        int nn=0;
        for(int j=1;j<=temp;j++){
            if(temp%j==0) nn++;
        }
        if(nn==2)Ans++;
    }
    printf("%d\n",Ans);
    return 0;
}
