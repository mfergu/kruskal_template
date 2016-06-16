//max possible num of elements array & num of elements currently in the forest, respectively

template<class T>
DisjointSets<T>::DisjointSets()
{
  std::cout << "\nConstructor"<< endl;
}

template<class T>
DisjointSets<T>::DisjointSets(int max_capacity)    //default
{
  length = 0;
  capacity = max_capacity;
  if(capacity < 1)
    capacity = 10;
  elements = new DSNode<T>*[capacity];
  
  
}

template<class T>
DisjointSets<T>::~DisjointSets()
{
  std::cout << "\ndestructor" << std::endl;
}

template<class T>
void DisjointSets<T>::makeSet(T* x)             //make a new singleton set containing data x
{
  if(length == capacity)
  {
    std::cout << "\n makeSet exceeding array capacity!"<<std::endl;
  }
  elements[length] = new DSNode<T>(x);
  elements[length]->parent = elements[length];
  elements[length]->rank = 0; 
  length++;
}

template<class T>
void DisjointSets<T>::makeUnion(T* x, T* y)     //union the disjoint sets containing data x and y
{
  DSNode<T>* n1 =  findSet(x); //find node containing x
  DSNode<T>* n2 =  findSet(y); //find node containing y
  link(n1, n2);
}


template<class T>
std::string DisjointSets<T>::display()      
{
  return;
}

template <class T>
        //finds and returns a node containing element x; null if not found.
DSNode<T>* DisjointSets<T>::find(T* x) 
{
  int index = 0;
  while((elements[index] != x) && (index < length))
    index++;
  if(elements[index] == x)
    return elements[index];
  else
    return nullptr;
}

        //returns the representative element by recursively taking the parent of x
template <class T>
DSNode<T>* DisjointSets<T>::findSet(DSNode<T> *x)
{
  if(x->parent != nullptr)
    findSet(x->parent);
  else
    return x;
}   

template <class T>
void DisjointSets<T>::link(DSNode<T> *x, DSNode<T> *y)
{
  if(x->rank > y->rank)
    y->parent = x;
  else if ( x->rank == y->rank)
    y++;
  x->parent = y;
}
