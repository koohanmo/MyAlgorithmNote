#include <cstdio>
#include <vector>
using namespace std;
int main(){
    int N,B; scanf("%d %d",&N,&B);
    vector<char> Ans;
    while(N!=0){
        int cur = N%B;
        if(cur<=9) Ans.push_back(cur+'0');
        else Ans.push_back(cur-10+'A');
        N/=B;
    }
    for(int i=Ans.size()-1;i>=0;i--)printf("%c",Ans[i]);
    return 0;
}
