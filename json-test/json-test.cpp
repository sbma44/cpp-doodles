#include "boost/property_tree/ptree.hpp"
#include "boost/property_tree/json_parser.hpp"

using boost::property_tree::ptree;

void walk(ptree *pt, int level=0) {
    for (auto &el: *pt) {

        // indent
        for(int i = 0; i < level; i++) {
            std::cout << " ";
        }

        std::cout << el.first;

        if (el.second.empty()) {
            std::cout << " " << el.second.get_value<std::string>() << std::endl;
        }
        else {
            std::cout << std::endl;
            walk(&(el.second), ++level);
        }

    }
}

int main() {
    ptree *pt = new ptree();
    read_json(std::cin, *pt);
    walk(pt, 0);
    
    return 0;
}
