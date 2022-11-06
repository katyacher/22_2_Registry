#include <iostream>
#include <map>

int main() {
    std::cout << "22.2 Registry" << std::endl;
    std::string answer;
    std::map<std::string, int> Queue;
    std::map<std::string,int>::iterator it;

    while(true){
        std::cout << "Enter the surname or 'Next' or 'Exit': " << std::endl;
        std::cin >> answer;
        if(answer == "Exit") break;
        if (answer == "Next"){
            if(Queue.begin() == Queue.end()){
                std::cout << "There is no person in the queue." << std::endl;
            } else{
                std::cout << (Queue.begin()->first) << std::endl;
                Queue.begin()->second -= 1;
                if(Queue.begin()->second == 0){
                    it = Queue.begin();
                    Queue.erase(it);
                }
            }
        } else {
            if(Queue.count(answer) > 0){
                Queue[answer] += 1;
            }else {
                Queue.emplace(answer, 1);
            }
        }
    }

    // show queue:
    for (it=Queue.begin(); it!=Queue.end(); ++it)
        std::cout << "Person in the queue:" << std::endl;
        std::cout << it->first << " : " << it->second << std::endl;

    return 0;
}
