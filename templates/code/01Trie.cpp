const int MAXM=10000005;
struct trie{
	int nex[MAXM][3];
	int exist[MAXM];
	int Index=0;

	trie(){
		memset(nex,0,sizeof(nex));
	}

	void insert(int s){
		int p=0;
		for (int i=30;i>=0;i--){
			int now=(s>>i)&1;
			if (!nex[p][now]) nex[p][now]=++Index;
			p=nex[p][now];
		}
	}

	int query(int s){
		int ans=0;
		int p=0;
		for (int i=30;i>=0;i--){
			int now=(s>>i)&1;
			if (nex[p][now^1]){
				p=nex[p][now^1];
				ans+=1<<i;
			}
			else p=nex[p][now];
		}
		return ans;
	}
};