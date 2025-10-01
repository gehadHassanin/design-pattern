#include <iostream>
#include "sorting.h"

SortContext::SortContext(SortingStrategy* strategy)
    : strategy_(strategy) {}

void SortContext::SetStrategy(SortingStrategy* strategy) {
    strategy_ = strategy;
}

void SortContext::ExecuteStrategy(std::vector<int>& arr) {
    strategy_->Sort(arr);
}

void BubbleSort::Sort(std::vector<int>& arr) {
    std::cout << "Sorting by bubble sort" << std::endl;
}

void QuickSort::Sort(std::vector<int>& arr) {
    std::cout << "Sorting by quick sort" << std::endl;
}