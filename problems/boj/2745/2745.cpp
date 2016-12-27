#include <cstdio>
#include <cstring>
int main(){
    char S[101];
    int B,len,mul=1,Ans=0; scanf("%s %d ",S,&B);
    len=strlen(S);
    for(int i=len-1;i>=0;i--,mul*=B){
        int cur = S[i];
        if(cur>='A' && cur<='Z') cur=cur-'A'+10;
        else cur=cur-'0';
        Ans+=(mul*cur);
    }
    printf("%d\n",Ans);
    return 0;
}
