/*# Employee Pension & Student Grade Calculator
<h1>Student_ID Name -s Bachelor's of Science in IT</h1>

<h2> Question </h2>
<p>1.write a cpp program that will employ structures and will compute the pension of each UNESWA employee which given by : 5% of the monthly gross * their tenure at UNESWA. Take note that there is 0 pension for employees with less than 10 years.

2.Write a cpp with structs program that will compute the grade of a student given that 20% goes to an assignment, 30% to a test and 50% for an exam. </p>

##Student notes to supervisor
This single source file combines both questions but seperates them using namespaces. I took some liberty to add an excess of features to make the project
as usable as possible.

This was developed and tested on EndeavourOS, tested on Arch, Fedora and Windows. See below for additional instructions.

If you fail to compile, kindly visit the bin folder to find the assignment's binaries, compiled by me, if you are inclined.

For more projects, please see my GitHub Repository.
https://github.com/Euclidae

## Feature Overview
- **Employee Pension Calculator**
  - Automatic pension calculation based on tenure and salary
  - Minimum tenure requirement (10 years)
  - File save/load functionality
- **Student Grade Calculator**
  - Final mark calculation (20% assignment, 30% test, 50% exam)
  - Grade symbol allocation (A-F)
  - File save/load functionality
- **Cross-Platform Support**
  - Works on Windows and Linux
  - Automatic terminal clearing (OS-appropriate)
  - Consistent file paths handling
- **Error Handling**
  - Input validation
  - File operation error checking
  - Type safety checks */

#include <iostream>
#include <limits>
#include <string>
#include <fstream>

#ifdef _WIN32
#define wipe "cls"
#else
#define wipe "clear"
#endif

namespace UNESWA {
    const unsigned char min_tenure = 10;

    struct Employee {
        std::string name;
        std::string surname;
        unsigned char tenure;
        double salary;
        double pension;
    };

    void calculate_pension(Employee& emp) {
        if (emp.tenure < min_tenure) {
            std::cout << "Candidate does not qualify for pension\n";
            emp.pension = 0.0;
            return;
        }
        emp.pension = (0.05 * emp.salary) * emp.tenure;
    }

    void clean_up() {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        system(wipe);
    }

    std::istream& operator >> (std::istream& is, Employee& emp){
        is >> emp.name >> emp.surname >> emp.tenure >> emp.salary;
        return is;
    }

    std::ostream& operator << (std::ostream& os, const Employee& emp) {
        os << "Name: " << emp.name << " " << emp.surname << "\n";
        os << "Tenure: " << static_cast<int>(emp.tenure) << " years\n";
        os << "Salary: " << emp.salary << "\n";
        os << "Pension: " << emp.pension << "\n";
        return os;
    }

    bool fetch_from_file(const std::string& location, Employee& emp){
        std::ifstream file_stream(location, std::ios::in);

        if(!file_stream.is_open()){
            std::cerr << "Error: File '" << location << "' not found or cannot be opened\n";
            return false;
        }

        if(file_stream >> emp) {
            calculate_pension(emp);
            std::cout << "Employee data loaded successfully\n";
            std::cout << emp;
            return true;
        } else {
            std::cerr << "Error: Could not read data from file. Check file format.\n";
            return false;
        }
    }

    bool save_to_file(const std::string& location, const Employee& emp) {
        std::ofstream file_stream(location, std::ios::out);

        if(!file_stream.is_open()){
            std::cerr << "Error: Could not open file '" << location << "' for writing\n";
            return false;
        }

        file_stream << emp.name << " " << emp.surname << " "
                   << static_cast<int>(emp.tenure) << " " << emp.salary;

        if(file_stream.fail()) {
            std::cerr << "Error: Failed to write to file\n";
            return false;
        }

        std::cout << "Employee data saved successfully to " << location << "\n";
        return true;
    }

    void init(Employee& emp){
        std::cout << "Input Name: ";
        std::getline(std::cin, emp.name);

        std::cout << "Input Surname: ";
        std::getline(std::cin, emp.surname);

        while (true) {
            std::cout << "Enter tenure: ";
            if (std::cin >> emp.tenure) {
                break;
            } else {
                std::cout << "Please enter a valid integer. ";
                clean_up();
                continue;
            }
        }
        clean_up();

        while (true) {
            std::cout << "Enter monthly salary: ";
            if (std::cin >> emp.salary) {
                break;
            } else {
                std::cout << "Please enter a valid salary. ";
                clean_up();
                continue;
            }
        }
        clean_up();

        calculate_pension(emp);
        std::cout << emp;
    }
}

namespace STUDENT {
    struct Student {
        std::string name;
        std::string surname;
        double assignment_mark;
        double test_mark;
        double exam_mark;
        double final_mark;
    };

    void clean_up() {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        system(wipe);
    }

    char get_symbol(const Student& stu){
        char symbol;
        if(stu.final_mark >= 90){
            symbol = 'A';
        }else if(stu.final_mark >= 80){
            symbol = 'B';
        }else if(stu.final_mark >= 70){
            symbol = 'C';
        }else if(stu.final_mark >= 60){
            symbol = 'D';
        }else if(stu.final_mark >=50){
            symbol = 'E';
        }else{
            symbol = 'F';
        }
        return symbol;
    }

    void calculate_grade(Student& stu) {
        stu.final_mark = (0.2 * stu.assignment_mark) +
                         (0.3 * stu.test_mark) +
                         (0.5 * stu.exam_mark);
    }

    std::istream& operator >> (std::istream& is, Student& stu) {
        is >> stu.name >> stu.surname >> stu.assignment_mark >> stu.test_mark >> stu.exam_mark;
        return is;
    }

    std::ostream& operator << (std::ostream& os,const Student& stu) {
        os << "Name: " << stu.name << " " << stu.surname << "\n";
        os << "Assignment Mark: " << stu.assignment_mark << "\n";
        os << "Test Mark: " << stu.test_mark << "\n";
        os << "Exam Mark: " << stu.exam_mark << "\n";
        os << "Final Mark: " << stu.final_mark << "\n";
        os << "Symbol: " << get_symbol(stu) << "\n";
        return os;
    }

    bool fetch_from_file(const std::string& location, Student& stu) {
        std::ifstream file_stream(location, std::ios::in);

        if(!file_stream.is_open()) {
            std::cerr << "Error: File '" << location << "' not found or cannot be opened\n";
            return false;
        }

        if(file_stream >> stu) {
            calculate_grade(stu);
            std::cout << "Student data loaded successfully\n";
            std::cout << stu;
            return true;
        } else {
            std::cerr << "Error: Could not read data from file. Check file format.\n";
            return false;
        }
    }

    bool save_to_file(const std::string& location, const Student& stu) {
        std::ofstream file_stream(location, std::ios::out);

        if(!file_stream.is_open()) {
            std::cerr << "Error: Could not open file '" << location << "' for writing\n";
            return false;
        }

        file_stream << stu.name << " " << stu.surname << " "
                   << stu.assignment_mark << " " << stu.test_mark << " " << stu.exam_mark;

        if(file_stream.fail()) {
            std::cerr << "Error: Failed to write to file\n";
            return false;
        }

        std::cout << "Student data saved successfully to " << location << "\n";
        return true;
    }


    void init(Student& stu) {
        std::cout << "Input Name: ";
        std::getline(std::cin, stu.name);

        std::cout << "Input Surname: ";
        std::getline(std::cin, stu.surname);

        while (true) {
            std::cout << "Enter assignment mark: ";
            if (std::cin >> stu.assignment_mark) {
                if(stu.assignment_mark < 0 || stu.assignment_mark > 100){
                    std::cerr << "Please enter a valid mark for assignment. Press enter to continue";
                    std::cin.get();
                    clean_up();
                    continue;
                }

                break;
            } else {
                std::cout << "Please enter a valid mark. ";
                clean_up();
                continue;
            }
        }
        clean_up();

        while (true) {
            std::cout << "Enter test mark: ";
            if (std::cin >> stu.test_mark) {
                if(stu.test_mark < 0 || stu.test_mark > 100){
                    std::cerr << "Please enter a valid mark for test. Press enter to continue";
                    std::cin.get();
                    clean_up();
                    continue;
                }
                break;
            } else {
                std::cerr << "Please enter a valid mark. ";
                clean_up();
                continue;
            }
        }
        clean_up();

        while (true) {
            std::cout << "Enter exam mark: ";
            if (std::cin >> stu.exam_mark) {
                if(stu.exam_mark < 0 || stu.exam_mark > 100){
                    std::cerr << "Please enter a valid mark for exam. Press enter to continue";
                    std::cin.get();
                    clean_up();
                    continue;
                }
                break;
            } else {
                std::cerr << "Please enter a valid mark. ";
                clean_up();
                continue;
            }
        }
        clean_up();

        calculate_grade(stu);
        std::cout << stu;
    }
}

int main() {
    unsigned short choice, selection;

    while (true) {
        std::cout << "\n--- Main Menu ---\n";
        std::cout << "1. Pension Calculator\n";
        std::cout << "2. Student Grade Calculator\n";
        std::cout << "0. Exit\n";
        std::cout << "Pick: ";

        if (std::cin >> choice) {
            if (choice == 0) {
                std::cout << "Exiting program. Goodbye!\n";
                return 0;
            } else if (choice == 1 || choice == 2) {
                break;
            } else {
                std::cout << "Invalid choice. Please select 0, 1, or 2.\n";
            }
        } else {
            std::cout << "Invalid input. Try again.\n";
            UNESWA::clean_up();
        }
    }
    UNESWA::clean_up();

    if (choice == 1) {
        UNESWA::Employee emp;

        while (true) {
            std::cout << "\n--- Pension Calculator Menu ---\n";
            std::cout << "1. Load employee data from file\n";
            std::cout << "2. Enter employee data manually\n";
            std::cout << "3. Save employee data to file\n";
            std::cout << "0. Return to main menu\n";
            std::cout << "Choose option: ";

            if (std::cin >> selection) {
                UNESWA::clean_up();

                if (selection == 0) {
                    main(); // Return to main menu
                    return 0;
                } else if (selection == 1) {
                    std::string file_name;
                    std::cout << "Enter filename: ";
                    std::getline(std::cin, file_name);
                    UNESWA::fetch_from_file(file_name, emp);
                } else if (selection == 2) {
                    UNESWA::init(emp);
                } else if (selection == 3) {
                    std::string file_name;
                    std::cout << "Enter filename to save: ";
                    std::getline(std::cin, file_name);
                    UNESWA::save_to_file(file_name, emp);
                } else {
                    std::cout << "Invalid option. Please try again.\n";
                }
            } else {
                std::cout << "Invalid input. Please try again.\n";
                UNESWA::clean_up();
            }
        }
    } else if (choice == 2) {
        STUDENT::Student stu;

        while (true) {
            std::cout << "\n--- Student Grade Calculator Menu ---\n";
            std::cout << "1. Load student data from file\n";
            std::cout << "2. Enter student data manually\n";
            std::cout << "3. Save student data to file\n";
            std::cout << "0. Return to main menu\n";
            std::cout << "Choose option: ";

            if (std::cin >> selection) {
                STUDENT::clean_up();

                if (selection == 0) {
                    main(); // Return to main menu
                    return 0;
                } else if (selection == 1) {
                    std::string file_name;
                    std::cout << "Enter filename: ";
                    std::getline(std::cin, file_name);
                    STUDENT::fetch_from_file(file_name, stu);
                } else if (selection == 2) {
                    STUDENT::init(stu);
                } else if (selection == 3) {
                    std::string file_name;
                    std::cout << "Enter filename to save: ";
                    std::getline(std::cin, file_name);
                    STUDENT::save_to_file(file_name, stu);
                } else {
                    std::cout << "Invalid option. Please try again.\n";
                }
            } else {
                std::cout << "Invalid input. Please try again.\n";
                STUDENT::clean_up();
            }
        }
    }

    return 0;
}
