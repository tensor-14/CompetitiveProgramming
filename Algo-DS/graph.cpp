#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define ss(s) scanf("%s",s)
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define ps(s) printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());

const int mod = 1'000'000'007;
const int N = 3e5, M = N;
//=======================

class Graph{
	int V;
	list<int> *adj;
	void DFSUtil(int v, bool visited[]);

	public:
	Graph(int V);
	void addEdge(int v, int w);
	void BFS(int s);
	void DFS(int v);
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
}

void Graph::BFS(int s){
	bool *visited = new bool[V];
	fo(i, V)
		visited[i] = false;
	
	list<int> queue;
	visited[s] = true;
	queue.push_back(s);
	
	list<int>::iterator i;
	while(!queue.empty()){
		s = queue.front();
		cout<<s<<" ";
		queue.pop_front();

		for(i = adj[s].begin(); i != adj[s].end(); ++i){
			if(!visited[*i]){
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
}

void Graph::DFSUtil(int v, bool visited[]){
	visited[v] = true;
	cout<<v<<" ";

	list<int>::iterator i;
	for(i = adj[v].begin(); i != adj[v].end(); ++i)
		if(!visited[*i])
			DFSUtil(*i, visited);
}

void Graph::DFS(int v){
	bool *visited = new bool[V];
	fo(i, V)
		visited[i] = false;

	DFSUtil(v, visited);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);
	
	cout<<"Following is the BFT "
			<<"(starting from vertex 2) \n";
	g.BFS(2);
	cout<<"\nDFT \n";
	g.DFS(2);

	return 0;
}
