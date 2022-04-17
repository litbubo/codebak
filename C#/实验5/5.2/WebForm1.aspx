<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="_5._2.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
    <style type="text/css">
        .auto-style1 {
            width: 280px;
            height: 262px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server" class="auto-style1">
        <div>
        </div>
        <asp:Label ID="Label1" runat="server" Text="姓名："></asp:Label>
        <asp:DropDownList ID="DropDownList1" runat="server" DataSourceID="SqlDataSource1" DataTextField="Sname" DataValueField="Sname">
        </asp:DropDownList>
        <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:SchoolConnectionString %>" SelectCommand="SELECT [Sname] FROM [Student]"></asp:SqlDataSource>
        <p>
            <asp:Label ID="Label2" runat="server" Text="班号："></asp:Label>
            <asp:DropDownList ID="DropDownList2" runat="server" DataSourceID="SqlDataSource2" DataTextField="Sclass" DataValueField="Sclass">
            </asp:DropDownList>
            <asp:SqlDataSource ID="SqlDataSource2" runat="server" ConnectionString="<%$ ConnectionStrings:SchoolConnectionString %>" SelectCommand="SELECT [Sclass] FROM [Student]"></asp:SqlDataSource>
        </p>
        <asp:Label ID="Label3" runat="server" Text="Label"></asp:Label>
        <p>
            <asp:Button ID="Button1" runat="server" ForeColor="Red" OnClick="Button1_Click" Text="提交" />
        </p>
    </form>
</body>
</html>
