class TreeLCA {
   public:
      vector<int> lca_top;
      vector<bool> lca_hev;
      void lca_dfs1(int p,int f,int d){int s=0,u=0;fa[p]=f;dep[p]=d;for(int i:tree[p]){if(i==f) continue;lca_dfs1(i,p,d+1);siz[p]+=siz[i];if(siz[i]>s){s=siz[i];u=i;}}siz[p]++;lca_hev[u]=true;}
      void lca_dfs2(int p,int f){lca_top[p]=lca_hev[p]?lca_top[f]:p;for(int i:tree[p])if(i!=f)lca_dfs2(i,p);}
      void diam_dfs(int x,int f,int dep,int& y,int &z){if(dep>y){y=dep;z=x;}for(int i:tree[x])if(i!=f)diam_dfs(i,x,dep+1,y,z);}
      void gc_dfs(int x,int f,vector<int>& sz,vector<int>& we,vector<int> &ct){sz[x]=1;we[x]=0;for(int i:tree[x])if(i!=f){gc_dfs(i,x,sz,we,ct);sz[x]+=sz[i];we[x]=max(we[x],sz[i]);}we[x]=max(we[x],(int)sz.size()-1-sz[x]);if(we[x]<=((int)sz.size()-1)/2)ct.push_back(x);}
      void dfn_dfs(int x,int f,int &cnt){dfn[x]=++cnt;for(int i:tree[x])if(i!=f)dfn_dfs(i,x,cnt);}
      int jump(int v){return lca_hev[v]?lca_top[v]:fa[v];}
   public:
      typedef pair<int,int> path;
      vector<vector<int>> tree;
      vector<int> siz,dep,fa,dfn;
      void resize(int n){tree.clear();tree.resize(n+1);}
      void addedge(int u,int v){tree[u].push_back(v);tree[v].push_back(u);}
      void init(int Root){int n=tree.size()-1,cnt=0;for(auto i:{&siz,&dep,&fa,&lca_top,&dfn}){i->clear();i->resize(n+1);}lca_hev.clear();lca_hev.resize(n+1);lca_dfs1(Root,0,1);lca_dfs2(Root,0);for(int i=1;i<=n;++i){vector<int> r;for(int j:tree[i])if(j!=fa[i]){r.push_back(j);if(lca_hev[j]) swap(r.end()[-1],r[0]);}if(fa[i]!=0)r.push_back(fa[i]);tree[i]=r;}dfn_dfs(Root,0,cnt);}
      int lca(int u,int v){while(lca_top[u]!=lca_top[v]){if(dep[jump(u)]<dep[jump(v)])v=jump(v);else u=jump(u);}return(dep[u]<dep[v]?u:v);}
      int dis(int u,int v){return dep[u]+dep[v]-dep[lca(u,v)]*2;}
      int dis(path x){return dis(x.first,x.second);}
      int nxt(int u,int v){if(u==v)return u;if(lca(u,v)!=u)return fa[u];return *(lower_bound(tree[u].begin(),tree[u].end()-(fa[u]!=0),v,[this](int x,int y)->int{return dfn[x]<=dfn[y];})-1);}
      path inter(path a,path b){array<int,4>x{lca(a.first,b.first),lca(a.first,b.second),lca(a.second,b.first),lca(a.second,b.second)};sort(x.begin(),x.end(),[this](int x,int y)->int{return dep[x]>dep[y];});if(x[0]!=x[1]||dep[x[0]]==max(dep[lca(a.first,a.second)],dep[lca(b.first,b.second)]))return{x[0],x[1]};return{-1,-1};}
      path diam(){int dep1=0,idx1=0,dep2=0,idx2=0;diam_dfs(1,0,0,dep1,idx1);diam_dfs(idx1,0,0,dep2,idx2);return{idx1,idx2};}
      pair<int,int> gravity_center(){int n=tree.size()-1;vector<int>sz(n+1),we(n+1),ct;gc_dfs(1,0,sz,we,ct);ct.push_back(0);return{ct[0],ct[1]};}
      TreeLCA(int n){resize(n);}TreeLCA(){}
};
