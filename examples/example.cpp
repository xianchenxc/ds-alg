#include <iostream>
#include "../lib/seqList.h"

using namespace std;

int main()
{
  SeqList<string> stringSeq;
  cerr << stringSeq.isEmpty() << endl;
  string a = "hello c++";
  stringSeq.Insert(1, a);
  cerr << stringSeq.isEmpty() << endl;
}