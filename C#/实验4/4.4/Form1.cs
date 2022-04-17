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

namespace _4._4
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            string mystr;
            //实例化SqlConnection对象myconn
            SqlConnection myconn = new SqlConnection();
            mystr = "Data Source=(local);";
            mystr += "Initial Catalog=School;";
            mystr += "uid=sa;";
            mystr += "pwd=3336;";
            myconn.ConnectionString = mystr;
            //打开myconn连接
            myconn.Open();
            //注释1：实例化SqlDataAdapter数据适配器对象myda，查询score表信息
            SqlDataAdapter myda = new SqlDataAdapter("SELECT * FROM SC",mystr);
            //注释2：实例化DataSet数据集对象myds
            DataSet myds = new DataSet();
            //注释3：用myda填充myds中的score表
            myda.Fill(myds, "score");
            //注释4：实例化BindingSource对象mybs，数据源为myds的"score"表
            BindingSource mybs = new BindingSource(myds, "score");
            Binding mybinding1 = new Binding("Text", mybs, "Sno");
            textBox1.DataBindings.Add(mybinding1);
            Binding mybinding2 = new Binding("Text", mybs, "Cname");
            textBox2.DataBindings.Add(mybinding2);
            Binding mybinding3 = new Binding("Text", mybs, "Grade");
            textBox3.DataBindings.Add(mybinding3);
            bindingNavigator1.Dock = DockStyle.Bottom;
            //注释5：设置控件bindingNavigator1的绑定源
            bindingNavigator1.BindingSource = mybs;
            myconn.Close();

        }
    }
}
