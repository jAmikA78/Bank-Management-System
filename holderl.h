#ifndef UNTITLED1_HOLDERL_H
#define UNTITLED1_HOLDERL_H

#include <iostream>
#include "branchl.h"

using namespace std;

class holder{
public:
    string id, name, address, branch_id;
    string balance;
    holder *next;

    holder(){
        id = name = address = branch_id = "";
        balance = "";
        next = NULL;
    }
};


class holderList{
public:
    holder *holders_head = NULL;
    holder *holders_last = NULL;

    // ========================================================================
    // HOLDERS FUNCTIONS

    // Check if no branches exist
    bool isEmptyHolders() {
        if (holders_head == NULL)
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

        if (holders_head == NULL || (holders_head)->balance >= newnode->balance) {
            newnode->next = holders_head;
            holders_head = newnode;
            return;
        }

        holder *temp = holders_head;
        while (temp->next != NULL && temp->next->balance < newnode->balance)
            temp = temp->next;

        newnode->next = temp->next;
        temp->next = newnode;
    }

    // Search a holder by name & id
    bool searchHolderName(string holder_name) {
        holder *temp = holders_head;
        while (temp != NULL) {
            if (temp->name == holder_name) return true;
            else temp = temp->next;
        }
        return false;
    }
    holder searchHolderNameAndPrint(string holder_name) {
        holder *temp = holders_head;
        while (temp != NULL) {
            if (temp->name == holder_name) return *temp;
            else temp = temp->next;
        }
        holder notFound;
        notFound.id = "-1";
        return notFound;
    }

    bool searchHolderID(string holder_id) {
        holder *temp = holders_head;
        while (temp != NULL) {
            if (temp->id == holder_id) return true;
            else temp = temp->next;
        }
        return false;
    }
    holder searchHolderIDAndPrint(string holder_id) {
        holder *temp = holders_head;
        while (temp != NULL) {
            if (temp->id == holder_id) return *temp;
            else temp = temp->next;
        }
        holder notFound;
        notFound.id = "-1";
        return notFound;
    }

    // Remove a holder.
    bool deleteHolder(string holder_id) {
        if (holders_head == NULL){
            cout << "Not Founded\n";
            return false;
        }

        // list has only one element
        if (holders_head->next == NULL){
            if (holders_head->id == holder_id)
            {
                delete holders_head;
                holders_head = NULL;
                return true;
            }
            else
                return false;
        }

        // search for element by id
        holder *cur = holders_head;
        while (cur->next != NULL && cur->next->id != holder_id)
            cur = cur->next;
        if (cur->next == NULL){
            return false;
        }
        delete cur->next;
        cur->next = NULL;
    }

    // Display holder data.
    void displayHoldersAll() {
        holder *temp = holders_head;
        while (temp != NULL) {
            cout << "Holder ID: " << temp->id << " Holder's name: " << temp->name << " Holder's manager: "
                 << temp->address << " Balance: " << temp->balance << "\nbelongs to the branch with id: "
                 << temp->branch_id << '\n';

            temp = temp->next;
//            cout << "=================================\n";
        }
//        cout << "=================================\n";
    }

    // Update Holder Information.
    bool UpdateHolder(string id, string name, string address, string branch_id, string balance){
        deleteHolder(id);
        insertSorted(id, name, address, branch_id, balance);
    }

    // ========================================================================
    // Additional Functions

    // Display Holders in a branch
    void displayBranchHolders(string branch_id){
        holder *temp = holders_head;
        while (temp != NULL) {
            if(temp->branch_id == branch_id) {
                cout << "*Holder ID: " << temp->id << "| Holder's name: " << temp->name << "| Holder's manager: "
                     << temp->address << "| Balance: $" << temp->balance << '\n';
            }
            temp = temp->next;
        }
//        cout << "=================================\n";
    }

    // Remove a branch
    void RemoveBranchAndHolders(string branch_id){
        if(deleteBranch(branch_id)){
            holder* current = holders_head;
            holder* prev = NULL;

            while (current != NULL) {
                if (current->branch_id == branch_id) {
                    // If it's the head node, update head
                    if (prev == NULL)
                        holders_head = current->next;
                    else
                        prev->next = current->next;

                    holder *temp = current;
                    current = current->next;
                    delete temp;
                } else
                    prev = current, current = current->next;
            }
        }
        else
            cout << "This branch id doesn't exist\n";
    }

};

#endif //UNTITLED1_HOLDERL_H
