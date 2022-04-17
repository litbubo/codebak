using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _3._6
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int[] numbers = new int[10] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            var numQuery =
                from num in numbers
                where (num % 2) == 0
                select num;
            var numQuery2 =
                from num in numbers
                where (num % 2) != 0
                select num;
            foreach (int num in numQuery)
            {
                richTextBox1.Text += num.ToString() + "   ";
            }
            richTextBox1.Text += "\n\n";
            foreach (int num in numQuery2)
            {
                richTextBox1.Text += num.ToString() + "   ";
            }
        }
    }
}
