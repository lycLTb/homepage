const int MAXM=1000005;
struct trie{
	int nex[MAXM][27];
	int exist[MAXM];
	int Index=0;

	trie(){
		memset(nex,0,sizeof(nex));
		memset(exist,0,sizeof(exist));
	}

	void insert(string s,int pos){
		int p=0;
		for (int i=0;i<s.size();i++){
			int now=s[i]-'a'+1;
			if (!nex[p][now]) nex[p][now]=++Index;
			p=nex[p][now];
		}
		exist[p]=pos;
	}

	int query(string s){
		int p=0;
		for (int i=0;i<s.size();i++){
			int now=s[i]-'a'+1;
			if (!nex[p][now]) return 0;
			p=nex[p][now];
		}
		return exist[p];
	}
};