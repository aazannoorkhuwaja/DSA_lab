#include<iostream>
#include<cstdlib>
#include<ctime>
#include<climits>

using namespace std;

class stock {
public:
    int* inventry;
    int size;
    int avg;
    int top_seller = 0;
    int count = 0;

    stock() {
        cout << "Welcome to Stocks inventory\nEnter the size of inventory: ";
        cin >> size;
        inventry = new int[size];

        
        srand(time(0));
        rand_numbers_for_inventry(); 
    }

    void rand_numbers_for_inventry() {
        cout << "Now assigning random quantities of products in inventory...\n";
        for (int i = 0; i < size; i++) {
            *(inventry + i) = rand() % 100 + 1;
        }
        cout << "Inventory initialized: ";
        for (int i = 0; i < size; i++) {
            cout << *(inventry + i) << " ";
        }
        cout << endl;
    }

    int avg_stock_l() {
        int temp = 0;
        for (int i = 0; i < size; i++) {
            temp += *(inventry + i);
        }
        avg = temp / size;
        return avg;
    }

    int critical_products() {
        for (int i = 0; i < size; i++) {
            if (*(inventry + i) < avg) {
                count++;
            }
        }
        return count;
    }

    int find_top_selling_one() {
        int max_val = INT_MIN;
        for (int i = 0; i < size; i++) {
            if (*(inventry + i) > max_val) {
                max_val = *(inventry + i);
            }
        }
        return max_val;
    }

    int find_sec_most() {
        int largest = INT_MIN, second_largest = INT_MIN;
        for (int i = 0; i < size; i++) {
            int val = *(inventry + i);
            if (val > largest) {
                second_largest = largest;
                largest = val;
            }
            else if (val > second_largest && val != largest) {
                second_largest = val;
            }
        }
        return second_largest;
    }

    void sort_by_popularity() {
        int temp;
        
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (*(inventry + j) < *(inventry + j + 1)) {
                    temp = *(inventry + j);
                    *(inventry + j) = *(inventry + j + 1);
                    *(inventry + j + 1) = temp;
                }
            }
        }

        cout << "The sorted inventory by popularity (descending): ";
        for (int i = 0; i < size; i++) {
            cout << *(inventry + i) << ", ";
        }
        cout << endl;
    }

    ~stock() {
        delete[] inventry;
    }
};

int main() {
    stock s;

    cout << "Average stock of inventory is: " << s.avg_stock_l() << endl;
    cout << "Total critical products are: " << s.critical_products() << endl;
    cout << "The Top Selling Product Quantity is: " << s.find_top_selling_one() << endl;
    cout << "The Second Top Selling Product Quantity is: " << s.find_sec_most() << endl;
    s.sort_by_popularity();

    return 0;
}
