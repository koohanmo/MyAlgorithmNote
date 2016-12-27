#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int L,N;
char S[16];

bool check(vector<char>& result){
    int ja=0,mo=0;
    for(int i=0;i<result.size();i++) {
        if(result[i]=='a'  ||result[i]=='e'|| result[i]=='i'|| result[i]=='o'|| result[i]=='u' ) mo++;
        else ja++;
    }
    if(mo>=1 && ja>=2) return true;
    else return false;
}

void find(int cur, int tot, vector<char>& result){
    if(tot>L || cur >=N) return;
    if(tot==L) {
        if(check(result)){
            for(int i=0;i<result.size();i++) printf("%c",result[i]);
            printf("\n");
        }
        return;
    }
    for(int i=cur+1;i<N;i++){
        result.push_back(S[i]);
        find(i,tot+1,result);
        result.pop_back();
    }
    
}
int main(){
    scanf("%d %d ",&L,&N);
    for(int i=0;i<N;i++)scanf("%c ",S+i);
    sort(S,S+N);
    for(int i=0;i<N;i++){
        vector<char> r(1,S[i]);
        find(i,1,r);
    }
    return 0;
}
