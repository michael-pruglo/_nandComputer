#ifndef NANDCOMPUTER_INPUTGENERATOR_HPP
#define NANDCOMPUTER_INPUTGENERATOR_HPP

#include <random>
#include <src/hardware/Hardware.hpp>

static std::mt19937 rng = std::mt19937(std::random_device()());
static std::uniform_int_distribution<Hardware::Bus32> uniformBus32Distribution;
static std::uniform_int_distribution<Hardware::Bus16> uniformBus16Distribution;
static std::uniform_int_distribution<Hardware::Bus8>  uniformBus8Distribution;
static std::uniform_int_distribution<>                uniformBoolDistribution(0,1);

inline Hardware::Bus32 generateBus32() { return uniformBus32Distribution(rng); }
inline Hardware::Bus16 generateBus16() { return uniformBus16Distribution(rng); }
inline Hardware::Bus8  generateBus8()  { return uniformBus8Distribution(rng); }
inline bool            generateBool()  { return uniformBoolDistribution(rng); }

#endif //NANDCOMPUTER_INPUTGENERATOR_HPP
