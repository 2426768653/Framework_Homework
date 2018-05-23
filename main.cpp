#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

void ClearScreen() {
//      printf("\033c"); //check which one is working
    printf("\033[H\033[J");
//    cout << string(100, '\n');
}

class Record {
 protected:
    string name;
    char sex;
    string ID;
    string birthday;    //pairs, or other 3 volumed
    string address;
    unsigned short age;
 public:
    Record() {
        cout << "Please enter Name: ";
        cin >> name;
        cout << "             Sex: ";
        cin >> sex;
        cout << "             ID: ";
        cin >> ID;
        cout << "             Birthday: ";
        cin >> birthday;
        cin.ignore();     // skips \n
        cout << "             Address: ";
        getline(cin, address);
        cout << "             Age: ";
        cin >> age;
    }
//    void print() {
//        cout << "\nName: " << this->name
//             << "\nSex: " << this->sex
//             << "\nID: " << this->ID
//             << "\nBirthday: " << this->birthday
//             << "\nAddress: " << this->address
//             << "\nAge: " << this->age;
//    }
    Record(string const &a, const char &b, string const &c,
           string const &d, string const &e, const unsigned short &f) {
        name = a;
        sex = b;
        ID = c;
        birthday = d;
        address = e;
        age = f;
    }
};
class Student: protected Record {
    string number;
    string dormitory;   //pairs<string name, int number>
    string major;
    unsigned short year;    //1 - 4
 public:
    Student() {
        cout << "             Student Number: ";
        getline(cin, number);
        //cin.ignore();     // skips \n
        cout << "             Dormitory Number: ";
        getline(cin, dormitory);
        cout << "             Major: ";
        cin >> major;
        cout << "             Year: ";
        cin >> year;
        cin.ignore();
        cout << "Press any key to continue...\n";
        cin.get();
    }

    Student(string const &a, const char &b, string const &c,
            string const &d, string const &e, const unsigned short &f,
            string const &g, string const &h, string const &j,
            const unsigned short &k) : Record(a, b, c, d, e, f) {
        number = g;
        dormitory = h;
        major = j;
        year = k;
    }
    /*inline*/bool operator==(Student const &a) {
        return (a.name == name && a.sex == sex && a.ID == ID
            && a.birthday == birthday && a.address == address
            && a.age == age && a.number == number
            && a.dormitory == dormitory && a.major == major);
    }

    static void print(vector<Student> &X, string const &stud_num);

    static void change(vector<Student> &X, string const &stud_num);

    static bool lookup(vector<Student> &X, string const &stud_num);

    friend ostream &operator<<(ostream &out, const Student &a);
    friend istream &operator>>(istream &in, Student &a);
};

class Staff: protected Record {
 protected:
    unsigned long worker_number;
    string appartment;
    unsigned dailyHours;
    unsigned salary;
 public:
    Staff() {
        cout << "             Worker Number: ";
        cin >> worker_number;
        cin.ignore();     // skips \n
        cout << "             Appartment: ";
        getline(cin, appartment);
        cout << "             Working Hours: ";
        cin >> dailyHours;
        cout << "             Salary: ";
        cin >> salary;
    }
    Staff(string const &a, const char &b, string const &c,
          string const &d, string const &e, const unsigned short &f,

          const unsigned long &g, string const &h, const unsigned &j,
          const unsigned &k) : Record(a, b, c, d, e, f) {
        worker_number = g;
        appartment = h;
        dailyHours = j;
        salary = k;
    }
//    void print() {
//        cout << "\nWorker Number: " << worker_number
//             << "\nAppartment: " << appartment
//             << "\nWorking Hours: " << dailyHours
//             << "\nSalary: " << salary;
//    }
};
class Professor: protected Staff {
 protected:
    string fieldOfTeaching;
    string research;
    unsigned numOfPostgrads;
 public:
    Professor() {
        cin.ignore();     // skips \n
        cout << "             Field Of Teaching: ";
        getline(cin, fieldOfTeaching);
        cout << "             Research Project: ";
        getline(cin, research);
        cout << "             Number Of Postgraduate Students: ";
        cin >> numOfPostgrads;

        cin.ignore();
        cout << "Press any key to continue...\n";
        cin.get();
    }
    Professor(string const &a, const char &b, string const &c,
              string const &d, string const &e, const unsigned short &f,
              const unsigned long &g, string const &h, const unsigned &j,
              const unsigned &k,
              string const &l, string const &m,
              const unsigned &n) : Staff(a, b, c, d, e, f, g, h, j, k) {
        fieldOfTeaching = l;
        research = m;
        numOfPostgrads = n;
    }
    bool operator==(Professor const &a) {
        return (a.name == name && a.sex == sex && a.ID == ID
            && a.birthday == birthday && a.address == address
            && a.age == age && a.worker_number == worker_number
            && a.appartment == appartment && a.dailyHours == dailyHours
            && a.salary == salary && a.fieldOfTeaching == fieldOfTeaching
            && a.research == research && a.numOfPostgrads == numOfPostgrads
        );
    }
    friend ostream &operator<<(ostream &out, const Professor &a);
    friend istream &operator>>(istream &in, Professor &a);

    static void print(vector<Professor> &X, const unsigned long &work_num);

    static void change(vector<Professor> &X, const unsigned long &work_num);

    static bool lookup(vector<Professor> &X, const unsigned long &work_num);
};

class Worker: protected Staff {
 protected:
    string job;
 public:
    Worker() {
        cin.ignore();     // skips \n
        cout << "             Job: ";
        getline(cin, job);
        cout << "Press any key to continue...\n";
        cin.get();
    }
    Worker(string const &a, const char &b, string const &c,
           string const &d, string const &e, const unsigned short &f,
           const unsigned long &g, string const &h, const unsigned &j,
           const unsigned &k, string const &l) : Staff(a, b, c, d, e, f, g, h, j, k) {
        job = l;
    }
    bool operator==(Worker const &a) {
        return (a.name == name && a.sex == sex && a.ID == ID
            && a.birthday == birthday && a.address == address
            && a.age == age && a.worker_number == worker_number
            && a.appartment == appartment && a.dailyHours == dailyHours
            && a.salary == salary && a.job == job

        );
    }
    friend ostream &operator<<(ostream &out, const Worker &a);
    friend istream &operator>>(istream &in, Worker &a);

    static void print(vector<Worker> &X, const unsigned long &work_num);

    static void change(vector<Worker> &X, const unsigned long &work_num);

    static bool lookup(vector<Worker> &X, const unsigned long &work_num);
};

void first_screen() {
    cout << "Welcome !\n" << "Choose the section:\n"
         << "1) Student\n"
         << "2) Professor\n"
         << "3) Worker\n"
         << "4) Exit\n";
//        << "4) Staff record\n"
//        << "5) Make a regular person record\n";
}
void second_screen() {
    //Welcoming to the screen of particular section,
    // add a parameter to customize welcoming
    cout << "1) Add a record" << endl
         << "2) Print a record" << endl
         << "3) Change a record" << endl
         << "4) Delete a record" << endl
         << "5) Find a record" << endl
         << "6) Exit" << endl;
}

//void nesting(int option){                                  //second screen choosing menu
//    //add screen cleaning
//    second_screen();
//    cin >> option;
//    switch (option) {                                     //add screen cleaning
//    case 1:
//        break;
//    case 2:
//
//        break;
//    case 3:
//
//        break;
//    case 4:
//
//        break;
//    case 5:
//
//        break;
//    default:
//        cerr << "Wrong Input\n";
//        break;
//    }
//}

void initialization(fstream &XX, vector<Student> &list) {
    string temporary;
//    getline(XX, temporary, '|');
    while (XX) {
        XX >> temporary;
        if (temporary == "Student") {
            Student input_temporary("0", 'a', "0", "0", "0", 0, "0", "0", "0", 0);
            XX >> input_temporary;
            list.emplace_back(input_temporary);
        }
        //add init for worker and professor
    }
    XX.close();
}

template<typename T>
void fin_out(ofstream &XX, const vector<T> &list) {
    for (auto const &x : list) {
        XX << x;
    }
    cout << "\nAll records were stored\n";
}

int main() {
    std::ios::sync_with_stdio(false);       //improves I/O, because doesn't make sync between c++ and c-style I/O
    short temp = 0;

    fstream fs("in.txt", ios::in);
    if (!fs)
        cerr << ("couldn't open in.txt file");

    vector<Student> students;
    vector<Professor> professors;
    vector<Worker> workers;

    initialization(fs, students);   //fs closed inside

    FIRST_SCREEN:

    first_screen();
    cin >> temp;
    ClearScreen();
    switch (temp) {
        case 1: {
//            ClearScreen();
            //add screen cleaning
            STUDENT_SCREEN:
            second_screen();

            cin >> temp;
            switch (temp) {
                //add screen cleaning
                case 1: {     //Adding record
                    Student temp_inp;       //stud_num recur check
                    students.push_back(temp_inp);
                    goto STUDENT_SCREEN;
                }
                case 2: {   //Printing
                    cout << "Student number of a student you want to print: ";
                    string temp_studnum;
                    cin >> temp_studnum;
                    Student::print(students, temp_studnum);
                    goto STUDENT_SCREEN;
                    break;
                }
                case 3: {   //Changing
                    cout << "Student number of a student record you want to change: ";
                    string temp_studnum;
                    cin >> temp_studnum;
                    Student::change(students, temp_studnum);
                    goto STUDENT_SCREEN;
                }
                case 4: {   //Deleting
                    cout << "Enter information about a record you want to delete: \n";
                    Student to_be_deleted;
                    auto it = find(students.begin(), students.end(), to_be_deleted);
                    if (it != students.end()) {
                        students.erase(it);
                        cout << "Record has been succesfully deleted.\n";
                    } else
                        cout << "No record with such information were found.\n";
                    goto STUDENT_SCREEN;
                }
                case 5: {   //Find
                    cout << "Student number of a student you want to find: ";
                    string temp_studnum;
                    cin >> temp_studnum;
                    if (Student::lookup(students, temp_studnum))
                        cout << "There's a student with student number " << temp_studnum << "\n";
                    else
                        cout << "There's no student with student number " << temp_studnum << "\n";
                    goto STUDENT_SCREEN;
                }
                case 6: {
                    goto FIRST_SCREEN;
                }
                default: {
                    cerr << "\nWrong Input\n\n";
                    goto STUDENT_SCREEN;
                }
            }
        }

        case 2: {
            PROFESSOR_SCREEN:
            second_screen();
            cin >> temp;
            switch (temp) {
                case 1: {     //Adding record
                    Professor temp_inp;
                    professors.push_back(temp_inp);
                    goto PROFESSOR_SCREEN;
                }
                case 2: {   //Printing
                    cout << "Worker number of a professor you want to print: ";
                    unsigned long temp_worknum;
                    cin >> temp_worknum;
                    Professor::print(professors, temp_worknum);
                    goto PROFESSOR_SCREEN;
                }
                case 3: {   //Changing
                    cout << "Worker number of a professor record you want to change: ";
                    unsigned long temp_worknum;
                    cin >> temp_worknum;
                    Professor::change(professors, temp_worknum);
                    goto PROFESSOR_SCREEN;
                }
                case 4: {   //Deleting
                    cout << "Enter information about a professor record you want to delete: \n";
                    Professor to_be_deleted;
                    auto it = find(professors.begin(), professors.end(), to_be_deleted);
                    if (it != professors.end()) {
                        professors.erase(it);
                        cout << "Record has been succesfully deleted.\n\n";
                    } else
                        cout << "No record with such information were found.\n\n";
                    goto PROFESSOR_SCREEN;
                }
                case 5: {   //Find
                    cout << "Worker number of a professor you want to find: ";
                    unsigned long temp_worknum;
                    cin >> temp_worknum;
                    if (Professor::lookup(professors, temp_worknum))
                        cout << "There's a professor with such worker number.\n\n";
                    else
                        cout << "There's no professor with such worker number\n\n";
                    goto PROFESSOR_SCREEN;
                }
                case 6: {
                    goto FIRST_SCREEN;
                }
                default: {
                    cerr << "\nWrong Input\n\n";
                    goto PROFESSOR_SCREEN;
                }
            }
        }
        case 3: {
            WORKER_SCREEN:
            second_screen();
            cin >> temp;
            switch (temp) {
                case 1: {     //Adding record
                    Worker temp_inp;       //stud_num recur check
                    workers.push_back(temp_inp);
                    goto WORKER_SCREEN;
                }
                case 2: {   //Printing
                    cout << "Worker number of a worker you want to print: ";
                    unsigned long temp_worknum;
                    cin >> temp_worknum;
                    Worker::print(workers, temp_worknum);
                    goto WORKER_SCREEN;
                }
                case 3: {   //Changing
                    cout << "Worker number of a worker record you want to change: ";
                    unsigned long temp_worknum;
                    cin >> temp_worknum;
                    Worker::change(workers, temp_worknum);
                    goto WORKER_SCREEN;
                }
                case 4: {   //Deleting
                    cout << "Enter information about a professor record you want to delete: \n";
                    Worker to_be_deleted;
                    auto it = find(workers.begin(), workers.end(), to_be_deleted);
                    if (it != workers.end()) {
                        workers.erase(it);
                        cout << "Record has been succesfully deleted.\n";
                    } else
                        cout << "No record with such information were found.\n";
                    goto WORKER_SCREEN;
                }
                case 5: {   //Find
                    cout << "Worker number of a worker you want to find: ";
                    unsigned long temp_worknum;
                    cin >> temp_worknum;
                    if (Worker::lookup(workers, temp_worknum))
                        cout << "There's a worker with such worker number.\n";
                    else
                        cout << "There's no worker with such worker number\n";
                    goto WORKER_SCREEN;
                }
                case 6: {
                    goto FIRST_SCREEN;
                }
                default: {
                    cerr << "\nWrong Input\n\n";
                    goto WORKER_SCREEN;
                }
            }

        }
        case 4: {
            //saving to output file;
            ofstream ofs("out.txt", ios::out);
            if (!ofs)
                cerr << ("couldn't open file");
            fin_out(ofs, students);
            return 0;
        }
        default: {
            cerr << "\nWrong Input\n\n";
            goto FIRST_SCREEN;
        }
    }

}
ostream &operator<<(ostream &out, const Student &a) {
    out << "Student | " << a.name
        << " | " << a.sex
        << " | " << a.ID
        << " | " << a.birthday
        << " | " << a.address
        << " | " << a.age
        << " | " << a.number
        << " | " << a.dormitory
        << " | " << a.major
        << " | " << a.year << endl;
    return out;
}
istream &operator>>(istream &in, Student &a) {
    in.ignore(3, '|');
    in >> a.name;
    in.ignore(2, '|');
    in >> a.sex;
    in.ignore(2, '|');
    in >> a.ID;
    in.ignore(2, '|');
    in >> a.birthday;
    in.ignore(2, '|');

    in.ignore(2, ' ');
    getline(in, a.address, '|');
    in.ignore(2, ' ');

    in >> a.age;
    in.ignore(2, '|');
    in >> a.number;
    in.ignore(2, '|');
    in >> a.dormitory;
    in.ignore(3, '|');

    in.ignore(2, ' ');
    getline(in, a.major, '|');
    in >> a.year;

    return in;
}
void Student::print(vector<Student> &X, string const &stud_num) {
    auto it = find_if(X.begin(), X.end(), [stud_num](const Student &t) -> bool {
      return t.number == stud_num;
    });
    if (it != X.end()) {
        //Record::it.print();
        cout << "\nName: " << it->name
             << "\nSex: " << it->sex
             << "\nID: " << it->ID
             << "\nBirthday: " << it->birthday
             << "\nAddress: " << it->address
             << "\nAge: " << it->age
             << "\nStudent Number: " << it->number
             << "\nDormitory Number: " << it->dormitory
             << "\nMajor: " << it->major;
        cin.ignore();
        cout << "\n\nPress any key to continue...\n";
        cin.get();
    } else {
        cout << "\nThere's no student with student number " << stud_num << endl << endl;
    }
}
void Student::change(vector<Student> &X, string const &stud_num) {
    auto it = find_if(X.begin(), X.end(), [stud_num](const Student &t) -> bool {
      return t.number == stud_num;
    });
    if (it == X.end()) {
        cout << "There's no student with such number.\nPress enter to proceed\n\n";
        cin.get();
    } else {
        cout << "A student with number " << stud_num << " has been succefully found.\n\n"
             << "Now you can change all information.\n";
        cout << "Please enter Name: ";
        getline(cin, it->name);                            //add feature to leave the same info after pressing enter
        cout << "             Sex: ";
        cin >> it->sex;
        cout << "             ID: ";
        getline(cin, it->ID);
        cout << "             Birthday: ";
        getline(cin, it->birthday);
        cout << "             Address: ";
        //cin.ignore();
        getline(cin, it->address);
        cout << "             Age: ";
        cin >> it->age;
        cout << "             Student Number: ";
        getline(cin, it->number);
        //cin.ignore();
        cout << "             Dormitory Number: ";
        getline(cin, it->dormitory);
        cout << "             Major: ";
        getline(cin, it->major);
        cout << "             Year: ";
        cin >> it->year;
//        cin.ignore();
        cout << "Press any key to continue...\n";
        cin.get();
    }
}
bool Student::lookup(vector<Student> &X, string const &stud_num) {
    auto it = find_if(X.begin(), X.end(), [stud_num](const Student &t) -> bool {
      return t.number == stud_num;
    });

    return it == X.end() ? false : true;
}

ostream &operator<<(ostream &out, const Professor &a) {
    out << "Professor | " << a.name
       << " | " << a.sex
       << " | " << a.ID
       << " | " << a.birthday
       << " | " << a.address
       << " | " << a.age
       << " | " << a.worker_number
       << " | " << a.appartment
       << " | " << a.dailyHours
       << " | " << a.salary
       << " | " << a.fieldOfTeaching
       << " | " << a.research
       << " | " << a.numOfPostgrads << endl;
    return out;
}
istream &operator>>(istream &in, Professor &a) {
    in.ignore(3, '|');
    in >> a.name;
    in.ignore(2, '|');
    in >> a.sex;
    in.ignore(2, '|');
    in >> a.ID;
    in.ignore(2, '|');
    in >> a.birthday;
    in.ignore(2, '|');

    in.ignore(2, ' ');
    getline(in, a.address, '|');
    in.ignore(2, ' ');

    in >> a.age;
    in.ignore(2, '|');
    in >> a.worker_number;
    in.ignore(2, '|');
    in.ignore(2, ' ');
    getline(in, a.address, '|');
    in.ignore(2, ' ');
    in >> a.dailyHours;
    in.ignore(2, '|');
    in >> a.salary;

    in.ignore(2, '|');
    in.ignore(2, ' ');
    getline(in, a.fieldOfTeaching, '|');
    in.ignore(2, ' ');

    in.ignore(2, '|');
    in.ignore(2, ' ');
    getline(in, a.research, '|');
    in.ignore(2, ' ');
    cin >> a.numOfPostgrads;

    return in;
}
void Professor::print(vector<Professor> &X, const unsigned long &work_num) {
    auto it = find_if(X.begin(), X.end(), [work_num](const Professor &t) -> bool {
      return t.worker_number == work_num;
    });
    if (it != X.end()) {
        cout << "\nName: " << it->name
             << "\nSex: " << it->sex
             << "\nID: " << it->ID
             << "\nBirthday: " << it->birthday
             << "\nAddress: " << it->address
             << "\nAge: " << it->age
             << "\nWorker Number: " << it->worker_number
             << "\nAppartment: " << it->appartment
             << "\nWorking Hours: " << it->dailyHours
             << "\nSalary: " << it->salary
             << "\nField Of Teaching: " << it->fieldOfTeaching
             << "\nResearch Project: " << it->research
             << "\nNumber Of Postgraduate Students: " << it->numOfPostgrads;
//        cin.ignore();
        cout << "\n\nPress any key to continue...\n\n";
        cin.get();
    } else {
        cout << "There's no professor with number " << work_num << endl << endl;
    }
}
void Professor::change(vector<Professor> &X, const unsigned long &work_num) {
    auto it = find_if(X.begin(), X.end(), [work_num](const Professor &t) -> bool {
      return t.worker_number == work_num;
    });
    if (it == X.end()) {
        cout << "There's no record with such number.\nPress enter to proceed\n\n";
        cin.get();
    } else {
        cout << "A professor with number " << work_num << " has been succefully found.\n\n"
             << "Now you can change all information.\n";
        cout << "Please enter Name: ";
        cin.ignore();
        getline(cin, it->name);
        //add feature to leave the same info after pressing enter
        cout << "             Sex: ";
        cin >> it->sex;
        cout << "             ID: ";
        cin.ignore();
        getline(cin, it->ID);
        cout << "             Birthday: ";
        getline(cin, it->birthday);
        cout << "             Address: ";
//        cin.ignore();
        getline(cin, it->address);
        cout << "             Age: ";
        cin >> it->age;
        cout << "             Worker Number: ";
        cin >> it->worker_number;
        cin.ignore();     // skips \n
        cout << "             Appartment: ";
        getline(cin, it->appartment);
        cout << "             Working Hours: ";
        cin >> it->dailyHours;
        cout << "             Salary: ";
        cin >> it->salary;
        cin.ignore();     // skips \n
        cout << "             Field Of Teaching: ";
        getline(cin, it->fieldOfTeaching);
        cout << "             Research Project: ";
        getline(cin, it->research);
        cout << "             Number Of Postgraduate Students: ";
        cin >> it->numOfPostgrads;
//        cin.ignore();
        cout << "Press any key to continue...\n";
        cin.get();
    }
}
bool Professor::lookup(vector<Professor> &X, const unsigned long &work_num) {
    auto it = find_if(X.begin(), X.end(), [work_num](const Professor &t) -> bool {
      return t.worker_number == work_num;
    });

    return it == X.end() ? false : true;
}

ostream &operator<<(ostream &out, const Worker &a) {
    out << "Worker | " << a.name
       << " | " << a.sex
       << " | " << a.ID
       << " | " << a.birthday
       << " | " << a.address
       << " | " << a.age
       << " | " << a.worker_number
       << " | " << a.appartment
       << " | " << a.dailyHours
       << " | " << a.salary
       << " | " << a.job << endl;
    return out;
}
istream &operator>>(istream &in, Worker &a) {
    in.ignore(3, '|');
    in >> a.name;
    in.ignore(2, '|');
    in >> a.sex;
    in.ignore(2, '|');
    in >> a.ID;
    in.ignore(2, '|');
    in >> a.birthday;
    in.ignore(2, '|');

    in.ignore(2, ' ');
    getline(in, a.address, '|');
    in.ignore(2, ' ');

    in >> a.age;
    in.ignore(2, '|');
    in >> a.worker_number;
    in.ignore(2, '|');
    in.ignore(2, ' ');
    getline(in, a.address, '|');
    in.ignore(2, ' ');
    in >> a.dailyHours;
    in.ignore(2, '|');
    in >> a.salary;
    in.ignore(2, '|');
    in.ignore(2, ' ');
    getline(in, a.job, '|');
    in.ignore(2, ' ');
    return in;
}
void Worker::print(vector<Worker> &X, const unsigned long &work_num) {
    auto it = find_if(X.begin(), X.end(), [work_num](const Worker &t) -> bool {
      return t.worker_number == work_num;
    });
    if (it != X.end()) {
        cout << "\nName: " << it->name
             << "\nSex: " << it->sex
             << "\nID: " << it->ID
             << "\nBirthday: " << it->birthday
             << "\nAddress: " << it->address
             << "\nAge: " << it->age
             << "\nWorker Number: " << it->worker_number
             << "\nAppartment: " << it->appartment
             << "\nWorking Hours: " << it->dailyHours
             << "\nSalary: " << it->salary
             << "\nJob: " << it->job;
//        cin.ignore();
        cout << "\n\nPress any key to continue...\n\n";
        cin.get();
    } else {
        cout << "There's no worker with number " << work_num << endl;
    }
}
void Worker::change(vector<Worker> &X, const unsigned long &work_num) {
    auto it = find_if(X.begin(), X.end(), [work_num](const Worker &t) -> bool {
      return t.worker_number == work_num;
    });
    if (it == X.end()) {
        cout << "There's no record with such number.\nPress enter to proceed\n\n";
        cin.get();
    } else {
        cout << "A worker with number " << work_num << " has been succefully found.\n\n"
             << "Now you can change all information.\n";
        cout << "Please enter Name: ";
        getline(cin, it->name);                            //add feature to leave the same info after pressing enter
        cout << "             Sex: ";
        cin >> it->sex;
        cout << "             ID: ";
        getline(cin, it->ID);
        cout << "             Birthday: ";
        getline(cin, it->birthday);
        cout << "             Address: ";
//        cin.ignore();
        getline(cin, it->address);
        cout << "             Age: ";
        cin >> it->age;
        cout << "             Worker Number: ";
        cin >> it->worker_number;
//        cin.ignore();     // skips \n
        cout << "             Appartment: ";
        getline(cin, it->appartment);
        cout << "             Working Hours: ";
        cin >> it->dailyHours;
        cout << "             Salary: ";
        cin >> it->salary;
//        cin.ignore();     // skips \n
        cout << "             Job: ";
        getline(cin, it->job);
//        cin.ignore();
        cout << "Press any key to continue...\n";
        cin.get();
    }
}
bool Worker::lookup(vector<Worker> &X, const unsigned long &work_num) {
    auto it = find_if(X.begin(), X.end(), [work_num](const Worker &t) -> bool {
      return t.worker_number == work_num;
    });

    return !(it == X.end()) /*? false : true*/;
}