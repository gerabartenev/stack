#include <iostream>
#include "cstack.h"

using namespace std;

int main(int argc, char *argv[])
{
    cstack<int> st;
    for (int i = 0; i < 10; i++) st.push(i);
    cout << "Hello World!" << endl;
    while (st.size() > 0)
    {
        int out = st.pop();
        cout << out << " ";
    }
    return 0;
}
