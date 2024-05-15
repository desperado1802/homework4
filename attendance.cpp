#include <iostream>
#include <bitset>
#include <limits>

int main(void)
{
    uint64_t attendance = 0;
    int option;
    while (1)
    {
        std::cout << "1. Set attendance\n" << std::endl;
        std::cout << "2. Clear attendance\n" << std::endl;
        std::cout << "3. Attendance info\n" << std::endl;
        std::cout << "4. Change attendance\n" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cin >> option;

            if (std::cin.fail()) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Invalid input. Please enter a number between 1 and 5." << std::endl;
            continue;
        }

        if (option == 1)
        {
            
            int student_number;
            std::cout << "Enter student number to mark present (1-64): ";
            std::cin >> student_number;

            if (student_number >= 1 && student_number <= 64) {
                attendance |= (1ULL << (student_number - 1));
            } else {
                std::cout << "Invalid student number. Please enter a number between 1 and 64." << std::endl;
                continue; 
            }

            std::cout << "Attendance: " << std::bitset<8*sizeof(attendance)>(attendance) << std::endl;
        
        }
        else if (option == 2)
        {
            int student_number;
            std::cout << "Enter student number to mark absent (1-64): ";
            std::cin >> student_number;

            if (student_number >= 1 && student_number <= 64) {
                attendance &= ~(1ULL << (student_number - 1));
            } else {
                std::cout << "Invalid student number. Please enter a number between 1 and 64." << std::endl;
                continue; 
            }

            std::cout << "Attendance: " << std::bitset<8*sizeof(attendance)>(attendance) << std::endl;
        }
        else if (option == 3) {
            std::cout << "Attendance: "<< std::bitset<8*sizeof(attendance)>(attendance) << std::endl;
            std::cout << "Total Present: "<< std::bitset<8*sizeof(attendance)>(attendance).count() << std::endl;
           
        }
        else if(option == 4) {

              int student_number;
            std::cout << "Enter student number to change attendance (1-64): ";
            std::cin >> student_number;

            if (student_number >= 1 && student_number <= 64) {
                attendance ^= (1ULL << (student_number - 1));
            } else {
                std::cout << "Invalid student number. Please enter a number between 1 and 64." << std::endl;
                continue; 
            }

            std::cout << "Attendance: " << std::bitset<8*sizeof(attendance)>(attendance) << std::endl;

        }
        else if(option == 5) {
            std::cout << "Application closed!" << std::endl;
            break;
        } 
        else {
            std::cout << "Please enter numbers 1-5 to interact with the program." << std::endl;
        }
       
    }
    return 0;
}
