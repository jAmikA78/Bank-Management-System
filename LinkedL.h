#ifndef UNTITLED1_LINKEDL_H
#define UNTITLED1_LINKEDL_H

#include <iostream>

using namespace std;

class holder{
public:
    string id, name, address, branch_id;
    int balance;
    holder *next;

    holder(){
        id = name = address = branch_id = "";
        balance = 0;
        next = NULL;
    }
};

class branch{
public:
    string id, name, manager;
    branch *next;

    branch(){
        id = name = manager = "";
        next = NULL;
    }
};

class LinkedList{
public:
    branch *branch_head = NULL;
    holder *holders_head = NULL;

    // ========================================================================
    // BRANCH FUNCTIONS

    // Check if no branches exist
    bool isEmptyBranches() {
        if (branch_head == NULL)
            return true;
        else
            return false;
    }

    // Add a branch
    void insertatend(string id, string name, string manager)
    {
//        branch *newnode=new branch();
//        newnode->id = id, newnode->name = name,
//        newnode->manager = manager, newnode->next= NULL;
//
//        branch *temp=branch_head;
//        while (temp->next != NULL)
//            temp=temp->next;
//        temp->next=newnode;
        branch *newnode=new branch();
        newnode->id = id, newnode->name = name,
        newnode->manager = manager, newnode->next= NULL;
        if(isEmptyBranches())
        {
            newnode->next=NULL;
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
        while (temp != NULL) {
            cout << "Branch id: " << temp->id << " Name: " << temp->name << " Manager: " << temp->manager << '\n';
            temp = temp->next;
        }
        cout << "=================================\n";
    }

    // Search for branch by id
    bool search_branch(string branch_id) {
        branch *temp = branch_head;
        while (temp != NULL) {
            if (temp->id == branch_id) return true;
            else temp = temp->next;
        }
        return false;
    }

    branch searchBranchAndPrint(string branch_id) {
        branch *temp = branch_head;

        while (temp != NULL) {
            if (temp->id == branch_id) return *temp;
            else temp = temp->next;
        }
        branch notFound;
        notFound.id = "-1";
        return notFound;
    }

    // delete a branch

    bool deleteBranch(string branch_id) {
        if (isEmptyBranches()) return false;
        else if (search_branch(branch_id)) {
            branch *temp1 = branch_head;
            branch *prev = NULL;
            if (branch_head->id == branch_id) {
                branch_head = branch_head->next;
                delete temp1;
            }
            else {
                prev = temp1;
                temp1 = temp1->next;
                while (prev->next != NULL) {
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
        if (holders_head == NULL)
            return true;
        else
            return false;
    }

    // Add a holder to a branch
    void insertSorted(string id, string name, string address, string branch_id, int balance) {
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

    bool searchHolderID(string holder_id) {
        holder *temp = holders_head;
        while (temp != NULL) {
            if (temp->id == holder_id) return true;
            else temp = temp->next;
        }
        return false;
    }

    // Remove a holder.
    void deleteHolder(string holder_id) {
        if (isEmptyHolders()) cout << "THERE IS NO HOLDERS TO BE DELETED\n";
        else if (searchHolderID(holder_id)) {
            holder *temp1 = holders_head;
            holder *prev = NULL;
            if (holders_head->id == holder_id) {
                holders_head = holders_head->next;
                delete temp1;
            }
            else {
                prev = temp1;
                temp1 = temp1->next;
                while (prev->next != NULL) {
                    if(!(temp1->id == holder_id))
                        prev = temp1, temp1 = temp1->next;
                    else
                        break;
                }
                prev->next = temp1->next;
                delete (temp1);
            }
            cout << "HOLDER IS DELETED SUCCESSFULLY\n";
        }
        else cout << "HOLDER TO BE DELETED IS NOT FOUND\n";
    }

    // Display holder data.
    void displayHoldersAll() {
        holder *temp = holders_head;
        while (temp != NULL) {
            cout << "Holder ID: " << temp->id << " Holder's name: " << temp->name << " Holder's manager: " << temp->address << " Balance: " << temp->balance << "\nbelongs to the branch with id: " << temp->branch_id << '\n';
            temp = temp->next;
            cout << "=================================\n";
        }
        cout << "=================================\n";
    }

    // Update Holder Information.
    void UpdateHolder(string id, string name, string address, string branch_id, int balance){
        deleteHolder(id);
        insertSorted(id, name, address, branch_id, balance);
    }

    // ========================================================================
    // Additional Functions

    // Display Holders in a branch
    void displayBranchHolders(string branch_id){
        holder *temp = holders_head;
        while (temp != NULL) {
            if(temp->branch_id == branch_id)
                cout << "Holder ID: " << temp->id << " Holder's name: " << temp->name << " Holder's manager: " << temp->address << " Balance: $" << temp->balance << '\n';
            temp = temp->next;
        }
        cout << "=================================\n";
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
#endif //UNTITLED1_LINKEDL_H
