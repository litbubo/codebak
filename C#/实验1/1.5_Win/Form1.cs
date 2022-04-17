using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1._5_Win
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            int num = Int32.Parse(textBox1.Text);
            int sum = 0;
            int temp = 1;
            //num = Int32.Parse(Console.ReadLine());
            for (int i = 1; i <= num; ++i)
            {
                temp *= i;
                sum += temp;
            }
            textBox2.Text = sum.ToString();
            //Console.WriteLine("1!+2!+3!+...+{0}! = {1}", num, sum);
            //Console.Read();
        }
    }
}
