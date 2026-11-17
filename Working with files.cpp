/*************************************
* Автор:   Кучина Мария              *
* Задание: Работа с файлами          *
* Вариант: 11                        *
**************************************/
  #include <iostream>
  #include <vector>
  #include <string>
  #include <fstream>

  using namespace std;

  struct Record {
      string departmentName;
      string configuration;
      int quantity;
      int purchaseYear;
  };

  int main() {
      const int INITIAL_MIN_YEAR = 2100;

      vector<Record> records;
      string fileName;
    
      cout << "Enter file name: ";
      cin >> fileName;

      ifstream inputFile(fileName);

      if (!inputFile.is_open()) {
          cout << "Error: Could not open file " << fileName << endl;
          return 1;
      }

      Record tempRecord;

      while (inputFile >> tempRecord.departmentName >> tempRecord.configuration >> tempRecord.quantity >> tempRecord.purchaseYear) {
          records.push_back(tempRecord);
      }

      inputFile.close();

      string targetDepartment;
      cout << "Enter department to search: ";
      cin >> targetDepartment;

      int totalComputers = 0;
      bool isFound = false;
      int oldestYear = INITIAL_MIN_YEAR;

      for (int i = 0; i < records.size(); i++) {
          if (records[i].departmentName == targetDepartment) {
              isFound = true;
              totalComputers += records[i].quantity;
          }

          if (records[i].purchaseYear < oldestYear) {
            oldestYear = records[i].purchaseYear;
          }
      }

      if (!isFound) {
          cout << "Department not found: " << targetDepartment << endl;
      }
      else {
          cout << "Total computers in " << targetDepartment << ": " << totalComputers << endl;
      }

      if (records.empty()) {
          cout << "Oldest computers: NONE" << endl;
      }
      else {
          cout << "Oldest computers (purchased in " << oldestYear << "):" << endl;

          for (int i = 0; i < records.size(); i++) {
              if (records[i].purchaseYear == oldestYear) {
                  cout << "- Dept: " << records[i].departmentName << ", Config: " << records[i].configuration << ", Qty: " << records[i].quantity << endl;
              }
          }
      }

      return 0;
  }