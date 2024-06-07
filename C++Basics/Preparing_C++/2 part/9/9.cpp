#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct Course {
    string name;
    vector<string> students;
};

int main() {
    unordered_map<int, Course> courses;

    Course course1;
    course1.name = "Основы с++";
    course1.students.push_back("Томилов");
    course1.students.push_back("Петров");
    courses[1] = course1;

    courses.erase(1);

    return 0;
}
