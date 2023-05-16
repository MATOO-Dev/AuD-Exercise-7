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

    //extra space for valgrind readability;
    std::cout << "\n";
    //get table size

    myTable.append(0);
    myTable.append(2);
    myTable.append(1);

    std::cout << "initial state:\n";
    myTable.print();
    std::cout <<"\n";

    myTable.last();
    //myTable.next();

    std::cout << "attempting to delete first entry\n\n";
    myTable.delete_node();
    myTable.print();
    std::cout << "\nattempting to delete another entry\n\n";
    myTable.last();
    myTable.delete_node();
    myTable.print();
    //std::cout << "\nattempting to delete final entry\n\n";
    //myTable.last();
    //myTable.delete_node();
    
    std::cout << "final state:\n";
    myTable.print();

    //extra space for valgrind and gdb readability;
    std::cout << "\n";
    return 0;
}