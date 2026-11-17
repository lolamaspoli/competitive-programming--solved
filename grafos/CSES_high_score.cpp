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

const ll INF = 1e18; // 9e18 puede desbordar si le sumás algo, 1e18 es más seguro xd
const int MAXN = 5000;

struct Arista {
    int d; //desde
    int h; //hasta
    ll w;
};

vector<Arista> graph;
ll dist[MAXN];
int n;

void func (int src){
    fill(dist, dist+n, INF);
    dist[src] = 0;
    forn(i, n-1){ // lo hago n-1 rondas q me asegura q mejoro todo
        for(auto &e : graph){
            if(dist[e.d] == INF) continue; //si todavia no puedo llegar al origen no analizo las destino
            if(dist[e.h] > dist[e.d] + e.w){ // puedo mejorar y relajar la arista
                dist[e.h] = dist[e.d] + e.w;
            }
        }
    }

    //no alcanza con ver si tiene ciclos negativos: tengo que ver si los ciclos negativos afectan mi camino de 1 a n
    //hago n rondas mas para comprobar si algun ciclo negativo afecta mi n
    //propago un -INF cuando hay ciclo negativo y veo si afecta a mi nodo final
    forn(i, n){
        for(auto &e : graph){
            if(dist[e.d] == INF) continue;
            if(dist[e.d] == -INF || dist[e.h] > dist[e.d]+e.w){ // si mejora inicia propagacion por un ciclo negativo. si habia propagacion continua
                dist[e.h] = -INF;
            }
        }
    }
    if(dist[n-1] == -INF) {
        cout << -1 << ln;
    } else {
        cout << -dist[n-1] << ln;
    }
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m, a, b;
    ll w;
    cin >> n >> m;
    
    forn(i,m){
        cin >> a >> b >> w;
        a--;
        b--;
        graph.push_back({a, b, -w}); //invierto el w para maximizar
    }
    func(0);
    return 0;


}