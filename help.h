
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

void myLine(int x1, int y1, int x2, int y2, int r, int g, int b) //use 3 integers if you want colored lines.
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(r, g, b)); //2 is the width of the pen
	SelectObject(device_context, pen);
	MoveToEx(device_context, x1, y1, NULL);
	LineTo(device_context, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);

}


// This function checks if any of the 4 cursor keys are pressed. 
// If any cursor key is pressed, then the function returns true, and whichKey identifies which of the 4 cursor keys is pressed.
// whichkey is assigned following values if any cursor key is pressed. 1 for left, 2 for up, 3 for right and 4 for left.
bool isCursorKeyPressed(int& whichKey)   //whichKey passed as reference.... 
{
	char key;
	key = GetAsyncKeyState(37);
	if (key == 1)
	{
		whichKey = 1;		// 1 if left key is pressed 
		return true;
	}
	key = GetAsyncKeyState(38);
	if (key == 1)
	{

		whichKey = 2;		// 2 if up key is pressed
		return true;
	}

	key = GetAsyncKeyState(39);
	if (key == 1)
	{

		whichKey = 3; // 3 if right key is pressed
		return true;
	}
	key = GetAsyncKeyState(40);
	if (key == 1)
	{

		whichKey = 4;   // 4 if down key is pressed
		return true;
	}
	key = GetAsyncKeyState(13);
	if (key == 1)
	{

		whichKey = 5;   // 5 if enter key is pressed
		return true;
	}
	return false;
}

void myRectangle(int x1, int y1, int x2, int y2, int R, int G, int B, int type) // type is for outer boundary of shape to indicate if it is a special or destroyer
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);
	int thickness = 2;
	//change the color by changing the values in RGB (from 0-255)
	HBRUSH brush = ::CreateSolidBrush(RGB(R, G, B)); //Fill color can also be passed as parameter to the function!!!
	if (type == 1)
	{
		R = 245; G = 182; B = 87; thickness = 4;
	}
	else if (type == 2)
	{
		R = 196; G = 212; B = 224; thickness = 4;
	}
	HPEN pen = CreatePen(PS_SOLID, thickness, RGB(R, G, B));
	SelectObject(device_context, pen);

	SelectObject(device_context, brush);

	Rectangle(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}
void myEllipse(int x1, int y1, int x2, int y2, int R, int G, int B, int type)  // type is for outer boundary of shape to indicate if it is a special or destroyer
{
	int thickness = 2;
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);
	HBRUSH brush = ::CreateSolidBrush(RGB(R, G, B)); //Fill color can also be passed as parameter to the function!!!
	if (type == 1)
	{
		R = 245; G = 182; B = 87; thickness = 4;
	}
	else if (type == 2)
	{
		R = 196; G = 212; B = 224; thickness = 4;
	}
	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, thickness, RGB(R, G, B));
	SelectObject(device_context, pen);
	SelectObject(device_context, brush);
	Ellipse(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);


}
void myTriangle(int x, int y, int R, int G, int B, int type)  // type is for outer boundary of shape to indicate if it is a special or destroyer
{
	POINT coord[3] = { {x,y + 40},{x + 20,y},{x + 40,y + 40} };
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);
	HBRUSH brush = ::CreateSolidBrush(RGB(R, G, B));
	int thickness = 2;
	if (type == 1)
	{
		R = 245; G = 182; B = 87; thickness = 4;
	}
	else if (type == 2)
	{
		R = 196; G = 212; B = 224; thickness = 4;
	}
	HPEN pen = CreatePen(PS_SOLID, thickness, RGB(R, G, B));
	SelectObject(device_context, pen);
	SelectObject(device_context, brush);
	Polygon(device_context, coord, 3);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);

}
void myHexagon(int x, int y, int R, int G, int B, int type)  // type is for outer boundary of shape to indicate if it is a special or destroyer
{
	POINT coord[6] = { {x,y + 10},{x + 20,y},{x + 40,y + 10},{x + 40,y + 30} , {x + 20,y + 40} , {x,y + 30 } };
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);
	HBRUSH brush = ::CreateSolidBrush(RGB(R, G, B));
	int thickness = 2;
	if (type == 1)
	{
		R = 245; G = 182; B = 87; thickness = 4;
	}
	else if (type == 2)
	{
		R = 196; G = 212; B = 224; thickness = 4;
	}
	HPEN pen = CreatePen(PS_SOLID, thickness, RGB(R, G, B));
	SelectObject(device_context, pen);
	SelectObject(device_context, brush);
	Polygon(device_context, coord, 6);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);

}
void myDiamond(int x, int y, int R, int G, int B, int type)   // type is for outer boundary of shape to indicate if it is a special or destroyer
{
	POINT coord[5] = { {x,y + 10},{x + 10,y},{x + 30,y},{x + 40,y + 10} , {x + 20,y + 40} };
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);
	HBRUSH brush = ::CreateSolidBrush(RGB(R, G, B));
	int thickness = 2;
	if (type == 1)
	{
		R = 245; G = 182; B = 87; thickness = 4;
	}
	else if (type == 2)
	{
		R = 196; G = 212; B = 224; thickness = 4;
	}
	HPEN pen = CreatePen(PS_SOLID, thickness, RGB(R, G, B));
	SelectObject(device_context, pen);
	SelectObject(device_context, brush);
	Polygon(device_context, coord, 5);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);

}

