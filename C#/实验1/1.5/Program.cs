using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1._5
{
    class Program
    {
        static void Main(string[] args)
        {
            int num = 0;
            int sum = 0;
            int temp = 1;
            num = Int32.Parse(Console.ReadLine());
            for (int i = 1; i <= num; ++i)
            {
                temp *= i;
                sum += temp;
            }
            Console.WriteLine("1!+2!+3!+...+{0}! = {1}", num, sum);
            Console.Read();
        }
    }
}
