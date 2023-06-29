#include <iostream>
#include <conio.h>
using namespace std;

class Node
{
    public:
        string name;
        string srcode;
        string subj;
        string sr_code_placeholder;
        int sr_code;
        Node* next;
};

Node* createNode(string name, string srcode, string subj, int sr_code)
{
    Node* newNode = new Node();
    newNode->name = name;
    newNode->srcode = srcode;
    newNode->subj = subj;
    newNode->sr_code = sr_code;
    newNode->next = nullptr;
    return newNode;
}

void insertNode(Node*& head, Node* newNode)
{
    if (head == nullptr)
    {
        head = newNode;
    } else
    {
        Node* temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayNodeDetails(Node* node)
{
    cout << "Name: " << node->name << endl;
    cout << "Description: " << node->subj << endl;
    cout << "Press Enter to Continue...";
    getch();
}

int main()
{
    int temp = 0;
    int search;
    string choice_input;
    system("cls");
    int size;
    string size_placeholder;

    while (true)
    {
        try
        {
            cout << "Please Enter Number of Students: ";
            cin >> size_placeholder;
            size = stoi(size_placeholder);
            break;
        } catch (const exception&)

        {
            cout << "Syntax Error Please Try Again\n";
            cout << "Make sure there are no special characters\n";
            cout << "Press Enter to Continue....\n";
            getch();
        }
    }

    Node* head = nullptr;

    for (int i = 0; i < size; i++)
    {
        cout << "Enter Name of Student No. " << i + 1 << ": ";
        string name;
        cin >> name;

        while (true)
        {
            try
            {
                cout << "Enter SRCODE: ";
                string sr_code_placeholder;
                cin >> sr_code_placeholder;
                int sr_code = stoi(sr_code_placeholder);

                Node* newNode = createNode(name, "", "", sr_code);
                insertNode(head, newNode);
                break;
            } catch (const exception&)
            {
                cout << "Syntax Error Please Try Again\n";
                cout << "Make sure there are no special characters\n";
                cout << "Press Enter to Continue....\n";
                getch();
            }
        }

        cout << "Enter Subject: ";
        cin >> head->subj;
        cout << "\n";
    }

    do
    {bool found = false;
        do
        {
            system("cls");
            cout << "Enter SRCODE to display the details: ";
            cin >> search;

            Node* temp = head;
            

            while (temp != nullptr)
            {
                if (search == temp->sr_code)
                {
                    system("cls");
                    displayNodeDetails(temp);
                    found = true;
                    break;
                }
                temp = temp->next;
            }

            if (found != true)
            {
                system("cls");
                cout << "Syntax Error Invalid SRCODE";
                cout << "\nPlease try Again";
                cout << "\nPress Enter to Continue...";
                getch();
                cout << endl;
            }
        } while(found != true);

        system("cls");
        cout << "Do you wish to input again? Y/N: ";
        cin >> choice_input;
        if (choice_input == "N" || choice_input == "n")
        {
            system("cls");
            cout << "Thank you!";
            return 0;
        } else if (choice_input != "Y" && choice_input != "y" && choice_input != "N" && choice_input != "n") {
            system("cls");
            cout << "Syntax Error. Please Try Again.";
            cout << "\nPress Enter To Continue";
            getch();
        }
    } while (choice_input != "N" && choice_input != "n");

    return 0;
}
