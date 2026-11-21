#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(int i = (int) a; i < (int) b; i++)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i = (int)b-1; i>=(int)a;--i)
#define dforn(i,n) for(int i = (int)n-1; i>=0; i--)
#define fore(e,c) for(const auto &e: (c))
#define pb push_back
#define ln '\n'
#define sz(c) ((int)c.size())
#define zero(v) memset(v,0,sizeof(v))
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const ll INFLL = 1e18; // 9e18 puede desbordar si le sumás algo, 1e18 es más seguro xd
const int INF = 1e9;
const int MAXN = 100001;
vector<pii> adj[MAXN];  // guardo {vertice, arista}
set<pii> ncs;
int low[MAXN]; // low[u]: el minimo tin que se puese llegar desde un subarbol de u, usando como mucho 
                    //una arista q no sea del arbol. es decir una arista q no es del arbol q llegue a q solo otro vertice
int tin[MAXN]; //el orden en el que voy descubriendo los vertices: indican que tan arriba estarian
int ultTin = 1;

void dfs(int u, int arista_donde_vengo){
    tin[u] = ultTin;
    ultTin++;
    low[u] = tin[u];
    for(auto [v , e]: adj[u]){
        if(e == arista_donde_vengo) continue;
        if(tin[v] == 0){    // no visito nadie este nodo por otro camino antes
            dfs(v, e);     //tiro la dfs en v a ver a donde llega
                       // despues de la dfs veo hasta donde llego v segun su low
            if(low[v] > tin [u]){       // si el minimo tin al que puedo llegar por un subarbol de v es mas grande que 
                                        // mi tin, significa que yendo por abajo no puedo volver a subir. es decir si 
                                        //desconecto esta arista el resto para abajo quedaran desconectadas pq no hay otro path
                ncs.insert({min(u,v), max(u,v)});   //pa no repetir
            }
            low[u] = min(low[u], low[v]);
        }
        else {    // esta arista ya fue visitada es decir se sale del arbol
            low[u] = min(tin[v], low[u]); //miro solo tin de v porque es solo hasta v no miro mas arriba que v
            
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    forn(i, m){
        cin >> a >> b;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    }
    dfs(1, -1);
    cout << ncs.size() << ln;
    for(auto [u, v] : ncs){
        cout << u << " " << v << ln;
    }
    return 0;
}