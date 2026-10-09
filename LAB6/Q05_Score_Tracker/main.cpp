#include <iostream>
using namespace std;

class Score {
    private:
        int score;

    public:
        Score(int s = 0) : score(s) {}

        Score& operator++() {        // prefix: increment, then return new value
            ++score;
            return *this;
        }

        Score operator++(int) {      //? postfix: return old value, then increment
            Score temp = *this;
            ++score;
            return temp;
        }

        int getScore() const { return score; }

        void display() const {
            cout << score;
        }
};

int main() {
    Score s1(10), pre;
    pre = ++s1;
    cout << "Prefix Increment (++s1):" << endl;
    cout << "s1 = "; s1.display();
    cout << ", pre = "; pre.display();
    cout << endl;

    Score s2(10), post;
    post = s2++;
    cout << "\nPostfix Increment (s2++):" << endl;
    cout << "s2 = "; s2.display();
    cout << ", post = "; post.display();
    cout << endl;

    return 0;
}
