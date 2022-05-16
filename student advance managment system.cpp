#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;
class student
{
    private:
    string name, roll_no, course, address, email_id, contact_no;
    public:
    void menu(),insert(),display(),modify(),search(),deleted();
};
void student::menu()
{
    menustart:
    int choice;
    char x;
    system("cls");
    cout << "\t\t\t STUDENT MANAGEMENT SYSTEM " << endl;
    cout << "\t\t\t 1. Enter New Record" << endl;
    cout << "\t\t\t 2. Display Record" << endl;
    cout << "\t\t\t 3. Modify Record" << endl;
    cout << "\t\t\t 4. Search Record" << endl;
    cout << "\t\t\t 5. Delete Record" << endl;
    cout << "\t\t\t 6. Exit" << endl;

    cout << "\t\t\tChoose Option:[1/2/3/4/5/6]" << endl;
    cout << "Enter Your Choose: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        do
        {
            insert();
            cout << "\n\t\t\t Add Another Student Record (Y,N): ";
            cin >> x;
        }
        while (x == 'y' || x == 'Y');
        break;
    case 2:
        display();
        break;
    case 3:
        modify();
        break;
    case 4:
        search();
        break;
    case 5:
        deleted();
        break;
    case 6:
        exit(0);
    default:
        cout << "\n\t\t\t Invalid choice... Please Try Again..";
    }
    getch();
    goto menustart;
}
void student::insert()
{
    system("cls");
    fstream file;
    cout << "\n Add Student Details " << endl;
    
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Roll No.: ";
    cin >> roll_no;
    cout << "Enter Course: ";
    cin >> course;
    cout << "Enter Email Id: ";
    cin >> email_id;
    cout << "Enter Contact No: ";
    cin >> contact_no;
    cout << "Enter Address: ";
    cin >> address;
    file.open("studentRecord.txt", ios::app | ios::out);
    file << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
    file.close();
}

void student::display()
{
    system("cls");
    fstream file;
    int total = 1;
    cout << " Student Record Table " << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\nNo Data Is Present.";
        file.close();
    }
    else
    {
        file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            cout << "\n\nStudent No.: " << total++ << endl;
            cout << "Student Name: " << name << endl;
            cout << "Student Roll No.: " << roll_no << endl;
            cout << "Student course: " << course << endl;
            cout << "Student Email Id.: " << email_id << endl;
            cout << "Student Contact No.: " << contact_no << endl;
            cout << "Student Address: " << address << endl;
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        }
        if (total == 0)
        {
            cout << "\nNo Data Is Present.";
        }
    }
    file.close();
}
void student::modify()
{
    system("cls");
    fstream file, file1;
    string rollno;
    int found = 0;
    cout << " Student Modify Details " << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\nNo Data is Present.";
    }
    else
    {
        cout << "\nEnter Roll No. of Student which you want to Modify: ";
        cin >> rollno;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (rollno != roll_no)

                file1 << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
            else
            {
                cout << "\n\t\t\tEnter Name: ";
                cin >> name;
                cout << "\t\t\tEnter Roll No.: ";
                cin >> roll_no;
                cout << "\t\t\tEnter Course: ";
                cin >> course;
                cout << "\t\t\tEnter Email Id: ";
                cin >> email_id;
                cout << "\t\t\tEnter Contact No.: ";
                cin >> contact_no;
                cout << "\t\t\tEnter Address: ";
                cin >> address;
                file1 << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
                found++;
            }
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
            if (found == 0)
            {
                cout << "\n\nStudent Roll No. Not Found.";
            }
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("record.txt", "studentRecord.txt");
    }
}
void student::search()
{
    system("cls");
    fstream file;
    int found = 0;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << " Student Search Data " << endl;
        cout << "\nNo Data Is Present.";
    }
    else
    {
        string rollno;
        cout << " Student Search Data " << endl;
        cout << "\n Enter Roll No. of Student Which You Want to Search: ";
        cin >> rollno;
        file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (rollno == roll_no)
            {
                cout << "\nStudent Name: " << name << endl;
                cout << "Student Roll No.: " << roll_no << endl;
                cout << "Student course: " << course << endl;
                cout << "Student Email Id.: " << email_id << endl;
                cout << "Student Address: " << address << endl;
                found++;
            }
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        }
        if (found == 0)
        {
            cout << "\nStudent Roll No. Not Found.";
        }
        file.close();
    }
}
void student::deleted()
{
    system("cls");
    fstream file, file1;
    int found = 0;
    string roll;
    cout << " Delete Student Details " << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\nNo Data is Present.";
        file.close();
    }
    else
    {
        cout << "\nEnter Roll No. of Student which you want Delete Data: ";
        cin >> roll;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (roll != roll_no)
            {
                file1 << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
            }
            else
            {
                found++;
                cout << "\nSuccessfully Delete Data";
            }
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        }
        if (found == 0)
        {
            cout << "\nStudent Roll NO. Not Found.";
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("record.txt", "studentRecord.txt");
    }
}
int main()
{
    student project;
    project.menu();
    return 0;
}
