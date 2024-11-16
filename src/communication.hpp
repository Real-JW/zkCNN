#ifndef COMMUNICATION_HPP
#define COMMUNICATION_HPP

#include "global_var.hpp"
#include "polynomial.h"
#include "prover.hpp"
#include "verifier.hpp"
#include "circuit.h"
#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>

quadratic_poly  comSumcheckUpdate1(prover *p, Fr previousRandom);
quadratic_poly  comSumcheckUpdate2(prover *p, Fr previousRandom);
quadratic_poly  comSumcheckLiuUpdate(prover *p, Fr previousRandom);
cubic_poly      comSumcheckDotProdUpdate1(prover *p, Fr previousRandom);
layeredCircuit  comLayeredCircuit(layeredCircuit C);
quadratic_poly  readPolyFromFile(const std::string& id);


#endif // COMMUNICATION_HPP