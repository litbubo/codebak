
namespace _3._1
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.点击更换窗体颜色ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.红ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.绿ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.蓝ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.还原ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.点击更换窗体颜色ToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(800, 28);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // 点击更换窗体颜色ToolStripMenuItem
            // 
            this.点击更换窗体颜色ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.红ToolStripMenuItem,
            this.绿ToolStripMenuItem,
            this.蓝ToolStripMenuItem,
            this.toolStripSeparator1,
            this.还原ToolStripMenuItem});
            this.点击更换窗体颜色ToolStripMenuItem.Name = "点击更换窗体颜色ToolStripMenuItem";
            this.点击更换窗体颜色ToolStripMenuItem.Size = new System.Drawing.Size(143, 24);
            this.点击更换窗体颜色ToolStripMenuItem.Text = "点击更换窗体颜色";
            // 
            // 红ToolStripMenuItem
            // 
            this.红ToolStripMenuItem.Name = "红ToolStripMenuItem";
            this.红ToolStripMenuItem.Size = new System.Drawing.Size(224, 26);
            this.红ToolStripMenuItem.Text = "红";
            this.红ToolStripMenuItem.Click += new System.EventHandler(this.红ToolStripMenuItem_Click);
            // 
            // 绿ToolStripMenuItem
            // 
            this.绿ToolStripMenuItem.Name = "绿ToolStripMenuItem";
            this.绿ToolStripMenuItem.Size = new System.Drawing.Size(224, 26);
            this.绿ToolStripMenuItem.Text = "绿";
            this.绿ToolStripMenuItem.Click += new System.EventHandler(this.绿ToolStripMenuItem_Click);
            // 
            // 蓝ToolStripMenuItem
            // 
            this.蓝ToolStripMenuItem.Name = "蓝ToolStripMenuItem";
            this.蓝ToolStripMenuItem.Size = new System.Drawing.Size(224, 26);
            this.蓝ToolStripMenuItem.Text = "蓝";
            this.蓝ToolStripMenuItem.Click += new System.EventHandler(this.蓝ToolStripMenuItem_Click);
            // 
            // 还原ToolStripMenuItem
            // 
            this.还原ToolStripMenuItem.Name = "还原ToolStripMenuItem";
            this.还原ToolStripMenuItem.Size = new System.Drawing.Size(224, 26);
            this.还原ToolStripMenuItem.Text = "还原";
            this.还原ToolStripMenuItem.Click += new System.EventHandler(this.还原ToolStripMenuItem_Click);
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(221, 6);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Text = "Form1";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem 点击更换窗体颜色ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 红ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 绿ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 蓝ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 还原ToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
    }
}

