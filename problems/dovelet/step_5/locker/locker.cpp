#include <cstdio>
int A[1001];
int D[1001];

void swap(int* a, int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int main(){
    int n; scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",A+i);
        A[i+n]=A[i];
    }

    int left=0,maxLen=0,right=0;
    for(int i=0;i<n;i++){
        int len=1;
        for(int j=i+1;j<2*n;j++){
            if(A[j-1]!=A[j]-1){
                if(A[j-1]!=n || A[j]!=1) break;
            }
            len++;
        }
        if(len>maxLen){
            left=i;
            maxLen=len;
        }
    }

    int shift1=n-left;
    int convertLeft=maxLen+1,convertRight=n;
    
    for(int i=left;i<left+n;i++) printf("%d ",A[i]);
    printf("\n");

    int tl=left+maxLen,tr=left+n-1;
    convertLeft=tl-left+1;
    while(tl<=tr){
        swap(&A[tl],&A[tr]);
        tl++;
        tr--;
    }

    
    for(int i=left;i<left+n;i++) printf("%d ",A[i]);
    printf("\n");

    int shift2=0;
    for(int i=left;i<left+n;i++){
        if(A[i]==1){
            shift2= left+n-i;
            break;
        }
    }
    printf("%d\n%d %d\n%d\n",shift2,convertLeft,convertRight,shift1);
    return 0;
}
