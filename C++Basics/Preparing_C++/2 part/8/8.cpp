#include <iostream>
#include <map>
#include <string>
#include <ctime>

struct Meeting {
    std::string date;
    std::string time;
};

int main() {
    std::map<int, Meeting> meetings; // Map для хранения встреч по уникальному ID

    // Добавление новой встречи
    Meeting newMeeting;
    newMeeting.date = "2022-12-31";
    newMeeting.time = "15:00";
    int meetingID = 1;
    meetings.insert(std::make_pair(meetingID, newMeeting));

    // Удаление существующей встречи
    int meetingToDeleteID = 1;
    auto it = meetings.find(meetingToDeleteID);
    if (it != meetings.end()) {
        meetings.erase(it);
        std::cout << "Встреча с ID " << meetingToDeleteID << " была удалена.\n";
    } else {
        std::cout << "Встреча с ID " << meetingToDeleteID << " не найдена.\n";
    }

    return 0;
}

