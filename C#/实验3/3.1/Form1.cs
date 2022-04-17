using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _3._1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void 红ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.BackColor = Color.Red;
            this.ForeColor = Color.Red;
        }

        private void 绿ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.BackColor = Color.Green;
            this.ForeColor = Color.Green;
        }

        private void 蓝ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.BackColor = Color.Blue;
            this.ForeColor = Color.Blue;
        }

        private void 还原ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.BackColor = Control.DefaultBackColor;
            this.ForeColor = Control.DefaultForeColor;
        }
    }
}
