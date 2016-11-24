#include <cstdio>
int A[12][2];
int main(){
    int mul,area=0; scanf("%d",&mul);
    
    for(int i=0;i<6;i++) {
        scanf(" %d %d ",&A[i][0],&A[i][1]);
        A[i+6][0]=A[i][0];
        A[i+6][1]=A[i][1];
    }
    for(int i=0;i<6;i++){
      
        if(A[i][0]==A[i+2][0] && A[i+1][0]==A[i+3][0]){
            area = A[i+4][1]*A[i+5][1] - A[i+1][1]*A[i+2][1];
            break;
        }
    }
    printf("%d\n",mul*area);
    return 0;
}
