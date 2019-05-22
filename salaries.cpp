//author: Tomasz Kaszlewicz
//problem: https://main.mimuw.edu.pl/en/archive/oi/19/pen

#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

#define FI first
#define SD second

using namespace std;

const int MAXN = 1000007;
int key[MAXN];
//stosy K i P z rozwiazania wzorcowego zastepione prezz kolejki K i P
queue<int> K, P;
vector<int> edges[MAXN], parent,m;
bool final[MAXN], used[MAXN];

vector<pair<int, int> > T;
vector<pair<int, int> >::iterator it_pair;

int size(int v){
    int res = 1;
    for (vector<int>::iterator it = edges[v].begin(); it != edges[v].end(); it++)
        res += size(*it);
    return res;
}

//szuka sciezki, konczy przy rozwidleniu
void dfs(int v) {
    key[v] = m.back();
	m.pop_back();
    if (edges[v].size() == 1)
        dfs(edges[v].back());
}

int main(void) {
	
    int n,p,z,curr,s;
	bool certain;
	
	scanf("%d", &n);
	
    for (int i=0; i<n; i++){
		scanf("%d%d", &p, &z);
        parent.push_back(p-1);
        key[i] = z-1;
    }
    
    for (int i=0; i<n; i++){
        curr = parent[i];
        if (curr == i)
            key[curr] = n-1;
        if (key[i] == -1){
        	if (key[curr] == -1)
				edges[curr].push_back(i);
        	else{
        		pair<int,int> tmp;
        		tmp.FI = key[curr];
        		tmp.SD = i;
            	T.push_back(tmp);
        	}
        }
    }

    sort(T.begin(), T.end());
    
    for (int i=0; i<n; i++)
        if (key[i] != -1)
            used[key[i]] = true;
    
    for (int i=0; i<n; i++){
        if (!used[i]){
            K.push(i);
            P.push(i);
        }
    }

    for (it_pair = T.begin(); it_pair != T.end(); it_pair++){
        pair<int,int> Ti = *it_pair;
        s = size(Ti.SD);
        certain = false;
        m.clear();
        //4 akapit rozwiazania wzorcowego
        while ((!K.empty()) && (K.front() < Ti.FI) && ((int)m.size() < s)) {
            m.push_back(K.front());
            K.pop();
        }

        if (K.empty() || K.front() > Ti.FI)
            dfs(Ti.SD);
        else
            certain = true;
            
        while ((!P.empty()) && (P.front() < Ti.FI)) {
            if (certain)
                final[P.front()] = true;
            P.pop();
        }
    }
    
    for (int i=0; i<n; i++){
    	if((key[i] != -1) && !(final[key[i]]))
			printf("%d\n", key[i]+1);
		else
			printf("0\n");
    }
return 0;
}
