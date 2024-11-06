#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Movie { 
private:
    string name;
    double rating;

public:
    Movie(const string& name, double rating) : name(name), rating(rating) {}

    string getName() const {
        return name;
    }

    double getRating() const {
        return rating;
    }

};

int main() {
    vector<Movie> movies = {
        Movie("titanic", 9.9),
        Movie("gone with the wind", 9.6),
        Movie("terminator", 9.7)
    };

    for (const auto& movie : movies) {
        cout << movie.getName() << ": " << movie.getRating() << endl;
    }

 
    cout << "계속하려면 아무 키나 누르십시오..." << endl;
    cin.get();

    return 0;
}