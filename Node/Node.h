//
// Created by M Elokaily on 7/17/2021.
//

#ifndef NODE_NODE_H
#define NODE_NODE_H

template <class t>
class Node {
private:
    t value;
    Node * nxt;
public:
    Node();
    Node(t);
    void setValue(t);
    t& getValue();
    void setNxt(Node<t>*);
    Node<t>* getNxt() const;
};

#endif //NODE_NODE_H