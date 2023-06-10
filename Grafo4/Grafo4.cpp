#include <iostream>
#include <bits/stdc++.h>

#define INF 1000+1
#define MAX_V 100+1

using namespace std;

int res[MAX_V][MAX_V];
vector<vector<int>> arcs;

void getFlow(int v ,int S ,vector<int>& path, int minEdge, int& flow) {
    if (v == S) {
		flow = minEdge;
	} else if (path[v] != -1) {
		getFlow(path[v], S ,path ,min(minEdge, res[path[v]][v]) ,flow);
		res[path[v]][v] -= flow;
		res[v][path[v]] -= flow;
	}
}

int findBW(int S, int T) {
	int max_flow = 0;
    int flow = 0;
    int u;

    queue<int> q;
    vector<int> path;
    bitset<MAX_V> visited;

	while (1) {

        // for(int i = 1 ; i <= 5 ; i++){
        //     for(int j = 1 ; j <= 5 ; j++){
        //         printf("%2d ",res[i][j]);
        //     }
        //     printf("\n");
        // }
        // printf("\n--------------\n");

		flow = 0;
		
        q = queue<int>();
        visited = bitset<MAX_V>();
		path.assign(MAX_V, -1);

        visited.set(S);
		q.push(S);
		
		while (!q.empty()) {
			u = q.front();
			q.pop();
			if (u == T)
				break;
			for (int& v : arcs[u]) {
				if (res[u][v] > 0 && !visited.test(v)) {
					visited.set(v);
					q.push(v);
					path[v] = u;                    
				}
			}
		}
		getFlow(T, S, path, INF,flow);

		if (flow == 0)break;
        
		max_flow += flow;
	}
    return max_flow;
}

int main() {
    
    int max_flow;
    int n0,n1,bw;
    int N_nodes;
    int S,T,C;

    static int count = 1;

    scanf("%d", &N_nodes);
    if(N_nodes==0) return 0;

    memset(res, 0, sizeof res);
    arcs.assign(N_nodes+1, vector<int>());

    scanf("%d %d %d", &S, &T, &C);

    for (int i = 0; i < C; i++) {
        scanf("%d %d %d",&n0,&n1,&bw);
        res[n0][n1] += bw;
        res[n1][n0] += bw;
        arcs[n0].push_back(n1);
        arcs[n1].push_back(n0);
    }

    max_flow = findBW(S,T);

    printf("Network %d\nThe bandwidth is %d.\n\n", count++, max_flow);

    main();
	return 0;
}