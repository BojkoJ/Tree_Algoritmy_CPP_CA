#include <iostream>
#include <list>

using namespace std;

class Graph {
    int V;
    //pole listů
    //list<int> l[V] - V ale ještě neznáme, takže použijeme pointer
    list<int> *l; //(aka) = new List[V]
public:
    Graph(int V) { //konstruktor, V - počet vrcholů
        this->V = V;
        l = new list<int>[V];
        //l je pointer na pole
        //každý element v tomhle poli je list
        //l[0] je list
    }

    void addEdge(int x, int y) //přidat hranu mezi nodama
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void printAdjList()
    {
        //iterovat skrze všechny vrcholy
        for (int i = 0; i < V; i++)
        {
            cout << "Vrchol " << i << " ->";
            for (int nbr:l[i])
            {
                cout << nbr << ",";
            }
            cout << endl;
        }
    }
};


int main()
{
    Graph g(4);
    g.addEdge(0, 1); //hrana mezi nodem 0 a nodem 1
    g.addEdge(0, 2); //hrana mezi nodem 0 a nodem 2
    g.addEdge(2, 3); //hrana mezi nodem 2 a nodem 3
    g.addEdge(1, 2); //hrana mezi nodem 1 a nodem 2

    //graf vypadá cca takto:
    /*

    |0|-----|1|
      \     /
       \   /
        |2|
         |
         |
        |3|

    */

    g.printAdjList();

}