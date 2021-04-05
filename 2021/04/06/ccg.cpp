    #include<iostream>
    #include<algorithm>
    #include<string>
    #include<map>
    using namespace std;
    #define REP(i, a, n) for(int i=a; i<n; i++)
     
    int n, m;
    map<string, int> mp;
    int main()
    {
    	cin >> n;
    	REP(i, 0, n) {
    		string s;
    		cin >> s;
    		mp[s]++;
    	}
    	cin >> m;
    	REP(i, 0, m) {
    		string s;
    		cin >> s;
    		mp[s]--;
    	}
    	int ans = 0;
    	for (auto itr : mp) {
    		ans = max(ans, itr.second);
    	}
    	cout << ans << endl;
    	return 0;
    }