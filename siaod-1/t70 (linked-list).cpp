#include <iostream>
#include <string>

using namespace std;

struct node {
    int number_b{}, number_g{}, degree{};
    node *prev = nullptr;
    node *next = nullptr;
};

class list {
    node *first;
    node *last;
    int count;

public:
    list() : first(nullptr), last(nullptr), count(0) {};
    void print1();
    void print2();
    void create_list(int n);
    void add_node(int number_b, int number_g, int degree);
    void del();
    void push_back();
    void friend new_l(list lst1, list lst2);
    node *findnode(int data);
};

void list::add_node(int number_b, int number_g, int degree) {
    node *x = new node;
    x->next = nullptr;
    x->prev = nullptr;
    x->number_b = number_b;
    x->number_g = number_g;
    x->degree = degree;
    if (last != nullptr) {
        last->next = x;
        x->prev = last;
    }
    if (count == 0) first = last = x;
    else
        last = x;
    count++;
}

void list::create_list(int n) {
    cout << "Value:" << '\n';
    int number_b, number_g, degree;
    for (int i = 0; i < n; i++) {
        cin >> number_b >> number_g >> degree;
        add_node(number_b, number_g, degree);
    }
}

void list::print1() {
    if (count != 0) {
        node *x = first;
        while (x != nullptr) {
            cout << x->number_b << ' '
                 << x->number_g << ' '
                 << x->degree << '\n';
            x = x->next;
        }
    }
}

void list::print2() {
    if (count != 0) {
        node *x = last;
        while (x != nullptr) {
            cout << x->number_b << ' '
                 << x->number_g << ' '
                 << x->degree << '\n';
            x = x->prev;
        }
    }
}

void list::del() {
    int data;
    cout << "Enter delete number of group";
    cin >> data;
    node *x = first;
    while (x != nullptr) {
        if (x->number_g == data) {
            node *y = x->prev;
            node *z = x->next;
            if (y != nullptr && count != 1) y->next = z;
            if (z != nullptr && count != 1) z->prev = y;
            if (y == nullptr) first = z;
            if (z == nullptr) last = y;
            delete x;
            count--;
            if (z != nullptr)
                x = z;
            else break;
        }
        x = x->next;
    }
    print1();
}

node *list::findnode(int data) {
    node *node = first;
    while (node != nullptr) {
        if (node->number_b == data) {
            return node;
        }
        node = node->next;
    }
    cout << "Not found\n";
    return nullptr;
}

void list::push_back() {
    cout << "Enter the number of book, number of group, degree" << '\n';
    int number_b, number_g, degree;
    cin >> number_b >> number_g >> degree;
    node *x = new node;
    x->number_b = number_b;
    x->number_g = number_g;
    x->degree = degree;
    if (x->number_b == first->number_b) {
        if (first->prev == nullptr) {}
        else {
            first->prev = x;
            x->prev = nullptr;
            x->next = first;
            node *second = first->prev;
            first->prev = x;
            x->next = first;
            x->prev = second;
        }
    }
    count++;
    print1();
}


void new_l(list lst1, list lst2) {
    node *x = lst1.first;
    while (x->next != nullptr) {
        if (x->degree == 2) {
            lst2.add_node(x->number_b, x->number_g, x->degree);
        }
        x = x->next;
    }
}

void menu() {
    list l, l2;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    l.create_list(n);
    cout << "Functions:" << endl
         << "1) Display ->" << endl
         << "2) Display <-" << endl
         << "3) Add node" << endl
         << "4) Delete node" << endl
         << "5) Create new list" << endl
         << "6) Find node" << endl;
    cout << "Enter function number: ";
    int a;
    cin >> a;
    switch (a) {
        case 1: { l.print1(); break; }
        case 2: { l.print2(); break; }
        case 3: { l.push_back(); break; }
        case 4: { l.del(); break; }
        case 5: { new_l(l, l2); break; }
        case 6: {
            cout << "Enter number of book: ";
            int data;
            cin >> data;
            l.findnode(data);
            break;
        }
        default: {
            cout << "Choose the true number" << '\n';
            break;
        }
    }
}

int main() {
    menu();
}