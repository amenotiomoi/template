//x1<=x<=x2 y1<=y<=y2
vector<int> pointcount_offline(vector<pair<int,int>>point,vector<array<int,4>>query){sort(point.begin(),point.end());vector<int>Q;for(pair<int,int> i:point){Q.push_back(i.first);Q.push_back(i.second);}for(array<int,4> i:query)for(int j:i)Q.push_back(j);sort(Q.begin(),Q.end());Q.resize(unique(Q.begin(),Q.end())-Q.begin());int n=Q.size()+1;for(int i=0;i<(int)point.size();++i){point[i].first=lower_bound(Q.begin(),Q.end(),point[i].first)-Q.begin()+1;point[i].second=lower_bound(Q.begin(),Q.end(),point[i].second)-Q.begin()+1;}for(int i=0;i<(int)query.size();++i)for(int j=0;j<4;++j)query[i][j]=lower_bound(Q.begin(),Q.end(),query[i][j])-Q.begin()+1;vector<vector<array<int,3>>>s(n);vector<vector<int>>p(n);vector<int>a(query.size()),f(n);for(int i=0;i<(int)query.size();++i){s[query[i][1]].push_back({i,1,query[i][3]});s[query[i][1]].push_back({i,-1,query[i][2]-1});s[query[i][0]-1].push_back({i,-1,query[i][3]});s[query[i][0]-1].push_back({i,1,query[i][2]-1});}for(int i=0;i<(int)point.size();++i)p[point[i].first].push_back(point[i].second);for(int i=0;i<n;++i){for(int j:p[i])for(int x=j;x<n;x+=x&-x)f[x]++;for(array<int,3> j:s[i]){int w=0;for(int x=j[2];x!=0;x-=x&-x)w+=f[x];a[j[0]]+=w*j[1];}}return a;}
namespace pointcount_online {
   // init(vector<pair<int,int>> point)   used to init
   // query(int x1,int x2,int y1,int y2)  count number of point which x1<=x<=x2 && y1<=y<=y2
   // query(int x,int y)                  count number of point which point.x<=x&&point.y<=y
   typedef signed pnode;
   struct node{int s;pnode ls,rs;};vector<node> pt;vector<pnode> rt;vector<int> u;
   pnode build(int l,int r){int m=(l+r)/2;node t=(l!=r?node{0,build(l,m),build(m+1,r)}:node{0,-1,-1});pt.push_back(t);return pt.size()-1;}
   pnode add(int l,int r,int x,pnode n){int m=(l+r)/2;node t;if(l==r)t={pt[n].s+1,-1,-1};else if(x<=m)t={pt[n].s+1,add(l,m,x,pt[n].ls),pt[n].rs};else t={pt[n].s+1,pt[n].ls,add(m+1,r,x,pt[n].rs)};pt.push_back(t);return pt.size()-1;}      
   int ask(int l,int r,int L,int R,pnode n){if(L<=l&&r<=R) return pt[n].s;int m=(l+r)/2;if(L>m) return ask(m+1,r,L,R,pt[n].rs);else if(R>m)return ask(l,m,L,R,pt[n].ls)+ask(m+1,r,L,R,pt[n].rs);return ask(l,m,L,R,pt[n].ls);}
   void init(vector<pair<int,int>> point){pt.clear();u.clear();for(pair<int,int> i:point){u.push_back(i.first);u.push_back(i.second);}u.push_back(1-(__int128(1)<<(sizeof(int)*8-1)));u.push_back(-u.back());sort(u.begin(),u.end());u.resize(unique(u.begin(),u.end())-u.begin());for(int i=0;i<(int)point.size();++i){point[i].first=lower_bound(u.begin(),u.end(),point[i].first)-u.begin();point[i].second=lower_bound(u.begin(),u.end(),point[i].second)-u.begin();}rt={build(0,u.size()-1)};vector<vector<int>>q(u.size());for(pair<int,int> i:point)q[i.first].push_back(i.second);for(int i=1;i<(int)u.size();++i){rt.push_back(rt.back());for(int j:q[i])rt.end()[-1]=add(0,u.size()-1,j,rt.end()[-1]);}}
   int query(int x,int y){x=lower_bound(u.begin(),u.end(),x+1)-u.begin()-1;y=lower_bound(u.begin(),u.end(),y+1)-u.begin()-1;return ask(0,u.size()-1,0,y,rt[x]);}
   int query(int x1,int x2,int y1,int y2){return query(x2,y2)-query(x2,y1-1)-query(x1-1,y2)+query(x1-1,y1-1);}
}

