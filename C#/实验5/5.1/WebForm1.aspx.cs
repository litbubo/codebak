using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;

namespace _5._1
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            SqlConnection oConn = new SqlConnection(); ;
            string strConn;
            strConn = "Data Source=(local);";
            strConn += "Initial Catalog=" + TextBox1.Text + ";";
            strConn += "uid=sa;";
            strConn += "pwd=3336;";
            oConn.ConnectionString = strConn;
            try
            {
                oConn.Open();
            }
            catch (Exception err)
            {
                Label2.Text = err.Message;
            }
            finally
            {
                if (oConn.State == System.Data.ConnectionState.Open)
                    Label2.Text = "成功连接到SQL Server数据库";
                else
                    Label2.Text = "不能连接到SQL Server数据库";
                oConn.Close();
            }

        }
    }
}