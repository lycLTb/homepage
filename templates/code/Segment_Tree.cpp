struct Segment_Tree{
	const int INF=0x3f3f3f3f;
	struct node{
		int l,r,len;
		int add,v,mn;
	}st[MAXN*4];
	
	void build(int p,int l,int r){
		st[p].l=l;st[p].r=r;
		st[p].len=r-l+1;
		if (l==r){
			st[p].v=a[l];
			st[p].mn=a[l];
			return;
		}
		int mid=l+r>>1;
		build(p<<1,l,mid);
		build(p<<1|1,mid+1,r);
		st[p].v=st[p<<1].v+st[p<<1|1].v;
		st[p].mn=min(st[p<<1].mn,st[p<<1|1].mn);
	}

	void spread(int p){
		st[p<<1].v+=st[p].add*st[p<<1].len;
		st[p<<1|1].v+=st[p].add*st[p<<1|1].len;
		st[p<<1].add+=st[p].add;
		st[p<<1|1].add+=st[p].add;
		st[p<<1].mn+=st[p].add;
		st[p<<1|1].mn+=st[p].add;
		st[p].add=0;
	}

	void change(int p,int l,int r,int c){
		if (l<=st[p].l&&st[p].r<=r){
			st[p].v+=c*st[p].len;
			st[p].add+=c;
			st[p].mn+=c;
			return;
		}
		spread(p);
		int mid=st[p].l+st[p].r>>1;
		if (l<=mid) change(p<<1,l,r,c);
		if (r>mid) change(p<<1|1,l,r,c);
		st[p].v=st[p<<1].v+st[p<<1|1].v;
		st[p].mn=min(st[p<<1].mn,st[p<<1|1].mn);
	}

	int query_sum(int p,int l,int r){
		if (l<=st[p].l&&st[p].r<=r)
			return st[p].v;
		spread(p);
		int mid=st[p].l+st[p].r>>1,ans=0;
		if (l<=mid) ans+=query_sum(p<<1,l,r);
		if (r>mid) ans+=query_sum(p<<1|1,l,r);
		return ans;
	}

	int query_min(int p,int l,int r){
		if (l<=st[p].l && st[p].r<=r)
			return st[p].mn;
		spread(p);
		int mid=st[p].l+st[p].r>>1,ans=INF;
		if (l<=mid) ans=query_min(p<<1,l,r);
		if (r>mid) ans=min(ans,query_min(p<<1|1,l,r));
		return ans;
	}
};