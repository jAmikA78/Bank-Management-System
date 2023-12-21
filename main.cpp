/// Project Description:-
/*
This project manages the bank activities. The bank has many branches. Each
branch has basic information (ID, Name, Manager). The bank deals with many
account holders and each holder may have many accounts. Each holder has
basic information (ID, Name, Address, Balance).
*/

/// what admin can do
/*
║ 1. Add new branch
║ 2. Display Branch
║ 3. Remove Branch
║ 4. Add new holder
║ 5. Remove a holder
║ 6. Display holder data
║ 7. Search for holder by Name
║ 8. Update Holder Information
║ 9. display Holders of a Branch by id
║ 10. Logout

note that
=====================
admin password = 1234
=====================

*/

/// what member can do
/*
║ 1. Display holder data
║ 2. Search for holder by Name
║ 3. Add new holder
║ 4. Logout                                                                               ║                             ║
*/

/// basic information
/*
===========================================
all data will be stored in a local Database
===========================================
holders will be stored in sorted order by balance
===========================================
*/

#include "GUI.h"
#include "datab.h"

using namespace std;


int main() {
    start_system();
    using_system();
    end_system();
    return 0;
}

