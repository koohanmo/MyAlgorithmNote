#include <cstdio>
#define ll long long
int main(){
    ll Y=1970,M=1,D=1,H=0,Mm=0,S=0;
    ll n; scanf("%lld",&n);
    n+=(3600*9);
     
    ll mY=365*24*3600;
    ll fmY=mY+24*3600;
    ll sousou= 24*3600*(ll)3652425;
    ll mD=24*3600;
    ll mM[13] ={1, mD*31,mD*28,mD*31,mD*30,mD*31,mD*30,mD*31,mD*31,mD*30,mD*31,mD*30,mD*31};
    ll mH= 3600;
    
    Y+= ((n/sousou)*10000); n%=sousou;
    bool is4=false;
    while(true){
        if(Y%4==0 && Y%100!=0) {
            if(n>=fmY){
            n-=fmY;
            Y++;
            }else {is4=true; goto EX;}
        }else if(Y%400==0){
            if(n>=fmY){
            n-=fmY;
            Y++;
            } else{is4=true; goto EX;}
        }else if(n>=mY){
            n-=mY;
            Y++;
        }else break;
    }

EX:

    if(is4) mM[2]=mD*29;

    for(int i=1;i<=12;i++){
        if(n>=mM[i]>=1){
            M++;
            n-=mM[i];
        }else break;
    } 

    while(n>=mD){
        D++;
        n-=mD;
    }

    H+=n/mH; n%=mH;
    Mm+=n/60; n%=60;
    S+=n;
     
 
    printf("%lld-",Y);
    if(M<10) printf("0");
    printf("%lld-",M);
     
    if(D<10) printf("0");
    printf("%lld ",D);
     
    if(H<10) printf("0");
    printf("%lld:",H);
     
    if(Mm<10) printf("0");
    printf("%lld:",Mm);
     
    if(S<10) printf("0");
    printf("%lld\n",S);
    //1970-01-01 09:00:01
     
 
    return 0;
}
