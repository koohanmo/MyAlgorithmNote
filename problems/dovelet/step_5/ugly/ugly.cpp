#include <cstdio>
#include <vector>
#include <algorithm>
#define ull unsigned long long
using namespace std;

vector<unsigned long long> temp,Ans;
void make(){
    
    ull two=1;
    for(int i=0;i<63;i++){
        ull three=1;
        for(int j=0;j<63;j++){
            if(two*three <=0) break;
            temp.push_back(two*three);
            three*=3;
        }
        two*=2;
    }
    for(int i=0;i<temp.size();i++){
        ull five=1;
        for(int j=0;j<63;j++){
            if(temp[i]*five<=0) break;
            Ans.push_back(temp[i]*five);
            five*=5;
        }
    }
    sort(Ans.begin(),Ans.end());
}
int main(){
    make();
    int n;scanf("%d",&n);
    printf("The %d'th ugly number is %llu.",n,Ans[n-1]);
    return 0;
}
