// 21 задание 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
struct record {
    std::string name;
    std::string surname;
    std::string date;
    double amount;
};




bool date(record* rec)
{
    int day, month, year;
    if (rec->date[0] == 0)
    {
        day = std::stoi(rec->date.substr(1, 1));
    }
    else
    {
        day = std::stoi(rec->date.substr(0, 2));

    }
    if (rec->date[3] == 0)
    {
        month = std::stoi(rec->date.substr(4, 1));
    }
    else
    {
        month = std::stoi(rec->date.substr(3, 2));

    }

    year = std::stoi(rec->date.substr(6, 4));
    if ((day > 0 && day < 31) && (month > 0 && month < 12) && (year > 0 && year < 2026))
    {
        return true;
    }
    else
        return false;
}
bool nameSurname(record * rec)
{
    if ((char(rec->name[0]) > 64 && char(rec->name[0]) < 91) && (char(rec->surname[0]) > 64 && char(rec->surname[0]) < 91))
    {
        return true;
    }
    else
    {
        return false;
    }

}
void listRecords(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "No records found."<<std::endl;
        return;
    }

    std::vector<record> records;
    record rec;

    while (file >> rec.name) {
        if (file.eof()) break;
        file >> rec.name >> rec.date >> rec.amount;
        records.push_back(rec);
    }
    file.close();

    if (records.empty()) {
        std::cout << "No records found." << std::endl;
    }
    else {
        for (const auto& r : records) {
            std::cout << r.name << " " << r.surname << " "
                << r.date << " " << r.amount << std::endl;
        }
    }
}
void addRecord(const std::string& filename) {
    std::ofstream file(filename, std::ios::app); 
    if (!file) {
        std::cerr << "Error: cannot open file for writing." << std::endl;
        return;
    }

    record rec;
    record* rec_ptr = &rec;
    do {
       
    std::cout << "Enter  name and surname: ";
    std::cin >> rec.name >> rec.surname;
   
        if (!nameSurname(rec_ptr)) {
            std::cout << "Invalid Name or Surname. Try again." << std::endl;
        }
    } while (!nameSurname(rec_ptr));
   
    do {
        std::cout << "Enter date (DD.MM.YYYY): ";
        std::cin >> rec.date;
        if (!date(rec_ptr)) {
            std::cout << "Invalid date. Try again." << std::endl;
        }
    } while (!date(rec_ptr));

    do {
        std::cout << "Enter amount: ";
        std::cin >> rec.amount;
        if (rec.amount <= 0) {
            std::cout << "Amount must be positive. Try again." << std::endl;
        }
    } while (rec.amount <= 0);

    file << rec.name << " " << rec.surname << " "
        << rec.date << " " << rec.amount << "\n";

    file.close();
    std::cout << "Record added successfully." << std::endl;
}





int main()
{
   
    do {
        std::string command;
        std::string filename = "vedomost.txt";

        std::cout << "Enter command (list / add / close): ";
        std::cin >> command;

        if (command == "list") {
            listRecords(filename);
        }
        else if (command == "add") {
            addRecord(filename);
        }
        else if(command == "close")
        {
            break;
        }
        else
        {
            std::cerr << "Unknown command." << std::endl;

        }

      

    } while (true);
  
    return 0;

}

