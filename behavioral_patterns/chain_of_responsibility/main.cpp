#include <iostream>
#include "Request.h"

int main() {
    JuniorManager junior;
    SeniorManager senior;
    Director director;

    junior.SetNext(&senior);
    senior.SetNext(&director);

    RequestType req1(300);
    RequestType req2(1000);
    RequestType req3(5000);
    RequestType req4(6000);

    junior.ProcessRequest(req1);
    junior.ProcessRequest(req2);
    junior.ProcessRequest(req3);
    junior.ProcessRequest(req4);
   return 0;
}