#include <iostream>
#include <map>
#include <set>
#include <string>

struct Flight {
    std::string route;
    std::string departureTime;
};

std::map<int, Flight> schedule;
std::set<int> flightIDs;

void addFlight(int flightID, const std::string& route, const std::string& departureTime) {
    if (flightIDs.count(flightID) == 0) {
        schedule[flightID] = {route, departureTime};
        flightIDs.insert(flightID);
        std::cout << "Flight " << flightID << " added to the schedule.\n";
    } else {
        std::cout << "Flight with ID " << flightID << " already exists.\n";
    }
}
void removeFlight(int flightID) {
    if (flightIDs.count(flightID) == 1) {
        schedule.erase(flightID);
        flightIDs.erase(flightID);
        std::cout << "Flight " << flightID << " removed from the schedule.\n";
    } else {
        std::cout << "Flight with ID " << flightID << " not found.\n";
    }
}

int main() {
    addFlight(1, "New York - London", "10:00");
    addFlight(2, "Paris - Tokyo", "14:30");
    addFlight(1, "Moscow - Berlin", "09:00"); // пытаемя создать повторяющийся рейс, но ничего не выйдет :D
     removeFlight(2);
    return 0;
}

