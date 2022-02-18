#include <iostream>
using namespace std;

// Zeroing all values in matrix
void mxZero (int** matrix, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = 0;
}

// Function for graph input
void mxInput (int **matrix, int n)
{
    cout << "Input both nodes and edge for every "
         << "connection, then 0 to finish" << endl;
    int i, j, edge;
    while (true)
    {
        cin >> i; if (i == 0) break;
        cin >> j; cin >> edge;
        if (i > 0 && i <= n && j > 0 && j <= n && edge > 0)
        {
            i--; j--;
            matrix[i][j] = edge;
            matrix[j][i] = edge;
        }
    }
}

// Prints all connections in graph
void mxPrintCon (int **matrix, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (matrix[i][j] != 0)
                cout << "Nodes " << i + 1 << " and " << j + 1
                     << ", edge length " << matrix[i][j] << endl;
}

// Prints the entire matrix as is
void mxPrintRaw (int **matrix, int n)
{
    cout << " *";
    for (int i = 1; i <= n; i++)
        cout << "\t(" << i << ")";
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "(" << i + 1 << ")";
        for (int j = 0; j < n; j++)
            cout << "\t" << matrix[i][j];
        cout << endl;
    }
}

int PrimsAlgo (int **matrix, int **tree, int n)
{
    // to track nodes in tree and end cycle
    bool done = false;
    bool picked[n];
    picked[0] = true;
    for (int i = 1; i < n; i++)
        picked[i] = false;

    int temp, weight = 0;
    int min_i, min_j, min_edge;

    // the main algorithm cycle
    while (!done)
    {
        // searching for the shortest connected edge
        min_edge = 99999999;
        for (int i = 0; i < n; i++)  // loop for picked nodes
            if (picked[i]) {
        for (int j = 0; j < n; j++)  // loop for unpicked nodes
            if (i != j && !picked[j])
            {
                temp = matrix[i][j]; // shortest edge check
                if (temp != 0 && temp < min_edge) {
                    min_edge = temp;
                    min_i = i;
                    min_j = j;
        }   }   }

        // putting result in tree
        picked[min_j] = true;
        tree[min_i][min_j] = min_edge;
        tree[min_j][min_i] = min_edge;
        weight += min_edge;

        // check if all nodes have been picked
        done = true;
        for (int i = 0; i < n; i++)
            if (!picked[i])
                done = false;
    }
    return weight;
}

int main()
{
    // enter size
    int n;
    do {
        cout << "Enter number of nodes: ";
        cin >> n; }
    while (n < 2);

    // initialize graph
    int** graph;
    graph = new int*[n];
    for (int i = 0; i < n; i++)
        graph[i] = new int[n];
    mxZero(graph, n);
    mxInput(graph, n);

    // print graph
    cout << endl << "----- Graph -----" << endl;
    mxPrintCon(graph, n);
    cout << endl;
    mxPrintRaw(graph, n);

    // initialize tree
    int** tree;
    tree = new int*[n];
    for (int i = 0; i < n; i++)
        tree[i] = new int[n];
    mxZero(tree, n);

    // building the spanning tree with Prim's algorithm
    int weight = PrimsAlgo(graph, tree, n);

    // print tree
    cout << endl << "Prim's algorithm done!" << endl;
    cout << endl << "----- Tree -----" << endl;
    mxPrintCon(tree, n);
    cout << "Tree weight: " << weight << endl;
}