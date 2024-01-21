using System;

class Fraction
{
    private int numerator;
    private int denominator;

    public int Numerator
    {
        get { return numerator; }
        set { numerator = value; Simplify(); }
    }

    public int Denominator
    {
        get { return denominator; }
        set
        {
            if (value == 0)
                throw new ArgumentException("Знаменатель не может быть равен 0");
            denominator = value;
            Simplify();
        }
    }

    public double DecimalValue
    {
        get { return (double)numerator / denominator; }
    }

    public Fraction(int numerator, int denominator)
    {
        this.numerator = numerator;
        this.Denominator = denominator;
    }

    public void Simplify()
    {
        int gcd = GCD(Math.Abs(numerator), denominator);
        numerator /= gcd;
        denominator /= gcd;
    }

    public static int GCD(int a, int b)
    {
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    public static Fraction operator +(Fraction a, Fraction b)
    {
        return new Fraction(a.numerator * b.denominator + b.numerator * a.denominator, a.denominator * b.denominator);
    }

    public static Fraction operator -(Fraction a, Fraction b)
    {
        return new Fraction(a.numerator * b.denominator - b.numerator * a.denominator, a.denominator * b.denominator);
    }

    public static Fraction operator *(Fraction a, Fraction b)
    {
        return new Fraction(a.numerator * b.numerator, a.denominator * b.denominator);
    }

    public static Fraction operator /(Fraction a, Fraction b)
    {
        return new Fraction(a.numerator * b.denominator, a.denominator * b.numerator);
    }
}

class Program
{
    static void Main()
    {
        Fraction f1 = new Fraction(1, 2);
        Fraction f2 = new Fraction(3, 4);

        Console.WriteLine("Сложение: " + (f1 + f2).DecimalValue);
        Console.WriteLine("Вычитание: " + (f1 - f2).DecimalValue);
        Console.WriteLine("Умножение: " + (f1 * f2).DecimalValue);
        Console.WriteLine("Деление: " + (f1 / f2).DecimalValue);
    }
}
