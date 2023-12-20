/*
Project Description:-
This project manages the bank activities. The bank has many branches. Each
Branch has basic information (ID, Name, Manager). The bank deals with many
account holders and each Holder may have many accounts. Each Holder has
basic information (ID, Name, Address, Balance). Create a C++ program using
two singly Linked Lists to perform the following functions.

1- For Branches:-
a. Add new Branch in sorted order bi id.
b. Display Branch by ID.
c. Display all Branchs.
d. Search for Branch by ID.
e- Remove Branch by ID.

2- For Account Holders:-
a. Add new Holder in sordet Holder by balance.
b. Remove a Holder.
c. Display Holder data.
d. Search for Holder by Name.
e. Update Holder Information.
f. Given a Branch id, display Holders in that Branch.
g. Display holders of a Branch ordered by their balances.

*/

/// code of the project

/// include libraries what we need in this project

#include <iostream>
#include <fstream>

using namespace std;

// define bransh struct
struct Branch
{
    string id, name, manager;
    Branch *next;
    Branch(string ID, string Name, string Manager)
    {
        id = ID;
        name = Name;
        manager = Manager;
        next = NULL;
    }
};

// define Holder struct
struct Holder
{
    string branch_id, id, name, address;
    double balance;
    Holder *next;

    Holder(string B_id, string ID, string Name, string Address, double Balance)
    {
        branch_id = B_id;
        id = ID;
        name = Name;
        address = Address;
        balance = Balance;
        next = NULL;
    }
};

struct list_of_branshs
{
    Branch *head;
    Branch *last;

    // add new branch (in sorted order by id)
    void add_branch(string ID, string Name, string Manager)
    {
        Branch *temp = new Branch(ID, Name, Manager);
        if (head == NULL || temp->id < head->id)
        {
            temp->next = head;
            head = temp;
            if (last == NULL)
                last = temp;
            return;
        }
        Branch *cur = head;
        while (cur->next != NULL && cur->next->id < temp->id)
            cur = cur->next;
        temp->next = cur->next;
        cur->next = temp;
        if (temp->next == NULL)
            last = temp;
    }

    // disblay branch by id
    void disblay_bransh(string id)
    {
        Branch *cur = head;
        while (cur != NULL)
        {
            if (cur->id == id)
            {
                cout << "Branch ID = " << cur->id << '\n';
                cout << "Branch Name = " << cur->name << '\n';
                cout << "Branch Manger = " << cur->manager << '\n';
                return;
            }
            cur = cur->next;
        }
        cout << "Not Founded\n";
        return;
    }

    // display all of the branchs
    void disblay_all()
    {
        if (head == NULL)
        {
            cout << "There is no branches to display\n";
            return;
        }
        Branch *cur = head;
        cout << "--------------------------------------------------\n";
        while (cur != NULL)
        {
            cout << "Branch ID = " << cur->id << '\n';
            cout << "Branch Name = " << cur->name << '\n';
            cout << "Branch Manger = " << cur->manager << '\n';
            cout << "--------------------------------------------------\n";
            cur = cur->next;
        }
    }

    // Search for Branch by ID.
    bool search_branch(string id)
    {
        if (head == NULL)
            return false;
        Branch *cur = head;
        while (cur != NULL)
        {
            if (cur->id == id)
                return true;
        }
        return false;
    }

    // remove branch by id
    void remove_branch(string id)
    {
        if (head == NULL)
        {
            cout << "Not Founded\n";
            return;
        }
        if (head->next == NULL)
        {
            if (head->id == id)
            {
                delete head;
                head = NULL;
                last = NULL;
            }
            else
                cout << "Not Founded\n";
            return;
        }
        Branch *cur = head;
        while (cur->next != NULL && cur->next->id != id)
            cur = cur->next;
        if (cur->next == NULL)
        {
            cout << "Not Founded\n";
            return;
        }
        if (cur->next->next == NULL)
            last = cur;
        delete cur->next;
        cur->next = NULL;
    }
};

struct list_of_holders
{
    Holder *head;
    Holder *last;
};

// function to useing system
void system()
{
    // here is the main code of my system
}

// function to restore old data base
void restore_branches_data()
{
    // Read input from branches data base
    ifstream branchs_data("branchs_data.txt");
    if (!branchs_data)
    {
        cerr << "Error opening branchs_data.txt" << endl;
        return;
    }

    // Your code to process input from branchs_data goes here

    // Close branchs_data
    branchs_data.close();

    //_____________________________________________________________________
}
void restore_holders_data()
{
    // Read input from holders_data
    ifstream holders_data("holders_data.txt");
    if (!holders_data)
    {
        cerr << "Error opening holders_data.txt" << endl;
        return;
    }
    // Your code to process input from holders_data goes here

    // Close holders_data
    holders_data.close();
}

// store the final data base
void store_branches_data()
{
    // Step 5: Store the output in branchs_data
    ofstream branchs_data("branchs_data.txt");
    if (!branchs_data)
    {
        cerr << "Error opening branchs_data.txt for output" << endl;
        return; // Exit with an error code
    }

    // Your code to write output to branchs_data goes here

    // Close branchs_data
    branchs_data.close();
}
void store_holders_data()
{
    //  Store the remaining input in holders_data
    ofstream holders_data("holders_data.txt");
    if (!holders_data)
    {
        cerr << "Error opening holders_data.txt for output" << endl;
        return; // Exit with an error code
    }

    // Your code to write output to holders_data goes here

    // Close holders_data
    holders_data.close();
}

// main function

int main()
{
    restore_branches_data();
    restore_holders_data();
    system();
    store_branches_data();
    store_holders_data();
    return 0;
}
