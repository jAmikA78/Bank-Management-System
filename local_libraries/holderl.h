#ifndef UNTITLED1_HOLDERL_H
#define UNTITLED1_HOLDERL_H

#include <bits/stdc++.h>
#include "branchl.h"

using namespace std;

class holder {
public:
    string id, name, address, branch_id, balance;
    holder *next;

    holder() {
        id = name = address = branch_id = balance = "";
        next = nullptr;
    }
};


class holderList {
public:
    holder *head = nullptr;
    holder *last = nullptr;

    /// ----------------------------------------- Check if no branches
    bool isEmptyHolders() {
        if (head == nullptr) return true;
        else return false;
    }

    /// ----------------------------------------- Insert holder into branch
    void insertSorted(string id, string name, string address, string branch_id, string balance) {
        holder *newnode = new holder();
        newnode->id = id;
        newnode->name = name;
        newnode->address = address;
        newnode->balance = balance;
        newnode->branch_id = branch_id;

        /// ----------------------------------------- Check if list is empty
        if (head == nullptr) {
            head = newnode;
            last = newnode;
            return;
        }

        /// ----------------------------------------- If new item less than head.
        if (head->balance >= newnode->balance) {
            newnode->next = head;
            head = newnode;
            return;
        }

        /// ----------------------------------------- Traverse to insert sorted
        holder *temp = head;
        while (temp->next != nullptr && temp->next->balance < newnode->balance)
            temp = temp->next;
        newnode->next = temp->next;
        temp->next = newnode;

        /// ----------------------------------------- Check if insert at end -> edit last node
        if (newnode->next == nullptr)
            last = newnode;
    }

    /// ----------------------------------------- Insert at the end
    void insert_at_last(string id, string name, string address, string branch_id, string balance) {
        holder *newnode = new holder();
        newnode->id = id;
        newnode->name = name;
        newnode->address = address;
        newnode->balance = balance;
        newnode->branch_id = branch_id;
        newnode->next = nullptr;

        /// ----------------------------------------- If list is empty
        if (head == nullptr) {
            head = newnode;
            last = newnode;
        }

        last->next = newnode;
        last = newnode;
    }

    /// ----------------------------------------- Search a holder using name
    bool searchHolderName(string holder_name) {
        holder *temp = head;
        while (temp != nullptr) {
            if (temp->name == holder_name) return true;
            else temp = temp->next;
        }
        return false;
    }

    /// ----------------------------------------- Get all holders data using name
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

    /// ----------------------------------------- Check if user already inserted using ID
    bool searchHolderID(string holder_id) {
        holder *temp = head;
        while (temp != nullptr) {
            if (temp->id == holder_id) return true;
            else temp = temp->next;
        }
        return false;
    }

    /// ----------------------------------------- Search about user and if already inserted return all data
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

    /// ----------------------------------------- Delete holder if list isn't empty
    bool deleteHolder(string holder_id) {
        if (head == nullptr) {
            cout << "Not Founded\n";
            return false;
        }

        if (head->next == nullptr) { /// if list has one element
            if (head->id == holder_id) {
                delete head;
                head = nullptr;
                last = nullptr;
                return true;
            } else
                return false;
        }

    /// -----------------------------------------
        holder *temp = head;
        while (temp->next != nullptr && temp->next->id != holder_id)
            temp = temp->next;
        if (temp->next == nullptr) {
            return false;
        }
        delete temp->next;
        temp->next = nullptr;
        last = temp;
    }

    // Display holder data.
    void displayHoldersAll() {
        holder *temp = head;
        while (temp != nullptr) {
            cout << "Holder ID: " << temp->id << " Holder's name: " << temp->name << " Holder's manager: "
                 << temp->address << " Balance: " << temp->balance << "\nbelongs to the branch with id: "
                 << temp->branch_id << '\n';
            temp = temp->next;
        }
    }

    // Update Holder Information.
    bool UpdateHolder(string id, string name, string address, string branch_id, string balance) {
        if(deleteHolder(id)) {
            insertSorted(id, name, address, branch_id, balance);
            return true;
        }
        return false;
    }

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
    }

    // Remove all branch holders
    void remove_all_holders(string branch_id) {

        holder *cur = head;
        holder *prev = nullptr;

        while (cur != nullptr) {
            if (cur->branch_id == branch_id) {
                // If it's the head node, update head
                if (prev == nullptr)
                    head = cur->next;
                else
                    prev->next = cur->next;

                holder *temp = cur;
                cur = cur->next;
                delete temp;
            } else
                prev = cur, cur = cur->next;
        }

    }

};

#endif
