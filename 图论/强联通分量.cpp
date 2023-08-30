namespace SCC {
   vector<vector<int>> graph,ugraph;
   void clear(int n){graph.clear();graph.resize(n+1);ugraph.clear();ugraph.resize(n+1);};
   void addedge(int u,int v){graph[u].push_back(v);ugraph[v].push_back(u);}
   vector<vector<int>> kosaraju(){vector<vector<int>>answer;vector<bool>vis(graph.size(),false);vector<int>vst;function<void(int)>dfs1=[&](int x){if(vis[x])return;vis[x]=true;for(int i:graph[x])dfs1(i);vst.push_back(x);};for(int i=1;i<(int)graph.size();++i)dfs1(i);reverse(vst.begin(),vst.end());function<void(int)>dfs2=[&](int x){if(!vis[x])return;vis[x]=false;answer.end()[-1].push_back(x);for(int i:ugraph[x])dfs2(i);};for(int i:vst)if(vis[i]){answer.push_back({});dfs2(i);}return answer;}
}
