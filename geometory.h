// geometory.h
//幾何学（図形）処理のヘッダファイル
#pragma once

#include "DxLib.h"
#include <math.h>

//外部のプロトタイプ宣言

//点関係
extern POINT GetPoint(int x, int y); //X地点とY地点からPOINT型を一時的に取得
extern BOOL CollPointToPoint(POINT a, POINT b); //点と点が当たっているか？

//矩形（くけい＝四角）関係
extern RECT GetRect(int left, int top, int right, int bottom); //左上右下からRECT型を一時的に取得
extern BOOL CollRectToRect(RECT a, RECT b); //矩形と矩形が当たっているか？
extern BOOL CollRectToPoint(RECT rect, POINT pt); //矩形と点が当たっているか？
extern void DrawRect(RECT rect, unsigned int color, BOOL fill); //RECT型で矩形を描く

// End
