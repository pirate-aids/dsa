
#include <iostream>
#include <cstring> // For strcmp, strcpy

using namespace std;

const int MAX_CITIES = 50;
const int MAX_NAME_LENGTH = 50;

struct CityConnection {
    char dest[MAX_NAME_LENGTH];
    int cost;
    CityConnection* next;
};

struct City {
    char name[MAX_NAME_LENGTH];
    CityConnection* connections;
    bool visited;
};

class FlightGraph {
private:
    City cities[MAX_CITIES];
    int numCities;

    int findCityIndex(const char* cityName) {
        for (int i = 0; i < numCities; i++) {
            if (strcmp(cities[i].name, cityName) == 0) {
                return i;
            }
        }
        return -1; // City not found
    }

    void resetVisited() {
        for (int i = 0; i < numCities; i++) {
            cities[i].visited = false;
        }
    }

public:
    FlightGraph() : numCities(0) {
        for (int i = 0; i < MAX_CITIES; i++) {
            cities[i].connections = nullptr;
        }
    }

    void addCity(const char* cityName) {
        if (numCities >= MAX_CITIES) {
            cout << "Maximum number of cities reached!" << endl;
            return;
        }
        strcpy(cities[numCities].name, cityName);
        cities[numCities].connections = nullptr;
        numCities++;
    }

    void addFlight(const char* src, const char* dest, int cost) {
        int srcIndex = findCityIndex(src);
        int destIndex = findCityIndex(dest);

        if (srcIndex == -1 || destIndex == -1) {
            cout << "City not found!" << endl;
            return;
        }

        // Add connection from source to destination
        CityConnection* newConnection = new CityConnection;
        strcpy(newConnection->dest, dest);
        newConnection->cost = cost;
        newConnection->next = cities[srcIndex].connections;
        cities[srcIndex].connections = newConnection;

        // For undirected graph, add reverse connection
        CityConnection* reverseConnection = new CityConnection;
        strcpy(reverseConnection->dest, src);
        reverseConnection->cost = cost;
        reverseConnection->next = cities[destIndex].connections;
        cities[destIndex].connections = reverseConnection;
    }

    bool isConnected() {
        if (numCities == 0) return true;

        resetVisited();
        int visitedCount = 0;

        // Use a simple array as a queue for BFS
        int queue[MAX_CITIES];
        int front = 0, rear = 0;

        // Start BFS from first city
        queue[rear++] = 0;
        cities[0].visited = true;
        visitedCount++;

        while (front < rear) {
            int current = queue[front++];
            CityConnection* conn = cities[current].connections;

            while (conn != nullptr) {
                int neighbor = findCityIndex(conn->dest);
                if (!cities[neighbor].visited) {
                    cities[neighbor].visited = true;
                    visitedCount++;
                    queue[rear++] = neighbor;
                }
                conn = conn->next;
            }
        }

        return visitedCount == numCities;
    }

    void printGraph() {
        for (int i = 0; i < numCities; i++) {
            cout << "Flights from " << cities[i].name << ": ";
            CityConnection* conn = cities[i].connections;
            while (conn != nullptr) {
                cout << "-> " << conn->dest << " (" << conn->cost << ") ";
                conn = conn->next;
            }
            cout << endl;
        }
    }
};

int main() {
    FlightGraph graph;
    int numCities, numFlights;

    cout << "Enter number of cities: ";
    cin >> numCities;
    cin.ignore(); // To ignore the newline character left by cin

    // Add cities
    for (int i = 0; i < numCities; i++) {
        char cityName[MAX_NAME_LENGTH];
        cout << "Enter city " << i + 1 << " name: ";
        cin.getline(cityName, MAX_NAME_LENGTH);
        graph.addCity(cityName);
    }

    cout << "Enter number of flights: ";
    cin >> numFlights;
    cin.ignore(); // To ignore the newline character left by cin

    // Add flights
    for (int i = 0; i < numFlights; i++) {
        char src[MAX_NAME_LENGTH], dest[MAX_NAME_LENGTH];
        int cost;

        cout << "Enter source city for flight " << i + 1 << ": ";
        cin.getline(src, MAX_NAME_LENGTH);

        cout << "Enter destination city for flight " << i + 1 << ": ";
        cin.getline(dest, MAX_NAME_LENGTH);

        cout << "Enter cost for flight " << i + 1 << ": ";
        cin >> cost;
        cin.ignore(); // To ignore the newline character left by cin

        graph.addFlight(src, dest, cost);
    }

    // Print the flight network
    graph.printGraph();

    // Check if the graph is connected
    if (graph.isConnected()) {
        cout << "\nThe flight network is connected." << endl;
    } else {
        cout << "\nThe flight network is not connected." << endl;
    }

    return 0;
}
