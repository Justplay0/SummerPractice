#ifndef FILEIN_H
#define FILEIN_H
#include<QObject>
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
class file
{
public:
    file();
    void filein(QString& info);
};

#endif // FILEIN_H
