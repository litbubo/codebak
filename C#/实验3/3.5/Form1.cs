using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _3._5
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string path = @"D:\myfile.txt";
            if (!File.Exists(path)) //不存在该文件时
                richTextBox1.Text = "指定的文件不存在";
            else
            {
                /*
                FileStream f = File.OpenWrite(path);
                BinaryWriter sw = new BinaryWriter(f, Encoding.Unicode);
                sw.Write("王源");
                sw.Write(99.9);
                sw.Write("李白");
                sw.Write(90.5);
                sw.Write("杜甫");
                sw.Write(66.6);
                sw.Write("张飞");
                sw.Write(85.3);
                sw.Close();
                f.Close();
                */
                FileStream f = File.OpenRead(path); //注释1：打开指定路径上的文件流
                BinaryReader sb = new BinaryReader(f, Encoding.Unicode); //注释2：实例化BinaryReader类对象sb
                string mystr = "";
                string name = "";
                Double score = 0;
                Double i;
                Double s = 0;
                for (i = 0; i < 4; i++)
                {
                    name = sb.ReadString();  //注释3：读取姓名数据
                    score = sb.ReadDouble();  //注释4：读取分数数据
                    s = s + score;
                    mystr = mystr + string.Format("{0}\t{1}\r\n", name, score);
                }
                richTextBox1.Text = mystr;
                textBox1.Text = string.Format("{0}", s / 4);
                sb.Close();
                f.Close();
            }
        }
    }
}
