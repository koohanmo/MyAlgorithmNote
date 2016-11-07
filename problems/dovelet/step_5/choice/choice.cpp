#include <cstdio>
#include <vector>
using namespace std;
int A[1001];
int n;
bool check(int tar){
    int next = A[tar];
    for(int i=0;i<n;i++){
        if(next==tar) return true;
        next=A[next];
    }
    return false;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&A[i]);
    int cnt=0;
    vector<int> ret;
    for(int i=1;i<=n;i++)if(check(i)){
        cnt++;
        ret.push_back(i);
    }
    printf("%d\n",cnt);
    for(int i=0;i<ret.size();i++)printf("%d\n",ret[i]);


    return 0;
}
