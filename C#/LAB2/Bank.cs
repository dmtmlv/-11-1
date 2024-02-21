using System;

public class KolichestvoException : Exception
{
    public KolichestvoException() : base("Ошибка: отрицательное значение параметра 'Количество месяцев'")
    {
    }
}

public class VkladException : Exception
{
    public VkladException(double summa) : base($"Невозможно создать вклад – указана отрицательная сумма вклада: {summa}")
    {
    }
}

public class Bank
{
    public string Name { get; set; }
}

public class Branch
{
    public string Name { get; set; }
    public double TotalDeposits { get; set; }
}

public class Deposit
{
    public string FullName { get; set; }
    public double Amount { get; set; }

    public virtual double CalculateDepositAmount(int months)
    {
        return Amount * months;
    }
}

public class LongTermDeposit : Deposit
{
    public override double CalculateDepositAmount(int months)
    {
        try
        {
            if (months < 0)
            {
                throw new KolichestvoException();
            }
        }
        catch (KolichestvoException ex)
        {
            Console.WriteLine(ex.Message);
        }

        return Amount * months;
    }
}

public class InstantAccessDeposit : Deposit
{
    public override double CalculateDepositAmount(int months)
    {
        try
        {
            if (months < 0)
            {
                throw new KolichestvoException();
            }
        }
        catch (KolichestvoException ex)
        {
            Console.WriteLine(ex.Message);
        }

        return Amount * months;
    }
}

class Program
{
    public static void Main(string[] args)
    {
        try
        {
            Deposit deposit = new Deposit { FullName = "Иванов Иван Иванович", Amount = -5000 };
            Branch branch = new Branch { Name = "Отделение №1", TotalDeposits = 1000000 };

            double depositAmount = deposit.CalculateDepositAmount(12);
            Console.WriteLine($"Сумма вклада: {depositAmount}");

            InstantAccessDeposit instantDeposit = new InstantAccessDeposit { FullName = "Петров Петр Петрович", Amount = 8000 };
            double instantDepositAmount = instantDeposit.CalculateDepositAmount(-6);
            Console.WriteLine($"Сумма вклада до востребования: {instantDepositAmount}");
        }
        catch (VkladException ex)
        {
            Console.WriteLine(ex.Message);
        }
    }
}

