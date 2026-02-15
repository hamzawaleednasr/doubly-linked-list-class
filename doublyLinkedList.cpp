#include <iostream>
#include <string>
#include "doubleLinkedList.h"

using namespace std;

int main()
{
    doubleLinkedList<int> myList;

    auto show = [&](const string& msg) {
        cout << msg;
        myList.print();
        cout << "\n";
    };

    // Build initial list (final order: 10 20 30 40 50)
    for (int v : {50, 40, 30, 20, 10})
        myList.insertAtBegining(v);
    show("Initial list: ");

    // find and insert after a node
    auto n1 = myList.find(30);
    cout << (n1 ? "Found :-)\n" : "Not Found :-(\n");
    myList.insertAfter(n1, 35);
    show("After insertAfter(node(30), 35): ");

    // append at end
    myList.insertAtEnd(60);
    show("After insertAtEnd(60): ");

    // delete by value
    myList.deleteNode(20);
    show("After deleteNode(20): ");

    // delete first and last
    myList.deleteFirstNode();
    show("After deleteFirstNode(): ");
    myList.deleteLastNode();
    show("After deleteLastNode(): ");

    cout << "The size = " << myList.size() << "\n";

    // empty the list
    while (!myList.isEmpty())
        myList.deleteFirstNode();
    cout << (myList.isEmpty() ? "The list is empty\n" : "The list is NOT empty\n");

    // populate with 1..5
    for (int i = 1; i <= 5; ++i)
        myList.insertAtEnd(i);
    show("Inserted 1..5 at end: ");

    // clear then repopulate and reverse
    myList.clear();
    cout << "The size after clear is = " << myList.size() << "\n";

    for (int i = 1; i <= 5; ++i)
        myList.insertAtEnd(i);
    show("Repopulated 1..5: ");

    myList.reverse();
    show("After reverse: ");

    // safe getNode
    auto n = myList.getNode(4);
    if (n)
        cout << "The value is = " << n->value << "\n";
    else
        cout << "getNode(4) returned null\n";

    // access elements using at() with exception handling (at() may throw)
    try {
        for (int i = 0; i < myList.size(); ++i)
            cout << "at(" << i << ") = " << myList.at(i) << "\n";
    }
    catch (const exception& e) {
        cout << "Exception while accessing by index: " << e.what() << "\n";
    }

    // update and insert
    myList.updateItem(2, 300);
    show("After updateItem(2, 300): ");

    myList.insertAfter(1, 200);
    show("After insertAfter(1, 200): ");

    return 0;
}
