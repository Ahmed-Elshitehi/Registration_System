/*
 * Ahmed Salah
 * 23 / 8 / 2023
 */
#include<iostream>
#include <set>
#include <map>
using namespace std;
set<pair<string, string>> data_base; // user name // password
map<string, pair<string, string>> informations; // user name --> {first name , lastname}
string inter_password(){
    string password;
    cout << "Password : ";
    TAKE_pass:
    getline(cin, password);
    if (password.empty()) {
        goto TAKE_pass;
    }
    return password;
}
void forget_password(string user_name) {
    string password;
    if (user_name.empty()) {
        cout << "\t\t user name : ";
        TAKE_user:
        getline(cin, user_name);
        if (user_name.empty()) {
            goto TAKE_user;
        }
    }
    if (data_base.lower_bound({user_name, ""})->first == user_name) {
        // taking password
        TAKE_Pass:
        cout << "\t\tNew ";
        password = inter_password();
        for (char i : password) { // check if the password have any spaces using simple for loop
            if (i == ' ') {
                cout << "\t\tpassword should not have spaces\n";
                goto TAKE_Pass;
            }
        }
        data_base.erase(data_base.lower_bound({user_name, ""}));
        data_base.insert({user_name, password});
        cout << "\t\tPassword Updated successfully \n";
    } else {
        cout << "\t\tincorrect username\n";
    }
}
void sign_UP() {
    string user_name, password, first_name, last_name;
    //taking user name
    TAKE_user_NAME:
    cout << "\t\t User Name : ";
    TAKE_user_NAME2:
    getline(cin, user_name);
    // chelk if this user name is already taken using lower bound for fast search in O(log n)
    if (data_base.lower_bound({user_name, ""})->first == user_name && !user_name.empty()) {
        cout << "\t\t this user name is already taken please inter new one\n";
        goto TAKE_user_NAME;
    }
    for (char i : user_name) { // check if the user name have any spaces using simple for loop
        if (i == ' ') {
            cout << "\t\tuser name should not have spaces\n";
            goto TAKE_user_NAME;
        }
    }
    if (user_name.empty()) {
        goto TAKE_user_NAME2;
    }
    //taking first name
    cout << "\t\t first Name : ";
    TAKE_NAME1:
    getline(cin, first_name);
    if (first_name.empty()) {
        goto TAKE_NAME1;
    }
    //taking last name
    cout << "\t\t last Name : ";
    TAKE_NAME2:
    getline(cin, last_name);
    if (last_name.empty()) {
        goto TAKE_NAME2;
    }
    // taking password
    TAKE_Pass:
    cout << "\t\t";
    password = inter_password();
    for (char i : password) { // check if the password have any spaces using simple for loop
        if (i == ' ') {
            cout << "\t\tpassword should not have spaces\n";
            goto TAKE_Pass;
        }
    }
    data_base.insert({user_name, password});
    informations[user_name] = {first_name, last_name};
    cout << "\n*****************************************\n" << endl;
}
void log_in() {
    start:
    cout << "\t\tLog in page\n";
    string user_name, password;
    cout << "\t\t user name : ";
    TAKE_user:
    getline(cin, user_name);
    if (user_name.empty()) {
        goto TAKE_user;
    }
    cout << "\t\t";
    password = inter_password();
    if (data_base.find({user_name, password}) != data_base.end()) {
        cout << "\t***    logged in successfully    ***\n";
        cout << "\t Your Data : ";
        cout << "\t user name " << user_name << '\n';
        cout << "\t first name " << informations[user_name].first << '\n';
        cout << "\t last name " << informations[user_name].first << "\n\n";
        cout << "\t\t Do you want to change password? (Y/N)  ";
        char x;
        cin >> x;
        if (toupper(x) == 'Y') {
            forget_password(user_name);
        } else {
            return;
        }
    } else {
        cout << "\t\tincorrect password or username\n";
        cout << "\t Do you want to re try to log in? (Y/N) ";
        char x;
        cin >> x;
        if (toupper(x) == 'Y') {
            goto start;
        } else {
            return;
        }
    }
}
int start_menu(){
    cout << "\t\tStart Menu\n";
    int x = 0;
    while (x == 0) {
        cout << "\t\t1) Sign Up\n";
        cout << "\t\t2) Log in\n";
        cout << "\t\t3) forget password\n";
        cout << "\t\t4) Exit\n";
        cin >> x;
        if (x > 4 || x < 1) {
            x = 0;
            cout << "\t\t Please inter valed value\n";
        }
    }
    return x;
}
int main() {
    int operation;
    while ((operation = start_menu() % 4)) {
        switch (operation) {
            case 1:
                sign_UP();
                break;
            case 2:
                log_in();
                break;
            case 3:
                forget_password("");
                break;
        }
    }
    cout << "\n\n"
            "***************************************"
            "\n"
            "thank you\n\n"
            "Ahmed Salah\n"
            "23 / 8 / 2023\n"
            "***************************************\n";
    return 0;
}
