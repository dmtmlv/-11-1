#include "Time.hpp"

// Конструктор с параметрами
Time::Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

// Геттеры и сеттеры
int Time::getHours() const { return hours; }
int Time::getMinutes() const { return minutes; }
int Time::getSeconds() const { return seconds; }
void Time::setHours(int h) { hours = h; }
void Time::setMinutes(int m) { minutes = m; }
void Time::setSeconds(int s) { seconds = s; }

// Сложение времени
Time Time::operator+(const Time& t) const {
    int s = seconds + t.seconds;
    int m = minutes + t.minutes + s / 60;
    s %= 60;
    int h = hours + t.hours + m / 60;
    m %= 60;
    return Time(h, m, s);
}

// Вычитание времени
Time Time::operator-(const Time& t) const {
    int s = seconds - t.seconds;
    int m = minutes - t.minutes;
    if (s < 0) {
        s += 60;
        m--;
    }
    int h = hours - t.hours;
    if (m < 0) {
        m += 60;
        h--;
    }
    return Time(h, m, s);
}

// Добавление времени в минутах
void Time::addMinutes(int m) {
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}

// Перевод времени в секунды
int Time::toSeconds() const {
    return hours * 3600 + minutes * 60 + seconds;
}

// Преобразование в строку (в формате Часы:Минуты:Секунды)
std::string Time::toString() const {
    std::stringstream ss;
    ss << std::setfill('0') << std::setw(2) << hours << ":"
        << std::setfill('0') << std::setw(2) << minutes << ":"
        << std::setfill('0') << std::setw(2) << seconds;
    return ss.str();
}