#include <iostream>
#include <string>
#include <utility>
#include <vector>

template <typename T>
class Node
{
public:
    Node() = default;
    Node(T val) : val(val), next(nullptr) {};
    Node(T val, Node *next) : val(val), next(next) {};
    Node(Node *next) : val{}, next(next) {};
    // Copy Constructor
    Node(Node &other)
    {
        std::cout << "Copying Node" << std::endl;
        val = other.val;
        next = other.next;
    }
    // Move constructor
    Node(Node &&other)
    {
        std::cout << "Moving node" << std::endl;
        val = std::move(other.val);
        next = std::exchange(other.next, nullptr);
    }

    T val;
    Node *next;
};

template <typename T>
class LinkedList
{
public:
    Node<T> *head;
    LinkedList()
    {
        head = new Node<T>();
    }
    LinkedList(T *list, int size)
    {
        head = new Node<T>();
        Node<T> *current = head;
        for (int i = 0; i < size; i++)
        {
            current->val = list[i];
            if (i < size - 1)
            {
                current->next = new Node<T>();
                current = current->next;
            }
        }
    }

    ~LinkedList()
    {
        Node<T> *current = head;
        Node<T> *previous;
        while (current)
        {
            previous = current;
            current = current->next;
            free(previous);
        }
    }
    // TODO: Add move assignment, move constructor and copy constructor;
    void print()
    {
        Node<T> *current = head;
        std::cout << "[" << current->val;
        current = current->next;
        while (current)
        {
            std::cout << ", " << current->val;
            current = current->next;
        }
        std::cout << "]" << std::endl;
    }
};

int main()
{
    int list[] = {1, 2, 3, 4, 5};
    std::vector<int> vec1 = {1, 2, 3};
    LinkedList<int> list2(list, 4);
    list2.print();
}