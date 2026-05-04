#include <bits/stdc++.h>
using namespace std;

vector<long long> dijkstra(int start, int n , vector<vector<pair<int,int>>>& graph){
    vector<long long> dist(n + 1, LLONG_MAX);
    dist[start] = 0;

    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    pq.push({0, start});

    while(!pq.empty()){
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(d > dist[u]) continue;

        for(int i = 0; i < graph[u].size(); i++){
            int v = graph[u][i].first;
            int w = graph[u][i].second;
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main(){
    int n, m, q, c;
    cin >> n >> m >> q >> c;
    vector<vector<pair<int,int>>> graph(n + 1);

    for(int i = 0; i < m; i++){
        int x, y, d;
        cin >> x >> y >> d;
        graph[x].push_back({y, d});
        graph[y].push_back({x, d});
    }

    vector<long long> distFromKaterynka = dijkstra(c, n, graph);

    for(int i = 0; i < q; i++){
        int v, u;
        cin >> v >> u;

        long long toKaterynka = distFromKaterynka[v];
        long long toMarichka = distFromKaterynka[u];

        cout << toKaterynka + toMarichka << endl;
    }
    return 0;
}