#include "stuk.h"
#include "color.h"
#include "cord.h"
#include <vector>

class pawn :public stuk
{
public:
	pawn(color kleur, cord coord);
	bool is_mog_bew(cord coord);

private:
	std::vector<cord> mog_bew;

};