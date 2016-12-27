#include <cstdio>

bool isPrime(int num){
    if(num==1) return false;
    for(int i=2;i*i<=num;i++){
        if(num%i==0) return false;
    }
    return true;
}
int main(){
    int n,Ans=0,temp;
    scanf("%d",&n);
    while(n--) {
        scanf("%d",&temp);
        if(isPrime(temp))Ans++;
    }
    printf("%d\n",Ans);
    return 0;
}
