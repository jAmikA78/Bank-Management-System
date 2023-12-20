/*
Project Description:-
This project manages the bank activities. The bank has many branches. Each
branch has basic information (ID, Name, Manager). The bank deals with many
account holders and each holder may have many accounts. Each holder has
basic information (ID, Name, Address, Balance). Create a C++ program using
two singly Linked Lists to perform the following functions.

1- For Branches:-
a. Add new branch in sorted order bi id.
b. Display Branch.
c. Search for Branch by ID.
d- Remove Branch.

2- For Account Holders:-
a. Add new holder in sordet holder by balance.
b. Remove a holder.
c. Display holder data.
d. Search for holder by Name.
e. Update Holder Information.
f. Given a Branch id, display Holders in that Branch.
g. Display holders of a branch ordered by their balances.

*/

/// code of the project

/// include libraries what we need in this project

#include <iostream>
#include <fstream>

using namespace std;

// define bransh struct
struct branch
{
    string id, name, manager;
    branch *next;
};

// define holder struct
struct holder
{
    string branch_id, id, name, address;
    double balance;
    holder *next;
};

struct list_of_branshs
{
    branch *head;

   
};

struct list_of_holders
{
    holder *head;

    
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

