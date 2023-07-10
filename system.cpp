#include <iostream>
#include <string>
#include <fstream> //describes a file stream in general. It has ofstream and ifstream capabilities. This means it can create files, write to files, and read data from files.

#include <sstream> //StringStream in C++ allows performing insertion, extraction, and other operations.

using namespace std;

int main()
{
    int a, i = 0;
    string text, old, password1, password0, password2, pass, name, age, user, word, word1;

    string creds[2], cp[2];

    cout << "         Security System         " << endl
         << endl;

    cout << "______________________________     " << endl;
    cout << "         1.Register            " << endl;
    cout << "         2.Login               " << endl;
    cout << "         3.Change Password     " << endl;
    cout << "         4.End Program         " << endl;
    cout << "______________________________     " << endl
         << endl;

    do
    {
        cout << "Enter your choice: ";
        cin >> a;
        switch (a)
        {
        case 1:
        {
            cout << "--------Register--------" << endl
                 << endl;
            cout << "Please enter your username: ";
            cin >> name;
            cout << "Plase enter your password: ";
            cin >> password0;
            cout << "Please enter your age: ";
            cin >> age;

            ofstream of1;
            of1.open("file.txt");
            if (of1.is_open())
            {
                of1 << name << endl;
                of1 << password0 << endl;

                cout << "Registration successful" << endl;
            }

            break;
        }

        case 2:
        {
            i = 0;
            cout << "--------Login--------" << endl
                 << endl;

            ifstream of2;
            of2.open("file.txt");
            cout << "Please enter the username: ";
            cin >> user;
            cout << "Please enter the password: ";
            cin >> pass;

            if (of2.is_open())
            {
                while (!of2.eof())
                {
                    while (getline(of2, text))
                    {
                        istringstream iss(text);
                        iss >> word;
                        creds[i] = word;
                        i++;
                    }

                    if (user == creds[0] && pass == creds[1])
                    {
                        cout << "--------Login Successful--------" << endl;

                        cout << "Details: " << endl;
                        cout << "Username: " << name << endl;
                        cout << "Password: " << pass << endl;
                        cout << "Age: " << age << endl
                             << endl;
                    }
                    else
                    {
                        cout << "Incorrect Credentials" << endl;

                        cout << "    Press 2 to Login    " << endl;
                        cout << "    Press 3 to Change Password    " << endl;

                        break;
                    }
                }
            }

            break;
        }

        case 3:
        {
            i = 0;

            cout << "--------Change Password--------" << endl;

            ifstream of0;
            of0.open("file.txt");
            cout << "Enter the old password: ";
            cin >> old;

            if (of0.is_open())
            {
                while (of0.eof())
                {
                    while (getline(of0, text))
                    {
                        istringstream iss(text);
                        iss >> word1;
                        cp[i] = word1;
                        i++;

                        if (old == cp[1])
                        {
                            of0.close();

                            ofstream of1;
                            if (of1.is_open())
                            {
                                cout << "Enter your new password: ";
                                cin >> password1;
                                cout << "Enter your  password again: ";
                                cin >> password2;

                                if (password1 == password2)
                                {
                                    of1 << cp[0] << endl;
                                    of1 << password1;
                                    cout << "Password changed successfully." << endl;
                                }
                                else
                                {
                                    of1 << cp[0] << endl;
                                    of1 << old;
                                    cout << "Password do not match." << endl;
                                }
                            }
                        }
                        else
                        {
                            cout << "Invalid password" << endl;
                            break;
                        }
                    }
                }
            }

            break;
        }

        case 4:
        {
            cout << "         Thank You!          " << endl;
            break;
        }
        default:
            cout << "Enter a valid choice." << endl;
            break;
        }

    } while (a != 4);

    return 0;
}