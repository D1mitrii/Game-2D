//
// Created by Dmitriy on 10/10/2022.
//

#ifndef OOP_RNGENERATOR_H
#define OOP_RNGENERATOR_H

#include <random>

class RNGenerator {
public:
    RNGenerator();
    RNGenerator(int64_t s);
    RNGenerator(const RNGenerator& rng) = delete;
    RNGenerator& operator=(const RNGenerator& rng) = delete;
    int64_t get_seed() const;

    template<typename R, typename I>
    R get_random_value(I& distr){
        return distr(rang_gen);
    }
    
    ~RNGenerator() = default;
private:
    std::mt19937 rang_gen;
    int64_t seed;
};


#endif //OOP_RNGENERATOR_H
