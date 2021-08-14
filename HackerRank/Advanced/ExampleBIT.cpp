#include "bits/stdc++.h"
#include <iostream>
#include <iomanip>

using namespace std;
class BIT {
    // Implementation of a Binary Indexed Tree (Fenwick Tree)
private:
        vector<int> m_array;
public:
        BIT(vector<int> list){
            m_array = vector<int>(list.size()+1,0);
            for (int idx = 0; idx < list.size(); idx++){
                    m_array[idx + 1] = list[idx];
            }

            for(int idx = 1; idx < m_array.size(); idx++){
                int idx2 = idx + (idx & -idx);
                if (idx2 < m_array.size()){
                    m_array[idx2] += m_array[idx];
                }
            }
        }

        int prefix_query(int idx) const {
            //Computes prefix sum of up to the element at index idx
            int result = 0;
            for(++idx; idx > 0; idx -= idx & -idx){
                    result += m_array[idx];
            }
            return result;
        }

        int range_query(int from_idx, int to_idx) const {

            if(from_idx == 0)
                return prefix_query(to_idx);
            else
                return prefix_query(to_idx) - prefix_query(from_idx-1);
        }

        void update(int idx, int add){
            for(++idx; idx < m_array.size(); idx += idx & -idx){
                    m_array[idx] += add;
            }
        }
};

void print(BIT const& bit, int length){
    cout << "Index: ";
    for (int idx = 0; idx < length; ++idx){
        cout << setw(2) << idx << " ";
    }
    cout << "\n";
    cout << "Array: ";
    for (int idx = 0; idx < length; ++idx){
        cout << setw(2) << bit.range_query(idx, idx) << " ";
    }
    cout << "\n" << "\n";

    cout << "Prefix sum of first 13 elements: \t" << bit.prefix_query(12) << "\n";
    cout << "Prefix sum of first 7 elements: \t" << bit.prefix_query(6) << "\n";
    cout << "Prefix sum from index 1 to index 5: \t" << bit.range_query(1,5) << "\n"; 
    cout << "\n";
    
}

int main(){
    vector<int> array{1,7,3,0,5,8,3,2,6,2,1,1,4,5};
    int length = array.size();
    BIT bit(array);
    cout << "\n";
    print(bit, length);

    bit.update(4,2);
    cout << "Add 2 to element at index 4" << "\n" << "\n";
    print(bit, length);

    int val = __gcd(1,2);
}