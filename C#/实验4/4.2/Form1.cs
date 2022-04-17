using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.OleDb;
using System.Data.SqlClient;

namespace _4._2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string mystr, mysql;
            //注释1：实例化SqlConnection对象myconn
            SqlConnection myconn = new SqlConnection();
            mystr = "Data Source=(local);";
            mystr += "Initial Catalog=School;";
            mystr += "uid=sa;";
            mystr += "pwd=3336;";
            myconn.ConnectionString = mystr;
            //注释2：打开myconn连接
            myconn.Open();
            //注释3：实例化SqlCommand对象mycmd
            SqlCommand mycmd = new SqlCommand();
            //注释4：定义SQL语句mysql，查询所有学生的学号、姓名、选修的课程名、分数
            mysql = "SELECT * FROM Student";
            mycmd.CommandText = mysql;
            mycmd.Connection = myconn;
            //注释5：执行mycmd对象的SQL语句，赋值给myreader对象
            SqlDataReader myreader = mycmd.ExecuteReader();
            listBox1.Items.Add("学号\t姓名\t\t课程名\t\t分数");
            listBox1.Items.Add("====================================");
            //注释6：在列表框listBox1中显示查询结果
            while (myreader.Read())
                listBox1.Items.Add(String.Format("{0}\t{1}\t{2}\t{3}\t{4}", myreader[0].ToString(), myreader[1].ToString(), myreader[2].ToString(), myreader.GetString(3), myreader.GetString(4)));
            //注释7：关闭myconn连接
            myconn.Close();

        }
    }
}
