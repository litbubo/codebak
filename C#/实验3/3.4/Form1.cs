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
    public partial class Form1 : Form
    {
        public student mystu = new student();
        public Form1()
        {
            InitializeComponent();
        }

        internal student Mystu { get => mystu; set => mystu = value; }

        private void 添加ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form2 newDialog = new Form2(this);
            newDialog.ShowDialog();
            listBox1.Items.Add("    姓名：" + mystu.name + "   年龄：" + mystu.age + "    性别：" + mystu.sex);
        }
    }
}
