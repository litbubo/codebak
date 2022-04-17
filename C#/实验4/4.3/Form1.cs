using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _4._3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        //注释1：实例化BindingSource对象mybs
        BindingSource mybs = new BindingSource();

        private void Form1_Load(object sender, EventArgs e)
        {
            string mystr, mysql;
            //实例化SqlConnection对象myconn
            SqlConnection myconn = new SqlConnection();
            mystr = "Data Source=(local);";
            mystr += "Initial Catalog=School;";
            mystr += "uid=sa;";
            mystr += "pwd=3336;";
            myconn.ConnectionString = mystr;
            //打开myconn连接
            myconn.Open();
            mysql = "SELECT * FROM SC";
            //注释2：实例化SqlDataAdapter对象myda
            SqlDataAdapter myda = new SqlDataAdapter(mysql, myconn);
            //注释3：实例化DataSet对象myds
            DataSet myds = new DataSet();
            //注释4：用myda填充数据集myds中的score表
            myda.Fill(myds, "score");
            //注释5：实例化mybs为数据集myds中的score表
            mybs = new BindingSource(myds, "score");
            //注释6：将score.学号与textBox1文本框绑定起来
            Binding mybinding1 = new Binding("Text", mybs, "Sno");
            textBox1.DataBindings.Add(mybinding1);
            //注释7：将score.课程名与textBox2文本框绑定起来
            Binding mybinding2 = new Binding("Text", mybs, "Cname");
            textBox2.DataBindings.Add(mybinding2);
            //注释8：将score.分数与textBox3文本框绑定起来
            Binding mybinding3 = new Binding("Text", mybs, "Grade");
            textBox3.DataBindings.Add(mybinding3);
            myconn.Close();

        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (mybs.Position != 0) //注释9：游标未指向第一个记录
                mybs.MoveFirst();  //注释10：移到第一个记录

        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (mybs.Position != 0)   //注释11：游标未指向第一个记录
                mybs.MovePrevious();　//注释12：移到上一个记录

        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (mybs.Position != mybs.Count - 1)  //注释13：游标未指向最后一个记录
                mybs.MoveNext();　//注释14：移到下一个记录

        }

        private void button4_Click(object sender, EventArgs e)
        {
            if (mybs.Position != mybs.Count - 1) //注释15：游标未指向最后一个记录
                mybs.MoveLast();　//注释16：移到最后一个记录

        }
    }
}
