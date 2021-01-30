int st[35][MAXN];
int lg[MAXN];

void init(){
	for (int i=1;i<=n;i++)
		st[0][i]=a[i];

	for (int i=1;i<=30;i++){
		for (int j=1;j<=n;j++){
			if (j+(1<<i-1)>n) continue;
			st[i][j]=max(st[i-1][j],st[i-1][j+(1<<i-1)]);
		}
	}

	lg[1]=0;
	for (int i=2;i<=n;i++)
		lg[i]=lg[i>>1]+1;
}

int query(int l,int r){
	int _lg=lg[r-l+1];
	return max(st[_lg][l],st[_lg][r-(1<<_lg)+1]);
}