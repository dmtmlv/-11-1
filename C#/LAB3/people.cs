using System;
using System.Net;
using Newtonsoft.Json;
using System.Collections.Generic;
using System.Diagnostics.Metrics;
using System.Net.Http.Json;
using System.Reflection;

public class People
{
    public string PhoneNumber { get; set; }
    public string Operator { get; set; }
    public string FullName { get; set; }
    public string INN { get; set; }
    public string Country { get; set; }
    public string Gender { get; set; }
}

class NumberInfo
{
    public string Phone { get; set; }
    public string Provider { get; set; }
    public string Country { get; set; }
}

class InnInfo
{
    public List<Suggestions> Suggestions { get; set; }
}

public class PrettyName
{
    public string Result { get; set; }
    public string Gender { get; set; }
}

public class Suggestions
{
    public Data Data { get; set; }
}
public class Data
{
    public Management Management { get; set; }
}
public class Management
{
    public string Name { get; set; }
}

public class Request
{
    public string Query { get; set; }
}

public class People_List
{
    public List<People> PeopleCollection { get; set; }

    public People_List()
    {
        PeopleCollection = new List<People>();
    }

    public void append(People people)
    {
        this.PeopleCollection.Add(people);
    }

    public void displayAll()
    {
        foreach (var person in PeopleCollection)
        {
            Console.WriteLine(person);
            Console.WriteLine();
        }
    }

    public void SaveToFile()
    {
        using (StreamWriter writer = new StreamWriter("info.txt", append:true))
        {
            foreach (var person in PeopleCollection)
            {
                writer.WriteLine($"ФИО: {person.FullName}, Телефон: {person.PhoneNumber}, Оператор: {person.Operator}, ИНН: {person.INN}, Страна: {person.Country}, Пол: {person.Gender}");
            }
        }
    }
}

class Program
{
    static HttpClient httpClient = new HttpClient();

    static async Task Main(string[] args)
    {
        httpClient.DefaultRequestHeaders.Add("API key", "5824cefcd7a9ba30b543c84068ae017c7a149657");
        httpClient.DefaultRequestHeaders.Add("secret key", "2744d3227c1b977bb18dc4d26bd7e953ae7c8c12");

        People_List peopleList = new People_List();
        try
        {
            while (true)
            {
                Console.WriteLine("Меню:");
                Console.WriteLine("1. Добавить человека");
                Console.WriteLine("2. Отобразить всех людей");
                Console.WriteLine("3. Сохранить файл");
                Console.WriteLine("4. Выход");

                Console.Write("Выберите нужный вариант: ");
                int choice = Convert.ToInt32(Console.ReadLine());

                switch (choice)
                {
                    case 1:
                        People person = new People();
                        Console.WriteLine("Введите номер телефона: ");
                        string phoneNumber = Console.ReadLine();
                        var numberResponse = await httpClient.PostAsJsonAsync("https://cleaner.dadata.ru/api/v1/clean/phone", new[] { phoneNumber });
                        var numberResult = await numberResponse.Content.ReadFromJsonAsync<List<NumberInfo>>();

                        foreach (var num_info in numberResult)
                        {
                            person.PhoneNumber = num_info.Phone;
                            person.Operator = num_info.Provider;
                            person.Country = num_info.Country;
                        };

                        Console.WriteLine("Введите ИНН: ");
                        string inn = Console.ReadLine();
                        var innResponse = await httpClient.PostAsJsonAsync("http://suggestions.dadata.ru/suggestions/api/4_1/rs/findById/party", new Request { Query = inn });
                        var innInfo = await innResponse.Content.ReadFromJsonAsync<InnInfo>();

                        person.INN = inn;
                        person.FullName = innInfo.Suggestions[0].Data.Management.Name;

                        string[] names = { person.FullName };
                        var nameResponse = await httpClient.PostAsJsonAsync("https://cleaner.dadata.ru/api/v1/clean/name", names);
                        var prettyNames = await nameResponse.Content.ReadFromJsonAsync<List<PrettyName>>();

                        foreach (var prettyName in prettyNames)
                        {
                            person.FullName = prettyName.Result;
                            person.Gender = prettyName.Gender;
                        }

                        peopleList.append(person);
                        break;
                    case 2:
                        peopleList.displayAll();
                        break;
                    case 3:
                        peopleList.SaveToFile();
                        Console.WriteLine("Файл сохранен.");
                        break;
                    case 4:
                        return;
                    default:
                        Console.WriteLine("Недопустимый параметр. Пожалуйста, попробуйте снова.");
                        break;
                }
            }
        }  
        catch (Exception ex) 
        { 
            Console.WriteLine(ex.Message); 
        }
    }
}
