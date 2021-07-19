//
// Created by M Elokaily on 7/19/2021.
//

#ifndef DOUBLY_LINKEDLIST_NODE_DOUBLYNODE_H
#define DOUBLY_LINKEDLIST_NODE_DOUBLYNODE_H

template <class t>
class DoublyNode {
private:
    t value;
    DoublyNode<t> * pre, *nxt;
public:
    DoublyNode();
    void setPre(DoublyNode<t>*);
    void setNxt(DoublyNode<t>*);
    void setValue(t);
    t& getValue();
    DoublyNode* getPre() const;
    DoublyNode* getNxt() const;
};

#endif //DOUBLY_LINKEDLIST_NODE_DOUBLYNODE_H
