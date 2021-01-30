struct BIT{
	int tree[MAXN];
	int Max_Value=n;

	inline int lowbit(int x){
	    return x&(-x);
	}

	inline void add(int x,int c){
		while (x<=Max_Value+1){
			tree[x]+=c;
			x+=lowbit(x);
		}
	}

	inline int query(int x){
		int ans=0;
		while (x>0){
			ans+=tree[x];
			x-=lowbit(x);
		}
		return ans;
	}

	inline int query2(int l,int r){
		return query(r)-query(l-1);
	}

	inline void add2(int l,int r,int c){
		add(l,c);
		add(r+1,-c);
	}
};