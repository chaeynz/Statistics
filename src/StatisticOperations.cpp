#include "StatisticOperations.hpp"

long double getMedian(std::unique_ptr<std::vector<long double>> numbers) {
	std::sort(numbers->begin(), numbers->end());
	if (numbers->size() % 2 == 1) {
		return (*numbers)[numbers->size() / 2];
	}
	else {
		std::vector<long double> numbers_middle = { (*numbers)[(numbers->size() - 1) / 2], (*numbers)[numbers->size() / 2] };
		return getAverage(std::make_unique<std::vector<long double>>(numbers_middle));
	}
	
}

long double getAverage(std::unique_ptr<std::vector<long double>> numbers) {
	long double sum = 0;
	for (int i = 0; i < numbers->size(); ++i) {
		sum = sum + (*numbers)[i];
	}
	return sum / numbers->size();
}