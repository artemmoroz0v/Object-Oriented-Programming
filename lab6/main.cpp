#include <iostream>
#include "pentagon.h"
#include "TLinkedList.h"
#include "TLinkedListItem.h"
#include "TAllocatorBlock.h"

int main () {
    //lab1
    Pentagon a (std::cin);
    std:: cout << "The area of your figure is : " << a.Area() << std:: endl;

    Pentagon b (std::cin);
    std:: cout << "The area of your figure is : " << b.Area() << std:: endl;

    Pentagon c (std::cin);
    std:: cout << "The area of your figure is : " << c.Area() << std:: endl;

    //Pentagon d (std::cin);
    //std:: cout << "The area of your figure is : " << d.Area() << std:: endl;

    //Pentagon e (std::cin);
    //std:: cout << "The area of your figure is : " << e.Area() << std:: endl;

    //lab8
    TLinkedList list;
    std:: cout << "Is list empty? " << list.Empty() << std:: endl;
    list.InsertFirst(a);
    std:: cout << "And now, is tree empty? " << list.Empty() << std:: endl;
    list.InsertLast(b);
    list.InsertLast(c);
    std:: cout << "The length of your list is: " << list.Length() << std:: endl;
    std:: cout << list;
    return 0;
}
