#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm>
#include <time.h>

using namespace std;

static int i = 0;

// default capacity is 10 it can be changed
static int storage = 10;

void create_contact(int id[], string firstname[], string lastname[], string ph[])
{
    string first_name, last_name, ID;
    char value1 = 'y';
    string number;

    while (i < storage && value1 == 'y' || value1 == 'Y')

    {

        cout << "first_name: ";
        cin >> first_name;

        cout << "last_name: ";
        cin >> last_name;

        cout << "Phone: ";
        cin >> number;

        id[i] = i;
        firstname[i] = first_name;
        lastname[i] = last_name;
        ph[i] = number;

        i += 1;

        cout << "your storage has been added." << endl;
        cout << "Do you want to add new contact[y/n]." << endl;

        cin >> value1;
    }
}

// contacts_list
void contacts_list(int id[], string firstname[], string lastname[], string ph[])
{
    cout << "-----------------------------------------------------------------------------------------" << endl;
    cout << "|\tID\t|\tfirst name\t|\tlast name\t|\tphone number\t|" << endl;
    for (int j = 0; j < i; j += 1)
    {
        cout << "----------------+-----------------------+-----------------------+------------------------" << endl;
        cout << "|\t" << setw(4) << id[j] << "\t|\t" << setw(8) << firstname[j] << "\t|\t" << setw(8) << lastname[j] << "\t|\t" << setw(8) << ph[j] << "\t|" << endl;
    }
    cout << "-----------------------------------------------------------------------------------------" << endl;
}

// delete_contact
void delete_contact(int id[], string firstname[], string lastname[], string ph[])
{

    contacts_list(id, firstname, lastname, ph);
    char value2;
    int id_for_delete;

    cout << "What is the ID that you want to delete" << endl;
    cout << "inter the ID :";
    cin >> id_for_delete;

    for (int k = i; k >= 0; k--)
    {
        if (id_for_delete == k)
        {
            cout << "---------------------------------------------------------------------------------" << endl;
            cout << "|\t" << id[k] << "\t|\t" << firstname[k] << "\t|\t" << lastname[k] << "\t|\t" << ph[k] << "\t|" << endl;
            cout << "---------------------------------------------------------------------------------" << endl;
            cout << "Warning!!! \a \a \a";
            cout << "Are you sure about deleting this contact?![y/n]";
            cin >> value2;
            if (value2 = 'Y' || value2 == 'y' || id_for_delete <= i)
            {
                for (int t = k; t < i - 1; t++)
                {
                    id[t] = id[t + 1];
                    firstname[t] = firstname[t + 1];
                    lastname[t] = firstname[t + 1];
                    ph[t] = ph[t + 1];
                }

                cout << "deleting contact was successful.\a \a" << endl
                     << endl;

                contacts_list(id, firstname, lastname, ph);

                cout << endl
                     << endl
                     << endl;
            }
            else
            {
                cout << "Cancelled";
            }
        }
    }
}

// search_contact
void search_contact(int id[], string firstname[], string lastname[], string ph[])
{
    int idSearch;
    cout << "please enter the id: \n";
    cin >> idSearch;
    cout << "Your contact is: \n";
    cout << "|\t" << id[idSearch] << "\t|\t" << firstname[idSearch] << "\t|\t" << lastname[idSearch] << "\t|\t" << ph[idSearch] << endl
         << endl;
}

// sort_by_name it might not work properly
void sort_by_name(int id[], string firstname[], string lastname[], string ph[])
{
    string temp[1000];
    for (int d = 0; d <= 1000; d++)
    {
        temp[d] = lastname[d];
    }

    sort(std::begin(temp), std::end(temp));

    for (int d = 0; d < 1000; d++)
    {
        for (int k = 0; k < 1000; k++)
        {
            if (temp[d] == lastname[k])
            {
                cout << id[k] << "\t" << firstname[k] << "\t" << temp[k] << "\t" << ph[k];
            }
        }
    }
}

// Greeting function
void welcome()
{
    cout << "your Storage is " << storage << " if you want to change it select from list below" << endl;
    cout << "1.create contact." << endl;
    cout << "2.edit contact." << endl;
    cout << "3.delete contact." << endl;
    cout << "4.contacts list." << endl;
    cout << "5.search contact." << endl;
    cout << "6.sort by name." << endl;
    cout << "7.changing contacts capacity" << endl;
    cout << "0.exit" << endl;
}

int main()
{

    int id[storage];
    string firstname[storage];
    string lastname[storage];
    string ph[storage];

    cout << "Welcome!!" << endl;
    while (true)
    {
        welcome();
        int choice;

        cout << "Enter From List:" << endl;
        cin >> choice;
        if (choice == 0)
        {
            cout << "SEE YOU SOON";
            break;
        }

        switch (choice)
        {
        case 0:
            cout << "\n\n\t\t(:bye bye:)";
            break;
        case 1:
            create_contact(id, firstname, lastname, ph);
            break;
        case 3:
            delete_contact(id, firstname, lastname, ph);
            break;
        case 4:
            contacts_list(id, firstname, lastname, ph);
            break;
        case 5:
            search_contact(id, firstname, lastname, ph);
            break;
        case 6:
            sort_by_name(id, firstname, lastname, ph);
            break;
        case 7:
            cout << "changing array's capacity" << endl;
            cout << "Enter the Storage capacity" << endl;
            cin >> storage;
            cout << endl
                 << endl;
        }
    }

    cout << endl
         << endl;
    return 0;
}
