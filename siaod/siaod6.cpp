#include <iostream>

// структура элемента списка
struct Node {
    int data;
    Node *nextNode;

    Node() {};

    Node (int data, Node *nextNode = nullptr):
            data(data),
            nextNode(nextNode) {}
};

// функция вывода списка
void showList(Node *head) {
    Node *node = head;
    while (node != nullptr) {
        std::cout << node->data;
        node = node->nextNode;
    }
}

// функция вставки элемента в край списка
void insertNode(Node *previousNode, int data, Node **node) {
    *node = new Node(data);
    previousNode->nextNode = *node;
}

// функция вставки элемента
void insertBetweenNode(Node *previousNode, int data, Node **node) {
    *node = new Node(data, previousNode->nextNode);
    previousNode->nextNode = *node;
}

// функция создания списка
void createList(int length, int *dataArr, Node *head) {
    Node *node = nullptr;
    insertNode(head, dataArr[1], &node);
    Node *previousNode = node;
    for (int i = 2; i < length; ++i) {
        Node *nextNode = nullptr;
        insertNode(previousNode, dataArr[i], &nextNode);
        previousNode = nextNode;
    }
}

bool checkIfUnique(int data, Node *head)
{
    bool unique = true;
    Node *node = head;
    while (node != nullptr) {
        if (node->data == data)
            unique = false;
    }
    return unique;
}

// функция 1 (список со значениями двух исходных списков)
void createSetList(Node *head, Node *list1, Node *list2)
{
    Node *node = list1;
    int data;
    while (node != nullptr) {
        data = node->data;
        if (checkIfUnique(data, head))
            insertNode(head, data, &nextNode);
    }
    node = list2;
    while (node != nullptr) {
        data = node->data;
        if (checkIfUnique(data, head))
            insertNode(head, data, &nextNode);
    }
}

// функция 2 (удаление четных элементов)
void deleteEvenNodes(Node *head) {
    Node *node = head;
    while (node != nullptr)
    {
        node->nextNode = node->nextNode->nextNode;
        node = node->nextNode;
    }
}

// функция 3 (вставка элемента после каждых двух элементов)
void insertAfterTwo(Node *head) {
    Node *node = head;
    int sum;
    while (node != nullptr)
    {
        sum += node->data;
        node = node->nextNode;
        sum += node->data;
        node = node->nextNode;
        if (node != nullptr)
            insertBetweenNode(node, sum, head);
    }
}

int main() {
    int l1, l2;
    std::cout << "Length of list 1 = ";
    std::cin >> l1;
    std::cout << "Length of list 2 = ";
    std::cin >> l2;

    std::cout << "Data of nodes for list 1:" << std::endl;
    int *dataArr1 = new int[l1];
    for (int i = 0; i < l1; ++i)
        std::cin >> dataArr1[i];
    std::cout << "Data of nodes for list 2:" << std::endl;
    int *dataArr2 = new int[l2];
    for (int i = 0; i < l2; ++i)
        std::cin >> dataArr2[i];

    Node *list1 = new Node(dataArr1[0]);
    Node *list2 = new Node(dataArr2[0]);
    createList(l1, dataArr1, list1);
    createList(l2, dataArr2, list2);

    /*
    showList(head);
    isSameNode(head);
    insertEvenNode(head);
    showList(head);
    deleteMax(&head);
    showList(head);
    */
}