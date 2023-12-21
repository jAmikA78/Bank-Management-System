/*
Project Description:-
This project manages the bank activities. The bank has many branches. Each
Branch has basic information (ID, Name, Manager). The bank deals with many
account holders and each Holder may have many accounts. Each Holder has
basic information (ID, Name, Address, Balance). Create a C++ program using
two singly Linked Lists to perform the following functions.

1- For Branches:-
a. Add new Branch in sorted order by id.
b. Display Branch by ID.
c. Display all Branches.
d. Search for Branch by ID.
e- Remove Branch by ID.

2- For Account Holders:-
a. Add new Holder in sorted Holder by balance.
b. Remove a Holder.
c. Display Holder data.
d. Search for Holder by Name.
e. Update Holder Information.
f. Given a Branch id, display Holders in that Branch.
g. Display holders of a Branch ordered by their balances.

*/

#include <iostream>
#include <fstream>
#include "holderl.h"
#include "branchl.h"
#include "GUI.h"
using namespace std;

void restore_branches_data();
void restore_holders_data();
void store_branches_data();
void store_holders_data();

// main function

int main() {
    restore_branches_data();
    restore_holders_data();
    using_system();
    store_branches_data();
    store_holders_data();
    return 0;
}

// function to restore old data base
void restore_branches_data() {
    ifstream branches_data("branches_data.txt");
    if (!branches_data) {
        cerr << "Error opening branches_data.txt" << endl;
        return;
    }


    branches_data.close();
}

void restore_holders_data() {
    ifstream holders_data("holders_data.txt");
    if (!holders_data) {
        cerr << "Error opening holders_data.txt" << endl;
        return;
    }


    holders_data.close();
}

void store_branches_data() {
    ofstream branches_data("branches_data.txt");
    if (!branches_data) {
        cerr << "Error opening branches_data.txt for output" << endl;
        return;
    }
    branch *temp = branchLIST.head;
    while (temp != nullptr) {
        branches_data << "Branch id: " << temp->id << " Name: " << temp->name << " Manager: " << temp->manager << '\n';
        temp = temp->next;
    }
    branches_data.close();
}

void store_holders_data() {
    ofstream holders_data("holders_data.txt");
    if (!holders_data) {
        cerr << "Error opening holders_data.txt for output" << endl;
        return;
    }


    holders_data.close();
}
