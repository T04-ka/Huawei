#include <stdio.h>
#include <assert.h>


//--------------------------------------------------------------------------
/// Extracts a value of match score
///
/// @param[in]  *data               Array with data
/// @param[in]  teamY               First match command
/// @param[in]  teamX               Second match command
/// @param[in]  numberOfcommands    A number of commands
///
/// @return A match score
//--------------------------------------------------------------------------
int matchScore(int *data, int teamY, int teamX, int numberOfcommands);



//--------------------------------------------------------------------------
int main(){

    int N = 4;
    int data[] = {7, 6, 3, 4, 1, -2};


    int teamY = 0;
    int teamX = 0;

    scanf("%d %d", &teamY, &teamX);


    int score = matchScore(data, teamY, teamX, N);
    printf("Team %d and Team %d after match has score %d\n", teamY, teamX, score);

    return 0;
}


int matchScore(int *data, int teamY, int teamX, int numberOfcommands){

        assert(teamX >= 0);
        assert(teamY >= 1);
        assert(teamX != teamY);
        assert(teamX <= teamY - 1);
        assert(teamX < numberOfcommands);
        assert(teamY < numberOfcommands);

        return *(data + (teamY - 1) * teamY / 2 + teamX);

}
