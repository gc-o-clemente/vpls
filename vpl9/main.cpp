#include <iostream>
#include "BaseMilitar.hpp"
#include "Canhao.hpp"
#include "CanhaoOrbital.hpp"
#include "LancadorMissil.hpp"

using namespace std;

int main() {
    BaseMilitar base;
    char comando;

    while (cin >> comando && comando != 's') {
        if (comando == 'c') {
            int id; double e, i; cin >> id >> e >> i;
            base.adicionarDefesa(new Canhao(id, e, i));
        } else if (comando == 'o') {
            int id; double e, i, g; cin >> id >> e >> i >> g;
            base.adicionarDefesa(new CanhaoOrbital(id, e, i, g));
        } else if (comando == 'm') {
            int id, m; double e; cin >> id >> e >> m;
            base.adicionarDefesa(new LancadorMissil(id, e, m));
        } else if (comando == 'd') {
            double vida; cin >> vida;
            base.defender(vida);
        }
    }
    return 0;
}