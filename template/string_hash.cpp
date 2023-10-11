class hstring {
   private:
      vector<int> pre[2];
   public:
      static const int mod[2],inv[2],base=1869442921;
      static vector<int> pow[2][2];
      typedef pair<int,long long> hvalue;
      hstring(string x){while(pow[0][0].size()<x.size())for(int i=0;i<2;++i)for(int j=0;j<2;++j)pow[i][j].push_back((long long)pow[i][j].end()[-1]*(j==0?base:inv[i])%mod[i]);pre[0]=pre[1]={x[0]};for(int i=1;i<(int)x.size();++i)for(int j=0;j<2;++j)pre[j].push_back(((long long)x[i]*pow[j][0][i]+pre[j].end()[-1])%mod[j]);}
      hvalue interval(int l,int r){if(l==0)return{r+1,((long long)pre[0][r]<<32ll)+pre[1][r]};return {r-l+1,((((long long)pre[0][r]-pre[0][l-1]+mod[0])*pow[0][1][l]%mod[0])<<32ll)+((long long)pre[1][r]-pre[1][l-1]+mod[1])*pow[1][1][l]%mod[1]};}
};
hstring::hvalue operator +(hstring::hvalue a,hstring::hvalue b){return{a.first+b.first,((((b.second>>32ll)*hstring::pow[0][0][a.first]+(a.second>>32ll))%hstring::mod[0])<<32ll)+((b.second&4294967295ll)*hstring::pow[1][0][a.first]+(a.second&4294967295))%hstring::mod[1]};}
vector<int> hstring::pow[2][2]={{{1},{1}},{{1},{1}}};
const int hstring::mod[2]={2134567921,2134567907},hstring::inv[2]={719416665,117520479};