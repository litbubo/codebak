#pragma once
class Ball
{
private:
	int m_radius;
	int m_Xdir;
	int m_Ydir;
	int m_speed;
	int m_x;
	int m_y;
	RECT m_rect;
	POINT m_ptold;
	COLORREF m_clrBack;
	COLORREF m_color;
public:
	Ball(void);
	~Ball(void);
	void Init(int x, int y, int r);
	void Draw(HDC hdc);
	void Run(void);
	void Go(int xdir, int ydir);
	bool IsTouchMe(int x, int y);
	void Boom(Ball &);
	void SetBound(RECT rect) { m_rect = rect; }
	void SetColor(COLORREF color) { m_color = color; }
	int GetX() { return m_x; }
	int GetY() { return m_y; }
	int GetRunX() { return m_Xdir; }
	int GetRunY() { return m_Ydir; }
	void BounceX() { m_Xdir = -m_Xdir; }
	void BounceY() { m_Ydir = -m_Ydir; }
};

