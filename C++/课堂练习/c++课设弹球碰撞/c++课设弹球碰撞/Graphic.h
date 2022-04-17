#pragma once
//
//  �������Ȩ�� ���ڡ���� ����
//
//ͼ�ι�����
class Graphic
{
private:
	HDC  m_hDC;			//�豸�������
	HPEN m_hpenOld;		//�ɵĻ���
	HPEN m_hpenCur;		//��ǰ����
	HBRUSH m_hbrOld;	//�ɵĻ�ˢ
	HBRUSH m_hbrCur;	//��ǰ��ˢ
	HFONT  m_hfontOld;	//�ɵ�����
	HFONT  m_hfontCur;	//��ǰ������
	COLORREF m_clrText;	//�ı�����ɫ
public:
	//���캯��
	Graphic(HDC hdc = NULL);
	//��������
	~Graphic(void);
public:
	//���û������
	void SetHDC(HDC hdc);
	// ���ɲ�ѡ��һ�ֻ���
	void SelectAPen(HPEN hpen);
	// ���ɲ�ѡ��һ�ֻ���
	void SelectAPen(int npstyle, int nwidth, COLORREF color);
	// ���ɲ�ѡ��һ�ֻ�ˢ
	void SelectABrush(HBRUSH hbrush);
	// ���ɲ�ѡ��һ�ֻ�ˢ
	void SelectABrush(COLORREF color);
	// ����һ������
	HFONT CreateAFont(TCHAR *sfontname, int nfontsize, bool bbold = false, bool bitalic = false);
	// ���ɲ�ѡ��һ������
	void SelectAFont(TCHAR *sfontname, int nfontsize, bool bbold = false, bool bitalic = false);
	// ���õ�ǰ���ʣ�����һ��ֱ��
	void DrawLine(int x1, int y1, int x2, int y2);
	// ����һ������
	void DrawRect(RECT rect, bool bfill = true);
	// ����һ������
	void DrawRect(int x1, int y1, int wx, int hy, bool bfill = true);
	// ����ɫ���һ������
	void FillRect(RECT rect, COLORREF color);
	// ����ɫ���һ������
	void FillRect(int x, int y, int wx, int hy, COLORREF color);
	// ����һ��Բ��
	void DrawCircle(int x, int y, int radius);
	//��ָ�������ڻ�������
	void DrawText(TCHAR *stext, RECT rect);
	//-------------------------------------------------------
	// VER1.1,��������ͼƬ����
	void DrawBitmap(HBITMAP hbmp, int x, int y);

public:
	//�����ı���ɫ����
	void SetTextColor(COLORREF color)
	{
		m_clrText = color;
	}
	//���ص�ǰ����
	HPEN GetCurPen() { return m_hpenCur; }
	//���ص�ǰ��ˢ
	HBRUSH GetCurBrush() { return m_hbrCur; }
	//���ص�ǰ����
	HFONT GetCurFont() { return m_hfontCur; }
	//�õ�һ�������ɫ����̬��Ա����
	static COLORREF GetRandColor()
	{
		return RGB(rand() % 256, rand() % 256, rand() % 256);
	}
};
