#include <iostream>
#include <vector>
#include <string>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

// Cтруктурa для хранения данных о прогнозе погоды на один день
struct DailyWeatherForecast
{
  std::string date;
  double minTemp;
  double maxTemp;
};

// Kласс для получения данных о погоде
class WeatherForecast
{
private:
  std::string apiKey;                          // Ключ API
  std::vector<DailyWeatherForecast> forecasts; // Список прогнозов погоды

public:
  // Конструктор класса
  WeatherForecast(const std::string &key) : apiKey(key) {}

  // Метод для получения прогноза погоды на 5 дней
  void getForecast(const std::string &postalCode)
  {
    // Формирование URL запроса
    std::string url = "http://api.openweathermap.org/data/2.5/forecast?zip=" + postalCode + ",us&appid=" + apiKey + "&units=metric";

    // Отправляем GET-запрос на сервер openweathermap
    auto response = cpr::Get(cpr::Url{url});

    // Проверяем, успешен ли запрос
    if (response.status_code == 200)
    {
      // Преобразуем полученные данные в формат JSON
      json jsonData = json::parse(response.text);

      // Очищаем список прогнозов
      forecasts.clear();

      // Получаем данные о прогнозе погоды на 5 дней
      for (const auto &item : jsonData["list"])
      {
        DailyWeatherForecast forecast;
        forecast.date = item["dt_txt"];
        forecast.minTemp = item["main"]["temp_min"];
        forecast.maxTemp = item["main"]["temp_max"];
        forecasts.push_back(forecast);
      }
    }
    else
    {
      std::cout << "Error: " << response.status_code << std::endl;
    }
  }

  // Метод для вывода прогноза погоды на все 5 дней
  void printAllForecasts()
  {
    for (const auto &forecast : forecasts)
    {
      std::cout << "Date: " << forecast.date << std::endl;
      std::cout << "Min Temperature: " << forecast.minTemp << "C" << std::endl;
      std::cout << "Max Temperature: " << forecast.maxTemp << "C" << std::endl;
    }
  }

  // Метод для вывода прогноза погоды на конкретный день
  void printForecastForDay(int day)
  {
    if (day >= 1 && day <= forecasts.size())
    {
      const auto &forecast = forecasts[day - 1];
      std::cout << "Date: " << forecast.date << std::endl;
      std::cout << "Min Temperature: " << forecast.minTemp << "°C" << std::endl;
      std::cout << "Max Temperature: " << forecast.maxTemp << "°C" << std::endl;
    }
    else
    {
      std::cout << "Invalid day" << std::endl;
    }
  }
};
