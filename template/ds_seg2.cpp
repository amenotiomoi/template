template <class node> class segment2 {
   private:
      int id(int l,int r){return (l+r)|(l!=r);}
      void build(int l,int r,typename node::info &y){if(l==r){seg[id(l,r)]=node{y,node::empty_tag()};return;}int mid=(l+r)/2;build(l,mid,y);build(mid+1,r,y);seg[id(l,r)]=node{node::merge(seg[id(l,mid)].Info,seg[id(mid+1,r)].Info),node::empty_tag()};}
      void push_down(int l,int r){int mid=(l+r)/2,ls=id(l,mid),rs=id(mid+1,r),pt=id(l,r);seg[ls]={node::merge(seg[ls].Info,seg[pt].Tag),node::merge(seg[ls].Tag,seg[pt].Tag)};seg[rs]={node::merge(seg[rs].Info,seg[pt].Tag),node::merge(seg[rs].Tag,seg[pt].Tag)};seg[pt].Tag=node::empty_tag();}
      void change(int L,int R,int l,int r,typename node::tag& y){if(L<=l&&r<=R){seg[id(l,r)]={node::merge(seg[id(l,r)].Info,y),node::merge(seg[id(l,r)].Tag,y)};return;}int mid=(l+r)/2;push_down(l,r);if(L<=mid)change(L,R,l,mid,y);if(R>mid)change(L,R,mid+1,r,y);seg[id(l,r)].Info=node::merge(seg[id(l,mid)].Info,seg[id(mid+1,r)].Info);}
      typename node::info query(int L,int R,int l,int r){if(L<=l&&r<=R)return seg[id(l,r)].Info;push_down(l,r);int mid=(l+r)/2;if(L>mid)return query(L,R,mid+1,r);else if(R>mid)return node::merge(query(L,R,l,mid),query(L,R,mid+1,r));else return query(L,R,l,mid);}
   public:
      vector<node> seg;int siz;
      void init(int n,typename node::info y){siz=n;seg.resize(2*n+4);build(1,siz,y);}
      void change(int l,int r,typename node::tag y){change(l,r,1,siz,y);}
      typename node::info query(int l,int r){return query(l,r,1,siz);}
};
struct node {
   struct info {
      int len,sum;
   }Info;
   struct tag {
      int add;
   }Tag;
   static tag empty_tag() {
      return {0};
   }
   static info merge(info a,info b) {
      return {a.len+b.len,a.sum+b.sum};
   }
   static tag merge(tag a,tag b) {
      return {a.add+b.add};
   }
   static info merge(info a,tag b) {
      return {a.len,a.sum+a.len*b.add};
   }
};