#include <iostream>
#include <windows.h>
#include <fstream>
#include <String>
using namespace std;

struct client {
    string service, mobileNo, name;
};

struct node {
    client info;
    node* next;
};

//Global pointers & Variables;

node* Front = NULL;
node* Front1 = NULL;
node* rear = NULL;
node* rear1 = NULL;
node* current = NULL;
node* current1 = NULL;
int clientCounter = 0;
int VIPcounter = 0;
int total_counter = 0;
client temp_client;
string phone[7] = { "01029930161","01021081067","01204426692","01210628365","01153415868","01029930160","01151454697" };

//get data in the general object 
void getData() {
    cin.ignore(); //To Define The getline Function
    cout << "Enter Your Name :" << endl;
    getline(cin, temp_client.name);
    cout << "Enter Serivce Tybe Between Teller OR Costumer Service :" << endl;
    getline(cin, temp_client.service);
    cout << "Enter Your Mobile Number :" << endl;
    cin >> temp_client.mobileNo;
}

void client_enqueue() {
    // -------------------- checking data ----------------- 
    // 1) Client Name
    int errorFlag = 0;
    for (int j = 0; j < temp_client.name.size(); j++)
    {
        if ( (temp_client.name[j] >= 'A' && temp_client.name[j] <= 'Z')   ||   (temp_client.name[j] >= 'a' && temp_client.name[j] <= 'z')    ||    temp_client.name[j] == ' ')
            continue;
        else {
            cout << "Invalid Operation..Please Enter Only Letters" << endl;
            errorFlag = 1;
        }
        break;

    }

    // 2) Service checking
    for (int j = 0; j < temp_client.service.size(); j++)
    {
        if ((temp_client.service[j] >= 'A' && temp_client.service[j] <= 'Z') || (temp_client.service[j] >= 'a' && temp_client.service[j] <= 'z') || temp_client.service[j] == ' ')
            continue;
        else {
            cout << "Invalid Operation..Please Enter Only Letters" << endl;
            errorFlag = 1;
        }
        break;

    }

    // 3) Phone Number Checking
    for (int i = 0; i < temp_client.mobileNo.size(); i++)
    {
        if (temp_client.mobileNo.size() == 11) {

            if ((temp_client.mobileNo[i] >= '0' && temp_client.mobileNo[i] <= '9'))
                continue;

        }
        else {
            cout << "Invalid Operation..Please Enter A valid mobile number! " << endl;
            errorFlag = 1;
        }
        break;

    }


    if (errorFlag == 0)
    {

        current = new node();
        if (Front == NULL) {
            Front = current;
            rear = current;
        }
        else {
            rear->next = current;
            rear = current;
        }
        current->info.name = temp_client.name;
        current->info.service = temp_client.service;
        current->info.mobileNo = temp_client.mobileNo;
        //To increase the count of clients that Enterd..
        clientCounter++;
        total_counter = VIPcounter + clientCounter;
    }
}
void VIP_Enqueue()
{

    // -------------------- checking data ----------------- 
    int errorFlag = 0;
    // 1) Client Name

    for (int j = 0; j < temp_client.name.size(); j++)
    {
        if ((temp_client.name[j] >= 'A' && temp_client.name[j] <= 'Z') || (temp_client.name[j] >= 'a' && temp_client.name[j] <= 'z') || temp_client.name[j] == ' ')
            continue;
        else {
            cout << "Invalid Operation..Please Enter Only Letters" << endl;
            errorFlag = 1;
        }
        break;

    }

    // 2) Service checking
    for (int j = 0; j < temp_client.service.size(); j++)
    {
        if ((temp_client.service[j] >= 'A' && temp_client.service[j] <= 'Z') || (temp_client.service[j] >= 'a' && temp_client.service[j] <= 'z') || temp_client.service[j] == ' ')
            continue;
        else {
            cout << "Invalid Operation..Please Enter Only Letters" << endl;
            errorFlag = 1;
        }
        break;

    }

    // 3) Phone Number Checking
    for (int i = 0; i < temp_client.mobileNo.size(); i++)
    {
        if (temp_client.mobileNo.size() == 11) {

            if ((temp_client.mobileNo[i] >= '0' && temp_client.mobileNo[i] <= '9'))
                continue;

        }
        else {
            cout << "Invalid Operation..Please Enter A valid mobile number ! " << endl;
            errorFlag = 1;
        }
        break;

    }

    if (errorFlag == 0)
    {

        current1 = new node();
        if (Front1 == NULL) {
            Front1 = current1;
            rear1 = current1;
        }
        else {
            rear1->next = current1;
            rear1 = current1;
        }

        current1->info.name = temp_client.name;
        current1->info.service = temp_client.service;
        current1->info.mobileNo = temp_client.mobileNo;

        VIPcounter++;//return the number of VTP Clients;
        total_counter = VIPcounter + clientCounter;//return  normal clients number

    }

}

void VIP_display()
{
    fstream client_data;
    client_data.open("storing_VIP_data.txt", ios::out);
    if (Front1 == NULL)
    {
        // If  Is NULL QUEUE
        cout << "The VIP Clients Queue Is Empty..\n";
    }
    else {

        current1 = Front1;

        int my_vip_order = 0;
        while (current1 != NULL)
        {
            my_vip_order++;

            cout << "The VIP Client Name : " << current1->info.name << endl;
            cout << "VIP Client Number : " << my_vip_order << endl;
            cout << "Choosen Service : " << current1->info.service << endl;
            cout << "Phone Number : " << current1->info.mobileNo << endl;

            //---------------- File Output ----------------------

            client_data << "VIP CLIENT DATA : " << endl;
            client_data << "\t""Name : " << current1->info.name << endl;
            client_data << "\t""Service Choosen : " << current1->info.service << endl;
            client_data << "\t"" VIP Client Number : " << my_vip_order << endl;
            client_data << "\t""Phone Number : " << current1->info.mobileNo << endl;
            current1 = current1->next;

        }

    }
        client_data.close();

}

void client_display() {

    fstream client_data;
    client_data.open("storing_data.txt", ios::out);
    if (Front == NULL)
        cout << "The Normal Clients Queue  Is Empty..\n";
    else {

        current = Front;

        int my_order = VIPcounter;

        while (current != NULL) {
            my_order++;
            cout << "The Client Name : " << current->info.name << endl;
            cout << "The Client Number : " << my_order << endl;
            cout << "Choosen Service : " << current->info.service << endl;
            cout << "Phone Number : " << current->info.mobileNo << endl;
            //---------------- File Output ----------------------

            client_data << "NORMAL CLIENT DATA : " << endl;
            client_data << "\t""Name : " << current->info.name << endl;
            client_data << "\t""Number : " << my_order << endl;
            client_data << "\t""Srevice Choosen : " << current->info.service << endl;
            client_data << "\t""Phone Number : " << current->info.mobileNo << endl;

            current = current->next;

        }
    }
        client_data.close();


}

void client_dequeue() {
    if (Front == NULL)
        cout << "The Dequeue Is Empty..\n";
    else if (Front == rear) {//If The First Node
        delete Front;
        Front = rear = NULL;
    }
    else {
        //if There're more than one
        node* current = Front;
        Front = Front->next;
        delete current;
    }

    clientCounter--;
    total_counter = VIPcounter + clientCounter;
}

void VIP_dequeue() {
    if (Front1 == NULL)
        cout << "The Dequue Is Empty..\n";

    else if (Front1 == rear1) {
        delete Front1;
        Front1 = rear1 = NULL;
    }
    else {
        node* current1 = Front1;
        Front1 = Front1->next;
        delete current1;
    }

    VIPcounter--;
    total_counter = VIPcounter + clientCounter;

}

// -------------- Searching Algorithm : Linear Search ---------------
void Enqueue_By_Phone() {

    int vipFlag = 0;

    for (int i = 0; i < 20; ++i) {
        if (phone[i] == temp_client.mobileNo)
        {
            vipFlag = 1;
        }
    }

    if (vipFlag == 1)
    {
        VIP_Enqueue();
        VIP_display();
    }
    else
    {
        client_enqueue();
        client_display();
    }
}
void Search_if_VIP_or_normal_client() {
    string num;
    cout << "Enter Your Phone Number : \n";
    cin >> num;
    bool Client = true;
    for (int i = 0; i < 7; ++i) {
        if (phone[i] == num) {
            cout << "You're A VIP Client.\n";
            Client = false;
            break;
        }
    }    if (Client)
        cout << "You're A Client.\n";


}
void update() {
    cout << "The Number Of Vip Clients : " << VIPcounter << endl;
    cout << "The Number Of Normal Clients : " << total_counter << endl;
}
void Dequeue_by_order()
{
    if (VIPcounter > 0) {
        VIP_dequeue();
        update();

    }
    else if (clientCounter > 0)
    {
        client_dequeue();
        update();

    }
    else
    {
        cout << "The Queue Is Already Empty" << endl;
    }
}

void MENUE() {
    while (true) {
        char key;
        cout << "\n----------------------------- WELCOME ------------------------------\n" << endl;
        cout << "\t\t-| [E] Enqueue        |-\n";
        cout << "\t\t-| [D] Dequeue        |-\n";
        cout << "\t\t-| [P] Print          |-\n";
        cout << "\t\t-| [S] Search         |-\n";
        cout << "\t\t-| [U] Update         |-\n";
        cout << "\t\t-| [Q] Quit           |-\n";
        cout << "\n--------------------------------------------------------------------\n";
        cout << "Please Enter a Key " << endl;
        cin >> key;
        if (key == 'E')
        {
            getData();
            Enqueue_By_Phone();

        }
        else if (key == 'D')
        {
            Dequeue_by_order();

        }
        else if (key == 'P') {
            int P = 0;
            cout << "Choose Between 1.Print All Clients OR 2.Print VIP Clients ?\n";
            cin >> P;
            switch (P) {
            case 1: VIP_display(); client_display(); break;
            case 2:  VIP_display(); break;
            }
        }

        else if (key == 'S')
        {

            Search_if_VIP_or_normal_client();
        }
        else if (key == 'U')
        {
            update();
        }
        else if (key == 'Q')
            return;
    }
}
void begin() {
    system("cls");
    system("Color 0B");
    char x = 219;
    cout << "\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t------------------------------------------------------------\n";
    cout << "\t\t\t\t------------------------------------------------------------\n";
    cout << "\t\t\t\t-------------------QUEUE SYSTEM BANK------------------------\n";
    cout << "\t\t\t\t------------------------------------------------------------\n";
    cout << "\t\t\t\t------------------------------------------------------------\n";
    cout << "\t\t\t\t  Loading ";
    for (int i = 0; i < 35; i++) {
        cout << x;
        if (i >= 0 && i < 10)
            Sleep(200);
        else if (i >= 10 && i < 20)
            Sleep(100);
        else if (i >= 20 && i < 30)
            Sleep(70);
        else if (i >= 30 && i < 40)
            Sleep(30);
    }
    system("cls");
}

int main() {
    system("cls");
    begin();
    MENUE();

    return 0;
}