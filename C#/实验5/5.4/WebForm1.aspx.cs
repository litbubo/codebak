using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace _5._4
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            if (Page.IsValid)
            {
                Label1.Text = "姓名为：";
                Label1.Text += TextBox1.Text + " ";
                Label1.Text += "密码为：" + TextBox2.Text + " ";
                Label1.Text += "邮箱为：" + TextBox4.Text;
            }
        }
    }
}