using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _2._1
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
            Point p1, p2;
            p1 = new Point(Convert.ToInt32(textBox1.Text), Convert.ToInt32(textBox2.Text));
            p2 = new Point(Convert.ToInt32(textBox3.Text), Convert.ToInt32(textBox4.Text));
            //p1 = new Point(1, 2);
            //p2 = new Point(3, 4);
            double distance = p1.DistanceP(p2);
            textBox5.Text = distance.ToString();
        }
    }

    public class Point
    {
        private int x;
        private int y;
        public Point(int x, int y)
        {
            this.x = x;
            this.y = y;
        }
        public int X
        {
            get { return x; }
            set { x = value; }
        }
        public int Y
        {
            get { return y; }
            set { y = value; }
        }

        public double DistanceP(Point P)
        {
            return System.Math.Sqrt((x - P.X) * (x - P.X) + (y - P.Y) * (y - P.Y));
        }

    }
}
