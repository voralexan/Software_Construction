#pragma once
#include "Figures.h"

const double PI = 3.141592653589793;
class Shape	//абстрактный класс фигуры
{
public:
	virtual TNote * Insert() = 0;
};