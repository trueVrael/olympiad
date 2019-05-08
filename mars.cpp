//author: Tomasz Kaszlewicz
//problem: https://main.mimuw.edu.pl/en/archive/oi/12/lot
#include <cstdio>
#include <vector>

using namespace std;

#define REP(n) for(int i=0; i<(n); i++)
#define FOR(k,n) for(int i=(k); i<(n); i++)
#define REPD(n) for(int i=(n); i>0; i--)

struct pole{
	unsigned int p,d;
};
vector <pole> mars;
bool tab[1000*1001];
int main(){
	int n,tmp=0,ile=0,id,id2,min=2000*1000*1001;
	unsigned int wh,pal=0,droga=0;
	pole stacja;
	scanf("%d", &n);
	REP(n){
		scanf("%d%d", &stacja.p,&stacja.d);
		mars.push_back(stacja);
		tab[i]=0;
		pal+=stacja.p;
		droga+=stacja.d;
	}
	if(pal<droga)
		REP(n)
			printf("NIE\n");
	else{
	//w jednÄ stronÄ
		REP(n){
			tmp+=mars[i].p-mars[i].d;
			if(tmp<min){
				min=tmp;
				wh=i+1;
			}
		}
		REPD(n){
			id=(i+wh)%n;
			if(i!=n)
				ile+=mars[id].p-mars[id].d;
			if(ile>=0){
				tab[id]=1;
			//	printf("%d ok id =\n", id);
				ile=0;
			}
		}
	//w drugÄ stronÄ
		tmp=0;
		ile=0;
		min=2000*1000*1001;
		REPD(n){
			id=i%n;
			id2=(i-1)%n;
		//	printf("tmp = %d min = %d\n",tmp,min);
			tmp+=mars[id].p-mars[id2].d;
			if(tmp<min){
				min=tmp;
				wh=id2;
			//	printf("cos\n");
			}
		}
	//	printf("%d AAAA\n",min); 
		REP(n){
			id=(i+wh)%n;
			id2=(wh+i-1)%n;
			if(i!=0)
				ile+=mars[id].p-mars[id2].d;
			if(ile>=0){
				tab[id]=1;
				ile=0;
			}
		}
		REP(n){
			if(tab[i]==1)
				printf("TAK\n");
			else
				printf("NIE\n");
		}
	}
return 0;
}

