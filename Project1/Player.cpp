#include "speler.h"
#include "color.h"
#include "cord.h"
#include "stuk.h"

Player::Player(Color kleur_van_speler) : kleur{ kleur_van_speler } {};

void Speler::movestuk(Cord nu, Cord nieuw) {
	spelbord.play(nu, nieuw);

}