#include "stdafx.h"
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	int i, count;
	ofstream outfile;
	outfile.open("..\\..\\T1.html");
	cout << "请输入您需要的行数：" << endl;
	cin >> count;
	outfile << "<!DOCTYPE html>" << endl << "<html>" << endl << "<head>" << endl;
	//outfile << "<meta charset = \"UTF-8\">" << endl;
	outfile << "<title>我的Html作业3</title>" << endl;
	outfile << "<style>" << endl;
	outfile << "table.dataintable tr:nth-child(odd)" << endl;
	outfile << "{background-color:#00FF7F;}" << endl;
	outfile << "table.dataintable tr:nth-child(even)" << endl;
	outfile << "{background - color:#40E0D0;}" << endl;
	outfile << "</style>" << endl << "</head>" << endl << "<body>" << endl;
	outfile << "<table class = \"dataintable\" width = \"1200\" height = \"60\" border = \"2\" frame = \"vsides\" rules = \"none\">" << endl;
	for (i = 0; i < count; i++)
	{
		outfile << "<tr>" << endl;
		outfile << "<td align = \"left\"><a href = \""<< i%10 <<".mp3\">" << i+1 << ".北大儿童英语"<< i+1 <<"</a></td>" << endl;
		outfile << "<td align = \"center\" valign = \"middle\"><img src = \"music.png\" width = 25></td>" << endl;
		outfile << "<td align = \"center\" valign = \"middle\"><img src = \"message.png\" width = 25></td>" << endl;
		outfile << "<td align = \"center\" valign = \"middle\"><img src = \"download.png\" width = 25></td>" << endl;
		outfile << "</tr>" << endl;
	}
	outfile << "</table>" << endl << "</body>" << endl << "</html>" << endl;
	outfile.close();
	cout << "网页创建成功！！" << endl;
	system ("pause");
	return 0;
}