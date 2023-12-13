/*
Project Description:-
This project manages the bank activities. The bank has many branches. Each
branch has basic information (ID, Name, Manager). The bank deals with many
account holders and each holder may have many accounts. Each holder has
basic information (ID, Name, Address, Balance). Create a C++ program using
two singly Linked Lists to perform the following functions.

1- For Branches:-
a. Add new branch.
b. Display Branch.
c. Search for Branch by ID.
d. Given a Branch id, display Holders in that Branch.
e. Display holders of a branch ordered by their balances.
f- Remove Branch.

2- For Account Holders:-
a. Add new holder.
b. Remove a holder.
c. Display holder data.
d. Search for holder by Name.
e. Update Holder Information.

*/

/// code of the project

/// include libraries what we need in this project

#include <iostream>

using namespace std;

// define bransh struct

struct branch
{
    string id, name, manager;
    branch *next;
};
