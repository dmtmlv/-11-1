using System;

public class OstatokNaSchetException : Exception
{
    public OstatokNaSchetException(double ostatok) : base($"Невозможно создать счет – указано некорректное значение остатка на счете: {ostatok}")
    {
    }
}

public class SnyatSoSchetaException : Exception
{
    public SnyatSoSchetaException(string message) : base("Невозможно снять со счета")
    {
    }
}

public class Bank
{
    public string Name { get; set; }
}

public class Account
{
    public string Number { get; set; }
    public int Pin { get; set; }
    public double Balance { get; set; }

    public Account(string number, int pin, double balance)
    {
        if (balance < 0)
        {
            throw new OstatokNaSchetException(balance);
        }

        Number = number;
        Pin = pin;
        Balance = balance;
    }

    public void SnyatSoScheta(double amount)
    {
        try
        {
            if (amount < 0 || amount > Balance)
            {
                throw new SnyatSoSchetaException("Ошибка при снятии средств со счета");
            }
            Balance -= amount;
        }
        catch (SnyatSoSchetaException ex)
        {
            Console.WriteLine(ex.Message);
        }
    }
}

public class RegularAccount : Account
{
    public RegularAccount(string number, int pin, double balance) : base(number, pin, balance)
    {
    }

    public new void SnyatSoScheta(double amount)
    {
        try
        {
            if (amount < 0 || amount > Balance)
            {
                throw new SnyatSoSchetaException("Ошибка при снятии средств со счета");
            }
            Balance -= amount;
        }
        catch (SnyatSoSchetaException ex)
        {
            Console.WriteLine(ex.Message);
        }
    }
}

public class PreferentialAccount : Account
{
    public PreferentialAccount(string number, int pin, double balance) : base(number, pin, balance)
    {
    }

    public new void SnyatSoScheta(double amount)
    {
        try
        {
            if (amount < 0 || amount > Balance)
            {
                throw new SnyatSoSchetaException("Ошибка при снятии средств со счета");
            }
            Balance -= amount;
        }
        catch (SnyatSoSchetaException ex)
        {
            Console.WriteLine(ex.Message);
        }
    }
}

public class ATM
{
    public int Id { get; set; }
    public string Address { get; set; }
}

class Program
{
    public static void Main(string[] args)
    {
        try
        {
            Account account = new Account("123456", 1234, 2000);
            account.SnyatSoScheta(600); 
            account.SnyatSoScheta(-300);
            account.SnyatSoScheta(1000);
        }
        catch (OstatokNaSchetException ex)
        {
            Console.WriteLine(ex.Message);
        }
    }
}

