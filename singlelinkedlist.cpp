#include <iostream>
#include <string.h>
using namespace std;

class node 
{
    public :
        int noMhs;
        node *next;

};

class linkedlist 
{
    node *START;

public :
    linkedlist()
    {
        START = NULL;
    }

    void addnote()
    {
        int nim;
        cout << "\nMasukkan nomor mahasiswa: ";
        cin >> nim;

        node *nodebaru = new node;
        nodebaru->noMhs = nim;

        if (START == NULL || nim <= START->noMhs )
        {
            if  ((START != NULL) && (nim == START->noMhs))
            {
                cout << "\nDuplikasi noMhs tidak dijinkan\n";
                return;
            }
            nodebaru->next = START;
            START = nodebaru;
            return;
            
        }

        node *previous = START;
        node *current = START;

        while ((current != NULL) && (nim >= current->noMhs))
        {
            if (nim == current-> noMhs )
            {
                cout << "\nDuplikasi noMhs tidak diijinkan\n";
                return;
            }
            previous = current;
            current = current->next;

        }

        nodebaru->next = current;
        previous->next = nodebaru;

    }

    bool listEmpty()
    {
        return (START == NULL);
    }

    bool search (int nim, node **previous, node **current)
    {
        *previous = START;
        *current = START;

        while ((*current != NULL) && (nim != (*current)-> noMhs))
        {
            *previous = *current;
            *current = (*current)->next;
        }

        return (*current != NULL);

    }

    bool delnode (int nim)
    {
        node *current, *previous;
        if (!search(nim, &previous, &current))
            return false;

        if (current == START)
            START = START->next;
        else
            previous->next = current->next;

        delete current ;
        return true ;

    }

    
}