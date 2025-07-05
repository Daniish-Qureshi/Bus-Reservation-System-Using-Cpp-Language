#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Bus {
private:
    string busNo;
    string driver;
    string arrival;
    string departure;
    string from;
    string to;
    string seats[8][4]; // 32 seats (8 rows × 4 cols)

public:
    void install();
    void allotSeat();
    void show();
    void available();
    void emptySeats();
    void displaySeats();
};

Bus buses[10];
int busCount = 0;

// Function to draw line
void line(char ch) {
    for (int i = 0; i < 80; i++) cout << ch;
    cout << endl;
}

// Install a new bus
void Bus::install() {
    cout << "Enter bus number: ";
    cin >> busNo;
    cout << "Enter driver's name: ";
    cin >> driver;
    cout << "Arrival time: ";
    cin >> arrival;
    cout << "Departure time: ";
    cin >> departure;
    cout << "From: ";
    cin >> from;
    cout << "To: ";
    cin >> to;

    // Initialize all seats to "Empty"
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 4; j++)
            seats[i][j] = "Empty";

    cout << "\nBus Installed Successfully!\n";
}

// Allot a seat to a passenger
void Bus::allotSeat() {
    string busNumber;
    cout << "Enter bus number: ";
    cin >> busNumber;

    int index = -1;
    for (int i = 0; i < busCount; i++) {
        if (buses[i].busNo == busNumber) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Bus number not found.\n";
        return;
    }

    int seatNo;
    cout << "Enter seat number (1 to 32): ";
    cin >> seatNo;

    if (seatNo < 1 || seatNo > 32) {
        cout << "Invalid seat number. Only 1 to 32 available.\n";
        return;
    }

    int row = (seatNo - 1) / 4;
    int col = (seatNo - 1) % 4;

    if (buses[index].seats[row][col] != "Empty") {
        cout << "Seat already reserved.\n";
    } else {
        cout << "Enter passenger name: ";
        cin >> buses[index].seats[row][col];
        cout << "Seat successfully reserved!\n";
    }
}

// Show details of a specific bus
void Bus::show() {
    string busNumber;
    cout << "Enter bus number: ";
    cin >> busNumber;

    int index = -1;
    for (int i = 0; i < busCount; i++) {
        if (buses[i].busNo == busNumber) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Bus not found.\n";
        return;
    }

    line('*');
    cout << "Bus No: " << buses[index].busNo
         << "\nDriver: " << buses[index].driver
         << "\tArrival: " << buses[index].arrival
         << "\tDeparture: " << buses[index].departure
         << "\nFrom: " << buses[index].from
         << "\tTo: " << buses[index].to << endl;
    line('*');

    buses[index].displaySeats();
}

// Show available buses
void Bus::available() {
    for (int i = 0; i < busCount; i++) {
        line('*');
        cout << "Bus No: " << buses[i].busNo
             << "\nDriver: " << buses[i].driver
             << "\tArrival: " << buses[i].arrival
             << "\tDeparture: " << buses[i].departure
             << "\nFrom: " << buses[i].from
             << "\tTo: " << buses[i].to << endl;
        line('*');
    }
}

// Display seat arrangement
void Bus::displaySeats() {
    int emptyCount = 0;
    int seatNum = 1;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            cout << setw(3) << seatNum << ". ";
            cout << setw(10) << left << seats[i][j] << " ";
            if ((j + 1) % 4 == 0) cout << endl;
            if (seats[i][j] == "Empty") emptyCount++;
            seatNum++;
        }
    }

    cout << "\nTotal Empty Seats: " << emptyCount << endl;
}

// MAIN
int main() {
    int choice;

    while (true) {
        cout << "\n\n===== BUS RESERVATION SYSTEM =====\n";
        cout << "1. Install Bus\n";
        cout << "2. Reserve Seat\n";
        cout << "3. Show Bus Info\n";
        cout << "4. Show Available Buses\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (busCount < 10) {
                buses[busCount].install();
                busCount++;
            } else {
                cout << "Maximum bus limit reached!\n";
            }
            break;
        case 2:
            buses[0].allotSeat(); // allot seat for selected bus
            break;
        case 3:
            buses[0].show();      // show info for selected bus
            break;
        case 4:
            buses[0].available(); // list all available buses
            break;
        case 5:
            cout << "Exiting program. Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
