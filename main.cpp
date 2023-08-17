#include <iostream>
#include <stdlib.h>
#include "drawing.h"
using namespace std;
Drawing dr;

void Project_Column_Chart()
{
    cout << "\n\n\t" << dr.TextColor("Library for creating graphs using Terminal",
    dr.FrontColor.Cyan(),
    dr.Background.Default(),
    dr.FormatAttribute.Bold()) << "\n\n";

    char strRow[] = "Sat,Sum,Mon,Tue,Wed,Thu,GGG";
    char strCol[] = "75,40,65,98,20,60,100";
    dr.Column_Chart(strRow,
    strCol,
    dr.Background.Red(),
    dr.FrontColor.Yellow(),
    dr.Background.Green());

    cout << "\t\t" << dr.TextColor("Profits for the first week",
    dr.FrontColor.Cyan(),
    dr.Background.Default(),
    dr.FormatAttribute.Bold()) << endl;
}

void Project_Bar_Chart()
{
    char strRow[] = "Sat,Sum,Mon,Tue,Wed,Thu,GGG";
    char strCol[] = "75,40,65,98,5,60,100";

    dr.Bar_Chart(strRow,
    strCol,
    dr.Background.Red(),
    dr.FrontColor.Yellow(),
    dr.Background.Green());
}


int main()
{
    system("clear");

    Project_Column_Chart();
    cout << "\n\n";
    Project_Bar_Chart();

    return 0;
}

