using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1._1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("请输入您的成绩：");
            double grade = Double.Parse(Console.ReadLine());
            if (grade >= 90)
                Console.WriteLine("优秀");
            else if (grade >= 80)
                Console.WriteLine("良好");
            else if (grade >= 70)
                Console.WriteLine("中等");
            else if (grade >= 60)
                Console.WriteLine("及格");
            else
                Console.WriteLine("不及格");
            Console.ReadLine();
        }
    }
}
