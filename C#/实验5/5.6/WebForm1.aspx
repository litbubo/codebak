<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="_5._6.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
    <style type="text/css">
        .auto-style1 {
            width: 553px;
            height: 727px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
        <div class="auto-style1">
            <asp:GridView ID="GridView1" runat="server" AllowPaging="True" AllowSorting="True" AutoGenerateColumns="False" BackColor="#DEBA84" BorderColor="#DEBA84" BorderStyle="None" BorderWidth="1px" CellPadding="3" CellSpacing="2" DataKeyNames="Sno" DataSourceID="SqlDataSource1">
                <Columns>
                    <asp:CommandField ButtonType="Button" ShowDeleteButton="True" ShowEditButton="True" />
                    <asp:BoundField DataField="Sno" HeaderText="Sno" ReadOnly="True" SortExpression="Sno" />
                    <asp:BoundField DataField="Sname" HeaderText="Sname" SortExpression="Sname" />
                    <asp:BoundField DataField="Ssex" HeaderText="Ssex" SortExpression="Ssex" />
                    <asp:BoundField DataField="Snation" HeaderText="Snation" SortExpression="Snation" />
                    <asp:BoundField DataField="Sclass" HeaderText="Sclass" SortExpression="Sclass" />
                </Columns>
                <FooterStyle BackColor="#F7DFB5" ForeColor="#8C4510" />
                <HeaderStyle BackColor="#A55129" Font-Bold="True" ForeColor="White" />
                <PagerStyle ForeColor="#8C4510" HorizontalAlign="Center" />
                <RowStyle BackColor="#FFF7E7" ForeColor="#8C4510" />
                <SelectedRowStyle BackColor="#738A9C" Font-Bold="True" ForeColor="White" />
                <SortedAscendingCellStyle BackColor="#FFF1D4" />
                <SortedAscendingHeaderStyle BackColor="#B95C30" />
                <SortedDescendingCellStyle BackColor="#F1E5CE" />
                <SortedDescendingHeaderStyle BackColor="#93451F" />
            </asp:GridView>
            <asp:DetailsView ID="DetailsView1" runat="server" AutoGenerateRows="False" BackColor="White" BorderColor="#E7E7FF" BorderStyle="None" BorderWidth="1px" CellPadding="3" DataKeyNames="Sno" DataSourceID="SqlDataSource1" GridLines="Horizontal" Height="50px" Width="125px">
                <AlternatingRowStyle BackColor="#F7F7F7" />
                <EditRowStyle BackColor="#738A9C" Font-Bold="True" ForeColor="#F7F7F7" />
                <Fields>
                    <asp:BoundField DataField="Sno" HeaderText="Sno" ReadOnly="True" SortExpression="Sno" />
                    <asp:BoundField DataField="Sname" HeaderText="Sname" SortExpression="Sname" />
                    <asp:BoundField DataField="Ssex" HeaderText="Ssex" SortExpression="Ssex" />
                    <asp:BoundField DataField="Snation" HeaderText="Snation" SortExpression="Snation" />
                    <asp:BoundField DataField="Sclass" HeaderText="Sclass" SortExpression="Sclass" />
                    <asp:CommandField ButtonType="Button" ShowInsertButton="True" />
                </Fields>
                <FooterStyle BackColor="#B5C7DE" ForeColor="#4A3C8C" />
                <HeaderStyle BackColor="#4A3C8C" Font-Bold="True" ForeColor="#F7F7F7" />
                <PagerStyle BackColor="#E7E7FF" ForeColor="#4A3C8C" HorizontalAlign="Right" />
                <RowStyle BackColor="#E7E7FF" ForeColor="#4A3C8C" />
            </asp:DetailsView>
            <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:SchoolConnectionString %>" DeleteCommand="DELETE FROM [Student] WHERE [Sno] = @Sno" InsertCommand="INSERT INTO [Student] ([Sno], [Sname], [Ssex], [Snation], [Sclass]) VALUES (@Sno, @Sname, @Ssex, @Snation, @Sclass)" SelectCommand="SELECT [Sno], [Sname], [Ssex], [Snation], [Sclass] FROM [Student]" UpdateCommand="UPDATE [Student] SET [Sname] = @Sname, [Ssex] = @Ssex, [Snation] = @Snation, [Sclass] = @Sclass WHERE [Sno] = @Sno">
                <DeleteParameters>
                    <asp:Parameter Name="Sno" Type="String" />
                </DeleteParameters>
                <InsertParameters>
                    <asp:Parameter Name="Sno" Type="String" />
                    <asp:Parameter Name="Sname" Type="String" />
                    <asp:Parameter Name="Ssex" Type="String" />
                    <asp:Parameter Name="Snation" Type="String" />
                    <asp:Parameter Name="Sclass" Type="String" />
                </InsertParameters>
                <UpdateParameters>
                    <asp:Parameter Name="Sname" Type="String" />
                    <asp:Parameter Name="Ssex" Type="String" />
                    <asp:Parameter Name="Snation" Type="String" />
                    <asp:Parameter Name="Sclass" Type="String" />
                    <asp:Parameter Name="Sno" Type="String" />
                </UpdateParameters>
            </asp:SqlDataSource>
        </div>
    </form>
</body>
</html>
