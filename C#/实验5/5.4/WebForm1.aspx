<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="_5._4.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
    <style type="text/css">
        .auto-style1 {
            width: 89%;
            height: 139px;
            margin-right: 263px;
        }
        .auto-style9 {
            height: 23px;
        }
        .auto-style10 {
            height: 24px;
        }
        .auto-style12 {
            height: 23px;
            width: 100px;
        }
        .auto-style13 {
            height: 24px;
            width: 100px;
        }
        .auto-style26 {
            width: 100px;
        }
        .auto-style27 {
            width: 77px;
        }
        .auto-style28 {
            height: 23px;
            width: 77px;
        }
        .auto-style29 {
            height: 24px;
            width: 77px;
        }
        .auto-style30 {
            width: 553px;
            height: 205px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server" class="auto-style30">
        <table class="auto-style1">
            <tr>
                <td aria-autocomplete="none" aria-busy="False" class="auto-style27">&nbsp;</td>
                <td aria-autocomplete="none" aria-busy="False" class="auto-style26">用户登录</td>
                <td>&nbsp;</td>
            </tr>
            <tr>
                <td class="auto-style28" style="color: #0000FF; font-size: small; font-weight: bold;">姓名</td>
                <td class="auto-style12">
                    <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
                </td>
                <td class="auto-style9">
                    <asp:RequiredFieldValidator ID="RequiredFieldValidator1" runat="server" ControlToValidate="TextBox1" ErrorMessage="姓名必须填写"></asp:RequiredFieldValidator>
                </td>
            </tr>
            <tr>
                <td class="auto-style29" style="color: #0000FF; font-size: small; font-weight: bold;">密码</td>
                <td class="auto-style13">
                    <asp:TextBox ID="TextBox2" runat="server" TextMode="Password"></asp:TextBox>
                </td>
                <td class="auto-style10">
                    <asp:RequiredFieldValidator ID="RequiredFieldValidator2" runat="server" ControlToValidate="TextBox2" ErrorMessage="密码必须填写"></asp:RequiredFieldValidator>
                </td>
            </tr>
            <tr>
                <td class="auto-style27" style="color: #0000FF; font-size: small; font-weight: bold;">密码确认</td>
                <td class="auto-style26">
                    <asp:TextBox ID="TextBox3" runat="server" TextMode="Password"></asp:TextBox>
                </td>
                <td>
                    <asp:CompareValidator ID="CompareValidator1" runat="server" ControlToCompare="TextBox2" ControlToValidate="TextBox3" ErrorMessage="两次密码不一致"></asp:CompareValidator>
                </td>
            </tr>
            <tr>
                <td class="auto-style27" style="color: #0000FF; font-size: small; font-weight: bold;">邮箱</td>
                <td class="auto-style26">
                    <asp:TextBox ID="TextBox4" runat="server"></asp:TextBox>
                </td>
                <td>
                    <asp:RegularExpressionValidator ID="RegularExpressionValidator1" runat="server" ControlToValidate="TextBox4" ErrorMessage="邮箱格式错误" ValidationExpression="\w+([-+.']\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*"></asp:RegularExpressionValidator>
                </td>
            </tr>
            <tr>
                <td class="auto-style27">&nbsp;</td>
                <td class="auto-style26">
                    <asp:Button ID="Button1" runat="server" ForeColor="Red" OnClick="Button1_Click" style="height: 27px" Text="提交" />
                </td>
                <td>&nbsp;</td>
            </tr>
            <tr>
                <td colspan="3">
                    <asp:Label ID="Label1" runat="server" Text="Label"></asp:Label>
                </td>
            </tr>
        </table>
    </form>
</body>
</html>
