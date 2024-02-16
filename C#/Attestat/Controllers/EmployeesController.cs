using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Generic;

namespace MyCompany.Controllers
{
    public class EmployeesController : Controller
    {
        public IActionResult Index()
        {
            List<Employee> employees = new List<Employee>
            {
                new Employee { FullName = "Иванов Иван Иванович", Age = 32 },
                new Employee { FullName = "Петров Петр Петрович", Age = 43 },
                new Employee { FullName = "Васильев Василий Васильевич", Age = 21 }
            };

            return View(employees);
        }

        public IActionResult Details(string fullName)
        {
            //  логика для получения дополнительной информации о сотруднике
            Employee employee = new Employee { FullName = fullName, Age = 30, BirthDate = new DateTime(1990, 5, 15) };

            return View(employee);
        }
    }

    // класс сотрудник
    public class Employee
    {
        public required string FullName { get; set; }
        public int Age { get; set; }
        public DateTime BirthDate { get; set; }
    }
}