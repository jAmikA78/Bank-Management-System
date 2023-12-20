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
        next = NULL;
    }
};

class branchList{
public:
    branch *branch_head = NULL;
    branch *branch_last = NULL;

    // ========================================================================
    // BRANCH FUNCTIONS

    // Check if no branches exist
    bool isEmptyBranches() {
        if (branch_head == NULL)
            return true;
        else
            return false;
    }

    branch getHeadBranch(){
        return *branch_head;
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
    bool searchBranchID(string branch_id) {
        branch *temp = branch_head;

        while (temp != NULL) {
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

};

#endif //UNTITLED1_BRANCHL_H
