
#include "disjoint_sets.cpp"
#include <iostream>
#include <string>
int main()
{
  DisjointSets<char> forest;
    //first create a bunch of singleton sets
    forest.makeSet(aa);
    forest.makeSet(bb);
    forest.makeSet(cc);
    forest.makeSet(dd);
    forest.makeSet(ee);
    forest.makeSet(ff);
    forest.makeSet(gg);
    forest.makeSet(hh);

    //now link-em together
    forest.makeUnion(gg, bb);
    assert(forest.toString() == "0:0  1:1  2:0  3:0  4:0  5:0  6:0->1:1  7:0  ");

    forest.makeUnion(aa, ee);
    assert(forest.toString() == "0:0->4:1  1:1  2:0  3:0  4:1  5:0  6:0->1:1  7:0  ");

    forest.makeUnion(gg, ee);
    assert(forest.toString() == "0:0->4:2  1:1->4:2  2:0  3:0  4:2  5:0  6:0->1:1->4:2  7:0  ");

    forest.makeUnion(hh, dd);
    assert(forest.toString() == "0:0->4:2  1:1->4:2  2:0  3:1  4:2  5:0  6:0->1:1->4:2  7:0->3:1  ");   
}
