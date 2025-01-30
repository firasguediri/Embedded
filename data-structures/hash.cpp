#include <iostream>
#include <cstring>

class HashMap
{
private:
    int *keys;
    // TODO: change values from array to linked list
    int *values;
    int size;

public:
    HashMap()
    {
        std::cout << "Hash map created" << std::endl;
        keys = nullptr;
        values = nullptr;
        size = 0;
    };

    ~HashMap()
    {
        std::cout << "Hash map deleated" << std::endl;
        delete[] keys;
        delete[] values;
        };

    void resize()
    {
        ++size;

        int *new_keys = new int[size];
        int *new_values = new int[size];

        std::memcpy(new_keys, keys, size - 1);
        std::memcpy(new_values, values, size - 1);

        delete[] keys;
        delete[] values;

        keys = new_keys;
        values = new_values;

        new_keys = nullptr;
        new_values = nullptr;
    };

    void insert(int key, int value)
    {
        resize();
        keys[size - 1] = key;
        values[hash(key)] = value;
    };

    int hash(int key)
    {
        return std::hash<int>{}(key) % size;
    };

    void print()
    {
        std::cout << "{";
        for (int i = 0; i < size - 1; i++)
        {
            std::cout << "(" << keys[i] << ", " << values[i] << "), ";
        }
        std::cout << "(" << keys[size - 1] << ", " << values[size - 1] << ")";
        std::cout << "}" << std::endl;
        ;
    };
};

int main()
{
    HashMap dict;
    dict.insert(1, 15);
    dict.insert(2, 18);
    dict.print();
    return 0;
}
