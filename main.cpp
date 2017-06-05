#include <chrono>
#include <iostream>
#include "dijkstra.h"

using namespace std;

int main( int argc, char *argv[] )
{
    int from = atoi( argv[ 1 ] );
    int to = atoi( argv[ 2 ] );

    string line = "";          

    while ( line.substr( 0, 4 ) != "p sp" )
    {
        getline( cin, line );
    }
 
    stringstream pref( line );
    unsigned n, m;
    string ac;
    pref >> ac >> ac >> n >> m;

    Graph g( n + 1 );

    unsigned i = 0;
    while ( i < m )
    {
        getline( cin, line );

        if ( line.substr( 0, 2 ) == "a " )
        {
            stringstream arc( line );
            unsigned u, v, w;
            arc >> ac >> u >> v >> w;
            g.addEdge( u, v, w );
            i++;
        }
    }

    HollowHeap heap;
    links.resize( 1000 );

    g.shortestPath( from, to, heap );

    return 0;
}