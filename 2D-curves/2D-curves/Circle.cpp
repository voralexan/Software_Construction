#include "Figures.h"
#include "Circle.h"

TNote * Circle::Insert()
{
	double S;
	S = PI * radius * radius;
	TNote *p = new TNote;
	p->area = S;
	return p;
}
