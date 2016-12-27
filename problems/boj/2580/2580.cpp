#include <cstdio>
#include <vector>
using namespace std;

int S[9][9];
vector< pair<int,int> > P;

bool check(int Y,int X){
    if(S[Y][X]==0) return false;
    for(int i=0;i<9;i++){
        if(Y==i) continue;
        if(S[Y][X]==S[i][X]) return false;
    }

    for(int i=0;i<9;i++){
        if(X==i) continue;
        if(S[Y][X]==S[Y][i]) return false;
    }

    int nY = Y-Y%3;
    int nX = X-X%3;

    for(int i=nY;i<nY+3;i++){
        for(int j=nX;j<nX+3;j++){
            if(i==Y && j==X) continue;
            if(S[Y][X]==S[i][j]) return false;
        }
    }
    return true;
}
bool solve(int curIdx){
    if(curIdx==P.size()) return true;
    int curY = P[curIdx].first;
    int curX = P[curIdx].second;

    for(int i=1;i<=9;i++){
        S[curY][curX]=i;
        if(check(curY,curX) && solve(curIdx+1)) return true;
        S[curY][curX]=0;
    }
    return false;
}

int main(){
    
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            scanf("%d ",&S[i][j]);
            if(S[i][j]==0) P.push_back(make_pair(i,j));
        }   
    }
    solve(0);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            printf("%d ",S[i][j]);
        } 
        printf("\n");
    }
    return 0;
}
