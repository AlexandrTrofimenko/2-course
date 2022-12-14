#include <iostream>

using namespace std;

struct node {
    explicit node(int t) : data(t) {}
    int data;
    node* first = nullptr;
    node* second = nullptr;
};

void Tree(node* tree) {
    if (tree != nullptr) {
        Tree(tree->first);
        cout << tree->data << " ";
        Tree(tree->second);
    }
}

node* new_leaf(node* tree, int x) {
    if (tree == nullptr)
        tree = new node(x);
    else
        if (x < tree->data)
            tree->first = new_leaf(tree->first, x);
        else
            tree->second = new_leaf(tree->second, x);
    return(tree);
}

void empty_space(node* tree) {
    if (tree != nullptr) {
        empty_space(tree->first);
        empty_space(tree->second);
        delete tree;
    }
}

node* Search(node* tree, int x)
{
    if (tree == nullptr) return nullptr;
    if (tree->data == x) return tree;
    if (x < tree->data) return Search(tree->first, x);
    else return Search(tree->second, x);

}

node* min(node* x)
{
    if (x->first == nullptr) return x;
    else return min(x->first);
}

node* max(node* x)
{
    if (x->second == nullptr) return x;
    else return max(x->second);
}

node* delete_leaf(node* tree, int x)
{
    if (tree == nullptr)
        return tree;
    if (x < tree->data)
        tree->first = delete_leaf(tree->first, x);
    else if (x > tree->data)
        tree->second = delete_leaf(tree->second, x);
    else if (tree->first != nullptr && tree->second != nullptr) {
        tree->data = min(tree->second)->data;
        tree->second = delete_leaf(tree->second, tree->data);
    }
    else
        if (tree->first != nullptr)
            tree = tree->first;
        else if (tree->second != nullptr)
            tree = tree->second;
        else
            tree = nullptr;
    return tree;
}

int main() {

    setlocale(LC_ALL, "Rus");

    node* root = nullptr;
    cout << "Введите число вершин:" << endl;
    int n, a, find, dob, del;
    cin >> n;
    cout << "Введите вершины дерева:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> a;
        root = new_leaf(root, a);
    }
    Tree(root);
    cout << endl;
    cout << "Введите вершину, которую нужно удалить ";
    cin >> del;
    delete_leaf(root, del)->data;
    Tree(root);
    cout << endl;
    cout << "Введите вершину, которую нужно добавить ";
    cin >> dob;
    new_leaf(root, dob)->data;
    Tree(root);
    cout << endl;
    cout << "Введите вершину, которую нужно найти ";
    cin >> find;
    if (Search(root, find) != nullptr)
        cout << "Присутствует";
    else
        cout << "Отсутствует";
    //cout << Search(root, find)->data<< endl;
    empty_space(root);
    return 0;
}