#pragma once
#include "header.h"

void initialize(int &);
void checkInt(int &);

class Key {
   int key;
public:
   static int comparisons;
   Key(int x);
   int the_key() const;
};

//  Declare overloaded comparison operators for keys.
  bool operator ==(const Key &x, const Key &y);
  bool operator > (const Key &x, const Key &y);
  bool operator < (const Key &x, const Key &y);
  bool operator >=(const Key &x, const Key &y);
  bool operator <=(const Key &x, const Key &y);
  bool operator !=(const Key &x, const Key &y);

  typedef Key Record;

template <typename Record>
class SortableList : public List<Record> {
public:
    Error_code sequential_search(const List<Record> &the_list,const Key &target, int &);
    int getComparisons() const;
private:
};

template<typename Record>
void sequentialSearch(SortableList<Record> &slist, const Key& key);






// Method's and Function's definitions

template<typename Record>
Error_code SortableList<Record>::sequential_search(const List<Record> &the_list, const Key &target, int &dest)
/*
Post: If an entry in the_list has key equal to target, then return
      success and the output parameter position locates such an entry
      within the list.
      Otherwise, return not_present and position becomes invalid.
*/
{
    int s = the_list.size();
    for (dest = 0; dest < s; dest++) {
        Record data;
        the_list.retrieve(dest, data);
        if (operator==(target, data)) return success;
        //if (data == target) return success;
    }
    return not_present;
}

template<typename Record>
int SortableList<Record>::getComparisons() const {
    return Key::comparisons;
}

template<typename Record>
void sequentialSearch(SortableList<Record> &sList, const Key& key) {
    Error_code check;
    int listSize {50}, pos;
    Random rand;
    for (int i = 0; i < listSize; i++) {
        sList.insert(i, rand.random_integer(1, 100));
    }
    check = sList.sequential_search(sList, 174, pos);
    if (check == success) {
        std::cout << "Found in position: " << pos << std::endl;
        std::cout << "Comparisons: " << sList.getComparisons() << std::endl;
    } else {
        std::cout << "Sorry, no hits" << std::endl;
        std::cout << "Comparisons: " << sList.getComparisons() << std::endl;
    }
}


