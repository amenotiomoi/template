# math
## Combinatorial number
| Function Name   | Feature                                          | Complexity            |
| --------------- | ------------------------------------------------ | --------------------- |
| `init(int n,ll mod)`  | Use $\text{mod}$ as the modulus, initialize first $n$ combinations | $\Theta(n)$           |
| `ll Inv(int x)` | Find the result of $\frac{1}{x}$ modulo | $\Theta(\log \text{mod})$ |
| `ll power(ll b,ll n)` | Calculate $b^n$ modulo `mod` | $\Theta(\log n)$      |
| `ll C(ll x,ll y)` | Calculate $\text{C(x,y)}$ (where $x, y \le n$) modulo `mod` | $\Theta(1)$           |
| `ll fac[int x]` | Calculate $x!$ (where $x \le n$) modulo `mod` | $\Theta(1)$           |
| `ll inv[int x]` | Find the result of $\frac{1}{x}$ modulo | $\Theta(1)$           |

[code](https://github.com/amenotiomoi/template/blob/main/%E6%95%B0%E5%AD%A6/%E7%BB%84%E5%90%88%E6%95%B0.cpp)

## Linear Sieve
| Function Name | Feature | Complexity |
| ------------- | ------- | ---------- |
| `init()`      | Precompute the first $10^6$ numbers(you can change `const int n=1000000;` to control it) | $\Theta(n)$           |
| `char isPrime[int x]` | Check if $x$ is a prime (Note: $1$ is considered prime) | $\Theta(1)$ |
| `int OneFac[int x]` | Get the smallest prime factor of $x$ (if $x$ is not prime) | $\Theta(1)$ |
| `int Prime[int x]` | Get the $x+1$-th prime (excluding $1$ as a prime) | $\Theta(1)$ |
| `vector<pair<int,int>> GetPrimeFac(int a)` | Decompose $a$ into prime factors and return them as pairs of $\text{prime}^\text{exponent}$ | $O(\log a)$ |
| `vector<int> GetFacList(int a)` | Get all factors of $a$ | $\Theta(d(a))$ |

[code](https://github.com/amenotiomoi/template/blob/main/%E6%95%B0%E5%AD%A6/%E7%BA%BF%E6%80%A7%E7%AD%9B.cpp)

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

[code](https://github.com/amenotiomoi/template/blob/main/%E6%95%B0%E5%AD%A6/%E6%95%B4%E6%95%B0%E5%88%86%E8%A7%A3.cpp)

## convolution
|                     function name                     |                 feature                  |      complexity       |
| :--------------------------------------------: | :-----------------------------------: | :---------------: |
| `vector<int> mul(vector<int> a,vector<int> b)` | return the convolution of a and b(based on NTT, modulus=$998244353$) | $\Theta(n\log n)$ |

[code](https://github.com/amenotiomoi/template/blob/main/%E6%95%B0%E5%AD%A6/%E5%A4%9A%E9%A1%B9%E5%BC%8F%E4%B9%98%E6%B3%95.cpp)

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

[code](https://github.com/amenotiomoi/template/blob/main/%E5%9B%BE%E8%AE%BA/%E6%97%A0%E8%B4%9F%E6%9D%83%E6%9C%80%E7%9F%AD%E8%B7%AF%EF%BC%88dijkstra%EF%BC%89.cpp)

## SCC
|              function name              |                             feature                             |   complexity    |
| :------------------------------: | :----------------------------------------------------------: | :---------: |
|          `clear(int n)`          |      rebuild a new empty edge graph, node from $1$ to $n$      | $\Theta(n)$ |
|      `addedge(int u,int v)`      |                 add a edge $u→v$                | $\Theta(1)$ |
| `vector<vector<int>> kosaraju()` | get all SCC from graph（every `vector<int>` included a SCC's all node index） | $\Theta(n)$ |

[code](https://github.com/amenotiomoi/template/blob/main/%E5%9B%BE%E8%AE%BA/%E5%BC%BA%E8%81%94%E9%80%9A%E5%88%86%E9%87%8F.cpp)
# data struct
## cat tree（better sparse table）
|          function name           |             feature              |      complexity       |
| :-----------------------: | :---------------------------: | :---------------: |
|  `init(vector<node> x)`   |       build a sparse table based on $x$        | $\Theta(n\log n)$ |
| `node query(int l,int r)` | return the value of interval $[l,r]$ |    $\Theta(1)$    |

this template is not based on the commutative law of merge function(in another word, you can use this to solve [GSS1](https://vjudge.net/problem/SPOJ-GSS1)).

[code](https://github.com/amenotiomoi/template/blob/main/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%8C%AB%E6%A0%91%EF%BC%88%E9%9D%99%E6%80%81%E5%88%86%E6%B2%BB%EF%BC%89.cpp)

## segment tree(single point change, interval query)
|          function name           |                             feature                             |      complexity      |
| :-----------------------: | :----------------------------------------------------------: | :--------------: |
|   `init(int n,node y)`    | rebuild a new tree, node from $1$ to $n$, with all $y$ |   $\Theta(n)$    |
|  `change(int x,node y)`   |                 change the value on index $x$ to $y$                  | $\Theta(\log n)$ |
| `node query(int l,int r)` |                return the value of interval $[l,r]$                 | $\Theta(\log n)$ |

this template is not based on the commutative law of merge function(in another word, you can use this to solve [GSS1](https://vjudge.net/problem/SPOJ-GSS1)).

[zkw(faster, but need 0.5x more memory than compress seg)](https://github.com/amenotiomoi/template/blob/main/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%BA%BF%E6%AE%B5%E6%A0%91_zkw.cpp)

[compress seg(slower, use less memory)](https://github.com/amenotiomoi/template/blob/main/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E7%BA%BF%E6%AE%B5%E6%A0%91_smaller_memory.cpp)
## segment tree(interval change, interval query)
|               function name                |                             feature                             |      complexity      |
| :---------------------------------: | :----------------------------------------------------------: | :--------------: |
| `init(int n,typename node::info y)` | rebuild a new tree, node from $1$ to $n$, with all $y$  |   $\Theta(n)$    |
|  `change(int l,int r,node::tag y)`  |        apply $y$ on $[l,r]$               | $\Theta(\log n)$ |
|   `node::info query(int l,int r)`   |                return the value of interval $[l,r]$                 | $\Theta(\log n)$ |

this template is not based on the commutative law of merge function(in another word, you can use this to solve [GSS1](https://vjudge.net/problem/SPOJ-GSS1)).

[code](https://github.com/amenotiomoi/template/blob/main/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E6%87%92%E6%A0%87%E8%AE%B0%E7%9A%84%E7%BA%BF%E6%AE%B5%E6%A0%91.cpp)

## segment tree(single point change, interval query, persistence)
|          function name           |                             feature                             |      Complexity      |
| :-----------------------: | :----------------------------------------------------------: | :--------------: |
|   `Psegment1(int n,node y)`    | rebuild a new tree, node from $1$ to $n$, with all $y$ |   $\Theta(n)$    |
|   `Psegment1(vector<node> y)`    | build a tree on $y$, `y[0]` not considered |   $\Theta(n)$    |
|   `Psegment1()`  | build a empty tree |   $\Theta(1)$    |
|  `node query(int l,int r)`   |   return the value of interval $[l,r]$  | $\Theta(\log n)$ |
| `Psegment1<node> change(int x,node y)` |    change the value on index $x$ to $y$, and return the new tree, this operation NOT change the old tree(you can still use it)  | $\Theta(\log n)$ |

this template is not based on the commutative law of merge function(in another word, you can use this to solve [GSS1](https://vjudge.net/problem/SPOJ-GSS1)).

**this template will NOT release memory and it need $\Theta(\log n)$ more memory than the seg tree of the up two. You'd better make sure you know what you're doing before you use this.**

[code](https://github.com/amenotiomoi/template/blob/main/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E5%8F%AF%E6%8C%81%E4%B9%85%E5%8C%96%E7%BA%BF%E6%AE%B5%E6%A0%91.cpp)

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

[point implementation(faster)](https://github.com/amenotiomoi/template/blob/main/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E6%A0%91%E4%B8%8A%E6%9C%80%E8%BF%91%E5%85%AC%E5%85%B1%E7%A5%96%E5%85%88_pointer.cpp)

[vector implementation(slower)](https://github.com/amenotiomoi/template/blob/main/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E6%A0%91%E4%B8%8A%E6%9C%80%E8%BF%91%E5%85%AC%E5%85%B1%E7%A5%96%E5%85%88_vector.cpp)

## static hld
|          function name           |                 feature                 |      Complexity       |
| :-----------------------: | :----------------------------------: | :---------------: |
|   `hld<node,cat_tree>`    |  build a node hld based on `cat_tree`  |    $\Theta(n)$    |
| `setvalue(int x,node y)`  | set the $x$ node of value $y$ |    $\Theta(1)$    |
|       `init(int x)`       |       calculate the hld based on root $x$        | $O(n\log n)$ |
| `node query(int l,int r)` |   query the value of path $u→v$  | $O(\log n)$ （In fact, it has a linear relationship with the number of heavy chains passed on the path from $l$ to $r$, and can be analyzed as $\Theta(1)$ under some special problems） |
| `lca_top[x]` | query the highest node index of the chain $x$ in it | $\Theta(1)$ |

this template is not based on the commutative law of merge function(in another word, you can use this to solve [GSS1](https://vjudge.net/problem/SPOJ-GSS1)).

[code](https://github.com/amenotiomoi/template/blob/main/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E9%9D%99%E6%80%81%E6%A0%91%E5%89%96.cpp)

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

[code](https://github.com/amenotiomoi/template/blob/main/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/%E6%A0%91%E5%93%88%E5%B8%8C.cpp)

# string

## string hash
|                 function name                 |                             feature                             |   Complexity    |
| :------------------------------------: | :----------------------------------------------------------: | :---------: |
|     `typedef pair<int,ll> hvalue`      |           hash value, you can compare it             |      /      |
|          `hstring(string x)`           | calculate the hash of $x$ (you can replace `string` to `vector<int>` without anything bad, but need every number smaller than $10^9$  | $\Theta(n)$ |
|     `hvalue interval(int l,int r)`     |        return the value of $[l,r]$        | $\Theta(1)$ |
| `hvalue operator +(hvalue a,hvalue b)` |                      return $a+b$                       | $\Theta(1)$ |
| `bool operator ==(hvalue a,hvalue b)`  |                  return $a==b$                  | $\Theta(1)$ |

[code](https://github.com/amenotiomoi/template/blob/main/%E5%AD%97%E7%AC%A6%E4%B8%B2/%E5%93%88%E5%B8%8C.cpp)

待办：
1. 懒标记的 zkw 线段树
2. 树剖套线段树
3. 网络流
4. 线段树二分
