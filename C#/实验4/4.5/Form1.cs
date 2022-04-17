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

namespace _4._5
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: 这行代码将数据加载到表“schoolDataSet1.SC”中。您可以根据需要移动或删除它。
            this.sCTableAdapter.Fill(this.schoolDataSet1.SC);
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
            //注释1：定义Sql语句，查询score表的全部行
            mysql = "SELECT * FROM SC";
            //注释2：实例化SqlDataAdapter数据适配器对象myda，查询score表信息
            SqlDataAdapter myda = new SqlDataAdapter(mysql, myconn);
            //注释3：实例化DataSet数据集对象myds
            DataSet myds = new DataSet();
            //注释4：用myda填充myds中的score表
            myda.Fill(myds, "score");
            //注释5：设置dataGridView1对象的数据源为myds的"score"表
            dataGridView1.DataSource = myds.Tables["score"];
            dataGridView1.GridColor = Color.RoyalBlue;
            dataGridView1.ScrollBars = ScrollBars.Vertical;
            dataGridView1.CellBorderStyle =
               DataGridViewCellBorderStyle.Single;
            dataGridView1.Columns[0].AutoSizeMode =
               DataGridViewAutoSizeColumnMode.AllCells;
            dataGridView1.Columns[1].AutoSizeMode =
               DataGridViewAutoSizeColumnMode.AllCells;
            dataGridView1.Columns[2].AutoSizeMode =
            DataGridViewAutoSizeColumnMode.AllCells;
            myconn.Close();
        }
    }
}
