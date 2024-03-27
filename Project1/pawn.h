#include "Piece.h"

class Pawn : public Piece
{
public:
	Pawn(Color color, Cord cord);
	bool is_pos(Cord _now,Cord _new) override;
	char return_type()  override;

private:

};