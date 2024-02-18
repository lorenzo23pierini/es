#include "particle.hpp"

int main()
{
    Particle e, mu, K;
    
    e.setName("Electron");
    e.setMass(0.5);
    e.setCharge(-1);
    e.setType("Fermion");
    e.setSpin(0.5);

    mu.setName("Muon");
    mu.setMass(105658389);
    mu.setCharge(-1);
    mu.setType("Fermion");
    mu.setSpin(0.5);

    K.setName("Kaon+");
    K.setMass(493677000);
    K.setCharge(1);
    K.setType("Boson");
    K.setSpin(1);
    
    e.print();
    mu.print();
    K.print();
    
    return 0;
}