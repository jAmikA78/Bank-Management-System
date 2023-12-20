#include <bits/stdc++.h>
#include<cstdlib>
#include <conio.h>
#include <windows.h>
#include "LinkedL.h"

using namespace std;

struct Branch {
    char id[15], name[30], manager[50];
} bd;
struct Holder {
    char id[30], name[30], address[30], branch_id[30], balance[30];
} hd;
LinkedList l1;

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

void main_window();


/*------- Main Function -------*/
int main() {
    ClearConsoleToColors(0, 0);
    SetConsoleTitle("Bank Management System - BMS");
    window();
    login();
    return 0;
}

void main_window() {
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
                login();
                break;
            default:
                exit(0);
        }
    }
}

///  ------------------------------------ Welcome Page
void login() {
    boxBorder();
    SetColor(1028);
    int x = 15, y = 16;
    int username;
    char password[25];
    char mainPassword[25] = "123456";
    posXY(15, 12);
    cout << "The database is password protected.";
    posXY(15, 13);
    cout << "Enter valid administrator password.";
    SetColor(17);
    posXY(20, x);
    cout << "USERNAME:- administrator";
    posXY(20, y);
    cout << "PASSWORD:- ";
    posXY(34, y);
    int p = 0;
    do {
        password[p] = getch();
        if (password[p] != '\r') {
            printf("*");
        }
        p++;
    } while (password[p - 1] != '\r');
    password[p - 1] = '\0';

    if (strcmp(mainPassword, password) == 0) {
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


void addBranch() {
    clearWindow();
    string id, name, manager;
    SetColor(10);
    PageTitle(" -- Add Branch -- ");
    int print = 37;
    char n_id[15];
    int isFound = 0;
    posXY(37, 10);
    cout << "ID: ";
    fflush(stdin);
    gets(n_id);
    FILE *data;
    data = fopen("info.txt", "a+");
    if (strlen(n_id) != 9) {
        posXY(37, 12);
        cout << "ID must be 9 characters";
    } else {
        while (fread(&bd, sizeof(bd), 1, data) == 1) {
            if (strcmp(n_id, bd.id) == 0) {
                isFound = 1;
                posXY(37, 12);
                cout << "Information already exist.";
                break;
            }
        }
        if (isFound == 0) {
            if (data == nullptr) {
                MessageBox(0, "Error in Opening file.\nMake sure file is not write protected.", "Warning", 0);
            } else {
                fflush(stdin);
                strcpy(bd.id, n_id);
                posXY(print, 12);
                cout << "Name: ";
                gets(bd.name);
                posXY(print, 14);
                cout << "Manager: ";
                gets(bd.manager);
                posXY(print, 16);
                cout << "Information is added successfully.";
                l1.insertatend(n_id, bd.name, bd.manager);
            }
        }
    }
    SetColor(28);
    fclose(data);
}

void displayBranch() {
    clearWindow();
    SetColor(10);
    PageTitle(" -- Display Branch info -- ");
    char n_id[15];
    int isFound = 0;
    posXY(37, 10);
    cout << "Enter ID: ";
    fflush(stdin);
    gets(n_id);
    branch info = l1.searchBranchAndPrint(n_id);
    if (info.id != "-1") {
        posXY(37, 12);
        cout << "Information is Found.";
        posXY(37, 14);
        cout << "ID: " << info.id;
        posXY(37, 15);
        cout << "Name: " << info.name;
        posXY(37, 16);
        cout << "Manager: " << info.manager;
    } else {
        posXY(37, 12);
        cout << "Sorry, Information not found.";
    }
    SetColor(28);
}

void removeBranch() { // this one needs to be handled correctly in the file (handled in the linked list)
    clearWindow();
    SetColor(10);
    PageTitle(" -- Delete a branch by its id -- ");
    char n_id[15];
    int isFound = 0, print = 37;
    posXY(37, 10);
    cout << "Enter ID: ";
    fflush(stdin);
    gets(n_id);
    posXY(37, 12);
    if (l1.deleteBranch(n_id))
        cout << "Information is deleted successfully.";
    else
        cout << "Branch doesnt exist.";
    SetColor(28);
}

void addHolder() {
    clearWindow();
    string id, name, manager;
    SetColor(10);
    PageTitle(" -- Add Holder -- ");
    int print = 37;
    char n_id[15];
    int isFound = 0;
    posXY(37, 10);
    cout << "ID: ";
    fflush(stdin);
    gets(n_id);
    FILE *data;
    data = fopen("info.txt", "a+");

    while (fread(&bd, sizeof(bd), 1, data) == 1) { // check if id already exist
        if (strcmp(n_id, bd.id) == 0) {
            isFound = 1;
            posXY(37, 12);
            cout << "ID already exist.";
            break;
        }
    }
    if (isFound == 0) {
        if (data == nullptr) {
            MessageBox(nullptr, "Error in Opening file.\nMake sure file is not write protected.", "Warning", 0);
        } else {
            fflush(stdin);
            strcpy(hd.id, n_id);
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
            if (!l1.search_branch(hd.branch_id)) {
                cout << "branch id doesnt exist.";
            } else {
                cout << "Balance: ";
                gets(hd.balance);
                posXY(print, 20);
                cout << "Information is added successfully.";
                l1.insertSorted(n_id, hd.name, hd.address, hd.branch_id, hd.balance);
            }
        }
    }
    SetColor(28);
    fclose(data);
}

void removeHolder() {
    clearWindow();
    SetColor(10);
    PageTitle(" -- Delete a holder by his id -- ");
    char n_id[15];
    int isFound = 0, print = 37;
    posXY(37, 10);
    cout << "Enter ID: ";
    fflush(stdin);
    gets(n_id);
    posXY(37, 12);
    if (l1.deleteHolder(n_id))
        cout << "Information is deleted successfully.";
    else
        cout << "Holder doesnt exist.";
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
    holder info = l1.searchHolderIDAndPrint(n_id);
    if (info.id != "-1") {
        posXY(37, 12);
        cout << "Information is Found.";
        posXY(37, 14);
        cout << "ID: " << info.id;
        posXY(37, 15);
        cout << "Name: " << info.name;
        posXY(37, 16);
        cout << "Address: " << info.address;
        posXY(37, 17);
        cout << "Branch ID: " << info.branch_id;
        posXY(37, 18);
        cout << "Balance: " << info.balance;
    } else {
        posXY(37, 12);
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
    holder info = l1.searchHolderNameAndPrint(n_name);
    if (info.id != "-1") {
        posXY(37, 12);
        cout << "Information is Found.";
        posXY(37, 14);
        cout << "ID: " << info.id;
        posXY(37, 15);
        cout << "Name: " << info.name;
        posXY(37, 16);
        cout << "Address: " << info.address;
        posXY(37, 17);
        cout << "Branch ID: " << info.branch_id;
        posXY(37, 18);
        cout << "Balance: " << info.balance;
    } else {
        posXY(37, 12);
        cout << "Sorry, Information not found.";
    }
    SetColor(28);
}

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
    if (l1.searchHolderID(n_id)) {
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
        if (!l1.search_branch(hd.branch_id)) {
            cout << "branch id doesnt exist.";
        } else {
            cout << "New Balance: ";
            gets(hd.balance);
            posXY(print, 20);
            l1.UpdateHolder(hd.id, hd.name, hd.address, hd.branch_id, hd.balance);
            cout << "Information is updated successfully.";
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
    char n_id[15];
    posXY(37, 10);
    cout << "Enter Branch ID: ";
    fflush(stdin);
    gets(n_id);
    if (l1.searchBranchID(n_id)) {
        holder *temp = l1.holders_head;
        int place = 12;
        while (temp != nullptr) {
            if (temp->branch_id == n_id) {
                posXY(37, place += 2);
                cout << "*Holder ID: " << temp->id << "| Holder's name: " << temp->name << "| Holder's manager: "
                     << temp->address << "| Balance: $" << temp->balance << '\n';
            }
            temp = temp->next;
        }
    } else {
        posXY(37, 12);
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
    SetColor(12);
    posXY(35, 2);
    cout << "Bank Management System";
    SetColor(100);
    posXY(28, 3);
    cout << "=======================================";
}

///  ------------------------------------ Page Header
void PageTitle(const string &title) {
    SetColor(10);
    SetColorAndBackground(3, 0);
    posXY(45, 8);
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
