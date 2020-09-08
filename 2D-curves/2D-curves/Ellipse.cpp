#include "Figures.h"
#include "Ellipse.h"


TNote * Ellipse::Insert()
{
	double S;
	S = PI * a * b;
	TNote *p = new TNote;
	p->area = S;
	return p;
}