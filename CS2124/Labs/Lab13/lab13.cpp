// rec13_test.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <vector>      // task 1
#include <list>        // task 2
#include <algorithm>   // task 3
#include <set>         // task 20
#include <map>         // task 22
using namespace std;

//Task 9
//void printList(const list<int>& l){
//    for (list<int>::iterator iter = l.begin(); iter!=l.end(); iter++){
//        cout << *iter << " ";
//    }
//}
void printListNine(const list<int>& l){
    for (list<int>::const_iterator iter = l.begin(); iter!=l.end(); iter++){
        cout << *iter << " ";
    }
    cout << endl;
}

//Task 10
void printListTen(const list<int>& l){
    for (int i : l){
        cout << i << " ";
    }
    cout << endl;
}

//Task 11
void printListEleven(const list<int>& l){
    for (auto iter = l.begin(); iter!=l.end(); iter++){
        cout << *iter << " ";
        iter++;
    }
    cout << endl;
}

//Task 12
list<int>::const_iterator find(const list<int>& l, int num){
    for (list<int>::const_iterator iter = l.begin(); iter!=l.end(); iter++){
        if (*iter == num){
            return iter;
        }
    }
    return l.end();
}

//Task 13
auto findAuto(const list<int>& l, int num){
    for (auto iter = l.begin(); iter!=l.end(); iter++){
        if (*iter == num){
            return iter;
        }
    }
    return l.end();
}

//Task 15
bool isEven(int n) { return n % 2 == 0; }

//Task 16
class IsEven{
public:
    bool operator() (int n) {return n % 2 == 0;}
};

//Task 19
list<int>::iterator ourFind(list<int>::iterator start, list<int>::iterator end, int target){
    cout << "Using ourFind" << endl;
    while (start != end){
        if (*start == target){
            return start;
        }
        ++start;
    }
    return end;
}

//Task 20
template <typename T, typename S>
T ourFind(T start, T end, S target){
    cout << "Using ourFind Template" << endl;
    while (start != end){
        if (*start == target){
            return start;
        }
        ++start;
    }
    return end;
}

int main() {
    // 1. Create a vector with some values and display using ranged for
    cout << "Task 1:\n";
    vector<int> v({8, 7, 6, 5, 4, 3, 2, 1});
    for (int i: v){
        cout << i << " ";
    }
    cout << "\n=======\n";
    
    // 2. Initalize a list as a copy of values from the vector
    cout << "Task 2:\n";
    list<int> l(v.begin(), v.end());
    for (int i : l){
        cout << i << " ";
    }
    cout << "\n=======\n";
    
    // 3. Sort the original vector.  Display both the vector and the list
    cout << "Task 3:\n";
    sort(v.begin(), v.end());
    for (int i: v){
        cout << i << " ";
    }
    cout << endl;
    for (int i : l){
        cout << i << " ";
    }
    cout << "\n=======\n";
    
    // 4. print every other element of the vector.
    cout << "Task 4:\n";
    for (size_t i = 0; i < v.size(); i+=2){
        cout << v[i] << " ";
    }
    cout << "\n=======\n";
    
    // 5. Attempt to print every other element of the list using the
    //    same technique.
    cout << "Task 5:\n";
//    for (size_t i = 0; i < l.size(); i+=2){
//        cout << l[i] << " ";
//    }
    cout << "\n=======\n";
    
    //
    // Iterators
    //
    
    // 6. Repeat task 4 using iterators.  Do not use auto;
    cout << "Task 6:\n";
    for (vector<int>::iterator iter = v.begin(); iter!=v.end(); iter+=2){
        cout << *iter << " ";
    }
    cout << "\n=======\n";
    
    // 7. Repeat the previous task using the list.  Again, do not use auto.
    //    Note that you cannot use the same simple mechanism to bump
    //    the iterator as in task 6.
    cout << "Task 7:\n";
    for (list<int>::iterator iter = l.begin(); iter!=l.end(); iter++){
        cout << *iter << " ";
        iter++;
    }
    cout << "\n=======\n";
    
    // 8. Sorting a list
    cout << "Task 8:\n";
    l.sort();
    for (int i : l){
        cout << i << " ";
    }
    cout << "\n=======\n";
    
    // 9. Calling the function to print the list
    cout << "Task 9:\n";
    printListNine(l);
    cout << "=======\n";
    
    // 10. Calling the function that prints the list, using ranged-for
    cout << "Task 10:\n";
    printListTen(l);
    cout << "=======\n";
    
    //
    // Auto
    //
    
    // 11. Calling the function that, using auto, prints alterate
    // items in the list
    cout << "Task 11:\n";
    printListEleven(l);
    cout << "=======\n";
    
    
    // 12.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 12:\n";
    if (find(l, 1) != l.end()){
        cout << "Found " << *find(l, 1) << endl;
    }
    else{
        cout << "Not Found";
    }
    if (find(l, 100) != l.end()){
        cout << "Found " << *find(l, 1) << endl;
    }
    else{
        cout << "Not Found" << endl;
    }
    cout << "=======\n";
    
    // 13.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 13:\n";
    if (findAuto(l, 1) != l.end()){
        cout << "Found " << *findAuto(l, 1) << endl;
    }
    else{
        cout << "Not Found" << endl;
    }
    if (findAuto(l, 100) != l.end()){
        cout << "Found " << *findAuto(l, 100) << endl;
    }
    else{
        cout << "Not Found" << endl;
    }
    cout << "=======\n";
    
    //
    // Generic Algorithms
    //
    
    // 14. Generic algorithms: find
    cout << "Task 14:\n";
    list<int>::iterator whereIs1= find(l.begin(), l.end(), 1);
    if (whereIs1 != l.end()){
        cout << "Found " << *whereIs1 << endl;
    }
    else{
        cout << "Not Found" << endl;
    }
    list<int>::iterator whereIs100 = find(l.begin(), l.end(), 100);
    if (whereIs100 != l.end()){
        cout << "Found " << *whereIs100 << endl;
    }
    else{
        cout << "Not Found" << endl;
    }
    cout << "=======\n";
    
    // 15. Generic algorithms: find_if
    cout << "Task 15:\n";
    cout << *find_if(v.begin(), v.end(), isEven) << endl;
    cout << *find_if(l.begin(), l.end(), isEven) << endl;
    cout << "=======\n";
    
    // 16. Functor
    cout << "Task 16:\n";
    IsEven isEvenFunctor;
    cout << *find_if(v.begin(), v.end(), isEvenFunctor) << endl;
    cout << *find_if(l.begin(), l.end(), isEvenFunctor) << endl;
    cout << "=======\n";
    
    // 17. Lambda
    cout << "Task 17:\n";
    [] { cout << "Hello Lambda!"; }();
    [] (int a, int b) { cout << a + b << endl; } (4, 5);
    cout << *find_if(v.begin(), v.end(), [](int n) {return n % 2 == 0;}) << endl;
    cout << *find_if(l.begin(), l.end(), [](int n) {return n % 2 == 0;}) << endl;
    cout << "=======\n";
    
    // 18. Generic algorithms: copy to an array
    cout << "Task 18:\n";
    int arr[8];
    copy(v.begin(), v.end(), arr);
    for (int i : arr){
        cout << i << " ";
    }
    cout << endl;
    cout << "=======\n";
    
    //
    // Templated Functions
    //
    
    // 19. Implement find as a function for lists
    cout << "Task 19:\n";
    list<int>::iterator whereIs3= ourFind(l.begin(), l.end(), 3);
    if (whereIs3 != l.end()){
        cout << "Found " << *whereIs3 << endl;
    }
    else{
        cout << "Not Found" << endl;
    }
    list<int>::iterator whereIs20= ourFind(l.begin(), l.end(), 20);
    if (whereIs20 != l.end()){
        cout << "Found " << *whereIs20 << endl;
    }
    else{
        cout << "Not Found" << endl;
    }
    cout << "=======\n";
    
    // 20. Implement find as a templated function
    cout << "Task 20:\n";
    vector<int>::iterator whereIs5= ourFind(v.begin(), v.end(), 5);
    if (whereIs5 != v.end()){
        cout << "Found " << *whereIs3 << endl;
    }
    else{
        cout << "Not Found" << endl;
    }
    vector<int>::iterator whereIs50= ourFind(v.begin(), v.end(), 50);
    if (whereIs50 != v.end()){
        cout << "Found " << *whereIs50 << endl;
    }
    else{
        cout << "Not Found" << endl;
    }
    cout << "=======\n";
    
    //
    // Associative collections
    //
    
    // 21. Using a vector of strings, print a line showing
    cout << "Task 21:\n";
    vector<string> words;
    ifstream ifs;
    ifs.open("pooh-nopunc.txt");
    if (!ifs){
        cerr << "Not Open" << endl;
    }
    string word;
    while (ifs >> word){
        if (find(words.begin(), words.end(), word) == words.end()){
            words.push_back(word);
        }
    }
    cout << "Size: " << words.size() << endl;
    for (string& word : words){
        cout << word << " ";
    }
    ifs.close();
    cout << "\n=======\n";
    
    // 22. Repeating previous step, but using the set
    cout << "Task 22:\n";
    set<string> wordsSet;
    ifs.open("pooh-nopunc.txt");
    while (ifs >> word){
        wordsSet.insert(word);
    }
    cout << "Size: " << wordsSet.size() << endl;
    for (string const& w : wordsSet)
    {
        cout << w << " ";
    }
    ifs.close();
    cout << "=======\n";
    
    // 23. Word co-occurence using map
    cout << "Task 23:\n";
    map<string, vector<int>> wordMap;
    ifs.open("pooh-nopunc.txt");
    int position = 0;
    while (ifs >> word){
        wordMap[word].push_back(position);
        ++position;
    }
    for (auto pair : wordMap){
        cout << pair.first << ": ";
        for (int num : pair.second){
            cout << num << " ";
        }
        cout << endl;
    }
    ifs.close();
    cout << "=======\n";
}

