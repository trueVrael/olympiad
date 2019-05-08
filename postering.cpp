//author: Tomasz Kaszlewicz
//problem: https://main.mimuw.edu.pl/en/archive/oi/15

#include <cstdio>
#include <stack>

using namespace std;

stack<int> dom;

int main(){
	int n,a,b,res=0;
	scanf("%d",&n);
	for(int i=0; i<n; ++i){
		scanf("%d%d",&a,&b);
		while(!dom.empty()){
				if(dom.top()>b){
					res++;
					dom.pop();
				}
				else
					break;
		}
		if(dom.empty())
			dom.push(b);
		if(!dom.empty() && b>dom.top())
			dom.push(b);
	}
	printf("%d\n",res+dom.size());
return 0;
}

