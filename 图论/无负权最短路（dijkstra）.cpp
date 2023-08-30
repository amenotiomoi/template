namespace dijkstra {
   vector<vector<pair<int,long long>>> graph;
   vector<long long> dis;int startnode;
   void clear(int n){graph.clear();graph.resize(n+1);dis.resize(n+1);}
   void addedge_dis(int u,int v,long long w){graph[u].push_back({v,w});}
   void addedge_undis(int u,int v,long long w){addedge_dis(u,v,w);addedge_dis(v,u,w);}
   void dijkstra(int s){startnode=s;for(int i=0;i<(int)graph.size();++i)dis[i]=1e18;priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>Q;Q.push({0,s});dis[s]=0;while(!Q.empty()){pair<long long,int>T=Q.top();Q.pop();if(T.first!=dis[T.second])continue;for(auto i:graph[T.second]){if(dis[i.first]>dis[T.second]+i.second){dis[i.first]=dis[T.second]+i.second;Q.push({dis[T.second]+i.second,i.first});}}}}
   long long get(int n){return dis[n];}
   void path_dfs(int n,int endnode,vector<int>& ans,vector<char>& vis){if(vis[n]||n==endnode) return;vis[n]=true;for(auto i:graph[n])if(dis[i.first]==dis[n]+i.second){ans.push_back(i.first);path_dfs(i.first,endnode,ans,vis);if(ans.end()[-1]!=endnode)ans.pop_back();else return;}}
   vector<int>path(int n){vector<int> ans{startnode};vector<char>vis(graph.size());path_dfs(startnode,n,ans,vis);return ans;}
}
