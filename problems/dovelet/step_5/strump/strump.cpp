#include <cstdio>
#include <vector>
using namespace std;

int main(){
    int n; scanf("%d",&n);
    vector<int> A(n+2,0);
    for(int i=1;i<=n;i++)scanf("%d",&A[i]);
    for(int i=1;i<=n;i++){
        if(A[i]>=A[i-1] && A[i]>=A[i+1]) printf("%d\n",i);
    }
    return 0;
}
