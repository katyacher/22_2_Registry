#include <iostream>
#include <map>

int main() {
    std::cout << "22.2 Registry" << std::endl;
    std::string answer;
    std::map<std::string, int> queue_of_people;
    std::map<std::string,int>::iterator it;

    while(true){
        std::cout << "Enter the surname or 'Next' or 'Exit': " << std::endl;
        std::cin >> answer;
        if(answer == "Exit") break;
        if (answer == "Next"){
            if(queue_of_people.empty()){
                std::cout << "There is no person in the queue_of_people." << std::endl;
            } else{
                std::cout << (queue_of_people.begin()->first) << std::endl;
                queue_of_people.begin()->second -= 1;
                if(queue_of_people.begin()->second == 0){
                    it = queue_of_people.begin();
                    queue_of_people.erase(it);
                }
            }
        } else {
            if(queue_of_people.count(answer) > 0){
                queue_of_people[answer] += 1;
            }else {
                queue_of_people.emplace(answer, 1);
            }
        }
    }

    // show queue_of_people:
    for (it=queue_of_people.begin(); it != queue_of_people.end(); ++it)
        std::cout << "Person in the queue_of_people:" << std::endl;
        std::cout << it->first << " : " << it->second << std::endl;

    return 0;
}
