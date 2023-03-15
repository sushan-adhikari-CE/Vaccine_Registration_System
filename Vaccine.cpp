// Please include the folders i.e., Admin and user to ensure that the program is running
#include <iostream> //For input/output operators(cout, cin)
#include <conio.h>  //For features such as clrscr, getch()
#include <cstdio>   //For features of C program (printf, scanf)
#include <cstdlib>  //For using exit and srand()
#include <cstring>  //For using strings and their functions
#include <time.h>   //For including delay and time(for random number generator)
#include <cmath>    //For absolute value
#include <fstream>  //For using file handling
#include <vector>   //For vector

// For the first page, that the user sees when the program is run
class COVID
{
private:
    // You can change it later
    std::string admin_username = "Admin";
    std::string admin_password = "Admin";

public:
    // Prototype of all the methods: features of the program
    void main_menu();              // First page
    void admin_login();            // First page 1.
    void user_login();             // First page 2.
    void create_account();         // First page 3.
    void admin_features();         // after admin login 1.a
    void Vaccine_edit();           // Features for admin 1.a.1
    void location_edit();          // Features for admin 1.a.2
    void doctor_edit();            // Features for admin 1.a.3
    void patient_list();           // Features for admin 1.a.4
    void patient_emergency_list(); // Features for admin 1.a.5
    void search_name_and_phone();  // Features for admin 1.a.6
    void search_username();        // Features for admin 1.a.7
    void search_phone_num();       // Features for admin 1.a.8
    void user_features();          // After user login 2.a
    void available_vaccine();      // Features for ussr 2.a.1
    void apply_vaccine();          // Features for user 2.a.2
    void vaccination_location();   // Features for user 2.a.3
    void emergency_register();     // Features for user 2.a.4
    void doctor_contact();         // Features for user 2.a.5
};
// Defining the methods one by one
// For the main menu, i.e., first page
void COVID ::main_menu() // Defining the method
{
    clrscr();

    int first_choice;
    std::cout << "\033[0;39,44m\033[21m";
    // For color: "\033[{FORMAT_ATTRIBUTE};{FORGROUND_COLOR};{BACKGROUND_COLOR}m{TEXT}\033[{RESET_FORMATE_ATTRIBUTE}m"
    std::cout << "\n\n\t\t\t\033[4;34;103m************************************************\033[0m\n";
    std::cout << "\t\t\t\033[1;31;47m*********COVID VACCINE REGISTRATION SYSTEM******\033[0m\n";
    std::cout << "\t\t\t\033[4;34;103m************************************************\033[0m\n";
    std::cout << "\n\t\t\t\033[5;32;107m*****************MAIN MENU********************\033[0m\n\n";
    std::cout << "\t\t\033[3;31;104m1. Admin login \n\n\033[0m";
    std::cout << "\t\t\033[3;31;43m2. User Login \n\n\033[0m";
    std::cout << "\t\t\033[3;31;102m3. Create an account \033[0m\n\n";
    std::cout << "\t\t\033[3;31;47m4. Quit the program \n\033[0m";
    std::cout << "\n";
    std::cout << "\t\t\033[1;34;106mEnter your choice:\033[27m ";

    std::cin >> first_choice;

    switch (first_choice)
    {
    case 1:
        admin_login();
        break;
    case 2:
        user_login();
        break;
    case 3:
        create_account();
        break;
    case 4:
        exit(0); // For quitting the program, 0 indicating success

    default:
        std::cout << "\t\t\tPlease, enter a valid choice." << std::endl;
        main_menu();
        break;
    }
}
// For admin login
void COVID ::admin_login()
{
    clrscr();

    std::string usernm_adm, passw_adm;
    // std::cin.ignore();
    int ch1;
    std::cout << "\n\n\t\t\t\033[4;34;103m************************************************\033[0m\n";
    std::cout << "\t\t\t\033[1;31;47m*********COVID VACCINE REGISTRATION SYSTEM******\033[0m\n";
    std::cout << "\t\t\t\033[4;34;103m************************************************\033[0m\n";

    std::cout << "\n\t\t\t\033[1;91;44m*****************ADMIN LOGIN******************\033[22m\n";
    std::cout << "\n\n\t\t\tEnter your username: ";

    std::cin >> usernm_adm;
    std::cout << std::endl;
    // note: cin throws a new line when it ends and it gets picked up by getch
    // and hence, the getch() does not work
    std::cin.ignore(); // To clear the buffer, i.e., to use cin and getline or getch in the same piece of method
    std::cout << "\n\n\t\t\tEnter your password: ";

    ch1 = getch();

    while (ch1 != 10) // getch() returns the ASCII value of the input
                      // For carriage return(enter), the ASCII value is 13.
                      // For new line, the ASCII value is 10
    {
        // We need to push the entered character starting from the end towards front of the array
        passw_adm.push_back(ch1); // push_back() takes character as an argument and hence it converts the argument to eqv. ASCII Character
        // For appending the entered characters in the string
        std::cout << "*";
        ch1 = getch();
    }
    std::cout << std::endl;
    // For Capthca check
    int capt, capt1; // string passw;
    // int ch;
    srand(time(0));            // SEt random time           // For randomizing the random number
    capt = abs((short)rand()); // we don't need negative random numbers and generally
                               // the numbers are large if only integer is used
    std::cout << "\t\t\tCapthca: ####" << capt << "####" << std::endl;
    std::cout << "\t\t\tEnter the captcha: ";
    std::cin >> capt1; // New line
    std::cin.ignore(); // clear the buffer

    if (capt1 == capt)
    {

        // Strings can be compared directly
        if (usernm_adm == admin_username && passw_adm == admin_password)
        {
            admin_features(); // Give access to admin features
        }
        else
        {
            clrscr();

            std::cout << "\n\n\nError(Username or password incorrect)! press any key to try again...";
            getch();
            admin_login();
        }
    }
    else
    {
        std::cout << "\t\t\tPlease, enter correct captcha.";
        std::cout << "\n\t\t\tPress any key to try again......";
        std::cout << std::endl
                  << std::endl;
        getch();
        admin_login(); // redirect to admin login
    }
}
// For login by the user whose username, password and details are stored in the database
void COVID ::user_login()
{
    clrscr();

    std::cout << "\n\n\t\t\t\033[4;34;103m************************************************\033[0m\n";
    std::cout << "\t\t\t\033[1;31;47m*********COVID VACCINE REGISTRATION SYSTEM******\033[0m\n";
    std::cout << "\t\t\t\033[4;34;103m************************************************\033[0m\n";

    std::string usernm_usr, passw_usr;
    int ch2;
    std::cout << "\n\t\t\t\033[3;34;102m **************USER LOGIN PAGE***************\033[21m ";
    // std::cin.ignore();
    // std::cout << "\n\t\t\tEnter your full name: ";
    // std::getline(std::cin, user_name);

    std::cout << "\n\n\n\t\t\tEnter your username: ";

    std::cin >> usernm_usr;
    std::cout << std::endl;
    // cin throws a carriage return after which goes to getch()
    std::cin.ignore(); // For clearing the buffer
    std::cout << "\n\n\t\t\tEnter your password: ";

    ch2 = getch();
    while (ch2 != 10) // getch() returns the ASCII value of the input
                      // For carriage return(enter), the ASCII value is 13(it works on windows).
    {                 // ASCII value of 10 means new line (it works on Linux)
        // We need to push the entered character starting from the end towards front of the array
        passw_usr.push_back(ch2); // For appending the entered characters in the string
        // push_back takes the argument as chars(it converts the ASCII to corresponding letters)
        std::cout << "*";
        ch2 = getch();
    }

    std::cout << std::endl;

    // For Capthca check
    int capt, capt1;
    srand(time(0));            // For randomizing the value per every zero nanosecond
    capt = abs((short)rand()); // Truncating  the length of the random number and making it +ve
    std::cout << "\t\t\tCapthca: #### " << capt << " ####" << std::endl;
    std::cout << "\t\t\tEnter the captcha: ";
    std::cin >> capt1;
    std::cin.ignore(); // Clear the buffer

    if (capt1 == capt)
    {

        std::string usernm_file, passw_file;

        // Check the username and password from the file where the list of users are stored
        // Use File Handling
        // Access the file where the username and password is stored and comapare every letter

        std::fstream(file);
        file.open("/user/" + usernm_usr + ".txt", std::ios::in);
        if (file.is_open())
        {
            int count = 0; // initialize the count to zero
            std::string line;
            while (!file.eof()) // Run the loop till the end of file(eof)
            {
                count++;             // increase the count every time the loop runs i.e., to indicate line number
                getline(file, line); // It reads the single line of the text file
                if (count == 2)      // At Second line, the username of the user is stored
                {
                    usernm_file = line;
                }
                if (count == 3) // At the Third line, the password of the user is stored
                {
                    passw_file = line;
                    break;
                }
            }
            file.close();
        }
        if (usernm_usr == usernm_file && passw_usr == passw_file)
        {
            user_features();
        }

        else
        {

            clrscr();
            int err; // err for choice with error
            int choice;
            std::cout << "\n\n\n\n\t\t\tError(Username or password mismatched)!" << std::endl;
            std::cout << "Don't have an account? Enter 1 to create a new account" << std::endl;
            std::cout << "Enter any other key(except 1) to try again" << std::endl;
            std::cout << "Enter your choice: ";

            choice = getch();
            switch (choice)
            {
            case 49: // 49 for number 1
                create_account();
                break;
            default:
                user_login();
                break;
            }
        }
    }
    else
    {
        std::cout << "\n\t\t\tPlease, enter correct captcha.";
        std::cout << "\n\t\t\tPress any key to try again......";
        std::cout << std::endl;
        getch();
        user_login();
    }
}
void COVID ::user_features() // After user login 2.a
{
    clrscr();
    int user_choice;
    std::cout << "\n\n\t\t\t\033[4;34;103m************************************************\033[0m\n";
    std::cout << "\t\t\t\033[1;31;47m*********COVID VACCINE REGISTRATION SYSTEM******\033[0m\n";
    std::cout << "\t\t\t\033[4;34;103m************************************************\033[0m\n";

    std::cout << "\n\t\t\t\033[2;31;47m*****************FEATURES FOR USER************\033[22m\n";
    std::cout << "\n\t\t\t1. See Available Vaccines";
    std::cout << "\n\t\t\t2. Apply For Vaccine ";
    std::cout << "\n\t\t\t3. Emergency Case ";
    std::cout << "\n\t\t\t4. See Vaccination Locations ";
    std::cout << "\n\t\t\t5. Contact a Doctor";

    std::cout << std::endl;
    std::cout << "\n\t\t\t Enter your choice: ";
    std::cin >> user_choice;
    switch (user_choice)
    {
    case 1:
        available_vaccine();
        break;
    case 2:
        apply_vaccine();
        break;
    case 3:
        emergency_register();
        break;
    case 4:
        vaccination_location();
        break;
    case 5:
        doctor_contact();
        break;

    default:
        std::cin.ignore(); // Clear the buffer
        std::cout << "please, make an appropriate choice\n";
        std::cout << "Enter a key to try again..............\n";
        getch();
        user_features();
        break;
    }
}
// Features available to admin after admin login
void COVID ::admin_features()
{

    clrscr();
    int adm_choice;
    std::cout << "\n\n\t\t\t\033[4;34;103m************************************************\033[0m\n";
    std::cout << "\t\t\t\033[1;31;47m*********COVID VACCINE REGISTRATION SYSTEM******\033[0m\n";
    std::cout << "\t\t\t\033[4;34;103m************************************************\033[0m\n";

    std::cout << "\n\t\t\t\033[1;31;49m*****************FEATURES FOR ADMIN************\033[22m\n";
    std::cout << "\n\t\t\t1. Edit vaccines";
    std::cout << "\n\t\t\t2. Edit vaccination site";
    std::cout << "\n\t\t\t3. Edit Doctors' info";
    std::cout << "\n\t\t\t4. Patient list";
    std::cout << "\n\t\t\t5. Emergency patient list";
    std::cout << "\n\t\t\t6. Search by name and phone number";
    std::cout << "\n\t\t\t7. Search by username";
    std::cout << "\n\t\t\t8. Search by phone number";
    std::cout << std::endl;
    std::cout << "\n\t\t\t Enter your choice: ";
    std::cin >> adm_choice;
    switch (adm_choice)
    {
    case 1:
        Vaccine_edit();
        break;
    case 2:
        location_edit();
        break;
    case 3:
        doctor_edit();
        break;
    case 4:
        patient_list();
        break;
    case 5:
        patient_emergency_list();
        break;
    case 6:
        search_name_and_phone();
        break;
    case 7:
        search_username();
        break;
    case 8:
        search_phone_num();
        break;
    default:
        std::cin.ignore(); // Clear the buffer
        std::cout << "please, make an appropriate choice\n";
        std::cout << "Enter a key to try again..............\n";
        getch();
        admin_features();
        break;
    }
}
// For creating a new account by the user
void COVID ::create_account()
{
    clrscr();
    std::string name, gender, location, username, password, contact_num, usernm_file;
    int age;
    int gender_choice;
    std::cout << "\n\n\t\t\t\033[4;34;103m************************************************\033[0m\n";
    std::cout << "\t\t\t\033[1;31;47m*********COVID VACCINE REGISTRATION SYSTEM******\033[0m\n";
    std::cout << "\t\t\t\033[4;34;103m************************************************\033[0m\n";
    std::cin.ignore();
    std::cout << "\n\t\t\t\033[1;36;47m***********CREATE AN ACCOUNT FOR LOGIN***********\033[21m";
    std::cout << "\n\t\t\tPlease, enter the correct credentials.\n\n";

    std::cout << "\t\t\tEnter your full name: ";
    getline(std::cin, name);
    std::cout << "\n\t\t\tEnter your age:";
    std::cin >> age;
    std::cout << std::endl;
    std::cout << "\n\t\t\tGender:" << std::endl;
    std::cout << "\t\t\t1. Male\t 2.Female\t 3.Rather not say" << std::endl;
    std::cout << "\n\t\t\tEnter your gender: ";
    std::cin >> gender_choice;
    switch (gender_choice)
    {
    case 1:
        gender = "Male";
        break;
    case 2:
        gender = "Female";
        break;
    case 3:
        gender = "Rather not say";
        break;
    default:
        std::cout << "\t\t\tPlease, try again with a correct choice";
        create_account();

        break;
    }
    std::cin.ignore();
    std::cout << "\n\t\t\tEnter your location: ";
    getline(std::cin, location);

    std::cout << "\n\t\t\tEnter your contact number: ";
    std::cin >> contact_num;
    std::cout << std::endl;
A:
    clrscr();
    std::cout << "\n\n\t\t\t\033[4;34;103m************************************************\033[0m\n";
    std::cout << "\t\t\t\033[1;31;47m*********COVID VACCINE REGISTRATION SYSTEM******\033[0m\n";
    std::cout << "\t\t\t\033[4;34;103m************************************************\033[0m\n";

    std::cout << "\n\t\t\t\033[0;34;49m***********CREATE AN ACCOUNT FOR LOGIN***********\033[27m";
    std::cout << "\n\n\t\t\t\033[Please, set  a username and password for login ";
    std::cout << "\n\n\t\t\t Set a new username: ";
    std::cin >> username;
    // If the username already exists then,
    std::string line;
    std::fstream(file);
    int line_count = 0;
    file.open("/Admin/username.txt", std::ios::in); // From a file where usernames are stored, read the username line by line
    if (file.is_open())
    {
        while (!file.eof()) // Loop until the end of the file
        {
            // Searching via Linear search(Going line by line from the beginning)
            line_count++;
            getline(file, line);
            usernm_file = line;
            if (username == usernm_file) // Check if the entered username exists with file handling
            {

                std::cin.ignore();
                std::cout << "\n\t\t\tSorry, the username already exists. Please, try again with a new one";
                std::cout << "\n\t\t\tPress any key to try again with a different username.......\n";

                getch();
                goto A;
                file.close();
                break;
            }
        }
        file.close();
    }
    std::cout << "\n\t\t\t Set a password: ";
    std::cin >> password;

    // Storing the username and password of the user by creating a file
    std::fstream(file_usr);
    file_usr.open("/user/" + username + ".txt", std::ios::out);
    if (file_usr.is_open())
    {
        file_usr << name << std::endl;        // First line
        file_usr << username << std::endl;    // Second Line
        file_usr << password << std::endl;    // Third Line
        file_usr << gender << std::endl;      // Fourth Line
        file_usr << location << std::endl;    // Fifth Line
        file_usr << contact_num << std::endl; // Sixth Line
    }
    file_usr.close();
    // Storing the username in the file where only usernames are stored
    file.open("/Admin/username.txt", std::ios::app); // For appending the usernames in the username file
    if (file.is_open())
    {
        file << username << std::endl;
    }
    file.close();
    // For storing only the name of the patients who have created a user-id
    file.open("/Admin/vacc_patient.txt", std::ios::app); // For appending the usernames in the username file
    if (file.is_open())
    {
        file << name << std::endl;
    }
    file.close();
    // Storing the phone number and username in a file(For searching)
    file.open("/Admin/phone and user.txt", std::ios::app); // For appending the usernames in the username file
    if (file.is_open())
    {
        file << contact_num << std::endl;
        file << username << std::endl;
    }
    file.close();
    // Storing the name, phone number, and username(For searching)
    file.open("/Admin/name and phone.txt", std::ios::app);
    if (file.is_open())
    {
        file << name << std::endl;
        file << contact_num << std::endl;
        file << username << std::endl;
    }
    file.close();
    // Storing the name and age of the user in a file for searching through name and age
    file.open("/Admin/name and age.txt", std::ios::app);
    if (file.is_open())
    {
        file << name << std::endl;
        file << age << std::endl;
        file << username << std::endl;
    }
    file.close();

    std::cin.ignore(); // Clear the buffer
    std::cout << "\t\t\tUser account created, press any key to proceed to login page........";
    getch();
    user_login();
}
void COVID::Vaccine_edit() // Features for admin 1.a.1
{

    clrscr();
    int choice, edit_choice, count_edit, temp_count;
    std::fstream(file);
    std::string line, temp_line;
    int count_line = 0, i = 0, j = 0, k = 1;
    std::cout << "\n\n\t\t\t********EDIT VACCINES ****************" << std::endl;
    std::cout << "\n\n\t\t\tThe list of vaccines and their count are:" << std::endl;
    // Access the name of vaccine and their count

    file.open("/Admin/vaccine.txt", std::ios::in);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            if (line != "\0") // Eliminating the null character as it is present at the end of the file
            {

                count_line++;
                if (count_line == (i + 1)) // For reading odd number lines
                {
                    std::cout << k << ")";
                    k++;

                    std::cout << "Vaccine : " << line;
                    j = j + 2;
                }
                else if (count_line == j) // For reading even numbered lines
                {

                    std::cout << "\t\tCount : " << line;
                    i = i + 2;
                    std::cout << std::endl;
                }
            }
        }
        file.close();
    }

    // Add or edit the name and count of vaccine on a file
    std::cout << "Press 1 if you want to edit the vaccine and their numbers" << std::endl;
    std::cout << "Press 2 if you want to go back to main menu" << std::endl;
    std::cout << "Press 3 if you want to quit the program" << std::endl;
    std::cout << "Please, enter your choice:";
    std::cin >> choice;
    switch (choice)
    {
    case 1:

        goto A;

        break;
    case 2:
        admin_features();
        break;
    case 3:
        exit(0);
    default:
        std::cout << "please try again with a correct choice" << std::endl;

        Vaccine_edit();
        break;
    }
A:
    clrscr();

    count_line = 0, i = 0, j = 0, k = 1;
    std::cout << "\n\n\t\t\t********EDIT VACCINES ****************" << std::endl;
    std::cout << "\n\n\t\t\tThe list of vaccines and their count are:" << std::endl;
    // Access the name of vaccine and their count

    file.open("/Admin/vaccine.txt", std::ios::in);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            if (line != "\0") // Eliminating the null character as it is present at the end of the file
            {

                count_line++;
                if (count_line == (i + 1)) // For reading odd number lines
                {
                    std::cout << k << ")";
                    k++;

                    std::cout << "Vaccine : " << line;
                    j = j + 2;
                }
                else if (count_line == j) // For reading even numbered lines
                {

                    std::cout << "\t\tCount : " << line;
                    i = i + 2;
                    std::cout << std::endl;
                }
            }
        }
        file.close();
    }
    // Code for editing

    count_line = 0;
    std::cout << "Enter which number you want to edit: ";
    std::cin >> edit_choice;
    std::vector<std::string> lines; // Creating a vector for storing all the lines
    file.open("/Admin/vaccine.txt", std::ios::in);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            if (line != "\0") // Eliminating the null character as it is present at the end of the file
            {

                lines.push_back(line); // Store all the lines in a vector

                count_line++;
                if (count_line == ((2 * edit_choice) - 1)) // For reading odd number lines
                {
                    std::cout << "The vaccine that you have selected to edit is: " << line;
                }
                else if (count_line == 2 * edit_choice) // For reading even numbered lines
                {
                    temp_count = stoi(line);
                    std::cout << "\nIts present count available is: " << temp_count;
                    std::cout << "\n\nEnter zero(0) if it is out of stock or not available";
                    std::cout << "\nEnter the new count for the vaccine: ";
                    std::cin >> count_edit;

                    // line = std::to_string(count_edit); // Convert the integer to string
                    // file << count_edit;
                }
            }
        }
        file.close();
    }
    if (2 * edit_choice > lines.size()) // If admin makes a selection that is not present on the list
    {
        std::cout << "Invalid choice, please try again";
        goto A;
    }

    // Recreating the same file but with the selected number of the vaccine edited.
    file.open("/Admin/vaccine.txt", std::ios::out);
    count_line = 0;
    if (file.is_open())
    {
        for (int i = 0; i < lines.size(); i++)
        {
            count_line++;
            if (count_line != 2 * edit_choice) // If the count of the line does not equal to the one selected
            {
                file << lines[i] << std::endl;
            }
            if (count_line == 2 * edit_choice) // If it equals to the one that has been selected
            {
                file << count_edit << std::endl;
            }
        }
        file.close();
    }
}
void COVID ::location_edit() // Features for admin 1.a.2
{
    clrscr();
    int k = 0, choice;
    std::cout << "\n\n\t\t\t***********LOCATION EDIT***********" << std::endl;
    std::cout << "The locations where vaccination is going on are: " << std::endl;
    std::string line;
    // Access the file and edit or change the inoculation center
    std::fstream(file);
    file.open("/Admin/location.txt", std::ios::in);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            if (line != "\0")
            {
                k++;
                std::cout << k << ") " << line << std::endl;
            }
        }
        file.close();
    }
    std::cout << "\n\n";
    std::cout << "Enter 1 if you want to edit the vaccination location.\n";
    std::cout << "Enter 2 if you want to go back to main menu.\n";
    std::cout << "Enter 3 if you want to quit the program\n";
    std::cin >> choice;
    switch (choice)
    {
    case 1:
        goto A;
        break;
    case 2:
        main_menu();
        break;
    case 3:
        exit(0);
    default:
        std::cout << "Error! please enter a valid choice";
        break;
    }
A:
    clrscr();
    std::cout << "You are about to edit the vaccination location" << std::endl;
    int edit_choice, count_line = 0;
    k = 0;
    std::string temp_edit;
    std::vector<std::string> lines;
    file.open("/Admin/location.txt", std::ios::in);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            if (line != "\0")
            {
                k++;
                std::cout << k << ") " << line << std::endl;
            }
        }
        file.close();
    }
    std::cout << "Which number you want to edit: ";
    std::cin >> edit_choice;
    file.open("/Admin/location.txt", std::ios::in);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            if (line != "\0")
            {
                count_line++;
                lines.push_back(line);
                if (count_line == edit_choice)
                {
                    std::cout << "The location that you have selected to edit is: " << line << std::endl;
                }
            }
        }
        file.close();
    }
    std::cin.ignore();
    std::cout << "Enter what you want to edit: ";
    getline(std::cin, temp_edit);

    count_line = 0;
    file.open("/Admin/location.txt", std::ios::out);
    if (file.is_open())
    {

        for (int i = 0; i < lines.size(); i++)
        {
            count_line++;

            if (count_line != edit_choice)
            {
                file << lines[i] << std::endl;
            }
            else
            {
                file << temp_edit << std::endl;
            }
        }

        file.close();
    }
}
void COVID ::doctor_edit() // Features for admin 1.a.3
{
    clrscr();
    std::cout << "\n\n\t\t\t*************DOCTOR LIST EDIT**************" << std::endl;
    // Access the file and add or remove the details of a doctor
    std::cout << "The list of doctors and their availability are:" << std::endl;
    int k = 0, choice;
    std::string line;
    // Access the file and edit or change the inoculation center
    std::fstream(file);
    file.open("/Admin/doctor.txt", std::ios::in);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            if (line != "\0")
            {
                k++;
                std::cout << k << ") " << line << std::endl;
            }
        }
        file.close();
    }
    std::cout << "\n\n";
    std::cout << "Enter 1 if you want to edit the vaccination location.\n";
    std::cout << "Enter 2 if you want to go back to main menu.\n";
    std::cout << "Enter 3 if you want to quit the program\n";
    std::cout << "Please, enter your choice: ";
    std::cin >> choice;
    switch (choice)
    {
    case 1:
        goto A;
        break;
    case 2:
        main_menu();
        break;
    case 3:
        exit(0);
    default:
        std::cout << "Error! please enter a valid choice";
        break;
    }
A:
    clrscr();
    std::cout << "You are about to edit the Doctor's information" << std::endl;
    int edit_choice, count_line = 0;
    k = 0;
    std::string temp_edit;
    std::vector<std::string> lines;
    file.open("/Admin/doctor.txt", std::ios::in);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            if (line != "\0")
            {
                k++;
                std::cout << k << ") " << line << std::endl;
            }
        }
        file.close();
    }
    std::cout << "Which number you want to edit: ";
    std::cin >> edit_choice;
    file.open("/Admin/doctor.txt", std::ios::in);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            if (line != "\0")
            {
                count_line++;
                lines.push_back(line);
                if (count_line == edit_choice)
                {
                    std::cout << "The doctor that you have selected to edit is: " << line << std::endl;
                }
            }
        }
        file.close();
    }
    std::cin.ignore();
    std::cout << "Enter what you information you want to edit: ";
    getline(std::cin, temp_edit);

    count_line = 0;
    file.open("/Admin/doctor.txt", std::ios::out);
    if (file.is_open())
    {

        for (int i = 0; i < lines.size(); i++)
        {
            count_line++;

            if (count_line != edit_choice)
            {
                file << lines[i] << std::endl;
            }
            else
            {
                file << temp_edit << std::endl;
            }
        }

        file.close();
    }
}
void COVID ::patient_list() // Features for admin 1.a.4
{
    clrscr();
    std::cout << "\n\n\t\t\t*******PATIENT LIST***********" << std::endl;
    std::cout << "\n\n\t\t\tThe details of registered patients are: " << std::endl;
    std::cout << "\n\t\t\tPatients who have registered for vaccination are: " << std::endl;
    std::string line;
    std::fstream(file);
    int k = 0;
    file.open("/Admin/vacc_patient.txt", std::ios::in);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            if (line != "\0")
            {
                k++;
                std::cout << k << ") " << line << std::endl;
            }
        }
        file.close();
    }
};
void COVID ::patient_emergency_list() // Features for admin 1.a.5
{
    clrscr();

    std::cout << "\n\n\t\t\t*******EMERGENCY PATIENTS LIST**********" << std::endl;
    int k = 0;
    std::string line;
    std::cout << "\t\t\tThe details of patients registered as emergency are:" << std::endl;
    std::fstream(file);
    file.open("/Admin/emergency/emer_list.txt", std::ios::in);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            k++;
            std::cout << k << ") " << line << std::endl;
        }
        file.close();
    }
}
void COVID ::search_name_and_phone() // Features for admin 1.a.6
{
    clrscr();
    std::string search_name, search_phone, line, temp_line, temp_phone, usernm_temp;
    int k = 0;
    std::cout << "\n\n\t\t\t***SEARCH BY NAME AND PHONE NUMBER***" << std::endl;
    std::cin.ignore();
    std::cout << "\n\t\tEnter the name: ";
    getline(std::cin, search_name);
    std::cout << "\n\t\tEnter the phone number: ";
    std::cin >> search_phone;
    // Check the name and phone number from the file and display the details
    std::fstream(file);
    file.open("/Admin/name and phone.txt", std::ios::in);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            if (k != 1)
            {
                if (line == search_name)
                {
                    temp_line = line;
                }
                if (line == search_phone)
                {
                    temp_phone = line;
                }
            }
            if (search_name == temp_line && search_phone == temp_phone)
            {
                k++;
            }
            if (k == 2)
            {
                usernm_temp = line;
                std::cout << "\n\nThe details of the user named ( " << search_name << " )are: " << std::endl;
                break;
            }
        }

        file.close();
    }
    if (k != 2)
    {
        int choice;
        std::cout << "Sorry, the data matching the entered details is not available";
        std::cout << "Press 1 if you want to try again with correct details." << std::endl;
        std::cout << "Press 2 if you want to go to admin features" << std::endl;
        std::cout << "Press, any key if you want to exit" << std::endl;
        std::cout << "Please, enter your choice: " << std::endl;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            search_name_and_phone();
            break;
        case 2:
            admin_features();
            break;
        default:
            exit(0);
            break;
        }
    }

    file.open("/user/" + usernm_temp + ".txt", std::ios::in);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            std::cout << "\t\t";
            std::cout << line << std::endl;
        }
        file.close();
    }
}
void COVID ::search_username() // Features for admin 1.a.7
{
    clrscr();
    std::string search_name, line;
    std::cout << "\n\n\t\t\t****SEARCH BY USERNAME***" << std::endl;
    std::cin.ignore();
    std::cout << "\n\n\t\t\tEnter the name: ";
    getline(std::cin, search_name);
    // Check the username from the file and display the details
    std::fstream(file);
    file.open("/user/" + search_name + ".txt", std::ios::in);
    if (file.is_open())
    {
        std::cout << "\n\n\t\t\tThe details of the patient having username " << search_name << " is: " << std::endl;
        while (getline(file, line))
        {
            std::cout << line << std::endl;
        }
        file.close();
    }
    if (file.fail())
    {
        std::cout << "Sorry, the file having username " << search_name << " does not exist." << std::endl;
        std::cout << "Press any key to try again.........";
        getch();
        search_username();
    }
}
void COVID ::search_phone_num() // Features for admin 1.a.8
{
    clrscr();
    std::string search_phone, line, temp_phone, usernm_temp;
    int choice;
    int k = 0;
    std::cout << "\n\n\t\t\t*******SEARCH BY PHONE NUMBER********";
    std::cout << "\n\n\t\t\tEnter the registered phone number:";
    std::cin >> search_phone;
    // Check the phone number from the file and display the details
    std::fstream(file);
    file.open("/Admin/name and phone.txt", std::ios::in);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            if (k != 1)
            {

                if (line == search_phone)
                {
                    temp_phone = line;
                }
            }
            if (search_phone == temp_phone)
            {
                k++;
            }
            if (k == 2)
            {
                usernm_temp = line;
                std::cout << "\n\nThe details of the user having phone no. " << search_phone << " are: " << std::endl;
                break;
            }
        }

        file.close();
    }
    if (k != 2)
    {
        std::cout << "Sorry, the data matching the entered details is not available" << std::endl;
        std::cout << "Press 1 if you want to try again with correct details." << std::endl;
        std::cout << "Press 2 if you want to go to admin features" << std::endl;
        std::cout << "Press, any key if you want to exit" << std::endl;
        std::cout << "Please, enter your choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            search_phone_num();
            break;
        case 2:
            admin_features();
            break;
        default:
            exit(0);
            break;
        }
    }

    file.open("/user/" + usernm_temp + ".txt", std::ios::in);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            std::cout << "\t\t";
            std::cout << line << std::endl;
        }
        file.close();
    }
}
void COVID::available_vaccine() // Features for user 2.a.1
{

    clrscr();
    int i = 0, j = 0, k = 0, choice, line_count = 0, temp_count;
    std::fstream file;
    std::string line, temp_line;
    std::cout << "\n\n\t\t\t*******AVAILABLE VACCINES************";
    std::cout << "\n\n\t\t\tThe list of available vaccines are: " << std::endl;
    // Check the vaccine, its available location and its count from the file and display the vaccine if the count is not zero
    file.open("/Admin/vaccine.txt", std::ios::in);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            if (line != "\0") // Eliminating the null character as it is present at the end of the file
            {

                line_count++;
                if (line_count == (i + 1)) // For reading odd number lines
                {
                    temp_line = line;
                    j = j + 2;
                }
                else if (line_count == j) // For reading even numbered lines
                {
                    temp_count = stoi(line); // converting the string read from the file to integer

                    i = i + 2;
                    if (temp_count != 0)
                    {
                        k++;
                        std::cout << k << ")";
                        std::cout << temp_line << std::endl;
                    }
                }
            }
        }
        file.close();
    }

    std::cout << "\n\n";
    std::cin.ignore();

    std::cout << "press 1 if you want to apply for the vaccine." << std::endl;
    std::cout << "Press 2 if you want to go back " << std::endl;
    std::cout << "Press any other key if you want ot quit the program" << std::endl;

    std::cout << "Enter your choice: ";
    choice = getch();
    if (choice == 49) // ASCII Value of 1 is 49
    {
        apply_vaccine();
    }
    if (choice == 50)
    {
        user_features();
    }

    else
    {
        exit(0);
    }
}
void COVID ::apply_vaccine() // Features for user 2.a.2
{
    clrscr();
    std::string apply_dose, apply_loca, usernm_usr;
    int apply_choice, apply_vacc, final_count;
    std::cout << "\n\n\t\t\t*******APPLY FOR VACCINE********" << std::endl;
    std::cout << "\n\t\t\tPlease, see the list of available vaccines before applying";

    std::cout << "\n\t\t\t1. First dose\t2. Second dose\t3. Booster" << std::endl;
    std::cout << "\n\n\t\t\tWhich dose are you applying for?---> ";
    std::cin >> apply_choice;

    switch (apply_choice)
    {
    case 1:
        apply_dose = "First dose";

        break;
    case 2:
        apply_dose = "Second dose";
        break;
    case 3:
        apply_dose = "Booster";

        break;
    default:
        std::cin.ignore();
        std::cout << "\t\t\tPlease, enter a valid choice.";
        std::cout << "\n\t\t\tpress any key to try again..........";
        getch();
        apply_vaccine();

        break;
    }
    std::cout << "The list of available vaccines are: " << std::endl;
    // Read the file, display the vaccines whose count is not equal to zero
    int i = 0, j = 0, k = 0, choice, line_count = 0, temp_count, read_line, edit_choice, count_edit;
    std::fstream file;
    std::string line, temp_line;
    std::vector<std::string> lines;
    file.open("/Admin/vaccine.txt", std::ios::in);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            if (line != "\0") // Eliminating the null character as it is present at the end of the file
            {

                line_count++;
                if (line_count == (i + 1)) // For reading odd number lines
                {
                    temp_line = line;
                    j = j + 2;
                }
                else if (line_count == j) // For reading even numbered lines
                {
                    temp_count = stoi(line);

                    i = i + 2;
                    if (temp_count != 0) // If the count is not zero
                    {
                        k++;
                        std::cout << k << ")";
                        std::cout << temp_line << "\t\t";
                        lines.push_back(temp_line); // Adding to the vector the list of vaccines whose count is not zero
                    }
                }
            }
        }
        file.close();
    }

    std::cout << "\n\t\t\tWhich vaccine are you applying for?---> ";

    std::cin >> apply_vacc;
    for (int i = 0; i < lines.size(); i++)
    {
        if (apply_vacc == i + 1)
        {
            temp_line = lines[i];
        }
    }
    // After the selection of vaccine by the user, decrease the count of the selected vaccine by 1 from the file
    file.open("/Admin/vaccine.txt", std::ios::in);
    int count_line = 0;
    if (file.is_open())
    {
        while (getline(file, line))
        {
            count_line++;

            if (temp_line == line)
            {
                edit_choice = count_line;
            }
        }
        file.close();
    }

    std::vector<std::string> line2;
    count_line = 0;
    file.open("/Admin/vaccine.txt", std::ios::in);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            if (line != "\0") // Eliminating the null character as it is present at the end of the file
            {

                line2.push_back(line); // Store all the lines in a vector

                count_line++;

                if (count_line == edit_choice + 1) // For reading the number of the selected vaccine
                {
                    temp_count = stoi(line);
                    final_count = temp_count - 1;

                    // line = std::to_string(count_edit); // Convert the integer to string
                    // file << count_edit;
                }
            }
        }
        file.close();
    }

    // Recreating the same file but with the selected number of the vaccine edited.
    file.open("/Admin/vaccine.txt", std::ios::out);
    count_line = 0;
    if (file.is_open())
    {
        for (int i = 0; i < line2.size(); i++)
        {
            count_line++;
            if (count_line != edit_choice + 1) // If the count of the line does not equal to the one selected
            {
                file << line2[i] << std::endl;
            }
            if (count_line == edit_choice + 1) // If it equals to the one that has been selected
            {
                file << final_count << std::endl;
            }
        }
        file.close();
    }

    std::cin.ignore();
    std::cout << "\n\t\t\tPlease, enter the location for vaccination: ";
    getline(std::cin, apply_loca);
    std::cout << "\t\t\tEnter your username for verification:";
    std::cin >> usernm_usr;
    std::cin.ignore();
    std::cout << std::endl;

    //    Store all the details in a file
    // Append in the user details

    file.open("/user/" + usernm_usr + ".txt", std::ios::app);
    if (file.is_open())
    {
        file << apply_dose << std::endl;
        file << temp_line << std::endl;

        file << apply_loca << std::endl;
    }
    file.close();
    std::cout << "\n\n\t\tCongratulations! you have successfully registered for " << apply_dose << " of " << temp_line << std::endl;
    std::cout << "\t\t\tplease, visit " << apply_loca << " for inoculation " << std::endl;
    std::cout << "\t\t\tPress any key to quit the program." << std::endl;
    getch();
    exit(0);
}
void COVID::vaccination_location() // Features for user 2.a.3
{
    int choice;
    clrscr();
    int i;
    std::string line;
    std::fstream(file);
    std::cout << "The location where vaccination campaign is going on is:" << std::endl;
    file.open("/Admin/location.txt", std::ios::in);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            if (line != "\0")
            {
                i++;
                std::cout << i << ") " << line << std::endl;
            }
        }
        file.close();
    }
    std::cout << "Press 1 if you want to go back" << std::endl;
    std::cout << "Press any key if you want to quit the app";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        user_features();
    default:
        exit(0);
    }
}
void COVID ::emergency_register() // Features for user 2.a.4
{
    clrscr();
    std::string emer_loc, emer_name, emer_case;
    std::cout << "\n\n\t\t\t*******EMERGENCY REGISTER***********" << std::endl;
    std::cin.ignore();
    std::cout << "\t\t\tEnter the location where you want to register: ";
    getline(std::cin, emer_loc);
    std::cout << "\t\t\tEnter the patient's name: ";
    getline(std::cin, emer_name);
    std::cout << "\t\t\tCase of emergency:";
    getline(std::cin, emer_case);
    std::cout << std::endl;
    // Storing the details in the file
    std::fstream(file);
    file.open("/Admin/emergency/" + emer_name + ".txt", std::ios::out);
    if (file.is_open())
    {
        file << emer_name << std::endl;
        file << emer_case << std::endl;
    }
    file.close();
    file.open("/Admin/emergency/emer_list.txt", std::ios::app);
    if (file.is_open())
    {
        file << emer_name << std::endl;
    }
    file.close();
    std::cout << "\t\t\tYou have successfully registered " << emer_name << std::endl
              << " \t\t\tas an emergency patient for" << emer_case << ".\n"
              << " \t\t\tPlease visit " << emer_loc << " for treatment" << std::endl;
    std::cout << "\t\t\tPress any key to close the program..........\n";
    // std::cin.ignore();
    getch();
    exit(0);
}
void COVID ::doctor_contact() // Features for user 2.a.4
{
    clrscr();
    std::string line;
    int i = 0;
    std::cout << "\n\n\t\t\t*******CONTACT A DOCTOR***********" << std::endl;
    std::cout << "The list of available doctors are: " << std::endl;
    // Get the list of doctors and their phone numbers from the file and display
    std::fstream(file);
    file.open("/Admin/doctor.txt", std::ios::in);
    if (file.is_open())
    {
        while (getline(file, line)) // Loop until the given condition is true
        {
            i++;

            std::cout << i << ") " << line << std::endl;
        }
        file.close();
    }
}
// Main function
int main()
{
    COVID run; // run is an object
    run.main_menu();
    return 0;
}
