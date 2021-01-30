inline int ksm(int x,int y){
    int ans=1;
    while (y){
        if (y&1) ans=ans*a;
        a=a*a;
        b>>=1;
    }
}