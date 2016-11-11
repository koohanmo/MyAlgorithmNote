#include <cstdio>
int main(){
    int n;scanf("%d",&n);
    int A[21],R[21]; for(int i=0;i<n;i++) scanf("%d",A+i);
    int D[20000],pos;
    for(pos=0;pos<A[0];pos++)D[pos]=-1;

    for(int i=0;i<n;i++){
        if(i==0 || A[i]==A[i-1]){
            D[pos++]=1;
        }else{
            int cha=A[i]-A[i-1];
            for(int j=0;j<cha;j++){
                D[pos++]=-1;
            }
            D[pos++]=1;
        }
        R[i]=0;
        int temp=1;
        for(int j=pos-2;j>=0;j--){
            R[i]++;
            if(temp+D[j]<=0) break;
            temp+=D[j];
        }
        R[i]/=2;
    }
    for(int i=0;i<n;i++) printf("%d ",R[i]+1);


    return 0;
}
