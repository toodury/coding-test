#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

bool solution(std:: vector<std::string> phone_book) {
    std::unordered_map<std::string, bool> phone_book_map;

    for (int i = 0; i < phone_book.size(); i++)
    {
        phone_book_map.insert(std::make_pair(phone_book[i], true));
    }
    for (int i = 0; i < phone_book.size(); i++)
    {
        for (int j = 1; j < phone_book[i].length(); j++)
        {
            if (phone_book_map.find(phone_book[i].substr(0, j)) != phone_book_map.end())
                return false;
        }
    }
    return true;
}

int main() {

    std::vector<std::string> phone_book1 = { "119", "97674223", "1195524421" };
    std::vector<std::string> phone_book2 = { "123","456","789" };
    std::vector<std::string> phone_book3 = { "12","123","1235","567","88" };
    bool solution1 = solution(phone_book1);
    bool solution2 = solution(phone_book2);
    bool solution3 = solution(phone_book3);

    std::cout << "solution1 : " << solution1 << std::endl
        << "solution2 : " << solution2 << std::endl
        << "solution3 : " << solution3 << std::endl;


	return 0;
}