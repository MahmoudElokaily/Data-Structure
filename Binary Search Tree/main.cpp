#include <iostream>

using namespace std;

template<class t>
struct Node {
    t value;
    Node* left;
    Node* right;
};

template<class t>
class BST{
private:
    Node<t>* root;

    // Function to help developer to remove from tree
    void deleteFromTree (Node<t>* &p) {
        Node<t> *current;    //pointer to traverse
        //the tree
        Node<t> *trailCurrent;   //pointer behind current
        Node<t> *temp;        //pointer to delete the node

        if (p->left == NULL && p->right == NULL) {
            delete p;
            p = NULL;
        } else if (p->left == NULL) {
            temp = p;
            p = p->right;
            delete temp;
        } else if (p->right == NULL) {
            temp = p;
            p = p->left;
            delete temp;
        } else {
            current = p->left;
            trailCurrent = NULL;

            while (current->right != NULL) {
                trailCurrent = current;
                current = current->right;
            }//end while

            p->value = current->value;

            if (trailCurrent == NULL) //current did not move;
                //current == p->left; adjust p
                p->left = current->left;
            else
                trailCurrent->right = current->left;

            delete current;
        }
    }
public:

    BST(){
        root = NULL;
    }

    // Function to insert new Item in BST
    void insert(t newItem){
        Node<t> * newNode = new Node<t>;
        newNode->value = newItem;
        newNode->right = newNode->left = NULL;
        if (root == NULL){
            root = newNode;
        }
        else {
            Node<t>* cur = root,* parent = NULL;
            while (cur != NULL){
                parent = cur;
                if (newItem <= cur->value){
                    cur = cur->left;
                }
                else {
                    cur = cur->right;
                }
            }
            if (newItem <= parent->value){
                parent->left = newNode;
            }
            else {
                parent->right = newNode;
            }
        }
    }

    // Function to return max element in BST
    t getMax(){
        Node<t>* cur = root;
        while (cur->right != NULL){
            cur = cur->right;
        }
        return cur->value;
    }

    // Function to return min element in BST
    t getMin(){
        Node<t>* cur = root;
        while (cur->left != NULL){
            cur = cur->left;
        }
        return cur->value;
    }

    // Function to remove elements
    void remove(t item)
    {
        Node<t> *current;  //pointer to traverse the tree
        Node<t> *trailCurrent; //pointer behind current

        if(root == NULL)
        {
            cout<<"Cannot delete from the empty tree."<<endl;
            return;
        }
        if(root->value == item)
        {
            deleteFromTree(root);
            return;
        }

        //if you get here, then the item to be deleted is not the root
        trailCurrent = root;

        if(root->value > item)
            current = root->left;
        else
            current = root->right;

        //search for the item to be deleted.
        while(current != NULL)
        {
            if(current->value == item)
                break;
            else
            {
                trailCurrent = current;
                if(current->value > item)
                    current = current->left;
                else
                    current = current->right;
            }
        }// once the while is done, current points to either NULL or to the node to be deleted

        if(current == NULL)
            throw "The delete item is not in the tree.";
        else if(trailCurrent->value > item)
            deleteFromTree(trailCurrent->left);
        else
            deleteFromTree(trailCurrent->right);
    }

    // Function to know height of Node

};
int main() {
    BST<int> t;
    t.insert(8);
    t.insert(5);
    t.insert(13);
    t.insert(3);
    t.insert(7);
    t.insert(10);
    t.insert(15);
    t.remove(3);
    cout<<t.getMax()<<endl;
    cout<<t.getMin()<<endl;


    return 0;
}
