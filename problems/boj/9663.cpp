#include <cstdio>
#include <vector>
#include <utility>
using namespace std;
int n;
vector< pair<int,int> > C;

int abs(int a) { return a>0? -a:a;}

bool check(int Y,int X){
    for(int i=0;i<C.size();i++){
        int dY = Y-C[i].first;
        int dX = X-C[i].second;
        if(dY==0 || dX==0) return false;
        if(abs(dX)==abs(dY)) return false;
    }
    return true;
}

int solve(int curY,int curX){
    if(curY >=n) return 0;
    int curSum=0;
    if(check(curY,curX)) {
        if(curY==n-1) return 1;
        C.push_back(make_pair(curY,curX));
    }
    else return 0;
    for(int i=0;i<n;i++){
        curSum+=solve(curY+1,i);
    }
    C.pop_back();
    return curSum;
}
int main(){
    scanf("%d",&n);
    int Ans =0;
    for(int i=0;i<n;i++) Ans+=solve(0,i);
    printf("%d\n",Ans);
    return 0;
}
