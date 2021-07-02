#include "projekt1.h"
#include "stdafx.h"
#include <vector>
#include <cstdio>
#include <Windows.h>
#include <fstream>
#include <iostream>
INT value;
int k = 0;
int Liczbaprzejsc[100];
#define MAX_LOADSTRING 100
#define TMR_1 1
// Zmienne globalne:
HINSTANCE hInst;                                // bieĹĽÄ…ce wystÄ…pienie
WCHAR szTitle[MAX_LOADSTRING];                  // Tekst paska tytuĹ‚u
WCHAR szWindowClass[MAX_LOADSTRING];            // nazwa klasy okna gĹ‚Ăłwnego
std::vector<float> Data;
HWND g_hPrzycisk2, g_hPrzycisk3, g_hPrzycisk4, g_hPrzycisk5;
HWND hStatic, hStatic2, hStatic3, hStatic4, hStatic10, hStatic9;int timestep = 4;
int T = 1;//zmiana na osi czasu 
int A = 2; // amplituda;
int n = 150;//ilosc pominietych probek
RECT drawArea1 = { 0, 0, 1500, 366 };
//RECT drawArea2 = { 50, 400, 650, 422 };

// PrzekaĹĽ dalej deklaracje funkcji doĹ‚Ä…czone w tym module kodu:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
HWND hwndButton;
void inputData()
{
    float x;
    std::fstream plik;
    plik.open("outputPendulum01.txt", std::ios::in);
    int i = 0;
    if (plik.good() == true)
    {
        while (!plik.eof()) {
            plik >> x;
            if (i == 0) {
                Data.push_back(x);
            }
            if (i == 11)i = -1;
            i++;
        }
        plik.close();
    }
    else std::cout << "Dostep do pliku zostal zabroniony!" << std::endl;

}
/// <summary>
/// //////////////////////////////////////////////////
/// </summary>
void czas()
{  
    int w = 0;
    int i = 0;
    inputData();
    while (!Data.empty()) {
        if (Data[0]*Data[1] < 0)
        {

            k++;

        }
        Data.erase(Data.begin());
        w++;
        if (k == 2)
        {  

            k = 0;
            Liczbaprzejsc[i] = w;
            w = 0;
            i++;
        }
    }
}
/// <summary>
/// ////////////////////////////////////////////////////////
/// </summary>
/// <param name="window"></param>
/// <returns></returns>
int OnCreate(HWND window)
{
    inputData();
    return 0;
}

void rysuj20(HDC hdc) {
    Graphics graphics(hdc);
    Pen pen2(Color(255, 0, 0, 0));
    switch (A) {
    case 1:
        graphics.DrawLine(&pen2, 195, 85, 195, 95);//0
        graphics.DrawLine(&pen2, 189, 95, 189, 85);//0
        graphics.DrawLine(&pen2, 189, 85, 195, 85);//0
        graphics.DrawLine(&pen2, 189, 95, 195, 95);//0
        graphics.DrawLine(&pen2, 186, 95, 180, 95);//2
        graphics.DrawLine(&pen2, 180, 95, 180, 89);//2
        graphics.DrawLine(&pen2, 180, 89, 186, 89);//2
        graphics.DrawLine(&pen2, 186, 89, 186, 85);//2
        graphics.DrawLine(&pen2, 186, 85, 180, 85);//2
        graphics.DrawLine(&pen2, 195, 285, 195, 295);//0
        graphics.DrawLine(&pen2, 189, 285, 195, 285);//0
        graphics.DrawLine(&pen2, 189, 290, 195, 290);//0
        graphics.DrawLine(&pen2, 189, 295, 195, 295);//0
        break;
    case 2:
        graphics.DrawLine(&pen2, 195, 85, 195, 75);//0
        graphics.DrawLine(&pen2, 189, 75, 189, 85);//0
        graphics.DrawLine(&pen2, 189, 85, 195, 85);//0
        graphics.DrawLine(&pen2, 189, 75, 195, 75);//0
        graphics.DrawLine(&pen2, 186, 85, 180, 85);//2
        graphics.DrawLine(&pen2, 180, 85, 180, 79);//2
        graphics.DrawLine(&pen2, 180, 79, 186, 79);//2
        graphics.DrawLine(&pen2, 186, 79, 186, 75);//2
        graphics.DrawLine(&pen2, 186, 75, 180, 75);//2
        graphics.DrawLine(&pen2, 195, 275, 195, 285);//0
        graphics.DrawLine(&pen2, 189, 275, 195, 275);//0
        graphics.DrawLine(&pen2, 189, 280, 195, 280);//0
        graphics.DrawLine(&pen2, 189, 285, 195, 285);//0
        break;
    case 4:
        graphics.DrawLine(&pen2, 195, 55, 195, 65);//0
        graphics.DrawLine(&pen2, 189, 65, 189, 55);//0
        graphics.DrawLine(&pen2, 189, 55, 195, 55);//0
        graphics.DrawLine(&pen2, 189, 65, 195, 65);//0
        graphics.DrawLine(&pen2, 186, 65, 180, 65);//2
        graphics.DrawLine(&pen2, 180, 65, 180, 59);//2
        graphics.DrawLine(&pen2, 180, 59, 186, 59);//2
        graphics.DrawLine(&pen2, 186, 59, 186, 55);//2
        graphics.DrawLine(&pen2, 186, 55, 180, 55);//2
        graphics.DrawLine(&pen2, 195, 255, 195, 265);//0
        graphics.DrawLine(&pen2, 189, 255, 195, 255);//0
        graphics.DrawLine(&pen2, 189, 260, 195, 260);//0
        graphics.DrawLine(&pen2, 189, 265, 195, 265);//0
        break;
    }
}

void osie(HDC hdc) {
    Graphics graphics(hdc);
    Pen pen2(Color(255, 0, 0, 0)); int k = A;
    graphics.DrawLine(&pen2, 200, 100, 1100 , 100);//OX
    graphics.DrawLine(&pen2, 200, 99, 1098 , 99);//OX
    graphics.DrawLine(&pen2, 200, 101, 1098, 101);//OX
    switch (A) {
    case 1:for (int i = 40; i < 200; i += 10) {
        graphics.DrawLine(&pen2, 200, i, 1100, i);
    }
          for (int i = 240; i < 310; i += 10) {
              graphics.DrawLine(&pen2, 200, i, 1100, i);
          }
        break;
    case 2:for (int i = 40; i < 200; i += 20) {
        graphics.DrawLine(&pen2, 200, i, 1100, i);
    }
          for (int i = 240; i < 310; i += 20) {
              graphics.DrawLine(&pen2, 200, i, 1100, i);
          }
        break;
    case 4:for (int i = 60; i < 200; i += 40) {
        graphics.DrawLine(&pen2, 200, i, 1100, i);
    }
          for (int i = 260; i < 310; i += 40) {
              graphics.DrawLine(&pen2, 200, i, 1100, i);
          }
        break;
    }
    

    graphics.DrawLine(&pen2, 1100, 100, 1095, 95);//OX strzalka
    graphics.DrawLine(&pen2, 1100, 99, 1095, 94);//OX strzalka
    graphics.DrawLine(&pen2, 1100, 100,1095, 105);//OX strzalka
    graphics.DrawLine(&pen2, 1100, 101, 1095, 106);//OX strzalka
    graphics.DrawLine(&pen2, 1106 , 95, 1120 , 95);//T
    graphics.DrawLine(&pen2, 1113 , 105, 1113 , 95);//T
    graphics.DrawLine(&pen2, 194, 18, 180, 27);//alfa
    graphics.DrawLine(&pen2, 180, 27, 175, 24);//alfa
    graphics.DrawLine(&pen2, 180, 18, 175, 24);//alfa
    graphics.DrawLine(&pen2, 180, 18, 194, 27);//alfa
    graphics.DrawLine(&pen2, 200, 20, 200, 200);//OY
    graphics.DrawLine(&pen2, 199, 22, 199, 200);//OY
    graphics.DrawLine(&pen2, 201, 22, 201, 200);//OY
    graphics.DrawLine(&pen2, 200, 19, 205, 24);//OY strzalka
    graphics.DrawLine(&pen2, 200, 18, 205, 23);//OY strzalka
    graphics.DrawLine(&pen2, 200, 19, 195, 24);//OY strzalka
    graphics.DrawLine(&pen2, 200, 18, 195, 23);//OY strzalka

    for (int i = 300; i < 1100; i += 100) {
        graphics.DrawLine(&pen2, i, 20, i, 200);//OY
        graphics.DrawLine(&pen2, i, 220, i, 310);//OY
    }
    
    //2 wykres dla h
    graphics.DrawLine(&pen2, 200, 300, 1100, 300);//OX
    graphics.DrawLine(&pen2, 200, 299, 1098, 299);//OX
    graphics.DrawLine(&pen2, 200, 301, 1098, 301);//OX
    graphics.DrawLine(&pen2, 1100, 300, 1095, 295);//OX strzalka
    graphics.DrawLine(&pen2, 1100, 299, 1095, 294);//OX strzalka
    graphics.DrawLine(&pen2, 1100, 300, 1095, 305);//OX strzalka
    graphics.DrawLine(&pen2, 1100, 301, 1095, 306);//OX strzalka
    graphics.DrawLine(&pen2, 1106, 295, 1120, 295);//T
    graphics.DrawLine(&pen2, 1113, 305, 1113, 295);//T
    graphics.DrawLine(&pen2, 180, 217, 180, 230);//H
    graphics.DrawLine(&pen2, 180, 223, 190, 223);//H
    graphics.DrawLine(&pen2, 190, 217, 190, 230);//H
    graphics.DrawLine(&pen2, 200, 220, 200, 310);//OY
    graphics.DrawLine(&pen2, 199, 220, 199, 310);//OY
    graphics.DrawLine(&pen2, 201, 220, 201, 310);//OY
    graphics.DrawLine(&pen2, 200, 219, 205, 224);//OY strzalka
    graphics.DrawLine(&pen2, 200, 218, 205, 223);//OY strzalka
    graphics.DrawLine(&pen2, 200, 219, 195, 224);//OY strzalka
    graphics.DrawLine(&pen2, 200, 218, 195, 223);//OY strzalka

    switch (A) {
    case 1: rysuj20(hdc);
        break;
    case 2:rysuj20(hdc);
        break;
    case 4:rysuj20(hdc);
        break;
    }
    

}
void napisOkno() {
    switch (n) {
    case 0:SetWindowText(hStatic4, L"0");
        break;
    case 50:SetWindowText(hStatic4, L"50");
        break;
    case 100:SetWindowText(hStatic4, L"100");
        break;
    case 150:SetWindowText(hStatic4, L"150");
        break;
    case 200:SetWindowText(hStatic4, L"200");
        break;
    case 250:SetWindowText(hStatic4, L"250");
        break;
    case 300:SetWindowText(hStatic4, L"300");
        break;
    case 350:SetWindowText(hStatic4, L"350");
        break;
    case 400:SetWindowText(hStatic4, L"400");
        break;
    case 450:SetWindowText(hStatic4, L"450");
        break;
    case 500:SetWindowText(hStatic4, L"500");
        break;
    case 550:SetWindowText(hStatic4, L"550");
        break;
    case 600:SetWindowText(hStatic4, L"600");
        break;
    default:SetWindowText(hStatic4, L"nie ma tylu danych");

    }
}

void napisOkno2() {
    switch (A) {
    case 1:SetWindowText(hStatic2, L"0,5"); break;
    case 2:SetWindowText(hStatic2, L"1"); break;
    case 4:SetWindowText(hStatic2, L"2"); break;
    }
}
void napisOkno3() {
    switch (timestep) {
    case 10:SetWindowText(hStatic3, L"10"); SetWindowText(hStatic9, L"przedzialka czasowa ma 2s"); break;
    case 8:SetWindowText(hStatic3, L"8"); SetWindowText(hStatic9, L"przedzialka czasowa ma 1,8s"); break;
    case 6:SetWindowText(hStatic3, L"6"); SetWindowText(hStatic9, L"przedzialka czasowa ma 1,6s"); break;
    case 4:SetWindowText(hStatic3, L"4"); SetWindowText(hStatic9, L"przedzialka czasowa ma 1,4s"); break;
    case 2:SetWindowText(hStatic3, L"2"); SetWindowText(hStatic9, L"przedzialka czasowa ma 1,2s"); break;
    case 0:SetWindowText(hStatic3, L"0"); SetWindowText(hStatic9, L"Wykres wykonany bez czasu"); break;
    case 12:SetWindowText(hStatic3, L"12"); SetWindowText(hStatic9, L"przedzialka czasowa ma 2,2s"); break;
    case 14:SetWindowText(hStatic3, L"14"); SetWindowText(hStatic9, L"przedzialka czasowa ma 2,4s"); break;
    case 16:SetWindowText(hStatic3, L"16"); SetWindowText(hStatic9, L"przedzialka czasowa ma 2,6s"); break;
    case 18:SetWindowText(hStatic3, L"18"); SetWindowText(hStatic9, L"przedzialka czasowa ma 2,8s"); break;
    case 20:SetWindowText(hStatic3, L"20"); SetWindowText(hStatic9, L"przedzialka czasowa ma 3s"); break;
    }
}

void MyOnPaint(HDC hdc)
{
    Graphics graphics(hdc);
    Pen pen(Color(255, 255, 255, 255));
    Pen pen2(Color(255, 0, 0, 0));
    inputData();
    int max = Data.size()-n;
    float q1 = 0, q2 = 0;
    if (Data.size() < n) { }//usuwanie n probek z wektora
    else {
        if (n > 0) {
            for (int i = 0; i < n; i++) {
                Data.erase(Data.begin());
            }
        }
    }osie(hdc); float a = Data.front();
    int x = 0; int y = 1000 * a; int z = y / 2000; int b = 1000 * a; int c = b / 2000;
    while (!Data.empty() && x<835-n) {//rysowanie wykresu i kompasu
        q1 = 100+100 * sin(a * 3.14 / 180);
        q2 = 30+100 * cos(a * 3.14 / 180);
        graphics.DrawLine(&pen2, q1-12,q2-12,q1+12,q2+12);
        graphics.DrawLine(&pen2, q1 + 12, q2 - 12, q1 - 12, q2 + 12);
        graphics.DrawLine(&pen2, q1 , q2 - 12, q1 , q2 + 12);
        graphics.DrawLine(&pen2, q1+12, q2 , q1-12, q2 );
        graphics.DrawLine(&pen2, q1-q1+100, q2-q2+30 , q1, q2);
        graphics.DrawLine(&pen2, 200 + T * (x), 100 - A*z, 200 + T * (x + 1), 100 - A*y / 2000);//wykres
        graphics.DrawLine(&pen2, 200 + T * (x), 300 - A * c, 200 + T * (x + 1), 300 - A * b / 2000);//wykres
        Sleep(timestep);
        a = Data.front();
        
        Data.erase(Data.begin());
       
        
        if (x<834-n) {
            graphics.DrawLine(&pen, q1 - 12, q2 - 12, q1 + 12, q2 + 12);
            graphics.DrawLine(&pen, q1 + 12, q2 - 12, q1 - 12, q2 + 12);
            graphics.DrawLine(&pen, q1, q2 - 12, q1, q2 + 12);
            graphics.DrawLine(&pen, q1 + 12, q2, q1 - 12, q2);
            graphics.DrawLine(&pen, q1 - q1 + 100, q2 - q2 + 30, q1, q2);
            z = y / 2000; c = b / 2000; if (c < 0)c *= (-1);

            y = 1000 * a; b = 1000 * a; if (b < 0)b *= (-1);
            }
        x++;
    }
}
void repaintWindow(HWND hWnd, HDC& hdc, PAINTSTRUCT& ps, RECT* drawArea)
{  
   
    
 
        InvalidateRect(hWnd, drawArea, TRUE); //repaint drawArea
    hdc = BeginPaint(hWnd, &ps);
   MyOnPaint(hdc);
   EndPaint(hWnd, &ps);
   k++;
   
}


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);


    GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR           gdiplusToken;
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

    // Inicjuj ciÄ…gi globalne
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_PROJEKT1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Wykonaj inicjowanie aplikacji:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_PROJEKT1));
    
    OnCreate(HWND(hInstance));
    MSG msg;

    // GĹ‚Ăłwna pÄ™tla komunikatĂłw:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    GdiplusShutdown(gdiplusToken);
    return (int)msg.wParam;
}



//
//  FUNKCJA: MyRegisterClass()
//
//  PRZEZNACZENIE: Rejestruje klasÄ™ okna.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PROJEKT1));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_PROJEKT1);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNKCJA: InitInstance(HINSTANCE, int)
//
//   PRZEZNACZENIE: Zapisuje dojĹ›cie wystÄ…pienia i tworzy okno gĹ‚Ăłwne
//
//   KOMENTARZE:
//
//        W tej funkcji dojĹ›cie wystÄ…pienia jest zapisywane w zmiennej globalnej i
//        jest tworzone i wyĹ›wietlane okno gĹ‚Ăłwne programu.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    HWND hWnd;
    hInst = hInstance; // Przechowuj dojĹ›cie wystÄ…pienia w naszej zmiennej globalnej

     hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
        TEXT("Generuj"),                  // the caption of the button
        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
        50, 370,                                  // the left and top co-ordinates
        80, 50,                              // width and height
        hWnd,                                 // parent window handle
        (HMENU)ID_BUTTON1,                   // the ID of your button
        hInstance,                            // the instance of your application
        NULL);
    hwndButton = CreateWindow(TEXT("button"), TEXT("Timer ON"),
        WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
        165, 400, 100, 30, hWnd, (HMENU)ID_RBUTTON1, GetModuleHandle(NULL), NULL);

    hwndButton = CreateWindow(TEXT("button"), TEXT("Timer OFF"),
        WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
        165, 450, 100, 30, hWnd, (HMENU)ID_RBUTTON2, GetModuleHandle(NULL), NULL);

    g_hPrzycisk2 = CreateWindowEx(0, L"BUTTON", L"reset ", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        50, 450, 80, 50, hWnd, NULL, hInstance, NULL);

    g_hPrzycisk3 = CreateWindowEx(0, L"BUTTON", L"Amplituda up ", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        300, 370, 150, 30, hWnd, NULL, hInstance, NULL);

    g_hPrzycisk5 = CreateWindowEx(0, L"BUTTON", L"Amplituda normal ", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        300, 420, 150, 30, hWnd, NULL, hInstance, NULL);

    g_hPrzycisk4 = CreateWindowEx(0, L"BUTTON", L"Amplituda down ", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        300, 470, 150, 30, hWnd, NULL, hInstance, NULL);
    hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
        TEXT("przyspieszenie 2ms"),                  // the caption of the button
        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
        500, 370,                                  // the left and top co-ordinates
        150, 30,                              // width and height
        hWnd,                                 // parent window handle
        (HMENU)ID_BUTTON2,                   // the ID of your button
        hInstance,                            // the instance of your application
        NULL);                               // extra bits you dont really need
    hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
        TEXT("spowolnienie 2ms"),                  // the caption of the button
        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
        500, 420,                                  // the left and top co-ordinates
        150, 30,                              // width and height
        hWnd,                                 // parent window handle
        (HMENU)ID_BUTTON3,                   // the ID of your button
        hInstance,                            // the instance of your application
        NULL);                               // extra bits you dont really need
    hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
        TEXT("ilosc probek +50"),                  // the caption of the button
        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
        700, 370,                                  // the left and top co-ordinates
        150, 30,                              // width and height
        hWnd,                                 // parent window handle
        (HMENU)ID_BUTTON4,                   // the ID of your button
        hInstance,                            // the instance of your application
        NULL);                               // extra bits you dont really need
    hwndButton = CreateWindow(TEXT("button"),                      // The class name required is button
        TEXT("ilosc probek -50"),                  // the caption of the button
        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  // the styles
        700, 420,                                  // the left and top co-ordinates
        150, 30,                              // width and height
        hWnd,                                 // parent window handle
        (HMENU)ID_BUTTON5,                   // the ID of your button
        hInstance,                            // the instance of your application
        NULL);

    hStatic = CreateWindowEx(0, L"STATIC", NULL, WS_CHILD | WS_VISIBLE |
        SS_LEFT, 880, 370, 200, 40, hWnd, NULL, hInstance, NULL);
    HWND hStatic5 = CreateWindowEx(0, L"STATIC", NULL, WS_CHILD | WS_VISIBLE |
        SS_LEFT, 880, 410, 150, 40, hWnd, NULL, hInstance, NULL);
    HWND hStatic6 = CreateWindowEx(0, L"STATIC", NULL, WS_CHILD | WS_VISIBLE |
        SS_LEFT, 880, 450, 150, 40, hWnd, NULL, hInstance, NULL);
    HWND hStatic7 = CreateWindowEx(0, L"STATIC", NULL, WS_CHILD | WS_VISIBLE |
        SS_LEFT, 880, 490, 150, 40, hWnd, NULL, hInstance, NULL);

    hStatic2 = CreateWindowEx(0, L"STATIC", NULL, WS_CHILD | WS_VISIBLE |
        SS_LEFT, 1030, 410, 50, 40, hWnd, NULL, hInstance, NULL);
    hStatic3 = CreateWindowEx(0, L"STATIC", NULL, WS_CHILD | WS_VISIBLE |
        SS_LEFT, 1030, 450, 50, 40, hWnd, NULL, hInstance, NULL);
    hStatic4 = CreateWindowEx(0, L"STATIC", NULL, WS_CHILD | WS_VISIBLE |
        SS_LEFT, 1030, 490, 50, 40, hWnd, NULL, hInstance, NULL);
    SetWindowText(hStatic5, L"Amplituda:");
    SetWindowText(hStatic6, L"Odstepy czasu");
    SetWindowText(hStatic7, L"Odrzucone probki");
    SetWindowText(hStatic, L"INFORMACJE");
    SetWindowText(hStatic2, L"2");
    SetWindowText(hStatic3, L"4");
    SetWindowText(hStatic4, L"150");

    hStatic9 = CreateWindowEx(0, L"STATIC", NULL, WS_CHILD | WS_VISIBLE |
        SS_CENTER, 50, 250, 100, 50, hWnd, NULL, hInstance, NULL);
    SetWindowText(hStatic9, L"przedzialka czasowa ma 1,4s");
    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

//
//  FUNKCJA: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PRZEZNACZENIE: Przetwarza komunikaty dla okna gĹ‚Ăłwnego.
//
//  WM_COMMAND  - przetwarzaj menu aplikacji
//  WM_PAINT    - Maluj okno gĹ‚Ăłwne
//  WM_DESTROY  - opublikuj komunikat o wyjĹ›ciu i wrĂłÄ‡
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{ 
    PAINTSTRUCT ps;
    HDC hdc;
    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        int wmEvent = HIWORD(wParam);
        // Analizuj zaznaczenia menu:
        if ((HWND)lParam == g_hPrzycisk2)
        {
            A = 2; n = 200; timestep = 4;
            napisOkno();
            napisOkno2();
            SetWindowText(hStatic, L"INFORMACJE");
            repaintWindow(hWnd, hdc, ps, &drawArea1);
        }
        if ((HWND)lParam == g_hPrzycisk3)
        {
            A = 4; napisOkno2();
            SetWindowText(hStatic, L"GENERUJ!!!");
        }
        if ((HWND)lParam == g_hPrzycisk4)
        {
            A = 1; napisOkno2();
            SetWindowText(hStatic, L"GENERUJ!!!");
        }
        if ((HWND)lParam == g_hPrzycisk5)
        {
            A = 2; napisOkno2();
            SetWindowText(hStatic, L"GENERUJ!!!");
        }
        switch (wmId)
        {
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;

        case ID_BUTTON2:
            if (timestep > 1) {
                timestep = timestep - 2;
                napisOkno3();
                SetWindowText(hStatic, L"GENERUJ!!!");
                // SetTimer(hWnd, TMR_1, 30, 0);
            }
            break;
        case ID_BUTTON3:
            if (timestep < 19)
                timestep = timestep + 2;

            napisOkno3();
            SetWindowText(hStatic, L"GENERUJ!!!");
            //  SetTimer(hWnd, TMR_1, 30, 0)
            break;
        case ID_BUTTON4:
            if (n < 601)n += 50; napisOkno();

            SetWindowText(hStatic, L"GENERUJ!!!");
            break;
        case ID_BUTTON5:
            if (n == 0) {}
            else {
                n -= 50;
            }
            napisOkno();
            SetWindowText(hStatic, L"GENERUJ!!!");
            break;
        case ID_BUTTON1:
            SetWindowText(hStatic, L"INFORMACJE");
            repaintWindow(hWnd, hdc, ps,&drawArea1 );
            break;

        case ID_RBUTTON1:
            SetTimer(hWnd, TMR_1, 25, 0);
            break;
        case ID_RBUTTON2:
            KillTimer(hWnd, TMR_1);
            break;

        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);


     
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_TIMER:
        switch (wParam)
        {
        case TMR_1:
            //force window to repaint
            repaintWindow(hWnd, hdc, ps, &drawArea1);
            value++;
            break;
        }
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Procedura obsĹ‚ugi komunikatĂłw dla okna informacji o programie.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}