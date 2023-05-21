?#include "tasks_rk2.h"

void task_1(void) {
#ifdef MEMORY_LEAK
    while (true) {                                    //memory leak test
        Graph* Gr = new Graph(5);
        delete Gr;
    }
#endif
    {                                                   //build from constructor, output, search test
        Graph* Gr = new Graph(5);                       //console output: 33 8 1 0; file output is tree from nameNode = 5
        Gr->BFS();
        std::pair<bool, std::list<int>> way;
        way = Gr->searchBFS(100);
        if (way.first == false) {
            std::cout << "Element not found" << std::endl;
        }
        std::list<int>::iterator ite = way.second.begin();
        while (ite != way.second.end()) {
            std::cout << *ite << std::endl;
            ite++;
        }
        std::cout << std::endl;
        delete Gr;
    }

    {                                                    //build without constructor from nameNode = 1, output, wrong search
        Graph* Gr = new Graph;                           //console output: NO; file output is tree from nameNode = 1
        Gr->buildTreeBFS(1);
        Gr->BFS();
        std::pair<bool, std::list<int>> way = Gr->searchBFS(5);
        if (way.first == false) {
            std::cout << "NO" << std::endl;
        }
        std::list<int>::iterator ite = way.second.begin();
        while (ite != way.second.end()) {
            std::cout << *ite << std::endl;
            ite++;
        }
        std::cout << std::endl;
        delete Gr;
    }

    {                                                   //build from wrong input, graph wasn't build, output wont't work
        Graph* Gr = new Graph;
        Gr->buildTreeBFS(-10);
        Gr->BFS();
        delete Gr;
    }

}

void task_2(void) {
    {                                                    //build without constructor from nameNode = 3
        Graph* Gr = new Graph;                           //console output: 2, 1, 0; file output is tree from nameNode = 3
        Gr->buildTreeDFS(3);
        Gr->DFS();
        std::pair<bool, std::list<int>> way = Gr->searchDFS(3);
        if (way.first == false) {
            std::cout << "NO" << std::endl;
        }
        std::list<int>::iterator ite = way.second.begin();
        while (ite != way.second.end()) {
            std::cout << *ite << std::endl;
            ite++;
        }
        std::cout << std::endl;
        delete Gr;
    }
}

int main()
{
    task_1();
    task_2();
    return 0;
}
