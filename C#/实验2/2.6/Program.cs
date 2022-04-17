using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2._6
{
    class Program
    {
        //注释1：定义迭代器方法，计算number的exponent次幂
        public static IEnumerable<int> Power(int number, int exponent)
        {
            int result = 1;

            for (int i = 0; i < exponent; i++)
            {
                result = result * number;
                yield return result;
            }
        }

        static void Main(string[] args)
        {
            //注释2：调用迭代器方法，实现集合元素遍历，该集合为{2n|n=1,2,…10}
            foreach (int i in Power(2, 10))
            {
                Console.Write("{0} ", i);
            }
        }
    }

}
