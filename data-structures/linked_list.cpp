#include <iostream>
#include <string>
#include <utility>
template <typename T>
class Node
{
public:
    Node() : _val{}, _next(nullptr) {};
    Node(T val) : _val(val), _next(nullptr) {};
    Node(T val, Node *next) : _val(val), _next(next) {};
    Node(Node *next) : _val{}, _next(next) {};
    // Copy Constructor
    Node(Node &other)
    {
        std::cout << "Copying Node" << std::endl;
        _val = other._val;
        _next = other._next;
    }
    // Move constructor
    Node(Node &&other)
    {
        std::cout << "Moving node" << std::endl;
        _val = std::move(other._val);
        _next = std::exchange(other._next, nullptr);
    }

    T _val;
    Node *_next;
};

int main()
{
    Node<std::string> *head = new Node<std::string>();
    head->_next = new Node<std::string>();

    std::cout << head->_val << std::endl;
    std::cout << head->_next->_val << std::endl;
    delete head;
}