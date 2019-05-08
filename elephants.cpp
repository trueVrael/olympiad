//author: Tomasz Kaszlewicz
//problem: https://main.mimuw.edu.pl/en/archive/oi/16/slo

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

#define FOR(x,n) for(int x=1; x<=(n); x++)
#define MAX 1000001

int tab[MAX];
int gdzie[MAX];
int jak[MAX];
int zam[MAX];
list<int> cykle[MAX];
int C[MAX];
int min2[MAX];
long long int suma[MAX];
bool help[MAX];

int main(){
int n,a,b,min3=7000,c=0,i;
long long int met1=0,met2=0,w=0;
scanf("%i", &n);
FOR(x,n){
	scanf("%i", &tab[x]);
	min3=min(min3,tab[x]);
}
FOR(x,n)
	scanf("%i", &gdzie[x]);
FOR(x,n)
	scanf("%i", &jak[x]); 
FOR(x,n)
	help[x]=false; 
FOR(x,n){
	a=gdzie[x];
	b=jak[x];
	zam[b]=a;
}
FOR(x,n){
	if(!C[x]){
		c++;
		i=x;
		while(!C[i]){
			C[i]=true;
			cykle[c].push_back(zam[i]);
			i=zam[i];
		}
	}
}



FOR(x,c){
	suma[x]=0;
	min2[x]=7000;
	for(list<int>::iterator iter=cykle[x].begin(); iter != cykle[x].end(); iter++){
		suma[x]+=tab[*iter];
		min2[x]=min(min2[x],tab[*iter]);		
	}
}
FOR(x,c){
	met1=0;
	met2=0;
	if(cykle[x].size()==1)
		met1=0;
	else
		met1=suma[x]+((cykle[x].size()-2)*min2[x]);
	met2=suma[x]+min2[x]+((cykle[x].size()+1)*min3);
	w+=min(met1,met2);
}
cout<<w<<endl;
return 0;
}

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
#define FOR(x,n) for(int x=1; x<=(n); x++)
#define MAX 1000001
int tab[MAX];
int gdzie[MAX];
int jak[MAX];
int zam[MAX];
list<int> cykle[MAX];
int C[MAX];
int min2[MAX];
long long int suma[MAX];
bool help[MAX];

int main(){
int n,a,b,min3=7000,c=0,i;
long long int met1=0,met2=0,w=0;
scanf("%i", &n);
FOR(x,n){
	scanf("%i", &tab[x]);
	min3=min(min3,tab[x]);
}
FOR(x,n)
	scanf("%i", &gdzie[x]);
FOR(x,n)
	scanf("%i", &jak[x]); 
FOR(x,n)
	help[x]=false; 
FOR(x,n){
	a=gdzie[x];
	b=jak[x];
	zam[b]=a;
}
FOR(x,n){
	if(!C[x]){
		c++;
		i=x;
		while(!C[i]){
			C[i]=true;
			cykle[c].push_back(zam[i]);
			i=zam[i];
		}
	}
}



FOR(x,c){
	suma[x]=0;
	min2[x]=7000;
	for(list<int>::iterator iter=cykle[x].begin(); iter != cykle[x].end(); iter++){
		suma[x]+=tab[*iter];
		min2[x]=min(min2[x],tab[*iter]);		
	}
}
FOR(x,c){
	met1=0;
	met2=0;
	if(cykle[x].size()==1)
		met1=0;
	else
		met1=suma[x]+((cykle[x].size()-2)*min2[x]);
	met2=suma[x]+min2[x]+((cykle[x].size()+1)*min3);
	w+=min(met1,met2);
}
cout<<w<<endl;
return 0;
}


