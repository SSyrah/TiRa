#ifndef LIST_H
#define LIST_H
#pragma once
#include "Utility.h"

const int max_list = 20;

//Task 1 methods:
template<class List_entry, class List>
Error_code insert_first(const List_entry &x, List &a_list);
template<class List_entry, class List>
Error_code remove_first(List_entry &x, List &a_list);
template<class List_entry, class List>
Error_code insert_last(const List_entry &x, List &a_list);
template<class List_entry, class List>
Error_code remove_last(List_entry &x, List &a_list);
template<class List_entry, class List>
Error_code median_list(List_entry &x, List &a_list);
template<class List, class List_entry>
Error_code interchange(int pos1, int pos2, List &a_list);
template<class List_entry, class List>
void reverse_traverse_list(List &a_list, void (*visit)(List_entry &));
template<class List>
Error_code copy(List &dest, List &source);
template<class List>
Error_code join(List &list1, List &list2);
template<class List>
void reverse(List &a_list);
template<class List>
Error_code split(List &source, List &oddlist, List &evenlist);


template <class List_entry>
class List {
public:
//  methods of the List ADT
    List();
    int size() const;
    bool full() const;
    bool empty() const;
    void clear();
    void traverse(void (*visit)(List_entry &));
    Error_code retrieve(int position, List_entry &x) const;
    Error_code replace(int position, const List_entry &x);
    Error_code remove(int position, List_entry &x);
    Error_code insert(int position, const List_entry &x);

protected:
//  data members for a contiguous list implementation
    int count;
    List_entry entry[max_list];
};


template<class List_entry>
List<List_entry>::List(){
    count = 0;
    for (int i = 0; i<max_list; i++)
        entry[i] = NULL;
}

template <class List_entry>
int List<List_entry>::size() const
/*
Post: The function returns the number of entries in the List.
*/
{
    return count;
}

template <class List_entry>
bool List<List_entry>::full() const{
    return count == max_list;
}

template<class List_entry>
bool List<List_entry>::empty()const {
    return count == 0;
}

template<class List_entry>
void List<List_entry>::clear() {
    for (int i = 0; i<max_list; i++)
        entry[i] = NULL;
        count = 0;
}

template<class List_entry>
Error_code List<List_entry>::retrieve(int position, List_entry &x) const {
    if (position < 0 || position > count)
        return utility_range_error;
    x = entry[position];
    return success;
}

template<class List_entry>
Error_code List<List_entry>::replace(int position, const List_entry &x){
    if (position < 0 || position > count)
        return utility_range_error;
    entry[position] = x;
    return success;
}

template<class List_entry>
Error_code List<List_entry>::remove(int position, List_entry &x){
    if (empty())
        return underflow;
    if (position < 0 || position > count)
        return utility_range_error;

    x = entry[position];
    for (int i = position; i<=count; i++){
        entry[i] = entry[i+1];
    }
    std::cout << "Count value: " << count << std::endl;
    count--;
    return success;
}

template <class List_entry>
Error_code List<List_entry>::insert(int position, const List_entry &x)
/*
Post: If the List is not full and 0 <= position <= n,
      where n is the number of entries in the List, the function succeeds:
      Any entry formerly at position and all later entries have their
      position numbers increased by 1 and x is inserted at position of the List.
      Else: The function fails with a diagnostic error code.
*/
{
    if (full())
        return overflow;

    if (position < 0 || position > count)
        return utility_range_error;

    for (int i = count - 1; i >= position; i--)
        entry[i + 1] = entry[i];

    entry[position] = x;
    count++;
    return success;
}
template <class List_entry>
void List<List_entry>::traverse(void (*visit)(List_entry &))
/*
Post: The action specified by function (*visit) has been performed on every
      entry of the List, beginning at position 0 and doing each in turn.
*/
{
    for (int i = 0; i < count; i++)
        (*visit)(entry[i]);
}

// Task 1 methods

//E1
template<class List_entry, class List>
Error_code insert_first(const List_entry &x, List &a_list){
    if (a_list.full()) return overflow;
    a_list.entry[0] = x;
    return success;
}

//E2
template<class List_entry, class List>
Error_code remove_first(List_entry &x, List &a_list){

    a_list.remove(0 , x);
    return success;
}
//E3
template<class List_entry, class List>
Error_code insert_last(const List_entry &x, List &a_list){

    if(a_list.full()) return overflow;
    a_list.entry[a_list.count+1] = x;
    return success;

}

//E4
template<class List_entry, class List>
Error_code remove_last(List_entry &x, List &a_list){
   
    a_list.remove(a_list.size(), x);
    return success;
}

//E5
template<class List_entry,class List>
Error_code median_list(List_entry &x, List &a_list) {
    int median = 0;
    if (a_list.empty()) return underflow;
    if (a_list.size() % 2 == 0){
        median = a_list.size() / 2 - 1;
    }
    else{
        median = a_list.size() / 2;
    }
    x = a_list.entry[median];
    return success;
}

//E6
template<class List, class List_entry>
Error_code interchange(int pos1, int pos2, List &a_list){
    if (a_list.count < 2) return utility_range_error;
    List_entry temp;
    temp = a_list.entry[pos1];
    a_list.entry[pos1] = a_list.entry[pos2];
    a_list.entry[pos2] = temp;
    return success;
}

//E7
template<class List_entry, class List>
void reverse_traverse_list(List &a_list, void (*visit)(List_entry &)){
    //code...

}

template<class List>
Error_code copy(List &dest, List &source){
    if (dest.empty() || source.empty()) return underflow;
    for (int i = 0; i<dest.count; i++){
        source.entry[i] = dest.entry[i];
    }
    return success;
}

//E8
template<class List>
Error_code join(List &dest, List &source){
    int j = 0;
    if ((max_list - dest.count) < source.count) return overflow;
    for (int i = dest.count+1; i <=(dest.count+1+(source.count));i++){
        dest.entry[i] = source.entry[j];
        j++;
    }
    dest.count += source.count;
    return success;
}

template<class List, class List_entry>
void reverse(List &a_list){
    List_entry temp;
    for (int i = 0; i<a_list.count; i++){
        temp = a_list.entry[i];
        a_list.entry[i] = a_list.entry[i+1];
        a_list.entry[i+1] = temp;
    }
}

template<class List>
Error_code split(List &source, List &oddlist, List &evenlist){
    if (source.empty()) return underflow;

    for (int i = 0; i<source.count; i++){
        if (source.entry[i] % 2 == 0){
            evenlist.insert(source.entry[i]);
            evenlist.count++;
        }
        else {
            oddlist.insert(source.entry[i]);
            oddlist.count++;
        }
    }
}
#endif