## mytest.h

```cpp
#ifndef MYTEST_H_INCLUDED
#define MYTEST_H_INCLUDED

#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

enum ConsoleForegroundColor
{
  CFC_Red        = FOREGROUND_INTENSITY | FOREGROUND_RED,
  CFC_Green      = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
  CFC_Blue       = FOREGROUND_INTENSITY | FOREGROUND_BLUE,
  CFC_Yellow     = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
  CFC_Purple     = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE,
  CFC_Cyan       = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
  CFC_Gray       = FOREGROUND_INTENSITY,
  CFC_White      = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
  CFC_HighWhite  = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
  CFC_Black      = 0,
};

enum ConsoleBackGroundColor
{
  CBC_Red        = BACKGROUND_INTENSITY | BACKGROUND_RED,
  CBC_Green      = BACKGROUND_INTENSITY | BACKGROUND_GREEN,
  CBC_Blue       = BACKGROUND_INTENSITY | BACKGROUND_BLUE,
  CBC_Yellow     = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN,
  CBC_Purple     = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE,
  CBC_Cyan       = BACKGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE,
  CBC_White      = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
  CBC_HighWhite  = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
  CBC_Black      = 0,
};

void setColor(WORD color) {
  HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(handle, color);
}

void reSet() {setColor(CFC_White|CBC_Black);}

void _print() {
  reSet();
  cerr << endl;
}
template <typename T, typename ... U>
void _print(T val, U ... tail) {
  cerr << val << ' ';
  _print(tail...);
}

#define print(...) do{setColor(CFC_Blue|CBC_HighWhite);_print(__VA_ARGS__);}while(0)
#define rprint(...)  do{setColor(CFC_Yellow|CBC_Red);_print(__VA_ARGS__);}while(0)
#define bprint(...)  do{setColor(CFC_Yellow|CBC_Blue);_print(__VA_ARGS__);}while(0)
#define open(file) if (freopen(#file, "r", stdin) == 0) freopen("CON", "r", stdin)

struct Clock {
  long long last_time;
  Clock() : last_time(GetTickCount()){}
  ~Clock() {operator()();}
  void operator()() {
    setColor(CFC_Purple|CBC_Yellow);
    cerr << endl;
    _print(GetTickCount() - last_time, "ms");
    last_time = GetTickCount();
  }
} clk;

#endif // MYTEST_H_INCLUDED

```

