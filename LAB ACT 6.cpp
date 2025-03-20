#include <iostream>
#include <cstring>
#include <cstdlib>  // For system() function
#include <unistd.h>  // For sleep function

using namespace std;

// String functions
int my_strlen(const char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

char* my_strcpy(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char* my_strcat(char *dest, const char *src) {
    int dest_len = my_strlen(dest);
    int i = 0;
    
    while (src[i] != '\0') {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
    return dest;
}

int my_strcmp(const char *str1, const char *str2) {
    int i = 0;
    
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return (str1[i] - str2[i]);
        }
        i++;
    }
    
    return (str1[i] - str2[i]);
}

char* my_strlwr(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
        i++;
    }
    return str;
}

char* my_strupr(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
        i++;
    }
    return str;
}

char* my_strrev(char *str) {
    int len = my_strlen(str);
    int i, j;
    char temp;
    
    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    
    return str;
}

// Function to check if the string contains any digits
bool contains_digit(const char* str) {
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            return true; // Return true if a digit is found
        }
    }
    return false; // No digits found
}

// Function to check if a string contains only digits
bool is_digits_only(const char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }
        i++;
    }
    return true;
}

// Clear screen function
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Student structure
struct Student {
    char firstName[25];
    char lastName[25];
    char fullName[50];
    char email[50];
    char phone[15];
    int age;
    char course[30];
    char gender;  // 'M' for Male, 'F' for Female
    bool admitted;
};

// Function to display header
void displayHeader() {
    cout << "       +----------------------------------------------------------------------------------------+\n";
    cout << "       |                                  SCHOOL ADMISSION SYSTEM                   [ 9 ] Exit  |\n";
    cout << "       +----------------------------------------------------------------------------------------+\n";
    cout << "       |               / ----------------- / ---------------- / --------------- /               |\n";
    cout << "       |            ADD NEW            SHOW ALL            SEARCH            CHANGE             |\n";
    cout << "       +----------------------------------------------------------------------------------------+\n";
}

void displayHeader_Add() {
    cout << "       +----------------------------------------------------------------------------------------+\n";
    cout << "       |                                  SCHOOL ADMISSION SYSTEM                   [ 9 ] Exit  |\n";
    cout << "       +----------------------------------------------------------------------------------------+\n";
    cout << "       |               * ----------------- / ---------------- / --------------- /               |\n";
    cout << "       |            ADD NEW            SHOW ALL            SEARCH            CHANGE             |\n";
    cout << "       +----------------------------------------------------------------------------------------+\n";
}

void displayHeader_Show() {
    cout << "       +----------------------------------------------------------------------------------------+\n";
    cout << "       |                                  SCHOOL ADMISSION SYSTEM                   [ 9 ] Exit  |\n";
    cout << "       +----------------------------------------------------------------------------------------+\n";
    cout << "       |               / ----------------- * ---------------- / --------------- /               |\n";
    cout << "       |            ADD NEW            SHOW ALL            SEARCH            CHANGE             |\n";
    cout << "       +----------------------------------------------------------------------------------------+\n";
}

void displayHeader_Search() {
    cout << "       +----------------------------------------------------------------------------------------+\n";
    cout << "       |                                  SCHOOL ADMISSION SYSTEM                   [ 9 ] Exit  |\n";
    cout << "       +----------------------------------------------------------------------------------------+\n";
    cout << "       |               / ----------------- / ---------------- * --------------- /               |\n";
    cout << "       |            ADD NEW            SHOW ALL            SEARCH            CHANGE             |\n";
    cout << "       +----------------------------------------------------------------------------------------+\n";
}

void displayHeader_Change() {
    cout << "       +----------------------------------------------------------------------------------------+\n";
    cout << "       |                                  SCHOOL ADMISSION SYSTEM                   [ 9 ] Exit  |\n";
    cout << "       +----------------------------------------------------------------------------------------+\n";
    cout << "       |               / ----------------- / ---------------- / --------------- *               |\n";
    cout << "       |            ADD NEW            SHOW ALL            SEARCH            CHANGE             |\n";
    cout << "       +----------------------------------------------------------------------------------------+\n";
}

// Main program
int main() {
    Student students[100];  // Array to store up to 100 students
    int studentCount = 0;   // Counter for number of students  
    int choice;
    char temp[50];
    bool running = true;
    
    while (running) {
        clearScreen();
        displayHeader();
        
        // Display menu
    	cout << "                                __-----_---__-----__-_---_-__----_-__--_-__ \n";
		cout << "                               |  ___   ____________________________   __  |\n";
		cout << "                               |:|   | |                            | |  |:|\n";
		cout << "                               |:| 1 [:]      Add New Student       [:]  |:|\n";
		cout << "                               |:|___| |____________________________| |__|:|\n";
		cout << "                               |__-___   __----__--_--__-_____---__   _--__|\n";
		cout << "                                __-----_---__-----__-_---_-__----_-__--_-__ \n";
		cout << "                               |  ___   ____________________________   __  |\n";
		cout << "                               |:|   | |                            | |  |:|\n";
		cout << "                               |:| 2 [:]      Show All Student      [:]  |:|\n";
		cout << "                               |:|___| |____________________________| |__|:|\n";
		cout << "                               |__-___   __----__--_--__-_____---__   _--__|\n";
		cout << "                                __-----_---__-----__-_---_-__----_-__--_-__ \n";
		cout << "                               |  ___   ____________________________   __  |\n";
		cout << "                               |:|   | |                            | |  |:|\n";
		cout << "                               |:| 3 [:]       Search Student       [:]  |:|\n";
		cout << "                               |:|___| |____________________________| |__|:|\n";
		cout << "                               |__-___   __----__--_--__-_____---__   _--__|\n";
		cout << "                                __-----_---__-----__-_---_-__----_-__--_-__ \n";
		cout << "                               |  ___   ____________________________   __  |\n";
		cout << "                               |:|   | |                            | |  |:|\n";
		cout << "                               |:| 4 [:]   Change Admission Status  [:]  |:|\n";
		cout << "                               |:|___| |____________________________| |__|:|\n";
		cout << "                               |__-___   __----__--_--__-_____---__   _--__|\n";
		
        cout << "\nEnter your choice (1-5): ";
        cin >> choice;
        cin.ignore();  // Clear the newline from input buffer
        
        switch (choice) {
            case 1:  // Add new student
                clearScreen();
                displayHeader_Add();
                cout << "                                       |:| ADD NEW STUDENT |:|" << endl;
                cout << "                                       |:|_________________|:|" << endl;
                cout << "                                       |_____________________|\n\n"<< endl;
                
                while (1) {
                // Get student details - separate first and last name
                cout << "       | Enter first name: ";
                cin.getline(students[studentCount].firstName, 25);
                
                if (contains_digit(students[studentCount].firstName)) {
            		cout << "       +--------------------------------------------------------------+" << endl;
            		cout << "       | !!! First name cannot contain digits. Please enter again.    |" << endl;
            		cout << "       +--------------------------------------------------------------+" << endl;
            		continue;
       			}
                
                	if (my_strlen(students[studentCount].firstName) > 10) {
                	cout << "       +--------------------------------------------------------------+" << endl;
    				cout << "       | !!!Firstname is too long! Please enter a shorter first name. |" << endl;
    				cout << "       +--------------------------------------------------------------+" << endl;
                } else {
                	break;
                }
            }
            
            if (students[studentCount].firstName[0] != '\0') {
        		strupr(students[studentCount].firstName);
        		if (students[studentCount].firstName[1] != '\0') {
            	strlwr(students[studentCount].firstName + 1);
        		}
    		}
                
                
                while (1) {
                cout << "       | Enter last name: ";
                cin.getline(students[studentCount].lastName, 25);
                
                if (contains_digit(students[studentCount].lastName)) {
            		cout << "       +--------------------------------------------------------------+" << endl;
            		cout << "       | !!! Last name cannot contain digits. Please enter again.    |" << endl;
            		cout << "       +--------------------------------------------------------------+" << endl;
           		    continue; 
        		}
                
                if (my_strlen(students[studentCount].lastName) > 10) {
                	cout << "       +--------------------------------------------------------------+" << endl;
    				cout << "       | !!!Lastname is too long! Please enter a shorter last name.   |" << endl;
    				cout << "       +--------------------------------------------------------------+" << endl;
				} else {
					break;
				}
			}
				
                // Combine first and last name into full name
                my_strcpy(students[studentCount].fullName, students[studentCount].firstName);
                my_strcat(students[studentCount].fullName, " ");
                my_strcat(students[studentCount].fullName, students[studentCount].lastName);
                
                // Get gender with validation
                while (true) {
                    cout << "       | Enter gender (M for Male, F for Female): ";
                    cin >> students[studentCount].gender;
                    cin.ignore();  // Clear the newline
                    
                    students[studentCount].gender = toupper(students[studentCount].gender);
                    
                    if (students[studentCount].gender == 'M' || students[studentCount].gender == 'F') {
                        break;
                    } else {
                    	cout << "       +----------------------------------------+" << endl;
                        cout << "       | !!!Invalid input! Please enter M or F. |" << endl;
                        cout << "       +----------------------------------------+" << endl;
                    }
                }
                
                
                // Generate email - convert name to lowercase and add @school.com
                my_strcpy(temp, students[studentCount].firstName);
                my_strlwr(temp);
                my_strcpy(students[studentCount].email, temp);
                
                my_strcat(students[studentCount].email, ".");
                
                my_strcpy(temp, students[studentCount].lastName);
                my_strlwr(temp);
                my_strcat(students[studentCount].email, temp);
                
                my_strcat(students[studentCount].email, "@phltch.edu");
                
                my_strrev(students[studentCount].firstName);
    			my_strrev(students[studentCount].lastName);
    			cout << "       +----------------------------------------+" << endl;
    			cout << "       | Reversed first name: " << students[studentCount].firstName << endl;
    			cout << "       | Reversed last name: " << students[studentCount].lastName << endl;
    			cout << "       +----------------------------------------+" << endl;
                
                // Get phone number with 11-digit validation
                while (true) {
                    cout << "       | Enter phone number: ";
                    cin.getline(students[studentCount].phone, 15);
                    
                    if (my_strlen(students[studentCount].phone) == 11 && is_digits_only(students[studentCount].phone)) {
                        break;
                    } else {
                    	cout << "       +----------------------------------------------------------+" << endl;
                        cout << "       | !!!Invalid phone number! Please enter exactly 11 digits. |" << endl;
                        cout << "       +----------------------------------------------------------+" << endl;
                    }
                }
                
                cout << "       | Enter age: ";
                cin >> students[studentCount].age;
                cin.ignore();
                
                cout << "       | Enter course: ";
                cin.getline(students[studentCount].course, 30);
                
                // Convert course to uppercase
                my_strupr(students[studentCount].course);
                
                // Set admitted status to false by default
                students[studentCount].admitted = false;
                
                studentCount++;
                clearScreen();
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n                              __-----_---__-----__-_---_-__----_-__--_-__\n";
        		cout << "                             |  _______________________________________  |\n";
        		cout << "                             |:|             SUCESSFULLY:>             |:|\n";
        		cout << "                             |:|   > All students have been marked <   |:|\n";
        		cout << "                             |:|_______________________________________|:|\n";
        		cout << "                             |__-_-_---___----__--_--__-_____----___--___|\n";
                cout << "\nPress Enter to continue...";
                cin.get();
                break;
                
            case 2:  // Show all students
                clearScreen();
                displayHeader_Show();
                cout << "                                       |:| SHOW ALL STUDENT |:|" << endl;
                cout << "                                       |:|__________________|:|" << endl;
                cout << "                                       |______________________|\n\n"<< endl;
                
                if (studentCount == 0) {
                    cout << "                              __-----_---__-----__-_---_-__----_-__--_-__\n";
        			cout << "                             |  _______________________________________  |\n";
        			cout << "                             |:|                  OOPS!                |:|\n";
        			cout << "                             |:|   > No students in the system yet <   |:|\n";
        			cout << "                             |:|_______________________________________|:|\n";
        			cout << "                             |__-_-_---___----__--_--__-_____----___--___|\n";
                } else {
                	cout << "+---------------------------------------------------------------------------------------------------+" << endl;
                    cout << "|ID | Name              | Email               | Phone        | Gender | Course      | Age | Status  |" << endl;
                    cout << "+---------------------------------------------------------------------------------------------------+" << endl;
                    
                    for (int i = 0; i < studentCount; i++) {
                        cout << i+1 << ".  ";
                        cout.width(22);
                        cout.setf(ios::left);
                        cout << students[i].fullName;
                        
                        cout.width(22);
                        cout << students[i].email;
                        
                        cout.width(15);
                        cout << students[i].phone;
                        
                        cout.width(8);
                        cout << (students[i].gender == 'M' ? "MALE" : "FEMALE");
                        
                        cout.width(15);
                        cout << students[i].course;
                        
                        cout.width(5);
                        cout << students[i].age;
                        
                        if (students[i].admitted) {
                            cout << "ADMITTED";
                        } else {
                            cout << "PENDING";
                        }
                        cout << endl;
                    }
                    cout << "+---------------------------------------------------------------------------------------------------+" << endl;
                }
                
                cout << "\nPress Enter to continue...";
                cin.get();
                break;
                
            case 3:  // Search student
                clearScreen();
                displayHeader_Search();
                cout << "                                       |:| SEARCH STUDENT_ |:|" << endl;
                cout << "                                       |:|_________________|:|" << endl;
               	cout << "                                       |_____________________|\n\n"<< endl;
                
                if (studentCount == 0) {
                    cout << "                             __-----_---__-----__-_---_-__----_-__--_-__\n";
        			cout << "                            |  _______________________________________  |\n";
        			cout << "                            |:|                  OOPS!                |:|\n";
        			cout << "                            |:|   > No students in the system yet <   |:|\n";
        			cout << "                            |:|_______________________________________|:|\n";
        			cout << "                            |__-_-_---___----__--_--__-_____----___--___|\n";
                } else {
                    char searchName[50];
                    bool found = false;
                    
                    cout << "       | Enter name to search: ";
                    cin.getline(searchName, 50);
                    my_strupr(searchName);  // Convert to uppercase for case-insensitive search
                    
                    cout << "       +------------------+\n";
                    cout << "       | Search Results:  |" << endl;
                    cout << "       +-----------------------------------------------------------------------------------------------+" << endl;
                    
                    for (int i = 0; i < studentCount; i++) {
                        char upperName[50];
                        my_strcpy(upperName, students[i].fullName);
                        my_strupr(upperName);
                        
                        // Check if searchName is in the student's name
                        if (strstr(upperName, searchName) != NULL) {
                        	cout << "|";
                            cout <<  i+1 << ".  ";
                            cout << students[i].fullName << " | ";
                            cout << students[i].email << " | ";
                            cout << students[i].phone << " | ";
                            cout << (students[i].gender == 'M' ? "MALE" : "FEMALE") << " | ";
                            cout << students[i].course << " | ";
                            cout << students[i].age << " | ";
                            
                            if (students[i].admitted) {
                                cout << "ADMITTED";
                            } else {
                                cout << "PENDING";
                            }
                            cout << endl;
                            
                            found = true;
                        }
                    }
                    
                    if (!found) {
                        cout << "No student found with that name." << endl;
                    }
                }
                
                cout << "\nPress Enter to continue...";
                cin.get();
                break;
                
            case 4:  // Change admission status
                clearScreen();
                displayHeader_Change();
                cout << "                                   |:| CHANGE ADMISSION STATUS |:|" << endl;
                cout << "                                   |:|_________________________|:|" << endl;
                cout << "                                   |_____________________________|\n\n"<< endl;
                
                if (studentCount == 0) {
                	cout << "                             __-----_---__-----__-_---_-__----_-__--_-__\n";
        			cout << "                            |  _______________________________________  |\n";
        			cout << "                            |:|                  OOPS!                |:|\n";
        			cout << "                            |:|   > No students in the system yet <   |:|\n";
        			cout << "                            |:|_______________________________________|:|\n";
        			cout << "                            |__-_-_---___----__--_--__-_____----___--___|\n";
                } else {
                    int id;
                    char confirm;
                    
                    // Display all students first
                    cout << "All Students:" << endl;
                    cout << "ID  Name                  Status" << endl;
                    cout << "----------------------------" << endl;
                    
                    for (int i = 0; i < studentCount; i++) {
                        cout << i+1 << ".  ";
                        cout.width(22);
                        cout.setf(ios::left);
                        cout << students[i].fullName;
                        
                        if (students[i].admitted) {
                            cout << "ADMITTED";
                        } else {
                            cout << "PENDING";
                        }
                        cout << endl;
                    }
                    
                    cout << "\nEnter student ID to change status: ";
                    cin >> id;
                    cin.ignore();
                    
                    if (id < 1 || id > studentCount) {
                        cout << "Invalid student ID!" << endl;
                    } else {
                        cout << "Student: " << students[id-1].fullName << endl;
                        cout << "Current status: " << (students[id-1].admitted ? "ADMITTED" : "PENDING") << endl;
                        cout << "Change to " << (students[id-1].admitted ? "PENDING" : "ADMITTED") << "? (y/n): ";
                        cin >> confirm;
                        cin.ignore();
                        
                        if (confirm == 'y' || confirm == 'Y') {
                            students[id-1].admitted = !students[id-1].admitted;
                            cout << "Status changed successfully!" << endl;
                        } else {
                            cout << "Status not changed." << endl;
                        }
                    }
                }
                
                cout << "\nPress Enter to back...";
                cin.get();
                break;
                
            case 9:  // Exit
                running = false;
                clearScreen();
                cout << "Thank you for using Student Admission System!" << endl;
                break;
                
            default:
            	clearScreen();
            	cout << "\n\n\n\n\n\n\n\n\n\n\n\n                                __-----_---__-----__-_---_-__----_-__--_-__\n";
        		cout << "                               |  _______________________________________  |\n";
        		cout << "                               |:|               INVALID!!!!             |:|\n";
        		cout << "                               |:|    > Please enter a valid options <   |:|\n";
        		cout << "                               |:|_______________________________________|:|\n";
        		cout << "                               |__-_-_---___----__--_--__-_____----___--___|\n";
                cout << "\nPress Enter to continue...";
                cin.get();
                break;
        }
    }
    
    return 0;
}

