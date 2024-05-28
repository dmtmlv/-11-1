using System;
using System.Collections.Generic;
using System.Linq;

class Book
{
    public string Title { get; set; }
    public string Author { get; set; }
    public double Price { get; set; }
    public DateTime PublicationDate { get; set; }
    public string Publisher { get; set; }
    public List<string> InventoryNumbers { get; set; }
}

class Program
{
    static void Main()
    {
        List<Book> books = new List<Book>
        {
            new Book { Title = "Book1", Author = "Author1", Price = 10.01, PublicationDate = new DateTime(2000, 1, 1), Publisher = "Publisher1", InventoryNumbers = new List<string> { "INV001", "INV002" } },
            new Book { Title = "Book2", Author = "Author2", Price = 20.02, PublicationDate = new DateTime(2010, 2, 02), Publisher = "Publisher2", InventoryNumbers = new List<string> { "INV003" } },
            new Book { Title = "Book3", Author = "Author1", Price = 30.03, PublicationDate = new DateTime(2020, 3, 03), Publisher = "Publisher1", InventoryNumbers = new List<string> { "INV004" } },
            new Book { Title = "Book4", Author = "Author2", Price = 40.04, PublicationDate = new DateTime(2030, 4, 04), Publisher = "Publisher2", InventoryNumbers = new List<string> { "INV005", "INV006" } }
        };

        // Все книги из списка
        Console.WriteLine("Все книги из списка:");
        foreach (var book in books)
        {
            
            Console.WriteLine($"Title: {book.Title}, Author: {book.Author}, Price: {book.Price}, Publication Date: {book.PublicationDate}, Publisher: {book.Publisher}, Inventory Numbers: {string.Join(", ", book.InventoryNumbers)}");
        }

        // Выборка данных по книге Book1
        Console.WriteLine("\nВыборка данных по книге 'Book1':");
        var filteredBooks = books.Where(b => b.Title == "Book1");
        foreach (var book in filteredBooks)
        {
           
            Console.WriteLine($"Title: {book.Title}, Author: {book.Author}, Price: {book.Price}, Publication Date: {book.PublicationDate}, Publisher: {book.Publisher}, Inventory Numbers: {string.Join(", ", book.InventoryNumbers)}");
        }

        // сортировка по полю PublicationDate
        Console.WriteLine("\nСортировка по дате:");
        var sortedBooks = books.OrderBy(b => b.PublicationDate);
        foreach (var book in sortedBooks)
        {
           
            Console.WriteLine($"Title: {book.Title}, Author: {book.Author}, Price: {book.Price}, Publication Date: {book.PublicationDate}, Publisher: {book.Publisher}, Inventory Numbers: {string.Join(", ", book.InventoryNumbers)}");
        }

        // группировка данных
        Console.WriteLine("\nГруппировка данных:");
        var groupedByAuthor = books.GroupBy(b => b.Author);
        foreach (var group in groupedByAuthor)
        {
            Console.WriteLine($"Author: {group.Key}");
            foreach (var book in group)
            {
                Console.WriteLine($"Title: {book.Title}, Price: {book.Price}");
            }
        }

        // проекция на название и издателя
        Console.WriteLine("\nПроекция на название и издателя:");
        var bookTitles = books.Select(b => new { Title = b.Title, Publisher = b.Publisher });
        foreach (var title in bookTitles)
        {
            Console.WriteLine($"Book Title: {title.Title}, Publisher: {title.Publisher}");
        }

    }
}
