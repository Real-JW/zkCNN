#include "communication.hpp"
#include <filesystem>

int id = 1;

void saveCubicPolyToFile(int id, cubic_poly poly) {
    std::filesystem::create_directories("communicationLog");
    std::ofstream outFile("communicationLog/" + std::to_string(id) + "_CubicPoly.bin", std::ios::binary);
    if (outFile.is_open()) {
        outFile.write(reinterpret_cast<const char*>(&poly), sizeof(cubic_poly));
        outFile.close();
    } else {
        std::cerr << "Unable to open file for writing: " << id << std::endl;
    }
}

cubic_poly readCubicPolyFromFile(int id) {
    cubic_poly poly;
    std::ifstream inFile("communicationLog/" + std::to_string(id) + "_CubicPoly.bin", std::ios::binary);
    if (inFile.is_open()) {
        inFile.read(reinterpret_cast<char*>(&poly), sizeof(cubic_poly));
        inFile.close();
    } else {
        std::cerr << "Unable to open file for reading: " << id << std::endl;
    }
    return poly;
}

void saveQuadPolyToFile(int id, quadratic_poly poly) {
    std::filesystem::create_directories("communicationLog");
    std::ofstream outFile("communicationLog/" + std::to_string(id) + "_QuadPoly.bin", std::ios::binary);
    if (outFile.is_open()) {
        outFile.write(reinterpret_cast<const char*>(&poly), sizeof(quadratic_poly));
        outFile.close();
    } else {
        std::cerr << "Unable to open file for writing: " << id << std::endl;
    }
}

quadratic_poly readQuadPolyFromFile(int id) {
    quadratic_poly poly;
    std::ifstream inFile("communicationLog/" + std::to_string(id) + "_QuadPoly.bin", std::ios::binary);
    if (inFile.is_open()) {
        inFile.read(reinterpret_cast<char*>(&poly), sizeof(quadratic_poly));
        inFile.close();
    } else {
        std::cerr << "Unable to open file for reading: " << id << std::endl;
    }
    return poly;
}

void saveFrToFile(int id, const Fr& previousRandom) {
    std::filesystem::create_directories("communicationLog");
    std::ofstream outFile("communicationLog/" + std::to_string(id) + "_Fr.bin", std::ios::binary);
    if (outFile.is_open()) {
        outFile.write(reinterpret_cast<const char*>(&previousRandom), sizeof(Fr));
        outFile.close();
    } else {
        std::cerr << "Unable to open file for writing: " << id << std::endl;
    }
}

Fr readFrFromFile(int id) {
    Fr previousRandom;
    std::ifstream inFile("communicationLog/" + std::to_string(id) + "_Fr.bin", std::ios::binary);
    if (inFile.is_open()) {
        inFile.read(reinterpret_cast<char*>(&previousRandom), sizeof(Fr));
        inFile.close();
    } else {
        std::cerr << "Unable to open file for reading: " << id << std::endl;
    }
    return previousRandom;
}

quadratic_poly comSumcheckUpdate1(prover *p, Fr previousRandom) {
    saveFrToFile(id, previousRandom);
    previousRandom = readFrFromFile(id);
    quadratic_poly poly = p->sumcheckUpdate1(previousRandom);
    saveQuadPolyToFile(id, poly);
    poly = readQuadPolyFromFile(id);
    id++;
    return poly;
}

quadratic_poly comSumcheckUpdate2(prover *p, Fr previousRandom) {
    saveFrToFile(id, previousRandom);
    previousRandom = readFrFromFile(id);
    quadratic_poly poly = p->sumcheckUpdate2(previousRandom);
    saveQuadPolyToFile(id, poly);
    poly = readQuadPolyFromFile(id);
    id++;
    return poly;
}

quadratic_poly comSumcheckLiuUpdate(prover *p, Fr previousRandom) {
    saveFrToFile(id, previousRandom);
    previousRandom = readFrFromFile(id);
    quadratic_poly poly = p->sumcheckLiuUpdate(previousRandom);
    saveQuadPolyToFile(id, poly);
    poly = readQuadPolyFromFile(id);
    id++;
    return poly;
}

cubic_poly comSumcheckDotProdUpdate1(prover *p, Fr previousRandom){
    saveFrToFile(id, previousRandom);
    previousRandom = readFrFromFile(id);
    cubic_poly poly = p->sumcheckDotProdUpdate1(previousRandom);
    saveCubicPolyToFile(id, poly);
    poly = readCubicPolyFromFile(id);
    id++;
    return poly;
};

layeredCircuit  comLayeredCircuit(layeredCircuit C) {
    std::filesystem::create_directories("communicationLog");
    std::ofstream outFile("communicationLog/layeredCircuit.bin", std::ios::binary);
    if (outFile.is_open()) {
        outFile.write(reinterpret_cast<const char*>(&C), sizeof(layeredCircuit));
        outFile.close();
    } else {
        std::cerr << "Unable to open file for writing: layeredCircuit" << std::endl;
    }
    return C;
}