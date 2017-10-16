#include <iostream>  // For cout and endl
#include <cstdlib>
#include <ctime>
#include "single_linked_list.h"

int main()
{
    int initialVals[] = {5, 6, 7, 8};
    SingleLinkedList<int> mylist(initialVals, 4);
    std::cout << "Appending 3" << std::endl;
    mylist.append(3);
    std::cout << "Current List: ";
    mylist.print();
    std::cout << std::endl;
    std::cout << "Appending 4" << std::endl;
    mylist.append(4);
    std::cout << "Current List: ";
    mylist.print();
    std::cout << std::endl;
    std::cout << "Item 2: " << mylist.get(2) << std::endl;
}
