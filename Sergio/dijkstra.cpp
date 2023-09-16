#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define pb push_back
#define INF INT_MAX

const int MAXN = 1e6;

vector<pii> adj [MAXN+1];
int dist [MAXN+1], processed [MAXN+1]{};

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w; // NO NEGATIVE EDGES
		adj[a].pb({b, w});
		adj[b].pb({a, w});
	}
	
	for (int i = 1; i <= n; i++) dist[i] = INF;

	int x = 1; // Starting node
	dist[x] = 0;
	priority_queue<pii> pq;
	pq.push({0,x});
	while (!pq.empty()) {
		int a = pq.top().second; pq.pop();
		if (processed[a]) continue;
		processed[a] = true;
		for (auto u : adj[a]) {
			int b = u.first, w = u.second;
			if (dist[a]+w < dist[b]) {
				dist[b] = dist[a]+w;
				pq.push({-dist[b],b});
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << i << ": " << dist[i] << endl;
	}
}

/*
This is O(n + m logm)

If you want negative edges, use bellman-ford / SPFA
- Similar, but process use normal queue (according to CPH) 
- Whenever reduced distance, add to queue
- Process all elements in the queue
- Only add elements to the queue if distance is smaller ofc
- O(nm) worst case, but usually faster than bellman-ford
*/
