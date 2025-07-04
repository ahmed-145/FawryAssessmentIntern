#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Product {
    string name;
    double price;
    int quantity;

    bool isExpirable;
    bool expired;
    bool isShippable;
    double weight;

    Product(string n, double p, int q,
            bool expirable = false, bool expiredFlag = false,
            bool shippable = false, double w = 0.0)
        : name(n), price(p), quantity(q),
          isExpirable(expirable), expired(expiredFlag),
          isShippable(shippable), weight(w) {}
};

struct CartItem {
    int productIndex;
    int quantity;
};

struct Customer {
    string name;
    double balance;
};

class Cart {
private:
    vector<CartItem> items;

public:
    void add(const vector<Product>& products, int productIndex, int qty) {
        const Product& product = products[productIndex];

        if (product.isExpirable && product.expired) {
            cout << "Error: " << product.name << " is expired.\n";
            return;
        }
        if (qty > product.quantity) {
            cout << "Error: Not enough stock for " << product.name << ".\n";
            return;
        }
        items.push_back({productIndex, qty});
    }

    bool isEmpty() const { return items.empty(); }

    const vector<CartItem>& getItems() const {
        return items;
    }
};

class ShippingService {
public:
    static void ship(const vector<pair<string, double>>& shippables) {
        if (shippables.empty()) return;

        cout << "\n** Shipment notice **\n";
        double totalWeight = 0;
        for (const auto& item : shippables) {
            cout << "1x " << item.first << " " << item.second * 1000 << "g\n";
            totalWeight += item.second;
        }
        cout << "Total package weight " << totalWeight << "kg\n";
    }
};

void checkout(Customer& customer, vector<Product>& products, Cart& cart) {
    if (cart.isEmpty()) {
        cout << "Error: Cart is empty.\n";
        return;
    }

    double subtotal = 0;
    double shippingFee = 0;
    vector<pair<string, double>> shippables;

    for (const auto& item : cart.getItems()) {
        Product& product = products[item.productIndex];

        if (product.isExpirable && product.expired) {
            cout << "Error: " << product.name << " is expired.\n";
            return;
        }

        if (item.quantity > product.quantity) {
            cout << "Error: Not enough stock for " << product.name << ".\n";
            return;
        }
    }

    cout << "\n** Checkout receipt **\n";

    for (auto& item : cart.getItems()) {
        Product& product = products[item.productIndex];

        double itemTotal = product.price * item.quantity;
        subtotal += itemTotal;
        product.quantity -= item.quantity;

        cout << item.quantity << "x " << product.name << " " << itemTotal << "\n";

        if (product.isShippable) {
            for (int i = 0; i < item.quantity; ++i) {
                shippables.push_back({product.name, product.weight});
            }
        }
    }

    if (!shippables.empty()) {
        shippingFee = 30;
    }

    double total = subtotal + shippingFee;

    cout << "----------------------\n";
    cout << "Subtotal " << subtotal << "\n";
    cout << "Shipping " << shippingFee << "\n";
    cout << "Amount " << total << "\n";

    if (customer.balance < total) {
        cout << "Error: Insufficient balance.\n";
        return;
    }

    customer.balance -= total;
    cout << "Customer balance after payment: " << customer.balance << "\n";

    ShippingService::ship(shippables);
}

int main() {
    vector<Product> products = {
        Product("Cheese", 100, 5, true, false, true, 0.2),
        Product("Biscuits", 150, 2, true, false, false),
        Product("TV", 300, 3, false, false, true, 7.0),
        Product("Scratch Card", 50, 10, false, false, false)
    };

    Customer ahmed = {"Ahmed", 1000};
    Cart cart;

    cart.add(products, 0, 2); // Cheese
    cart.add(products, 1, 1); // Biscuits
    cart.add(products, 2, 1); // TV
    cart.add(products, 3, 1); // Scratch Card

    checkout(ahmed, products, cart);

    return 0;
}
