struct mat{
	int _n,_m;
	vector<vector<int> > a;

	mat(){}
	mat(int n,int m,bool eye){
		_n=n;_m=m;
		a.resize(n+1);
		for (int i=0;i<n;i++)
			a[i].resize(m+1);

		if (eye){
			for (int i=0;i<min(_n,_m);i++)
				a[i][i]=1;
		}
	}

	mat(vector<vector<int> > x){
		a=x;
		_n=a.size();_m=a[0].size();
	}

	mat operator *(const mat &b) const{
		mat ans(_n,b._m,false);
		for (int i=0;i<_n;i++){
			for (int k=0;k<_m;k++){
				for (int j=0;j<b._m;j++){
					add(ans.a[i][j],a[i][k]*b.a[k][j]%MOD,MOD);
				}
			}
		}
		return ans;
	}
	void operator *=(mat b) {*this=*this*b;}

	mat operator ^(int b){
		mat x=*this;
		mat ans(x._n,x._m,true);
		while (b){
			if (b&1) ans=ans*x;
			x=x*x;
			b>>=1;
		}
		return ans;
	}

	void print(){
		cout<<"Matrix: "<<_n<<' '<<_m<<endl;
		for (int i=0;i<_n;i++){
			for (int j=0;j<_m;j++)
				cout<<a[i][j]<<' ';
			cout<<endl;
		}
	}
};