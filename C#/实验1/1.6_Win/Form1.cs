using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1._6_Win
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
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

            textBox1.Text = sum.ToString();
            //Console.WriteLine("结果为：{0}", sum);
            //Console.Read();
        }
    }
}
