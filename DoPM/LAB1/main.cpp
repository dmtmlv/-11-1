#include <iostream>
#include <string>
#include "API_Weather.cpp"
int main()
{
    // Вводим ключ API openweathermap
    std::string apiKey = "6621222c73cda5b82906e5145ce74aa2";

    // Создаем объект класса WeatherForecast
    WeatherForecast weatherForecast(apiKey);

    // Вводим почтовый индекс
    std::string postalCode;
    std::cout << "Enter postal code: ";
    std::cin >> postalCode;

    // Получаем прогноз погоды
    weatherForecast.getForecast(postalCode);

    // Выводим прогноз погоды на все 5 дней
    std::cout << "All Forecasts:" << std::endl;
    weatherForecast.printAllForecasts();

    // Вводим день, для которого хотим вывести прогноз
    int day;
    std::cout << "Enter day (1-5): ";
    std::cin >> day;

    // Выводим прогноз погоды для выбранного дня
    std::cout << "Forecast for Day " << day << ":" << std::endl;
    weatherForecast.printForecastForDay(day);

    return 0;
}