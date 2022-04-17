using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _3._2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            toolStripStatusLabel1.Text = "时间：" + DateTime.Now.ToString("h:mm:ss");
        }

        private void Form1_Load_1(object sender, EventArgs e)
        {
            toolStripStatusLabel1.Text = "时间：" + DateTime.Now.ToString("h:mm:ss");
            timer1.Enabled = true;
        }

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            toolStripStatusLabel2.Text = "     X = " + e.X.ToString() + "     Y = " + e.Y;
        }
    }
}
