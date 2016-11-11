#include <cstdio>


int main(){
    
    int n,Ans=0; scanf("%d",&n);
    int A[1001][3];
    for(int i=0;i<n;i++) scanf("%d %d %d",&A[i][0],&A[i][1],&A[i][2]);
    for(int i=1;i<=9;i++)for(int j=1;j<=9;j++)for(int k=1;k<=9;k++){
        if(i==j || i==k || j==k) continue;
        bool isCan=true;
        for(int z=0;z<n;z++){
            int cur=A[z][0];
            int a=cur/100, b=(cur/10)%10,c=cur%10;
            int st=0, ball=0;
            if(a==i) st++;
            else if(a==j || a==k) ball++;

            if(b==j) st++;
            else if(b==i || b==k) ball++;

            if(c==k)st++;
            else if(c==i || c==j) ball++;
            if(st!=A[z][1] || ball!=A[z][2]){
                isCan=false;
                break;
            }
        }
        if(isCan)Ans++;
    }
    printf("%d\n",Ans);
    return 0;
}
