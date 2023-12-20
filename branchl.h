#ifndef UNTITLED1_BRANCHL_H
#define UNTITLED1_BRANCHL_H

#include <iostream>

using namespace std;


class branch{
public:
    string id, name, manager;
    branch *next;

    branch(){
        id = name = manager = "";
        next = nullptr;
    }
};

class branchList{
public:
    branch *head = nullptr;

    // Check if no branches exist
    bool isEmptyBranches() {
        if (head == nullptr)
            return true;
        else
            return false;
    }

    // Add a branch
    void insert_at_beginning(string id, string name, string manager)
    {
        branch *newnode=new branch();
        newnode->id = id, newnode->name = name,
        newnode->manager = manager, newnode->next= nullptr;
        if(head=nullptr)
        {
            newnode->next=nullptr;
            head=newnode;
        }
        else
        {
            newnode->next=head;
            head=newnode;
        }
    }

    // Display a branch
    void displayBranches() {
        branch *temp = head;
        while (temp != nullptr) {
            cout << "Branch id: " << temp->id << " Name: " << temp->name << " Manager: " << temp->manager << '\n';
            temp = temp->next;
        }
    }

    // Search for branch by id
    bool search_branch(string branch_id) {
        branch *temp = head;
        while (temp != nullptr) {
            if (temp->id == branch_id) return true;
            else temp = temp->next;
        }
        return false;
    }

    branch searchBranchAndPrint(string branch_id) {
        branch *temp = head;

        while (temp != nullptr) {
            if (temp->id == branch_id) return *temp;
            else temp = temp->next;
        }
        branch notFound;
        notFound.id = "-1";
        return notFound;
    }

    bool searchBranchID(string branch_id) {
        branch *temp = head;

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
            branch *temp1 = head;
            branch *prev = nullptr;
            if (head->id == branch_id) {
                head = head->next;
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

};

#endif //UNTITLED1_BRANCHL_H
