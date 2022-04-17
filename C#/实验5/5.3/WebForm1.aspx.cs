using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace _5._3
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void Button1_Click1(object sender, EventArgs e)
        {
            if (RadioButtonList1.SelectedItem != null)
            {
                Label2.Text = "&nbsp&nbsp性别：";
                Label2.Text += RadioButtonList1.SelectedItem.Text;
            }
            if (RadioButtonList2.SelectedItem != null)
            {
                Label3.Text = "&nbsp&nbsp年龄：";
                Label3.Text += RadioButtonList2.SelectedItem.Text;
            }
            if (CheckBoxList1.SelectedIndex > -1)
            {
                Label4.Text = "&nbsp&nbsp爱好：";
                for (int i = 0; i <= CheckBoxList1.Items.Count - 1; i++)
                {
                    if (CheckBoxList1.Items[i].Selected)
                    {
                        Label4.Text += CheckBoxList1.Items[i].Text + "&nbsp";
                    }
                }
            }
            if (CheckBox1.Checked)
            {
                Label5.Text = "&nbsp&nbsp该生是三好学生！";
            }
            else
            {
                Label5.Text = "&nbsp&nbsp该生不是三好学生！";
            }
        }
    }
}