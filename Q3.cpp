#include <iostream>
#include <fstream>
#include<sstream>
#include <string>
#include <vector>

using namespace std;

struct Person {
  string firstName;
  string lastName;
  string age;
  string gender;
  string address;
};

vector<Person> readDataFromFile(string fileName) {
  vector<Person> persons;

  ifstream infile(fileName);
  if (!infile.is_open()) {
    cout << "Error opening file: " << fileName << endl;
    return persons;
  }

  string line;
  while (getline(infile, line)) {
    Person person;

    vector<string> fields;
    string field;
    stringstream ss(line);
    while (getline(ss, field, ',')) {
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

Person findPersonData(vector<Person>& persons, string name) {
  for (int i = 0; i < persons.size(); i++) {
    if (persons[i].firstName == name || persons[i].lastName == name) {
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

int main() {
  string fileName = "A4-Q3.csv";
  vector<Person> persons = readDataFromFile(fileName);

  string nameToFind;
  cout << "Enter the name of the person to find: ";
  cin >> nameToFind;

  Person person = findPersonData(persons, nameToFind);

  if (person.firstName != "") {
    cout << "Person data found:" << endl;
    cout << "First Name: " << person.firstName << endl;
    cout << "Last Name: " << person.lastName << endl;
    cout << "Age: " << person.age << endl;
    cout << "Gender: " << person.gender << endl;
    cout << "Address: " << person.address << endl;
  } else {
    cout << "Person data not found." << endl;
  }

  return 0;
}
