#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
public:
    T data;
    Node* left;
    Node* right;

    Node(T& data) : data(data), left(nullptr), right(nullptr){} // TODO: Implement constructor here
};

#endif // NODE_H