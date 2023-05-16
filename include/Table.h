#pragma once
#include <iostream>

template <class item_type>
class Table
{
    struct node
    {
        item_type value = 0;
        node* next = nullptr;
        node* previous = nullptr;
    };

private:
    node* head;
    node* tail;
    node* iterator;
    uint size = 0;

public:
    Table();
    ~Table();
    bool insert(item_type r);
    bool append(item_type r);
    bool first();
    bool last();
    bool next();
    bool previous();
    bool delete_node();
    bool get_node(item_type& r);
    bool set_node(item_type& r);
    uint length();
    void print();

    //todo: add special cases
    //1) table is empty
};