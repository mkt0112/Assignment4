#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class VOL_DATA
{
private:
    string fileName;

public:
    VOL_DATA(const string &fileName)
    {
        this->fileName = fileName;
    }

    int readCSV(vector<vector<string>> &data)
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

            data.push_back(row);
        }

        file.close();
        return 1;
    }
};

int main()
{
    VOL_DATA csvReader2("A4-Q2.csv");

    vector<vector<string>> data;

    if (csvReader2.readCSV(data))
    {
        for (const auto &row : data)
        {
            for (const auto &col : row)
            {
                cout << col;
                cout << "\t";
            }
            cout << endl;
        }
    }
}
