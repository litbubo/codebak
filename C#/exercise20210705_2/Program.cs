using System;
/*
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
*/

namespace exercise20210705_2
{

    class Rectangel
    {

        double length;
        double width;
        public void Acceptdetails()
        {
            length = 4.5;
            width = 3.5;
        }

        public double GetArea()
        {
            return length * width;
        }
        public void Display()
        {
            Console.WriteLine("{0}{1}", length, GetArea());
        }
    }

    class NumSwap
    {
        public void Swap(ref int x, ref int y)
        {
            int temp;
            temp = x;
            x = y;
            y = temp;
        }

        public void Change(out int x)
        {
            x = 12;
        }
    }
    class Program
    {
        void Print()
        {
            Console.WriteLine(6);
        }
        static void Main(string[] args)
        {
            Console.WriteLine("666");
            Rectangel r = new Rectangel();
            r.Acceptdetails();
            r.GetArea();
            r.Display();
            Console.ReadKey();

            int i = 0;
            double d = 5379.336;

            //i = (int)d;

            //i = d;

            Console.WriteLine(i);
            if (i < d)
            {
                Console.WriteLine("大于");
            }
            int judge = 0;

            judge = i < d ? 1 : 0;

            if (judge == 1)
            {
                Console.WriteLine("dayu");
            }



            int[] array = new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

            foreach (int temp in array)
                Console.WriteLine(temp);

            char[] array2 = new char[] { 'a', 'b', 'c', 'd', 'e', 'f', 'g'};

            foreach (char temp in array2)
                Console.WriteLine(temp);

            /*Console.WriteLine(temp);*/

            NumSwap n = new NumSwap();
            int a = 5;
            int b = 10;
            int x;
            n.Swap(ref a, ref b);
            n.Change(out x);
            Console.WriteLine("{0},{1},{2}",a,b,x);
            Console.ReadKey();
        }
    }
}
