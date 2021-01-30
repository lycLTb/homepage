const int INF=1e9+7;
const int Maxn=10005;
const int MAXM=100005;
int s,t;
int Index=0;
int w[MAXM*2];
vector<int> v[Maxn];
int point[MAXM*2];
int label[Maxn];
int cur[Maxn*2];

void add_edge(int x,int y,int f){
	v[x].push_back((++Index)*2);
	v[y].push_back(Index*2+1);
	w[Index*2]=f;
	w[Index*2+1]=0;
	point[Index*2]=y;
	point[Index*2+1]=x;
}

bool bfs(){
	memset(label,0,sizeof(label));
	memset(cur,0,sizeof(cur));
	queue<int> q;
	q.push(s);
	label[s]=1;
	while (!q.empty()){
		int now=q.front();
		q.pop();
		for (int i=0;i<v[now].size();i++){
			int edge=v[now][i];
			int u=point[edge];
			if (!label[u] && w[edge]){
				label[u]=label[now]+1;
				q.push(u);
			}
		}
	}

	return label[t]!=0;
}

int dfs(int p,int limit){
	if (limit==0||p==t) return limit;

	int used=0;
	for (int i=cur[p];i<v[p].size();i++){
		cur[p]=i;
		int edge=v[p][i];
		int u=point[edge];
		if (w[edge] && label[p]+1==label[u]){
			int flow=dfs(u,min(limit-used,w[edge]));
			used+=flow;
			w[edge]-=flow;
			w[edge^1]+=flow;
			if (used==limit) break;
		}
	}

	return used;
}

int dinic(){
	int ans=0;
	while (bfs())
		ans+=dfs(s,INF);
	return ans;
}