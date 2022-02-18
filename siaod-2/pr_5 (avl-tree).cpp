#include <iostream>

using namespace std;

// structure for node of AVL tree
struct node {
    int key; // integer node value as in variant (2)
    unsigned char height;
    node *left;
    node *right;

    node(int k) {
        key = k;
        left = right = 0;
        height = 1;
    }
};

unsigned char height(node *p) { return p ? p->height : 0; }

int balanceFactor(node *p) { return height(p->right) - height(p->left); }

void fixHeight(node *p) {
    unsigned char hl = height(p->left);
    unsigned char hr = height(p->right);
    p->height = (hl > hr ? hl : hr) + 1;
}

// right rotation around node p
node *rotateRight(node *p) {
    node *q = p->left;
    p->left = q->right;
    q->right = p;
    fixHeight(p);
    fixHeight(q);
    return q;
}

// left rotation around node p
node *rotateLeft(node *q) {
    node *p = q->right;
    q->right = p->left;
    p->left = q;
    fixHeight(q);
    fixHeight(p);
    return p;
}

// balancing of node p
node *balance(node *p) {
    fixHeight(p);
    if (balanceFactor(p) == 2) {    // balancing for right side
        if (balanceFactor(p->right) < 0)
            p->right = rotateRight(p->right);
        return rotateLeft(p);
    }
    if (balanceFactor(p) == -2) {   // balancing for left side
        if (balanceFactor(p->left) > 0)
            p->left = rotateLeft(p->left);
        return rotateRight(p);
    }
    return p;                       // balancing not needed
}

// insert new node with value k into tree with root p
node *insert(node *p, int k) {
    if (!p) return new node(k); // first node
    if (k < p->key) p->left = insert(p->left, k);
    else p->right = insert(p->right, k);
    return balance(p);
}

node *findMin(node *p) { return p->left ? findMin(p->left) : p; }

node *removeMin(node *p) {
    if (p->left == 0) return p->right;
    p->left = removeMin(p->left);
    return balance(p);
}

// removal of node with value k from tree p
node *remove(node *p, int k) {
    if (!p) return 0;
    if (k < p->key)         // search in left tree
        p->left = remove(p->left, k);
    else if (k > p->key)    // search in right tree
        p->right = remove(p->right, k);
    else {                  // found and removing
        node *q = p->left;
        node *r = p->right;
        delete p;
        if (!r) return q;
        node *min = findMin(r);
        min->right = removeMin(r);
        min->left = q;
        return balance(min);
    }
    return balance(p);
}

// symmetrical traversing of tree p
void traverseSymm(node *p) {
    if (!p) return;
    traverseSymm(p->left);
    cout << p->key << " ";
    traverseSymm(p->right);
}

// find height of the tree
void findHeight(node *p, int &h) {
    if (!p) return;
    findHeight(p->left, h);
    if (p->height > h) h = p->height;
    findHeight(p->right, h);
}

// find node and its distance from root
bool findNode(node *p, int k, int &c) {
    if (p != nullptr) {
        if (k == p->key) { c++; return true; }
        else if (k < p->key) {
            if (findNode(p->left, k, c))
                { c++; return true; }}
        else {
            if (findNode(p->right, k, c))
                { c++; return true; }
            return false; }}
    return false;
}

void print_Tree(node *p, int level) {
    if (p) {
        print_Tree(p->left, level + 1);
        for (int i = 0; i < level; i++) cout << "\t";
        cout << p->key << endl;
        print_Tree(p->right, level + 1);
    }
}

int main() {
    node *p = nullptr;
    int temp, h = -1, c = -1;
    cout << "Enter 10 values:" << endl;
    for (int i = 0; i < 10; i++)
        { cin >> temp; p = insert(p, temp); }

    cout << "Traversing tree:" << endl;
    traverseSymm(p); cout << endl;
    findHeight(p, h);
    cout << "Height = " << h - 1 << endl;

    cout << "Tree:" << endl;
    print_Tree(p, 0);
    cout << endl;

    cout << "Enter key to search: ";
    int k; cin >> k;
    if (findNode(p, k, c))
        cout << "Distance to node with value " << k << " is " << c << endl;
    else cout << "Node with value " << k << " not found" << endl;
}