template <class node> class cat_tree {
   private:
   public:
      vector<vector<node>> ct;
      void init(vector<node> a){int n=a.size();ct={a};for(int i=1,v=(n==1?0:__lg(n-1)+1),f=1;i<v;++i,f=1){ct.push_back(a);for(int j=0;j<(n>>i);++j,f^=1)if(f)for(int k=(1<<i)-2;k>=0;--k)ct[i][(j<<i)+k]=node::merge(ct[i][(j<<i)+k],ct[i][(j<<i)+k+1]);else for(int k=1;k<=(1<<i)-1;++k)ct[i][(j<<i)+k]=node::merge(ct[i][(j<<i)+k-1],ct[i][(j<<i)+k]);if(f)for(int k=n-2;k>=n/(1<<i)*(1<<i);--k)ct[i][k]=node::merge(ct[i][k],ct[i][k+1]);else for(int k=n/(1<<i)*(1<<i)+1;k<n;++k)ct[i][k]=node::merge(ct[i][k-1],ct[i][k]);}}
      node query(int l,int r){if(l==r)return ct[0][l];int v=__lg(l^r);return node::merge(ct[v][l],ct[v][r]);}
};
struct node {
   int value;
   static node merge(node a,node b) {
      return {max(a.value,b.value)};
   }
};