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



/*
Task 26
table:
    insert:
        keine schleifen -> ca. konstante laufzeit (n paar if/else)
        daher O(1)
        speicheraufwand: 1 node (1 * item_type, 2 * pointer)
    delete:
        keine schleifen -> ca. konstante laufzeit (n paar if/else)
        daher O(1)
        keine zusätzlichen speicheraufwände

array:
    insert:
        for-loop von array-ende bis iterator -> potenziell n
        daher O(n)
        speicheraufwand: 1 array-eintrag (1 * item_type) + evtl array resize
    delete:
        for-loop von iterator bis array ende -> potenziell n 
        daher O(n)
        keine zusätzlichen speicheraufwände

    => Doppelt verkettete list besitzt deutlich schnellere laufzeit für insert/delete
    => Doppelt verkettete liste benutzt etwas mehr speicher pro eintrag (2 zusätzliche pointer)
        -> relativ vernachlässigbar außer bei abertausenden pointern (beispiel int: 8 bytes pro eintrag)
        -> bei implementation mit automatischem array-resize kann das array größer ausfallen als benötigt!
*/



int main()
{
    //create a new table
    Table<int> myTable = Table<int>();

    //extra space for valgrind and gdb readability;
    std::cout << "\n";

    //fill table with +4 to -4
    for(int i = 0; i < 5; i++)
    {
        myTable.insert(i);
        myTable.first();
    }
    for(int i = -1; i > -5; i--)
        myTable.append(i);

    //print out the initial state after filling
    std::cout << "initial state:\n";
    myTable.print();
    std::cout <<"\n";

    //move back and forth a bit
    myTable.first();
    myTable.next();
    myTable.next();
    myTable.previous();
    myTable.next();
    myTable.next();
    
    //read a value and return it
    int container = 0;
    myTable.get_node(container);
    std::cout << "entry value is: " << container << std::endl;

    //write a value, then read it to verify
    std::cout << "setting entry value to 27\n";
    container = 27;
    myTable.set_node(container);
    myTable.get_node(container);
    std::cout <<"\n";
    myTable.print();

    //delete the first entry
    myTable.first();
    myTable.delete_node();
    std::cout <<"\n";
    std::cout << "deleting first entry\n";
    myTable.print();
    
    //delete the last entry
    myTable.last();
    myTable.delete_node();
    std::cout <<"\n";
    std::cout << "deleting last entry\n";
    myTable.print();

    //delete the middle entry (technically the fourth, but in this case middle)
    myTable.first();
    myTable.next();
    myTable.next();
    myTable.next();
    myTable.delete_node();
    std::cout <<"\n";
    std::cout << "deleting middle entry\n";
    myTable.print();

    //extra space for valgrind and gdb readability;
    std::cout << "\n";
    return 0;
}