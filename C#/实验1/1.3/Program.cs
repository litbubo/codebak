using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1._3
{
    class Program
    {
        static void Main(string[] args)
        {
            double send = 0, rec = 0;
            double temp = 0.01;
            for (int i = 0; i < 30; ++i)
            {
                send += 100000;
                rec += temp;
                temp *= 2;
            }
            Console.WriteLine("富翁给陌生人的钱：{0}元", send);
            Console.WriteLine("陌生人给富翁的钱：{0}元", rec);
            Console.ReadLine();

        }
    }
}
