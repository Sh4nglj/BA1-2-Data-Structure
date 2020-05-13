#include <iostream>
#include <cstdio>

#include "Graph.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    Graph g(5);

    g.addedge(1, 2, 10);
    g.addedge(1, 3, 10);
    g.addedge(1, 4, 10);
    g.addedge(1, 5, 10);
    g.addedge(2, 3, 1);

    if(g.prim() == 31) cout << "pass check point 1!" << endl;
    if(g.kruskal() == 31) cout << "pass check point 2!" << endl;

    Graph t(7);
    t.addedge(1, 2, 28);
    t.addedge(1, 6, 10);
    t.addedge(2, 3, 16);
    t.addedge(2, 7, 14);
    t.addedge(3, 4, 12);
    t.addedge(4, 5, 22);
    t.addedge(4, 7, 18);
    t.addedge(5, 6, 25);
    t.addedge(5, 7, 24);
    cout << t.prim() << endl;

    Graph h(7);
    h.addedge(1, 2, 7);
    h.addedge(1, 4, 5);
    h.addedge(2, 3, 8);
    h.addedge(2, 5, 7);
    h.addedge(2, 4, 9);
    h.addedge(3, 5, 5);
    h.addedge(4, 5, 15);
    h.addedge(4, 6, 6);
    h.addedge(5, 6, 8);
    h.addedge(5, 7, 9);
    h.addedge(6, 7, 11);
    cout << h.prim() << endl;
    return 0;
}