#ifndef UNTITLED1_HOLDERL_H
#define UNTITLED1_HOLDERL_H

#include <iostream>
#include "branchl.h"

using namespace std;

class holder {
public:
    string id, name, address, branch_id;
    string balance;
    holder *next;

    holder() {
        id = name = address = branch_id = "";
        balance = "";
        next = nullptr;
    }
};


class holderList {
public:
    holder *head = nullptr;
    holder *last = nullptr;

    // Check if no branches exist
    bool isEmptyHolders() {
        if (head == nullptr)
            return true;
        else
            return false;
    }

    // Add a holder to a branch
    void insertSorted(string id, string name, string address, string branch_id, string balance) {
        holder *newnode = new holder();
        newnode->id = id;
        newnode->name = name;
        newnode->address = address;
        newnode->balance = balance;
        newnode->branch_id = branch_id;

        //list is empty
        if (head == nullptr) {
            head = newnode;
            last = newnode;
            return;
        }

        if (head->balance >= newnode->balance) {
            newnode->next = head;
            head = newnode;
            return;
        }

        holder *temp = head;
        while (temp->next != nullptr && temp->next->balance < newnode->balance)
            temp = temp->next;
        newnode->next = temp->next;
        temp->next = newnode;

        // my new node is the last node
        if (newnode->next == nullptr)
            last = newnode;
    }

    // insert in the end to read old database
    void inser_at_last(string id, string name, string address, string branch_id, string balance) {
        holder *newnode = new holder();
        newnode->id = id;
        newnode->name = name;
        newnode->address = address;
        newnode->balance = balance;
        newnode->branch_id = branch_id;

        //insert first element
        if (head == nullptr) {
            head = newnode;
            last = newnode;
        }

        last->next = newnode;
        last = newnode;
    }

    // Search a holder by name & id
    bool searchHolderName(string holder_name) {
        holder *temp = head;
        while (temp != nullptr) {
            if (temp->name == holder_name) return true;
            else temp = temp->next;
        }
        return false;
    }

    holder searchHolderNameAndPrint(string holder_name) {
        holder *temp = head;
        while (temp != nullptr) {
            if (temp->name == holder_name) return *temp;
            else temp = temp->next;
        }
        holder notFound;
        notFound.id = "-1";
        return notFound;
    }

    bool searchHolderID(string holder_id) {
        holder *temp = head;
        while (temp != nullptr) {
            if (temp->id == holder_id) return true;
            else temp = temp->next;
        }
        return false;
    }

    holder searchHolderIDAndPrint(string holder_id) {
        holder *temp = head;
        while (temp != nullptr) {
            if (temp->id == holder_id) return *temp;
            else temp = temp->next;
        }
        holder notFound;
        notFound.id = "-1";
        return notFound;
    }

    // delete a holder.
    bool deleteHolder(string holder_id) {
        if (head == nullptr) {
            cout << "Not Founded\n";
            return false;
        }

        // list has only one element
        if (head->next == nullptr) {
            if (head->id == holder_id) {
                delete head;
                head = nullptr;
                last = nullptr;
                return true;
            } else
                return false;
        }

        // search for element by id
        holder *cur = head;
        while (cur->next != nullptr && cur->next->id != holder_id)
            cur = cur->next;
        if (cur->next == nullptr) {
            return false;
        }
        delete cur->next;
        cur->next = nullptr;
        last = cur;
    }

    // Display holder data.
    void displayHoldersAll() {
        holder *temp = head;
        while (temp != nullptr) {
            cout << "Holder ID: " << temp->id << " Holder's name: " << temp->name << " Holder's manager: "
                 << temp->address << " Balance: " << temp->balance << "\nbelongs to the branch with id: "
                 << temp->branch_id << '\n';

            temp = temp->next;
//            cout << "=================================\n";
        }
//        cout << "=================================\n";
    }

    // Update Holder Information.
    bool UpdateHolder(string id, string name, string address, string branch_id, string balance) {
        deleteHolder(id);
        insertSorted(id, name, address, branch_id, balance);
    }

    // ========================================================================
    // Additional Functions

    // Display Holders in a branch
    void displayBranchHolders(string branch_id) {
        holder *temp = head;
        while (temp != nullptr) {
            if (temp->branch_id == branch_id) {
                cout << "*Holder ID: " << temp->id << "| Holder's name: " << temp->name << "| Holder's manager: "
                     << temp->address << "| Balance: $" << temp->balance << '\n';
            }
            temp = temp->next;
        }
//        cout << "=================================\n";
    }

    // Remove all branch holders
    void remove_all_holders(string branch_id) {

        holder *current = head;
        holder *prev = nullptr;

        while (current != nullptr) {
            if (current->branch_id == branch_id) {
                // If it's the head node, update head
                if (prev == nullptr)
                    head = current->next;
                else
                    prev->next = current->next;

                holder *temp = current;
                current = current->next;
                delete temp;
            } else
                prev = current, current = current->next;
        }

    }

};

#endif //UNTITLED1_HOLDERL_H
