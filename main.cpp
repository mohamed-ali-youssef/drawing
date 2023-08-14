#include <iostream>
#include "drawing.h"
using namespace std;
Drawing dr;

int main()
{
    system("clear");

    cout << "\n\n\t" << dr.TextColor("Library for creating graphs using Terminal",
    dr.FrontColor.Cyan(),
    dr.Background.Null(),
    dr.Bold.True()) << "\n\n";


    char strRow[] = "Sat,Sum,Mon,Tue,Wed,Thu";
    char strCol[] = "75,40,65,98,20,60";
    dr.Chart(strRow,
    strCol,
    dr.ColumnsColor.Red(),
    dr.HeadsColor.Yellow(),
    dr.ColorBox.Blue());


    cout << "\t\t" << dr.TextColor("Profits for the first week",
    dr.FrontColor.Cyan(),
    dr.Background.Null(),
    dr.Bold.True());


    return 0;
}

