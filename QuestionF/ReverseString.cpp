/*#include <string>
void reverseString(std::string s) {
int left = 0;
int right = s.size();
while (left < right) {
char temp = s[left];
s[left] = s[right];
s[right] = temp;
left++;
right--;
}
}
The above code is given has some bugs has informed in the question.
a)
Bug 1 is that input value is passed by value which means the origibal is string is not modified and so calling by reference is better  i.e, std::string& s
Bug 2 is that right is initialized to s.size() which throws an error which accesses invalid index.This works only when first index starts from 1
Bug 3 is accessing the string in line s[right] which is out of bounds or index due to right=s.size()

b)
Passing by value is inefficient because it will create a copy of the string before the function executes whcih leads memory and time.Passing by references overcomes the making copy and makinf original  string modified directly.

c)
The scenario where the function might fail is that if the string is empty the right pointer point to -1 which creates an incorrect behaviour.This can be fixed by adding 
if string is empty
return;

The corrected code is given below*/

void reverseString(std::string& s) {
    if (s.empty()) {
        return;
    }
    int left = 0;
    int right = s.size() - 1; // Corrected to s.size() - 1
    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

