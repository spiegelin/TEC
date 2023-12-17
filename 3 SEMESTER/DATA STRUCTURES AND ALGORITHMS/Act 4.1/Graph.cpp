#include "Graph.hpp"


// Constructor
Graph::Graph(int V, int E) {
    numVertices = V;
    numEdges = E;
    adjLists = new std::list<int>[V];
    visited = new bool[V];
    adjMatrix = std::vector<std::vector<bool> >(numVertices, std::vector<bool>(numVertices, false)); 
}

// Destructor
Graph::~Graph() {
    delete[] adjLists; // Libera la memoria de las listas de adyacencia
    delete[] visited; // Libera la memoria de la matriz de visitados u otros recursos dinámicos
}


/* Funciones Lista */
// Add Edge (Undirected Graph)
void Graph::addEdge(int source, int destination) {
    this->adjLists[source].push_back(destination);
    this->adjLists[destination].push_back(source);
}

// Add Edge Direct (Directed Graph)
void Graph::addEdgeDirect(int source, int destination) {
    this->adjLists[source].push_back(destination);
}

// Print Graph
void Graph::printGraphL() {
    for (int i = 0; i < this->numVertices; i++) {
        std::cout << "\nVertex " << i << ":";
        for (auto x : this->adjLists[i]) {
            std::cout << " -> " << x;
        }
        std::cout << std::endl;
    }
}

// Reset Visited
void Graph::ResetVisited() {
    for (int i = 0; i < numVertices; i++) {
        visited[i] = false;
    }
}

/* Funciones Matriz */
// Print Graph
void Graph::printGraphM() {
    std::cout << " ";
    for (int i = 0; i < numVertices; i++) {
        std::cout << "  " << i;
    }

    std::cout << std::endl;
    for (int i = 0; i < numVertices; i++) {
        std::cout << i << "  ";
        for (int j = 0; j < numVertices; j++) {
            std::cout << adjMatrix[j][i] << "  "; //
        }
        std::cout << std::endl;  // Salto de línea para pasar a la siguiente fila
    }
}

/* Tarea */
// Load Graph
// (Randomly fill the Adjacency Matrix / list)
// Input: number of vertices (n), number of edges (m) 
// Adjacency Matrix / list with m connections must match.
void Graph::loadGraph(int n, int m) {
    // Vector para llevar un registro de las aristas generadas
    std::vector<std::pair<int, int> > generatedEdges; 

    // Inicializa la semilla del generador de números aleatorios con el valor actual del reloj del sistema
    //srand(static_cast<unsigned>(time(0)));

    /* Código para número aleatorio obtenido de StackOverflow */
    // Utiliza std::random_device para obtener una semilla aleatoria
    std::random_device rd;
    
    // Inicializa un generador de números aleatorios con la semilla aleatoria
    std::mt19937 gen(rd());

    // Define la distribución para los vértices
    std::uniform_int_distribution<int> dist(0, numVertices - 1);


    for (int i = 0; i < m; i++) {
        int u, v;
        do {
            u = dist(gen);//rand() % n;
            v = dist(gen);//rand() % n;
        } while (u == v || std::find(generatedEdges.begin(), generatedEdges.end(), std::make_pair(u, v)) != generatedEdges.end());

        // Lista
        adjLists[u].push_back(v);
        //adjLists[v].push_back(u); // Para grafos no dirigidos, se agrega la arista en ambas direcciones.

        // Matriz
        adjMatrix[u][v] = true;

        // Registra la arista generada en el vector
        generatedEdges.push_back(std::make_pair(u, v));

        //sort(generatedEdges.begin(), generatedEdges.end());
        //generatedEdges.erase(unique(generatedEdges.begin(), generatedEdges.end()), generatedEdges.end());
    }

    // Ordenar las listas adyacentes de menor a mayor
    // Lo hago para que en vez de que se imprima en el orden que fueron agregados se impriman en menor a mayor
    // Así se ve igual el resultado de la lista y la matriz en BFS y DFS, de otro modo el DFS y BFS de la
    // lista le da prioridad al primer valor agregado y no al más pequeño (cosa que la matriz hace)
    // Y se ve Vertex 0: -> 1 -> 2 -> 3 en lugar de Vertex 0: -> 3 -> 1 -> 2
    for (int i = 0; i < numVertices; i++) {
        adjLists[i].sort();
    }

    // Imprimir conexiones generadas
    for (const std::pair<int, int>& edge : generatedEdges) {
        std::cout << "(" << edge.first << ", " << edge.second << ") ";
    }
    std::cout << std::endl;
}



// DFS (Depth First Search) -> Graph Traversal
// Mark each vertex as visited or not visited while avoiding cycles
// 1. Start with any graph's vertices on top of a stack.
// 2. Add the top vertex of the stack to the visited list.
// 3. Add to the top of the stack the vertex's adjacent nodes that aren't in visited yet.
// 4. Keep repeating steps 2 and 3 until the stack is empty.

// Lista
void Graph::initDFSList(int vertex) {
    this->visited[vertex] = true;
    std::list<int> adjVertex = this->adjLists[vertex];

    std::cout << vertex << " ";

    for (auto i : adjVertex) {
        if (!this->visited[i]) {
            initDFSList(i);
        }
    }
}

void Graph::DFSList(int startVertex) {
    // Marca todos los vértices como no visitados al comienzo.
    for (int i = 0; i < numVertices; i++) {
        visited[i] = false;
    }

    // Llama a la función auxiliar DFSList desde el vértice de inicio.
    initDFSList(startVertex);

    // Si el grafo tiene partes desconectadas, ejecuta DFS desde otros vértices no visitados.
    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            initDFSList(i);
        }
    }
}

// Matriz
void Graph::DFSMatrix(int startVertex) {
    // Marca todos los vértices como no visitados al comienzo.
    for (int i = 0; i < numVertices; i++) {
        visited[i] = false;
    }

    // Llama a la función auxiliar DFSMatrix desde el vértice de inicio.
    initDFSMatrix(startVertex);

    // Si el grafo tiene partes desconectadas, ejecuta DFS desde otros vértices no visitados.
    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            initDFSMatrix(i);
        }
    }
}

void Graph::initDFSMatrix(int vertex) {
    visited[vertex] = true;

    std::cout << vertex << " ";

    for (int i = 0; i < numVertices; i++) {
        if (adjMatrix[vertex][i] && !visited[i]) {
            initDFSMatrix(i);
        }
    }
}


// BFS (Breadth First Search)
// Recursive algorithm for searching all the vertices of a graph or tree data structure.
// 1. Start by putting any one of the graph's vertices at the back of a queue.
// 2. Take the front item of the queue and add it to the visited list.
// 3. Create a list of that vertex's adjacent nodes. Add the ones which aren't in the visited list to 
// the back of the queue. 
// 4. Keep repeating steps 2 and 3 until the queue is empty.

// EXTRA: The graph might have two different disconnected parts so to make sure that we cover every vertex, 
// we can also run the BFS algorithm on every node.

// Lista
void Graph::BFSList(int vertex) {
    visited[vertex] = true;
    // Marca todos los vértices como no visitados al comienzo.
    for (int i = 0; i < numVertices; i++) {
        visited[i] = false;
    }

    // Recorre todos los nodos del grafo y ejecuta BFS desde los nodos no visitados.
    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            initBFSList(i);
        }
    }
}

void Graph::initBFSList(int startVertex) {
    visited[startVertex] = true;

    std::list<int> queue;
    queue.push_back(startVertex);

    while (!queue.empty()) {
        int currVertex = queue.front();
        std::cout << currVertex << " ";
        queue.pop_front();

        for (auto i : adjLists[currVertex]) {
            if (!visited[i]) {
                visited[i] = true;
                queue.push_back(i);
            }
        }
    }
}

// Matriz
void Graph::BFSMatrix(int vertex) {
    // Marca todos los vértices como no visitados al comienzo.
    for (int i = 0; i < numVertices; i++) {
        visited[i] = false;
    }

    // Recorre todos los nodos del grafo y ejecuta BFS desde los nodos no visitados.
    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            initBFSMatrix(i);
        }
    }
}

void Graph::initBFSMatrix(int startVertex) {
    visited[startVertex] = true;

    std::list<int> queue;
    queue.push_back(startVertex);

    while (!queue.empty()) {
        int currVertex = queue.front();
        std::cout << currVertex << " ";
        queue.pop_front();

        for (int i = 0; i < numVertices; i++) {
            if (adjMatrix[currVertex][i] && !visited[i]) {
                visited[i] = true;
                queue.push_back(i);
            }
        }
    }
}