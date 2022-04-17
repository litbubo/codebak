<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="_5._5.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
    <style type="text/css">
        .auto-style1 {
            width: 412px;
            height: 417px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
        <div class="auto-style1">
            <asp:LinkButton ID="LinkButton1" runat="server" PostBackUrl="~/WebForm2.aspx">转向WebForm2</asp:LinkButton>
            <br />
            <asp:ImageButton ID="ImageButton1" runat="server" Height="84px" ImageUrl="~/Snipaste_2021-11-07_22-40-12.png" PostBackUrl="~/WebForm3.aspx" Width="310px" />
            <br />
            <br />
            <asp:HyperLink ID="HyperLink1" runat="server" NavigateUrl="~/WebForm4.aspx">转向WebForm4</asp:HyperLink>
            <br />
            <br />
            <br />
            <br />
            <br />
            <br />
            <br />
            <br />
            <br />
            <br />
            <br />
            <br />
            <br />
            <br />
        </div>
    </form>
</body>
</html>
