//disjoint_sets.h
#include <iostream>
#include <string>

/*template <class T>
class Edge
{
  public:
    int endx, endz, weight;
};
*/
    
template <class T>
class DSNode
{
public:
    T* data;
    int rank;                   
    DSNode<T> *parent;
    DSNode(T* e) : data(e), rank(0), parent(nullptr) 
    {}                                      
};

template <class T> 
class DisjointSets
{
    DSNode<T>* *elements;

    //max possible num of elements array & num of elements currently in the forest, respectively
    int capacity, length; 
    public:
        DisjointSets(int max_capacity = 10);    //default
        ~DisjointSets();

        void makeSet(T* x); //make a new singleton set containing data x
        void makeUnion(T* x, T* y); //union the disjoint sets containing data x and y
        T* findSet(T* x); //return the representative of the set containing x

        std::string display();      
    private:
        //finds and returns a node containing element x; null if not found.
        DSNode<T>* find(T* x); 

        //returns the repr element by recursively taking the parent of x
        DSNode<T>* findSet(DSNode<T> *x);   
        void link(DSNode<T> *x, DSNode<T> *y); //union two sets repr. by data x and y     
};

#include "disjoint_sets.cpp"
