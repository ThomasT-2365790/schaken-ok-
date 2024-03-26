#include "speler.h"
#include "color.h"
#include "cord.h"
#include "stuk.h"

speler::speler(color kleur_van_speler) : kleur{ kleur_van_speler } {};

void speler::movestuk(cord nu, cord nieuw) {
	spelbord.play(nu, nieuw);

}