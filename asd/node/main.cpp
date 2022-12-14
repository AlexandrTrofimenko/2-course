#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct leaf
{
    int value;
    leaf* left;
    leaf* right;

};

class BinaryTree
{
public:

    BinaryTree()
    {
        root = NULL;
    }
    ~BinaryTree()
    {
        destroy_tree();
    }

    void destroy_tree()
    {
        destroy_tree(root);
    }

    void readAndInsert(int& i, string& plant)
    {
        readAndInsert(i, plant, NULL);
    }

    void direct_traversal()
    {
        direct_traversal(root);
    }

    void symmetric_traversal()
    {
        symmetric_traversal(root);
    }

    void reverse_traversal()
    {
        reverse_traversal(root);
    }

private:
    leaf* root;
    void destroy_tree(leaf* leaf)
    {
        if (leaf != NULL)
        {
            destroy_tree(leaf->left);
            destroy_tree(leaf->right);
            delete leaf;
        }
    }

    bool readAndInsert(int& i, string& plant, leaf* currentLeaf) 
    {
        string str = "";
        while (i < plant.size() && plant[i] != '(' && plant[i] != ')' && plant[i] != ',') 
        {
            if (plant[i] != ' ')
            {
                str += plant[i];
            }
            i++;
        }
        i++;

        if (str != "") 
        {
            int newValue = stoi(str);

            if (currentLeaf == NULL)
            {
                root = new leaf;
                root->value = newValue;
                currentLeaf = root;
            }
            else
            {
                currentLeaf->value = newValue;
            }
            currentLeaf->left = NULL;
            currentLeaf->right = NULL;

            if (plant[i - 1] != ',' && plant[i - 1] != ')')
            {
                currentLeaf->left = new leaf;
                if (!readAndInsert(i, plant, currentLeaf->left))
                {
                    delete currentLeaf->left;
                    currentLeaf->left = NULL;
                }

                currentLeaf->right = new leaf;
                if (!readAndInsert(i, plant, currentLeaf->right))
                {
                    delete currentLeaf->right;
                    currentLeaf->right = NULL;
                }

            }

            while (i < plant.size() && (plant[i] == ')' || plant[i] == ','))
            {
                i++;
            }
            return true;
        }
        else
        {
            return false;
        }
    }


    void direct_traversal(leaf* currentLeaf)
    {
        if (currentLeaf != NULL)
        {
            cout << currentLeaf->value << " ";
            direct_traversal(currentLeaf->left);
            direct_traversal(currentLeaf->right);
        }
    }

    void symmetric_traversal(leaf* currentLeaf)
    {
        if (currentLeaf != NULL)
        {
            symmetric_traversal(currentLeaf->left);
            cout << currentLeaf->value << " ";
            symmetric_traversal(currentLeaf->right);
        }
    }


    void reverse_traversal(leaf* currentLeaf)
    {
        if (currentLeaf != NULL)
        {
            reverse_traversal(currentLeaf->left);
            reverse_traversal(currentLeaf->right);
            cout << currentLeaf->value << " ";
        }
    }

};

int main()
{
    setlocale(LC_ALL, "Russian");
    BinaryTree NewTree;

    cout << "Введите дерево" << endl;

    string plant;
    getline(cin, plant);
    cout << endl;

    int i = 0;
    NewTree.readAndInsert(i, plant);

    cout << "Прямой обход:" << endl;
    NewTree.direct_traversal();
    cout << endl;

    cout << "Центрированный обход:" << endl;
    NewTree.symmetric_traversal();
    cout << endl;

    cout << "Концевой обход:" << endl;
    NewTree.reverse_traversal();
    cout << endl;

    return 0;
}