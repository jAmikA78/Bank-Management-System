#include <bits/stdc++.h>
#include <fstream>
#include "holderl.h"
#include "branchl.h"
#include "GUI.h"

using namespace std;

void restore_branches_data();

void restore_holders_data();

void store_branches_data();

void store_holders_data();

int main() {
    restore_branches_data();
    restore_holders_data();
    using_system();
    store_branches_data();
    store_holders_data();
    return 0;
}

/// ---------------------------------------------- function to restore from database
void restore_branches_data() {
    ifstream branches_data("branches_data.txt");
    if (!branches_data) {
        cerr << "Error opening branches_data.txt" << endl;
        return;
    }
    string id, name, manager;
    while (branches_data >> id >> name >> manager)
        branchLIST.insert_at_beginning(id, name, manager);

    branches_data.close();
}

void restore_holders_data() {
    ifstream holders_data("holders_data.txt");
    if (!holders_data) {
        cerr << "Error opening holders_data.txt" << endl;
        return;
    }

    string id, name, address, branch_id, balance;
    while (holders_data >> id >> name >> address >> branch_id >> balance)
        holderLIST.insert_at_last(id, name, address, branch_id, balance);

    holders_data.close();
}

void store_branches_data() {
    ofstream branches_data("branches_data.txt", ios::trunc);
    if (!branches_data) {
        cerr << "Error opening branches_data.txt for output" << endl;
        return;
    }
    branch *temp = branchLIST.head;
    while (temp != nullptr) {
        branches_data << temp->id << ' ' << temp->name << ' ' << temp->manager << '\n';
        temp = temp->next;
    }
    branches_data.close();
}

void store_holders_data() {
    ofstream holders_data("holders_data.txt", ios::trunc);
    if (!holders_data) {
        cerr << "Error opening holders_data.txt for output" << endl;
        return;
    }

    holder *temp = holderLIST.head;
    while (temp != nullptr) {
        holders_data << temp->id << ' ' << temp->name << ' ' << temp->address <<
                     ' ' << temp->branch_id << ' ' << temp->balance << '\n';
        temp = temp->next;
    }
    holders_data.close();
}
