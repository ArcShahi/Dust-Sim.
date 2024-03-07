#ifndef CHAOS_H
#define CHAOS_H



#include <random>


std::random_device rd{};
std::seed_seq ss{ rd(),rd(),rd(),rd(),rd(),rd(),rd(),rd(),rd(),rd(),rd(),rd()};
std::mt19937 engine{ ss }; // creating and seeding the PRNG


namespace arc {
	inline  int getRandomi(int min, int max)
	{
		std::uniform_int_distribution<int> range{ min,max };// fixing the range 
		return range(engine);

	}	
	
	


	inline float getRandomf(float min, float max)
	{

		std::uniform_real_distribution<float> range{ min,max };
		return range(engine);

	}


	inline char getRandomC()
	{
		static constexpr char alphabet[]{ "abcdefghlijklmnopqrstuvwxyzABCDEFGHIJKLMOPQRSTUVWXYZ" };

		std::uniform_int_distribution<int> range{ 0,52 };// fixing the range 
		return alphabet[range(engine)];
	}





};
#endif // CHAOS_H
