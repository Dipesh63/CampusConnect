#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student {
    string name;
    string email;
    vector<vector<string>> festsName;

public:
    void setData() {
        cout << "Enter the name: ";
        cin >> name;
        cout << "Enter the email (XXXXXXXXXX@gmail.com): ";
        cin >> email;
    }

    string getName() const {
        return name;
    }

    string getEmail() const {
        return email;
    }

    void registerForFest(const vector<string>& registeredFests) {
        festsName.push_back(registeredFests);
    }
};

class Club {
    string clubName;
    vector<Student*> registeredStudents;
    vector<string> festInformation;

public:
    void setData() {
        cout << "Enter the club name: ";
        cin >> clubName;
        cout << "Enter the fest name and date (Name-DD-MM-YYYY): ";
        string festInfo;
        cin.ignore();
        getline(cin, festInfo);
        festInformation.push_back(festInfo);
    }

    string getName() const {
        return clubName;
    }

    void showFestInformation() const {
        cout << "Fest information for " << clubName << " club:\n";
        for (const string& info : festInformation) {
            cout << info << endl;
        }
    }

    void registerStudent(Student* student) {
        registeredStudents.push_back(student);
    }

    void showRegisteredStudents() const {
        cout << "Registered students for " << clubName << " club:\n";
        for (const Student* student : registeredStudents) {
            cout << "Name: " << student->getName() << ", Email: " << student->getEmail() << endl;
        }
    }
};

class Workshop {
    string workshopName;
    vector<Student*> registeredStudents;
    vector<string> workshopInformation;

public:
    void setData() {
        cout << "Enter the workshop name: ";
        cin >> workshopName;
        cout << "Enter the workshop information: ";
        string workshopInfo;
        cin.ignore();
        getline(cin, workshopInfo);
        workshopInformation.push_back(workshopInfo);
    }

    string getName() const {
        return workshopName;
    }

    void showWorkshopInformation() const {
        cout << "Workshop information for " << workshopName << ":\n";
        for (const string& info : workshopInformation) {
            cout << info << endl;
        }
    }

    void registerStudent(Student* student) {
        registeredStudents.push_back(student);
    }

    void showRegisteredStudents() const {
        cout << "Registered students for " << workshopName << ":\n";
        for (const Student* student : registeredStudents) {
            cout << "Name: " << student->getName() << ", Email: " << student->getEmail() << endl;
        }
    }
};

int main() {
    Student students[10];
    int numStudents = 0;

    Club clubs[3];
    int numClubs = 0;

    Workshop workshops[2];
    int numWorkshops = 0;

    string command;
    while (true) {
        cout << "1) Enter any keyword to start the project" << endl;
        cout << "2) Enter a command ('exit' to quit): ";
        cin >> command;

        if (command == "exit") {
            break;
        }

        int userRole;
        cout << "Enter user role (1 for student, 2 for club member,3 for workshop member): ";
        cin >> userRole;

        switch (userRole) {
            case 1: { // Student
                int action;
                cout << "Enter action (1 to view fest information, 2 to view workshop information): ";
                cin >> action;

                switch (action) {
                    case 1:
                        for (int i = 0; i < numClubs; i++) {
                            clubs[i].showFestInformation();
                            cout << "And Press " << i + 1 << " to execute this" << endl;
                        }
                        int choice;
                        cin >> choice;
                        if (choice > 0 && choice <= numClubs) {
                            students[numStudents].setData();
                            clubs[choice - 1].registerStudent(&students[numStudents]);
                            numStudents++;
                        } else {
                            cout << "Invalid choice!" << endl;
                        }
                        break;
                    case 2:
                        for (int i = 0; i < numWorkshops; i++) {
                            workshops[i].showWorkshopInformation();
                            cout << "And Press " << i + 1 << " to execute this" << endl;
                        }
                        cin >> choice;
                        if (choice > 0 && choice <= numWorkshops) {
                            students[numStudents].setData();
                            workshops[choice - 1].registerStudent(&students[numStudents]);
                            numStudents++;
                        } else {
                            cout << "Invalid choice!" << endl;
                        }
                        break;
                    default:
                        cout << "Invalid action!" << endl;
                        break;
                }
                break;
            }

            case 2: { // Club Member / Workshop Organizer
                int action;
                cout << "Enter action (1 to view registered students for a fest, 2 to announce students for a fest): ";
                cin >> action;

                switch (action) {
                    case 1:
                        for (int i = 0; i < numClubs; i++) {
                            clubs[i].showRegisteredStudents();
                        }
                        break;


                    case 2:

                        {
                            clubs[numClubs].setData();numClubs++;
                        }
                        break;

                         default:
                        cout << "Invalid action!" << endl;
                        break;
                }
                break;
            }
                    case 3:
                         { // Club Member / Workshop Organizer
                int action;
                cout << "Enter action (1 to view registered students for a workshop, 2 to announce students for a workshop): ";
                cin >> action;

                switch (action) {
                     case 1:
                        for (int i = 0; i < numWorkshops; i++) {
                            workshops[i].showRegisteredStudents();
                        }
                        break;



                        case 2:

                        {
                           workshops[numWorkshops ].setData();numWorkshops ++;
                        }
                        break;


                         default:
                        cout << "Invalid action!" << endl;
                        break;
                }
                break;
                         }

                }

            }


        }

