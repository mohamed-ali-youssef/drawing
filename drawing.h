/*******************************************************************
  Design library for drawing colors on the black screen commands Terminal
           using language C++ This library is open source
   Developed by Eng. Mohammad Ali Youssef on Last Update 17-08-2023
    Tel : +20 01066568205  |   Email : ensert.egypt@hotmail.com
*******************************************************************/

#include <iostream>
#include <string.h>
 #include<cmath>
using namespace std;
string CodeFrontColor[] = {"39","30","31","32","33","34","35","36","37","90","91","92","93","94","95","96","97"};    
string CodeBackground[] = {"49","40","41","42","43","44","45","46","47","100","101","102","103","104","105","106","107"};
string CodeFormat[] = {"0","1","2","3","4","5","7","8"};

class cFrontColor
{
    public:
    string Default() { return CodeFrontColor[0]; }
    string Black() { return CodeFrontColor[1]; }
    string Red() { return CodeFrontColor[2]; }
    string Green() { return CodeFrontColor[3]; }
    string Yellow() { return CodeFrontColor[4]; }
    string Blue() { return CodeFrontColor[5]; }
    string Magenta() { return CodeFrontColor[6]; }
    string Cyan() { return CodeFrontColor[7]; }
    string LightGray() { return CodeFrontColor[8]; }
    string DarkGray() { return CodeFrontColor[9]; }
    string LightRed() { return CodeFrontColor[10]; }
    string LightGreen() { return CodeFrontColor[11]; }
    string LightYellow() { return CodeFrontColor[12]; }
    string LightBlue() { return CodeFrontColor[13]; }
    string LightMagenta() { return CodeFrontColor[14]; }
    string LightCyan() { return CodeFrontColor[15]; }
    string White() { return CodeFrontColor[16]; }
};
class cBackground 
{
    public:
    string Default() { return CodeBackground[0]; }
    string Black() { return CodeBackground[1]; }
    string Red() { return CodeBackground[2]; }
    string Green() { return CodeBackground[3]; }
    string Yellow() { return CodeBackground[4]; }
    string Blue() { return CodeBackground[5]; }
    string Magenta() { return CodeBackground[6]; }
    string Cyan() { return CodeBackground[7]; }
    string LightGray() { return CodeBackground[8]; }
    string DarkGray() { return CodeBackground[9]; }
    string LightRed() { return CodeBackground[10]; }
    string LightGreen() { return CodeBackground[11]; }
    string LightYellow() { return CodeBackground[12]; }
    string LightBlue() { return CodeBackground[13]; }
    string LightMagenta() { return CodeBackground[14]; }
    string LightCyan() { return CodeBackground[15]; }
    string White() { return CodeBackground[16]; }
};
class cFormatAttribute
{
    public:
    string Default() { return CodeFormat[0]; }
    string Bold() { return CodeFormat[1]; }
    string Dim() { return CodeFormat[2]; }
    string Italics() { return CodeFormat[3]; }
    string Underlined() { return CodeFormat[4]; }
    string Blink() { return CodeFormat[5]; }
    string Reverse() { return CodeFormat[6]; }
    string Hidden() { return CodeFormat[7]; }
};

class Drawing
{
    private:
        int splitcount(string str)
        {
            string deli = ",";
            int n = 0;
            int start = 0;
            int end = str.find(deli);
            while (end != -1) {
                start = end + deli.size();
                end = str.find(deli, start);
                n++;
            }
            return n;
        }
        struct arrWrap {string arr[100];};
        struct arrWrap DrowRow(char strRow[])
        {
            struct arrWrap xRow;
            int nR = 0;
            char *tokenRow = strtok(strRow, ",");
            while (tokenRow != NULL)
            {
                xRow.arr[nR] = tokenRow;
                nR++;
                tokenRow = strtok(NULL, ",");
            }
            return xRow;
        }
        struct arrWrap DrowCol(char strCol[])
        {
            struct arrWrap xCol;
            int nC = 0;
            char *tokenCol = strtok(strCol, ",");
            while (tokenCol != NULL)
            {
                xCol.arr[nC] = tokenCol;
                nC++;
                tokenCol = strtok(NULL, ",");
            }
            return xCol;
        }
    public:
        cFrontColor FrontColor;
        cBackground Background;
        cFormatAttribute FormatAttribute;
        string TextColor(string Text,string FrontColor,string Background,string FormatAttribute)
        {
            return "\x1B[" + FormatAttribute + ";" + Background + ";" +
            FrontColor + "m" + Text + "\033[0m";
        }

        void Column_Chart(char strRow[],char strCol[],string ColumnsColour,string HeadsColor,string ColorBox)
        {
            int cRow = splitcount(strRow);
            int cCol = splitcount(strCol);
            struct arrWrap xRow = DrowRow(strRow);
            struct arrWrap xCol = DrowCol(strCol);
            string s;
            for(int i = 10; i >= 1; i--)
            {
                int x = i * 10;
                (x < 100) ? s = " " + to_string(x) : s = to_string(x);
                cout << "    ";
                cout << TextColor(s,HeadsColor,Background.Default(),FormatAttribute.Default());
                cout << " ";
                cout << TextColor("-",FrontColor.White(),ColorBox,FormatAttribute.Default());
                cout << "----";
                for(int j = 0; j < cCol; j++)
                {
                    int int_Col = stoi(xCol.arr[j]);
                    (int_Col >= x) ? cout << TextColor("----",FrontColor.White(),ColumnsColour,FormatAttribute.Default()) :
                    cout << TextColor("----",FrontColor.Default(),Background.Default(),FormatAttribute.Default()) ;
                    cout << "----"  ;
                }
                int int_Col = stoi(xCol.arr[cCol]);
                (int_Col >= x)  ? cout << TextColor("----",FrontColor.White(),ColumnsColour,FormatAttribute.Default()) << "--" :
                cout << TextColor("------",FrontColor.Default(),Background.Default(),FormatAttribute.Default()) ;
                cout << "\n";
            }
            cout << "        ";
            string UnderLine = "     ";
            for(int j = 0; j <= cCol; j++)
            {
                UnderLine = UnderLine + "        ";
            }
            cout << TextColor(UnderLine,FrontColor.White(),ColorBox,FormatAttribute.Default()) << "\n";
            cout << "             ";
            for(int j = 0; j < cRow; j++)
            {
                string str_Row = xRow.arr[j];
                cout << TextColor(str_Row + " ",HeadsColor,Background.Default(),FormatAttribute.Bold()) << "    "; 
            }
            string str_Row = xRow.arr[cRow];
            cout << TextColor(str_Row + " ",HeadsColor,Background.Default(),FormatAttribute.Bold()) << "\n";   
        }

        void Bar_Chart(char strRow[],char strCol[],string ColumnsColour,string HeadsColor,string ColorBox)
        {
            cout << "    " ;
            int cRow = splitcount(strRow);
            struct arrWrap xRow = DrowRow(strRow);
            struct arrWrap xCol = DrowCol(strCol);

            for(int i = 0; i < cRow; i++)
            {
                cout << TextColor(" ",FrontColor.Black(),ColorBox,FormatAttribute.Default()) << "\n";
                cout << TextColor(xRow.arr[i],HeadsColor,Background.Default(),FormatAttribute.Bold()) << " " ;
                cout << TextColor(" ",FrontColor.Black(),ColorBox,FormatAttribute.Default());
                int dCol = ceil((stod(xCol.arr[i]) / 2) - 1);
                for(int j = 0; j < dCol; j++)
                { cout << TextColor(" ",FrontColor.Black(),ColumnsColour,FormatAttribute.Default()); }
                cout << xCol.arr[i] << "\n    ";
                //cout << "" ;
            }
            cout << TextColor(" ",FrontColor.Black(),ColorBox,FormatAttribute.Default()) ;
            cout << TextColor("_____________________________________________________",to_string((stoi(ColorBox)- 10)) ,Background.Default(),FormatAttribute.Default()) << "\n";
            cout << TextColor("    0   10   20   30   40   50   60   70   80   90   100  ",HeadsColor,Background.Default(),FormatAttribute.Bold()) << "\n";
        }

        void Developer()
        {
            cout << "011111000010110101100010111010110001111110111010011110" << "\n";
            cout << "01100010" << TextColor("[Eng. Mohammad Ali   Tel : 01066568205]",
            FrontColor.Yellow(),Background.Default(),FormatAttribute.Bold()) << "0010010" << "\n";
            cout << "011111000010110101100010111010110001111110111010011110" << "\n";
            cout << "01                   100000110010                   10" << "\n";
            cout << "01  Python       100              0010       C++    10" << "\n";
            cout << "01            00     1101110           11           10" << "\n";
            cout << "01   C#     00    0111100001110111       10    C    10" << "\n";
            cout << "01        01   0000010101101000010111     0         10" << "\n";
            cout << "01  Java  0  001010001011000100101110010   0   PHP  10" << "\n";
            cout << "01        0  110011100100010100100001010   1        10" << "\n";
            cout << "01        1  1000000110011111101000001010   1       10" << "\n";
            cout << "01  HTML  1 0111010110001101001011100001    0  CSS  10" << "\n";
            cout << "01        1             10          0110    0       10" << "\n";
            cout << "01        1             1              0   00       10" << "\n";
            cout << "01  IOS  010           011              0  0    JS  10" << "\n";
            cout << "01       1111         1110              1  0        10" << "\n";
            cout << "01  a   0001100    10 000  01         011  0    s   10" << "\n";
            cout << "01  n   100101010111 11100 11010  0001110  1    t   10" << "\n";
            cout << "01  d   100000010011111101001100111000100 00    u   10" << "\n";
            cout << "01  r   001100100 01001001010 01111000011 110   d   10" << "\n";
            cout << "01  o  001001101                1110110001101   i   10" << "\n";
            cout << "01  i   000000000111         10  1100000 11     o   10" << "\n";
            cout << "01  d   110101 1111110     11110   10000 1          10" << "\n";
            cout << "01      10011010 0         01  0    011 101         10" << "\n";
            cout << "01       01101                      101   10        10" << "\n";
            cout << "01       11111 10100                 0    00        10" << "\n";
            cout << "01        100111000         10      0     0         10" << "\n";
            cout << "01         000000101110101010010  0       0         10" << "\n";
            cout << "01          01111001001011010001     00   01        10" << "\n";
            cout << "01         110101                   101111111111101010" << "\n";
            cout << "01     000000010                   0 01101000000001010" << "\n";
            cout << "01011001011010100                 10110111101001110110" << "\n";
            cout << "010101001 00010010                 1100101100010011110" << "\n";
            cout << "01000011110110000000              00011111100100010010" << "\n";
            cout << "011010001101110100010          00100100000100101110110" << "\n";
            cout << "0100100011101110110010       1001101000111001011010010" << "\n";
            cout << "011000111111100101101110110000111000111010101011010010" << "\n";
            cout << "011101110000100010110101001011010010011011010001100010" << "\n\n";
        }

};

