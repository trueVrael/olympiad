//author: Tomasz Kaszlewicz
//problem: https://main.mimuw.edu.pl/en/archive/oi/16/kam

#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

#define MAX_U 10
#define MAX_N 1000

vector<int> b[MAX_U], tmp;

int main(){

int u,ile,licz=0,ixor;
scanf("%d", &u);
for(int i=0; i<u; i++){
	licz=0;
	scanf("%d", &ile);
	if(ile%2!=0){
		licz++;
	}
	b[i] = vector<int>(ile+licz, 0);
	b[i][0]=0;
	for(int j=licz; j<ile+licz; j++){
		scanf("%d", &b[i][j]);	
	}
}
for(int l=0; l<u; l++){
		tmp.clear();
		ixor=0;
		swap(tmp, b[l]);
	if(tmp.size()==2){
		/*if(tmp[0]==0)
			cout<<"TAK";
		else{*/
			ixor=tmp[1] xor tmp[0];
			if(ixor>0)
			cout<<"TAK";
			else
			cout<<"NIE";
		//}
	}
	else{
		ixor=tmp[1]-tmp[0];
		for(int k=2; k<tmp.size(); k+=2)
			ixor=ixor xor (tmp[k+1] - tmp[k]);
		if(ixor>0)
			cout<<"TAK";
		else
			cout<<"NIE";
	}
cout<<endl;
}
return 0;
}

