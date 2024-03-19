#include "stuk.h"

class pawn : public stuk
{
public:
	pawn(color kleur, cord coord);
	bool is_mog_bew(cord coord);

private:
	std::vector<cord> bew_pawn;

};