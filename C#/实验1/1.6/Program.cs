using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1._6
{
    class Program
    {
        static void Main(string[] args)
        {
            int addup = 1, adddown = 1;
            int up = 2, down = 1;
            double sum = 0;

            for (int i = 0; i < 20; ++i)
            {
                sum += (double)up / down;

                int tempup = up;
                int tempdown = down;
                up += addup;
                down += adddown;
                addup = tempup;
                adddown = tempdown;
            }
            Console.WriteLine("结果为：{0}", sum);
            Console.Read();
        }
    }
}
