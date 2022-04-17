<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="_5._3.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
    <style type="text/css">
        .auto-style1 {
            width: 95%;
            height: 490px;
        }
        .auto-style2 {
            height: 24px;
        }
        .auto-style5 {
            width: 18px;
        }
        .auto-style6 {
            width: 28px;
        }
        .auto-style7 {
            width: 100%;
        }
        .auto-style8 {
            height: 21px;
        }
        .auto-style9 {
            width: 280px;
            height: 543px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server" class="auto-style9">
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <table class="auto-style1">
            <tr>
                <td class="auto-style2" colspan="2" style="background-color: #FFFF00; border-style: none">
        <asp:RadioButtonList ID="RadioButtonList1" runat="server" Height="44px" Width="115px">
            <asp:ListItem Selected="True">男</asp:ListItem>
            <asp:ListItem>女</asp:ListItem>
        </asp:RadioButtonList>
                </td>
            </tr>
            <tr>
                <td class="auto-style6" style="background-color: #FFFF00; border-style: none">
        <asp:RadioButtonList ID="RadioButtonList2" runat="server" Height="165px" Width="99px">
            <asp:ListItem Selected="True">小于18</asp:ListItem>
            <asp:ListItem>18-22</asp:ListItem>
            <asp:ListItem>大于22</asp:ListItem>
        </asp:RadioButtonList>
                </td>
                <td class="auto-style5" style="background-color: #FFFF00; border-style: none">
        <asp:CheckBoxList ID="CheckBoxList1" runat="server" Height="238px" Width="99px">
            <asp:ListItem>看书</asp:ListItem>
            <asp:ListItem>足球</asp:ListItem>
            <asp:ListItem>游泳</asp:ListItem>
            <asp:ListItem>武术</asp:ListItem>
        </asp:CheckBoxList>
                </td>
            </tr>
            <tr>
                <td colspan="2" style="background-color: #FFFF00; border-style: none">
        <asp:CheckBox ID="CheckBox1" runat="server" Text="是否三好学生" />
                </td>
            </tr>
            <tr>
                <td colspan="2" style="background-color: #FFFF00; border-style: none">
            <asp:Button ID="Button1" runat="server" ForeColor="Red" Text="提交" OnClick="Button1_Click1" />
                </td>
            </tr>
            <tr>
                <td colspan="2" style="background-color: #FFFF00; border-style: none">
                    <table class="auto-style7">
                        <tr>
                            <td class="auto-style8">
                                <asp:Label ID="Label1" runat="server" Text="你的选择："></asp:Label>
                            </td>
                        </tr>
                        <tr>
                            <td>
                                <asp:Label ID="Label2" runat="server" Text="&amp;nbsp&amp;nbsp性别："></asp:Label>
                            </td>
                        </tr>
                        <tr>
                            <td>
                                <asp:Label ID="Label3" runat="server" Text="&amp;nbsp&amp;nbsp年龄："></asp:Label>
                            </td>
                        </tr>
                        <tr>
                            <td>
                                <asp:Label ID="Label4" runat="server" Text="&amp;nbsp&amp;nbsp爱好："></asp:Label>
                            </td>
                        </tr>
                        <tr>
                            <td>
                                <asp:Label ID="Label5" runat="server" Text="&amp;nbsp&amp;nbsp"></asp:Label>
                            </td>
                        </tr>
                    </table>
                </td>
            </tr>
        </table>
    </form>
</body>
</html>
