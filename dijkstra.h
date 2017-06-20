#ifndef DIJKSTRA
#define DIJKSTRA

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <cmath>
#include "hollowheap.h"

using namespace std;
# define INF 0x3f3f3f3f

typedef pair<int, int> iPair;
 
class Graph
{
    int V;
 
    list< pair<int, int> > *adj;
 
public:
    Graph( int V );
 
    void addEdge( int u, int v, int w );
 
    void shortestPath( int from, int to, HollowHeap heap );
};
 
Graph::Graph( int V )
{
    this->V = V;
    adj = new list<iPair> [ V ];
}
 
void Graph::addEdge( int u, int v, int w )
{
    adj[ u ].push_back( make_pair( v, w ) );
}
 
void Graph::shortestPath( int from, int to, HollowHeap heap )
{
    vector<int> dist( V, INF );
 
    heap.insert( 0, from );
    dist[ from ] = 0;
    int u, v = -1, weight = -1, stop = 0, get = 0;
 
    while ( !heap.isEmpty() && stop == 0 )
    {
        u = heap.deleteMin();        

        list< pair<int, int> >::iterator i;
        for ( i = adj[ u ].begin(); i != adj[ u ].end(); ++i )
        {
            v = ( *i ).first;
            weight = ( *i ).second;

            if ( dist[ v ] == INF )
            {
                dist[ v ] = dist[ u ] + weight;
                heap.insert( dist[ v ], v ); 
            }

            else
            {
                if ( ( dist[ u ] + weight ) < dist[ v ] )
                {
                    dist[ v ] = dist[ u ] + weight;
                }

                heap.decreaseKey( v, dist[ v ] );
            }
        }

        if ( u == to )
        {
            get = 1;
        }

        if ( to > 0 && get == 1 )
        {
            stop = 1;
            break;
        }
    }

    if ( get == 0 )
    {
        cout << "inf" << endl;
    }
    else
    {
        cout << dist[ u ] << endl;
    }
}

#endif
