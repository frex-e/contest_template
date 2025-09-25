#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>
using namespace std;

long long min_total_waiting = LLONG_MAX;
vector<long long> effective_finish_times;
vector<long long> candidates;
int p;

void generate_combinations(vector<long long>& current_combination, int start_idx, int remaining) {
    if (remaining == 0) {
        // We have a complete combination of p departure times
        vector<long long> departure_times = current_combination;
        sort(departure_times.begin(), departure_times.end());
        
        long long total_waiting = 0;
        bool valid_assignment = true;
        
        // For each cat, assign it to the earliest feeder that can pick it up
        for (long long eff_time : effective_finish_times) {
            bool assigned = false;
            
            for (long long dep_time : departure_times) {
                if (dep_time >= eff_time) {
                    // This feeder can pick up the cat
                    long long waiting_time = dep_time - eff_time;
                    total_waiting += waiting_time;
                    assigned = true;
                    break;
                }
            }
            
            if (!assigned) {
                // No feeder can pick up this cat - invalid assignment
                valid_assignment = false;
                break;
            }
        }
        
        if (valid_assignment) {
            min_total_waiting = min(min_total_waiting, total_waiting);
        }
        return;
    }
    
    // Generate combinations with replacement
    for (int i = start_idx; i < candidates.size(); i++) {
        current_combination.push_back(candidates[i]);
        generate_combinations(current_combination, i, remaining - 1);
        current_combination.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m >> p;
    
    vector<long long> distances(n);
    distances[0] = 0; // distance to hill 1 is 0
    
    // Read distances d2, d3, ..., dn
    for (int i = 1; i < n; i++) {
        long long d;
        cin >> d;
        distances[i] = distances[i-1] + d;
    }
    
    // Read cats and calculate effective finish times
    for (int i = 0; i < m; i++) {
        int h;
        long long t;
        cin >> h >> t;
        h--; // convert to 0-indexed
        
        long long effective_time = t - distances[h];
        effective_finish_times.push_back(effective_time);
    }
    
    // Get unique candidates (sorted)
    set<long long> candidate_set(effective_finish_times.begin(), effective_finish_times.end());
    candidates = vector<long long>(candidate_set.begin(), candidate_set.end());
    
    // Generate all combinations of p departure times
    vector<long long> current_combination;
    generate_combinations(current_combination, 0, p);
    
    cout << min_total_waiting << endl;
    
    return 0;
}