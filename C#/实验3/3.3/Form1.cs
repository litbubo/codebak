using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _3._3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void 颜色ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (richTextBox1.SelectedText != "")
            {
                colorDialog1.ShowDialog();
                richTextBox1.SelectionColor = colorDialog1.Color;
            }
        }

        private void 字体ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (richTextBox1.SelectedText != "")
            {
                fontDialog1.ShowDialog();
                richTextBox1.SelectionFont = fontDialog1.Font;
            }
        }
    }
}
