int son[MAXN],top[MAXN],siz[MAXN],dep[MAXN];
int fa[MAXN];

void dfs1(int p,int fath){
	dep[p]=dep[fath]+1;
	siz[p]=1;
	fa[p]=fath;
	for (auto i:v[p]){
		if (i==fath) continue;
		dfs1(i,p);
		siz[p]+=siz[i];
		if (siz[i]>=siz[son[p]]) son[p]=i;
	}
}

void dfs2(int p,int tp){
	top[p]=tp;
	if (son[p]) dfs2(son[p],tp);
	for (auto i:v[p]){
		if (i==fa[p] || i==son[p]) continue;
		dfs2(i,i);
	}
}

inline int lca(int x,int y){
	while (top[x]!=top[y]){
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
		x=fa[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}