#ifndef UNTITLED1_GUI_H
#define UNTITLED1_GUI_H

#include <bits/stdc++.h>
#include<cstdlib>
#include <conio.h>
#include <windows.h>
#include "branchl.h"
#include "holderl.h"

using namespace std;

struct Branch {
    char id[15], name[30], manager[50];
} bd;
struct Holder {
    char id[30], name[30], address[30], branch_id[30], balance[30];
} hd;

branchList branchLIST;
holderList holderLIST;

///  ------------------------------------ Functions Declaration
void SetColor(int FontColor);

void ClearConsoleToColors(int FontColor, int BackColor);

void SetColorAndBackground();

void posXY(int x, int y);

void boxBorder();

void window();

void PageTitle(const string &title);

void clearWindow();

void addBranch();

void displayBranch();

void searchBranch();

void addHolder();

void removeHolder();

void displayHolder();

void searchHolder();

void searchHolderName();

void updateHolder();

void displayBranchHolders();

void removeBranch();

void login();

void first_window();

void main_window();

void main_window2();


/*------- Main Function -------*/
void using_system() {
    ClearConsoleToColors(0, 0);
    SetConsoleTitle("Bank Management System - BMS");
    window();
    first_window();
    return;
}

void main_window() {
    ClearConsoleToColors(0, 0);
    SetConsoleTitle("Bank Management System - BMS");
    window();
    boxBorder();
    SetColor(28);
    int choice;
    int x = 2;
    while (true) {
        posXY(x, 8);
        cout << "1. Add new branch";
        posXY(x, 9);
        cout << "2. Display Branch";
        posXY(x, 10);
        cout << "3. Remove Branch";
        posXY(x, 11);
        cout << "4. Add new holder";
        posXY(x, 12);
        cout << "5. Remove a holder";
        posXY(x, 13);
        cout << "6. Display holder data";
        posXY(x, 14);
        cout << "7. Search for holder by Name";
        posXY(x, 15);
        cout << "8. Update Holder Information";
        posXY(x, 16);
        cout << "9. display Holders of a Branch by id";
        posXY(x, 17);
        cout << "10. Logout";
        posXY(x, 20);
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addBranch();
                break;
            case 2:
                displayBranch();
                break;
            case 3:
                removeBranch();
                break;
            case 4:
                addHolder();
                break;
            case 5:
                removeHolder();
                break;
            case 6:
                displayHolder();
                break;
            case 7:
                searchHolderName();
                break;
            case 8:
                updateHolder();
                break;
            case 9:
                displayBranchHolders();
                break;
            case 10:
                clearWindow();
                system("cls");
                window();
                first_window();
                break;
            default:
                return;
        }
    }
    return;
}

void main_window2() {
    ClearConsoleToColors(0, 0);
    SetConsoleTitle("Bank Management System - BMS");
    window();
    boxBorder();
    SetColor(28);
    int choice;
    int x = 2;
    while (true) {
        posXY(x, 8);
        cout << "1. Display holder data";
        posXY(x, 9);
        cout << "2. Search for holder by Name";
        posXY(x, 10);
        cout << "3. Add new holder";
        posXY(x, 11);
        cout << "4. Logout";
        posXY(x, 20);
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                displayHolder();
                break;
            case 2:
                searchHolderName();
                break;
            case 3:
                addHolder();
                break;
            case 4:
                clearWindow();
                system("cls");
                window();
                first_window();
                break;
            default:
                return;
        }
    }
}

///  ------------------------------------ Welcome Page
void login() {
    ClearConsoleToColors(0, 0);
    SetConsoleTitle("Bank Management System - BMS");
    window();
    boxBorder();
    SetColor(1028);
    int x = 15, y = 16;
    char password[25];
    char adminPassword[25] = "1";
    posXY(25, 12);
    cout << "The database is password protected.";
    posXY(25, 13);
    cout << "Enter valid administrator password.";
    SetColor(17);
    posXY(30, x);
    cout << "USERNAME:- administrator";
    posXY(30, y);
    cout << "PASSWORD:- ";
    posXY(41, y);
    int p = 0;
    do {
        password[p] = getch();
        if (password[p] != '\r') {
            printf("*");
        }
        p++;
    } while (password[p - 1] != '\r');
    password[p - 1] = '\0';

    if (strcmp(adminPassword, password) == 0) {
        system("cls");
        window();
        main_window();
    } else {
        system("cls");
        window();
        posXY(20, 18);
        cout << "Invalid Password. Try again." << endl;
        login();
    }
}

void first_window() {
    ClearConsoleToColors(0, 0);
    SetConsoleTitle("Bank Management System - BMS");
    window();
    boxBorder();
    SetColor(28);
    int choice;
    int posX = 2, posY = 10;
    while (true) {
        posXY(posX, posY += 2);
        cout << "1. Sign in as Administrator";
        posXY(posX, posY += 2);
        cout << "2. Use as holder";
        posXY(posX, 20);
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                login();
                break;
            case 2:
                main_window2();
                break;
            default:
                return;
        }
    }
}
void addBranch() {
    clearWindow();
    SetColor(10);
    PageTitle(" -- Add Branch -- ");
    char branch_id[15];

    int posX = 45, posY = 10;
    posXY(posX, posY += 2);
    cout << "ID: ";
    fflush(stdin);
    gets(branch_id);

    if (strlen(branch_id) != 4) {
        posXY(posX, posY += 2);
        SetColor(1028);
        cout << "ID must be 4 characters";
    } else {
        if (branchLIST.searchBranchID(branch_id)) {
            posXY(posX, posY += 2);
            SetColor(1028);
            cout << "Information already exist.";
        } else {
            fflush(stdin);
            strcpy(bd.id, branch_id);
            posXY(posX, posY += 2);
            cout << "Name: ";
            gets(bd.name);
            posXY(posX, posY += 2);
            cout << "Manager: ";
            gets(bd.manager);
            SetColor(10);
            posXY(posX, posY += 2);
            cout << "Information is added successfully.";
            branchLIST.insert_at_beginning(branch_id, bd.name, bd.manager);
        }
    }

    SetColor(28);
}

void displayBranch() {
    clearWindow();
    SetColor(10);
    PageTitle(" -- Display Branch info -- ");
    char branch_id[15];
    int print = 40;
    posXY(print, 10);
    cout << "Enter ID: ";
    fflush(stdin);
    gets(branch_id);
    branch info = branchLIST.searchBranchAndPrint(branch_id);
    if (info.id != "-1") {
        posXY(print, 12);
        cout << "Information is Found.";
        posXY(print, 14);
        cout << "ID: " << info.id;
        posXY(print, 15);
        cout << "Name: " << info.name;
        posXY(print, 16);
        cout << "Manager: " << info.manager;
    } else {
        posXY(print, 12);
        SetColor(1028);
        cout << "Sorry, Information not found.";
    }
    SetColor(28);
}

void removeBranch() { // this one needs to be handled correctly in the file (handled in the linked list)
    clearWindow();
    SetColor(10);
    PageTitle(" -- Delete a branch by its id -- ");
    char n_id[15];
    int print = 37;
    posXY(print, 10);
    cout << "Enter ID: ";
    fflush(stdin);
    gets(n_id);
    posXY(print, 12);
    if (branchLIST.deleteBranch(n_id)) {
        SetColor(10);
        cout << "Information is deleted successfully.";
        holderLIST.remove_all_holders(n_id);
    } else {
        SetColor(1028);
        cout << "Branch doesnt exist.";
    }
    SetColor(28);
}

void addHolder() {
    clearWindow();
    SetColor(10);
    PageTitle(" -- Add Holder -- ");
    int print = 40;
    posXY(print, 10);
    cout << "ID: ";
    fflush(stdin);
    gets(hd.id);
    if (!holderLIST.searchHolderID(hd.id)) {
        fflush(stdin);
        strcpy(hd.id, hd.id);
        posXY(print, 12);
        cout << "Name: ";
        gets(hd.name);
        posXY(print, 14);
        cout << "Address: ";
        gets(hd.address);
        posXY(print, 16);
        cout << "Branch ID: ";
        gets(hd.branch_id);
        posXY(print, 18);
        if (!branchLIST.searchBranchID(hd.branch_id))
            cout << "branch holder_id doesnt exist.";
        else {
            cout << "Balance: ";
            gets(hd.balance);
            SetColor(10);
            posXY(print, 20);
            cout << "Information is added successfully.";
            holderLIST.insertSorted(hd.id, hd.name, hd.address, hd.branch_id, hd.balance);
        }
    }
    SetColor(28);
}

void removeHolder() {
    clearWindow();
    SetColor(10);
    PageTitle(" -- Delete a holder by his id -- ");
    char holder_id[15];
    int print = 40;
    posXY(print, 10);
    cout << "Enter ID: ";
    fflush(stdin);
    gets(holder_id);
    posXY(print, 12);
    if (holderLIST.deleteHolder(holder_id)) {// O(holder)
        SetColor(10);
        cout << "Information is deleted successfully.";
    }
    else {
        SetColor(1028);
        cout << "Holder doesnt exist.";
    }
    SetColor(28);
}

void displayHolder() {
    clearWindow();
    SetColor(10);
    PageTitle(" -- Display Holder info -- ");
    char n_id[15];
    posXY(37, 10);
    cout << "Enter ID: ";
    fflush(stdin);
    gets(n_id);
    holder info = holderLIST.searchHolderIDAndPrint(n_id); // O(n)
    if (info.id != "-1") {
        posXY(40, 12);
        cout << "Information is Found.";
        posXY(40, 14);
        cout << "ID: " << info.id;
        posXY(40, 15);
        cout << "Name: " << info.name;
        posXY(40, 16);
        cout << "Address: " << info.address;
        posXY(40, 17);
        cout << "Branch ID: " << info.branch_id;
        posXY(40, 18);
        cout << "Balance: $" << info.balance;
    } else {
        posXY(40, 12);
        SetColor(1028);
        cout << "Sorry, Information not found.";
    }
    SetColor(28);
}

void searchHolderName() {
    clearWindow();
    SetColor(10);
    PageTitle(" -- Search Holder info -- ");
    char n_name[15];
    posXY(37, 10);
    cout << "Enter Name: ";
    fflush(stdin);
    gets(n_name);
    holder info = holderLIST.searchHolderNameAndPrint(n_name); // O(n)
    if (info.id != "-1") {
        posXY(40, 12);
        cout << "Information is Found.";
        posXY(40, 14);
        cout << "ID: " << info.id;
        posXY(40, 15);
        cout << "Name: " << info.name;
        posXY(40, 16);
        cout << "Address: " << info.address;
        posXY(40, 17);
        cout << "Branch ID: " << info.branch_id;
        posXY(40, 18);
        cout << "Balance: $" << info.balance;
    } else {
        posXY(40, 12);
        SetColor(1028);
        cout << "Sorry, Information not found.";
    }
    SetColor(28);
}

// NOT DONE YET
void updateHolder() {
    clearWindow();
    SetColor(10);
    PageTitle(" -- Update Holder -- ");
    int print = 37;
    char n_id[15];
    posXY(37, 10);
    cout << "ID: ";
    fflush(stdin);
    gets(n_id);
    if (holderLIST.searchHolderID(n_id)) { // O(holder)
        fflush(stdin);
        strcpy(hd.id, n_id);
        posXY(print, 12);
        cout << "New Name: ";
        gets(hd.address);
        posXY(print, 14);
        cout << "New Address: ";
        gets(hd.address);
        posXY(print, 16);
        cout << "New Branch ID: ";
        gets(hd.branch_id);
        posXY(print, 18);
        if (!branchLIST.searchBranchID(hd.branch_id)) {
            SetColor(1028);// O(branch)
            cout << "branch id doesnt exist.";
        } else {
            cout << "New Balance: ";
            gets(hd.balance);
            posXY(print, 20);
            if(holderLIST.UpdateHolder(hd.id, hd.name, hd.address, hd.branch_id, hd.balance)) {
                SetColor(10);
                cout << "Information is updated successfully.";
            }
            else{
                SetColor(1028);
                cout << "couldnt update data.";
            }
        }

    } else {
        posXY(37, 12);
        cout << "ID Doest Exist.";
    }
    SetColor(28);
}

void displayBranchHolders() {
    clearWindow();
    SetColor(10);
    PageTitle(" -- Display Holder info -- ");
    char branch_id[15];
    posXY(37, 10);
    cout << "Enter Branch ID: ";
    fflush(stdin);
    gets(branch_id);
    if (branchLIST.searchBranchID(branch_id)) {
        holder *temp = holderLIST.head;
        int y_pos = 12;
        while (temp != nullptr) { // I wrote this function here cuz I couldn't handle it in the .h file
            if (temp->branch_id == branch_id) {
                posXY(40, y_pos += 2);
                cout << "*Holder ID: " << temp->id << "| Holder's name: " << temp->name << "| Holder's address: "
                     << temp->address << "| Balance: $" << temp->balance << '\n';
            }
            temp = temp->next;
        }
    } else {
        posXY(40, 12);
        cout << "Sorry, Information not found.";
    }
    SetColor(28);
}

///  ------------------------------------ Set Colors
void SetColor(int FontColor) {
    WORD wColor;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE consoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
    if (GetConsoleScreenBufferInfo(consoleColor, &csbi)) {
        wColor = (csbi.wAttributes & 0xF0) + (FontColor & 0x0F);
        SetConsoleTextAttribute(consoleColor, wColor);
    }
}

///  ------------------------------------ Clear Console And Put Colors
void ClearConsoleToColors(int FontColor, int BackColor) {
    WORD wColor = ((BackColor & 0x0F) << 4) + (FontColor & 0x0F);
    HANDLE consoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Coordinate = {0, 0};
    DWORD count;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    SetConsoleTextAttribute(consoleColor, wColor);
    if (GetConsoleScreenBufferInfo(consoleColor, &csbi)) {
        FillConsoleOutputCharacter(consoleColor, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, Coordinate, &count);
        FillConsoleOutputAttribute(consoleColor, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, Coordinate, &count);
        SetConsoleCursorPosition(consoleColor, Coordinate);
    }
}

///  ------------------------------------ Put Colors
void SetColorAndBackground(int FontColor, int BackColor) {
    WORD wColor = ((BackColor & 0x0F) << 4) + (FontColor & 0x0F);;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}

///  ------------------------------------ Manage Coordinates
COORD Coordinate = {0, 0};

void posXY(int x, int y) {
    Coordinate.X = x;
    Coordinate.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coordinate);
}

///  ------------------------------------ Build Window
void window() {
    boxBorder();
    SetColor(11);
    posXY(35, 3);
    cout << "Bank Management System";
}

///  ------------------------------------ Page Header
void PageTitle(const string &title) {
    SetColor(10);
    SetColorAndBackground(3, 0);
    posXY(53, 8);
    cout << title;
    SetColorAndBackground(15, 0);
}

///  ------------------------------------ Clear Window
void clearWindow() {
    for (int i = 37; i < 78; i++)
        for (int j = 7; j < 25; j++)
            posXY(i, j), cout << " ";
}

///  ------------------------------------ Box Border
void boxBorder() {

    SetColor(8);

    posXY(0, 0), wcout << (wchar_t) 201;
    for (int i = 1; i < 90; i++) { posXY(i, 0), wcout << (wchar_t) 205; }

    posXY(90, 0), wcout << wchar_t(187);

    for (int i = 1; i < 25; i++) {
        posXY(90, i);
        if (i == 6) wcout << (wchar_t) 185;
        else wcout << (wchar_t) 186;
    }

    posXY(90, 25), wcout << (wchar_t) 188;

    for (int i = 89; i > 0; i--) { posXY(i, 25), wcout << (wchar_t) 205; }

    posXY(0, 25), wcout << (wchar_t) 200;

    for (int i = 24; i > 0; i--) {
        posXY(0, i);
        if (i == 6) wcout << (wchar_t) 204;
        else wcout << (wchar_t) 186;
    }

    for (int i = 1; i < 90; i++) { posXY(i, 6), wcout << (wchar_t) 205; }
}

#endif //UNTITLED1_GUI_H


//        a. Add new branch.
//        h. Remove Branch.
//        b. Display Branch.
//        c. Search for Branch by ID.
//        =====================================================
//        a. Add new holder.
//        b. Remove a holder.
//        c. Display holder data.
//        d. Search for holder by Name.
//        e. Update Holder Information.
//        f. display Holders of a Branch by id.

/*------- Function Declaration -------*/


/*------- Menu -------*/

//        a. Add new branch.                        done
//        h. Remove Branch.                         done
//        b. Display Branch.                        done
//        c. Search for Branch by ID.               done
//        ==================================================
//        a. Add new holder.                        done
//        b. Remove a holder.                       done
//        c. Display holder data.                   done
//        d. Search for holder by Name.             done
//        e. Update Holder Information.             done
//        f. display Holders of a Branch by id.     NOT DONE
