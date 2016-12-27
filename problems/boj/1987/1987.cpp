#include <cstdio>
#include <cstring>
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
char T[22][22];
bool visit[30];
int Ans=0;
int R,C; 
void search(int curY,int curX,int tot){
    if(curY<0 || curY >=R || curX<0 || curX>=C || visit[T[curY][curX]-'A']) return ;
    if(tot>Ans) Ans=tot;
    visit[T[curY][curX]-'A']=true;
    for(int i=0;i<4;i++) search(curY+dir[i][0],curX+dir[i][1],tot+1);
    visit[T[curY][curX]-'A']=false;
}
int main(){
    memset(visit,false,sizeof(visit));
    scanf("%d %d",&R,&C);    
    for(int i=0;i<R;i++) scanf("%s",T[i]);
    search(0,0,1);
    printf("%d\n",Ans);
    return 0;
}
