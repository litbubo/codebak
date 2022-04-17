using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Collections;

namespace _1._4_Win
{
    public partial class Form1 : Form
    {
        ArrayList tellist = new ArrayList();
        struct telephonebook
        {
            public String name;
            public int tel;
        }
        public Form1()
        {
            InitializeComponent();
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            
            telephonebook temp;
            temp.name = textBox1.Text;
            temp.tel = Int32.Parse(textBox2.Text);
            tellist.Add(temp);
            label5.Text = "添加成功！";

        }
            

        private void button2_Click(object sender, EventArgs e)
        {
            string search = textBox3.Text;
            string temp = "查询到的号码为：";
            foreach (telephonebook t in tellist)
            {
                if (search == t.name)
                    label5.Text = temp + t.tel.ToString();
            }
            //label5.Text = temp;
        }
        
    }
}
