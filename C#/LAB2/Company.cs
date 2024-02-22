using System;

public class PremiyaException : Exception
{
    public PremiyaException() : base("Отрицательное значение параметра 'Премия'")
    {
    }
}

public class OkladException : Exception
{
    public int OkladError {get; set;}
    public OkladException(double oklad) : base($"Невозможно добавить сотрудника – указан отрицательный оклад: {oklad}")
    {
        OkladError = oklad;
    }
}

public class Firma
{
    public string Name { get; set; }
}

public class Otdel
{
    public string Name { get; set; }
    public int NumberOfEmployees { get; set; }
}

public class ShtatnySotrudnik
{
    public double Premiya { get; set; }

    public double CalculateSalary()
    {
        try
        {
            if (Premiya < 0)
            {
                throw new PremiyaException();
            }
        }
        catch (PremiyaException ex)
        {
            Console.WriteLine(ex.Message);
        }

        return Premiya;
    }
}

public class Sotrudnik
{
    public string FullName { get; set; }
    public string Position { get; set; }
    public double Oklad { get; set; }

    public double CalculateSalary()
    {
        try
        {
            if (Oklad < 0)
            {
                throw new OkladException(Oklad);
            }
        }
        catch (OkladException ex)
        {
            Console.WriteLine(ex.Message + $". Некорректная сумма оклада {ex.OkladError}");
        }

        return Oklad;
    }
}

public class SotrudnikPoKontraktu
{
    public double CalculateSalary()
    {
        return 0;
    }
}

class Program
{
    public static void Main(string[] args)
    {
        ShtatnySotrudnik shtatnySotrudnik = new ShtatnySotrudnik { Premiya = -1000 };
        double salary = shtatnySotrudnik.CalculateSalary();

        Sotrudnik sotrudnik = new Sotrudnik { FullName = "Иванов Иван Иванович", Position = "Менеджер", Oklad = -2000 };
        double sotrudnikSalary = sotrudnik.CalculateSalary();
    }
}
