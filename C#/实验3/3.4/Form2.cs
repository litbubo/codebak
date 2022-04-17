using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
namespace _3._4
{
    public partial class Form2 : Form
    {
        private Form1 myform;
        public Form2(Form1 myform)
        {
            this.myform = myform;
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            myform.Mystu.name = textBox1.Text;
            myform.Mystu.age = textBox2.Text;
            myform.Mystu.sex = textBox3.Text;
            this.Close();
        }
    }
}
