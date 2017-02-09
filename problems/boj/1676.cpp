#include <cstdio>

int main(){
    int n; scanf("%d",&n);
    int t=0,f=0;
    for(int i=1;i<=n;i++){
        int cur=i;
        while(cur%2==0 || cur%5==0){
            if(cur%2==0) {t++; cur/=2;continue;}
            if(cur%5==0) {f++; cur/=5;continue;}
        }
    }
    printf("%d\n",t<f? t:f);
}
