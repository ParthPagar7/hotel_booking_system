#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Define a class for representing a room
class Room {
private:
    int roomNumber;
    bool isOccupied;
    string guestName;

public:
    Room(int number) : roomNumber(number), isOccupied(false), guestName("") {}

    // Getter methods
    int getRoomNumber() const { return roomNumber; }
    bool getIsOccupied() const { return isOccupied; }
    string getGuestName() const { return guestName; }

    // Setter methods
    void setIsOccupied(bool occupied) { isOccupied = occupied; }
    void setGuestName(string name) { guestName = name; }
};

// Define a class for representing a booking
class Booking {
private:
    string guestName;
    int roomNumber;
    string checkInDate;
    string checkOutDate;

public:
    Booking(string name, int room, string checkIn, string checkOut) : guestName(name), roomNumber(room), checkInDate(checkIn), checkOutDate(checkOut) {}

    // Getter methods
    string getGuestName() const { return guestName; }
    int getRoomNumber() const { return roomNumber; }
    string getCheckInDate() const { return checkInDate; }
    string getCheckOutDate() const { return checkOutDate; }
};

// Define a class for the booking system
class BookingSystem {
private:
    vector<Room> rooms;
    vector<Booking> bookings;

public:
    // Constructor to initialize rooms
    BookingSystem(int numRooms) {
        for (int i = 1; i <= numRooms; ++i) {
            rooms.push_back(Room(i));
        }
    }

    // Method to book a room
    void bookRoom(string guestName, int roomNumber, string checkInDate, string checkOutDate) {
        if (roomNumber < 1 || roomNumber > rooms.size()) {
            cout << "Invalid room number." << endl;
            return;
        }

        Room& room = rooms[roomNumber - 1];
        if (room.getIsOccupied()) {
            cout << "Room " << roomNumber << " is already occupied." << endl;
            return;
        }

        room.setIsOccupied(true);
        room.setGuestName(guestName);
        bookings.push_back(Booking(guestName, roomNumber, checkInDate, checkOutDate));
        cout << "Room " << roomNumber << " booked successfully for " << guestName << "." << endl;
    }

    // Method to display all bookings
    void displayBookings() const {
        if (bookings.empty()) {
            cout << "No bookings available." << endl;
            return;
        }

        cout << "Bookings:" << endl;
        for (const auto& booking : bookings) {
            cout << "Guest: " << booking.getGuestName() << ", Room: " << booking.getRoomNumber() << ", Check-in: " << booking.getCheckInDate() << ", Check-out: " << booking.getCheckOutDate() << endl;
        }
    }
};

int main() {
    // Initialize booking system with 5 rooms
    BookingSystem bookingSystem(5);

    // Book some rooms
    bookingSystem.bookRoom("Alice", 1, "2024-03-15", "2024-03-20");
    bookingSystem.bookRoom("Bob", 3, "2024-03-18", "2024-03-25");

    // Display all bookings
    bookingSystem.displayBookings();

    return 0;
}
