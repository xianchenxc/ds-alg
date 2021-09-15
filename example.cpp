#include <iostream>
#include "lib/seqList.h"

using namespace std;

int main()
{
    SeqList<int> stringSeq(2);
    cerr << stringSeq.isEmpty() << endl;
    int a = 1;
    stringSeq.Insert(1, a);
    cout << stringSeq.isEmpty() << endl;
}