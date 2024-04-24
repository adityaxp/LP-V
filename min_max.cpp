#pragma omp parallel for reduction(min: min_value)
#pragma omp parallel for reduction(max: max_value)
#pragma omp parallel for reduction(+: sum)