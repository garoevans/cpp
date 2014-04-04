#include <iostream>
#include <string>

int main()
{
    using namespace std;

    enum eAdservers {
        VANILLA,
        BETA,
        UAT3,
        MAX_ADSERVERS
    };

    struct sAdserver {
        string ip;
        int id;
    };

    sAdserver aAdservers[MAX_ADSERVERS];

    aAdservers[VANILLA].ip = "1.2.3.4";
    aAdservers[VANILLA].id = 1;

    cout << aAdservers[VANILLA].ip;

    return 0;
}
