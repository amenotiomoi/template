class tree_hash {
   private:
      typedef unsigned long long ull;
      int *cnt;pair<int,int> *edge;
      void dfs(int x,int fa){hash[x]={107122481065844ull,452841009001ull};for(int i=0;i<tree[x].second;++i){int y=tree[x].first[i];if(y==fa)continue;dfs(y,x);hash[x].first+=nxt(hash[y].first);hash[x].second+=nxt(hash[y].second);}}
      static ull nxt(ull x){x^=x<<7;x^=x>>11;x^=x<<13;return x;}
   public:
      typedef pair<ull,ull> hvalue;
      pair<int*,int> *tree;hvalue *hash;
      static hvalue merge(vector<hvalue> a){hvalue s={107122481065844ull,452841009001ull};for(hvalue i:a){s.first+=nxt(i.first);s.second+=nxt(i.second);}return s;}
      void addedge(int u,int v){edge[tree[0].second++]={u,v};cnt[u]++;cnt[v]++;}
      void init(int root){tree[0].second++;for(int i=1;i<=tree[0].second;++i)tree[i]={tree[i-1].first+cnt[i-1],cnt[i]};for(int i=0;i<tree[0].second-1;++i){pair<int,int>t=edge[i];tree[t.first].first[--cnt[t.first]]=t.second;tree[t.second].first[--cnt[t.second]]=t.first;}delete[]edge;delete[]cnt;dfs(1,0);}
      tree_hash(int n){cnt=new int[n+1];edge=new pair<int,int>[n];tree=new pair<int*,int>[n+1];hash=new hvalue[n+1];for(int i=0;i<=n;++i)cnt[i]=0;tree[0]={new int[n*2-1],0};}
      ~tree_hash(){delete[]tree[0].first;delete[]tree;delete[]hash;}
};