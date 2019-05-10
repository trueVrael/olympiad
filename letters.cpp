//author: Tomasz Kaszlewicz
//problem: https://main.mimuw.edu.pl/en/archive/oi/19/lit

#include <cstdio>
#include <queue>

using namespace std;

int tree[2097151];
int M=1048576;
char jas[1000001];
char mal[1000001];
queue<int> tab[26];

void insert(int x) {
   int e=M+x;
   tree[e]++;
   while (e!=1){
     e>>=1;
     tree[e]=tree[2*e]+tree[(2*e)+1];
   }
}

inline int query(int a, int b) {
   int va = M + a, vb = M + b;
   int wyn=tree[va];
   if (va != vb) wyn+=tree[vb];
   while (va / 2 != vb / 2) {
     if (va%2==0) wyn+=tree[va+1];
     if (vb%2==1) wyn+=tree[vb-1];
     va>>=1; vb>>=1;
   }
   return wyn;
}

int main(){
    int n,gdzie;
    long long int res=0;
    char tmp;
    scanf("%d",&n);
    getchar();
    for(int i=0; i<n; i++){
                    scanf("%c",&jas[i]);
                    tab[jas[i]-'A'].push(i);
    }
    getchar();
    for(int m=0; m<n; m++)         scanf("%c",&mal[m]);
    for(int j=0; j<n; j++){
            tmp=mal[j]-'A';
            gdzie=tab[tmp].front()+query(tab[tmp].front(),n);
            insert(tab[tmp].front());
            tab[tmp].pop();
            res+=gdzie-j;
    }
    printf("%lld\n",res);
    return 0;
}
