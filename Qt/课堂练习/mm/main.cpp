#include "exampleA.h"
#include "exampleB.h"
int main(){
    CExampleA   a;
    CExampleB   b;
    QObject::connect(&a, SIGNAL(stateChanged(int)),
                               &b, SLOT(Function(int)));
    a.SetValue(100);
    return 0;
}
