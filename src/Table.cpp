#include "../include/Table.h"

template <class item_type>
Table<item_type>::Table()
{
    //set pointers to null
    head = nullptr;
    tail = nullptr;
    iterator = nullptr;
}

template <class item_type>
Table<item_type>::~Table()
{
    //iterate over table to delete all entries
    first();
    while(iterator != nullptr)
    {
        delete_node();
        iterator = tail;
    }
}

#pragma region addNode

template <class item_type>
bool Table<item_type>::insert(item_type r)
{
    //special case if table is empty
    if(size == 0)
    {
        //create node and assign value
        node* item = new node();
        item->value = r;

        //assign pointers
        head = item;
        tail = item;
        iterator = item;
        item->previous = nullptr;
        item->next = nullptr;

        //increase size
        size++;
        return true;
    }

    //if pointers are not valid, cancel
    if(iterator == nullptr || tail == nullptr)
        return false;
    
    //create new node and assign its value
    node* item = new node();
    item->value = r;
    
    //set node references
    item->previous = iterator->previous;
    item->next = iterator;

    //retarget references for surrounding nodes
    if(iterator != tail)
        iterator->previous->next = item;
    iterator->previous = item;

    //update table size
    size++;

    //if iterator is tail, also retarget tail
    if(iterator == tail)
        tail = item;

    return true;
}

template <class item_type>
bool Table<item_type>::append(item_type r)
{
    //special case if table is empty
    if(size == 0)
    {
        node item;
        item.value = r;
        head = &item;
        tail = &item;
        iterator = &item;
        return true;
    }

    //if pointers are not valid, cancel
    if(head == nullptr)
        return false;

    //create new node and assign its value
    node item;
    item.value = r;
    
    //set node references
    item.previous = head;
    item.next = nullptr;

    //retarget reference for current head
    head->next = &item;

    //retarget head
    head = &item;

    //update table size
    size++;

    return true;
}

#pragma endregion

#pragma region moveIterator

template <class item_type>
bool Table<item_type>::first()
{
    if(tail == nullptr)
        return false;
    //retarget iterator to tail
    iterator = tail;
    return true;
}

template <class item_type>
bool Table<item_type>::last()
{
    if(head == nullptr)
        return false;

    //retarget iterator to head
    iterator = head;
    return true;
}

template <class item_type>
bool Table<item_type>::next()
{
    //move iterator to next node, unless its the head
    if(iterator != head)
    {
        iterator = iterator->next;
        return true;
    }
    //return false if iterator was already head
    return false;
}

template <class item_type>
bool Table<item_type>::previous()
{
    //move iterator to previous node, unless its the tail
    if(iterator != tail)
    {
        iterator = iterator->previous;
        return true;
    }
    //return false if iterator was already tail
    return false;
}

#pragma endregion

template <class item_type>
bool Table<item_type>::delete_node()
{
    if(size == 0 || iterator == nullptr)
        return false;

    //retarget surrounding nodes
    //case for middle nodes (default)
    if(iterator != tail && iterator != head)
    {
        iterator->previous->next = iterator->next;
        iterator->next->previous = iterator->previous;
    }
    //case for iterator being tail
    if(iterator == tail)
    {
        //retarget new tail
        if(size > 1)
        {
            iterator->next->previous = nullptr;
            tail = iterator->next;
        }
        //if this is the last element, set to nullptr instead
        else
            tail = nullptr;
    }
    //case for iterator being head
    if(iterator == head)
    {
        //retarget new head
        if(size > 1)
        {
            iterator->previous->next = nullptr;
            head = iterator->previous;
        }
        //if this is the last element, set to nullptr instead
        else
            head = nullptr;
    }

    //free iterator memory
    delete iterator;
    iterator = nullptr;

    //update table size
    size--;

    return true;
}

#pragma region getSet

template <class item_type>
bool Table<item_type>::get_node(item_type& r)
{
    if(iterator == nullptr)
        return false;
    r = iterator->value;
    return true;
}

template <class item_type>
bool Table<item_type>::set_node(item_type& r)
{
    if(iterator == nullptr)
        return false;
    iterator->value = r;
    return true;
}

template <class item_type>
uint Table<item_type>::length()
{
    return size;
}

template <class item_type>
void Table<item_type>::print()
{
    std::cout << "size: " << size << std::endl;
    node* current = tail;
    while(current != nullptr)
    {
        std::cout << "node: " << current << ", value: " << current->value << "\n";
        if(current == head)
            break;
        current = current->next;
    }
}

#pragma endregion