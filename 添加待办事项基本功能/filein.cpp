#include "filein.h"

file::file()
{

}
void file::filein(QString& game) {
    ofstream outfile("data.txt", ios::app);
    if (outfile.is_open()) {
        ifstream infile("data.txt");
        }


        outfile << game.allstep << endl;

        outfile.close();
    }
    else {
        cout << "文件无法打开！" << endl;
    }
