/*******************************************************************
  Design library for drawing colors on the black screen commands Terminal
           using language C++ This library is open source
   Developed by Eng. Mohammad Ali Youssef on Last Update 14-08-2023
    Tel : +20 01066568205  |   Email : ensert.egypt@hotmail.com
*******************************************************************/

#include <iostream>
#include <string.h>
using namespace std;
class cFrontColor
{
    public:
    string Null() { return "0m"; }
    string Black() { return "30m"; }
    string Red() { return "31m"; }
    string Green() { return "32m"; }
    string Yellow() { return "33m"; }
    string Blue() { return "34m"; }
    string Magenta() { return "35m"; }
    string Cyan() { return "36m"; }
    string White() { return "37m"; }
};

class cHeadsColor
{
    public:
    string Null() { return "0m"; }
    string Black() { return "30m"; }
    string Red() { return "31m"; }
    string Green() { return "32m"; }
    string Yellow() { return "33m"; }
    string Blue() { return "34m"; }
    string Magenta() { return "35m"; }
    string Cyan() { return "36m"; }
    string White() { return "37m"; }
};

class cBackground 
{
    public:
    string Null() { return ""; }
    string Black() { return "40;"; }
    string Red() { return "41;"; }
    string Green() { return "42;"; }
    string Yellow() { return "43;"; }
    string Blue() { return "44;"; }
    string Magenta() { return "45;"; }
    string Cyan() { return "46;"; }
    string White() { return "47;"; }
};
class cColumnsColor 
{
    public:
    string Null() { return ""; }
    string Black() { return "40;"; }
    string Red() { return "41;"; }
    string Green() { return "42;"; }
    string Yellow() { return "43;"; }
    string Blue() { return "44;"; }
    string Magenta() { return "45;"; }
    string Cyan() { return "46;"; }
    string White() { return "47;"; }
};

class cColorBox 
{
    public:
    string Null() { return ""; }
    string Black() { return "40;"; }
    string Red() { return "41;"; }
    string Green() { return "42;"; }
    string Yellow() { return "43;"; }
    string Blue() { return "44;"; }
    string Magenta() { return "45;"; }
    string Cyan() { return "46;"; }
    string White() { return "47;"; }
};

class cBold 
{
    public:
    string True() { return "1;"; }
    string False() { return ""; }
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
        cBold Bold;
        cColumnsColor ColumnsColor;
        cHeadsColor HeadsColor;
        cColorBox ColorBox;

        string TextColor(string Text,string FrontColor,string Background,string Bold)
        {
            return "\x1B[" + Bold + Background + 
            FrontColor + Text + "\033[0m";
        }

        void Chart(char strRow[],char strCol[],string ColumnsColour,string HeadsColor,string ColorBox)
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
                cout << TextColor(s,HeadsColor,Background.Null(),Bold.False());
                cout << " ";
                cout << TextColor("-",FrontColor.White(),ColorBox,Bold.False());
                cout << "----";
                for(int j = 0; j < cCol; j++)
                {
                    int int_Col = stoi(xCol.arr[j]);
                    (int_Col >= x) ? cout << TextColor("----",FrontColor.White(),ColumnsColour,Bold.False()) :
                    cout << TextColor("----",FrontColor.Null(),Background.Null(),Bold.False()) ;
                    cout << "----"  ;
                }
                int int_Col = stoi(xCol.arr[cCol]);
                (int_Col >= x)  ? cout << TextColor("----",FrontColor.White(),ColumnsColour,Bold.False()) << "--" :
                cout << TextColor("------",FrontColor.Null(),Background.Null(),Bold.False()) ;
                cout << "\n";
            }
            cout << "        ";
            string UnderLine = "     ";
            for(int j = 0; j <= cCol; j++)
            {
                UnderLine = UnderLine + "        ";
            }
            cout << TextColor(UnderLine,FrontColor.White(),ColorBox,Bold.False()) << "\n";
            cout << "             ";
            for(int j = 0; j < cRow; j++)
            {
                string str_Row = xRow.arr[j];
                cout << TextColor(str_Row + " ",HeadsColor,Background.Null(),Bold.True()) << "    "; 
            }
            string str_Row = xRow.arr[cRow];
            cout << TextColor(str_Row + " ",HeadsColor,Background.Null(),Bold.True()) << "\n";   
        }

        void Developer()
        {
            cout << "011111000010110101100010111010110001111110111010011110" << "\n";
            cout << "01100010" << TextColor("[Eng. Mohammad Ali   Tel : 01066568205]",
            FrontColor.Yellow(),Background.Null(),Bold.True()) << "0010010" << "\n";
            cout << "011111000010110101100010111010110001111110111010011110" << "\n";
            cout << "01                   100000110010                   10" << "\n";
            cout << "01               100              0010              10" << "\n";
            cout << "01            00     1101110           11           10" << "\n";
            cout << "01          00    0111100001110111       10         10" << "\n";
            cout << "01        01   0000010101101000010111     0         10" << "\n";
            cout << "01        0  001010001011000100101110010   0        10" << "\n";
            cout << "01        0  110011100100010100100001010   1        10" << "\n";
            cout << "01        1  1000000110011111101000001010   1       10" << "\n";
            cout << "01        1 0111010110001101001011100001    0       10" << "\n";
            cout << "01        1             10          0110    0       10" << "\n";
            cout << "01        1             1              0   00       10" << "\n";
            cout << "01       010           011              0  0        10" << "\n";
            cout << "01       1111         1110              1  0        10" << "\n";
            cout << "01      0001100    10 000  01         011  0        10" << "\n";
            cout << "01      100101010111 11100 11010  0001110  1        10" << "\n";
            cout << "01      100000010011111101001100111000100 00        10" << "\n";
            cout << "01      001100100 01001001010 01111000011 110       10" << "\n";
            cout << "01     001001101                1110110001101       10" << "\n";
            cout << "01      000000000111         10  1100000 11         10" << "\n";
            cout << "01      110101 1111110     11110   10000 1          10" << "\n";
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
            cout << "011101110000100010110101001011010010011011010001100010";
        }

};

