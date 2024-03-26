#include "Piece.h"

class Pawn : public Piece
{
public:
	Pawn(Color color, Cord cord);
	bool is_pos(Cord _now,Cord _new);
	void print_type() const override;

private:

};