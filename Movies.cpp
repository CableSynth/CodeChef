#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Movies{
	int index;
	int length;
	int rating;
	int lenTimeRate;
};


int main(){
	int tests = 0;
	cin >> tests;
	int *arrTest;
	arrTest = new int[tests];
	for(int i =0; i < tests; ++i){
		int numOfMovies = 0;
		cin >> numOfMovies;
		int *lengths;
		int *ratings;
		Movies *movies;
		lengths = new int [numOfMovies];
		ratings = new int [numOfMovies];
		movies = new Movies [numOfMovies];

		for(int j = 0; j < numOfMovies; ++j){
			cin >> lengths[j];
		}

		for(int j = 0; j < numOfMovies; ++j){
			cin >> ratings[j];
		}

		for(int j = 0; j < numOfMovies; ++j){
			movies[j].rating = ratings[j];
			movies[j].length = lengths[j];
			movies[j].index = j;
			movies[j].lenTimeRate = ratings[j] * lengths[j];
		}

		int end = 0;

		while(++end != numOfMovies){ // Will loop max. 9 times
			Movies temp;
    			bool swapped = false;
   			for(int j = 0; j < numOfMovies; ++j){

        			if(movies[j].lenTimeRate > movies[j + 1].lenTimeRate){    //If the current element 
            				temp = movies[j];    //is bigger than the next

				        movies[j] = movies[j + 1];//Change the positions
				        movies[j + 1] = temp;
				        swapped = true;    
        			}else if(movies[j].lenTimeRate == movies[j + 1].lenTimeRate){
					if(movies[j].rating > movies[j].rating){
						temp = movies[j];    //is bigger than the next
				        	movies[j] = movies[j + 1];//Change the positions
				        	movies[j + 1] = temp;
				        	swapped = true;    
					}else if(movies[j].rating == movies[j + 1].rating){
						if(movies[j].index < movies[j+1].index){
							temp = movies[j];    //is bigger than the next
						        movies[j] = movies[j + 1];//Change the positions
						        movies[j + 1] = temp;
							swapped = true;    
						}
					}
				}


    			}
   			 if (!swapped) break;
		}

		cout << movies[0].index + 1 << endl;
	}


	
	return 0;

}


