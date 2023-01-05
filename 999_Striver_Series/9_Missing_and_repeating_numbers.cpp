/*
Missing_and_repeating_numbers.cpp

https://www.codingninjas.com/codestudio/problems/873366
*/

#include <bits/stdc++.h> 

// // SET. TC: O(N) SC: O(N)
// pair<int,int> missingAndRepeating(vector<int> &arr, int n) {
//     unordered_set<int> us;
//     int repeated = 0;
//     int missing  = 0;

    
//     for(auto &n: arr) {
//         if(us.find(n) == us.end()) {
//             us.insert(n);
//         } else {
//             repeated = n;
//         }
//     }
    
//     for(int i=1; i<=n; i++) {
//         if(us.find(i) == us.end()) {
//             missing = i;
//             break;
//         }
//     }
    
//     return { missing, repeated };
// }



// // Mark Negative. TC: O(N) SC: O(1). Original array is modified.
// pair<int,int> missingAndRepeating(vector<int> &arr, int n) {
// 	int missing = 0, repeated = 0;

// 	for(int i=0; i<n; i++) {
// 		int curr = abs(arr[i]);
// 		if(arr[curr-1] < 0) repeated = curr;
// 		else arr[curr-1] *= -1;
// 	}

// 	for(int i=0; i<n; i++) {
// 		if(arr[i] > 0) missing = i+1;
// 	}

// 	return { missing, repeated };
// }


// Bit manipulation. TC: O(N) SC: O(1)
// Take XOR of expected and given array. You will be left with missing & repeated xor;
// get setBit and Seperate out both the elements.
// Assign one to missing and repeating. Check if missing present in array if it is swap(missing,repeated)
pair<int,int> missingAndRepeating(vector<int> &arr, int n) {
	int missing = 0, repeated = 0;

	int x = 0;
	for(int i=0; i<n; i++) {
		x ^= arr[i];
		x ^= (i+1);
	}

	// pulling out set bit from x; for further search;
	int setBit = x & ~(x-1);

	// differentiate in buckets by & with setBit
	for(int i=0; i<n; i++) {
		if(arr[i] & setBit) {
			missing ^= arr[i];
		} else {
			repeated ^= arr[i];
		}

		if((i+1) & setBit) {
			missing ^= (i+1);
		} else {
			repeated ^= (i+1);
		}
	}

	// check if missing element is actually the missing one else swap. If missing is present swap.
	for(int i=0; i<n; i++) {
		if(arr[i] == repeated)
			break;
		if(arr[i] == missing) {
			swap(missing, repeated);
			break;
		}
	}

	return { missing, repeated };
}

