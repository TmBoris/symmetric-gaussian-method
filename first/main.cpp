#include <iostream>
#include <vector>


int main() {
    std::vector<std::vector<double>> v;
    size_t a;
    std::cin >> a;
    v.resize(a);
    for (size_t i = 0; i < a; ++i) {
        v[i].resize(a);
        for (size_t j = 0; j < a; ++j) {
            double tmp;
            std::cin >> tmp;
            v[i][j] = tmp;
        }
    }
    size_t i = 0;
    size_t counter;
    while (i < a + 1) {
        counter = 0;
        for (size_t x = i; x < a; ++x) {
            if (v[x][i] != 0) {
                counter++;
            }
        }
        if (counter != 0) {
            if (v[i][i] != 0) {
                double coef;
                for (size_t q = i + 1; q < a; ++q) {
                    coef = v[q][i] / v[i][i];
                    for (size_t w = i; w < a; ++w) {
                        v[q][w] -= (v[i][w] * coef);

                    }
                }
                for (size_t q = i + 1; q < a; ++q) {
                    coef = v[i][q] / v[i][i];
                    for (size_t w = i; w < a; ++w) {
                        v[w][q] -= v[w][i] * coef;
                    }
                }
            } else {
                size_t coun = 0;
                size_t p = i;
                for (; p < a; ++p) {
                    if (v[p][p] != 0) {
                        coun++;
                        break;
                    }
                }
                if (coun == 0) {
                    p = i;
                    for (; p < a; ++p) {
                        if (v[p][i] != 0) {
                            break;
                        }
                    }
                    for (size_t q = i; q < a; ++q) {
                        v[i][q] += v[p][q];
                    }
                    for (size_t q = i; q < a; ++q) {
                        v[q][i] += v[q][p];
                    }
                    double coef;
                    for (size_t q = i + 1; q < a; ++q) {
                        coef = v[q][i] / v[i][i];
                        for (size_t w = i; w < a; ++w) {
                            v[q][w] -= (v[i][w] * coef);

                        }
                    }
                    for (size_t q = i + 1; q < a; ++q) {
                        coef = v[i][q] / v[i][i];
                        for (size_t w = i; w < a; ++w) {
                            v[w][q] -= v[w][i] * coef;
                        }
                    }
                } else {
                    for (size_t q = 0; q < a; ++q) {
                        std::swap(v[q][p], v[q][i]);
                    }
                    for (size_t q = 0; q < a; ++q) {
                        std::swap(v[p][q], v[i][q]);
                    }
                    double coef;
                    for (size_t q = i + 1; q < a; ++q) {
                        coef = v[q][i] / v[i][i];
                        for (size_t w = i; w < a; ++w) {
                            v[q][w] -= (v[i][w] * coef);

                        }
                    }
                    for (size_t q = i + 1; q < a; ++q) {
                        coef = v[i][q] / v[i][i];
                        for (size_t w = i; w < a; ++w) {
                            v[w][q] -= v[w][i] * coef;
                        }
                    }
                }
            }
        }
        for (size_t q = 0; q < a; ++q) {
            for (size_t w = 0; w < a; ++w) {
                std::cout << v[q][w] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "---------" << std::endl;
        i++;
    }
    for (size_t q = 0; q < a; ++q) {
        for (size_t w = 0; w < a; ++w) {
            std::cout << v[q][w] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}