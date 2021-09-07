#include <iostream>
#include <vector>
#include <string>
#include <cmath>

bool primeTest(int test_num)
{
    if (test_num == 0 || test_num == 1)
        return false;
    for (int i = 2; i < int(sqrt(test_num)) + 1; i++)
    {
        if (test_num % i == 0)
            return false;
    }
    return true;
}

bool find(std::vector<int> prime_vec, int target)
{
    for (int i = 0; i < prime_vec.size(); i++)
    {
        if (target == prime_vec[i])
            return true;
    }
    return false;
}

void doit(int& answer, std::vector<int>* prime_vec, std::vector<int> number_vec)
{
    int test_num = 0;
    for (int i = 0; i < number_vec.size(); i++)
    {
        test_num += number_vec[i] * pow(10, i);
    }
    if (primeTest(test_num))
    {
        if (!find(*prime_vec, test_num))
        {
            answer++;
            prime_vec->push_back(test_num);
        }
    }
}

int solution(std::string numbers) {
    int answer = 0;
    std::vector<int> prime_vec;
    std::vector<int> number_vec;

    for (int i = 0; i < numbers.size(); i++)
    {
        number_vec = { numbers[i] - 48 };

        doit(answer, &prime_vec, number_vec);

        if (numbers.size() > 1)
        {
            for (int j = 0; j < numbers.size(); j++)
            {
                if (i == j)
                    continue;

                number_vec.push_back(numbers[j] - 48);

                doit(answer, &prime_vec, number_vec);

                if (numbers.size() > 2)
                {
                    for (int k = 0; k < numbers.size(); k++)
                    {
                        if (k == i || k == j)
                            continue;
                        number_vec.push_back(numbers[k] - 48);

                        doit(answer, &prime_vec, number_vec);

                        if (numbers.size() > 3)
                        {
                            for (int l = 0; l < numbers.size(); l++)
                            {
                                if (l == i || l == j || l == k)
                                    continue;
                                number_vec.push_back(numbers[l] - 48);
                                doit(answer, &prime_vec, number_vec);

                                if (numbers.size() > 4)
                                {
                                    for (int m = 0; m < numbers.size(); m++)
                                    {
                                        if (m == i || m == j || m == k || m == l)
                                            continue;
                                        number_vec.push_back(numbers[m] - 48);
                                        doit(answer, &prime_vec, number_vec);
                                        if (numbers.size() > 5)
                                        {
                                            for (int n = 0; n < numbers.size(); n++)
                                            {
                                                if (n == i || n == j || n == k || n == l || n == m)
                                                    continue;
                                                number_vec.push_back(numbers[n] - 48);
                                                doit(answer, &prime_vec, number_vec);
                                                if (numbers.size() > 6)
                                                {
                                                    for (int o = 0; o < numbers.size(); o++)
                                                    {
                                                        if (o == i || o == j || o == k || o == l || o == m || o == n)
                                                            continue;
                                                        number_vec.push_back(numbers[o] - 48);
                                                        doit(answer, &prime_vec, number_vec);
                                                        number_vec.pop_back();
                                                    }
                                                }
                                                number_vec.pop_back();
                                            }
                                        }
                                        number_vec.pop_back();
                                    }
                                }
                                number_vec.pop_back();
                            }
                        }
                        number_vec.pop_back();
                    }
                }
                number_vec.pop_back();
            }
        }
    }
    return answer;
}

int main() {

    std::string numbers = "361";
    int answer = solution(numbers);

    std::cout << "answer : " << answer << std::endl;
    
	return 0;
}