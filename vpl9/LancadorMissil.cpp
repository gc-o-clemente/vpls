#include "LancadorMissil.hpp"

LancadorMissil::LancadorMissil(int id, double energia, int misseis)
    : Defesa(id, energia), _misseis(misseis) {}

void LancadorMissil::atacar(double &danoAcumulado) {
    if (_misseis > 0 && _getEnergia() >= 5.0) {
        _consumirEnergia(5.0);
        _misseis--;
        danoAcumulado += 40.0;
    }
}