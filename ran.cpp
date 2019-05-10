//author: Tomasz Kaszlewicz
//task: https://main.mimuw.edu.pl/en/archive/oi/19/ran

#include <cstdio>
#include <vector>
using namespace std;
  
int m,l,nr,h=0;   
int ile=0;                   // liczba krawêdzi w grafie, g=wierzochelek cyklu, l=ludzie
vector<int> g;
vector<int> cykle;
int f;
int wh[500007];
int cykl[500007];   //numer wierzcho³ka w cyklu
int adj[500007];               // tablicw s¹siadów ka¿dego wierzcho³ka
int prev[500007];
char color[500007];
char color2[500007];
int L[500007]; //poziom w drzewie          
int P[500007][20]; //jakas tablica do LCA
int wysokosc[500007]; 
vector<int> rev[500007];
int mak[500007];
void dfs(int u)               
{
  color[u]=1;                
  int v;
    v = adj[u];
    if(color[v]==0) dfs(v);   
    else if (color[v]==1){
         g.push_back(v);
         ile++;
         };
  color[u]=2;
};
 
//DFS 2, Wysokoœæ
void dfs2(int a,int q){  
  color2[a]=1;
  if(wh[a]==0){
              L[a]=L[adj[a]]+1;
              if(L[a]>wysokosc[wh[q]])
                                  wysokosc[wh[q]]=L[a];
              }
  int o,s=rev[a].size();
  for(int i=0;i<s;i++)
  {
    o= rev[a][i];
    if(color2[o]==0 && wh[o]==0)
                   dfs2(o,q);
  }
  color2[a]=2;
};
 
void process3(){
      int i, j;
   
  //we initialize every element in P with -1
      for (i = 1; i <= m; i++)
          for (j = 0; 1 << j < m; j++)
              P[i][j] = -1;
   
  //the first ancestor of every node i is T[i]
      for (i = 1; i <= m; i++){
         if(wh[i]==0)
                      P[i][0] = adj[i];
      }
   
  //bottom up dynamic programing
      for (j = 1; 1 << j < m; j++)
         for (i = 1; i <= m; i++)
             if (P[i][j - 1] != -1)
                 P[i][j] = P[P[i][j - 1]][j - 1];
  }
 pair<int,int> query(int p, int q)
  {
      int tmp, log, i;
      bool zm=false;
      pair<int,int> res;
  //if p is situated on a higher level than q then we swap them
      if (L[p] < L[q])
          tmp = p, p = q, q = tmp,zm=true;
  //        printf("p = %d  q = %d\n",p,q);
  //we compute the value of [log(L[p)]
      for (log = 1; 1 << log <= L[p]; log++);
      log--;
 //  printf("log = %d\n", log);
  //we find the ancestor of node p situated on the same level
  //with q using the values in P
      for (i = log; i >= 0; i--)
          if (L[p] - (1 << i) >= L[q])
              p = P[p][i];
      if (p == q){
            res.first=p;
            res.second=p;
          return res;
      }
   
  //we compute LCA(p, q) using the values in P
      for (i = log; i >= 0; i--){
          if (P[p][i] != -1 && P[p][i] != P[q][i])
              p = P[p][i], q = P[q][i];
      }
      if(wh[p]!=0){
                   if(!zm){
                         res.first=p;
                         res.second=q;
                   }
                   else{
                        res.first=q;
                        res.second=p;
                   }
      }
      else{        if(!zm){
                           res.first=adj[p];
                           res.second=adj[q];
                   }
                   else{
                         res.first=adj[q];
                         res.second=adj[p];
                   }
      }
      return res;
  }
int main(){
  int b;  //roboczo konce krawedzi
  scanf("%d %d", &m, &l);
  for(int i=1;i<=m;i++)
  {
    scanf("%d",&b);
    adj[i]=b;
    rev[i].push_back(b);
    rev[b].push_back(i);
  }
  for(int y=1; y<=m; y++){
         if(color[y]==0)
                         dfs(y);
  }                          
  for(int o=0; o<ile; o++){
          cykle.push_back(g[o]);
  }
  //PODZIEL CYKLE
  int kt=1;
  int f;
  for(int i=0; i<cykle.size(); i++){          
      int next=-1;
      int liczcos=0;
      f=cykle[i];
      int now=f;  
      cykl[f]=liczcos;
      while(f!=next){
                     next=adj[now];
                     wh[now]=kt;
                     L[now]=0;
                     now=next;
                     liczcos++;
                     cykl[now]=liczcos;
                     if(liczcos>mak[kt])
                                        mak[kt]=liczcos;
      }
      kt++;
  }
  for(int i=1; i<=m; i++){
          if(wh[i]!=0 && color2[i]==0)
                   dfs2(i,i);
                   
  }
  //PODZIELONE
  process3();
  int x,y,help1,help2,dop,dod;
  pair<int,int> wynik;
  for(int i=0; i<l; i++){
          scanf("%d%d",&x,&y);
          if(x==y){
                   printf("0 0\n");
          }
          else{
               wynik=query(x,y);
                   if(wh[wynik.first]==wh[wynik.second]){//jedno drzewo
                        if(wh[x]==wh[y] && wh[x]!=0){    //w jednym cyklu
                                        if(cykl[x]<cykl[y]){
                                                            dop=cykl[y]-cykl[x];
                                                            dod=mak[wh[x]]-cykl[y]+cykl[x];
                                        }
                                        else{
                                             dop=mak[wh[x]]-cykl[x]+cykl[y];
                                             dod=cykl[x]-cykl[y];
                                        }
                                        if(dop<=dod)              printf("%d 0\n",dop);
                                        else                     printf("0 %d\n",dod);
                        }
                        //a tu niestety nie w jednym cyklu
                        //a tu w dodatku w³a¿¹ do jakiegoœ cyklu
                        else{
                             if(wynik.first==wynik.second){
                                        printf("%d %d\n", L[x]-L[wynik.first], L[y]-L[wynik.second]);
                             }
                                        else{
                                             help1=L[x]-L[wynik.first];
                                             help2=L[y]-L[wynik.second];
                                             if(cykl[wynik.first]<cykl[wynik.second]){
                                                            dop=cykl[wynik.second]-cykl[wynik.first];
                                                            dod=mak[wh[wynik.first]]-cykl[wynik.second]+cykl[wynik.first];
                                             }
                                             else{
                                                  dop=mak[wh[wynik.first]]-cykl[wynik.first]+cykl[wynik.second];
                                                  dod=cykl[wynik.first]-cykl[wynik.second];
                                             }
                                                     if(help1+dop==help2+dod){
                                                        if(help1<help2)
                                                            printf("%d %d\n",help1,help2+dod);
                                                        else
                                                            printf("%d %d\n",help1+dop,help2);              
                                                     }
                                                     if(help1+dop>help2+dod){
                                                                    printf("%d %d\n",help1,help2+dod);
                                                     }
                                                     if(help1+dop<help2+dod){
                                                                    printf("%d %d\n",help1+dop,help2);
                                                     }
                             }
                        }
                   }                   
                   else
                       printf("-1 -1\n");                  
          } 
  }
  return 0;
}
