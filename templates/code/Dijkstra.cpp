struct node{
	int x,w;
	bool operator<(const node &b)const{
		return w>b.w;
	}
};
int dis[MAXN];
bool vis[MAXN];
vector<node> v[MAXN];

void Dijkstra(int S){
	/*for (int i=1;i<=m;i++){
		int x=read(),y=read(),c=read();
		v[x].push_back((node){y,c});
	}*/

	memset(dis,0x3f3f3f3f,sizeof(dis));
	priority_queue<node> q;

	dis[S]=0;
	q.push((node){S,0});
	while (!q.empty()){
		auto p=q.top();q.pop();
		if (vis[p.x]) continue;
		vis[p.x]=true;

		for (auto i:v[p.x]){
			if (vis[i.x]) continue;
			if (dis[i.x]>p.w+i.w){
				dis[i.x]=p.w+i.w;
				if (!vis[i.x]) q.push((node){i.x,dis[i.x]});
			}
		}
	}
}