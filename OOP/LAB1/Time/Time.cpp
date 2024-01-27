#include "Time.h"

Time::Time() {
    seconds = 0;
    minutes = 0;
    hours = 0;
}

Time::Time(double hours, double minutes, double seconds) {
    if (hours >= 0 && minutes >= 0 && seconds >= 0) {
        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;
        return;
    }
    throw "Время не может быть отрицательным"; //сообщение об ошибке
}
//геттеры и сеттеры
double Time::getHours() const { return hours; }
double Time::getMinutes() const { return minutes; }
double Time::getSeconds() const { return seconds; }
void Time::setHours(double hours) {
    if (hours >= 0) {
        this->hours = hours;
    }
}
void Time::setMinutes(double minutes) {
    if (minutes >= 0) {
        this->minutes = minutes;
    }
}
void Time::setSeconds(double seconds) {
    if (seconds >= 0) {
        this->seconds = seconds;
    }
}

//метод для перевода времени в часы
double Time::convertToHours() {
    return hours + minutes / 60 + seconds / 3600;
}

//метод для перевода времени в минуты
double Time::convertToMinutes() {
    return  hours * 60 + minutes + seconds / 60;
}

//метод для перевода времени в секунды
double Time::convertToSeconds() {
    return  hours * 3600 + minutes * 60 + seconds;
}
// метод для перевода времени в строку
std::string Time::getString() const {
    std::string result;
    result += std::to_string(static_cast<int>(hours)) + ":" + std::to_string(static_cast<int>(minutes)) + ":" + std::to_string(static_cast<int>(seconds));
    return result;
}
// метод для добавления часов
void Time::addHours(double hours) {
    if (hours >= 0) {
        this->hours += hours;
    }
}
// метод для добавления минут
void Time::addMinutes(double minutes) {
    if (minutes >= 0) {
        this->minutes += minutes;
    }
}
// метод для добавления секунд
void Time::addSeconds(double seconds) {
    if (seconds >= 0) {
        this->seconds += seconds;
    }
}
// метод для сложения времени
Time Time::operator+(const Time& other) {
    return Time(hours + other.hours, minutes + other.minutes, seconds + other.seconds);
}
// метод для вычитания времени
Time Time::operator-(const Time& other) {
    return Time(hours - other.hours, minutes - other.minutes, seconds - other.seconds);
}
// метод для вывода
std::ostream& operator<<(std::ostream& out, const Time& other) {
    return out << other.getHours() << ":" << other.getMinutes() << ":" << other.getSeconds();
}

//Перегрузка оператора сравнения на равенство
bool Time::operator==(const Time& other) const {
    return hours == other.hours && minutes == other.minutes && seconds == other.seconds;
}
