template <class node> class splay {
   private:
      splay *son[2],*fa;int w;node t;
      void upd(){w=son[0]->w+son[1]->w+1;t=node::merge(son[0]->t,son[1]->t);}
      void rotate(bool f){splay *a=son[!f]->son[!f],*b=son[!f]->son[f],*c=son[f];swap(son[0],son[1]);son[f]->son[!f]=b;son[f]->son[f]=c;son[!f]=a;b->fa=c->fa=son[f];a->fa=this;son[f]->upd();upd();}
      void toroot(splay* p){while(true){if(p==this)break;if(p->fa==this){rotate(p==son[0]);break;}if((p->fa->son[0]==p)==(p->fa->fa->son[0]==p->fa)){p->fa->fa->rotate(p->fa->fa->son[0]==p->fa);p->fa->rotate(p->fa->son[0]==p);p=p->fa;}else{p->fa->rotate(p->fa->son[0]==p);p=p->fa;p->fa->rotate(p->fa->son[0]==p);p=p->fa;}}}
      splay(vector<node>&a,int n){son[0]=new splay(a[n]);if(n+2==(int)a.size())son[1]=new splay(a.back());else son[1]=new splay(a,n+1);son[0]->fa=this;son[1]->fa=this;upd();}
      void kth(int k){splay* q=this;while(q->son[0]!=nullptr){int v=q->son[0]->w;if(k==v+1){toroot(q);return;}if(k<=v)q=q->son[0];else{q=q->son[1];k-=v+1;}}toroot(q);}
   public:
      void change(int x,node y){if(w==1){t=y;return;}if(x==1){kth(2);son[0]->t=y;upd();return;}if(x==(w+1)/2){kth(w-1);son[1]->t=y;upd();return;}kth(2*x-2);son[1]->kth(2*x-son[0]->w-1);son[1]->son[0]->t=y;son[1]->upd();upd();}
      node query(int l,int r){if(l==1&&r==(w+1)/2)return t;if(l==1){kth(2*r);return son[0]->t;}if(r==(w+1)/2){kth(2*(l-1));return son[1]->t;}kth(2*(l-1));son[1]->kth(2*(r-l+1));return son[1]->son[0]->t;}
      splay cut(int l,int r){if(l==1){kth(2*r);splay ans=*son[0],tmp=*son[1];ans.fa=nullptr;delete son[1];*this=tmp;if(son[0]!=nullptr) son[0]->fa=son[1]->fa=this;return ans;}if(r==(w+1)/2){kth((l-1)*2);splay ans=*son[1],tmp=*son[0];ans.fa=nullptr;delete son[0];*this=tmp;if(son[0]!=nullptr) son[0]->fa=son[1]->fa=this;return ans;}kth((l-1)*2);son[1]->kth(2*(r-l+1));splay ans=*son[1]->son[0],*tmp=son[1]->son[1];ans.fa=nullptr;delete son[1];son[1]=tmp;tmp->fa=this;upd();return ans;}
      void insert(splay &x,int p){if(x.w==0) return;if(w==0){*this=x;}else if(w==1){splay* tmp=new splay(*this),*pt=new splay(x);tmp->fa=this;pt->fa=this;if(0<=p&&p<=1){son[p]=pt;son[!p]=tmp;}else assert(false);upd();}else if(p==0){kth(2);splay *t1=new splay(*son[0]),*t2=new splay(x);t1->fa=son[0];t2->fa=son[0];son[0]->son[0]=t2;son[0]->son[1]=t1;son[0]->upd();upd();}else if(p==(w+1)/2){kth(w-1);splay *t1=new splay(*son[1]),*t2=new splay(x);t1->fa=son[1];t2->fa=son[1];son[1]->son[1]=t2;son[1]->son[0]=t1;son[1]->upd();upd();}else{kth(2*p-2);son[1]->kth(2);splay *t1=new splay(*(son[1]->son[0])),*t2=new splay(x);t1->fa=t2->fa=son[1]->son[0];son[1]->son[0]->son[0]=t1;son[1]->son[0]->son[1]=t2;son[1]->son[0]->upd();son[1]->upd();upd();}x.son[0]=x.son[1]=x.fa=nullptr;x.w=0;}
      splay(){son[0]=son[1]=fa=nullptr;w=0;}
      splay(node x){son[0]=son[1]=fa=nullptr;w=1;t=x;}
      splay(vector<node>&a){if((int)a.size()==0)*this=splay();if((int)a.size()==1)*this=splay(a[0]);else{*this=splay(a,0);son[0]->fa=son[1]->fa=this;}fa=nullptr;}
      splay(const splay<node>& a){*this=a;if(son[0]!=nullptr){son[0]->fa=son[1]->fa=this;}}
};
struct node {
   int sum,lmax,rmax,ans;
   static inline node merge(node a,node b) {
      return {a.sum+b.sum,max(a.lmax,a.sum+b.lmax),max(b.rmax,b.sum+a.rmax),max({a.ans,b.ans,a.rmax+b.lmax})};
   }
};
