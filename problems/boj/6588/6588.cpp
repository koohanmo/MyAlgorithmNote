#include <cstdio>
#include <cstring>

bool isPrime[1000001];
void era(){
    isPrime[1]=false;
    for(int i=2;i*i<=1000000;i++){
        if(isPrime[i]){
            for(int j=i+i;j<=1000000;j+=i){
                isPrime[j]=false;
            }
        }
    }
}
int main(){
    memset(isPrime,true,sizeof(isPrime));
    era();
    while(true){
        int cur; 
        scanf("%d",&cur);
        if(cur==0) break;
        int a=3,b=cur-1;
        while(a<b){
            if(a%2==0 || !isPrime[a]){
                a++;
                continue;
            }
            if(b%2==0 || !isPrime[b]){
                b--;
                continue;
            }
            
            if(a+b >cur) b--;
            else if(a+b <cur) a++;
            else break;
        }
        if(a+b==cur) printf("%d = %d + %d\n",cur,a,b);
        else printf("Goldbach's conjecture is wrong.\n");
    }
    return 0;
}
