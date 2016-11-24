#include <cstdio>
#include <vector>
using namespace std;


int main(){
    int n; scanf("%d",&n);
    int D=10;
    while(D<n) D*=10;
    int Ans=0,now=D;
    vector<int> his(n*10+1,0);
    do{
        Ans++;
        if(now==0){
            Ans=0;
            break;
        }
        if(his[now]!=0){
            Ans=Ans-his[now];
            break;
        }
        his[now]=Ans;
        now=(now%n)*10;
    }while(true);
ED:    
    printf("%d\n",Ans);
    return 0;
}
