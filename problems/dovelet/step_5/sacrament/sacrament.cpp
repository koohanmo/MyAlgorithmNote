#include <cstdio>

int A[50001],B[50001];
int main(){
    int na,nb; scanf("%d",&na);for(int i=0;i<na;i++)scanf("%d",A+i);
    scanf("%d",&nb);for(int i=0;i<nb;i++) scanf("%d",B+i);
    bool Ans=false;
    for(int i=0,j=0 ;i<na && j<nb;){
        if(A[i]+B[j]==10000){
            Ans=true;
            break;
        }else if(A[i]+B[j]<10000)i++;
        else j++;
    }
    if(Ans)printf("YES");
    else printf("NO");
    return 0;
}
