#include <bits/stdc++.h>
using namespace std;
class student
{
private:
    int rollno, age;
    string name;

public:
    student(int stdRoll, int stdAge, string stdName)
    {
        this->age = stdAge;
        this->rollno = stdRoll;
        this->name = stdName;
    }
    void setRollno(int stdRollno)
    {
        rollno = stdRollno;
    }
    int getRollNo()
    {
        return rollno;
    }
    void setName(string stdName)
    {
        name = stdName;
    }
    string getNmae()
    {
        return name;
    }
    void setAge(int stdAge)
    {
        age = stdAge;
    }
    int getAge()
    {
        return age;
    }
    void displayStudent()
    {
        cout << "\t\tRoll No :" << rollno << endl;
        cout << "\t\tNmae :" << name << endl;
        cout << "\t\tAge :" << age << endl;
    }
};
// create function to add new student
void addNewStudent(vector<student> &students)
{
    int rollno, age;
    string name;
    cout << "\t\tEnter Rollno";
    cin >> rollno;
    // check if student already exist
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].getRollNo() == rollno)
        {
            cout << "\t\tStudents Already Exists .... " << endl;
            return;
        }
    }

    cout << "\t\tEnter Name";
    cin >> name;
    cout << "\t\tEnter Age";
    cin >> age;

    student newStudent(rollno, age, name);
    students.push_back(newStudent);

    cout << "\t\tstudent Add successful" << endl;
}

// display all student
void displayAllStudent(vector<student> &students)
{
    if (students.empty())
    {
        cout << "\t\tNo student find" << endl;
        return;
    }
    for (int i = 0; i < students.size(); i++)
    {
        students[i].displayStudent();
        cout << endl;
    }
}
// student Search
void studentSearch(vector<student> &students)
{
    int rollno;
    cout << "\t\tEnter Rollno" << endl;
    cin >> rollno;
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].getRollNo() == rollno)
        {
            cout << "\t\t ----------Student found---------" << endl;
            students[i].displayStudent();
            cout << endl;
            return;
        }
    }
    cout << "\t\t -------No Student found---------" << endl;
    return;
}
// create function to update student record
void updateStudent(vector<student> &students)
{
    string sname;
    bool found = false;
    cout << "\t\tEnter Nmae to update Record :" << endl;
    getline(cin, sname);
    int choice;
    for (int i = 0; i < students.size(); i++)
    {
        cout << sname << " hello " << endl;
        if (students[i].getNmae() == sname)
        {
            found = true;

            cout << "\t\t--- Student found---" << endl;
            cout << "\t\t1. Update Rollno " << endl;
            cout << "\t\t2. Update Nmae " << endl;
            cout << "\t\t3. Update Age " << endl;
            cout << "\t\tEnter your choice\n";
            string name1;
            int rno;
            cin >> choice;
            int age;
            switch (choice)
            {
            case 1:
                cout << "\t\tEnter new Rollno\n";
                cin >> rno;
                students[i].setRollno(rno);
                break;
            case 2:
                cout << "\t\tEnter new name\n";
                cin.ignore();
                getline(cin, name1);
                students[i].setName(name1);
                break;
            case 3:
                cout << "\t\tEnter new age\n";
                cin >> age;
                students[i].setAge(age);
                break;
            default:
                cout << "\t\tInvalid number\n";
                break;
            }
        }
    }
    if (found == false)
    {
        cout << "\t\t Record not found" << endl;
    }
}
// delete student
void deleteStudent(vector<student> &students)
{
    int roll;
    bool found = false;
    cout << "\t\tEnter Rollno :" << endl;
    cin >> roll;
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].getRollNo() == roll)
        {
            int k = students.size() - 1;
            swap(students[i], students[k]);
            students.pop_back();
            cout << "\t\t -------Student Deleted---------" << endl;
            return;
        }
    }
    cout << "\t\t -------No Student found---------" << endl;
    return;
}

int main()
{
    vector<student> students;
    students.push_back(student(1, 20, "akash"));
    int op = 1;
    int choice = 1;
    while (choice)
    {
        system("cls");
        cout << "\t\t---------------------------" << endl;
        cout << "\t\tStudent management system" << endl;
        cout << "\t\t---------------------------" << endl;
        cout << "\t\t1. Add New Student" << endl;
        cout << "\t\t2. Display All Student" << endl;
        cout << "\t\t3. Search student" << endl;
        cout << "\t\t4. Update student" << endl;
        cout << "\t\t5. Delete student" << endl;
        cout << "\t\t6. Exit" << endl;
        cout << "\t\tEnter your choice" << endl;
        cin >> op;
        cin.ignore();
        switch (op)
        {
        case 1:
            addNewStudent(students);
            break;
        case 2:
            displayAllStudent(students);
            break;
        case 3:
            studentSearch(students);
            break;
        case 4:
            updateStudent(students);
            break;
        case 5:
            deleteStudent(students);
            break;
        case 6:
            exit(1);
            break;

        default:
            cout << "\t\tInvalid selection" << endl;
            break;
        }
        cout << "\t\t Do you want to continue[Yes(1) / No(0)] ? :" << endl;
        cin >> choice;
        cin.ignore();
    }

    return 0;
}