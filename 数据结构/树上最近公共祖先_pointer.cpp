// 对于每一个树都需要在添加恰好 n-1 个边后进行 init，再进行析构，否则是 UB（例如，只在主函数内定义一个 TreeLCA 后立刻结束，是 UB）
class TreeLCA {
   public:
      int*cnt;pair<int,int>*edge;
      void lca_dfs1(int p,int f,int d){int u=0;fa[p]=f;dep[p]=d;siz[p]=1;for(int i=0,s=0;i<tree[p].second;++i){int t=tree[p].first[i];if(t==f)continue;lca_hev[t]=false;lca_dfs1(t,p,d+1);siz[p]+=siz[t];if(siz[t]>s){s=siz[t];u=t;}}lca_hev[u]=true;}
      void lca_dfs2(int p,int f){lca_top[p]=lca_hev[p]?lca_top[f]:p;for(int i=0;i<tree[p].second;++i)if(tree[p].first[i]!=f)lca_dfs2(tree[p].first[i],p);}
      void dfn_dfs(int p,int f,int& dfn_cnt){dfn[p]=++dfn_cnt;for(int i=0;i<tree[p].second;++i)if(tree[p].first[i]!=f)dfn_dfs(tree[p].first[i],p,dfn_cnt);}
      void diam_dfs(int x,int f,int dep,int& y,int &z){if(dep>y){y=dep;z=x;}for(int i=0;i<tree[x].second;++i)if(tree[x].first[i]!=f)diam_dfs(tree[x].first[i],x,dep+1,y,z);}
      void gc_dfs(int x,int f,int* sz,int* we,int* ct,int &cnt){sz[x]=1;we[x]=0;for(int i=0;i<tree[x].second;++i)if(tree[x].first[i]!=f){gc_dfs(tree[x].first[i],x,sz,we,ct,cnt);sz[x]+=sz[tree[x].first[i]];we[x]=max(we[x],sz[tree[x].first[i]]);}we[x]=max(we[x],tree[0].second-sz[x]);if(we[x]<=tree[0].second/2){ct[cnt]=x;cnt++;}}
      int jump(int v){return lca_hev[v]?lca_top[v]:fa[v];}
   public:
      typedef pair<int,int> path;
      pair<int*,int>*tree;bool *lca_hev;int *siz,*dep,*fa,*dfn,*lca_top;
      void addedge(int u,int v){edge[tree[0].second++]={u,v};cnt[u]++;cnt[v]++;}
      void init(int Root){tree[0].second++;for(int i=1;i<=tree[0].second;++i)tree[i]={tree[i-1].first+cnt[i-1],cnt[i]};for(int i=0;i<tree[0].second-1;++i){pair<int,int>t=edge[i];tree[t.first].first[--cnt[t.first]]=t.second;tree[t.second].first[--cnt[t.second]]=t.first;}delete[]edge;delete[]cnt;for(int**i:{&siz,&dep,&fa,&dfn,&lca_top}){*i=new int[tree[0].second+1];}lca_hev=new bool[tree[0].second+1];lca_hev[Root]=false;dep[0]=0;lca_dfs1(Root,0,1);lca_dfs2(Root,0);for(int i=1;i<=tree[0].second;++i){int hevid=-1,faid=-1;for(int j=0;j<tree[i].second;++j){if(tree[i].first[j]==fa[i])faid=j;else if(lca_hev[tree[i].first[j]])hevid=j;}if(hevid==-1)continue;swap(tree[i].first[hevid],tree[i].first[0]);if(faid==0)faid=hevid;if(faid!=-1)swap(tree[i].first[faid],tree[i].first[tree[i].second-1]);}int dfn_cnt=0;dfn_dfs(Root,0,dfn_cnt);}
      int lca(int u,int v){while(lca_top[u]!=lca_top[v]){if(dep[jump(u)]<dep[jump(v)])v=jump(v);else u=jump(u);}return dep[u]<dep[v]?u:v;}
      int dis(int u,int v){return dep[u]+dep[v]-dep[lca(u,v)]*2;}
      int dis(path x){return dis(x.first,x.second);}
      int nxt(int u,int v){if(u==v)return u;if(lca(u,v)!=u)return fa[u];return *(lower_bound(tree[u].first,tree[u].first+tree[u].second-(fa[u]!=0),v,[this](int x,int y)->int{return dfn[x]<=dfn[y];})-1);}
      path inter(path a,path b){array<int,4>x{lca(a.first,b.first),lca(a.first,b.second),lca(a.second,b.first),lca(a.second,b.second)};sort(x.begin(),x.end(),[this](int x,int y)->int{return dep[x]>dep[y];});if(x[0]!=x[1]||dep[x[0]]==max(dep[lca(a.first,a.second)],dep[lca(b.first,b.second)]))return{x[0],x[1]};return{-1,-1};}
      path diam(){int dep1=0,idx1=0,dep2=0,idx2=0;diam_dfs(1,0,0,dep1,idx1);diam_dfs(idx1,0,0,dep2,idx2);return{idx1,idx2};}
      pair<int,int> gravity_center(){int n=tree[0].second;int *sz=new int[n+1],*we=new int[n+1],*ct=new int[2],count;ct[0]=ct[1]=0;gc_dfs(1,0,sz,we,ct,count);pair<int,int>answer={ct[0],ct[1]};delete[]sz;delete[]we;delete[]ct;return answer;}
      vector<int> Edge(int x){vector<int> s(tree[x].second);for(int i=0;i<tree[x].second;++i)s[i]=tree[x].first[i];return s;}
      TreeLCA(int n){cnt=new int[n+1];edge=new pair<int,int>[n];tree=new pair<int*,int>[n+1];for(int i=0;i<=n;++i)cnt[i]=0;tree[0]={new int[n*2-1],0};}
      ~TreeLCA(){delete[]lca_hev;for(int**i:{&siz,&dep,&fa,&dfn,&lca_top})delete[]*i;}
};
