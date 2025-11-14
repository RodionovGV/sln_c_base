// pj_dbg_lib.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"

extern "C"{
    #include "logModule.h"
}

// TODO: This is an example of a library function
void fnpjdbglib()
{

}

int main() {
    LOG_INIT("Xample");

    LOG_DESTROY();
    return 0;
}
