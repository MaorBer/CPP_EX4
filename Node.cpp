// maorw9@gmail.com
// 212305965


#pragma once


#include <vector>
#include <stdexcept>
#include <iostream>

using std::vector;

template <typename T>
class Node {
    T node_value;
    vector<Node<T>*> child_nodes;
    unsigned int max_degree = 0;
    unsigned int child_index = 0;

public:
    Node(T value) : node_value(value) { child_nodes.resize(0); }
    Node(T value, unsigned int degree) : node_value(value) { set_degree(degree); }
    ~Node() {
        for (auto& curr_child : child_nodes)
            delete curr_child;
        child_nodes.clear();
    }

    void set_degree(unsigned int degree_measure);
    T get_value() const { return node_value; }

    void add_child(Node<T>* child);
    unsigned int num_children() const { return child_index; }
    Node<T>* get_child(unsigned int index) const { return child_nodes[index]; }

    T operator*() const { return node_value; }

   class Iterator {
        typename vector<Node<T>*>::iterator iter;

    public:
        explicit Iterator(typename vector<Node<T>*>::iterator it) : iter(it) {}

        Iterator& operator++() {
            ++iter;
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return this->iter != other.iter;
        }

        Node<T>& operator*() const {
            return **iter;
        }

        Node<T>* operator->() const {
            return *iter;
        }
    };

    Iterator begin() {
        return Iterator(child_nodes.begin());
    }

    Iterator end() {
        return Iterator(child_nodes.begin() + child_index);
    }
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Node<T>& node) {
    os << node.get_value();
    return os;
}

template<typename T>
void Node<T>::add_child(Node<T>* child) {
    if (child_index >= max_degree)
        throw std::out_of_range("The node has reached its maximum degree");
    child_nodes[child_index++] = child;
}

template<typename T>
void Node<T>::set_degree(unsigned int degree) {
    if (max_degree != 0)
        throw std::logic_error("The degree of the node has already been set");
    max_degree = degree;
    child_nodes.resize(degree);
}


