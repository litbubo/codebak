using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

namespace exercise20210826_2
{
    
    class Program
    {
        enum Xlp { b = 1, c = 2, d = 3, e = 4 };
        static void Main(string[] args)
        {
            /*
            string str;
            str = Console.ReadLine();

            bool a = str.Equals("a");
            Console.WriteLine(a.ToString());
            int b = str.Length;
            Console.WriteLine(b.ToString());
            */
            /*
            int a = 5, b = 10, c = 15, MAX = 0;
            MAX = a > b ? a : b;
            MAX = c < MAX ? c : MAX;
            Console.WriteLine(MAX.ToString());
            */
            int a = 5, b = 5, c = 6, d;
            Console.WriteLine("{0}", d = a > b ? (a > c ? a : c) : b);


            for (int i = 0; i<10; i++)
            {

                Console.WriteLine(i);
                if (i == 5)
                    break;
            }

            int[] arraya = new int[5] { 1, 2, 3, 4, 5 };
            int[] arrayb = new int[] { 1, 2, 3, 4, 5 };
            int[] arrayc = { 1, 2, 3, 4 ,5};
            int[,] arrayd = new int[4,5];
            arrayd[2, 3] = 789456;
            Console.WriteLine(arrayd[2, 3]);
            for (int i = 0; i < 5; i++)
            {

                Console.WriteLine(arraya[i]);
                Console.WriteLine(arrayb[i]);
                Console.WriteLine(arrayc[i]);

            }
            Console.WriteLine();

            int[] num = new int[] { 1, 2, 3 };

            ArrayList array = new ArrayList();

            array.Add(num[0]);
            array.Add(num[1]);
            array.Add(num[2]);
            array.Insert(1, 10);
            for(int i = 0; i<4; i++)
            {
                Console.WriteLine(array[i]);
            }

            ArrayList array2 = new ArrayList();
            array2.Add(num);



            /*
            int i = Console.Read();'htssaa
            int y = Console.Read();
            int z = Console.Read();
            int j = Console.Read();
            Console.WriteLine("{0},{1},{2},{3}", i, y, z, j);*/
            //Console.WriteLine("x = {0}", Console.ReadLine());
            //Console.Write("1");
            //Console.ReadLine();
            Console.ReadKey();
        }
    }
}
