// maorw9@gmail.com
// 212305965

#pragma once
#include "Node.cpp"
#include <queue>
#include <algorithm>
#include <stdexcept>

template <typename T, unsigned int D = 2>
class Tree
{
private:
    Node<T> *root = nullptr;

public:
    ~Tree() { delete root; }

    void add_root(T nodeValue);
    void add_sub_node(T parentValue, T childValue);

    Node<T> *get_root() const { return root; }
    unsigned int get_degree() const { return D; }

    class Iterator
    {
    protected:
        std::queue<Node<T> *> node_queue;

    public:
        virtual Iterator &operator++()
        {
            node_queue.pop();
            return *this;
        }

        virtual bool operator!=(const Iterator &other) const
        {
            return !node_queue.empty() || !other.node_queue.empty();
        }

        virtual Node<T> &operator*() const
        {
            return *node_queue.front();
        }

        virtual Node<T> *operator->() const
        {
            return node_queue.front();
        }
    };

    class BFS_iterator : public Iterator
    {
    public:
        explicit BFS_iterator(Node<T> *root = nullptr)
        {
            if (root != nullptr)
                visit_BFS(root);
        }

    private:
        void visit_BFS(Node<T> *source)
        {
            std::queue<Node<T> *> q;
            q.push(source);
            while (!q.empty())
            {
                Node<T> *node = q.front();
                q.pop();
                this->node_queue.push(node);
                for (auto &child : *node)
                    q.push(&child);
            }
        }
    };

    class Pre_Order_Iterator : public Iterator
    {
    public:
        explicit Pre_Order_Iterator(Node<T> *root = nullptr)
        {
            if (root != nullptr)
                visit_pre_order(root);
        }

    private:
        void visit_pre_order(Node<T> *node)
        {
            this->node_queue.push(node);
            for (auto &child : *node)
                visit_pre_order(&child);
        }
    };

    class Post_Order_Iterator : public Iterator
    {
    public:
        explicit Post_Order_Iterator(Node<T> *root = nullptr)
        {
            if (root != nullptr)
                visit_post_order(root);
        }

    private:
        void visit_post_order(Node<T> *node)
        {
            for (auto &child : *node)
                visit_post_order(&child);
            this->node_queue.push(node);
        }
    };

    class In_Order_Iterator : public Iterator
    {
    public:
        explicit In_Order_Iterator(Node<T> *root = nullptr)
        {
            if (root != nullptr)
                visit_in_order(root);
        }

    private:
        void visit_in_order(Node<T> *node)
        {
            int numChildren = node->num_children();
            if (numChildren > 0)
            {
                // Visit the left half of the children
                for (int i = 0; i < numChildren / 2; ++i)
                {
                    visit_in_order(node->get_child(i));
                }
                // Process the current node
                this->node_queue.push(node);
                // Visit the right half of the children
                for (int i = numChildren / 2; i < numChildren; ++i)
                {
                    visit_in_order(node->get_child(i));
                }
            }
            this->node_queue.push(node);
            if (numChildren == 2)
            {
                visit_in_order(node->get_child(1));
            }
        }
    };

    class DFS_Iterator : public Iterator
    {
    public:
        explicit DFS_Iterator(Node<T> *root = nullptr)
        {
            if (root != nullptr)
                visit_DFS(root);
        }

    private:
        void visit_DFS(Node<T> *node)
        {
            for (auto &child : *node)
                visit_DFS(&child);
            this->node_queue.push(node);
        }
    };

    Iterator begin() { return BFS_iterator(root); }
    Iterator end() { return BFS_iterator(); }

    BFS_iterator begin_BFS() { return BFS_iterator(root); }
    BFS_iterator end_BFS() { return BFS_iterator(); }

    DFS_Iterator begin_DFS() { return DFS_Iterator(root); }
    DFS_Iterator end_DFS() { return DFS_Iterator(); }

    Pre_Order_Iterator begin_PreOrder() { return Pre_Order_Iterator(root); }
    Pre_Order_Iterator end_PreOrder() { return Pre_Order_Iterator(); }

    Post_Order_Iterator begin_PostOrder() { return Post_Order_Iterator(root); }
    Post_Order_Iterator end_PostOrder() { return Post_Order_Iterator(); }

    In_Order_Iterator begin_InOrder() { return In_Order_Iterator(root); }
    In_Order_Iterator end_InOrder() { return In_Order_Iterator(); }

    Iterator begin_Heap()
    {
        to_heap();
        return BFS_iterator(root);
    }
    Iterator end_Heap() { return BFS_iterator(); }

    void clear()
    {
        delete root;
        root = nullptr;
    }

    void to_heap();
};

template <typename T, unsigned int D>
void Tree<T, D>::to_heap()
{
    if (D != 2)
        throw std::logic_error("Can only turn binary trees to heaps");

    std::vector<T> values;
    for (auto &node : *this)
        values.push_back(*node);
    std::sort(values.begin(), values.end());

    clear();
    root = new Node<T>(values[0], D);
    for (unsigned int i = 1; i < values.size(); ++i)
        add_sub_node(values[(i - 1) / 2], values[i]);
}

template <typename T, unsigned int D>
void Tree<T, D>::add_sub_node(T parentValue, T childValue)
{
    Node<T> *parent = nullptr;
    for (auto &node : *this)
    {
        if (*node == childValue)
            throw std::logic_error("The child node already exists in the tree");
        if (*node == parentValue)
            parent = &node;
    }
    if (parent == nullptr)
        throw std::logic_error("The parent node does not exist in the tree");
    if (parent->num_children() >= D)
        throw std::logic_error("The parent has reached its maximum degree");
    parent->add_child(new Node<T>(childValue, D));
}

template <typename T, unsigned int D>
void Tree<T, D>::add_root(T node_value)
{
    if (root != nullptr)
        throw std::logic_error("The root of the tree has already been set");
    root = new Node<T>(node_value, D);
}
