#ifndef SDDS_SHOPPINGLIST_H
#define SDDS_SHOPPINGLIST_H

// Your header file content goes here


namespace sdds {
    bool loadList();
    void displayList();
    void removeBoughtItems();
    void removeItem(int index);
    bool saveList();
    void clearList();
    void toggleBought();
    void addItemToList();
    void removeItemfromList();
    bool listIsEmpty();
}

#endif