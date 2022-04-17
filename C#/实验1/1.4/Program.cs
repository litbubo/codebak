using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

namespace _1._4
{
    class Program
    {
        struct telephonebook
        {
            public String name;
            public int tel;
        }
        static void Main(string[] args)
        {
            ArrayList tellist = new ArrayList();
            while (true)
            {
                Console.WriteLine("输入exit退出输入，任意字符继续录入：");
                if ("exit" == Console.ReadLine())
                    break;
                telephonebook temp;
                Console.WriteLine("请输入姓名：");
                temp.name = Console.ReadLine();
                Console.WriteLine("请输入号码：");
                temp.tel = Int32.Parse(Console.ReadLine());
                tellist.Add(temp);
            }
            Console.WriteLine("请输入要查询的姓名：");
            string search = Console.ReadLine();
            foreach (telephonebook t in tellist)
            {
                if (search == t.name)
                    Console.WriteLine("查询到的：姓名：{0}  号码：{1}", t.name, t.tel);
            }
            Console.Read();
        }
    }
}
