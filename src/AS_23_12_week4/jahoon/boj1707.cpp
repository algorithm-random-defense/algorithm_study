#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// 이분 그래프
string bfs(int v, vector <vector <int>> &graph){
	vector<int> color(v+1, 0);
    queue<int> q;
    for (int i=1; i<=v; i++) {
        if (color[i]) {
			continue;
		}
        q.push(i);
        color[i] = 1;
        while (!q.empty()){
            int cur = q.front();
            for (int i=0; i<graph[cur].size(); i++) {
                if (!color[graph[cur][i]]) {
                    color[graph[cur][i]] = -color[cur];
                    q.push(graph[cur][i]);
                }
                if (color[graph[cur][i]] == color[cur]) {
					return "NO";
				}
            }
            q.pop();
        }
    }
    return "YES";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
    int t, v, e, a, b;
    cin >> t;
    vector<string> res;
    for (int i=0; i<t; i++) {
        cin >> v >> e;
        vector<vector<int>> graph(v+1);
        for (int i=0; i<e; i++) {
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        res.push_back(bfs(v, graph));
    }

    for (int i=0; i<res.size(); i++) {
        cout<<res[i]<<"\n";
    }
}