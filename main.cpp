#include <iostream>
#include "include/Table.h"
#include "src/Table.cpp"

/*
Task 24
a)
u(n) element O(n²)
n/n² -> 0 -> wahr

v(n) element O(n)
n/n -> 1 -> wahr

beide wahr -> wahr

u(n)+v(n)*n element O(n²)
(n+n²)/n² -> unendlich -> falsch

-> Aus etwas wahrem etwas falsches folgern -> falsch

b)
u(n) element Ω(n⁴)
n/n³ -> 0 -> wahr

u(n)*n element Ω(n⁴)
n²/n⁴ -> 0 -> wahr

v(n) = u(n)*n element Ω(n⁴)
v(n) wächst unbeschrankt, rechte seite konvergent gegen 0 -> falsch

-> aus etwas wahrem etwas falsches folgern -> falsch
*/

int main()
{
    Table<int> myTable = Table<int>();

    //extra space for valgrind and gdb readability;
    std::cout << "\n";
    //get table size
    for(int i = 0; i < 5; i++)
    {
        myTable.insert(i);
        myTable.first();
    }
    for(int i = -1; i > -5; i--)
        myTable.append(i);

    std::cout << "initial state:\n";
    myTable.print();
    std::cout <<"\n";

    myTable.first();
    myTable.next();
    myTable.next();
    myTable.previous();
    myTable.next();
    myTable.next();
    
    int container = 0;
    myTable.get_node(container);
    std::cout << "entry value is: " << container << std::endl;

    std::cout << "setting entry value to 27\n";
    container = 27;
    myTable.set_node(container);
    myTable.get_node(container);
    std::cout <<"\n";

    myTable.print();
    myTable.first();
    myTable.delete_node();
    std::cout <<"\n";
    std::cout << "deleting first entry\n";
    
    myTable.print();
    myTable.last();
    myTable.delete_node();
    std::cout <<"\n";
    std::cout << "deleting last entry\n";

    myTable.print();
    myTable.first();
    myTable.next();
    myTable.next();
    myTable.next();
    myTable.delete_node();
    std::cout <<"\n";
    std::cout << "deleting middle entry\n";
    
    std::cout << "final state:\n";
    myTable.print();

    //extra space for valgrind and gdb readability;
    std::cout << "\n";
    return 0;
}