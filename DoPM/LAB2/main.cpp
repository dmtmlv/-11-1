#include <iostream>
#include <httplib.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

// Функция для получения списка рейсов по заданной дате из одного пункта в другой
json getFlightsByDate(const std::string& date, const std::string& from, const std::string& to) {
    // URL запрос к API яндекс.расписания
    std::string url = "https://api.rasp.yandex.net/v3.0/search/?apikey=3284c898-f76e-42e3-a319-7bb498890219&format=json&date=" + "&from=" + from + "&to=" + to + date ;

    // GET запрос
    httplib::Client client("api.rasp.yandex.net");
    auto res = client.Get(url.c_str());

    // Проверяем статус код ответа
    if (res && res->status == 200) {
        json response = json::parse(res->body);

        // Если запрос успешный, возвращаем список рейсов
        if (response["pager"]["total"].get<int>() > 0) {
            return response["segments"];
        }
    }

    // Если произошла ошибка или рейсов не найдено, возвращаем пустой список
    return json::array();
}

// Функция для получения списка ближайших станций по заданному адресу
json getNearestStations(const std::string& address) {
    // URL запрос к API геокодера
    std::string url = "https://geocode-maps.yandex.ru/1.x/?apikey=fa4be221-a58a-4f4c-b845-f243f16e0e43&format=json&geocode=" + address;

    // GET запрос
    httplib::Client client("geocode-maps.yandex.ru");
    auto res = client.Get(url.c_str());

    // Проверяем статус код ответа
    if (res && res->status == 200) {
        json response = json::parse(res->body);

        // Если запрос успешный, возвращаем список ближайших станций
        if (response["response"]["GeoObjectCollection"]["metaDataProperty"]["GeocoderResponseMetaData"]["found"].get<int>() > 0) {
            return response["response"]["GeoObjectCollection"]["featureMember"];
        }
    }

    // Если произошла ошибка или станций не найдено, возвращаем пустой список
    return json::array();
}

// Функция для получения информации о перевозчике
json getCarrierInfo(const std::string& carrierId) {
    // URL запрос к API яндекс.расписаний
    std::string url = "https://api.rasp.yandex.net/v3.0/carrier/?format=json&apikey=3284c898-f76e-42e3-a319-7bb498890219&lang=ru_RU&code=" + carrierId;

    // GET запрос
    httplib::Client client("api.rasp.yandex.net");
    auto res = client.Get(url.c_str());

    // Проверяем статус код ответа
    if (res && res->status == 200) {
        // Парсим ответ в формате JSON
        json response = json::parse(res->body);

        // Если запрос успешный, возвращаем информацию о перевозчике
        if (response["pager"]["total"].get<int>() > 0) {
            return response["carriers"][0];
        }
    }

    // Если произошла ошибка или информацию о перевозчике не найдено, возвращаем пустой объект
    return json();
}

int main() {

    // Получаем список рейсов по заданной дате из одного пункта в другой
    json flights = getFlightsByDate("c43", "c213","2024-02-08");

    // Выводим информацию о рейсах
    std::cout << "Рейсы по заданной дате из Казани в Москву:" << std::endl;
    for (const auto& flight : flights) {
        std::cout << "Номер рейса: " << flight["thread"]["number"].get<std::string>() << std::endl;
        std::cout << "Время отправления: " << flight["departure"].get<std::string>() << std::endl;
        std::cout << "Время прибытия: " << flight["arrival"].get<std::string>() << std::endl;
    }

    // Получаем список ближайших станций по заданному адресу
    json stations = getNearestStations("Казань, Северный вокзал");
    // Выводим информацию о ближайших станциях
    std::cout << "Ближайшие станции к Северному вокзалу:" << std::endl;
    for (const auto& station : stations) {
        std::cout << "Название станции: " << station["GeoObject"]["name"].get<std::string>() << std::endl;
        std::cout << "Координаты: " << station["GeoObject"]["Point"]["pos"].get<std::string>() << std::endl;
    }

    // Получаем информацию о перевозчике
    json carrier = getCarrierInfo("s9210491");

    // Выводим информацию о перевозчике
    std::cout << "Информация о перевозчике:" << std::endl;
    std::cout << "Название: " << carrier["title"].get<std::string>() << std::endl;
    std::cout << "Телефон: " << carrier["contacts"]["phone"].get<std::string>() << std::endl;
    std::cout << "Адрес офиса: " << carrier["contacts"]["address"].get<std::string>() << std::endl;

    return 0;
}