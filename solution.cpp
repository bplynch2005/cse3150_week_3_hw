#include <iostream>
#include <cstring>   // for strlen, strcpy

// TODO: function prototypes

// TODO: implement addStudent
void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity){
	if(size+1 >= capacity){
		throw "List full";
	}
	names[size] = name;
	gpas[size] = gpa;
	++size;
}

// TODO: implement updateGPA
void updateGPA(double* gpaPtr, double newGpa){
	*gpaPtr = newGpa;
}

// TODO: implement printStudent
void printStudent(const char* name, const double& gpa){
	std::cout << "Name: " << name << ", GPA: " << gpa << std::endl; 
}

// TODO: implement averageGPA
double averageGPA(const double gpas[], int size){
	double sum = 0.0;
	if(size == 0){
		throw "No students";
	}
	
	for(int i = 0; i < size; ++i){
		sum += gpas[i];
	}

	sum = (sum/size);
	return sum;
}
int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./program <capacity>" << std::endl;
        return 1;
    }

    int capacity = std::stoi(argv[1]);
    char* names[capacity];
    double gpas[capacity];
    int size = 0;

    int choice;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Add student\n";
        std::cout << "2. Update GPA\n";
        std::cout << "3. Print all students\n";
        std::cout << "4. Compute average GPA\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
	std::cin.ignore(256, '\n');

        switch (choice) {
            case 1: {
                // TODO: implement menu logic
		char* name = nullptr;
		try{
			char buffer[256];
			std::cout << "Enter Name: ";
			std::cin.getline(buffer, 256);
			name = new char[std::strlen(buffer) + 1];
			std::strcpy(name, buffer);		
		
			std::cout << "Enter GPA: ";
			double gpa;
			std::cin >> gpa;
		
			addStudent(name, gpa, names, gpas, size, capacity);

		}
           	catch(const char* msg){
			std::cout << msg << std::endl;
			delete[] name;
		}

		break;
            }
            case 2: {
                // TODO: implement menu logic
		
		double* gpaPtr = nullptr;
		try{
			if(size == 0){
				throw "No students";
			}

			char buffer[256];
			std::cout << "Enter Name: ";
			std::cin.getline(buffer, 256);
			
			std::cout << "Enter GPA: ";
			double gpa;
			std::cin >> gpa;

			for(int i = 0; i < size; ++i){
				if(std::strcmp(names[i], buffer) == 0){
					gpaPtr = &gpas[i];
					updateGPA(gpaPtr, gpa);
					break;
				}
			}
			if(gpaPtr == nullptr){
				throw "No student by given name";
		
			}
		}
		catch(const char* msg){
			std::cout << msg << std::endl;
			break;
		}
		
		std::cout << *gpaPtr << std::endl;
		
                break;
            }
            case 3: {
                // TODO: implement menu logic
		
		try{
			if(size == 0){
				throw "No students";
			}

			for(int i = 0; i < size; ++i){
				printStudent(names[i], gpas[i]);
			}
		}
		catch(const char* msg){
			std::cout << msg << std::endl;
		}

                break;
            }
            case 4: {
                // TODO: implement menu logic
		
		try{
			int avgGpa = static_cast<int>(averageGPA(gpas, size));
			std::cout << "Average GPA: " << avgGpa << std::endl;
		}
		
		catch(const char* msg){
			std::cout << msg << std::endl;
		}

                break;
            }
            case 5: {
                std::cout << "Goodbye!" << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice" << std::endl;
            }
        }
    } while (choice != 5);

    // TODO: free memory
	for(int i = 0; i < size; ++i){
		delete[] names[i];
	}
    return 0;
}
