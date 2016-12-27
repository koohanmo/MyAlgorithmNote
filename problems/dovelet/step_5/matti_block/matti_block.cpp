#include <cstdio>
#include <cstring>

int min(int a, int b){return a<b? a:b;}

int F[1001],R[1001];

int main(){
    int K,AnsMin=0,AnsMax=0; scanf("%d",&K);
    for(int i=0;i<K;i++) scanf("%d",F+i);
    for(int i=0;i<K;i++) scanf("%d",R+i);
    
    
    bool RV[1001];
    memset(RV,false,sizeof(RV));

    for(int front=0; front<K;front++){
        if(F[front]==0) continue;
        bool isE=false;
        for(int right=0;right<K;right++){
            if(RV[right]==false && R[right]==F[front]){
                isE=true;
                AnsMin+=R[right];
                RV[right]=true;
                break;
            }
        }
        if(!isE) AnsMin+=F[front];
    }
    for(int right=0;right<K;right++){
        if(RV[right]==false) AnsMin+=R[right];
    }
    printf("%d ",AnsMin);


    for(int front=0; front<K;front++){
        if(F[front]==0) continue;
        
        for(int right=0;right<K;right++){
            if(R[right]!=0){
                AnsMax+=min(R[right],F[front]);
            }
        }
    }
    printf("%d\n", AnsMax);

}
