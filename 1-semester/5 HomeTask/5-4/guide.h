#pragma once

#include <iostream>
#include <fstream>

using namespace std;

struct GuideElement;
struct Guide;

Guide *createGuide();
GuideElement *createGuideElement(char *name, char *phone, GuideElement *next);
void deleteGuide(Guide *guide);


void addItem(Guide *notes);
void searchPhone(Guide *notes);
void searchName(Guide *notes);
void saveData(Guide *notes, char *fileName);
void loadData(Guide *notes, char *fileName);