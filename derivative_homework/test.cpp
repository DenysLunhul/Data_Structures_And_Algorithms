#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> parent;
vector<ll> mass;
vector<bool> isPainted;

ll find(ll v) {
    if (parent[v] == v) return v;
    return parent[v] = find(parent[v]);
}


void unions(ll v, ll u) {
    ll a = find(v);
    ll b = find(u);
    if (a == b) return;
    if (mass[a] > mass[b]) swap(a, b);
    parent[a] = b;
    mass[b] += mass[a];
}


int main(){
    ll n;
    cin >> n;
    mass.assign(n + 1, 0);
    isPainted.assign(n + 1, false);
    parent.assign(n + 1, 0);
    for (ll i = 1; i <= n; i++) {
        cin >> mass[i];
        parent[i] = i;
    }
    ll max_mass = 0;
    for (ll i = 1; i <= n; i++) {
        ll move;
        cin >> move;
        isPainted[move] = true;

        if (move > 1 && isPainted[move - 1])
            unions(move, move - 1);
        if (move < n && isPainted[move + 1])
            unions(move, move + 1);

        max_mass = max(max_mass, mass[find(move)]);
        cout << max_mass << " ";
    }
    return 0;
}
