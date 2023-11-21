#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <ctime>

using namespace std;

// below codes are for Q1
class DATA
{
private:
    string fileName;

public:
    DATA(const string &fileName)
    {
        this->fileName = fileName;
    }

    int readCSV(vector<vector<string>> &data1)
    {
        string line;
        ifstream file(fileName);

        if (!file.is_open())
        {
            cout << "Can't open the file " << fileName << "\n";
            return 0;
        }

        while (getline(file, line))
        {
            vector<string> row;
            stringstream ss(line);
            string col;

            while (getline(ss, col, ','))
            {
                row.push_back(col);
            }

            data1.push_back(row);
        }

        file.close();
        return 1;
    }
};

// below codes are for Q2

class VOL_DATA
{
private:
    string fileName;

public:
    VOL_DATA(const string &fileName)
    {
        this->fileName = fileName;
    }

    int readCSV(vector<vector<string>> &data2)
    {
        string line;
        ifstream file(fileName);

        if (!file.is_open())
        {
            cout << "Can't open the file " << fileName << "\n";
            return 0;
        }

        while (getline(file, line))
        {
            vector<string> row;
            stringstream ss(line);
            string col;

            while (getline(ss, col, ','))
            {
                row.push_back(col);
            }

            data2.push_back(row);
        }

        file.close();
        return 1;
    }
};

// below codes are for Q3

struct Person
{
    string firstName;
    string lastName;
    string age;
    string gender;
    string address;
};

vector<Person> readDataFromFile(string fileName)
{
    vector<Person> persons;

    ifstream infile(fileName);
    if (!infile.is_open())
    {
        cout << "Error opening file: " << fileName << endl;
        return persons;
    }

    string line;
    while (getline(infile, line))
    {
        Person person;

        vector<string> fields;
        string field;
        stringstream ss(line);
        while (getline(ss, field, ','))
        {
            fields.push_back(field);
        }

        person.firstName = fields[0];
        person.lastName = fields[1];
        person.age = fields[2];
        person.gender = fields[3];
        person.address = fields[4];

        persons.push_back(person);
    }

    infile.close();

    return persons;
}

Person findPersonData(vector<Person> &persons, string name)
{
    for (int i = 0; i < persons.size(); i++)
    {
        if (persons[i].firstName == name || persons[i].lastName == name)
        {
            return persons[i];
        }
    }

    Person person;
    person.firstName = "";
    person.lastName = "";
    person.age = "";
    person.gender = "";
    person.address = "";

    return person;
}

void open3()
{
    string fileName = "A4-Q3.csv";
    vector<Person> persons = readDataFromFile(fileName);

    string nameToFind;
    cout << "\nEnter the name of the person to find: ";
    cin >> nameToFind;

    Person person = findPersonData(persons, nameToFind);

    if (person.firstName != "")
    {
        cout << "\nPerson data found:\n"
             << endl;
        cout << "First Name: " << person.firstName << endl;
        cout << "Last Name: " << person.lastName << endl;
        cout << "Age: " << person.age << endl;
        cout << "Gender: " << person.gender << endl;
        cout << "Address: " << person.address << endl;
        cout << "\n";
    }
    else
    {
        cout << "\nPerson data not found.\n"
             << endl;
    }
}

// bellow code are for Q4

struct Person2
{
    string vehicleNumber;
    string firstName;
    string lastName;
    string age;
    string gender;
    string address;
};

vector<Person2> readDataFromFile2(const string &fileName)
{
    vector<Person2> persons2;
    ifstream infile(fileName);

    if (!infile.is_open())
    {
        cout << "Error opening file: " << fileName << endl;
        return persons2;
    }

    string line;
    // Skip the header line
    getline(infile, line);

    while (getline(infile, line))
    {
        Person2 person2;
        vector<string> fields;
        string field;
        stringstream ss(line);

        while (getline(ss, field, ','))
        {
            fields.push_back(field);
        }

        person2.vehicleNumber = fields[1];
        person2.firstName = fields[2];
        person2.lastName = fields[3];
        person2.age = fields[4];
        person2.gender = fields[5];
        person2.address = fields[6];

        persons2.push_back(person2);
    }

    infile.close();
    return persons2;
}

Person2 findPersonByVehicleNumber(const vector<Person2> &persons2, const string &vehicleNumber)
{
    for (const auto &p : persons2)
    {
        if (p.vehicleNumber == vehicleNumber)
        {
            return p;
        }
    }

    return {};
}

void open4()
{
    string fileName = "A4-Q1.csv"; //
    vector<Person2> persons2 = readDataFromFile2(fileName);

    string vehicleNumber;
    cout << "Enter the Vehicle Number to find information: ";
    cin >> vehicleNumber;

    Person2 foundPerson = findPersonByVehicleNumber(persons2, vehicleNumber);

    if (!foundPerson.vehicleNumber.empty())
    {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        int seconds = ltm->tm_sec;
        string nameOfWitness;

        if (seconds % 2 == 0)
        {

            cout << "\nEnter name of witness : ";
            cin >> nameOfWitness;
            cout << "\n";
        }
        cout << "Car data found:" << endl;
        cout << "Vehicle Number: " << foundPerson.vehicleNumber << endl;
        cout << "First Name: " << foundPerson.firstName << endl;
        cout << "Last Name: " << foundPerson.lastName << endl;
        cout << "Age: " << foundPerson.age << endl;
        cout << "Gender: " << foundPerson.gender << endl;
        cout << "Address: " << foundPerson.address << endl;
        if (seconds % 2 == 0)
        {
            cout << "\nThis car is invloved in accident..." << endl;
            cout << "Witness name is " << nameOfWitness << endl;
        }
        else
        {
            cout << "\nThis car is not involved in any accident...\n"
                 << endl;
        }
    }
    else
    {
        cout << "Car with Vehicle Number " << vehicleNumber << " not found.\n"
             << endl;
    }
}

int choice()
{
    int choice;
    cout << "\n0. Exit" << endl;
    cout << "1. Main menu." << endl;
    cout << "Choose your option: ";
    cin >> choice;
    return choice;
}
int main()
{
    int count = 0;

    DATA csvReader1("A4-Q1.csv");
    vector<vector<string>> data1;
    VOL_DATA csvReader2("A4-Q2.csv");
    vector<vector<string>> data2;

    cout << "\nWelcome to the program!\n"
         << endl;

    while (1)
    {

        cout << "\n1. Show the data of all vehicles." << endl;
        cout << "2. Show the details of those vehicles who involved in voilation of rules." << endl;
        cout << "3. To check the details of any person in updated Address list." << endl;
        cout << "4. To check accident status of any vehicle." << endl;
        cout << "5. Exit" << endl;

        cout << "\nEnter your choice : ";
        cin >> count;
        switch (count)
        {
        case 1:
            // Q1 starts from here

            if (csvReader1.readCSV(data1))
            {
                for (const auto &row : data1)
                {
                    for (const auto &col : row)
                    {
                        cout << col;
                        cout << "\t";
                    }
                    cout << endl;
                }
                cout << endl;
            }
            if (!choice())
            {
                return 0;
            }
            break;

        case 2:
            // Q2 starts from here

            if (csvReader2.readCSV(data2))
            {
                for (const auto &row : data2)
                {
                    for (const auto &col : row)
                    {
                        cout << col;
                        cout << "\t";
                    }
                    cout << endl;
                }
                cout << endl;
            }
            if (!choice())
            {
                return 0;
            }

            break;

        case 3:
            // Q3 starts from here
            open3();
            if (!choice())
            {
                return 0;
            }
            break;

        case 4:

            // Q4 starts from here
            open4();
            if (!choice())
            {
                return 0;
            }
            break;

        case 5:
            // end the program
            exit(1);
            break;

        default:
            cout << "Wrong input.." << endl;
        }
    }
}