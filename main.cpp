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

using namespace std;

void restore_branches_data();
void restore_holders_data();
void system_control();
void store_branches_data();
void store_holders_data();

// main function

int main() {
    restore_branches_data();
    restore_holders_data();
    system_control();
    store_branches_data();
    store_holders_data();
    return 0;
}


// function to using system
void system_control() {
    // here is the main code of my system
}

// function to restore old data base
void restore_branches_data() {
    // Read input from branches database
    ifstream branches_data("branches_data.txt");
    if (!branches_data) {
        cerr << "Error opening branches_data.txt" << endl;
        return;
    }

    // Your code to process input from branches_data goes here

    // Close branches_data
    branches_data.close();

    //_____________________________________________________________________
}

void restore_holders_data() {
    // Read input from holders_data
    ifstream holders_data("holders_data.txt");
    if (!holders_data) {
        cerr << "Error opening holders_data.txt" << endl;
        return;
    }
    // Your code to process input from holders_data goes here

    // Close holders_data
    holders_data.close();
}

// store the final database
void store_branches_data() {
    // Step 5: Store the output in branches_data
    ofstream branches_data("branches_data.txt");
    if (!branches_data) {
        cerr << "Error opening branches_data.txt for output" << endl;
        return; // Exit with an error code
    }

    // Your code to write output to branches_data goes here

    // Close branches_data
    branches_data.close();
}

void store_holders_data() {
    //  Store the remaining input in holders_data
    ofstream holders_data("holders_data.txt");
    if (!holders_data) {
        cerr << "Error opening holders_data.txt for output" << endl;
        return; // Exit with an error code
    }

    // Your code to write output to holders_data goes here

    // Close holders_data
    holders_data.close();
}
