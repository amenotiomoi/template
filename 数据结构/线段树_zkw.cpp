template <class node> class segment1 {
   private:
      int len,siz;
      node* tree;
   public:
      segment1(int n,node y){len=n;siz=(1<<(__lg(n)+1));tree=new node[siz+n+2];for(int i=(len+siz)/2+1;i<=siz+n+1;++i)tree[i]=y;for(int i=(len+siz)/2;i>=1;--i)tree[i]=node::merge(i*2>siz+n+1?y:tree[i*2],i*2+1>siz+n+1?y:tree[i*2+1]);}
      void change(int x,node y){x+=siz;tree[x]=y;for(int i=x/2;i!=0;i/=2)tree[i]=node::merge(tree[i*2],tree[i*2+1]);}
      node query(int l,int r){node answer[2];bool empty[2]={true,true};for(l+=siz-1,r+=siz+1;(l^r)!=1;l>>=1,r>>=1){if(~l&1){answer[0]=empty[0]?tree[l^1]:node::merge(answer[0],tree[l^1]);empty[0]=false;}if(r&1){answer[1]=empty[1]?tree[r^1]:node::merge(tree[r^1],answer[1]);empty[1]=false;}}return empty[0]?answer[1]:empty[1]?answer[0]:node::merge(answer[0],answer[1]);}
      ~segment1(){delete[]tree;}
};
struct node {
   int sum;
   static node merge(node a,node b) {
      return node{a.sum+b.sum};
   }
};
