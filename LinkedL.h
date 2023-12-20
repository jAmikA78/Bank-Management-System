#ifndef UNTITLED1_LINKEDL_H
#define UNTITLED1_LINKEDL_H

#include <iostream>

using namespace std;

class holder{
public:
    string id, name, address, branch_id;
    string balance;
    holder *next;

    holder(){
        id = name = address = branch_id = "";
        balance = "";
        next = nullptr;
    }
};

class branch{
public:
    string id, name, manager;
    branch *next;

    branch(){
        id = name = manager = "";
        next = nullptr;
    }
};

class LinkedList{
public:
    branch *branch_head = nullptr;
    holder *holders_head = nullptr;

    // ========================================================================
    // BRANCH FUNCTIONS

    // Check if no branches exist
    bool isEmptyBranches() {
        if (branch_head == nullptr)
            return true;
        else
            return false;
    }

    branch getHeadBranch(){
        return *branch_head;
    }
    holder getHeadHolder(){
        return *holders_head;
    }

    // Add a branch
    void insertatend(string id, string name, string manager)
    {
//        branch *newnode=new branch();
//        newnode->id = id, newnode->name = name,
//        newnode->manager = manager, newnode->next= nullptr;
//
//        branch *temp=branch_head;
//        while (temp->next != nullptr)
//            temp=temp->next;
//        temp->next=newnode;
        branch *newnode=new branch();
        newnode->id = id, newnode->name = name,
        newnode->manager = manager, newnode->next= nullptr;
        if(isEmptyBranches())
        {
            newnode->next=nullptr;
            branch_head=newnode;
        }
        else
        {
            newnode->next=branch_head;
            branch_head=newnode;
        }
    }

    // Display a branch
    void displayBranches() {
        branch *temp = branch_head;
        while (temp != nullptr) {
            cout << "Branch id: " << temp->id << " Name: " << temp->name << " Manager: " << temp->manager << '\n';
            temp = temp->next;
        }
        cout << "=================================\n";
    }

    // Search for branch by id
    bool search_branch(string branch_id) {
        branch *temp = branch_head;
        while (temp != nullptr) {
            if (temp->id == branch_id) return true;
            else temp = temp->next;
        }
        return false;
    }

    branch searchBranchAndPrint(string branch_id) {
        branch *temp = branch_head;

        while (temp != nullptr) {
            if (temp->id == branch_id) return *temp;
            else temp = temp->next;
        }
        branch notFound;
        notFound.id = "-1";
        return notFound;
    }
    bool searchBranchID(string branch_id) {
        branch *temp = branch_head;

        while (temp != nullptr) {
            if (temp->id == branch_id) return true;
            else temp = temp->next;
        }
        return false;
    }

    // delete a branch

    bool deleteBranch(string branch_id) {
        if (isEmptyBranches()) return false;
        else if (search_branch(branch_id)) {
            branch *temp1 = branch_head;
            branch *prev = nullptr;
            if (branch_head->id == branch_id) {
                branch_head = branch_head->next;
                delete temp1;
            }
            else {
                prev = temp1;
                temp1 = temp1->next;
                while (prev->next != nullptr) {
                    if(!(temp1->id == branch_id))
                        prev = temp1, temp1 = temp1->next;
                    else
                        break;
                }
                prev->next = temp1->next;
                delete (temp1);
            }
            return true;
        }
        else return false;
    }

    // END OF BRANCH FUNCTIONS
    // ========================================================================

    // ========================================================================
    // HOLDERS FUNCTIONS

    // Check if no branches exist
    bool isEmptyHolders() {
        if (holders_head == nullptr)
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

        if (holders_head == nullptr || (holders_head)->balance >= newnode->balance) {
            newnode->next = holders_head;
            holders_head = newnode;
            return;
        }

        holder *temp = holders_head;
        while (temp->next != nullptr && temp->next->balance < newnode->balance)
            temp = temp->next;

        newnode->next = temp->next;
        temp->next = newnode;
    }

    // Search a holder by name & id
    bool searchHolderName(string holder_name) {
        holder *temp = holders_head;
        while (temp != nullptr) {
            if (temp->name == holder_name) return true;
            else temp = temp->next;
        }
        return false;
    }
    holder searchHolderNameAndPrint(string holder_name) {
        holder *temp = holders_head;
        while (temp != nullptr) {
            if (temp->name == holder_name) return *temp;
            else temp = temp->next;
        }
        holder notFound;
        notFound.id = "-1";
        return notFound;
    }

    bool searchHolderID(string holder_id) {
        holder *temp = holders_head;
        while (temp != nullptr) {
            if (temp->id == holder_id) return true;
            else temp = temp->next;
        }
        return false;
    }
    holder searchHolderIDAndPrint(string holder_id) {
        holder *temp = holders_head;
        while (temp != nullptr) {
            if (temp->id == holder_id) return *temp;
            else temp = temp->next;
        }
        holder notFound;
        notFound.id = "-1";
        return notFound;
    }

    // Remove a holder.
    bool deleteHolder(string holder_id) {
        if (holders_head == nullptr){
            cout << "Not Founded\n";
            return false;
        }

        // list has only one element
        if (holders_head->next == nullptr){
            if (holders_head->id == holder_id)
            {
                delete holders_head;
                holders_head = nullptr;
                return true;
            }
            else
                return false;
        }

        // search for element by id
        holder *cur = holders_head;
        while (cur->next != nullptr && cur->next->id != holder_id)
            cur = cur->next;
        if (cur->next == nullptr){
            return false;
        }
        delete cur->next;
        cur->next = nullptr;
    }

    // Display holder data.
    void displayHoldersAll() {
        holder *temp = holders_head;
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
    bool UpdateHolder(string id, string name, string address, string branch_id, string balance){
        deleteHolder(id);
        insertSorted(id, name, address, branch_id, balance);
    }

    // ========================================================================
    // Additional Functions

    // Display Holders in a branch
    void displayBranchHolders(string branch_id){
        holder *temp = holders_head;
        while (temp != nullptr) {
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
            holder* prev = nullptr;

            while (current != nullptr) {
                if (current->branch_id == branch_id) {
                    // If it's the head node, update head
                    if (prev == nullptr)
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
#endif //UNTITLED1_LINKEDL_H
