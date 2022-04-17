#include "stdafx.h"
#include "Ball.h"
#include "Graphic.h"

Ball::Ball(void)
{
	Init(0, 0, 1);
	m_speed = 1;
	m_x = 0;
	m_y = 0;
	m_clrBack = RGB(255, 255, 255);
	m_color = RGB(0, 0, 0);
}

Ball::~Ball(void) {  }

void Ball::Init(int x, int y, int r)
{
	m_x = x;
	m_y = y;
	m_radius = r;
	m_Xdir = m_Ydir = 0;
	m_ptold.x = x;
	m_ptold.y = y;
}

void Ball::Draw(HDC hdc)
{
	Graphic graph(hdc);
	RECT rect = { m_ptold.x - m_radius,m_ptold.y - m_radius,m_ptold.x + m_radius,m_ptold.y + m_radius };
	graph.FillRect(rect,m_clrBack);
	graph.SelectAPen(PS_SOLID, 1, RGB(255, 255, 255));
	graph.SelectABrush(m_color);
	graph.DrawCircle(m_x, m_y, m_radius);
}

void Ball::Run(void)
{
	int xt, yt;
	xt = m_x;
	yt = m_y;
	xt += m_Xdir*m_speed;
	yt += m_Ydir*m_speed;
	if (xt >= m_rect.right - m_radius)
		m_Xdir = -1;
	if (xt <= m_rect.left + m_radius)
		m_Xdir = 1;
	if (yt <= m_rect.top + m_radius)
		m_Ydir = 1;
	if (yt >= m_rect.bottom - m_radius)
		m_Ydir = -1;
	m_ptold.x = m_x;
	m_ptold.y = m_y;
	m_x += m_Xdir*m_speed;
	m_y += m_Ydir*m_speed;
}

void Ball::Go(int xdir, int ydir)
{
	m_Xdir = xdir;
	m_Ydir = ydir;
}

bool Ball::IsTouchMe(int x, int y)
{
	int dx = x-m_x;
	int dy = y-m_y;
	return (dx*dx + dy*dy) <= (m_radius*m_radius);
}

void Ball::Boom(Ball &ball2)
{
	int d,d0;
	d = (m_x - ball2.GetX())*(m_x - ball2.GetX()) + (m_y - ball2.GetY())*(m_y - ball2.GetY());
	d0 = (2 * m_radius)*(2 * m_radius);
	if (d < d0)
	{
		if (m_Xdir == ball2.GetRunX() && m_Ydir != ball2.GetRunY())
		{
			BounceY();
			ball2.BounceY();
		}
		if (m_Xdir == ball2.GetRunX() && m_Ydir == ball2.GetRunY())
		{
			BounceX();
			ball2.BounceX();
			BounceY();
			ball2.BounceY();
		}
		if (m_Xdir != ball2.GetRunX() && m_Ydir == ball2.GetRunY())
		{
			BounceX();
			ball2.BounceX();
		}
		if (m_Xdir != ball2.GetRunX() && m_Ydir != ball2.GetRunY())
		{
			BounceX();
			ball2.BounceX();
			BounceY();
			ball2.BounceY();
		}
	}
}