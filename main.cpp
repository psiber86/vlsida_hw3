#include <iostream>
#include <ctime>
#include <cmath>
#include <cstring>

int main(int argc, char* argv[])
{
    time_t t0 = time(NULL);
    bool debug = false;
    int cubeCount = 0;
    int numVars, numCubes = 0;
    char *cubeStr = NULL;
    unsigned **cubes = NULL;
    
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " [-d] < input_cover_file > output_cover_file " << std::endl;
        exit(1);
    } else if (argc == 2 && std::string(argv[1]) == "-d") {
        debug = true;
    }

    std::cin >> numVars;
    std::cin >> numCubes;
    if ((cubes = (unsigned **)calloc(numCubes, sizeof(unsigned *))) == NULL) {
        printf("CALLOC ERROR!\n");
        exit(1);
    }

    if ((cubeStr = (char *)malloc((numVars+1)*sizeof(char))) == NULL) {
        printf("CALLOC ERROR!\n");
        exit(1);
    }

    for (int i = 0; i < numCubes; i++) {
        if ((cubes[i] = (unsigned *)calloc((numVars+1), sizeof(unsigned))) == NULL) {
            printf("CALLOC ERROR!\n");
            exit(1);
        }
    }

    //parse file and populate cube arrays 
    while (cubeCount < numCubes) {
        std::cin >> cubeStr;

        if(debug) printf("input cube string: %s\n", cubeStr);

        //parse cubes and populate cube arrays
        for (int ivar = 0; ivar < int(strlen(cubeStr)); ivar++) {
            if (cubeStr[ivar] == '0') {
                cubes[cubeCount][ivar] = 0;
            } else if (cubeStr[ivar] == '1') {
                cubes[cubeCount][ivar] = 1;
            } else if (cubeStr[ivar] == '-') {
                cubes[cubeCount][ivar] = 2;
            } else {
                printf("INVALID CHARACTER IN CUBE\n");
                exit(1);
            }
        }

        cubeCount++;
    }

    for (int icubes = 0; icubes < numCubes; icubes++) {
        printf("cube[%i]: ", icubes);
        for (int ivars = 0; ivars < numVars+1; ivars++) {
            if (cubes[icubes][ivars] == 2) {
                printf("-");
            } else {
                printf("%i", cubes[icubes][ivars]);
            }
        }
        printf("\n");
    }

    time_t tf = time(NULL);
    printf("Run time: %i hour(s), %i min(s), %i (secs)\n",
            int((tf - t0)/3600), int(((tf - t0)%3600)/60), int((tf - t0)%60));

    return 0;
}
