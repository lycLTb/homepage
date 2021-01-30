int dfn[MAXN],low[MAXN];
int cnt=0;
int Index=0;
bool in[MAXN];
int s[MAXN],siz=0;
vector<int> scc[MAXN];
int bel[MAXN];

void Tarjan(int p){
	if (dfn[p]) return;
	dfn[p]=low[p]=++Index;
	s[++siz]=p;
	in[p]=true;

	for (int i:v[p]){
		if (!dfn[i]){
			Tarjan(i);
			low[p]=min(low[p],low[i]);
		}
		else if (in[i]) low[p]=min(low[p],dfn[i]);
	}

	if (dfn[p]==low[p]){
		int u=s[siz--];
		in[u]=false;
		bel[u]=++cnt;
		scc[cnt].push_back(u);
		while (u!=p){
			u=s[siz--];
			scc[cnt].push_back(s[u]);
			in[u]=false;
			bel[u]=cnt;
		}
	}
}