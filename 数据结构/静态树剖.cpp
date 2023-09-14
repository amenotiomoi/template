template<typename node,template<typename>typename ds>class hld:public TreeLCA{};
template<typename node>
class hld<node,cat_tree>:public TreeLCA{
   private:
      cat_tree<node> ds[2];
      vector<node> ar;
      int getsz(vector<vector<int>> &tree){return tree.size()-1;}
      int getsz(pair<int*,int>* &tree){return tree[0].second;}
   public:
      void setvalue(int x,node y){ar[x]=y;}
      void init(int x){TreeLCA::init(x);vector<node> t(ar.size());for(int i=1;i<(int)ar.size();++i)t[dfn[i]]=ar[i];t[0]=t[1];ds[0].init(t);reverse(t.begin(),t.end());ds[1].init(t);t.clear();}
      node query(int l,int r){int n=getsz(tree),fx=lca_top[l],fy=lca_top[r];node ans[2],tmp;bool em[2]={true,true};while(fx!=fy)if(dep[fx]>=dep[fy]){tmp=ds[1].query(n-dfn[l],n-dfn[fx]);ans[0]=em[0]?tmp:node::merge(ans[0],tmp);em[0]=false;l=fa[fx];fx=lca_top[l];}else{tmp=ds[0].query(dfn[fy],dfn[r]);ans[1]=em[1]?tmp:node::merge(tmp,ans[1]);em[1]=false;r=fa[fy];fy=lca_top[r];}if(dfn[l]>=dfn[r])tmp=ds[1].query(n-dfn[l],n-dfn[r]);else tmp=ds[0].query(dfn[l],dfn[r]);if(em[0]&&em[1])return tmp;if(em[0])return node::merge(tmp,ans[1]);if(em[1])return node::merge(ans[0],tmp);return node::merge(ans[0],node::merge(tmp,ans[1]));}
      hld(int n):TreeLCA(n){ar.resize(n+1);}
};
