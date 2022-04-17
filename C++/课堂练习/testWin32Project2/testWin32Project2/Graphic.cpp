#include "StdAfx.h"
#include "Graphic.h"

Graphic::Graphic(HDC hdc)
{
	m_hDC = hdc;

	m_hpenOld = NULL;
	//��ǰ����
	m_hpenCur = NULL;
	//�ɵĻ�ˢ
	m_hbrOld = NULL;
	//��ǰ��ˢ
	m_hbrCur = NULL;
	//�ɵ�����
	m_hfontOld = NULL;
	//��ǰ����
	m_hfontCur = NULL;
	//
	m_clrText = 0;
}

Graphic::~Graphic(void)
{
	if (m_hpenOld != NULL) ::SelectObject(m_hDC, m_hpenOld);
	if (m_hpenCur != NULL) ::DeleteObject(m_hpenCur);

	if (m_hbrOld != NULL) ::SelectObject(m_hDC, m_hbrOld);
	if (m_hbrCur != NULL) ::DeleteObject(m_hbrCur);

	if (m_hfontOld != NULL) ::SelectObject(m_hDC, m_hfontOld);
	if (m_hfontCur != NULL) ::DeleteObject(m_hfontCur);
}
// ѡ��һ�ֻ���
void Graphic::SelectAPen(HPEN hpen)
{
	HPEN hpold;
	hpold = (HPEN)::SelectObject(m_hDC, hpen);
	if (m_hpenOld == NULL) m_hpenOld = hpold;
	if (m_hpenCur != NULL) ::DeleteObject(m_hpenCur);
	m_hpenCur = hpen;
}
// ���ɲ�ѡ��һ�ֻ���
void Graphic::SelectAPen(int npstyle, int nwidth, COLORREF color)
{
	HPEN hpen = ::CreatePen(npstyle, nwidth, color);
	SelectAPen(hpen);;
}

// ���ɲ�ѡ��һ�ֻ�ˢ
void Graphic::SelectABrush(HBRUSH hbrush)
{
	HBRUSH hbrold;
	hbrold = (HBRUSH)::SelectObject(m_hDC, hbrush);
	if (m_hbrOld == NULL) m_hbrOld = hbrold;
	if (m_hbrCur != NULL) ::DeleteObject(m_hbrCur);
	m_hbrCur = hbrush;
}
// ���ɲ�ѡ��һ�ֻ�ˢ
void Graphic::SelectABrush(COLORREF color)
{
	HBRUSH hbr = ::CreateSolidBrush(color);
	SelectABrush(hbr);;
}
// ���õ�ǰ���ʣ�����һ��ֱ��
void Graphic::DrawLine(int x1, int y1, int x2, int y2)
{
	::MoveToEx(m_hDC, x1, y1, NULL);
	::LineTo(m_hDC, x2, y2);
}
// ����һ������
void Graphic::DrawRect(RECT rect, bool bfill)
{
	if (bfill)
		::Rectangle(m_hDC, rect.left, rect.top, rect.right, rect.bottom);
	else
	{
		::MoveToEx(m_hDC, rect.left, rect.top, NULL);
		::LineTo(m_hDC, rect.right, rect.top);
		::LineTo(m_hDC, rect.right, rect.bottom);
		::LineTo(m_hDC, rect.left, rect.bottom);
		::LineTo(m_hDC, rect.left, rect.top);
	}
}
// ����һ������
void Graphic::DrawRect(int x1, int y1, int wx, int hy, bool bfill)
{
	RECT rc = { x1,y1,x1 + wx,y1 + hy };
	DrawRect(rc, bfill);
}

// ����ɫ���һ������
void Graphic::FillRect(RECT rect, COLORREF color)
{	//����API����ʵ�־������
	HBRUSH hbr = ::CreateSolidBrush(color);
	::FillRect(m_hDC, &rect, hbr);
	::DeleteObject(hbr);
}
// ����ɫ���һ������
void Graphic::FillRect(int x, int y, int wx, int hy, COLORREF color)
{
	RECT rect;
	rect.left = x;
	rect.right = x + wx;
	rect.top = y;
	rect.bottom = y + hy;
	//�������غ���ʵ�־������
	FillRect(rect, color);
}

// ����һ��Բ��
void Graphic::DrawCircle(int x, int y, int radius)
{	//����API��������Բ
	::Ellipse(m_hDC, x - radius, y - radius, x + radius, y + radius);
}
// ����һ������
HFONT Graphic::CreateAFont(TCHAR *sfontname, int nfontsize, bool bbold, bool bitalic)
{
	int nWeight = bbold ? 700 : 400;
	DWORD dwItalic = bitalic ? 1 : 0;
	HFONT  hfont;
	hfont = ::CreateFont(
		-::MulDiv(nfontsize, GetDeviceCaps(m_hDC, LOGPIXELSY), 72),		//����߶�
		0,					//ƽ�������ȣ�Ĭ��Ϊ0
		0,					//������ʾ�ĽǶȣ�Ĭ��Ϊ0
		0,					//������ߵĽǶȣ�Ĭ��Ϊ0
		nWeight,			//����Ĵ�ϸ
		dwItalic,			//б�������Կ��أ�����ѡ��1��0��Ĭ��Ϊ0
		0,					//�»������Կ��أ�����ѡ��1��0��Ĭ��Ϊ0
		0,					//��ɾ���ߵ����Կ��أ�����ѡ��1��0��Ĭ��Ϊ0
		DEFAULT_CHARSET,	//������ַ�����Ĭ��ΪDEFAULT_CHARSET
		0,					//����ľ��ȣ�Ĭ��Ϊ0
		0,					//���õľ��ȣ�Ĭ��Ϊ0
		0,					//�߼�����������豸��ʵ������֮��ľ��ȣ�Ĭ��Ϊ0
		0,					//����������弯��Ĭ��Ϊ0
		sfontname			//��������
	);
	return hfont;
}
// ���ɲ�ѡ��һ������
void Graphic::SelectAFont(TCHAR *sfontname, int nfontsize, bool bbold, bool bitalic)
{
	HFONT  hfont, hfold;
	hfont = CreateAFont(sfontname, nfontsize, bbold, bitalic);
	hfold = (HFONT)::SelectObject(m_hDC, hfont);
	if (m_hfontOld == NULL) m_hfontOld = hfold;
	if (m_hfontCur != NULL) ::DeleteObject(m_hfontCur);
	m_hfontCur = hfont;
}
//��ָ�������ڻ�������
void Graphic::DrawText(TCHAR *stext, RECT rect)
{
	::SetTextColor(m_hDC, m_clrText);
	::SetBkMode(m_hDC, TRANSPARENT);
	::DrawText(m_hDC, stext, -1, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_NOCLIP);
}

//-------------------------------------------------------
// VER1.1,��������ͼƬ����
void Graphic::DrawBitmap(HBITMAP hbmp, int x, int y)
{
	BITMAP	bminfo;
	HDC memdc = CreateCompatibleDC(m_hDC);  //�ڴ�DC
	GetObject(hbmp, sizeof(bminfo), &bminfo);  //��ȡͼƬ��С��Ϣ
	SelectObject(memdc, hbmp);        //��g_bg_bmpѡ���ڴ�DC
	BitBlt(m_hDC, x, y, bminfo.bmWidth, bminfo.bmHeight, memdc, 0, 0, SRCCOPY);  //��ͼ��Ŀ��DC 
	DeleteDC(memdc);
}