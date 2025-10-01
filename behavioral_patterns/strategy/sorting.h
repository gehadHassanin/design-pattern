#ifndef STRATEGY_SORTING_H_
#define STRATEGY_SORTING_H_

#include <vector>

class SortingStrategy {
 public:
    virtual void Sort(std::vector<int>& arr) = 0;
};

class SortContext {
 public:
    SortContext(SortingStrategy* strategy);
    void SetStrategy(SortingStrategy* strategy);
    void ExecuteStrategy(std::vector<int>& arr);
 private:
    SortingStrategy* strategy_;
};

class BubbleSort : public SortingStrategy {
 public:
   void Sort(std::vector<int>& arr) override; 
};


class QuickSort : public SortingStrategy {
 public:
   void Sort(std::vector<int>& arr) override; 
};

#endif  //  STRATEGY_SORTING_H_