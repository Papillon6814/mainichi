    #include <bits/stdc++.h>
    #define rep(i,n)for(int i=0;i<(n);i++)
    #define INF 0x3f3f3f3f
    #define INFL 0x3f3f3f3f3f3f3f3f
    #define EPS (1e-10)
    #define MOD 1000000007
    using namespace std;
    typedef long long ll;
    typedef pair<int,int>P;
     
    signed main(){
    	int n;scanf("%d",&n);
    	set<int>se;
    	rep(i,n){
    		int a;cin>>a;
    		se.insert(a);
    	}
    	cout<<se.size()<<endl;
    }