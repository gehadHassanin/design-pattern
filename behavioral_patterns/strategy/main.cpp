#include <memory>
#include "sorting.h"

int main() {
    std::unique_ptr<SortingStrategy> strategy = 
    std::make_unique<BubbleSort>();
    std::vector<int> arr = {1, 2, 3, 4};
    SortContext context(strategy.get());
    context.ExecuteStrategy(arr);
    strategy = std::make_unique<QuickSort>();
    context.SetStrategy(strategy.get());
    context.ExecuteStrategy(arr);
    return 0;
}