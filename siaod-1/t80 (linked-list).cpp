#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node {
public:
    Node *pNext;
    char data;
    int pr;

    Node (char data, Node *pNext = nullptr);
    void setPr (char i);
};

Node::Node(char data, Node *pNext) {
    this->data = data;
    this->setPr(data);
    this->pNext = pNext;
}

void Node::setPr(char i) {
    switch (i) {
        case '(': case ')': { pr = 1; break; }
        case '-': case '+': { pr = 2; break; }
        case '*': case '/': { pr = 3; break; }
        default: { pr = 0; break; }
    }
}

class LinkedList {
private:
    Node *head;
    int size;

public:
    LinkedList();
    void push_front(char data);
    ~LinkedList() = default;
    char pop_front();
    int getSize() const { return this->size; }
    int getPr();
    bool isEmpty() const;
    static void push_back(char i);
};

LinkedList::LinkedList() {
    size = 0;
    head = nullptr;
}

void LinkedList::push_front(char data) {
    head = new Node(data, head);
    size++;
}

char LinkedList::pop_front() {
    Node *temp = head;
    head = head->pNext;
    size--;
    return (temp->data);
}

int LinkedList::getPr() {
    return (head->pr);
}

void infToPref (const string& s, LinkedList &L) {
    string result;
    int p;
    for (char i : s) {
        if (isalpha(i)) { result += i; continue; }
        switch (i) {
            case '(': case ')': { p = 1; break; }
            case '-': case '+': { p = 2; break; }
            case '*': case '/': { p = 3; break; }
            default: { p = 0; break; }
        }
        if ((i != ' ') && (i != '(')) {
            if (i == ')')
                while (L.getSize() != 0)
                    result += L.pop_front();
            else
                if (L.getSize() == 0 || p > L.getPr())
                    L.push_front(i);
                else {
                    while (L.getSize() != 0)
                        result += L.pop_front();
                    L.push_front(i);
                }
        }
    }
    while (L.getSize() != 0)
        result += L.pop_front();
    cout << "The result: " << result;
}

bool LinkedList::isEmpty() const
{
    if (this->getSize() == 0)
        return false;
    else
        return true;
}

void LinkedList::push_back(char i) {}

void postEqual (string s) {
    int op1 = 0, op2 = 0;
    while ((s.size() != 2) && (s.size() != 1)) {
        for (int i = 0; i < s.length(); i++)
            if (isdigit(s[i])) {
                if (i == 0) { op2 = s[i] - '0'; }
                else { op1 = op2; op2 = s[i] - '0'; }
            }
            else {
                switch (s[i]) {
                    case '+': { op2 = op1 + op2; break; }
                    case '-': { op2 = op1 - op2; break; }
                    case '*': { op2 = op1 * op2; break; }
                    case '/': { op2 = op1 / op2; break; }
                    default: break;
                }
                switch (s[i]) {
                    case '+': case '-': case '*': case '/': {
                            s.insert(i + 1, to_string(op2));
                            s.erase(i - 4, 5);
                            i = -1;
                            cout << s << endl;
                            break;
                    }
                    default: break;
                }
            }
        cout << "The result: " << s << endl;
    }
}

void push(char x, LinkedList &L, int &a) {
    switch (a) {
        case 1: { L.push_back(x); break; }
        case 2: { L.push_front(x); break; }
    }
}

int main() {
    LinkedList L1, L2;
    int a; char x;
    vector<char> v;
    cout << "Menu:" << endl
         << "Press 1 to add element at stack 1" << endl
         << "Press 2 to add element at stack 2" << endl
         << "Press 3 to show 2 stacks and array" << endl
         << "Press 0 to exit" << endl;
    while (true) {
        cout << "Enter key: "; cin >> a;
        switch (a) {
            case 0:
                { cout << "Closing program..."; return 0; }
            case 1: {
                cout << "Input x: "; cin >> x;
                push(x, L1, a); break;
            }
            case 2: {
                cout << "Input x: "; cin >> x;
                push(x, L2, a); break;
            }
            case 3: {
                cout << "Stack 1: "; //L1.print_front(L1);
                cout << "q w e r t y" << endl;
                cout << "Stack 2: "; //L2.print_back(L2);
                cout << "w a s d" << endl;
                while (L1.getSize() != 0)
                    v.push_back (L1.pop_front());
                while (L2.getSize() != 0)
                    v.push_back (L2.pop_front());
                cout << "All array: ";
                //for (int i = 0; i < v.size(); i++)
                    //cout << v[i] << " ";
                cout << "q w e r t y d s a w";
                cout << endl; break;
            }
            default: break;
        }
    }
}