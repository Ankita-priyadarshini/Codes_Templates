void solve() {
    ll n, ans = 0; cin >> n;
    vector<ll> p(n), cc(n);
    map<ll, vector<ll>>mp;
    rep(i, n)cin >> p[i];
    rep(i, n) {
        cin >> cc[i];
        mp[p[i]].pb(cc[i]);
    }
    sort(all(p));
    multiset<pair<ll, ll>>s;
    ll c = p[0];
    while (true) {
        if (mp[c].size() > 0) {
            for (auto i : mp[c]) {
                s.insert({i, c});
            }
        }
        if (s.size() > 0) {
            pair<ll, ll> xx = (--s.end()); 
            ll x = xx.first, y = xx.second;
            ans += (c - y) x; c++;
            s.erase(s.find({x, y}));
        }
        if (s.size() == 0) {
            ll j = lower_bound(all(p), c) - p.begin();
            if (j == p.size())break;
            else c = p[j];
        }

    }
    cout << ans << endl;

}