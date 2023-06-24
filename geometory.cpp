// geometory.cpp
//幾何学（図形）処理のソースファイル

#include "geometory.h"

//関数 //////////////
//点関係
//X地点とY地点からPOINT型を一時的に取得
POINT GetPoint(int x, int y)
{
	POINT pt{};

	pt.x = x;
	pt.y = y;

	return pt;
}

//点と点が当たっているか？
BOOL CollPointToPoint(POINT a, POINT b)
{
	if (a.x == b.x && a.y == b.y)
	{
		//当たっている
		return TRUE;
	}
	//当たっていない
	return FALSE;
}

//矩形（くけい＝四角）関係
//左上右下からRECT型を一時的に取得
RECT GetRect(int left, int top, int right, int bottom)
{
	RECT rect{};

	rect.left = left;
	rect.top = top;
	rect.right = right;
	rect.bottom = bottom;

	return rect;
}

//矩形と矩形が当たっているか？
BOOL CollRectToRect(RECT a, RECT b)
{
	if (a.left <= b.right
		&& a.top <= b.bottom
		&& a.right >= b.left
		&& a.bottom >= b.top)
	{
		//当たっている
		return TRUE;
	}
	//当たっていない
	return FALSE;
}

//矩形と点が当たっているか？
BOOL CollRectToPoint(RECT rect, POINT pt)
{
	if (rect.left <= pt.x
		&& rect.top <= pt.y
		&& rect.right >= pt.x
		&& rect.bottom >= pt.y)
	{
		//当たっている
		return TRUE;
	}
	//当たっていない
	return FALSE;
}

//RECT型で矩形を描く
void DrawRect(RECT rect, unsigned int color, BOOL fill)
{
	//矩形を描く
	DrawBox(
		rect.left,
		rect.top,
		rect.right,
		rect.bottom,
		color,
		fill
	);

	return;
}

// End
