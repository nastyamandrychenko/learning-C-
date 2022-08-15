using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Variables
{
    class Program
    {
        static void Main(string[] args)
        {
            int num, num1;

            Console.WriteLine("Multiplication");
            Console.WriteLine("Enter first value");
            num = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Enter second value");
            num1 = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("The resut is " + (num * num1));
            Console.ReadKey();
        }
    }
}
