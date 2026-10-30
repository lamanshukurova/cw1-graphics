#include <nanobench.h>
#include <vmlib/small_matrix.hpp>
#include <string>
#include <cstddef>

template<std::size_t N>
void benchmarkSize(ankerl::nanobench::Bench& b)
{
    SmallMat<N,N,float> A{};

    // Fill the matrix
    for (std::size_t row = 0; row < N; ++row)
    {
        for (std::size_t col = 0; col < N; ++col)
        {
            if (row == col)
                A[row,col] = N + 1;
            else
                A[row,col] = 1.f;
        }
    }

    // Configure benchmark iterations
    if constexpr (N <= 4)
        b.minEpochIterations(700000);
    else if constexpr (N <= 10)
        b.minEpochIterations(40000);
    else if constexpr (N <= 20)
        b.minEpochIterations(5000);
    else if constexpr (N <= 50)
        b.minEpochIterations(250);
    else
        b.minEpochIterations(100);

    // Matrix inversion
    b.run("inversion " + std::to_string(N) + "x" + std::to_string(N), [&] {
        auto result = invert(A);
        ankerl::nanobench::doNotOptimizeAway(result);
    });

    // Matrix multiplication
    b.run("multiplication " + std::to_string(N) + "x" + std::to_string(N), [&] {
        auto result = A * A;
        ankerl::nanobench::doNotOptimizeAway(result);
    });
}

int main()
{
    ankerl::nanobench::Bench b;

    benchmarkSize<4>(b);
    benchmarkSize<10>(b);
    benchmarkSize<20>(b);
    benchmarkSize<50>(b);
    benchmarkSize<100>(b);

    return 0;
}