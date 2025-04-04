# math
## Combinatorial number
| Function Name   | Feature                                          | Complexity            |
| --------------- | ------------------------------------------------ | --------------------- |
| `init(int n,ll mod)`  | Use $\text{mod}$ as the modulus, initialize first $n$ combinations | $\Theta(n)$           |
| `ll Inv(ll x)` | Find the result of $\frac{1}{x}$ modulo | $\Theta(\log \text{mod})$ |
| `ll power(ll b,ll n)` | Calculate $b^n$ modulo `mod` | $\Theta(\log n)$      |
| `ll C(ll x,ll y)` | Calculate $\text{C(x,y)}$ (where $x, y \le n$) modulo `mod` | $\Theta(1)$           |
| `ll fac[int x]` | Calculate $x!$ (where $x \le n$) modulo `mod` | $\Theta(1)$           |
| `ll inv[int x]` | Find the result of $\frac{1}{x}$ modulo | $\Theta(1)$           |

[code](https://github.com/amenotiomoi/template/blob/main/template/math_combi.cpp)

## Linear Sieve
| Function Name | Feature | Complexity |
| ------------- | ------- | ---------- |
| `init()`      | Precompute the first $10^6$ numbers(you can change `const int n=1000000;` to control it) | $\Theta(n)$           |
| `char isPrime[int x]` | Check if $x$ is a prime (Note: $1$ is considered prime) | $\Theta(1)$ |
| `int OneFac[int x]` | Get the smallest prime factor of $x$ (if $x$ is not prime) | $\Theta(1)$ |
| `int Prime[int x]` | Get the $x+1$-th prime (excluding $1$ as a prime) | $\Theta(1)$ |
| `vector<pair<int,int>> GetPrimeFac(int a)` | Decompose $a$ into prime factors and return them as pairs of $\text{prime}^\text{exponent}$ | $O(\log a)$ |
| `vector<int> GetFacList(int a)` | Get all factors of $a$ | $\Theta(d(a))$ |

[code](https://github.com/amenotiomoi/template/blob/main/template/math_factor.cpp)

## integer square root
|      function name      |             feature              |      complexity      |
| :--------------: | :---------------------------: | :--------------: |
| `ll isqrt(ll x)` | return $\lfloor\sqrt{x}\rfloor$ | $\Theta(\log \omega)$(around 6 if it's `ll`) |
```cpp
ll isqrt(ll x){ll a=1ll<<(__lg(x+1)/2+2),b=1ll<<(__lg(x+1)/2+1);while(a>b){a=b;b=(b+x/b)/2;}return a;}
```

## PR（prime fact）
|             function name              |                      feature                      |              complexity              |
| :-----------------------------: | :--------------------------------------------: | :------------------------------: |
|       `bool Prime(ll x)`        |     Check if $x$ is a prime    |          $O(\log^2 x)$           |
|    `ll NonTrivialFact(ll x)`    | return any factor of $x$ (not consider $1$ and $x$), if not, return $-1$ | expect $\Theta(\sqrt[4]{x}\log x)$ |
| `vector<ll> PrimeFacList(ll x)` |                 return prime factor list of $x$                 | expect $\Theta(\sqrt[4]{x}\log x)$ |

[code](https://github.com/amenotiomoi/template/blob/main/template/math_pr.cpp)

## convolution
|                     function name                     |                 feature                  |      complexity       |
| :--------------------------------------------: | :-----------------------------------: | :---------------: |
| `vector<int> mul(vector<int> a,vector<int> b)` | return the convolution of a and b(based on NTT, modulus=$998244353$) | $\Theta(n\log n)$ |
| `vector<int> setadd(vector<int> a,vector<int> b)` | all possible values of a[i]+b[j] are sorted, uniqued in the result | $\Theta(n\log n), n=\max{a}+\max{b}-min{a}-min{b}$ |
| `vector<int> setsub(vector<int> a,vector<int> b)` | all possible values of a[i]-b[j] are sorted, uniqued in the result | $\Theta(n\log n), n=\max{a}+\max{b}-min{a}-min{b}$ |

[code](https://github.com/amenotiomoi/template/blob/main/template/math_ntt.cpp)

# graph
## dijkstra
|                  function name                  |                         feature                          |      complexity       |
| :--------------------------------------: | :---------------------------------------------------: | :---------------: |
|              `clear(int n)`              |  rebuild a new empty edge graph, node from $1$ to $n$   |    $\Theta(n)$    |
|  `addedge_dis(int u,int v,ll w)`  |      add a edge $u→v$, weighted $w$      |    $\Theta(1)$    |
| `addedge_undis(int u,int v,ll w)` |      add a edge $u↔v$, weighted $w$        |    $\Theta(1)$    |
|            `dijkstra(int s)`             |                run dijkstra with initial point $s$                | $\Theta(n\log n)$ |
|             `ll get(int n)`              |    get the shortest path from $s$ to $t$, if there's no path, return $10^{18}$     |    $\Theta(1)$    |
|         `vector<int>path(int n)`         | get all node from a possible sortest path from $s$ to $n$ (included $s$ and $n$) |    $O(n)$    |

[code](https://github.com/amenotiomoi/template/blob/main/template/graph_dijkstra.cpp)

## SCC
|              function name              |                             feature                             |   complexity    |
| :------------------------------: | :----------------------------------------------------------: | :---------: |
|          `clear(int n)`          |      rebuild a new empty edge graph, node from $1$ to $n$      | $\Theta(n)$ |
|      `addedge(int u,int v)`      |                 add a edge $u→v$                | $\Theta(1)$ |
| `vector<vector<int>> kosaraju()` | get all SCC from graph（every `vector<int>` included a SCC's all node index） | $\Theta(n)$ |

[code](https://github.com/amenotiomoi/template/blob/main/template/graph_scc.cpp)
# data struct

In all `merge` function, it is not based on the law of exchange, For example, you can define a rule such that merge(a,b)≠merge(b,a) and the next data structure still works fine.

## cat tree（better sparse table）
|          function name           |             feature              |      complexity       |
| :-----------------------: | :---------------------------: | :---------------: |
|  `init(vector<node> x)`   |       build a sparse table based on $x$  (`a[0]` in array is index $0$)        | $\Theta(n\log n)$ |
| `node query(int l,int r)` | return the value of interval $[l,r]$ |    $\Theta(1)$    |

[code](https://github.com/amenotiomoi/template/blob/main/template/ds_cattree.cpp)

## segment tree(single point change, interval query)
|          function name           |                             feature                             |      complexity      |
| :-----------------------: | :----------------------------------------------------------: | :--------------: |
|   `init(int n)`    | rebuild a new tree, node from $1$ to $n$, empty node |   $\Theta(n)$    |
|  `segmentree[x]=y;`   |                 change the value on index $x$ to $y$                  | $\Theta(\log n)$ |
| `node query(int l,int r)` |                return the value of interval $[l,r]$                 | $\Theta(\log n)$ |

[code1(memory*3, faster)](https://github.com/amenotiomoi/template/blob/main/template/ds_seg1.cpp)

## segment tree(interval change, interval query)
|               function name                |                             feature                             |      complexity      |
| :---------------------------------: | :----------------------------------------------------------: | :--------------: |
| `init(int n,typename node::info y)` | rebuild a new tree, node from $1$ to $n$, with all $y$  |   $\Theta(n)$    |
|  `change(int l,int r,node::tag y)`  |        apply $y$ on $[l,r]$               | $\Theta(\log n)$ |
|   `node::info query(int l,int r)`   |                return the value of interval $[l,r]$                 | $\Theta(\log n)$ |

[code](https://github.com/amenotiomoi/template/blob/main/template/ds_seg2.cpp)

## sequence splay(link, cut, single point change, interval query)
|          function name           |                             feature                             |      complexity      |
| :-----------------------: | :----------------------------------------------------------: | :--------------: |
|   `splay(vector<node>&a)`    | rebuild a new tree, node from $1$ to $\|a\|$, with $a$ (`a[0]` in splay is index $1$) |   $\Theta(n)$    |
|  `change(int x,node y)`   |                 change the value on index $x$ to $y$                  | $\Theta(\log n)$ |
| `node query(int l,int r)` |                return the value of interval $[l,r]$                 | $\Theta(\log n)$ |
| `splay cut(int l,int r)` | cut the interval $[l,r]$ out and build a new splay on it(This interval will be deleted from the original splay) | $\Theta(\log n)$ | 
| `insert(splay x,int p)` | insert the splay after the index $p$(for example about insert function, if $p=0$, $x$ will be connected in begin, if $p=\|s\|$, $x$ will be connect on the end.) | $\Theta(\log n)$ |

[code](https://github.com/amenotiomoi/template/blob/main/template/ds_splay1.cpp)

## segment tree(single point change, interval query, persistence)
|          function name           |                             feature                             |      Complexity      |
| :-----------------------: | :----------------------------------------------------------: | :--------------: |
|   `Psegment1(int n,node y)`    | rebuild a new tree, node from $1$ to $n$, with all $y$ |   $\Theta(n)$    |
|   `Psegment1(vector<node> y)`    | build a tree on $y$, `y[0]` not considered |   $\Theta(n)$    |
|   `Psegment1()`  | build a empty tree |   $\Theta(1)$    |
|  `node query(int l,int r)`   |   return the value of interval $[l,r]$  | $\Theta(\log n)$ |
| `Psegment1<node> change(int x,node y)` |    change the value on index $x$ to $y$, and return the new tree, this operation NOT change the old tree(you can still use it)  | $\Theta(\log n)$ |

**this template will NOT release memory and it need $\Theta(\log n)$ more memory than the seg tree of the up two. You'd better make sure you know what you're doing before you use this.**

[code](https://github.com/amenotiomoi/template/blob/main/template/ds_pseg1.cpp)

## Lowest Common Ancestor
|              function name              |                             feature                             |      Complexity      |
| :------------------------------: | :----------------------------------------------------------: | :--------------: |
|         `TreeLCA(int n)`         |                         rebuild a new tree, node from $1$ to $n$                         |   $\Theta(n)$    |
|      `addedge(int u,int v)`      |                   add a edge $u↔v$                   |   $\Theta(1)$    |
|         `init(int Root)`         |   initialize with $\text{Root}$  |   $\Theta(n)$    |
|      `int lca(int u,int v)`      |                return the lowest common ancestor of $u$ and $v$                | $\Theta(\log n)$ |
|      `int dis(int u,int v)`      |              return the edge number on path $u↔v$              | $\Theta(\log n)$ |
|      `int nxt(int u,int v)`      |    return the shortest node to $u$ on the path $u↔v$ (except $u$)     | $\Theta(\log n)$ |
|   `path inter(path a,path b)`    |          Find the intersection of two paths (if no, return `{-1,-1}`)          | $\Theta(\log n)$ |
|          `path diam()`           |                          find the longest path on tree                          |   $\Theta(n)$    |
| `pair<int,int> gravity_center()` |        find the gravity center of tree(if don't have two, the pair.second is `0`)          |   $\Theta(n)$    |

This data structure requires strict ordering of operations, you need to define it first, then add the correct number $(n-1)$ of edges, followed by init, and finally destruct it, otherwise it will result in RE, WA or a memory leak. The sample code is given in the comments.

The path is based on point but not edge. 

[code](https://github.com/amenotiomoi/template/blob/main/template/ds_lca.cpp)

## hld
|          function name           |                 feature                 |      Complexity       |
| :-----------------------: | :----------------------------------: | :---------------: |
|   `hld<node,segment1> Q(int cnt)`    |  build a node hld Q based on `segmentt1`, with cnt size, all empty node  |    $\Theta(n)$    |
|   `addedge(int u,int v)`    |  add a edge $u↔v$  |    $\Theta(1)$    |
| `Q[x]=y`  | set the $x$ node of value $y$ |    $\Theta(\log n)$    |
|       `init(int x)`       |       calculate the hld based on root $x$        | $O(n\log n)$ |
| `node query(int l,int r)` |   query the value of path $u→v$  | $O(\log^2 n)$ （Mostly it's fast looks like a $O(\log n)$） |

This data structure requires strict ordering of operations, you need to define it first, then add the correct number $(n-1)$ of edges, followed by init, and finally destruct it, otherwise it will result in RE, WA or a memory leak. The sample code is given in the comments.

[code](https://github.com/amenotiomoi/template/blob/main/template/ds_hld.cpp)

## tree hash
|             function name             |                 feature                  |   Complexity    |
| :----------------------------: | :-----------------------------------: | :---------: |
| `typedef pair<ull,ull> hvalue` |          hash value, you can compare it          |      /      |
|         `htree(int n)`         |         rebuild a new tree, node from $1$ to $n$         | $\Theta(n)$ |
|  `void addedge(int u,int v)`   |      add a edge $u↔v$       | $\Theta(n)$ |
|     `void init(int root)`      |       calculate hash value of root $\text{root}$        | $\Theta(n)$ |
|        `hvalue hash[i]`        | find the hash value of the subtree with $i$ root | $\Theta(1)$ |
|        `hvalue merge(vector<hvalue> a)`        | find the new tree hash value if all tree in $a$ merged on a new node | $\Theta(1)$ |
|      `int tree[0].second`      |               size of tree                | $\Theta(1)$ |

[code](https://github.com/amenotiomoi/template/blob/main/template/ds_treehash.cpp)

# string

## string hash
|                 function name                 |                             feature                             |   Complexity    |
| :------------------------------------: | :----------------------------------------------------------: | :---------: |
|     `typedef pair<int,ll> hvalue`      |           hash value, you can compare it             |      /      |
|          `hstring(string x)`           | calculate the hash of $x$ (you can replace `string` to `vector<int>` without anything bad, but need every number smaller than $10^9$  | $\Theta(n)$ |
|     `hvalue interval(int l,int r)`     |        return the value of $[l,r]$(based on $0$)        | $\Theta(1)$ |
| `hvalue operator +(hvalue a,hvalue b)` |                      return $a+b$                       | $\Theta(1)$ |
| `bool operator ==(hvalue a,hvalue b)`  |                  return $a==b$                  | $\Theta(1)$ |

[code](https://github.com/amenotiomoi/template/blob/main/template/string_hash.cpp)

# algorithms

## 2D point count

|                 function name                 |                             feature                             |   Complexity    |
| :------------------------------------: | :----------------------------------------------------------: | :---------: |
|     `vector<int> pointcount_offline(vector<pair<int,int>>point,vector<array<int,4>>query)`      |        For each query, return how many points satisfy `a[0]<=x<=a[1]&&a[2]<=y<=a[3]`                |    $\Theta(n\log n)$   |
|     `pointcount_online::init(vector<pair<int,int>> point)`      |        Initialize a point set                |    $\Theta(n\log n)$   |
|     `pointcount_online::query(int x1,int x2,int y1,int y2)`      |        count number of point which `x1<=x<=x2 && y1<=y<=y2`                |    $\Theta(\log n)$   |
|     `pointcount_online::query(int x,int y)`      |        count number of point which `point.x<=x&&point.y<=y`                |    $\Theta(\log n)$ (Smaller constants, recommended)  |

[code](https://github.com/amenotiomoi/template/blob/main/template/algo_2dpoint.cpp)


