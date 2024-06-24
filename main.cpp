//Project OOP Business Management - "Hotel management system"

// Section: 004
//U2310210 - Qodirov Odilxon
//U2310226 - Sa'diev Asalbek



#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class User
{
protected:
    string username;
    string password;

public:
    User(const string& username, const string& password) : username(username), password(password) {}

    bool checkpassword(const string& inUsername, const string& inPassword)
    {
        return (username == inUsername && password == inPassword);
    }
};

class hotel : public User
{
private:
    class Guest
    {
    public:
        string name;
        string roomType;
        int duration; // in days
        double totalPrice;
        double totalBill;
    };

    Guest guests[100];
    int guestCount;



public:
    hotel(const string& username, const string& password) : User(username, password), guestCount(0)
    {
        // Default guest list
        guests[0] = { "Aziz", "Double", 7, 0 }; // 0 is just a placeholder for total bill
        guests[1] = { "Tom and Kate", "Double", 5, 0 }; // 0 is just a placeholder for total bill
        guests[2] = { "Li", "Single", 3, 0 }; // 0 is just a placeholder for total bill
        guestCount = 3;

    }

    void showMenu() const
    {
        cout << "1. Book Rooms"<<endl;
        cout << "2. Display Available Services"<<endl;
        cout << "3. Accounting for Guests"<<endl;
        cout << "4. Billing"<<endl;
        cout << "5. Room Occupancy Analysis"<<endl;
        cout << "6. Order Food and Drinks for Room"<<endl; // Updated option
        cout << "7. Room Services" << endl;
        cout << "8. Exit"<<endl;
    }

    void bookRoom()
    {
        if (guestCount >= 100)
        {
            cout << "Guest list is full!" << endl;
            return;
        }

        string name, roomType;
        int duration;
        double totalPrice = 0;
        double priceforperday = 0;

        cout << "Enter guest name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Select room type (Single/Double/Lux): ";
        cin >> roomType;
        cout << "Enter duration of stay (in days): ";
        cin >> duration;

        if (roomType == "Single")
        {
            priceforperday = 70.0;
        }
        else if (roomType == "Double")
        {
            priceforperday = 250.0;
        }
        else if (roomType == "Lux")
        {
            priceforperday = 750.0;
        }
        else
        {
            cout << "Invalid room type!" << endl;
            return;
        }

        totalPrice = priceforperday * duration;

        cout << "Price per day: $" << priceforperday << endl;
        cout << "Total Price: $" << totalPrice << endl;

        cout << "Confirm booking? (yes/no): ";
        string confirm;
        cin >> confirm;

        if (confirm == "yes")
        {
            guests[guestCount++] = { name, roomType, duration, totalPrice };
            cout << "Room booked successfully!" << endl;

            ofstream billFile(name + "_bill.txt");
            if (billFile.is_open())
            {
                billFile << "    GoldHotel" << endl;
                billFile << "***********************" << endl;
                billFile << "Received from: Mr. John" << endl;
                billFile << "Room Type: " << roomType << endl;
                billFile << "Number of Days: " << duration << endl;
                billFile << "Payment Details:" << endl;
                billFile << "Total Amount: $" << totalPrice << endl;
                billFile << "Paid" << endl;
                billFile << "Signature: __________________" << endl;
                billFile.close();
                cout << "Bill created successfully." << endl << endl;
            }
            else
            {
                cout << "Unable to create bill file!" << endl;
            }
        }
        else
        {
            cout << "Booking cancelled." << endl << endl;
        }
    }
void displayServices() const
{
    cout << "Available Services:" << endl;
    cout << "1. Spa - $50 per session" << endl;
    cout << "2. Restaurant - $30 per meal" << endl;
    cout << "3. Gym - $20 per visit" << endl;
    cout << "4. Laundry - $10 per load" << endl << endl;
}

void accountingForGuests() const
{
    cout << "Guests List:" << endl;
    for (int i = 0; i < guestCount; ++i)
    {
        cout << "Name: " << guests[i].name << ", Room Type: " << guests[i].roomType
            << ", Duration: " << guests[i].duration << " days" << endl;
    }
}

void calculateBill(const Guest& guest) const
{
    cout << "Total Bill for " << guest.name << ": $" << guest.totalPrice << endl << endl;
}

void roomOccupancyAnalysis() const
{
    int singleRooms = 0, doubleRooms = 0, suiteRooms = 0;

    for (int i = 0; i < guestCount; ++i)
    {
        if (guests[i].roomType == "Single")
        {
            singleRooms++;
        }
        else if (guests[i].roomType == "Double")
        {
            doubleRooms++;
        }
        else if (guests[i].roomType == "Lux")
        {
            suiteRooms++;
        }
    }

    cout << "Room Occupancy Analysis:"<<endl;
    cout << "Single Rooms Occupied: " << singleRooms << endl;
    cout << "Double Rooms Occupied: " << doubleRooms << endl;
    cout << "Lux Rooms Occupied: " << suiteRooms << endl << endl;
}

void orderFoodAndDrinksForRoom() // Updated function name
{
    string roomNumber;
    cout << "Enter room number to order food and drinks: ";
    cin >> roomNumber;
    cout << endl;
    cout << "Food Menu:"<<endl;
    cout << "1. Pizza - 13$" << endl;
    cout << "2. Burger - 8$" << endl;
    cout << "3. Pasta - 10$" << endl;
    cout << "4. Soup - 5$" << endl;
    int choice;
    cout << "Enter the number of the food item to order: ";
    cin >> choice;

    if (choice >= 1 && choice <= 4)
    {
        double totalPrice=0;
        if (choice == 1)
        {
            totalPrice += 13;
        }
        else if (choice == 2)
        {
            totalPrice += 8;
        }
        else if (choice == 3)
        {
            totalPrice += 10;
        }
        else if (choice == 4)
        {
            totalPrice += 5;
        }
        else
        {
            cout << "Incorrect choice!" << endl;
        }

        // For drinks
        cout << "Drinks Menu:" << endl;
        cout << "1. Water - 2$" << endl;
        cout << "2. Soda - 3$" << endl;
        cout << "3. Juice - 4$" << endl;
        int drinkChoice;
        cout << "Enter the number of the drink to order: ";
        cin >> drinkChoice;

        if (drinkChoice >= 1 && drinkChoice <= 3)
        {
            if (drinkChoice == 1)
            {
                totalPrice += 2;
            }
            else if (drinkChoice == 2)
            {
                totalPrice += 3;
            }
            else if (drinkChoice == 3)
            {
                totalPrice += 4;
            }
            else
            {
                cout << "Incorrect choice!" << endl;
            }
        }
        cout << "Total Price for food and drinks: $" << totalPrice << endl;
        // Create bill check file
                ofstream billCheck("BillCheckforFood.txt");
                if (billCheck.is_open())
                {
                    billCheck << "     GoldHotel" << endl;
                    billCheck << "Room Service: Food and Drinks" << endl;
                    billCheck << "Room №: " << roomNumber << endl;
                    billCheck << "*****************************" << endl;
                    billCheck << "List of Order:" << endl;
                    billCheck << "Foods: " << endl;
                    if (choice == 1)
                    {
                        billCheck << "Pizza - 13$" << endl;
                    }
                    else if (choice == 2)
                    {
                        billCheck << "Burger - 8$" << endl;
                    }
                    else if (choice == 3)
                    {
                        billCheck << "Pasta - 10$" << endl;
                    }
                    else if (choice == 4)
                    {
                        billCheck << "Soup - 5$" << endl;
                    }
                    billCheck << "Drinks: " << endl;;
                    if (drinkChoice == 1)
                    {
                        billCheck << "Water - $2" << endl;
                    }
                    else if (drinkChoice == 2)
                    {
                        billCheck << "Soda - $3" << endl;
                    }
                    else if (drinkChoice == 3)
                    {
                        billCheck << "Juice - $4" << endl;
                    }
                    billCheck << "Total Cost: $" << totalPrice << endl;
                    billCheck << "Signature: ___________________" << endl;
                    billCheck.close();
                    cout << "Bill check created successfully." << endl << endl;
                }
                else
                {
                    cout << "Unable to create bill check file!" << endl << endl;
                }
            }
            else
            {
                cout << "Invalid choice!" << endl;
            }
        }

        void roomService()
        {
            cout << "Room Service: " << endl;
            string roomnumber;
            cout << "Enter the room number: ";
            cin >> roomnumber;
            int choice;
            do
            {
                cout << "1. Laundary (Service which washes and irons clothes, sheets and towels for guests)" << endl;
                cout << "2. Cleaning (Service which clesns the room)" << endl;
                cout << "3. Transportation (Service which will order the taxi for guests)" << endl;
                cout << "4. Go to the main menu." << endl;
                cout << "Enter the number to use the service " << endl;
                cin >> choice;
                if (choice >= 1 && choice <= 3)
                {
                    if (choice == 1)
                    {
                        cout << "The service is orderred and the close will be ready after 4 hours" << endl<<endl;
                    }
                    else if (choice == 2)
                    {
                        cout << "The cleaning is ordered to room number: "<<roomnumber << endl<<endl;
                    }
                    else if (choice == 3)
                    {
                        string str;
                        cout << "Enter the location of place to order the taxi: ";
                        //getline(cin, str);
                        cin >> str;
                        cout << "The taxi ordered to " << str << " successfully" << endl<<endl;
                    }
                }
            } while (choice != 4);
        }

        void startHotelManagement()
        {
            string inUsername, inPassword;
            cout << "Enter Login: ";
            cin >> inUsername;
            cout << "Enter Password: ";
            cin >> inPassword;

            if (checkpassword(inUsername, inPassword))
            {
                cout << "Login Successful!" << endl << endl;

                int choice;
                do
                {
                    showMenu();
                    cout << "Enter your choice: ";
                    cin >> choice;


                    switch (choice)
                        {
                        case 0:
                            break;
                        case 1:
                            bookRoom();
                            break;
                        case 2:
                            displayServices();
                            break;
                        case 3:
                            accountingForGuests();
                            break;
                        case 4:
                        {
                            // For billing, prompt for guest name and calculate bill
                            string guestName;
                            cout << "Enter guest name for billing: ";
                            cin.ignore();
                            getline(cin, guestName);
                            for (int i = 0; i < guestCount; ++i)
                            {
                                if (guests[i].name == guestName)
                                {
                                    calculateBill(guests[i]);
                                    break;
                                }
                            }
                            break;
                        }
                        case 5:
                        {
                            roomOccupancyAnalysis();
                            break;
                        }
                        case 6:
                        {
                            orderFoodAndDrinksForRoom(); // Updated function call
                            break;
                        }
                        case 7:
                        {
                            roomService();
                            break;
                        }
                        case 8:
                        {
                            cout << "Exiting..." << endl << endl;
                            break;
                        }
                        default:
                        {
                            cout << "Incorrect choice, Please try again." << endl;
                            break;
                        }
                        }
                    } while (choice != 8);
                    }
                    else
                    {
                    cout << "Incorrect login." << endl;
                    }
                    }
                    };

                    int main()
                    {
                    hotel m("admin", "admin123");
                    m.startHotelManagement();

                    return 0;
                    }

