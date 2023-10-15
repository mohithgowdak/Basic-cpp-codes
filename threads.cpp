#include <iostream>
#include <thread>
#include <vector>
#include <numeric>

// Function to calculate the sum of elements in a given range of an array
void sumRange(const std::vector<int>& arr, int low, int high, long long& result) {
    result = std::accumulate(arr.begin() + low, arr.begin() + high, 0LL);
}

int main() {
    // Initialize an array
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Define the number of threads and segments
    int numThreads = 4;
    int segmentSize = arr.size() / numThreads;

    // Create a vector to store the threads and results
    std::vector<std::thread> threads;
    std::vector<long long> results(numThreads);

    // Launch threads to calculate the sum in different segments
    for (int i = 0; i < numThreads; ++i) {
        int low = i * segmentSize;
        int high = (i == numThreads - 1) ? arr.size() : (i + 1) * segmentSize;
        threads.emplace_back(sumRange, std::cref(arr), low, high, std::ref(results[i]));
    }

    // Join the threads
    for (auto& t : threads) {
        t.join();
    }

    // Calculate the final sum
    long long totalSum = std::accumulate(results.begin(), results.end(), 0LL);

    // Print the result
    std::cout << "Sum of elements: " << totalSum << std::endl;

    return 0;
}
