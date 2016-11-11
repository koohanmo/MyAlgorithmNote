#include <cstdio>

int main(){
    int L; scanf("%d",&L);
    int A[51];for(int i=0;i<L;i++)scanf("%d",A+i);
    int B[51];
    for(int i=0;i<L;i++){
        int val = A[i];
        if(val==1) B[L-i-1]=3;
        else if(val==2) B[L-i-1]=4;
        else if(val==3) B[L-i-1]=1;
        else B[L-i-1]=2;
    }
    int N,Ans; scanf("%d",&N);
    int S[101][51];
    for(int i=0;i<N;i++){
        bool test=false;
        int T[51]; for(int z=0;z<L;z++) scanf("%d",T+z);
        for(int j=0;j<L;j++){
            if(A[0]==T[j]){
                test=true;
                for(int z=0,pos=j;z<L;z++,pos=(pos+1)%L){
                    if(A[z]!=T[pos]){
                        test=false;
                        break;
                    }
                }
            }
            if(test==true){
                for(int x=0;x<L;x++) S[Ans][x]=T[x];
                Ans++;
                break;
            }
            
            if(B[0]==T[j]){
                test=true;
                for(int z=0,pos=j;z<L;z++,pos=(pos+1)%L){
                    if(B[z]!=T[pos]){
                        test=false;
                        break;
                    }
                }
            }
            if(test==true){
                for(int x=0;x<L;x++) S[Ans][x]=T[x];
                Ans++;
                break;
            }
        }
    }
    printf("%d\n",Ans);
    for(int i=0;i<Ans;i++){for(int j=0;j<L;j++)
        {
            printf("%d ",S[i][j]);
        }
        printf("\n");
    }
    return 0;
}
