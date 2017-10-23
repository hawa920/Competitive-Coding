/*
 *
 * This example is an 'single source shortest path in an undirected graph' implementation with Dijkstra's Algorithm.
 * If yours is a directed graph, simply change the code that builds the adjacency list will work.
 *
 * Description: Given a starting point and find out the shortest path from starting point to all the other points in the graph.
 *
 *  Solution:
 *
 *    1. Build up the adjacency list, rather than adjacency matrix in order to save memory.
 *
 *    2. Build up the minimum heap, initialize it with distant(0) and point(starting point).
 *
 *    3. Each round, we select the pair with shortest distantance in the heap, and traverse the adjacency list
 *       to check if there exist shorter path.
 *
 *    4. Keep running step 3 until the minimum heap is empty, then we can find all shortest path
 *       to a single source starting point.
 *
 *    Time Complexity: O( E+VlgV )
 *      -> Using long long pair vector for adjacency list.
 *      -> Using Priority_queue for minimum heap.
 *
 *    Dijkstra's Algorithm doesn't work for negative edge. I will ends up in an infinity loop.
 *
 * */



#include <bits/stdc++.h>
#define SPT 1 /* starting point of the graph */
#define MVS 100009 /* max vertices size */
#define xx  first /* std::pair::first */
#define yy  second /* std::pair::second */
#define pb  push_back /* std::vector::push_back()*/
#define mp  make_pair /* std::pair::make_pair() */


using namespace std;
typedef long long ll;  /* using ll = long long; */
typedef pair<ll,ll> llp; /* using llp = pair<ll,ll>; */
typedef vector<llp> llpv; /* using llpv = vector<llp>; */
typedef priority_queue<llp,llpv,greater<llp> > llppq; /* using llppq = priority_queue<llp,llpv,greater<llp>>; */

int parent[MVS];
ll u, v, w, nv, ne, dist[MVS], inf(4294967296);
llp nextv;
llpv adjlist[MVS];
llppq minHeap;

void dijkstra(int spt)  {

  /* sync off */
  ios_base::sync_with_stdio(false);
  cin >> nv >> ne;
  /* init */
  for(int i = 0; i <= nv; i++) {
    dist[i] = inf;
    parent[i] = -1;
  }
  dist[spt] = 0;
  /* init adj list */
  for(int i = 0; i < ne; i++) {
    cin >> u >> v >> w;
    adjlist[u].pb(mp(v, w));
    adjlist[v].pb(mp(u, w));
  }
  /* init min heap */
  minHeap.push(mp(0, spt));
  /* Implementation */
  while(not minHeap.empty())  {

    nextv = minHeap.top();
    minHeap.pop();
    /* traverse connecting pts */
    for(llpv::iterator i = adjlist[nextv.yy].begin(); i != adjlist[nextv.yy].end(); i++)  {
      /* if find smaller cost */
      if(dist[(*i).xx] > nextv.xx + (*i).yy)  {
        dist[(*i).xx] = nextv.xx + (*i).yy;
        minHeap.push(mp(dist[(*i).xx], (*i).xx));
        parent[(*i).xx] = nextv.yy;
      }
    }
  }
}
