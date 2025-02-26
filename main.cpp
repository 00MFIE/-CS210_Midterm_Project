#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;


struct School {
    string name;
    string address;
    string city;
    string state;
    string country;
    School* next;
};

class SchoolList
{
    School* head = nullptr;

public:
    void insertFirst(School school) {
        School* SchoolNode = new School(school.name, school.address, school.city, school.state, school.country);
        if (head == nullptr) {
            head = SchoolNode;
        }
        else {
            SchoolNode->next = head;
            head = SchoolNode;
        }

    }
    void insertLast(School school) {
        School* SchoolNode = new School(school.name, school.address, school.city, school.state, school.country);

        if (head == nullptr) {
            head = SchoolNode;
        }
        else {
            School* temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = SchoolNode;
        }

    }
    void deleteByName(string name) {
        School* current = head;
        School* prev = nullptr;
        if (current == nullptr) {
            cout<<"List is empty!" << endl;
            return;
        }

        while (current != nullptr) {
            if (current->name == name) {
                break;
            }
            prev = current;
            current = current->next;
        }
        if(current==nullptr) {
            cout<<"The Name is not present in the list!"<<endl;
        }
        else if (head->name==name){
            School* temp = head;
            head = head->next;
            delete temp;
        }
        else {
            prev->next = current->next;
        }


    }
    void findByName(string name) {
        School* temp = head;

        if (temp == nullptr) {
            cout<<"List is empty!"<<endl;
            return;
        }
        while (temp != nullptr){
            if (temp->name == name) {
                cout << temp->name << "," << temp->address << "," << temp->city << "," << temp->state << "," << temp->country << endl;
                return;
            }
            temp = temp->next;
        }
        if(temp==nullptr) {
            cout<<"The Name is not present in the list!"<<endl;
        }
    }

    void display() {
        School* temp = head;
        while (temp != nullptr) {
            cout << temp->name << "," << temp->address << "," << temp->city << "," << temp->state << "," << temp->country << endl;
            temp = temp->next;
        }
    }

};

static vector<vector<string>> readCSV(const string& filename, School& school,int column) {
    ifstream file(filename);
    vector<vector<string>> data;
    string line, word;

    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return data;
    }

    while (getline(file, line)) {
        stringstream ss(line);
        vector<string> row;

        while (getline(ss, word, ',')) {
            row.push_back(word);
        }
        data.push_back(row);
    }

    school.name = data[column][0];
    school.address = data[column][1];
    school.city = data[column][2];
    school.state = data[column][3];
    school.country = data[column][4];

    file.close();
    return data;
}

int main() {
    SchoolList list;
    School schoolarr1;
    School schoolarr2;
    School schoolarr3;


    readCSV("SchoolList.csv", schoolarr1, 1);
    readCSV("SchoolList.csv", schoolarr2, 2);
    readCSV("SchoolList.csv", schoolarr3, 3);
    list.insertLast(schoolarr1);
    list.insertLast(schoolarr2);
    list.insertFirst(schoolarr3);
    list.display();
    list.findByName("PLEASANT VALLEY MIDDLE SCHOOL");
    list.deleteByName("PLEASANT VALLEY MIDDLE SCHOOL");
    list.insertLast(schoolarr3);
    list.display();

}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.