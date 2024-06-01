#include <iostream>
#include <string>
#include <unordered_map>

struct Product {
    std::string name;
    int quantity;
};

std::unordered_map<int, Product> inventory;

void addProduct(int id, const std::string& name, int quantity) {
    if (inventory.find(id) == inventory.end()) {
        Product newProduct = {name, quantity};
        inventory[id] = newProduct;
        std::cout << "Product with ID " << id << " added successfully." << std::endl;
    } else {
        std::cout << "Product with ID " << id << " already exists." << std::endl;
    }
}

void removeProduct(int id) {
    if (inventory.find(id) != inventory.end()) {
        inventory.erase(id);
        std::cout << "Product with ID " << id << " removed successfully." << std::endl;
    } else {
        std::cout << "Product with ID " << id << " not found." << std::endl;
    }
}

int main() {
    addProduct(1, "Laptop", 10);
    addProduct(2, "Smartphone", 15);
    
    removeProduct(1);
    removeProduct(3); // Trying to remove a nonexistent product
    
    return 0;
}
